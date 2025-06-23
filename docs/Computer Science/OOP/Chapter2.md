---
comments: true
---

<span style="font-family: 'Times New Roman';">

# Chapter2 类与对象

***

## 2.1 类（class）与对象（object）

$~$

**基本结构：**

```cpp linenums="1"
class class_name
{
    private:        // 默认，可以省略
        // 私有成员
    protected:
        // 保护成员
    public:
        // 公有成员
};
```

类中声明的数据和函数统称为**成员（member）**，包括**数据成员（data member）**和**成员函数（member function）**。

{ }所包围的区域称为**类域（class scope）**，同一类域中的成员不受访问权限的限制，相互之间可以自由访问。

!!! Note
    class和struct都是类，有相同的功能，用法也类似。二者唯一的区别是，在没有指定成员的访问权限时，struct默认为public，class默认为private。

!!! Example
    **设计复数类`Complex`，提供复数的修改、输入和显示功能。**

    ```cpp linenums="1"
    class Complex
    {
        private:
            double image;
            double real;
        public:
            void display()
            {
                cout<<real<<"+"<<image<<"i"<<endl;
            }
            void inputData()
            {
                cout<<"input real:";
                cin>>real;
                cout<<endl<<"input image:";
                cin>>image;
            }
            void setImage(double i)
            {
                image=i;
            }
            void setReal(double r)
            {
                real=r;
            }
    };

    int main()
    {
        Complex c1;
        c1.image=9.2;   //错误，image设为private，无法在外部修改
        c1.inputData();
        c1.display();
        c1.setImage(9.2);
        c1.setReal(5.3);
        c1.display;
    }
    ```

$~$

**访问限定符（access specifier）：**

`private`、`protected`、`public`称为访问限定符，出现次数没有限制，也没有先后之分。

访问限定符|自身的类成员是否可以访问|子类的类成员是否可以访问|自身的类对象是否可以访问
:---:|:---:|:---:|:---:
public|√|√|√
protected|√|√|×
private|√|×|×

!!! Note
    一个成员函数接受该类的一个对象，只要是在类的定义中，就可以访问任何成员。例如：

    ```cpp linenums="1"
    class A
    {
        public:
            void display(A& w)
            {
                cout<<w.weight;
            }
        private:
            double weight;
    };
    ```

$~$

**数据成员（data member）：**

数据成员的数据类型有以下限制：

* 数据成员可以是另一个类的对象或指向另一个类的对象的指针，可以是指向自身类的指针或引用，但不能是自身类的对象
* 数据成员可以是`const`常量，但不能是`constexpr`常量
* 数据成员可以用`decltype`推断定义，但不能用`auto`推断定义
* 数据成员不能指定为寄存器`register`或外部`extern`存储类型

数据成员可以有类内初始值，但此时并没有获取到相应的内存空间，只有在用类定义对象时，才会为数据成员分配内存空间。

常量数据成员只能通过初始化列表进行初始化。

$~$

**成员函数（member function）：**

成员函数的定义可以分为类内和类外。

类内定义成员函数：

```cpp linenums="1"
class Date
{
    int day,month,year;
    public:
        void init(int d,int m,int y)
        {
            day=d;
            month=m;
            year=y;
        }
        int getDay()
        {
            return day;
        }
}
```

类外定义成员函数：

```cpp linenums="1"
class Date
{
    int day,month,year;
    public:
        void init(int,int,int); //省略了形参
        int getDay();
        inline int getMonth();
};

inline void Date::init(int d,int m,int y)
{
    day=d;
    month=m;
    year=y;
}   //定义时标明inline，因此是内联函数

int Date::getDay()
{
    return day;
}

int Date::getMonth()
{
    return month;
}
```

类内定义的成员函数默认为内联函数。

若类外定义成员函数，则在类内声明成员函数的原型时可以省略形参名，只声明形参类型；但类外定义时需要保持一致，并且指出形参名。

若类外定义成员函数，则成员函数名前面要加上类名，用`::`连接。


**常量成员函数（const member function）** 用于禁止成员函数修改数据成员的值，一旦被声明为常量成员函数，则函数体内就不能含有任何修改类内数据成员的语句：

```cpp linenums="1"
class X
{
    ...
    T f(...) const;
    ...
};
```

只有类的成员函数才能定义为常量函数，普通函数不能定义为常量函数。

如果类内声明常量成员函数，类外定义，那么都需要加上`const`限定符。

在同一个类中，允许定义多个函数名相同但参数列表不同，称为**成员函数重载（member function overloading）**。为了避免编译错误，如果某个参数指定了默认值（缺省值），其右边的所有参数也必须指定默认值。

```cpp linenums="1"
class Date
{
    int day, month, year;
    public:
        void init(int d, int m=8, int y=2016) 
        {　
            day = d;
            month = m;
            year = y; 
        } 
        void init(int d, int m)
        {　
            day = d;   
            month = m;  
            year = 2016; 
        }
        void init(int d)
        {
            day = d;     
            month = 8;   
            year = d;　
        }
};
```

该类的定义存在成员函数重载冲突，例如`init(10)`，编译器无法判断调用的是第一个`init`还是第三个`init`。

$~$

**访问成员函数：**

通过对象访问：

```cpp linenums="1"
class_name object_name;
object_name.function_name();
```

通过指针访问：

```cpp linenums="1"
class_name *object_name;
object_name->function_name();
```

$~$

**常量对象：**

```cpp linenums="1"
类型名 const 对象名(构造实参列表);
const 类型名 对象名(构造实参列表);
```

常量对象所有数据成员的值都不能被修改（除了`mutable`修饰的数据成员），也不能调用非常量成员函数。

$~$

***

## 2.2 构造函数（constructor）

$~$

**构造函数：**

构造函数是一种特殊成员函数，主要用于初始化对象的数据成员。

构造函数有以下特点：

* 与类同名，没有返回类型
* 可以被重载
* 由系统自动调用（定义对象时），不允许在程序中显式调用
* 不能被声明为常量成员函数
* 通常定义为public

```cpp linenums="1"
class Desk
{
    public:
        Desk(int,int);  //构造函数声明
    private:
        int width,length,weight=2,height=3;
};

Desk::Desk(int l,int w) //构造函数定义
{
    length=l;
    width=w;
    cout<<"call constructor!"<<endl;
}

int main()
{
    Desk d(3,5);
}
```

$~$

**默认构造函数（default constructor）：**

默认构造函数可以是：

* 类内没有定义任何构造函数时系统自动提供的无参构造函数
* 类内定义的无参构造函数
* 所有的形参都提供了默认值的构造函数

在以下情况中，系统使用默认构造函数：

* 一个类没有定义任何构造函数
* 定义对象的时候没有提供参数
* 定义数组

使用系统提供的默认构造函数创建对象时，如果创建的是全局对象或静态对象，则所有数据成员初始化为0；如果创建的是局部对象，则不进行初始化。例如：

```cpp linenums="1"
class point
{
    private:
        int x,y;
    public:
        void setpoint(int a,int b) 
        { 
            x=a;    
            y=b;
        }
        int getx() 
        { 
            return x; 
        }
        int gety() 
        { 
            return y; 
        }
};

point p1;               //全局对象

int main()
{
    static point p2;    //静态对象
    point p3;           //局部对象
}
```

由于`point`类没有定义任何构造函数，因此系统自动生成默认构造函数。`p1`和`p2`的数据成员初始化为0，`p3`的数据成员不进行初始化。

以下情况编译器不会为类创建默认构造函数：

* 类内自定义了构造函数
* 类A的一个数据成员的类型是类B，但类B有其它构造函数，却没有默认构造函数，此时类A无法自动生成默认构造函数
* 数据成员中有常量类型和引用类型，并且未初始化

类一旦定义构造函数，系统就不再产生默认构造函数；此时若需要创建无参对象，则必须显式定义无参构造函数：

```cpp linenums="1"
class point
{
    private:
        int x,y;
    public:
        point(int a,int b)  //类内定义了构造函数，因此不使用默认构造函数
        {
            x=a;
            y=b;
        }
};

point p1;                   //错误

int main()
{
    static point p2;        //错误
    point p3,*p4,a[10];     //错误
    p4=new point;           //错误
}
```

错误的原因均为没有参数（定义的构造函数要求两个参数）。

$~$

**初始化列表（initializer list）：**

初始化列表是在构造函数的形参表和函数体之间为数据成员赋初值的一种方式：

```cpp linenums="1"
constructor_name(type x1,type x2,...): data_member1(y1),data_member2(y2),...
{
    main body;
}    
```

例如：

```cpp linenums="1"
class Tdate
{
    public:
        Tdate(int y,int m,int d);
    protected:
        int month=12,day,year;
};

Tdate::Tdate(int y,int m,int d): month(m),day(d)
{
    year=y;
}

int main()
{
    Tdate day(2003,10,1);
}
```

注意事项：

* 初始化列表中**成员初始化顺序应该与其在类中的声明顺序一致**，而不是初始化列表中的顺序，也就是说，只要数据成员在类中的声明顺序不变，那么初始化列表中怎么排序，初始化次序都一致；
* 数据成员的初始化顺序为：类内初始值→初始化列表→构造函数的函数体；
* 有些数据类型必须使用初始化列表（或者类内初始值）进行初始化，如常量、引用、类对象等。

!!! Example
    **分析类中数据成员的值。**

    ```cpp linenums="1"
    class A
    {
        int x,y,j;
        const int i=4;
        int& k;
        public:
            A(int a,int b,int c): j(b),k(c),x(y)
            {
                y=a;
            }
    }
    int main()
    {
        int m=6;
        A x(4,5,m);
    }
    ```

    最终结果为：

    * `x=?`
    * `y=4`
    * `j=5`
    * `i=4`
    * `k=6`

$~$

**委托构造函数（delegating constructor）：**

若一个构造函数使用其所在类的其它构造函数来执行自己的初始化功能，则称为委托构造函数。

委托构造函数只能在初始化列表中调用它要委托的构造函数，而且初始化列表中不允许再有其他成员：

```cpp linenums="1"
class Tdate
{
    public:
        Tdate();                    //第一个委托构造函数
        Tdate(int d);               //第二个委托构造函数
        Tdate(int m,int d);         //第三个委托构造函数
        Tdate(int y,int m,int d);   //被委托的函数
    private:
        int year=2008,month=8,day=8;
};

Tdate::Tdate(): Tdate(2008,8,1)                         //正确
{
    cout<<"delegating constructor Tdate()"<<endl;
}
Tdate::Tdate(int d): Tdate(2008,8,d),month(2) {}        //错误，初始化列表不能再有其他成员
Tdate::Tdate(int m,int d): Tdate(2008,m,d) {}           //正确
Tdate::Tdate(int y,int m,int d)
{
    year=y;
    month=m;
    day=d;
}
```

$~$

***

## 2.3 其他特殊函数

$~$

**析构函数（destructor）：**

析构函数是另一种与类同名的特殊成员函数，主要用于清理对象，释放对象所占用的资源。

特点：

* 函数名为“~”加类名
* 无参数
* 无返回值
* 不能重载

析构函数在对象生命期结束时自动调用：

* 自动/局部对象：定义的语句块结束时
* 全局/静态对象：程序结束时

注意事项：

* 如果没有显式定义析构函数，则会生成默认析构函数，类似于`X::~X(){}`；
* 若有多个对象同时结束生存期，则将按照与调用构造函数相反的顺序调用析构函数；
* 若一个类的构造函数进行了动态内存分配，则系统默认的析构函数无法回收，必须编写自定义的析构函数进行回收。

例如：

```cpp linenums="1"
class A
{
    private:
        int i;
    public:
        A(int x)
        {
            i=x;
            cout<<"constructor:"<<i<<endl;
        }
        ~A()
        {
            cout<<"destructor:"<<i<<endl;
        }
};

int main()
{
    A a1(1);
    A a2(2);
    A a3(3);
}
```

运行结果为：

```
constructor:1
constructor:2
constructor:3
destructor:3
destructor:2
destructor:1
```

$~$

**构造函数和析构函数的调用顺序：**

* 全局对象的构造函数在所有函数（包括`main`函数）执行之前调用，若一个程序有多个文件，不同文件中都定义了全局对象，则这些对象的构造函数的执行顺序是不确定的；析构函数在`main`函数执行完毕或者调用`exit`函数时调用。
* 局部对象的构造函数在建立对象时调用，若所在函数被多次调用，则每次建立对象时都要调用构造函数；析构函数在函数结束时调用。
* 静态局部对象的构造函数只在第一次调用所在函数时调用；析构函数在`main`函数执行完毕或者调用`exit`函数时调用。

$~$

**拷贝与移动：**

```cpp linenums="1"
class A
{
    type x;
    A(const A& o)               //1.拷贝构造函数（copy constructor）
    {
        x=o.x;
    }
    A(A&& o)                    //2.移动构造函数（move constructor）
    {
        x=o.x;
    }
    A& operator=(const A& o)    //3.拷贝赋值运算符（copy assignment operator）
    {
        x=o.x;
    }
    A& operator=(A&& o)         //4.移动赋值运算符（move assignment operator）
    {
        x=o.x;
    }
};
```

$~$

***

## 2.4 友元（friend）

$~$

**友元函数（friend function）：**

类的封装性使得该类外部的函数只能访问其public成员，但类可以授予指定函数特权，让其可以访问该类的所有成员，这个获得特权的函数就是友元函数。

友元函数的参数如果是该类对象，就可以直接访问该类的所有成员；如果在友元函数内部定义了该类的对象，也可以直接访问该类的所有成员。

```cpp linenums="1"
class X
{
    friend Type f(...); //声明f为X类的友元，f的形参通常是X类的对象
};
...
Type f(...)
{
    ...
}
```

!!! Example
    **Point类是处理屏幕坐标点的类，为其设计计算两点之间距离的友元函数。**

    ```cpp linenums="1"
    class point
    {
        private:
            int x,y;
            friend int dist1(point p1,point p2);
        public:
            point(int a=10,int b=10)
            {
                x=a;
                y=b;
            }
            int getx()
            {
                return x;
            }
            int gety()
            {
                return y;
            }
    };

    int dist1(point p1,point p2)    //友元函数
    {
        double x=(p2.x-p1.x);
        double y=(p2.y-p1.y);
        return sqrt(x*x+y*y);
    }
    int dist2(point p1,point p2)    //普通函数
    {
        double x=(p2.getx()-p1.getx());
        double y=(p2.gety()-p1.gety());
        return sqrt(x*x+y*y);
    }

    int main()
    {
        point p1(2,5),p2(4,20);
        cout<<dist1(p1,p2)<<endl;
        cout<<dist2(p1,p2)<<endl;
    }
    ```

友元函数并非类的成员函数，因此其放在public、private或者protected区域都是相同的。

$~$

**友元成员函数（friend member function）：**

可以指定类的某个成员函数为另一个类的友元函数，也就是友元成员函数。

!!! Example
    **有两个类A和B，将类A的成员函数`sum`定义成类B的友元成员函数，使其能够计算两个类数据成员的总和。**

    ```cpp linenums="1"
    class B;    //前向引用声明
    class A
    {
        private:
            int x,y;
        public:
            A(int i,int j)
            {
                x=i;
                y=j;
            }
            int sum(B,b);   //在此只能声明，定义须在class B定义之后
    };

    class B
    {
        private:
            int z;
        public:
            B(int i=0)
            {
                z=i;
            }
            friend int A::sum(B b);
    }

    int A::sum(B b) //sum() 的定义只能在class B定义之后
    {
        return x+y+b.z;
    }

    int main()
    {
        A a(2,3);
        B b(4);
        cout<<a.sum(b)<<endl;
    }
    ```

$~$

**友元类（friend class）：**

一个类可以是另一个类的友元类，友元类的所有成员函数都是另一个类的友元函数。

```cpp linenums="1"
class A
{
    private:
        int x,y;
    public:
        A(int i,int j)
        {
            x=i;
            y=j;
        }
        friend class B;
};

class B
{
    private:
        int z;
    public:
        int add(A a)
        {
            return a.x+a.y+z;
        }
        int mul(A a)
        {
            return a.x*a.y*z;
        }
};
```

$~$

***

## 2.5 其他

$~$

**静态成员（static member）：**

普通成员与对象关联，每个对象拥有独立的数据；静态成员与类关联，被该类所有对象共享。

静态数据成员只能在类内声明，类外定义和初始化，类外定义时无需再加`static`限定词；普通数据成员只能在类内定义；静态成员函数和普通成员函数都可以。

声明：

```cpp linenums="1"
class A
{
    static type x;
    static type f();
};
```

定义：

```cpp linenums="1"
type A::x;
type A::x=value;
```

访问：

静态成员可以在定义类的任何对象之前使用，普通成员只能在定义对象之后才能使用。静态成员可以通过类名或者对象名访问：

```cpp linenums="1"
class X
{
    public:
        int n;
        static int m;
        static in getm()
        {
            return m;
        }
};

int X::m=0;

int main()
{
    X a;
    cout<<X::getm();
    cout<<a.getm();
}
```

静态成员函数只能访问静态成员或其他静态成员函数，不能访问普通成员（没有`this`指针）。如果想要访问普通成员，必须先通过参数传递得到对象，再通过对象访问：

```cpp linenums="1"
class X
{
    int n;
    static int m;
    int getmn()
    {
        return m+n; //正确
    }
    static int summn()
    {
        return m+n; //错误
    }
};
```

!!! Example
    **设计一个Book类，能够保存书名、定价、所有书的本数和总价。**

    为了实现这一要求，可以将书名、定价设计为普通数据成员，将书的本数和总价设计为静态数据成员。

    ```cpp linenums="1"
    class Book
    {
        private:
            string bkName;
            double price;
            static int number;
            static double totalPrice;
        public:
            Book()
            {
                bkName="";
                price=0;
                number++;
            }
            Book(string,double);
            ~Book();
            void setName(string bname)
            {
                bkName=bname;
            }
            void setPrice(double bprice)
            {
                totalPrice-=price;
                price=bprice;
                totalPrice+=price;
            }
            double getPrice()
            {
                return price;
            }
            string getName()
            {
                return bkName;
            }
            static int getNumber()
            {
                return number;
            }
            static double getTotalPrice()
            {
                return totalPrice;
            }
            void display();
    };
    
    Book::Book(string name,double Price)
    {
        bkName=name;
        price=Price;
        number++;
        totalPrice+=price;
    }
    Book::~Book()
    {
        number--;
        totalPrice-=price;
    }
    void Book::display()
    {
        cout<<"book name:"<<bkName<<" "<<"price:"<<price<<endl;
        cout<<"number:"<<number<<" "<<"total price:"<<totalPrice<<endl;
        cout<<"call static function"<<getNumber()<<endl;
    }
    int Book::number=0;
    double Book::totalPrice=0;
    ```

$~$

**`this`指针：**

`this`指针是一个隐式指针，指向调用成员函数的对象自身的地址，为不允许修改的常量。

```cpp linenums="1"
X::f(...)
{
    this->member=...;
}
```

用法一：使用`this`指针返回调用对象：

```cpp linenums="1"
X& f(...)
{
    ...
    return *this;
}
```

用法二：使用`this`指针区分二义性：

```cpp linenums="1"
class X
{
    int i;
    f(int i)
    {
        this->i=i;
    }
};
```

* 常量成员函数中，`this`指针被设置成`const X*`类型，不能通过它修改对象的数据成员；
* 静态成员函数没有`this`指针，因此在静态成员函数中不能访问对象的非静态数据成员；
* 通过`this`指针可以访问类内的public、protected和private成员。

$~$

**成员操作访问符：**

操作符|`.`|`->`|`*`|`.*`|`->*`
:---:|:---:|:---:|:---:|:---:|:---:
**作用**|成员选择|指针成员选择|解引用|成员解引用|指针解引用成员选择

!!! Example
    **设计具有姓名、编号、年龄的简单类Person，能够输出和修改Person的编号和年龄。**

    Person类定义：

    ```cpp linenums="1"
    class Person
    {
        public:
            char* name=nullptr;
            int id;
            int age;
            void outData()
            {
                cout<<"id:"<<id<<"\tname"<<name<<"\tage:"<<age<<endl;
            }
            int modifyId(int Id)
            {
                id=Id;
                return id;
            }
            int modifyAge(int Age)
            {
                age=Age;
                return age;
            }
    };
    ```

    各类成员访问操作符的实际应用：

    ```cpp linenums="1"
    int main()
    {
        //.的应用
        Person p1;
        p1.name=new char[10];
        p1.id=10001;
        p1.age=10;
        strcpy(p1.name,"Tom");
        p1.outData();

        //->的应用
        Person* p2;
        p2=new Person();
        p2->age=20;
        p2->id=10002;
        p2->name=new char[10];
        strcpy(p2->name,"Jack");

        //*的应用
        (*p2).age=21;

        //.*的应用
        int (Person::* P_int)=&Person::age; //成员指针
        char* (Person::* Pname)=&Person::name;
        int (Person::* pf1)(int)=&Person::modifyAge;
        void (Person::* pf2)()=&Person::outData;
        p1.*P_int=23;
        P_int=&Person::id;
        p1.*P_int=10004;
        (p1.*pf2)();
        (p1.*pf1)(30);
        p1.outData();

        //->*的应用
        p2->*P_int=40;
        P_int=&Person::id;
        p2->*P_int=10005;
        (p2->*pf2)();
        (p2->*pf1)(32);
        p2->outData();
    }
    ```

$~$

**对象成员：**

如果用其他类的对象作为类的成员，则称为对象成员：

```cpp linenums="1"
class X
{
    A1 a1;
    A2 a2;
    ...
    AN aN;
};
```

这个时候，X的构造函数一般如下定义：

```cpp linenums="1"
X::X(X的形参表): a1(A1的形参表), a2(A2的形参表), ..., aN(AN的形参表)
{
    //函数体
}
```

拥有对象成员的类必须对对象成员进行初始化，初始化方式包括类内初始化或者构造函数初始化列表。

在创建一个拥有对象成员的类的对象时，首先会按照声明顺序调用对象成员的构造函数，然后再调用自身的构造函数；析构函数相反。