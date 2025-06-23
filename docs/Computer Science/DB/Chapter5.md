---
comments: true
---

<span style="font-family: 'Times New Roman';">

# Chapter5 Advanced SQL

***

## 5.1 Accessing SQL From a Programming Language

SQL处理数据的力度与通用程序语言是不匹配的。SQL的数据处理单位是表格，而通用程序语言的数据处理单位是变量。

通过通用程序语言访问数据库有以下两种方式：

* Dynamic SQL：在程序运行时连接数据库，通过函数调用向数据库发送请求，对数据库进行操作，得到返回结果。如ODBC（C++）、JDBC（Java）等
* Embedded SQL：将SQL语句嵌入到通用程序语言的代码中，在编译时解析。

**JDBC:**

JDBC是Java Database Connectivity的缩写，是Java访问数据库的API。

JDBC与数据库的交互过程可分为以下几步：

* 建立数据库连接
* 创建Statement对象
* 通过Statement对象执行SQL语句
* 处理报错

以下java代码展示了如何使用JDBC连接并操作数据库：

```java linenums="1"
public static void JDBCexample(String dbid, String userid, String passwd) 
{
    try 
    (
        Connection conn = DriverManager.getConnection(
            "jdbc:oracle:thin:@db.yale.edu:2000:univdb", userid, passwd);
        Statement stmt = conn.createStatement();
    ) 
    {
        ...Do Actual Work...
    } 
    catch (SQLException sqle) 
    { 
        System.out.println("SQLException: " + sqle);
    }
}
```

整体框架定义了一个名为`JDBCexample`的方法，`public`说明可以从任何地方调用，`static`说明属于类本身，而不是某个对象，`void`说明没有返回值。三个参数`dbid`为数据库ID，`userid`为用户ID，`passwd`为密码。

`try`模块中，`Connection`对应的语句用于建立数据库连接，其中参数`"jdbc:oracle:thin:@db.yale.edu:2000:univdb"`是连接字符串（内含多重信息），`userid`和`passwd`是用户名和密码。`Statement`对应的语句用于创建一个Statement对象。

`{...Do Actual Work...}`部分是实际的数据库操作代码。

`catch`模块用于捕获异常，可暂时不去细究。

使用`executeUpdate`方法执行数据库的更新：

```java
stmt.executeUpdate("insert into instructor values('77987', 'Kim', 'Physics', 98000)");
```

使用`executeQuery`方法执行数据库的查询：

```java
ResultSet rset = stmt.executeQuery("select dept_name, avg(salary)
                                    from instructor
                                    group by dept_name");
```

`ResultSet`对象`rset`是一个元组的集合，需要通过循环逐个取出元组。不同属性的数据类型不同，因此使用不同的方法获取（`getString`，`getFloat`等），参数可以是属性名，也可以是属性的序号：

```java
while (rset.next()) 
{
System.out.println(rset.getString("dept_name") + " " +rset.getFloat(2));
}
```

使用`wasNull`方法判断是否为空值：

```java
if(rset.wasNull()) System.out.println("Null value");
```

**Prepared Statement:**

prepared statement是一种预编译SQL语句，使用占位符`?`。

```java linenums="1"
public static void insertInstructor(String userid, String passwd) {
    try (
        // 建立数据库连接
        Connection conn = DriverManager.getConnection(
            "jdbc:oracle:thin:@db.yale.edu:2000:univdb", userid, passwd);
        
        // 创建 PreparedStatement 对象
        PreparedStatement pStmt = conn.prepareStatement(
            "insert into instructor values(?,?,?,?)");
    ) {
        // 设置参数
        pStmt.setString(1, "88877");    // 第一个"?"
        pStmt.setString(2, "Perry");    // 第二个"?"
        pStmt.setString(3, "Finance");  // 第三个"?"
        pStmt.setInt(4, 125000);        // 第四个"?"
        pStmt.executeUpdate();          
        pStmt.setString(1, "88878");
        pStmt.executeUpdate();

        ...
        // 执行插入操作
        int rowsInserted = pStmt.executeUpdate();
        System.out.println(rowsInserted + " row(s) inserted successfully!");
    } catch (SQLException sqle) {
        ...
    }
}
```

prepared statement的好处之一是只需要编译一次，便可执行多次。

prepared statement的另一个好处是避免通过字符串拼接的方法注入攻击。

!!! Note
    假设查询语句使用`"select * from instructor where name = '" + name + "'"`的字符串拼接方法，如果用户输入的`name`为恶意内容`X' or 'Y' = 'Y`，那么实际解析出来的字符串为`select * from instructor where name = 'X' or 'Y' ='Y'`，这个查询语句始终返回所有记录。
    假如使用prepared statement，则SQL查询语句会被预编译，用户的输入不会被直接拼接到查询字符串中。如果用户的输入中含有特殊字符（如单引号），那么prepared statement会自动进行转义处理，避免SQL注入攻击。

    ```java
    PreparedStatement pstmt = conn.prepareStatement(
    "select * from instructor where name = ?");
    pstmt.setString(1, "X' or 'Y' = 'Y");
    ```

**Metadata:**

元数据是描述数据的数据，分为以下两种：

* ResultSet Metadata：描述查询结果的元数据，如属性等
* Database Metadata：描述数据库的数据，如视图、索引等

使用`getMetaData()`方法获取表格的元数据：

```java
ResultSetMetaData rsmd = rset.getMetaData();
for (int i = 1; i <= rsmd.getColumnCount(); i++) 
{
    System.out.println(rsmd.getColumnName(i));       // 输出列名
    System.out.println(rsmd.getColumnTypeName(i));   // 输出列的数据类型
}
```

```java
DatabaseMetaData dbmd = conn.getMetaData();
ResultSet rs = dbmd.getColumns(null, "univdb", "department", "%");while( rs.next()) 
{
    System.out.println(rs.getString("COLUMN_NAME"),rs.getString("TYPE_NAME"));
}
```

**Transaction Control:**

每次执行一条SQL语句后，JDBC会自动提交该语句作为一个单独的事务。然而，对于需要执行多个更新的事务，默认的自动提交可能导致部分操作成功，部分操作失败，从而破坏数据的一致性。

可以关闭自动提交：

```java
conn.setAutoCommit(false);
```

若关闭自动提交，则之后的提交或者回滚都需要手动操作：

```java
conn.commit();
conn.rollback();
```

***

## 5.2 Functions and Procedures

SQL支持函数和过程，函数和过程的区别在于函数有返回值，通常无副作用；过程没有返回值，包含一系列副作用。

**SQL Functions:**

使用`create function`创建函数：

```sql linenums="1"
create function dept_count (dept_name varchar(20)) 
returns integer
begin
    declare d_count integer;
    
    select count(*) 
    into d_count
    from instructor
    where instructor.dept_name = dept_name;
    
    return d_count;
end;
```

其中，`returns`定义返回的数据类型，`declare`定义局部变量，`select ... into ...`用于查询并将结果赋值给变量，`return`返回结果。

调用函数：

```sql
select dept_name, budget
from department
where dept_count (dept_name ) > 12
```

**Table Function:**

表函数是一类特殊的函数，其返回结果是一张表。

创建表函数与创建普通函数类似，只是要在返回类型中声明返回的是表：

```sql linenums="1"
create function instructor_of (dept_name char(20))
returns table (
    ID varchar(5),
    name varchar(20),
    dept_name varchar(20),
    salary numeric(8,2)
)
return table (
    select ID, name, dept_name, salary
    from instructor
    where instructor.dept_name = dept_name
);
```

调用表函数：

```sql
select *
from table (instructor_of ('Music'))
```

**SQL Procedures:**

使用`create procedure`创建过程：

```sql
create procedure dept_count_proc (in dept_name varchar(20), out d_count integer)
begin
    select count(*) into d_count
    from instructor
    where instructor.dept_name = dept_count_proc.dept_name;
end;
```

其中，`in`表示输入参数，`out`表示输出参数。

调用过程：

```sql
declare d_count integer;
call dept_count_proc( 'Physics', d_count);
```