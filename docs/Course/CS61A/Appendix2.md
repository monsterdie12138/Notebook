---
comments: true
---

<span style="font-family: 'Times New Roman';">

# Appendix2 Lab

***

## Lab1

### Q1: Return and Print

```py linenums="1"
>>> def welcome():
...     print('Go')
...     return 'hello'
>>> def cal():
...     print('Bears')
...     return 'world'
>>> welcome()
(line 1)? Go
(line 2)? 'hello'
-- OK! --

>>> print(welcome(), cal())
(line 1)? Go           
(line 2)? Bears 
(line 3)? hello world 
-- OK! --
```

### Q2: Pick a Digit

Implement `digit`, which takes positive integers `n` and `k` and has only a single return statement as its body. It returns the digit of `n` that is `k` positions to the left of the rightmost digit (the one's digit). If `k` is 0, return the rightmost digit. If there is no digit of n that is `k` positions to the left of the rightmost digit, return 0.

```py linenums="1"
def digit(n, k):
    """Return the digit that is k from the right of n for positive integers n and k.

    >>> digit(3579, 2)
    5
    >>> digit(3579, 0)
    9
    >>> digit(3579, 10)
    0
    """
    return n//pow(10,k)%10
```

### Q3: Middle Number

Implement `middle` by writing a single return expression that evaluates to the value that is neither the largest or smallest among three different integers `a`, `b`, and `c`.

```py linenums="1"
def middle(a, b, c):
    """Return the number among a, b, and c that is not the smallest or largest.
    Assume a, b, and c are all different numbers.

    >>> middle(3, 5, 4)
    4
    >>> middle(30, 5, 4)
    5
    >>> middle(3, 5, 40)
    5
    >>> middle(3, 5, 40)
    5
    >>> middle(30, 5, 40)
    30
    """
    return a+b+c-max(a,b,c)-min(a,b,c)
```

### Q4: Falling Factorial

Let's write a function `falling`, which is a "falling" factorial that takes two arguments, `n` and `k`, and returns the product of `k` consecutive numbers, starting from `n` and working downwards. When `k` is 0, the function should return 1.

```py linenums="1"
def falling(n, k):
    """Compute the falling factorial of n to depth k.

    >>> falling(6, 3)  # 6 * 5 * 4
    120
    >>> falling(4, 3)  # 4 * 3 * 2
    24
    >>> falling(4, 1)  # 4
    4
    >>> falling(4, 0)
    1
    """
    if k==0:
        return 1
    elif k==1:
        return n
    else:
        return n*falling(n-1,k-1)
```

### Q5: Divisible By k

Write a function `divisible_by_k` that takes positive integers `n` and `k`. It prints all positive integers less than or equal to `n` that are divisible by `k` from smallest to largest. Then, it returns how many numbers were printed.

```py linenums="1"
def divisible_by_k(n, k):
    """
    >>> a = divisible_by_k(10, 2)  # 2, 4, 6, 8, and 10 are divisible by 2
    2
    4
    6
    8
    10
    >>> a
    5
    >>> b = divisible_by_k(3, 1)  # 1, 2, and 3 are divisible by 1
    1
    2
    3
    >>> b
    3
    >>> c = divisible_by_k(6, 7)  # There are no integers up to 6 divisible by 7
    >>> c
    0
    """
    i=1
    j=0
    while i<=n:
        if i%k==0:
            print(i)
            j+=1
        i+=1
    return j
```

### Q6: Sum Digits

Write a function that takes in a nonnegative integer and sums its digits. (Using floor division and modulo might be helpful here!)

```py linenums="1"
def sum_digits(y):
    """Sum all the digits of y.

    >>> sum_digits(10) # 1 + 0 = 1
    1
    >>> sum_digits(4224) # 4 + 2 + 2 + 4 = 12
    12
    >>> sum_digits(1234567890)
    45
    >>> a = sum_digits(123) # make sure that you are using return rather than print
    >>> a
    6
    """
    sum=0
    while y>0:
        sum+=y%10
        y//=10
    return sum
```

### Q7: WWPD: What If?

```py linenums="1"
>>> def ab(c, d):
...     if c > 5:
...         print(c)
...     elif c > 7:
...         print(d)
...     print('foo')
>>> ab(10, 20)
(line 1)? 10
(line 2)? foo
-- OK! --

>>> def bake(cake, make):
...    if cake == 0:
...        cake = cake + 1
...        print(cake)
...    if cake == 1:
...        print(make)
...    else:
...        return cake
...    return make
>>> bake(0, 29)
(line 1)? 1
(line 2)? 29
(line 3)? 29
-- OK! --

>>> bake(1, "mashed potatoes")
(line 1)? mashed potatoes
(line 2)? "mashed potatoes" 
-- OK! --
```

### Q8: Double Eights

Write a function that takes in a number and determines if the digits contain two adjacent 8s.

```py linenums="1"
def double_eights(n):
    """Return true if n has two eights in a row.
    >>> double_eights(8)
    False
    >>> double_eights(88)
    True
    >>> double_eights(2882)
    True
    >>> double_eights(880088)
    True
    >>> double_eights(12345)
    False
    >>> double_eights(80808080)
    False
    """
    i=0
    flag=0
    while n>0:
        if n%10==8:
            if i==0:
                i+=1
            else:
                flag=1
        else:
            i=0
        n//=10
    return flag==1
```

***

## Lab2

### Q1: WWPD: The Truth Will Prevail

```py linenums="1"
>>> True and 13
? 13
-- OK! --

>>> False or 0
? 0
-- OK! --

>>> not 10
? False
-- OK! --

>>> not None
? True
-- OK! --

>>> True and 1 / 0  # If this errors, just type Error.    
? Error
-- OK! --

>>> True or 1 / 0  # If this errors, just type Error.     
? True
-- OK! --

>>> -1 and 1 > 0 # If this errors, just type Error.       
? True
-- OK! --

>>> -1 or 5
? -1
-- OK! --

>>> (1 + 1) and 1  # If this errors, just type Error. If this is blank, just type Nothing.
? 1
-- OK! --

>>> print(3) or ""
(line 1)? 3
(line 2)? ""
-- OK! --

>>> def f(x):
...     if x == 0:
...         return "zero"
...     elif x > 0:
...         return "positive"
...     else:
...         return ""
>>> 0 or f(1)
? "positive" 
-- OK! --

>>> f(0) or f(-1)
? "zero"
-- OK! --

>>> f(0) and f(-1)
? ""
-- OK! --
```

### Q2: WWPD: Higher-Order Functions

```py linenums="1"
>>> # If Python displays <function...>, type Function, if 
it errors type Error, if it displays nothing type Nothing 
>>> def cake():
...    print('beets')
...    def pie():
...        print('sweets')
...        return 'cake'
...    return pie
>>> chocolate = cake()
? beets
-- OK! --

>>> chocolate
? Function
-- OK! --

>>> chocolate()
(line 1)? sweets
(line 2)? 'cake'
-- OK! --

>>> more_chocolate, more_cake = chocolate(), cake
? sweets
-- OK! --

>>> more_chocolate
? 'cake'
-- OK! --

>>> def snake(x, y):
...    if cake == more_cake:
...        return chocolate
...    else:
...        return x + y
>>> snake(10, 20)
? Function
-- OK! --

>>> snake(10, 20)()
(line 1)? sweets
(line 2)? 'cake'
-- OK! --

>>> cake = 'cake'
>>> snake(10, 20)
? 30
-- OK! --
```

### Q3: WWPD: Lambda

```py linenums="1"
Q: Which of the following statements describes a difference between a def statement and a lambda expression?        
Choose the number of the correct choice:
0) A def statement can only have one line in its body.    
1) A lambda expression cannot have more than two parameters.
2) A lambda expression cannot return another function.    
3) A lambda expression does not automatically bind the function that it returns to a name.
? 3
-- OK! --

Q: How many formal parameters does the following lambda expression have?
lambda a, b: c + d
Choose the number of the correct choice:
0) three
1) one
2) Not enough information
3) two
? 3
-- OK! --

Q: When is the return expression of a lambda expression executed?
Choose the number of the correct choice:
0) When you pass the lambda expression into another function.
1) When you assign the lambda expression to a name.       
2) When the lambda expression is evaluated.
3) When the function returned by the lambda expression is 
called.
? 3
-- OK! --

>>> # If Python displays <function...>, type Function, if 
it errors type Error, if it displays nothing type Nothing 
>>> lambda x: x  # A lambda expression with one parameter 
x
? Function
-- OK! --

>>> a = lambda x: x  # Assigning a lambda function to the 
name a
>>> a(5)
? 5
-- OK! --

>>> (lambda: 3)()  # Using a lambda expression as an operator in a call exp.
? 3
-- OK! --

>>> b = lambda x, y: lambda: x + y # Lambdas can return other lambdas!
>>> c = b(8, 4)
>>> c
? Function
-- OK! --

>>> c()
? 12
-- OK! --

>>> d = lambda f: f(4)  # They can have functions as arguments as well
>>> def square(x):
...     return x * x
>>> d(square)
? 16
-- OK! --
```

### Q4: Composite Identity Function

Write a function that takes in two single-argument functions, `f` and `g`, and returns another function that has a single parameter x. The returned function should return `True` if `f(g(x))` is equal to `g(f(x))` and `False` otherwise. You can assume the output of `g(x)` is a valid input for `f` and vice versa.

```py linenums="1"
def composite_identity(f, g):
    """
    Return a function with one parameter x that returns True if f(g(x)) is
    equal to g(f(x)). You can assume the result of g(x) is a valid input for f
    and vice versa.

    >>> add_one = lambda x: x + 1        # adds one to x
    >>> square = lambda x: x**2          # squares x [returns x^2]
    >>> b1 = composite_identity(square, add_one)
    >>> b1(0)                            # (0 + 1) ** 2 == 0 ** 2 + 1
    True
    >>> b1(4)                            # (4 + 1) ** 2 != 4 ** 2 + 1
    False
    """
    def h(x):
        return f(g(x))==g(f(x))
    return h
```

### Q5: Count Cond

Write a function `count_cond`, which takes in a two-argument predicate function `condition(n, i)`. `count_cond` returns a one-argument function that takes in `n`, which counts all the numbers from 1 to `n` that satisfy `condition` when called.

```py linenums="1"
def count_cond(condition):
    """Returns a function with one parameter N that counts all the numbers from
    1 to N that satisfy the two-argument predicate function Condition, where
    the first argument for Condition is N and the second argument is the
    number from 1 to N.

    >>> count_fives = count_cond(lambda n, i: sum_digits(n * i) == 5)
    >>> count_fives(10)   # 50 (10 * 5)
    1
    >>> count_fives(50)   # 50 (50 * 1), 500 (50 * 10), 1400 (50 * 28), 2300 (50 * 46)
    4

    >>> is_i_prime = lambda n, i: is_prime(i) # need to pass 2-argument function into count_cond
    >>> count_primes = count_cond(is_i_prime)
    >>> count_primes(2)    # 2
    1
    >>> count_primes(3)    # 2, 3
    2
    >>> count_primes(4)    # 2, 3
    2
    >>> count_primes(5)    # 2, 3, 5
    3
    >>> count_primes(20)   # 2, 3, 5, 7, 11, 13, 17, 19
    8
    """
    def f(n):
        i=1
        count=0
        while i<=n:
            if condition(n,i):
                count+=1
            i+=1
        return count
    return f
```

### Q6: Multiple

Write a function that takes in two numbers and returns the smallest number that is a multiple of both.

```py linenums="1"
def multiple(a, b):
    """Return the smallest number n that is a multiple of both a and b.

    >>> multiple(3, 4)
    12
    >>> multiple(14, 21)
    42
    """
    i=max(a,b)
    while 1:
        if i%min(a,b)==0:
            return i
        i+=max(a,b)
```

### Q7: I Heard You Liked Functions...

Define a function `cycle` that takes in three functions `f1`, `f2`, and `f3`, as arguments. `cycle` will return another function `g` that should take in an integer argument `n` and return another function `h`. That final function h should take in an argument `x` and cycle through applying `f1`, `f2`, and `f3` to `x`, depending on what `n` was. Here's what the final function `h` should do to `x` for a few values of `n`:

* `n = 0`, return `x`
* `n = 1`, apply `f1` to `x`, or return `f1(x)`
* `n = 2`, apply `f1` to `x` and then `f2` to the result of that, or return `f2(f1(x))`
* `n = 3`, apply `f1` to `x`, `f2` to the result of applying `f1`, and then `f3` to the result of applying `f2`, or `f3(f2(f1(x)))`
* `n = 4`, start the cycle again applying `f1`, then `f2`, then `f3`, then `f1` again, or `f1(f3(f2(f1(x))))`
* And so forth.

```py linenums="1"
def cycle(f1, f2, f3):
    """Returns a function that is itself a higher-order function.

    >>> def add1(x):
    ...     return x + 1
    >>> def times2(x):
    ...     return x * 2
    >>> def add3(x):
    ...     return x + 3
    >>> my_cycle = cycle(add1, times2, add3)
    >>> identity = my_cycle(0)
    >>> identity(5)
    5
    >>> add_one_then_double = my_cycle(2)
    >>> add_one_then_double(1)
    4
    >>> do_all_functions = my_cycle(3)
    >>> do_all_functions(2)
    9
    >>> do_more_than_a_cycle = my_cycle(4)
    >>> do_more_than_a_cycle(2)
    10
    >>> do_two_cycles = my_cycle(6)
    >>> do_two_cycles(1)
    19
    """
    def func1(n):
        def func2(x):
            result=x
            i=1
            while i<=n:
                if i%3==1:
                    result=f1(result)
                elif i%3==2:
                    result=f2(result)
                else:
                    result=f3(result)
                i+=1
            return result
        return func2
    return func1
```

***

## Lab3

### Q1: WWPD: Lists & Ranges

Predict what Python will display when you type the following into the interactive interpreter. Then try it to check your answers.

```py linenums="1"
>>> s = [7//3, 5, [4, 0, 1], 2]
>>> s[0]
? 2
-- OK! --

>>> s[2]
? [4,0,1]
-- OK! --

>>> s[-1]
? 2
-- OK! --

>>> len(s)
? 4
-- OK! --

>>> 4 in s
? False
-- OK! --

>>> 4 in s[2]
? True
-- OK! --

>>> s[2] + [3 + 2]
? [4,0,1,5]
-- OK! --

>>> 5 in s[2]
? False
-- OK! --

>>> s[2] * 2
? [4,0,1,4,0,1]
-- OK! --

>>> list(range(3, 6))
? [3,4,5]
-- OK! --

>>> range(3, 6)
? range(3, 6)
-- OK! --

>>> r = range(3, 6)
>>> [r[0], r[2]]
? [3,5]
-- OK! --

>>> range(4)[-1]
? 3
-- OK! --
```

### Q2: Print If

Implement `print_if`, which takes a list `s` and a one-argument function `f`. It prints each element `x` of `s` for which `f(x)` returns a true value.

```py linenums="1"
def print_if(s, f):
    """Print each element of s for which f returns a true value.

    >>> print_if([3, 4, 5, 6], lambda x: x > 4)
    5
    6
    >>> result = print_if([3, 4, 5, 6], lambda x: x % 2 == 0)
    4
    6
    >>> print(result)  # print_if should return None
    None
    """
    for x in s:
        if f(x):
            print(x)
```

### Q3: Close

Implement `close`, which takes a list of numbers `s` and a non-negative integer `k`. It returns how many of the elements of `s` are within `k` of their index. That is, the absolute value of the difference between the element and its index is less than or equal to `k`.

```py linenums="1"
def close(s, k):
    """Return how many elements of s that are within k of their index.

    >>> t = [6, 2, 4, 3, 5]
    >>> close(t, 0)  # Only 3 is equal to its index
    1
    >>> close(t, 1)  # 2, 3, and 5 are within 1 of their index
    3
    >>> close(t, 2)  # 2, 3, 4, and 5 are all within 2 of their index
    4
    >>> close(list(range(10)), 0)
    10
    """
    count = 0
    for i in range(len(s)):  # Use a range to loop over indices
        if abs(s[i]-i)<=k:
            count+=1
    return count
```

### Q4: WWPD: List Comprehensions

```py linenums="1"
>>> [2 * x for x in range(4)]
? [0,2,4,6]
-- OK! --

>>> [y for y in [6, 1, 6, 1] if y > 2]
? [6,6]
-- OK! --

>>> [[1] + s for s in [[4], [5, 6]]]
? [[1,4],[1,5,6]]
-- OK! --

>>> [z + 1 for z in range(10) if z % 3 == 0]
? [1,4,7,10]
-- OK! --
```

### Q5: Close List

Implement `close_list`, which takes a list of numbers `s` and a non-negative integer `k`. It returns a list of the elements of `s` that are within `k` of their index. That is, the absolute value of the difference between the element and its index is less than or equal to `k`.

```py linenums="1"
def close_list(s, k):
    """Return a list of the elements of s that are within k of their index.

    >>> t = [6, 2, 4, 3, 5]
    >>> close_list(t, 0)  # Only 3 is equal to its index
    [3]
    >>> close_list(t, 1)  # 2, 3, and 5 are within 1 of their index
    [2, 3, 5]
    >>> close_list(t, 2)  # 2, 3, 4, and 5 are all within 2 of their index
    [2, 4, 3, 5]
    """
    return [s[i] for i in range(len(s)) if abs(i-s[i])<=k]
```

### Q6: Squares Only

Implement the function `squares`, which takes in a list of positive integers. It returns a list that contains the square roots of the elements of the original list that are perfect squares. Use a list comprehension.

```py linenums="1"
def squares(s):
    """Returns a new list containing square roots of the elements of the
    original list that are perfect squares.

    >>> seq = [8, 49, 8, 9, 2, 1, 100, 102]
    >>> squares(seq)
    [7, 3, 1, 10]
    >>> seq = [500, 30]
    >>> squares(seq)
    []
    """
    return [int(sqrt(n)) for n in s if sqrt(n)-int(sqrt(n))==0]
```

### Q7: Double Eights

Write a recursive function that takes in a positive integer `n` and determines if its digits contain two adjacent 8s (that is, two 8s right next to each other).

```py linenums="1"
def double_eights(n):
    """Returns whether or not n has two digits in row that
    are the number 8.

    >>> double_eights(1288)
    True
    >>> double_eights(880)
    True
    >>> double_eights(538835)
    True
    >>> double_eights(284682)
    False
    >>> double_eights(588138)
    True
    >>> double_eights(78)
    False
    >>> # ban iteration
    >>> from construct_check import check
    >>> check(LAB_SOURCE_FILE, 'double_eights', ['While', 'For'])
    True
    """
    if n==0:
        return False
    if n%10!=8:
        return double_eights(n//10)
    else:
        if n//10%10==8:
            return True
        else:
            return double_eights(n//10//10)
```

### Q8: Making Onions

Write a function `make_onion` that takes in two one-argument functions, `f` and `g`. It returns a function that takes in three arguments: `x`, `y`, and `limit`. The returned function returns `True` if it is possible to reach `y` from `x` using up to `limit` calls to `f` and `g`, and False otherwise.

For example, if `f` adds 1 and `g` doubles, then it is possible to reach 25 from 5 in four calls: `f(g(g(f(5))))`.

```py linenums="1"
def make_onion(f, g):
    """Return a function can_reach(x, y, limit) that returns
    whether some call expression containing only f, g, and x with
    up to limit calls will give the result y.

    >>> up = lambda x: x + 1
    >>> double = lambda y: y * 2
    >>> can_reach = make_onion(up, double)
    >>> can_reach(5, 25, 4)      # 25 = up(double(double(up(5))))
    True
    >>> can_reach(5, 25, 3)      # Not possible
    False
    >>> can_reach(1, 1, 0)      # 1 = 1
    True
    >>> add_ing = lambda x: x + "ing"
    >>> add_end = lambda y: y + "end"
    >>> can_reach_string = make_onion(add_ing, add_end)
    >>> can_reach_string("cry", "crying", 1)      # "crying" = add_ing("cry")
    True
    >>> can_reach_string("un", "unending", 3)     # "unending" = add_ing(add_end("un"))
    True
    >>> can_reach_string("peach", "folding", 4)   # Not possible
    False
    """
    def can_reach(x, y, limit):
        if limit < 0:
            return False
        elif x == y:
            return True
        else:
            return can_reach(f(x), y, limit - 1) or can_reach(g(x), y, limit - 1)
    return can_reach
```

***

## Lab4

### Q1: WWPD: Dictionaries

```py linenums="1"
>>> pokemon = {'pikachu': 25, 'dragonair': 148, 'mew': 151}
>>> pokemon['pikachu']
? 25
-- OK! --

>>> len(pokemon)
? 3
-- OK! --

>>> 'mewtwo' in pokemon
? False
-- OK! --

>>> 'pikachu' in pokemon
? True
-- OK! --

>>> 25 in pokemon
? False
-- OK! --

>>> 148 in pokemon.values()
? True
-- OK! --

>>> 151 in pokemon.keys()
? False
-- OK! --

>>> 'mew' in pokemon.keys()
? True
-- OK! --
```

### Q2: Divide

Implement `divide`, which takes two lists of positive integers `quotients` and `divisors`. It returns a dictionary whose keys are the elements of `quotients`. For each key `q`, its corresponding value is a list of all the elements of `divisors` that can be evenly divided by `q`.

```py linenums="1"
def divide(quotients, divisors):
    """Return a dictonary in which each quotient q is a key for the list of
    divisors that it divides evenly.

    >>> divide([3, 4, 5], [8, 9, 10, 11, 12])
    {3: [9, 12], 4: [8, 12], 5: [10]}
    >>> divide(range(1, 5), range(20, 25))
    {1: [20, 21, 22, 23, 24], 2: [20, 22, 24], 3: [21, 24], 4: [20, 24]}
    """
    return {x: [y for y in divisors if y%x==0] for x in quotients}
```

### Q3: Buying Fruit

Implement the `buy` function that takes three parameters:

* `fruits_to_buy`: A list of strings representing the fruits you need to buy. At least one of each fruit must be bought.
* `prices`: A dictionary where the keys are fruit names (strings) and the values are positive integers representing the cost of each fruit.
* `total_amount`: An integer representing the total money available for purchasing the fruits. Take a look at the docstring for more details on the input structure.

The function should print all possible ways to buy the required fruits so that the combined cost equals `total_amount`. You can only select fruits mentioned in `fruits_to_buy` list.

```py linenums="1"
def buy(fruits_to_buy, prices, total_amount):
    """Print ways to buy some of each fruit so that the sum of prices is amount.

    >>> prices = {'oranges': 4, 'apples': 3, 'bananas': 2, 'kiwis': 9}
    >>> buy(['apples', 'oranges', 'bananas'], prices, 12)  # We can only buy apple, orange, and banana, but not kiwi
    [2 apples][1 orange][1 banana]
    >>> buy(['apples', 'oranges', 'bananas'], prices, 16)
    [2 apples][1 orange][3 bananas]
    [2 apples][2 oranges][1 banana]
    >>> buy(['apples', 'kiwis'], prices, 36)
    [3 apples][3 kiwis]
    [6 apples][2 kiwis]
    [9 apples][1 kiwi]
    """
    def add(fruits, amount, cart):
        if fruits == [] and amount == 0:
            print(cart)
        elif fruits and amount > 0:
            fruit = fruits[0]
            price = prices[fruit]
            for k in range(1,amount//price+1):
                # Hint: The display function will help you add fruit to the cart.
                add(fruits[1:], amount-price*k, cart+display(fruit,k))
    add(fruits_to_buy, total_amount, '')

def display(fruit, count):
    """Display a count of a fruit in square brackets.

    >>> display('apples', 3)
    '[3 apples]'
    >>> display('apples', 1)
    '[1 apple]'
    >>> print(display('apples', 3) + display('kiwis', 3))
    [3 apples][3 kiwis]
    """
    assert count >= 1 and fruit[-1] == 's'
    if count == 1:
        fruit = fruit[:-1]  # get rid of the plural s
    return '[' + str(count) + ' ' + fruit + ']'
```

### Q4: Distance

We will now implement the function `distance`, which computes the distance between two city objects. Recall that the distance between two coordinate pairs `(x1, y1)` and `(x2, y2)` can be found by calculating the `sqrt` of `(x1 - x2)**2 + (y1 - y2)**2`. We have already imported `sqrt` for your convenience. Use the latitude and longitude of a city as its coordinates; you'll need to use the selectors to access this info!

```py linenums="1"
from math import sqrt
def distance(city_a, city_b):
    """
    >>> city_a = make_city('city_a', 0, 1)
    >>> city_b = make_city('city_b', 0, 2)
    >>> distance(city_a, city_b)
    1.0
    >>> city_c = make_city('city_c', 6.5, 12)
    >>> city_d = make_city('city_d', 2.5, 15)
    >>> distance(city_c, city_d)
    5.0
    """
    xa=get_lat(city_a)
    ya=get_lon(city_a)
    xb=get_lat(city_b)
    yb=get_lon(city_b)
    return sqrt((xa-xb)**2+(ya-yb)**2)
```

### Q5: Closer City

Next, implement `closer_city`, a function that takes a latitude, longitude, and two cities, and returns the name of the city that is closer to the provided latitude and longitude.

You may only use the selectors `get_name` `get_lat` `get_lon`, constructors `make_city`, and the `distance` function you just defined for this question.

```py linenums="1"
def closer_city(lat, lon, city_a, city_b):
    """
    Returns the name of either city_a or city_b, whichever is closest to
    coordinate (lat, lon). If the two cities are the same distance away
    from the coordinate, consider city_b to be the closer city.

    >>> berkeley = make_city('Berkeley', 37.87, 112.26)
    >>> stanford = make_city('Stanford', 34.05, 118.25)
    >>> closer_city(38.33, 121.44, berkeley, stanford)
    'Stanford'
    >>> bucharest = make_city('Bucharest', 44.43, 26.10)
    >>> vienna = make_city('Vienna', 48.20, 16.37)
    >>> closer_city(41.29, 174.78, bucharest, vienna)
    'Bucharest'
    """
    city_c=make_city('',lat,lon)
    da=distance(city_a,city_c)
    db=distance(city_b,city_c)
    return get_name(city_a) if da<db else get_name(city_b)
```

***

## Lab5

### Q1: WWPD: List-Mutation

```py linenums="1"
>>> s = [6, 7, 8]
>>> print(s.append(6))
None
-- OK! --

>>> s
[6, 7, 8, 6]
-- OK! --

>>> s.insert(0, 9)
>>> s
[9, 6, 7, 8, 6]
-- OK! --

>>> x = s.pop(1)
>>> s
[9, 7, 8, 6]
-- OK! --

>>> s.remove(x)
>>> s
[9, 7, 8]
-- OK! --

>>> a, b = s, s[:]
>>> a is s
True
-- OK! --

>>> b == s
True
-- OK! --

>>> b is s
False
-- OK! --

>>> a.pop()
? 8    
-- OK! --

>>> a + b
? [9,7,9,7,8]
-- OK! --

>>> s = [3]
>>> s.extend([4, 5])
>>> s
? [3,4,5]
-- OK! --

>>> a
? [9,7]
-- OK! --

>>> s.extend([s.append(9), s.append(10)])
>>> s
? [3,4,5,9,10,None,None]
-- OK! --
```

### Q2: Insert Items

Write a function that takes in a list `s`, a value `before`, and a value `after`. It modified `s` in place by inserting after just `after` each value equal to `before` in `s`. It returns `s`.

Important: No new lists should be created.

```py linenums="1"
def insert_items(s, before, after):
    """Insert after into s after each occurrence of before and then return s.

    >>> test_s = [1, 5, 8, 5, 2, 3]
    >>> new_s = insert_items(test_s, 5, 7)
    >>> new_s
    [1, 5, 7, 8, 5, 7, 2, 3]
    >>> test_s
    [1, 5, 7, 8, 5, 7, 2, 3]
    >>> new_s is test_s
    True
    >>> double_s = [1, 2, 1, 2, 3, 3]
    >>> double_s = insert_items(double_s, 3, 4)
    >>> double_s
    [1, 2, 1, 2, 3, 4, 3, 4]
    >>> large_s = [1, 4, 8]
    >>> large_s2 = insert_items(large_s, 4, 4)
    >>> large_s2
    [1, 4, 4, 8]
    >>> large_s3 = insert_items(large_s2, 4, 6)
    >>> large_s3
    [1, 4, 6, 4, 6, 8]
    >>> large_s3 is large_s
    True
    """
    index_list=[i for i in range(len(s)) if s[i]==before]
    index_list.reverse()
    for i in index_list:
        s.insert(i+1,after)
    return s
```

### Q3: Group By

Write a function that takes a list `s` and a function `fn`, and returns a dictionary that groups the elements of `s` based on the result of applying `fn`.

* The dictionary should have one key for each unique result of applying `fn` to elements of `s`.
* The value for each key should be a list of all elements in `s` that, when passed to `fn`, produce that key value.

In other words, for each element `e` in `s`, determine `fn(e)` and add `e` to the list corresponding to `fn(e)` in the dictionary.

```py linenums="1"
def group_by(s, fn):
    """Return a dictionary of lists that together contain the elements of s.
    The key for each list is the value that fn returns when called on any of the
    values of that list.

    >>> group_by([12, 23, 14, 45], lambda p: p // 10)
    {1: [12, 14], 2: [23], 4: [45]}
    >>> group_by(range(-3, 4), lambda x: x * x)
    {9: [-3, 3], 4: [-2, 2], 1: [-1, 1], 0: [0]}
    """
    grouped = {}
    for x in s:
        key = fn(x)
        if key in grouped:
            grouped[key]+=[x]
        else:
            grouped[key] = [x]
    return grouped
```

### Q4: WWPD: Iterators

```py linenums="1"
>>> s = [1, 2, 3, 4]
>>> t = iter(s)
>>> next(s)
? Error
-- OK! --  

>>> next(t)
? 1
-- OK! --  

>>> next(t)
? 2
-- OK! --        

>>> next(iter(s))
? 1
-- OK! --

>>> next(iter(s))
? 1
-- OK! --

>>> next(t)
? 3
-- OK! --

>>> next(t)
? 4
-- OK! --
```

```py linenums="1"
>>> r = range(6)
>>> r_iter = iter(r)
>>> next(r_iter)
? 0
-- OK! --

>>> [x + 1 for x in r]
? [1,2,3,4,5,6]
-- OK! --

>>> [x + 1 for x in r_iter]
? [2,3,4,5,6]
-- OK! --       

>>> next(r_iter)
? StopIteration
-- OK! --
```

```py linenums="1"
>>> map_iter = map(lambda x : x + 10, range(5))
>>> next(map_iter)
? 10
-- OK! --

>>> next(map_iter)
? 11
-- OK! --

>>> list(map_iter)
? [12,13,14]
-- OK! --

>>> for e in filter(lambda x : x % 4 == 0, range(1000, 1008)):
...     print(e)
(line 1)? 1000
(line 2)? 1004
-- OK! --

>>> [x + y for x, y in zip([1, 2, 3], [4, 5, 6])]
? [5,7,9]
-- OK! -
```

***

## Lab6

### Q1: Bank Account

Extend the `BankAccount` class to include a `transactions` attribute. This attribute should be a list that keeps track of each transaction made on the account. Whenever the `deposit` or `withdraw` method is called, a new `Transaction` instance should be created and added to the list, even if the action is not successful.

The `Transaction` class should have the following attributes:

* `before`: The account balance before the transaction.
* `after`: The account balance after the transaction.
* `id`: The transaction ID, which is the number of previous transactions (deposits or withdrawals) made on that account. The transaction IDs for a specific `BankAccount` instance must be unique, but this `id` does not need to be unique across all accounts. In other words, you only need to ensure that no two `Transaction` objects made by the same BankAccount have the same `id`.
In addition, the `Transaction` class should have the following methods:

* `changed()`: Returns `True` if the balance changed (i.e., `before` is different from `after`), otherwise returns `False`.
* `report()`: Returns a string describing the transaction. The string should start with the transaction ID and describe the change in balance. Take a look at the doctests for the expected output.

```py linenums="1"
class Transaction:
    def __init__(self, id, before, after):
        self.id = id
        self.before = before
        self.after = after

    def changed(self):
        """Return whether the transaction resulted in a changed balance."""
        return self.before!=self.after

    def report(self):
        """Return a string describing the transaction.

        >>> Transaction(3, 20, 10).report()
        '3: decreased 20->10'
        >>> Transaction(4, 20, 50).report()
        '4: increased 20->50'
        >>> Transaction(5, 50, 50).report()
        '5: no change'
        """
        msg = 'no change'
        if self.changed():
            if self.after>self.before:
                msg='increased '+str(self.before)+'->'+str(self.after)
            else:
                msg='decreased '+str(self.before)+'->'+str(self.after)
        return str(self.id) + ': ' + msg

class BankAccount:
    """A bank account that tracks its transaction history.

    >>> a = BankAccount('Eric')
    >>> a.deposit(100)    # Transaction 0 for a
    100
    >>> b = BankAccount('Erica')
    >>> a.withdraw(30)    # Transaction 1 for a
    70
    >>> a.deposit(10)     # Transaction 2 for a
    80
    >>> b.deposit(50)     # Transaction 0 for b
    50
    >>> b.withdraw(10)    # Transaction 1 for b
    40
    >>> a.withdraw(100)   # Transaction 3 for a
    'Insufficient funds'
    >>> len(a.transactions)
    4
    >>> len([t for t in a.transactions if t.changed()])
    3
    >>> for t in a.transactions:
    ...     print(t.report())
    0: increased 0->100
    1: decreased 100->70
    2: increased 70->80
    3: no change
    >>> b.withdraw(100)   # Transaction 2 for b
    'Insufficient funds'
    >>> b.withdraw(30)    # Transaction 3 for b
    10
    >>> for t in b.transactions:
    ...     print(t.report())
    0: increased 0->50
    1: decreased 50->40
    2: no change
    3: decreased 40->10
    """

    # *** YOU NEED TO MAKE CHANGES IN SEVERAL PLACES IN THIS CLASS ***

    def __init__(self, account_holder):
        self.balance = 0
        self.holder = account_holder
        self.transactions=[]

    def deposit(self, amount):
        """Increase the account balance by amount, add the deposit
        to the transaction history, and return the new balance.
        """
        before=self.balance
        self.balance = self.balance + amount
        after=self.balance
        self.transactions+=[Transaction(len(self.transactions),before,after)]
        return self.balance

    def withdraw(self, amount):
        """Decrease the account balance by amount, add the withdraw
        to the transaction history, and return the new balance.
        """
        before=self.balance
        if amount<=self.balance:
            self.balance=self.balance-amount
        after=self.balance
        self.transactions+=[Transaction(len(self.transactions),before,after)]
        if amount>before:
            return 'Insufficient funds'
        else:
            return self.balance
```

### Q2: Email

An email system has three classes: `Email`, `Server`, and `Client`. A `Client` can `compose` an email, which it will `send` to the `Server`. The `Server` then delivers it to the `inbox` of another `Client`. To achieve this, a `Server` has a dictionary called `clients` that maps the name of the `Client` to the `Client` instance.

Assume that a client never changes the server that it uses, and it only composes emails using that server.

Fill in the definitions below to finish the implementation! The `Email` class has been completed for you.

```py linenums="1"
class Email:
    """An email has the following instance attributes:

        msg (str): the contents of the message
        sender (Client): the client that sent the email
        recipient_name (str): the name of the recipient (another client)
    """
    def __init__(self, msg, sender, recipient_name):
        self.msg = msg
        self.sender = sender
        self.recipient_name = recipient_name

class Server:
    """Each Server has one instance attribute called clients that is a
    dictionary from client names to client objects.
    """
    def __init__(self):
        self.clients = {}

    def send(self, email):
        """Append the email to the inbox of the client it is addressed to.
            email is an instance of the Email class.
        """
        self.clients[email.recipient_name].inbox.append(email)

    def register_client(self, client):
        """Add a client to the clients mapping (which is a 
        dictionary from client names to client instances).
            client is an instance of the Client class.
        """
        self.clients[client.name] = client

class Client:
    """A client has a server, a name (str), and an inbox (list).

    >>> s = Server()
    >>> a = Client(s, 'Alice')
    >>> b = Client(s, 'Bob')
    >>> a.compose('Hello, World!', 'Bob')
    >>> b.inbox[0].msg
    'Hello, World!'
    >>> a.compose('CS 61A Rocks!', 'Bob')
    >>> len(b.inbox)
    2
    >>> b.inbox[1].msg
    'CS 61A Rocks!'
    >>> b.inbox[1].sender.name
    'Alice'
    """
    def __init__(self, server, name):
        self.inbox = []
        self.server = server
        self.name = name
        server.register_client(self)

    def compose(self, message, recipient_name):
        """Send an email with the given message to the recipient."""
        email = Email(message, self, recipient_name)
        self.server.send(email)
```

### Q3: Mint

A mint is a place where coins are made. In this question, you'll implement a `Mint` class that can output a `Coin` with the correct year and worth.

* Each `Mint` instance has a `year` stamp. The `update` method sets the `year` stamp of the instance to the `present_year` class attribute of the `Mint` class.
* The `create` method takes a subclass of `Coin` (not an instance!), then creates and returns an instance of that subclass stamped with the `Mint`'s year (which may be different from `Mint.present_year` if it has not been updated.)
* A `Coin`'s `worth` method returns the `cents` value of the coin plus one extra cent for each year of age beyond 50. A coin's age can be determined by subtracting the coin's year from the `present_year` class attribute of the Mint class.

```py linenums="1"
class Mint:
    """A mint creates coins by stamping on years.

    The update method sets the mint's stamp to Mint.present_year.

    >>> mint = Mint()
    >>> mint.year
    2024
    >>> dime = mint.create(Dime)
    >>> dime.year
    2024
    >>> Mint.present_year = 2104  # Time passes
    >>> nickel = mint.create(Nickel)
    >>> nickel.year     # The mint has not updated its stamp yet
    2024
    >>> nickel.worth()  # 5 cents + (80 - 50 years)
    35
    >>> mint.update()   # The mint's year is updated to 2104
    >>> Mint.present_year = 2179     # More time passes
    >>> mint.create(Dime).worth()    # 10 cents + (75 - 50 years)
    35
    >>> Mint().create(Dime).worth()  # A new mint has the current year
    10
    >>> dime.worth()     # 10 cents + (155 - 50 years)
    115
    >>> Dime.cents = 20  # Upgrade all dimes!
    >>> dime.worth()     # 20 cents + (155 - 50 years)
    125
    """
    present_year = 2024

    def __init__(self):
        self.update()

    def create(self, coin):
        return coin(self.year)

    def update(self):
        self.year=self.present_year

class Coin:
    cents = None # will be provided by subclasses, but not by Coin itself

    def __init__(self, year):
        self.year = year

    def worth(self):
        age=Mint.present_year-self.year
        value=self.cents
        if age>50:
            value+=(age-50)
        return value

class Nickel(Coin):
    cents = 5

class Dime(Coin):
    cents = 10
```

***

## Lab7

### Q1: WWPD: Inheritance ABCs

```py linenums="1"
>>> class A:
...   x, y = 0, 0
...   def __init__(self):
...         return
>>> class B(A):
...   def __init__(self):
...         return
>>> class C(A):
...   def __init__(self):
...         return
>>> print(A.x, B.x, C.x)
? 0 0 0
-- OK! --

>>> B.x = 2
>>> print(A.x, B.x, C.x)
? 0 2 0
-- OK! --

>>> A.x += 1
>>> print(A.x, B.x, C.x)
? 1 2 1
-- OK! --

>>> obj = C()
>>> obj.y = 1
>>> C.y == obj.y
? False
-- OK! --

>>> A.y = obj.y
>>> print(A.y, B.y, C.y, obj.y)
? 1 1 1 1
-- OK! --
```

### Q2: Retirement

Add a `time_to_retire` method to the `Account` class. This method takes in an `amount` and returns the number of years until the current `balance` grows to at least `amount`, assuming that the bank adds the interest (calculated as the current balance multiplied by the `interest` rate) to the `balance` at the end of each year. Make sure you're not modifying the account's balance!

```py  linenums="1"
class Account:
    """An account has a balance and a holder.

    >>> a = Account('John')
    >>> a.deposit(10)
    10
    >>> a.balance
    10
    >>> a.interest
    0.02
    >>> a.time_to_retire(10.25)  # 10 -> 10.2 -> 10.404
    2
    >>> a.balance                # Calling time_to_retire method should not change the balance
    10
    >>> a.time_to_retire(11)     # 10 -> 10.2 -> ... -> 11.040808032
    5
    >>> a.time_to_retire(100)
    117
    """
    max_withdrawal = 10
    interest = 0.02

    def __init__(self, account_holder):
        self.balance = 0
        self.holder = account_holder

    def deposit(self, amount):
        self.balance = self.balance + amount
        return self.balance

    def withdraw(self, amount):
        if amount > self.balance:
            return "Insufficient funds"
        if amount > self.max_withdrawal:
            return "Can't withdraw that amount"
        self.balance = self.balance - amount
        return self.balance

    def time_to_retire(self, amount):
        """Return the number of years until balance would grow to amount."""
        assert self.balance > 0 and amount > 0 and self.interest > 0
        i=0
        principal=self.balance
        while principal<amount:
            principal*=(1+self.interest)
            i+=1
        return i
```

### Q3: FreeChecking

Implement the `FreeChecking` class, which is like the `Account` class except that it charges a withdraw fee `withdraw_fee` after withdrawing `free_withdrawals` number of times. If a withdrawal is unsuccessful, no withdrawal fee will be charged, but it still counts towards the number of free withdrawals remaining.

```py linenums="1"
class FreeChecking(Account):
    """A bank account that charges for withdrawals, but the first two are free!

    >>> ch = FreeChecking('Jack')
    >>> ch.balance = 20
    >>> ch.withdraw(100)  # First one's free. Still counts as a free withdrawal even though it was unsuccessful
    'Insufficient funds'
    >>> ch.withdraw(3)    # Second withdrawal is also free
    17
    >>> ch.balance
    17
    >>> ch.withdraw(3)    # Now there is a fee because free_withdrawals is only 2
    13
    >>> ch.withdraw(3)
    9
    >>> ch2 = FreeChecking('John')
    >>> ch2.balance = 10
    >>> ch2.withdraw(3) # No fee
    7
    >>> ch.withdraw(3)  # ch still charges a fee
    5
    >>> ch.withdraw(5)  # Not enough to cover fee + withdraw
    'Insufficient funds'
    """
    withdraw_fee = 1
    free_withdrawals = 2

    def withdraw(self, amount):
        if self.free_withdrawals>0:
            self.free_withdrawals-=1
            if amount > self.balance:
                return "Insufficient funds"
            if amount > self.max_withdrawal:
                return "Can't withdraw that amount"
            self.balance = self.balance - amount
        else:
            if amount+self.withdraw_fee > self.balance:
                return "Insufficient funds"
            if amount > self.max_withdrawal:
                return "Can't withdraw that amount"
            self.balance = self.balance - amount-self.withdraw_fee
        return self.balance
```

### Q4: WWPD: Linked Lists

```py linenums="1"
>>> from lab08 import *
>>> link = Link(1000)
>>> link.first
? 1000
-- OK! --
>>> from lab08 import *
>>> link = Link(1000)
>>> link.first
? 1000
-- OK! --
>>> link = Link(1000)
>>> link.first
? 1000
-- OK! --

>>> link.rest is Link.empty
? True
-- OK! --

>>> link = Link(1000, 2000)
? Error
-- OK! --

>>> link = Link(1000, Link())
? Error
-- OK! --


>>> from lab08 import *
>>> link = Link(1, Link(2, Link(3)))
>>> link.first
? 1
-- OK! --

>>> link.rest.first
? 2
-- OK! --

>>> link.rest.rest.rest is Link.empty
? True
-- OK! --

>>> link.first = 9001
>>> link.first
? 9001
-- OK! --

>>> link.rest = link.rest.rest
>>> link.rest.first
? 3
-- OK! --

>>> link = Link(1)
>>> link.rest = link
>>> link.rest.rest is Link.empty
? False
-- OK! --

>>> link.rest.rest.rest.rest.first
? 1
-- OK! --

>>> link = Link(2, Link(3, Link(4)))
>>> link2 = Link(1, link)
>>> link2.first
? 1
-- OK! --

>>> link2.rest.first
? 2
-- OK! --


>>> from lab08 import *
>>> link = Link(5, Link(6, Link(7)))
>>> link                  # Look at the __repr__ method of Link
? Link(5, Link(6, Link(7)))
-- OK! --

>>> print(link)          # Look at the __str__ method of Link
? <5 6 7>
-- OK! --
```

### Q5: Without One

Implement `without`, which takes a linked list `s` and a non-negative integer `i`. It returns a new linked list with all of the elements of `s` except the one at index `i`. (Assume `s.first` is the element at index 0.) The original linked list `s` should not be changed.

```py linenums="1"
def without(s, i):
    """Return a new linked list like s but without the element at index i.

    >>> s = Link(3, Link(5, Link(7, Link(9))))
    >>> without(s, 0)
    Link(5, Link(7, Link(9)))
    >>> without(s, 2)
    Link(3, Link(5, Link(9)))
    >>> without(s, 4)           # There is no index 4, so all of s is retained.
    Link(3, Link(5, Link(7, Link(9))))
    >>> without(s, 4) is not s  # Make sure a copy is created
    True
    """
    if not s:
        return Link.empty
    if i==0:
        return s.rest
    else:
        return Link(s.first,without(s.rest,i-1))
```

### Q6: Duplicate Link

Write a function `duplicate_link` that takes in a linked list `s` and a value `val`. It mutates `s` so that each element equal to `val` is followed by an additional `val` (a duplicate copy). It returns `None`. Be careful not to get into an infinite loop where you keep duplicating the new copies!

```py linenums="1"
def duplicate_link(s, val):
    """Mutates s so that each element equal to val is followed by another val.

    >>> x = Link(5, Link(4, Link(5)))
    >>> duplicate_link(x, 5)
    >>> x
    Link(5, Link(5, Link(4, Link(5, Link(5)))))
    >>> y = Link(2, Link(4, Link(6, Link(8))))
    >>> duplicate_link(y, 10)
    >>> y
    Link(2, Link(4, Link(6, Link(8))))
    >>> z = Link(1, Link(2, (Link(2, Link(3)))))
    >>> duplicate_link(z, 2) # ensures that back to back links with val are both duplicated
    >>> z
    Link(1, Link(2, Link(2, Link(2, Link(2, Link(3))))))
    """
    if not s:
        return s
    if s.first==val:
        s.rest=Link(val,s.rest)
        duplicate_link(s.rest.rest,val)
    else:
        duplicate_link(s.rest,val)
```

***

## Lab8

### Q1: WWPD: Trees

```py linenums="1"
>>> t = Tree(1, Tree(2)) # Enter Function if you believe the answer is <function ...>, Error if it errors, and Nothing if nothing is displayed.
? Error
-- OK! --

>>> t = Tree(1, [Tree(2)])
>>> t.label
? 1
-- OK! --

>>> t.branches[0]
? Tree(2)
-- OK! --

>>> t.branches[0].label
? 2
-- OK! --

>>> t.label = t.branches[0].label
>>> t
? Tree(2, [Tree(2)])
-- OK! --

>>> t.branches.append(Tree(4, [Tree(8)]))
>>> len(t.branches)
? 2
-- OK! --

>>> t.branches[0]
? Tree(2)
-- OK! --

>>> t.branches[1]
? Tree(4, [Tree(8)])
-- OK! --
```

### Q2: Cumulative Mul

Write a function `cumulative_mul` that mutates the Tree `t` so that each node's label is replaced by the product of its label and the labels of all its descendents.

```py linenums="1"
def cumulative_mul(t):
    """Mutates t so that each node's label becomes the product of its own
    label and all labels in the corresponding subtree rooted at t.

    >>> t = Tree(1, [Tree(3, [Tree(5)]), Tree(7)])
    >>> cumulative_mul(t)
    >>> t
    Tree(105, [Tree(15, [Tree(5)]), Tree(7)])
    >>> otherTree = Tree(2, [Tree(1, [Tree(3), Tree(4), Tree(5)]), Tree(6, [Tree(7)])])
    >>> cumulative_mul(otherTree)
    >>> otherTree
    Tree(5040, [Tree(60, [Tree(3), Tree(4), Tree(5)]), Tree(42, [Tree(7)])])
    """
    if t.branches:
        for i in range(len(t.branches)):
            cumulative_mul(t.branches[i])
            t.label*=t.branches[i].label
```

### Q3: Prune Small

Removing some nodes from a tree is called pruning the tree.

Complete the function `prune_small` that takes in a Tree `t` and a number `n`. For each node with more than `n` branches, keep only the `n` branches with the smallest labels and remove (prune) the rest.

```py linenums="1"
def prune_small(t, n):
    """Prune the tree mutatively, keeping only the n branches
    of each node with the smallest labels.

    >>> t1 = Tree(6)
    >>> prune_small(t1, 2)
    >>> t1
    Tree(6)
    >>> t2 = Tree(6, [Tree(3), Tree(4)])
    >>> prune_small(t2, 1)
    >>> t2
    Tree(6, [Tree(3)])
    >>> t3 = Tree(6, [Tree(1), Tree(3, [Tree(1), Tree(2), Tree(3)]), Tree(5, [Tree(3), Tree(4)])])
    >>> prune_small(t3, 2)
    >>> t3
    Tree(6, [Tree(1), Tree(3, [Tree(1), Tree(2)])])
    """
    while len(t.branches)>n:
        largest = max(t.branches, key=lambda x:x.label)
        t.branches.remove(largest)
    for b in t.branches:
        prune_small(b,n)
```

### Q4: Delete

Implement `delete`, which takes a Tree `t` and removes all non-root nodes labeled `x`. The parent of each remaining node is its nearest ancestor that was not removed. The root node is never removed, even if its label is `x`.

```py linenums="1"
def delete(t, x):
    """Remove all nodes labeled x below the root within Tree t. When a non-leaf
    node is deleted, the deleted node's children become children of its parent.

    The root node will never be removed.

    >>> t = Tree(3, [Tree(2, [Tree(2), Tree(2)]), Tree(2), Tree(2, [Tree(2, [Tree(2), Tree(2)])])])
    >>> delete(t, 2)
    >>> t
    Tree(3)
    >>> t = Tree(1, [Tree(2, [Tree(4, [Tree(2)]), Tree(5)]), Tree(3, [Tree(6), Tree(2)]), Tree(4)])
    >>> delete(t, 2)
    >>> t
    Tree(1, [Tree(4), Tree(5), Tree(3, [Tree(6)]), Tree(4)])
    >>> t = Tree(1, [Tree(2, [Tree(4), Tree(5)]), Tree(3, [Tree(6), Tree(2)]), Tree(2, [Tree(6),  Tree(2), Tree(7), Tree(8)]), Tree(4)])
    >>> delete(t, 2)
    >>> t
    Tree(1, [Tree(4), Tree(5), Tree(3, [Tree(6)]), Tree(6), Tree(7), Tree(8), Tree(4)])
    """
    new_branches = []
    for b in t.branches:
        delete(b,x)
        if b.label == x:
            new_branches+=b.branches
        else:
            new_branches+=[b]
    t.branches = new_branches
```

### Q5: Maximum Path Sum

Write a function that takes in a tree and returns the maximum sum of the values along any path from the root to a leaf of the tree.

```py linenums="1"
def max_path_sum(t):
    """Return the maximum path sum of the tree.

    >>> t = Tree(1, [Tree(5, [Tree(1), Tree(3)]), Tree(10)])
    >>> max_path_sum(t)
    11
    """
    if not t:
        return 0
    elif not t.branches:
        return t.label
    else:
        return t.label+max([max_path_sum(b) for b in t.branches])
```

***

## Lab9

### Q1: Over or Under

Define a procedure `over-or-under` which takes in a number `num1` and a number `num2` and returns the following:

* -1 if `num1` is less than `num2`
* 0 if `num1` is equal to `num2`
* 1 if `num1` is greater than `num2`

```scheme linenums="1"
(define (over-or-under num1 num2) 
        (cond ((< num1 num2) -1)
              ((= num1 num2) 0)
              (else 1)))
```

### Q2: Make Adder

Write a procedure `make-adder` that takes a number `num` as input and returns a new procedure. This returned procedure should accept another number `inc` and return the result of `num + inc`.

```scheme linenums="1"
(define (make-adder num) 
        (lambda (inc) (+ num inc)))
```

### Q3: Compose

Write the procedure `composed`, which takes in procedures `f` and `g` and returns a new procedure. This new procedure takes in a number `x` and returns the result of calling `f` on `g` of `x`.

```scheme linenums="1"
(define (composed f g) 
        (lambda (x) (f (g x))))
```

### Q4: Repeat

Write the procedure `repeat`, which takes in a procedure `f` and a number `n`, and outputs a new procedure. This new procedure takes in a number `x` and returns the result of calling `f` on `x` a total of `n` times.

```scheme linenums="1"
(define (repeat f n) 
        (if (= n 0)
            (lambda (x) x)
            (composed f (repeat f (- n 1)))))
```

### Q5: Greatest Common Divisor

The Greatest Common Divisor (GCD) is the largest integer that evenly divides two positive integers.

Write the procedure `gcd`, which computes the GCD of numbers `a` and `b` using Euclid's algorithm, which recursively uses the fact that the GCD of two values is either of the following:

* the smaller value if it evenly divides the larger value, or
* the greatest common divisor of the smaller value and the remainder of the larger value divided by the smaller value

```scheme linenums="1"
(define (gcd a b) 
        (if (= (min a b) 0)
            (max a b)
            (gcd (min a b) (modulo (max a b) (min a b)))))
```

***

## Lab10

### Q1: Using Pair

```py linenums="1"
Q: Write out the Python expression that returns a `Pair` representing the given expression: (+ (- 2 4) 6 8)
Choose the number of the correct choice:
0) None of these
1) Pair(+, Pair(Pair(-, Pair(2, Pair(4, nil))), Pair(6, Pair(8, nil))))
2) Pair('+', Pair('-', Pair(2, Pair(4, Pair(6, Pair(8, nil))))))
3) Pair('+', Pair(Pair('-', Pair(2, Pair(4))), Pair(6, Pair(8))))
4) Pair('+', Pair(Pair('-', Pair(2, Pair(4, nil))), Pair(6, Pair(8, nil))))
? 4
-- OK! --

Q: What is the operator of the previous part's call expression?
Choose the number of the correct choice:
0) None of these
1) +
2) 6
3) 2
4) (
5) -
? 1
-- OK! --

Q: If the `Pair` you constructed in the previous part was bound to the name `p`,
how would you retrieve the operator?
Choose the number of the correct choice:
0) p.first.rest
1) p.rest
2) p.first
3) p
4) p.rest.first
? 2
-- OK! --

Q: If the `Pair` you constructed was bound to the name `p`,
how would you retrieve a list containing all of the operands?
Choose the number of the correct choice:
0) p.first.rest
1) p.rest.first
2) p.rest
3) p.first
4) p
? 2
-- OK! --

Q: How would you retrieve only the first operand?
Choose the number of the correct choice:
0) p.first.rest
1) p
2) p.rest
3) p.rest.first
4) p.first
? 3
-- OK! --

Q: What is the first operand of the call expression (+ (- 2 4) 6 8) prior to evaluation?
Choose the number of the correct choice:
0) 4
1) 2
2) -2
3) Pair('-', Pair(2, Pair(4, nil)))
4) Pair(2, Pair(4, nil))
5) '-'
6) '+'
? 3
-- OK! --
```

```py linenums="1"
def calc_eval(exp):
    """
    >>> calc_eval(Pair("define", Pair("a", Pair(1, nil))))
    'a'
    >>> calc_eval("a")
    1
    >>> calc_eval(Pair("+", Pair(1, Pair(2, nil))))
    3
    """
    if isinstance(exp, Pair):
        operator = exp.first # UPDATE THIS FOR Q2, e.g (+ 1 2), + is the operator
        operands = exp.rest # UPDATE THIS FOR Q2, e.g (+ 1 2), 1 and 2 are operands
        if operator == 'and': # and expressions
            return eval_and(operands)
        elif operator == 'define': # define expressions
            return eval_define(operands)
        else: # Call expressions
            return calc_apply(calc_eval(operator), operands.map(calc_eval)) # UPDATE THIS FOR Q2, what is type(operator)?
    elif exp in OPERATORS:   # Looking up procedures
        return OPERATORS[exp]
    elif isinstance(exp, int) or isinstance(exp, bool):   # Numbers and booleans
        return exp
    elif exp in bindings.keys(): # CHANGE THIS CONDITION FOR Q4 where are variables stored?
        return bindings[exp] # UPDATE THIS FOR Q4, how do you access a variable?

def calc_apply(op, args):
    return op(args)
```

### Q2: New Procedure

Add the `//` operation to Calculator, a floor-division procedure such that `(// dividend divisor)` returns the result of dividing `dividend` by `divisor`, ignoring the remainder (`dividend // divisor` in Python). Handle multiple inputs as illustrated in the following example: `(// dividend divisor1 divisor2 divisor3)` evaluates to `(((dividend // divisor1) // divisor2) // divisor3)` in Python. Assume every call to `//` has at least two arguments.

```py linenums="1"
def floor_div(args):
    """
    >>> floor_div(Pair(100, Pair(10, nil)))
    10
    >>> floor_div(Pair(5, Pair(3, nil)))
    1
    >>> floor_div(Pair(1, Pair(1, nil)))
    1
    >>> floor_div(Pair(5, Pair(2, nil)))
    2
    >>> floor_div(Pair(23, Pair(2, Pair(5, nil))))
    2
    >>> calc_eval(Pair("//", Pair(4, Pair(2, nil))))
    2
    >>> calc_eval(Pair("//", Pair(100, Pair(2, Pair(2, Pair(2, Pair(2, Pair(2, nil))))))))
    3
    >>> calc_eval(Pair("//", Pair(100, Pair(Pair("+", Pair(2, Pair(3, nil))), nil))))
    20
    """
    first=args.first
    rest=args.rest
    while rest is not nil:
        first=first//rest.first
        rest=rest.rest
    return first
```

### Q3: New Form

Add `and` expressions to our Calculator interpreter as well as introduce the Scheme boolean values `#t` and `#f`, represented as Python `True` and `False`. (The examples below assumes conditional operators (e.g. `<`, `>`, `=`, etc) have already been implemented, but you do not have to worry about them for this question.)

In a call expression, we first evaluate the operator, then evaluate the operands, and finally apply the procedure to its arguments (just like you did for `floor_div` in the previous question). However, we cannot evaluate `and` expressions the same way we evaluate call expressions. Since `and` is a special form that short circuits on the first false argument, we need to add special logic so that we don't always evaluate all the sub-expressions.

```py linenums="1"
def eval_and(expressions):
    """
    >>> calc_eval(Pair("and", Pair(1, nil)))
    1
    >>> calc_eval(Pair("and", Pair(False, Pair("1", nil))))
    False
    >>> calc_eval(Pair("and", Pair(1, Pair(Pair("//", Pair(5, Pair(2, nil))), nil))))
    2
    >>> calc_eval(Pair("and", Pair(Pair('+', Pair(1, Pair(1, nil))), Pair(3, nil))))
    3
    >>> calc_eval(Pair("and", Pair(Pair('-', Pair(1, Pair(0, nil))), Pair(Pair('/', Pair(5, Pair(2, nil))), nil))))
    2.5
    >>> calc_eval(Pair("and", Pair(0, Pair(1, nil))))
    1
    >>> calc_eval(Pair("and", nil))
    True
    """
    if expressions is nil:
        return True
    first=expressions.first
    rest=expressions.rest
    while rest is not nil:
        if calc_eval(first) is scheme_f:
            break
        first=rest.first
        rest=rest.rest
    return calc_eval(first)
```

### Q4: Saving Values

Implement a `define` special form that binds values to symbols. This should work like `define` in Scheme: `(define <symbol> <expression>)` first evaluates the `expression`, then binds the `symbol` to the value of `expression`. The whole `define` expression evaluates to the `symbol`.

```py linenums="1"
def eval_define(expressions):
    """
    >>> eval_define(Pair("a", Pair(1, nil)))
    'a'
    >>> eval_define(Pair("b", Pair(3, nil)))
    'b'
    >>> eval_define(Pair("c", Pair("a", nil)))
    'c'
    >>> calc_eval("c")
    1
    >>> calc_eval(Pair("define", Pair("d", Pair("//", nil))))
    'd'
    >>> calc_eval(Pair("d", Pair(4, Pair(2, nil))))
    2
    """
    first=expressions.first
    rest=expressions.rest.first
    bindings[first]=calc_eval(rest)
    return first
```

***

## Lab11

### Q1: WWSD: Quasiquote

```scheme linenums="1"
scm> '(1 x 3)
? (1 x 3)
-- OK! --        

scm> (define x 2)
? x
-- OK! --    

scm> `(1 x 3)
? (1 x 3)
-- OK! --

scm> `(1 ,x 3)
? (1 2 3)
-- OK! --

scm> `(1 x ,3)
? (1 x 3)
-- OK! --

scm> `(1 (,x) 3)
? (1 (2) 3)
-- OK! --

scm> `(1 ,(+ x 2) 3)
? (1 4 3)
-- OK! --

scm> (define y 3)
? y
-- OK! --

scm> `(x ,(* y x) y)
? (x 6 y)
-- OK! --

scm> `(1 ,(cons x (list y 4)) 5)
? (1 (2 3 4) 5)
-- OK! --
```

### Q2: If Program

In Scheme, the `if` special form allows us to evaluate one of two expressions based on a predicate. Write a program `if-program` that takes in the following parameters:

1. `predicate` : a quoted expression which will evaluate to the condition in our `if`-expression
2. `if-true` : a quoted expression which will evaluate to the value we return if `predicate` evaluates to true (`#t`)
3. `if-false` : a quoted expression which will evaluate to the value we return if `predicate` evaluates to false (`#f`)
The program returns a Scheme list that represents an `if` expression in the form: (`if <predicate> <if-true> <if-false>`). Note that we don't want to evaluate the expression (in our program at least).

```scheme linenums="1"
(define (if-program condition if-true if-false)
        `(if ,condition ,if-true ,if-false))
```

### Q3: Exponential Powers

Implement a procedure `(pow-expr base exp)` that returns an expression that, when evaluated, raises the number `base` to the power of the nonnegative integer `exp`. The body of `pow-expr` should not perform any multiplication (or exponentiation). Instead, it should just construct an expression containing only the symbols `square` and `*` as well as the number `base` and parentheses. The length of this expression should grow logarithmically with respect to `exp`, rather than linearly.

```scheme linenums="1"
(define (pow-expr base exp)
        (cond ((= exp 0) 1)
              ((even? exp) `(square ,(pow-expr base (quotient exp 2))))
              (else `(* ,base ,(pow-expr base (- exp 1))))))
```

### Q4: Repeat

Define `repeat`, a macro that takes a number `n` and an expression `expr`. Calling `repeat` evaluates `expr` in a local frame `n` times, and its value is the final result. You will find the helper function `repeated-call` useful, which takes a number `n` and a zero-argument procedure `f` and calls `f` `n` number of times.

```scheme linenums="1"
(define-macro (repeat n expr)
  `(repeated-call ,n (lambda () ,expr)))

; Call zero-argument procedure f n times and return the final result.
(define (repeated-call n f)
  (if (= n 1)
      (f)
      (begin (f) (repeated-call (- n 1) f))))
```

***

## Lab12

```sql linenums="1"
CREATE TABLE finals AS
  SELECT "RSF" AS hall, "61A" as course UNION
  SELECT "Wheeler"    , "61A"           UNION
  SELECT "Pimentel"   , "61A"           UNION
  SELECT "Li Ka Shing", "61A"           UNION
  SELECT "Stanley"    , "61A"           UNION
  SELECT "RSF"        , "61B"           UNION
  SELECT "Wheeler"    , "61B"           UNION
  SELECT "Morgan"     , "61B"           UNION
  SELECT "Wheeler"    , "61C"           UNION
  SELECT "Pimentel"   , "61C"           UNION
  SELECT "Soda 310"   , "61C"           UNION
  SELECT "Soda 306"   , "10"            UNION
  SELECT "RSF"        , "70";

CREATE TABLE sizes AS
  SELECT "RSF" AS room, 900 as seats    UNION
  SELECT "Wheeler"    , 700             UNION
  SELECT "Pimentel"   , 500             UNION
  SELECT "Li Ka Shing", 300             UNION
  SELECT "Stanley"    , 300             UNION
  SELECT "Morgan"     , 100             UNION
  SELECT "Soda 306"   , 80              UNION
  SELECT "Soda 310"   , 40              UNION
  SELECT "Soda 320"   , 30;
```

### Q1: Room Sharing

Create a `sharing` table with two columns:

* `course` (strings): The name of a course
* `shared` (numbers): The number of rooms the course uses that are also shared with other courses

Include a row for every course that uses at least one room also occupied by another course. Do not include it in the table if a course does not share any rooms.

```sql linenums="1"
CREATE TABLE sharing AS
  SELECT a.course, COUNT(DISTINCT a.hall) AS shared
  FROM finals AS a, finals AS b
  WHERE a.hall = b.hall AND a.course <> b.course GROUP BY a.course;
```

### Q2: Two Rooms

Create a `pairs` table with one column:

* `rooms` (strings): A string describing pairs of rooms that together have at least 1,000 seats

Each string should 1) List the two room names in alphabetical order 2) State the combined number of seats in the two rooms

Only include pairs where the total seats are at least 1,000. Rows should appear in decreasing order of the total seats.

```sql linenums="1"
CREATE TABLE pairs AS
  SELECT a.room || ' and ' || b.room || ' together have ' || (a.seats + b.seats) || ' seats' AS rooms
  FROM sizes AS a, sizes AS b 
  WHERE a.seats + b.seats >= 1000 AND a.room < b.room
  ORDER BY (a.seats + b.seats) DESC;
```

### Q3: (OPTIONAL) Big Courses

Create a `big` table with one column:

* `course` (strings): The name of a course

Include only courses where the total number of seats across all their final exam rooms is at least 1,000. Each course should appear in its own row.

```sql linenums="1"
CREATE TABLE big AS
  SELECT course
  FROM finals, sizes
  WHERE hall = room
  GROUP BY course
  HAVING SUM(seats) >= 1000;
```

### Q4: (OPTIONAL) Seats Remaining

Create a `remaining` table with two columns:

* `course` (strings): The name of a course
* `remaining` (numbers): The total number of seats in all rooms used for that course excluding the room with the largest number of seats

Include one row for each course and for each course, sum the seats from all but the largest room.

```sql linenums="1"
CREATE TABLE remaining AS
  SELECT course, SUM(seats) - MAX(seats) AS remaining
  FROM finals, sizes
  WHERE hall = room
  GROUP BY course;
```