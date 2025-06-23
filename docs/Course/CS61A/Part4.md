---
comments: true
---

<span style="font-family: 'Times New Roman';">

# Part4 Scheme

***

## 4.1 Scheme Basics

Scheme语言是Lisp语言的方言之一，由表达式组成，可以是基本表达式，如`2`，`3.3`，`+`，`quotient`等；也可以是组合，如`(quotient 10 2)`，`(not true)`等，组合需要使用括号。

```scheme linenums="1" 
scm> (quotient 10 2)
5
scm> (quotient (+ 8 7) 5)
3
```

在Scheme中，`quotient`等被称为**procedure 过程**。一些过程支持两个以上参数，也可以无参数：

```scheme linenums="1" 
scm> (+ 1 2 3 4)
10
scm> (+)
0
scm> (* 1 2 3 4)
24
scm> (*)
1
```

`number?`，`zero?`，`integer?`等过程返回布尔值：

```scheme linenums="1" 
scm> (number? +) 
#f
scm> (number? 3)
#t
scm> (zero? 2)   
#f
scm> (zero? 0) 
#t
scm> (integer? 2.2)
#f
scm> (integer? 2) 
#t
```

**`if` Statement:**

```scheme linenums="1"
(if <predicate> <consequent> <alternative>)
```

**`define` Statement:**

`define`的第一个作用是绑定符号：

```scheme linenums="1"
(define <symbol> <expression>)
```

例如：

```scheme linenums="1"
scm> (define (abs x)
             (if (< x 0)
                 (- x)
                 x))
```

`define`的第二个作用是创建新的过程：

```scheme linenums="1"
(define (<symbol> <formal parameters>) <body>)
```

例如：

```scheme linenums="1"
scm> (define (square x) (* x x))
square
scm> (square 16)
256
scm> (define (average x y)
        (/ (+ x y) 2))    
average
scm> (average 3 7)
5
```

通过`define`可以构建递归函数：

```scheme linenums="1"
scm> (define (sqrt x)  ;牛顿迭代法求平方根
             (define (update guess)
                     (if (= (square guess) x)
                         guess
                         (update (average guess (/ x guess)))))
             (update 1))
sqrt
scm> (sqrt 256)
16
```

**Lambda Expressions:**

```scheme linenums="1"
(lambda (<formal-parameter>) <body>)
```

以下两式等价：

```scheme linenums="1"
(define (plus4 x) (+ x 4))            ;New procedure

(define plus4 (lambda (x) (+ x 4)))   ;Binding symbol
```

**`cond` Statement:**

`cond`用于多重条件判断，类似于Python中的`if-elif-else`。

Python代码：

```py linenums="1"
if x>10:
    print('big')
elif x>5:
    print('medium')
else:
    print('small')
```

Scheme代码：

```scheme linenums="1"
; 写法一
(cond ((> x 10) (print 'big))
      ((> x 5)  (print 'medium))
      (else     (print 'small)))

; 写法二
(print
    (cond ((> x 10) 'big)
          ((> x 5)  'medium)
          (else     'small)))
```

**`begin` Statement:**

`begin`用于将多个表达式合并为一个表达式，值为最后一个表达式的值。

Python代码：

```py linenums="1"
if x>10:
    print('big')
    print('guy')
else:
    print('small')
    print('fry')
```

Scheme代码：

```scheme linenums="1"
(if (> x 10) (begin
                (print 'big)
                (print 'guy))
             (begin
                (print 'small)
                (print 'fry)))
```

**`let` Statement:**

`let`与`define`类似，但不同之处在于其只是临时地将符号绑定到一个表达式的值。

Python代码：

```py linenums="1"
a=3
b=2+2
c=math.sqrt(a*a+b*b)
```

`a`和`b`被绑定。

Scheme代码：

```scheme linenums="1"
(define c (let ((a 3)
                (b (+ 2 2)))
                (sqrt (+ (* a a) (* b b)))))
```

`a`和`b`未被绑定，或者说`a`和`b`的临时绑定在计算完`c`后就解除了。

***

## 4.2 Scheme Lists

**List Procedures:**

* `cons`：创建列表
* `car`：获取列表的第一个元素
* `cdr`：获取列表的剩余部分
* `nil`：表示空列表

```scheme linenums="1"
scm> (cons 1 (cons 2 nil))
(1 2)
scm> (define s (cons 1 (cons 2 nil)))
scm> s
(1 2)
scm> (car s)
1
scm> (cdr s)
(2)
scm> (cons (cons 4 (cons 3 nil)) s)
((4 3) 1 2)
scm> (car (cons (cons 4 (cons 3 nil)) s))
(4 3)
scm> (car (car (cons (cons 4 (cons 3 nil)) s)))
4
scm> (cons s s)
((1 2) 1 2)
scm> (cons s (cons s nil))
((1 2) (1 2))
```

* `list?`：判断是否为列表
* `null?`：判断列表是否为空
* `list`：创建列表

```scheme linenums="1"
scm> (define s (cons 1 (cons 2 nil)))
s
scm> s
(1 2)
scm> (list? s)
#t
scm> (list? nil)
#t
scm> (null? s)
#f
scm> (null? nil)
#t
scm> (list 1 2 3 4)
(1 2 3 4)
```

* `(append s1 s2)`：将两个（或多个）列表的元素放到一个列表中
* `(map f s)`：对列表中的每个元素应用函数`f`，返回一个新列表
* `(filter f s)`：对列表中的每个元素应用函数`f`，返回结果为真的元素组成的列表
* `(apply f s)`：对完整的列表应用函数`f`

```scheme linenums="1"
scm> (define s (cons 1 (cons 2 nil)))
s
scm> s
(1 2)
scm> (append s s)
(1 2 1 2)
scm> (append s s s s)
(1 2 1 2 1 2 1 2)
scm> (list s s s s)
((1 2) (1 2) (1 2) (1 2))
scm> (map even? s)
(#f #t)
scm> (map (lambda (x) (* 2 x)) s)
(2 4)
scm> (filter even? s)
(2)
scm> (filter even? '(5 6 7 8 9))
(6 8)
scm> (filter list? '(5 (6 7) 8 (9)))
((6 7) (9))
scm> (map (lambda (s) (cons 5 s)) (filter list? '(5 (6 7) 8 (9))))
((5 6 7) (5 9))
scm> (apply quotient '(10 5)) 
2
scm> (apply + '(1 2 3 4))
10
scm> (+ 1 2 3 4)         
10
scm> (map + '(1 2 3 4))
(1 2 3 4)
scm> (list (+ 1) (+ 2) (+ 3) (+ 4))
(1 2 3 4)
```

!!! Example

    **Even Subsets: 找到一个列表的所有偶数子集（元素之和为偶数）。**

    ```scheme linenums="1"
    (define (even-subsets s) 
        (if (null? s) nil 
            (append (even-subsets (cdr s)) 
                (map (lambda (t) (cons (car s) t)) 
                    (if (even? (car s)) 
                        (even-subsets (cdr s)) 
                        (odd-subsets (cdr s))))
                (if (even? (car s)) (list (list (car s))) nil))))

    (define (odd-subsets s) 
        (if (null? s) nil 
            (append (odd-subsets (cdr s)) 
                (map (lambda (t) (cons (car s) t)) 
                    (if (odd? (car s)) 
                        (odd-subsets (cdr s)) 
                        (even-subsets (cdr s))))
                (if (odd? (car s)) (list (list (car s))) nil))))
    ```

    减少重复代码的写法：

    ```scheme linenums="1"
    (define (even-subsets s) 
        (if (null? s) nil 
            (append (even-subsets (cdr s)) 
                (subset-helper even? s))))

    (define (odd-subsets s) 
        (if (null? s) nil 
            (append (odd-subsets (cdr s)) 
                (subset-helper odd? s))))
            
    (define subset-helper f s 
        (append
            (map (lambda (t) (cons (car s) t)) 
                (if (f (car s)) 
                    (even-subsets (cdr s)) 
                    (odd-subsets (cdr s))))
            (if (f (car s)) (list (list (car s))) nil)))
    ```

***

## 4.3 Tail Calls

一个过程调用另一个过程，若调用位于最后一步，调用结束后没有更多的工作要做，则称为尾调用（tail call）。

尾调用是尾上下文（tail context）中的调用表达式，尾上下文分为：

* 函数/Lambda表达式的最后一个子表达式（确定返回值的那个）
* 尾上下文中`if`语句的第二个和第三个子表达式（`if`语句有三个表达式，分别是谓词、结果和替代项）
* 尾上下文中`cond`语句的非谓词部分
* 尾上下文中`and`、`or`语句的最后一个子表达式
* 尾上下文中`begin`语句的最后一个子表达式

!!! Example
    **Length of a List**

    非尾调用：
    ```scheme linenums="1"
    (define (length s) 
            (if (null? s) 0
                (+ 1 (length (cdr s)))))
    ```

    尾调用：
    ```scheme linenums="1"
    (define (length-tail s) 
            (define (length-iter s n) 
                    (if (null? s) n 
                        (length-iter (cdr s) (+ 1 n))))
            (length-iter s 0))
    ```
    
***

## 4.4 Quotation

**Quotation:**

单引号（'）和`quote`是完全等价的，它们的作用都是阻止求值，将表达式直接当作数据而非代码处理。

```scheme linenums="1"
scm> 'a
a
scm> (quote a)
a
scm> (cons 'a nil)
(a)
scm> (cons (quote a) nil)
(a)
scm> '(1 2)
(1 2)
scm> '(1 a)
(1 a)
scm> (list 1 'a)
(1 a)
scm> '(1 (2 3) 4)
(1 (2 3) 4)
scm> (car (cdr (car (cdr '(1 (2 3) 4)))))
3
scm> (car (cdr (car (cdr '(a (b c) d))))) 
c   
```

**Quasiquotation:**

准引用（quasiquotation）与普通引用的区别在于：普通引用（使用单引号`'`）完全阻止求值，而准引用（使用反引号`` ` ``）允许部分求值，只要标记出来（使用逗号`,`）就行。

直接使用没有区别：

```scheme linenums="1"
scm> '(a b)
(a b)
scm> `(a b)
(a b)
```

使用逗号`,`取消引用后有所区别：

```scheme linenums="1"
scm> (define b 4)
b
scm> '(a ,(+ b 1))
(a (unquote (+ b 1)))
scm> `(a ,(+ b 1))
(a 5)
```

!!! Example
    **从2到9，求偶数的平方和。**

    ```scheme linenums="1"
    (begin
          (define (f x total) 
                  (if (< x 10) 
                      (f (+ x 2) (+ total (* x x)))
                      total))
          (f 2 0))
    ```

    如果不是2到9而是其他的数，如果不是求和，如果不是平方，又该如何应对？这时候我们考虑为所有情况编写Scheme表达式。

    ```scheme linenums="1"
    (define (sum-while initial-x condition add-to-total update-x)
            `(begin
                   (define (f x total) 
                           (if ,condition 
                           (f ,update-x (+ total ,add-to-total))
                           total))
                   (f ,initial 0)))

    scm> (define result (sum-while 1 '(< (* x x) 50) 'x '(+ x 1)))
    result
    >scm result
    (begin (define (f x total) (if (< (* x x) 50) (f (+ x 1) (+ total x)) total)) (f 1 0))
    scm> (list? result)
    #t
    scm> (car result)
    begin
    scm> (eval result)
    28
    scm> (eval (sum-while 2 '(< x 10) '(* x x) '(+ x 2)))
    120
    ```

**Macros:**

Scheme中的宏（macro）允许定义新的特殊语句（已有的特殊语句包括`if`, `cond`, `and`, `or`等），使用`define-macro`。

```scheme linenums="1"
scm> (define-macro (twice expr) (list 'begin expr expr))
twice
scm> (twice (print 2)) ; (begin (print 2) (print 2))
2
2
```

普通定义的过程在调用前会先对所有参数表达式进行求值，再把求值结果传给过程本身。

宏定义的过程在调用时不会对参数表达式进行求值，而是将参数表达式原封不动地传给宏本身，再由宏本身决定如何处理参数表达式。

```scheme linenums="1"
scm> (define (twice expr) (list 'begin expr expr))
scm> (twice (print 2))
2
(begin None None)

scm> (define-macro (twice expr) (list 'begin expr expr))
twice
scm> (twice (print 2))
2
2
```

!!! Example
    **设计一个`check`宏，检查表达式的真假。**

    ```scheme linenums="1"
    scm> (define (check val) (if val 'passed 'failed))
    check
    scm> (define x -2)
    x
    scm> (check (> x 0))
    failed
    ```

    现在不仅想知道对与错，还想知道错在哪儿（打印出原本的表达式）：

    ```scheme linenums="1"
    scm> (define-macro (check expr) 
                       (list 'if expr ''passed (list 'quote(list 'failed: expr))))
    check
    scm> (define x -2)
    x
    scm> (check (> x 0))
    (failed: (> x 0))
    ```

!!! Example
    **设计一个`for`宏，类似于Python中的`for`语句。**

    不使用宏定义：
    ```scheme linenums="1"
    scm> (define (map fn vals) 
                 (if (null? vals) 
                     () 
                     (cons (fn (car vals)) 
                           (map fn (cdr vals)))))
    map
    scm> (map (lambda (x) (* x x)) '(2 3 4 5))
    (4 9 16 25)
    ```

    定义`for`宏：
    ```scheme linenums="1"
    (define-macro (for sym vals expr) 
                  (list 'map (list 'lambda (list sym) expr) vals))
    for
    scm> (for x '(2 3 4 5) (* x x))
    (4 9 16 25)
    ```

**Tracing Recursive Calls:**

在Python中，我们有如下的实现：

```py linenums="1"
# 定义了一个装饰器trace
def trace(fn):
    def traced(n):
        print(f'{fn.__name__}({n})') # f-string
        return fn(n)
    return traced

@trace # 语法糖，相当于fact=trace(fact)
def fact(n):
    if n==0:
        return 1
    else:
        return n*fact(n-1)
```

在Scheme中，可以不用宏实现：

```scheme linenums="1"
(define fact (lambda (n) (if (zero? n) 1 (* n (fact (- n 1))))))
(define original fact)
(define fact (lambda (n) (print (list 'fact n)) (original n)))
```

整合一下：

```scheme linenums="1"
(begin 
      (define original fact)    ; 将fact的原始定义保存在original中 
      (define fact (lambda (n) (print (list 'fact n)) (original n)))    ; 重新定义fact，进行修饰
      (define result (fact 5))    ; 调用fact，print并得到结果
      (define fact original)    ; 恢复原始定义
      result)   ; 最后一个表达式为返回结果
```

二者不同之处在于，Python的两套定义的独立性比较好，如果换个函数trace也能用；但Scheme的写法针对的就是“阶乘”这个函数。

用宏进行泛化：

```scheme linenums="1"
(define-macro (trace expr)
              (define operator (car expr))
             `(begin 
                    (define original ,operator)
                    (define ,operator (lambda (n) (print (list (quote ,operator) n)) (original n)))
                    (define result ,expr)
                    (define ,operator original)
                    result))
```