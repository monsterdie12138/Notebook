---
comments: true
---

<span style="font-family: 'Times New Roman';">

# Chapter3 Introduction to SQL

***

## 3.1 SQL Data Definition

**Domain Types:**

* `char(n)`: 定长字符串，n为字符串长度
* `varchar(n)`: 变长字符串，n为最大字符串长度
* `int`: 整数
* `smallint`: 小整数
* `numeric(p, d)`: 定点数，p为总位数，d为小数位数
* `real precision`: 单精度浮点数
* `double precision`: 双精度浮点数
* `float(n)`: 浮点数，n为精度

**`create table` 创建表格：**

基本格式如下：

```sql
create table r                  # r为表格名字
    (A1 D1,                     # A为属性，D为数据类型   
     A2 D2,
     ...,
     An Dn,
    (integrity-constraint1),    # 完整性约束
    (integrity-constraint2),
    ...,
    (integrity-constraintk))
```

例如：

```sql
create table instructor(
    ID          char(5),
    name        varchar(20),
    dept_name   varchar(20),
    salary      numeric(8, 2)
)
```

**Integrity Constraints 完整性约束：**

完整性约束1：设定主键`primary key`：

```sql
primary key (A1, A2, ..., An)
```

也可以直接放在数据类型后面：

```sql
A D primary key
```

!!! Note
    设定主键的属性取值不能为null，否则报错。

完整性约束2：设定外键`foreign key`：

```sql
foreign key (A1, A2, ..., An) references r
```

可以设置外键的删除/更新绑定：

```sql
foreign key (A1, A2, ..., An) references r on delete/update cascade     # 同步删除/更新
foreign key (A1, A2, ..., An) references r on delete/update set null    # 设定为null
foreign key (A1, A2, ..., An) references r on delete/update restrict    # 拒绝删除/更新
foreign key (A1, A2, ..., An) references r on delete/update set default # 设定为默认值
```

完整性约束3：设定非空`not null`：

```sql
A D not null
```

整体用法例如：

```sql
create table student(
    ID          varchar(5),
    name        varchar(20) not null,
    dept_name   varchar(20),
    tot_cred    numeric(3, 0),
    primary key (ID),
    foreign key (dept_name) references department
)
```

**Updates to Tables:**

* `insert into values`
  ```sql
  insert into r values (A1, A2, ..., An)
  ```
* `delete from`
  ```sql
  delete from r
  ```
* `drop table`
  ```sql
  drop table r
  ```
* `alter add/drop`
  ```sql
  alter table r add A D     # 向表格r中添加属性，名字为A，域为D，初始化为null
  alter table r drop A      # 从表格r中删除属性A
  ```

!!! Note
    `delete from`将表格内容清空，`drop table`将表格整个删除。

## 3.2 Basic Query Structure

一个典型的SQL查询语句格式如下：

```sql
select A1, A2, ..., An
from r1, r2, ..., rm
where P
```

* $A$：属性
* $r$：表格
* $P$：谓词

查询结果为一个relation，即一张表格。

**`select` Cause:**

`select`字句列出所有想在查询结果中保留的属性，对应关系代数中的投影算子。例如：

```sql
select name from instructor
```

!!! Note
    SQL大小写不敏感。

`select`默认**不去重**，可以用关键字`distinct`去重，或者`all`不去重。例如：

```sql
select distinct dept_name from instructor
select all dept_name from instructor
```

使用星号表示选择所有属性。例如：

```sql
select * from instructor
```

属性可以是没有`from`子句的字面量，返回的表格只有一行一列，内容即为该字面量。例如：

```sql
select '437'
```

上述写法常用于指定别名。例如：

```sql
select '437' as FOO
```

属性可以是有`from`子句的字面量，返回的返回的表格只有一列，行数和`from`后面表格的一致，每一行的内容都是该字面量。例如：

```sql
select 'A' from instructor
```

属性可以包含算术运算符（要求属性的域支持该运算），得到的表格中该属性下的值也会进行相应的运算。例如：

```sql
select ID, name, salary/12 from instructor
```

可以使用关键字`as`对属性重命名。例如：

```sql
select ID, name, salary/12 as monthly_salary from instructor
```

**`where` Cause:**

`where`子句用于过滤查询结果，对应关系代数中的选择算子。例如：

```sql
select name from instructor where dept_name='Comp. Sci.'
```

可以使用`and`、`or`、`not`等逻辑运算符。例如：

```sql
select name from instructor where dept_name='Comp. Sci.' and salary>70000
```

**`from` Cause:**

`from`子句用于指定查询的表格，可以指定多个表格，对应关系代数中的笛卡尔积算子。例如：

```sql
select * from instructor, teaches
```

## 3.3 Additional Basic Operations

**`as` 重命名：**

`as`关键字用于给表格或者属性重命名，对应关系代数中的重命名算子。例如：

```sql
select distinct T.name 
from instructor as T, instructor as S 
where T.salary>S.salary and S.dept_name='Comp. Sci.'
```

`as`可以被省略：`instructor as T`$\equiv$`instructor T`

**`like` 字符匹配：**

`like`关键字用于字符匹配，其使用：

* `%`：匹配任意长度的字符串
* `_`：匹配一个字符

例如，在instructor中找到所有含有"dar"的名字：

```sql
select name 
from instructor 
where name like '%dar%'
```

可使用`\`进行转义，这样`%`和`_`也能被识别为普通字符。例如，匹配字符串"100%"：

```sql
like '100\%' escape '\'
```

!!! Example
    `Intro%`：以"Intro"开头的字符串  
    `%Comp%`：包含"Comp"的字符串  
    `___`： 三个字符的字符串  
    `___%`：至少三个字符的字符串

**`order by` 排序：**

`order by`关键字指定一个属性，输出表格中的元组按照该属性的数值/字母顺序排列。例如：

```sql
select distinct name 
from instructor 
order by name
```

可以使用`desc`关键字进行降序排列，`asc`关键字进行升序排列，默认为**升序**排列。例如：

```sql
order by name desc
```

可以使用多个属性进行排序。例如：

```sql
order by dept_name, name
```

**`between and` 比较运算:**

`between and`关键字用于范围比较，判断一个值是否在两个值之间（闭区间）。例如：

```sql
select name
from instructor
where salary between 90000 and 100000
```

**Tuple Comparison:**

`where`子句中可以比较两个元组是否相等来作为筛选条件。例如：

```sql
select name,course_id
from instructor,teaches
where (instructor.ID,dept_name)=(teaches.ID,'Biology')
```

**`union`/`intersect`/`except` 集合操作:**

`union`关键字表示集合的并。例如，查询所有在2017秋学期或2018春学期开设的课程：

```sql
(select course_id from section where sem='Fall' and year=2017)
union
(select course_id from section where sem='Spring' and year=2018)
```

`intersect`关键字表示集合的交。例如，查询所有在2017秋学期和2018春学期都开设的课程：

```sql
(select course_id from section where sem='Fall' and year=2017)
intersect
(select course_id from section where sem='Spring' and year=2018)
```

`except`关键字表示集合的差。例如，查询所有在2017秋学期开设但2018春学期没有开设的课程：

```sql
(select course_id from section where sem='Fall' and year=2017)
except
(select course_id from section where sem='Spring' and year=2018)
```

集合操作默认**去重**，如果想要保留重复则需要加关键词`all`，例如`union all`，`intersect all`，`except all`。

**`null` 空值:**

`null`有两重含义，一是unknown，二是not exist。

任何包含`null`的算术表达式的结果都是`null`。

`is null`和`is not null`关键字用于判断值是否为`null`。例如：

```sql
select name 
from instructor
where salary is null
```

`unknown`为`true`和`false`以外的第三种结果，包含`null`的比较式结果均为`unknown`。`null=null`的结果也为`unknown`。

对于布尔运算符：

* `and`
  
  * `(true and unknown)=unknown`
  * `(false and unknown)=false`
  * `(unknown and unknown)=unknown`
* `or`
  
  * `(unknown or true)=true`
  * `(unknown or false)=unknown`
  * `(unknown or unknown)=unknown`

在查询中，要保证`where`返回的元组为当前确定的真值，因此`unknown`会被当做`false`。

**`max`/`min`/`avg`/`sum`/`count` 聚合:**

聚合函数（aggregate function）包括`max`，`min`，`avg`，`sum`，`count`等，处理的对象是一个属性列下的所有值组成的多重集合，**不去重**。

例如，查询计算机科学系教授的平均工资：

```sql
select avg(salary)
from instructor
where dept_name='Comp.Sci'
```

例如，查询在2018春学期授课的教授人数：

```sql
select count(distinct ID)
from teaches
where semester='Spring' and year=2018
```

例如，查询course的元组个数：

```sql
select count(*)
from course
```

**`group by` 分组：**

`group by`关键字后面跟一个属性名，以此为依据进行分组，在这个属性上的值相同则分到同一组。例如，查询每个系教授的平均工资：

```sql
select dept_name, avg(salary) as avg_salary
from instructor
group by dept_name
```

在有`group by`的语句中，`select`之后放分类属性和聚合属性，不能放其他属性，否则会报错。

`having`关键字位于`group by`之后，与`where`的作用类似，用于约束。例如，查询平均工资高于42000的院系：

```sql
select dept_name, avg(salary) as avg_salary
from instructor
group by dept_name
having avg(salary)>42000
```

!!! Note
    `having`虽然与`where`类似，但前者的筛选位于聚合之后，后者的筛选位于聚合之前。两者不能随意移动并相互替换，否则会报错。

***

## 3.4 Nested Subqueries

一套由`select`，`from`和`where`组成的查询语句返回的是一张表，其可以参与另一张表的构建，出现在`select`，`from`或者`where`字句中。

**`where`子句的嵌套子查询：**

`in`和`not in`关键字表示集合从属。例如，查询所有在2017秋学期和2018春学期都开设的课程：

```sql
select distinct course_id
from section
where semester='Fall' and year=2017 and
      course_id in (select course_id
                    from section
                    where semester='Spring' and year=2018)
```

查询所有在2017秋学期开设但2018春学期没有开设的课程：

```sql
select distinct course_id
from section
where semester='Fall' and year=2017 and
      course_id not in (select course_id
                        from section
                        where semester='Spring' and year=2018)
```

`in`和`not in`后面可以直接跟集合。例如，查询所有名字既不是Mozart也不是Einstein的教授：

```sql
select distinct name
from instructor
where name not in ('Mozart','Einstein')
```

从属关系的属性可以不止一个。例如，查询所有上过ID为10101的教授所授课程的学生数：

```sql
select count(distinct ID)
from takes
where (course_id,sec_id,semester,year) in (select course_id,sec_id,semester,year
                                           from teaches
                                           where teaches.ID=10101)
```

`some`和`all`关键字用于元素与集合之间的比较。例如，查询工资比某个生物系教授高的教授：

```sql
# 写法一
select distinct T.name
from instructor as T,instructor as S
where T.salary>S.salary 
and S.dept_name='Biology'

# 写法二：
select name
from instructor
where salary >some (select salary
                    from instructor
                    where dept_name='Biology')
```

查询工资比所有生物系教授都高的教授：

```sql
select name
from instructor
where salary >all (select salary
                   from instructor
                   where dept_name='Biology')
```

!!! Note
    `=some`与`in`等价  
    `<>some`与`not in`不等价  
    `<>all`与`not in`等价  
    `=all`与`in`不等价  

`exists`和`not exists`用于判断一张表格是否为空。若表格$r$不为空，则`exists r`为真；若表格$r$为空，则`not exists r`为真。例如，查询所有在2017秋学期和2018春学期都开设的课程：

```sql
select course_id
from section as S
where semester='Fall' and year=2017 and 
      exists(select *
             from section as T
             where semester='Spring' and year=2018 and S.course_id=T.course_id)
```

!!! Success "Definition"
    **correlation name 关联名称:**  
    外层查询中定义的表别名或变量，例如上例中的`S`。`S`的数据范围是`section`表的全部数据。  
    但是，由于外层查询的`where`子句中有`semester='Fall' and year=2017`，所以外层查询只会处理`section`表中满足这些条件的行。  
    内层查询中的`S.course_id`引用的是外层查询当前处理的行中的`course_id`。

    **correlated subquery 相关子查询:**  
    即为内层查询，引用关联名称。

当处理集合与集合的包含关系时，由于有等价式$X-Y=\emptyset\Leftrightarrow X\subseteq Y$，因此可以考虑使用`except`和`not exists`。例如，查询上过所有生物系课程的学生：

```sql
select distinct S.ID,S.name
from student as S
where not exists((select course_id
                  from course
                  where dept_name='Biology')
                  except
                 (select T.course_id
                  from takes as T
                  where S.ID=T.ID))
```

`unique`关键字判断一张表格中的元素是否有重复。例如，查询所有在2017年最多只上过一次的课：

```sql
select T.course_id
from course as T
where unique(select R.course_id
             from section as R
             where T.course_id=R.course_id and R.year=2017)
```

**`from`子句的嵌套子查询：**

`from`字句的嵌套子查询相对比较容易理解，因为其后面本就是表格。例如，查询那些平均工资高于42000的院系的平均工资：

```sql
# 写法一：
select dept_name,avg_salary
from (select dept_name,avg(salary) as avg_salary
      from instructors
      group by dept_name)
where avg_salary>42000

# 写法二：
select dept_name,avg_salary
from (select dept_name,avg(salary)
      from instructor
      group by dept_name)
      as dept_avg(dept_name,avg_salary)
where avg_salary>42000
```

`with`关键字用于定义临时表格，该表格只能在`with`所在的查询语句中可用。例如，查询拥有最多预算的院系：

```sql
with max_budget(value) as 
     (select max(budget) 
      from department)
select department.name
from department,max_budget
where department.budget=max_budget.value
```

查询总工资比平均总工资高的院系：

```sql
with dept_total(dept_name,value) as
     (select dept_name,sum(salary)
      from instructor
     group by dept_name)
     dept_total_avg(value) as
     (select avg(value)
      from dept_total)
select dept_name
from dept_total,dept_total_avg
where dept_total.value>dept_total_avg.value
```

**`select`子句的嵌套子查询：**

`select`子句的嵌套子查询又称为scalar subquery，因为一般只期待返回一个单一值。若子查询返回的表格中有超过一个元组则会报错。例如，查询各院系的教授人数：

```sql
select dept_name,
       (select count(*) 
        from instructor 
        where department.dept_name=instructor.dept_name) 
       as num_instructors
from department
```

!!! Note
    如果使用`group by`，则查询结果不同。假设某个院系没有教授，则上例中依然会如实反馈，而使用`group by`则无法反馈。