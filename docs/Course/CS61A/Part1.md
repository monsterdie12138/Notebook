---
comments: true
---

<span style="font-family: 'Times New Roman';">

# Part1 Python Basics

***

## 1.1 Terminology and Grammar

**None:**

`None`是一个特殊值，不会被解释器作为表达式结果显示出来，当一个函数没有使用`return`时返回的就是`None`。

在Python中表示false value的符号：`None`，`False`，`0`，`''`。

**Division:**

* `truediv`: 小数除法
* `floordiv`: （向下）整除
* `mod`: 取余

!!! Example
    ```py linenums="1"
    >>> from operator import truediv, floordiv, mod
    >>> truediv(2013,10)
    201.3
    >>> floordiv(2013,10)
    201
    >>> mod(2013,10)
    3
    ```

**`and`&`or`:**

```py
<left> and <right>
```

如果`<left>`为false，则`and`返回`<left>`；

如果`<left>`为true，则`and`返回`<right>`。

```py
<left> or <right>
```

如果`<left>`为true，则`or`返回`<left>`；

如果`<left>`为false，则`or`返回`<right>`。

**Doctest:**

doctest是Python的一个内置模块，主要功能是运行示例代码，验证代码是否按照预期工作。

!!! Example
    以下例为例，两个"""之间的内容即为示例代码。

    ```py linenums="1"
    from operator import floordiv,mod

    def divide_exact(n,d):
        """Return the quotient and remainder of dividing N by D.
        >>> q,r=divide_exact(2013,10)
        >>> q
        201
        >>> r
        3
        """
        return floordiv(n,d),mod(n,d)
    ```

    如果键入`python -m doctest -v ex.py`，得到结果如下：

    ```py linenums="1"
    Trying:
        q,r=divide_exact(2013,10)
    Expecting nothing
    ok
    Trying:
        q
    Expecting:
        201
    ok
    Trying:
        r
    Expecting:
        3
    ok
    1 items had no tests:
        ex
    1 items passed all tests:
        3 tests in ex.divide_exact
    3 tests in 2 items.
    3 passed and 0 failed.
    Test passed.
    ```

    如果把注释中正确的201改成错误的202，再键入之前的语句，得到结果如下：

    ```py linenums="1"
    Failed example:
        q
    Expected:
        202
    Got:
        201
    Trying:
        r
    Expecting:
        3
    ok
    1 items had no tests:
        ex
    **********************************************************************
    1 items had failures:
        1 of   3 in ex.divide_exact
    3 tests in 2 items.
    2 passed and 1 failed.
    ***Test Failed*** 1 failures.
    ```

***

## 1.2 Functions

**Pure Functions & Non-Pure Functions:**

* pure functions 纯函数：  
  仅仅返回结果，如`abs`，`pow`

* none-pure functions 非纯函数：  
  除了输出外还有其他副作用，如`print`，其返回结果是`None`，但其副作用是显示传入的内容。

!!! Example
    ```py linenums="1"
    >>> print(print(1),print(2)) 
    1
    2
    None None
    ```

**Default Value:**

在定义函数时可以如下定义：

```py
def function_name(para1=x,para2=y,...):
```

表示当没有值传递给形参时，形参的默认值依次为`x`，`y`，……

**Higher-Order Functions:**

高阶函数是指将函数作为参数传递或将函数作为返回值返回的函数。

第一种情况：将函数作为参数传递。

!!! Example
    **对以下计算式归纳统一。**

    $$\sum\limits_{k=1}^5k=1+2+3+4+5=15$$

    $$\sum\limits_{k=1}^5k^3=1^3+2^3+3^3+4^3+5^3=225$$

    $$\sum\limits_{k=1}^5\frac{8}{(4k-3)(4k-1)}=\frac{8}{3}+\frac{8}{35}+\frac{8}{99}+\frac{8}{195}+\frac{8}{323}=3.04$$

    ```py linenums="1"
    def identity(k):
        return k

    def cube(k):
        return pow(k,3)

    def pi_term(k):
        return 8/mul(4*k-3,4*k-1)

    def summation(n,term):
        """Sum the first N terms of a sequence.

        >>> summation(5,cube)
        225
        """
        total,k=0,1
        while k<=n:
            total,k=total+term(k),k+1
        return total

    def sum_naturals(n):
        return summation(n,identity)

    def sum_cubes(n):
        return summation(n,cube)

    def pi_sum(n):
        return summation(n,pi_term)
    ```

第二种情况：将函数作为返回值返回。

!!! Example
    **使用高阶函数构造加法器。**

    ```py linenums="1"
    def make_adder(n):
        """Return a function that takes one argument K and return K+N.

        >>> add_three=make_adder(3)
        >>> add_three(4)
        7
        """
        def adder(k):
            return k+n
        return adder

    >>> make_adder(1)(2)
    3
    ```

**decorators:**

decorator是一种高阶函数，其接受一个函数作为输入，并返回一个新的函数。decorator的作用是在不改变原函数的情况下，为其添加新的功能。

考虑以下斐波那契函数`fib`：

```py
def fib(n):
    if n==0 or n==1:
        return n
    else:
        return fib(n-1) + fib(n-2)
```

在不影响原函数的情况下，使用decorator`count`为其添加一个计数功能，将结果放在`call_count`中：

```py
def count(f):
    def counted(n):
        counted.call_count+=1
        return f(n)
    counted.call_count=0
    return counted
```

对`fib`进行包装，注意一定要`fib=count(fib)`，不可以`fib2=count(fib)`等，因为要保证递归调用还是经过包装，否则`call_count`不会被记录：

```py
>>> fib=count(fib)
>>> fib(5)
5
>>> fib.call_count
15
>>> fib(30)
832040
>>> fib.call_count
2692567
```

以下是另一种decorator，用于加速程序运行时间，记住之前的计算结果：

```py
def memo(f):
    cache={}
    def memoized(n):
        if n not in cache:
            cache[n]=f(n)
        return cache[n]
    return memoized
```

对`fib`进行包装，可以很大程度上提升运行速度。

**Lambda Expression:**

Lambda表达式是一种匿名函数，用于定义短小、简单的函数。

```py
lambda x1,x2,...: expression
```

其中，`x1,x2,...`为形参，`expression`为返回结果。

!!! Example
    **平方函数。**

    ```py linenums="1"
    >>> square = lambda x: x*x
    >>> square(4)
    16
    >>> square(10)
    100
    >>> (lambda x: x*x)(3)
    9
    ```

!!! Note
    Lambda表达式和`def`语句的不同之处在于：`def`语句给了函数一个内置名称，而Lambda表达式没有。

    ```py linenums="1"
    >>> square=lambda x:x*x
    >>> square
    <function <lambda> at 0x000002B375BEBBA0>

    >>> def square(x):
    ...     return x*x
    ... 
    >>> square
    <function square at 0x000002B375C48900>
    ```

**Function Currying：**

函数柯里化是指将一个接收多个参数的函数转换为一系列接收单个参数的函数。柯里化的函数每次只接收一个参数，然后返回一个新的函数，接收下一个参数，直到所有参数都接收完毕后返回最终结果。

!!! Example 
    ```py linenums="1"
    def make_adder(n):
        return lambda k:n+k

    >>> add(2,3)
    5
    >>> make_adder(2)(3)
    5
    ```

    `make_adder`和`add`之间的关系可以表示为：

    ```py linenums="1"
    def curry2(f):
        def g(x):
            def h(y):
                return f(x,y)
            return h
        return g

    >>> add(2,3)
    5
    >>> m=curry2(add)
    >>> add_three=m(3)
    >>> add_three(2)
    5
    ```

***

## 1.3 Data Abstraction

**Data Abstraction:**

数据抽象让我们可以将复合对象作为一个单元来操作。

数据抽象是一种方法论，函数强制在数据的表示和使用之间建立一个抽象屏障。

**Rational Numbers:**

函数`rational(n,d)`是一个constructor，返回一个有理数`x`；

函数`numer(x)`和`denom(x)`是两个selectors，分别返回`x`的分子和分母。

```py
from fractions import gcd

def rational(n,d):
    """Construct a rational number that represents N/D."""
    g=gcd(n,d)
    return [n//g,d//g]

def numer(x):
    """Return the numerator of rational number X."""
    return x[0]

def denom(x):
    """Return the denominator of rational number X."""
    return x[1]
```

```py
def mul_rational(x,y):
    return rational(numer(x)*numer(y),denom(x)*denom(y))

def add_rational(x,y):
    nx,dx=numer(x),denom(x)
    ny,dy=numer(y),denom(y)
    return rational(nx*dy+ny*dx,dx*dy)

def equal_rational(x,y):
    return numer(x)*denom(y)==numer(y)*denom(x)  
```

**Abstraction Barriers:**

Parts of the program that...|Treat rationals as|Using
---|---|---
Use rational numbers to perform computation|whole data values|`add_rational`, `mul_rational`, `equal_rational`
Create rationals or implement rational operations|numerators and denominators|`rational`, `numer`, `denom`
Implement selectors and constructors for rationals|two-element lists|list literals and element selection

***

## 1.4 Examples

!!! Example
    **Prime Factorization 质因式分解：**

    ```py linenums="1"
    def prime_factor(n):
        """Print the prime factors of n in non-decreasing order.
        >>> prime_factor(858)
        2
        3
        11
        13
        """
        while n>1:
            k=smallest_prime_factor(n)
            n=n//k
            print(k)

    def smallest_prime_factor(n):
        """Return the smallest k>1 that evenly divides n."""
        k=2
        while n%k!=0:
            k=k+1
        return k
    ```

!!! Example
    **Fibonacci Sequence 斐波那契数列：**

    ```py linenums="1"
    def fib(n):
        pred,curr=0,1
        k=1
        while k<n:
            pred,curr=curr,pred+curr
        return curr
    ```

    当 n = 0 时，为了保证程序能够输出第零个斐波那契数为0，可将代码改为：

    ```py linenums="1"
    def fib(n):
        pred,curr=1,0
        k=0
        while k<n:
            pred,curr=curr,pred+curr
        return curr
    ```

    tree recursion版本：

    ```py linenums="1"
    def fib(n):
        if n==0:
            return 0
        elif n==1:
            return 1
        else:
            return fib(n-2)+fib(n-1)
    ```

!!! Example
    **Digit Sums: 将一个数所有位的数字相加求和。**

    ```py linenums="1"
    def split(n):
        """Split positive n into all but its last digit and its last digit."""
        return n//10,n%10

    def sum_digits(n):
        """Return the sum of the digits of positive integer n."""
        if n<10:
            return n
        else:
            all_but_last,last=split(n)
            return sum_digits(all_but_last)+last
    ```

!!! Example
    **The Luhn Algorithm:**

    !!! Success "Definition"
        **Luhn算法（Luhn Algorithm）**：    
        也称为模10算法，是一种简单的校验和算法，一般用于验证身份识别码。  
        最右位为校验位（check digit），向左按位移动，每到偶数位则翻倍。若翻倍后大于9（例如：7*2=14），则将乘积的各位和作为新的一位（例如：10：1+0=1，14：1+4=5）。

        位数（从右往左）|第6位|第5位|第4位|第3位|第2位|第1位    
        ---|---|---|---|---|---|--- 
        **原始序列**|1|3|8|7|4|3    
        **新序列**|2|3（不变）|1+6=7|7（不变）|8|3（不变）  

        将新序列的各位相加得到30，其为10的整数倍，任何一位改变都不再是10的整数倍。

    ```py linenums="1"
    def split(n):
        """Split positive n into all but its last digit and its last digit."""
        return n//10,n%10

    def sum_digits(n):
        """Return the sum of the digits of positive integer n."""
        if n<10:
        return n
        else:
            all_but_last,last=split(n)
            return sum_digits(all_but_last)+last

    def luhn_sum(n):
        if n<10:
            return n
        else:
            all_but_last,last=split(n)
            return luhn_sum_double(all_but_last)+last

    def luhn_sum_double(n):
        all_but_last,last=split(n)
        luhn_digit=sum_digit(2*last)
        if n<10:
            return luhn_digit
        else:
            return luhn_sum(all_but_last)+luhn_digit
    ```

!!! Example
    **Cascade:**

    ```py linenums="1"
    # Version1
    def cascade(n):
        if n<10:
            print(n)
        else:
            print(n)
            cascade(n//10)
            print(n)

    # Version2
    def cascade(n):
        print(n)
        if n>=10:
            cascade(n//10)
            print(n)

    >>> cascade(12345)
    12345
    1234
    123
    12
    1
    12
    123
    1234
    12345
    ```

!!! Example
    **Inverse Cascade:**

    ```py linenums="1"
    def inverse_cascade(n):
        grow(n)
        print(n)
        shrink(n)

    def f_then_g(f,g,n):
        if n:
            f(n)
            g(n)

    grow=lambda n: f_then_g(grow,print,n//10)
    shrink=lambda n: f_then_g(print,shrink,n//10)

    >>> inverse_cascade(1234)
    1
    12
    123
    1234
    123
    12
    1
    ```

!!! Example
    **Counting Patition: 给定一个正整数`n`，对其进行划分。再给定一个正整数`m`，表示划分的最大部分不超过`m`，现在要计算划分的总可能数。**

    `count_partitions(6,4)` 

    2+4=6   
    1+1+4=6     
    3+3=6   
    1+2+3=6     
    1+1+1+3=6   
    2+2+2=6     
    1+1+2+2=6   
    1+1+1+1+2=6     
    1+1+1+1+1+1=6

    ```py linenums="1"
    def count_partitions(n,m):
        if n==0:
            return 1
        elif n<0:
            return 0
        elif m==0:
            return 0
        else:
            with_m=count_partitions(n-m,m)
            without_m=count_partitions(n,m-1)
            return with_m+without_m
    ```