---
comments: true
---

<span style="font-family: 'Times New Roman';">

# Chapter4 多态

***

## 4.1 多态（polymorphism）

$~$

**多态基本概念：**

多态指的是不同对象接收到同一消息时会产生不同的行为，或者说在同一个类（或父类与子类）中，用同名虚函数实现不同的功能。

多态主要解决的问题是：单接口，多实现。

例如：假设Base类有一个成员函数`f`，Deri1类和Deri2类继承Base类，且分别定义了新的同名成员函数`f`，现在有一个函数`g`：

```cpp linenums="1"
void g(Base* p)
{
    p->f();
}
```

如果创建Deri1类的对象`d1`，并且执行`g(&d1)`；创建Deri2类的对象`d2`，并且执行`g(&d2)`。我们希望`g`函数实际调用的分别是Deri1类和Deri2类的`f`函数，而不是Base类的`f`函数。这就是多态的目的。

实现如上的多态有三个条件：

* 继承关系
* 子类要有和父类原型（名称、参数数量和类型、任何修饰符）完全相同的虚成员函数（父类用`virtual`标识，子类用`override`标识），其中返回类型不一定完全相同，如果是指针或引用的话只要有类的继承关系即可
* 把父类的指针或引用绑定到子类对象上

!!! Example
    **设计一个管理动物声音的软件。**

    用Animal类表示动物类，用虚成员函数`sound`表示动物发声的行为。

    类的定义：
    ```cpp linenums="1"
    class Animal
    {
        public:
            virtual void sound() {cout<<"unknown!"<<endl;}
    };

    class Dog:public Animal
    {
        public:
            void sound() {cout<<"wang!"<<endl;}
    };

    class Cat:public Animal
    {
        public:
            void sound() {cout<<"miao!"<<endl;}
    };

    class Wolf:public Animal
    {
        public:
            void sound() {cout<<"wu!"<<endl;}
    };
    ```

    设计`animalSound`函数管理每种动物的声音，多态能够很好地实现此需求：

    ```cpp linenums="1"
    void animalSound(Animal& animal) {animal.sound();}
    ```

    具体使用：

    ```cpp linenums="1"
    int main()
    {
        Dog dog;
        Cat cat;
        Wolf wolf;

        animalSound(dog); // 输出：wang!
        animalSound(cat); // 输出：miao!
        animalSound(wolf);// 输出：wu!
    }
    ```

多态使开发者在没有确定某些具体功能如何实施的情况下，可以站在高层（父类）设计并完成系统开发，等到新功能明确并实现后，通过多态可以很容易地融入系统。

$~$

**联编（linking）：**

一个程序常常会调用来自不同文件或者库中的函数，需要通过编译和链接才能形成可执行文件，这个过程中把调用的函数名和对应的函数关联在一起的过程称为联编。

* **静态联编（static linking）：**
  
  * 在编译过程中绑定调用函数名和具体函数
  * 对应**编译时多态性**
  * 通过函数重载和运算符重载实现
  
* **动态联编（dynamic linking）：**
  
  * 在运行过程中绑定调用函数名和具体函数
  * 对应**运行时多态性**
  * 通过继承和虚函数实现

$~$

***

## 4.2 虚函数（virtual function）

$~$

回忆之前的赋值相容，不论哪种赋值方式，都只能通过父类对象（或父类对象的指针、引用）访问子类对象从父类继承得到的成员，而无法访问子类定义的成员。

虚函数使得通过父类对象的指针或引用可以访问子类重定义的虚成员函数。

!!! Example
    **设计雇员类与经理类。**

    假如不使用虚函数：

    雇员类（父类）：
    ```cpp linenums="1"
    class Employee
    {
        public:
            Employee(string Name,string Id) {name=Name;id=Id;}
            string getName() {return name;}
            string getId() {return id;}
            float getSalary() {return 0.0;}
            void print() {cout<<"姓名："<<name<<"\t\t编号："<<id<<endl;}
        private:
            string name;
            string id;
    };
    ```

    经理类（子类）：
    ```cpp linenums="1"
    class Manager: public Employee
    {
        public:
            Manager(string Name,string Id,float s=0.0): Employee(Name,Id) {WeeklySalary=s;}
            void setSalary(float s) {WeeklySalary=s;}
            float getSalary() {return WeeklySalary;}
            void print() {cout<<"姓名："<<getName()<<"\t\t编号："<<getId()<<"\t\t周工资："<<getSalary()<<endl;}
        private:
            float WeeklySalary;
    };
    ```

    具体使用：
    ```cpp linenums="1"
    Manager m("Alex","NO0001",128);
    m.print();      //输出：姓名：Alex		编号：NO0001		周工资：128
    Employee* pm;
    pm=&m;
    pm->print();    //输出：姓名：Alex		编号：NO0001
    Employee &rm=m;
    rm.print();     //输出：姓名：Alex		编号：NO0001
    ```

    输出的2、3行表明，通过父类对象的指针或引用只能访问到父类定义的`print`函数，这是因为`pm->print()`和`rm.print()`采用静态联编，而`pm`和`rm`的类型都是`Employee`，所以只能访问`Employee`类的成员。

    如果将`Employee`类的`print`指定为虚函数：

    ```cpp linenums="1"
    virtual void print()
    {
        cout<<"姓名："<<name<<"\t\t编号："<<id<<endl;
    }
    ```

    则运行结果为：

    ```
    姓名：Alex		编号：NO0001		周工资：128
    姓名：Alex		编号：NO0001		周工资：128
    姓名：Alex		编号：NO0001		周工资：128
    ```

    此时，`print`为虚函数，采用动态联编，运行到调用的语句时，才绑定到`pm`和`rm`实际的内存对象类型`Manager`的`print`上。

虚函数是用`virtual`关键字修饰的成员函数，采用**动态联编**的形式编译，拥有虚函数的类称为**多态类（polymorphic class）**。

如果父类的非静态成员函数被定义为虚函数，且子类用原型一致的函数覆盖了父类的虚函数，则通过基类的指针或引用调用该函数时，编译器将执行动态绑定，调用到该指针或引用实际所指对象（子类）的函数。

通过指向子类对象的父类指针访问成员函数时：

* 非虚函数由定义指针的类型决定调用的函数
* 虚函数由指针实际指向的对象的类型决定调用的函数

在子类中，如果一个成员函数没有用`virtual`显式地声明，那么只要它和父类某个虚函数的原型一致，则即为虚函数。

$~$

**`override`:**

多态的实现需要父类和子类的虚成员函数的原型完全一致，通过`override`关键字限制子类的虚成员函数，当子类的虚成员函数原型不一致时，编译器会报错；如果不加以限定，则编译器默认子类的虚成员函数是父类的虚成员函数的重载函数，而不是覆盖函数。

$~$

**`final`:**

`final`关键字用于限定只想让子类继承，而不允许被覆盖的虚成员函数。

$~$

**虚函数的特性：**

一旦将某个成员函数声明为虚函数，则其在继承体系中就永远为虚函数：

```cpp linenums="1"
class A
{
    public:
        void f(int i){...};         //非虚函数
};

class B:public A
{
    public:
        virtual void f(int i){...}; //虚函数
};

class C:public B
{
    public:
        void f(int i){...};         //虚函数
};
```

子类通过从父类继承的成员函数调用虚函数时，将访问到子类中的版本，如果去掉`virtual`则访问父类的版本：

```cpp linenums="1"
class B
{
    public:
        void f() {g()};
        virtual void g() {cout<<"B::g"<<endl;}
};

class D:public B
{
    public:
        void g() {cout<<"D::g"<<endl;}
};

int main()
{
    D d;
    d.f(); //输出：D::g
}
```

!!! Example
    **分析下面程序的输出结果，理解虚函数的调用过程。**

    ```cpp linenums="1"
    class B
    {
        public:
            void f() {cout<<"bf";}
            virtual void vf() {cout<<"bvf";}
            void ff() {vf(); f();}
            virtual void vff() {vf(); f();}
    };

    class D:public B
    {
        public:
            void f() {cout<<"df";}
            void ff() {f(); vf();}
            void vf() {cout<<"dvf";}
    };

     int main()
     {
        D d;
        B* pB=&d;
        pB->f();
        pB->ff();
        pB->vf();
        pB->vff();
     }
    ```

    输出结果：

    ```
    bf dvf bf dvf dvf bf
    ```

构造函数、静态成员函数、内联函数不能是虚函数。

$~$

**虚析构函数（virtual destructor）：**

若使用`delete`来销毁一个指向子类的父类指针，如果父类的析构函数不是虚函数，那么`delete`调用的是父类的析构函数，而不是子类的析构函数，导致子类的资源释放不彻底。

若不使用虚析构函数：

```cpp linenums="1"
class A
{
    public:
        ~A() {cout<<"call A::~A()"<<endl;}
};

class B:public A
{
    char* buf;
    public:
        B(int i) {buf=new char[i];}
        ~B()
        {
            delete [] buf;
            cout<<"call B::~B()"<<endl;
        }
};

int main()
{
    A* a=new B(10);
    delete a;
}
```

此时程序的运行结果为：`call A::~A()`，说明没有析构`buf`。

若使用虚析构函数：

```cpp linenums="1"
class A
{
    public:
        virtual ~A() {cout<<"call A::~A()"<<endl;}
};

class B:public A
{
    char* buf;
    public:
        B(int i) {buf=new char[i];}
        ~B()
        {
            delete [] buf;
            cout<<"call B::~B()"<<endl;
        }
};

int main()
{
    A* a=new B(10);
    delete a;
}
```

此时程序的运行结果为：`call B::~B() call A::~A()`，说明回收了`buf`空间。

$~$

**纯虚函数（pure virtual function）和抽象类（abstract class）：**

纯虚函数是没有具体实现的虚函数，在父类中只是声明，而必须由子类提供实现。具有纯虚函数的类称为抽象类。

```cpp linenums="1"
virtual returnType funName(param)=0;
```

* 由于抽象类的纯虚函数没有实现的代码，因此不能建立抽象类的对象，不能将其用作参数类型、函数返回类型或显式转换的类型，但可以创建抽象类的指针或引用。
* 如果子类只是简单地继承了抽象类的纯虚函数，而没有重写（但有可能通过函数将其隐藏却仍然保留），则子类也是一个抽象类。
* 不允许从具体类派生出抽象类。

!!! Example
    **在一个图形系统中，实现计算各种图形面积的程序设计。**

    ```cpp linenums="1"
    class Figure
    {
        protected:
            double x,y;
        public:
            void set(double i,double j){x=i;y=j;}
            virtual void area()=0;  // 纯虚函数
    };

    class Triangle:public Figure
    {
        public:
            void area(){cout<<"三角形面积："<<x*y*0.5<<endl;}   // 重写父类纯虚函数
    };

    class Rectangle:public Figure
    {
        public:
            void area(int i){cout<<"矩形面积："<<x*y<<endl;} 
    };

    int main()
    {
        Figure* pF;
        Figure f1;      //错误，不能创建抽象类对象
        Rectangle r;    //错误，Rectangle类的area函数与父类的原型不一致，因此不是覆盖版本，Ractangle类也是抽象类
        Triangle t;
        t.set(10,20);
        pF=&t;
        pF->area();     //输出：三角形面积：100
        Figure &rF=t;
        rF.set(20,20);
        rF.area();      //输出：三角形面积：200
    }
    ```

!!! Note
    重写（override）和重载（overload）：

    重写：子类重新提供与父类完全相同函数签名（返回类型、参数列表完全一致，常量/引用限定一致），以替换父类的虚函数实现。

    重载：在同一个作用域（通常是同一个类）里，定义同名但参数列表不同的多个函数，编译器根据调用时实参来区分它们。

$~$

***

## 4.3 运行时类型信息（run-time type information, RTTI）

$~$

**RTTI:**

运行时类型信息提供了在程序运行时刻确定对象类型的方法，相关运算符有`dynamic_cast`，`typeid`，`type_info`。

$~$

**`dynamic_cast`:**

强制类型转换操作符，用于多态问题中父类与子类之间指针或引用的转换，在程序运行时刻执行。

!!! Note
    `const_cast`、`static_cast`和`reinterpret_cast`强制类型转换是在编译时刻完成的。

```cpp linenums="1"
dynamic_cast<type *>(e)     //指针转换，e是指针
dynamic_cast<type &>(e)     //引用转换，e是左值
dynamic_cast<type &&>(e)    //引用转换，e是右值
```

其中，`type`必须是类的类型，通常情况下该类是一个多态类。当`e`和`type`之间是父类和子类关系时转换成功；指针转换失败时返回0，引用转换失败时抛出异常。

* **向上转换（upcasting）：** 子类转换成父类，即把子类对象的指针或引用转换成父类对象的（c++默认方式完成）
* **向下转换（downcasting）：** 父类转换成子类，即把父类对象的指针或引用转换成子类对象的（父类指针指向或引用实际的子类对象后使用`dynamic_cast`）

```cpp linenums="1"
D d;
B* pb=&d;
D* pd=dynamic_cast<D*>(pb);
B& rb=d;
D& rd=dynamic_cast<D&>(rb);
```

默认情况下，用父类指针操作子类对象时，只能访问子类从父类继承的函数，如果继承的是虚函数则访问子类的虚函数版本。

$~$

**`typeid`:**

`typeid`操作符在程序运行时判定一个对象的真实数据类型，用法为：

```cpp linenums="1"
typeid(exp)
```

`exp`可以是任何表达式，`typeid`返回一个`type_info`类对象的引用，`type_info`类包括一个数据类型的许多信息，该类有一个成员函数`name`，可以获取`exp`的类型名称。

```cpp linenums="1"
A a;
A* p;
A& rA=a;
cout<<"1: "<<typeid(a).name()<<endl;                // 输出：1: class A
cout<<"2: "<<typeid(p).name()<<endl;                // 输出：2: class A*
cout<<"3: "<<typeid(rA).name()<<endl;               // 输出：3: class A&
cout<<"4: "<<typeid(3).name()<<endl;                // 输出：4: int
cout<<"5: "<<typeid("this is string").name()<<endl; // 输出：5: char const[15]
cout<<"6: "<<typeid(4+9.8).name()<<endl;            // 输出：6: double
```

!!! Example
    **利用`typeid`获取父类指针实际所指对象，并进行不同的函数调用。**

    ```cpp linenums="1"
    class B
    {
        int x;
        public:
            virtual void f(){cout<<"1: B::f()"<<endl;}
    };

    class D1:public B
    {
        public:
            virtual void g(){cout<<"2: D1::g()"<<endl;}
    };

    class D2:public B
    {
        int x;
        public:
            virtual void f(){cout<<"3: D2::f()"<<endl;}
            void h(){cout<<"4:D2::h()\n";}
    };

    void AccessB(B* pb)
    {
        if(typeid(*pb)==typeid(B))
        {
            pb->f();
        }
        else if(typeid(*pb)==typeid(D1))
        {
            D1* pd1=dynamic_cast<D1*>(pb);
            pd1->g();
        }
        else if(typeid(*pb)==typeid(D2))
        {
            D2* pd2=dynamic_cast<D2*>(pb);
            pd2->h();
    }

    int main()
    {
        B b;
        D1 d1;
        D2 d2;
        AccessB(&b);
        AccessB(&d1);
        AccessB(&d2);
    }
    ```

    输出结果为：

    ```
    1: B::f()
    2: D1::g()
    4: D2::h()
    ```