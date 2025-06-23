---
comments: true
---

<span style="font-family: 'Times New Roman';">

# Appendix1 Homework

***

## Homework1

### Q1: A Plus Abs B

Python's `operator` module contains two-argument functions such as `add` and `sub` for Python's built-in arithmetic operators. For example, `add(2, 3)` evalutes to 5, just like the expression 2 + 3.

Fill in the blanks in the following function for adding `a` to the absolute value of `b`, without calling `abs`. You may not modify any of the provided code other than the two blanks.

```py linenums="1"
def a_plus_abs_b(a, b):
    """Return a+abs(b), but without calling abs.

    >>> a_plus_abs_b(2, 3)
    5
    >>> a_plus_abs_b(2, -3)
    5
    >>> a_plus_abs_b(-1, 4)
    3
    >>> a_plus_abs_b(-1, -4)
    3
    """
    if b < 0:
        f = sub
    else:
        f = add
    return f(a, b)
```

### Q2: Two of Three

Write a function that takes three positive numbers as arguments and returns the sum of the squares of the two smallest numbers. Use only a single line for the body of the function.

```py linenums="1"
def two_of_three(i, j, k):
    """Return m*m + n*n, where m and n are the two smallest members of the
    positive numbers i, j, and k.

    >>> two_of_three(1, 2, 3)
    5
    >>> two_of_three(5, 3, 1)
    10
    >>> two_of_three(10, 2, 8)
    68
    >>> two_of_three(5, 5, 5)
    50
    """
    return i**2+j**2+k**2-max(i,j,k)**2
```

### Q3: Largest Factor

Write a function that takes an integer `n` that is greater than 1 and returns the largest integer that is smaller than `n` and evenly divides `n`.

```py linenums="1"
def largest_factor(n):
    """Return the largest factor of n that is smaller than n.

    >>> largest_factor(15) # factors are 1, 3, 5
    5
    >>> largest_factor(80) # factors are 1, 2, 4, 5, 8, 10, 16, 20, 40
    40
    >>> largest_factor(13) # factor is 1 since 13 is prime
    1
    """
    i=n-1
    while i>0:
        if n%i==0:
            return i
        i=i-1
```

### Q4: Hailstone

Douglas Hofstadter's Pulitzer-prize-winning book, Gödel, Escher, Bach, poses the following mathematical puzzle.

1. Pick a positive integer `n` as the start.
2. If `n` is even, divide it by 2.
3. If `n` is odd, multiply it by 3 and add 1.
4. Continue this process until `n` is 1.

The number `n` will travel up and down but eventually end at 1 (at least for all numbers that have ever been tried -- nobody has ever proved that the sequence will terminate). Analogously, a hailstone travels up and down in the atmosphere before eventually landing on earth.

This sequence of values of `n` is often called a Hailstone sequence. Write a function that takes a single argument with formal parameter name `n`, prints out the hailstone sequence starting at `n`, and returns the number of steps in the sequence.

```py linenums="1"
def hailstone(n):
    """Print the hailstone sequence starting at n and return its
    length.

    >>> a = hailstone(10)
    10
    5
    16
    8
    4
    2
    1
    >>> a
    7
    >>> b = hailstone(1)
    1
    >>> b
    1
    """
    num=0
    while n>1:
        print(n)
        num=num+1
        if n%2==0:
            n=n//2
        else:
            n=n*3+1
    print(n)
    num=num+1
    return num
```

***

## Homework2

### Q1: Product

Write a function called `product` that returns the product of the first `n` terms of a sequence. Specifically, `product` takes in an integer `n` and `term`, a single-argument function that determines a sequence. (That is, `term(i)` gives the ith term of the sequence.) `product(n, term)` should return `term(1) * ... * term(n)`.

```py linenums="1"
def product(n, term):
    """Return the product of the first n terms in a sequence.

    n: a positive integer
    term:  a function that takes one argument to produce the term

    >>> product(3, identity)  # 1 * 2 * 3
    6
    >>> product(5, identity)  # 1 * 2 * 3 * 4 * 5
    120
    >>> product(3, square)    # 1^2 * 2^2 * 3^2
    36
    >>> product(5, square)    # 1^2 * 2^2 * 3^2 * 4^2 * 5^2
    14400
    >>> product(3, increment) # (1+1) * (2+1) * (3+1)
    24
    >>> product(3, triple)    # 1*3 * 2*3 * 3*3
    162
    """
    i=1
    product=1
    while i<=n:
        product*=term(i)
        i+=1
    return product
```

### Q2: Accumulate

`accumulate` has the following parameters:

* `fuse`: a two-argument function that specifies how the current term is fused with the previously accumulated terms
* `start`: value at which to start the accumulation
* `n`: a non-negative integer indicating the number of terms to fuse
* `term`: a single-argument function; `term(i)` is the ith term of the sequence

Implement `accumulate`, which fuses the first `n` terms of the sequence defined by `term` with the `start` value using the `fuse` function.

```py linenums="1"
def accumulate(fuse, start, n, term):
    """Return the result of fusing together the first n terms in a sequence 
    and start.  The terms to be fused are term(1), term(2), ..., term(n). 
    The function fuse is a two-argument commutative & associative function.

    >>> accumulate(add, 0, 5, identity)  # 0 + 1 + 2 + 3 + 4 + 5
    15
    >>> accumulate(add, 11, 5, identity) # 11 + 1 + 2 + 3 + 4 + 5
    26
    >>> accumulate(add, 11, 0, identity) # 11 (fuse is never used)
    11
    >>> accumulate(add, 11, 3, square)   # 11 + 1^2 + 2^2 + 3^2
    25
    >>> accumulate(mul, 2, 3, square)    # 2 * 1^2 * 2^2 * 3^2
    72
    >>> # 2 + (1^2 + 1) + (2^2 + 1) + (3^2 + 1)
    >>> accumulate(lambda x, y: x + y + 1, 2, 3, square)
    19
    """
    i=1
    result=start
    while i<=n:
        result=fuse(result,term(i))
        i+=1
    return result
```

Then, implement `summation` (from lecture) and `product` as one-line calls to `accumulate`.

```py linenums="1"
def summation_using_accumulate(n, term):
    """Returns the sum: term(1) + ... + term(n), using accumulate.

    >>> summation_using_accumulate(5, square) # square(1) + square(2) + ... + square(4) + square(5)
    55
    >>> summation_using_accumulate(5, triple) # triple(1) + triple(2) + ... + triple(4) + triple(5)
    45
    >>> # This test checks that the body of the function is just a return statement.
    >>> import inspect, ast
    >>> [type(x).__name__ for x in ast.parse(inspect.getsource(summation_using_accumulate)).body[0].body]
    ['Expr', 'Return']
    """
    return accumulate(add,0,n,term)


def product_using_accumulate(n, term):
    """Returns the product: term(1) * ... * term(n), using accumulate.

    >>> product_using_accumulate(4, square) # square(1) * square(2) * square(3) * square()
    576
    >>> product_using_accumulate(6, triple) # triple(1) * triple(2) * ... * triple(5) * triple(6)
    524880
    >>> # This test checks that the body of the function is just a return statement.
    >>> import inspect, ast
    >>> [type(x).__name__ for x in ast.parse(inspect.getsource(product_using_accumulate)).body[0].body]
    ['Expr', 'Return']
    """
    return accumulate(mul,1,n,term)
```

### Q3: Make Repeater

Implement the function `make_repeater` which takes a one-argument function `f` and a positive integer `n`. It returns a one-argument function, where `make_repeater(f, n)(x)` returns the value of `f(f(...f(x)...))` in which `f` is applied `n` times to `x`. For example, `make_repeater(square, 3)(5)` squares 5 three times and returns 390625, just like `square(square(square(5)))`.

```py linenums="1"
def make_repeater(f, n):
    """Returns the function that computes the nth application of f.

    >>> add_three = make_repeater(increment, 3)
    >>> add_three(5)
    8
    >>> make_repeater(triple, 5)(1) # 3 * (3 * (3 * (3 * (3 * 1))))
    243
    >>> make_repeater(square, 2)(5) # square(square(5))
    625
    >>> make_repeater(square, 3)(5) # square(square(square(5)))
    390625
    """
    def function(k):
        i=1
        result=k
        while i<=n:
            result=f(result)
            i+=1
        return result
    return function
```

***

## Homework3

### Q1: Num Eights

Write a recursive function `num_eights` that takes a positive integer `n` and returns the number of times the digit 8 appears in `n`.

```py linenums="1"
def num_eights(n):
    """Returns the number of times 8 appears as a digit of n.

    >>> num_eights(3)
    0
    >>> num_eights(8)
    1
    >>> num_eights(88888888)
    8
    >>> num_eights(2638)
    1
    >>> num_eights(86380)
    2
    >>> num_eights(12345)
    0
    >>> num_eights(8782089)
    3
    >>> from construct_check import check
    >>> # ban all assignment statements
    >>> check(HW_SOURCE_FILE, 'num_eights',
    ...       ['Assign', 'AnnAssign', 'AugAssign', 'NamedExpr', 'For', 'While'])
    True
    """
    if n<10:
        return 1 if n==8 else 0
    else:
        return num_eights(n//10)+(1 if n%10==8 else 0)
```

### Q2: Digit Distance

For a given integer, the digit distance is the sum of the absolute differences between consecutive digits. For example:

* The digit distance of 61 is 5, as the absolute value of 6-1 is 5.
* The digit distance of 71253 is 12 (abs(7-1)+abs(1-2)+abs(2-5)+abs(5-3)=6+1+3+2).
* The digit distance of 6 is 0 because there are no pairs of consecutive digits.

Write a function that determines the digit distance of a positive integer. You must use recursion or the tests will fail.

```py linenums="1"
def digit_distance(n):
    """Determines the digit distance of n.

    >>> digit_distance(3)
    0
    >>> digit_distance(777) # 0 + 0
    0
    >>> digit_distance(314) # 2 + 3
    5
    >>> digit_distance(31415926535) # 2 + 3 + 3 + 4 + ... + 2
    32
    >>> digit_distance(3464660003)  # 1 + 2 + 2 + 2 + ... + 3
    16
    >>> from construct_check import check
    >>> # ban all loops
    >>> check(HW_SOURCE_FILE, 'digit_distance',
    ...       ['For', 'While'])
    True
    """
    if n<10:
        return 0
    else:
        return digit_distance(n//10)+abs(n%10-n//10%10)
```

### Q3: Interleaved Sum

Write a function `interleaved_sum`, which takes in a number `n` and two one-argument functions: `odd_func` and `even_func`. It applies `odd_func` to every odd number and `even_func` to every even number from 1 to `n` inclusive and returns the sum.

```py linenums="1"
def interleaved_sum(n, odd_func, even_func):
    """Compute the sum odd_func(1) + even_func(2) + odd_func(3) + ..., up
    to n.

    >>> identity = lambda x: x
    >>> square = lambda x: x * x
    >>> triple = lambda x: x * 3
    >>> interleaved_sum(5, identity, square) # 1   + 2*2 + 3   + 4*4 + 5
    29
    >>> interleaved_sum(5, square, identity) # 1*1 + 2   + 3*3 + 4   + 5*5
    41
    >>> interleaved_sum(4, triple, square)   # 1*3 + 2*2 + 3*3 + 4*4
    32
    >>> interleaved_sum(4, square, triple)   # 1*1 + 2*3 + 3*3 + 4*3
    28
    >>> from construct_check import check
    >>> check(HW_SOURCE_FILE, 'interleaved_sum', ['While', 'For', 'Mod']) # ban loops and %
    True
    >>> check(HW_SOURCE_FILE, 'interleaved_sum', ['BitAnd', 'BitOr', 'BitXor']) # ban bitwise operators, don't worry about these if you don't know what they are
    True
    """
    def helper(k):
        if k==n:
            return odd_func(k)
        elif k==n-1:
            return odd_func(k)+even_func(k+1)
        else:
            return helper(k+2)+odd_func(k)+even_func(k+1)
    return helper(1)
```

### Q4: Count Dollars

Given a positive integer `total`, a set of dollar bills makes change for `total` if the sum of the values of the dollar bills is `total`. Here we will use standard US dollar bill values: 1, 5, 10, 20, 50, and 100. For example, the following sets make change for 15:

* 15 1-dollar bills
* 10 1-dollar, 1 5-dollar bills
* 5 1-dollar, 2 5-dollar bills
* 5 1-dollar, 1 10-dollar bills
* 3 5-dollar bills
* 1 5-dollar, 1 10-dollar bills
* 
Thus, there are 6 ways to make change for 15. Write a recursive function `count_dollars` that takes a positive integer `total` and returns the number of ways to make change for `total` using 1, 5, 10, 20, 50, and 100 dollar bills.

Use `next_smaller_dollar` in your solution: `next_smaller_dollar` will return the next smaller dollar bill value from the input (e.g. `next_smaller_dollar(5)` is 1). The function will return `None` if the next dollar bill value does not exist.

```py linenums="1"
def next_smaller_dollar(bill):
    """Returns the next smaller bill in order."""
    if bill == 100:
        return 50
    if bill == 50:
        return 20
    if bill == 20:
        return 10
    elif bill == 10:
        return 5
    elif bill == 5:
        return 1

def count_dollars(total):
    """Return the number of ways to make change.

    >>> count_dollars(15)  # 15 $1 bills, 10 $1 & 1 $5 bills, ... 1 $5 & 1 $10 bills
    6
    >>> count_dollars(10)  # 10 $1 bills, 5 $1 & 1 $5 bills, 2 $5 bills, 10 $1 bills
    4
    >>> count_dollars(20)  # 20 $1 bills, 15 $1 & $5 bills, ... 1 $20 bill
    10
    >>> count_dollars(45)  # How many ways to make change for 45 dollars?
    44
    >>> count_dollars(100) # How many ways to make change for 100 dollars?
    344
    >>> count_dollars(200) # How many ways to make change for 200 dollars?
    3274
    >>> from construct_check import check
    >>> # ban iteration
    >>> check(HW_SOURCE_FILE, 'count_dollars', ['While', 'For'])
    True
    """
    def count_dollars_limit(total,max):
        if total==0:
            return 1
        elif total<0:
            return 0
        elif max==None:
            return 0
        return count_dollars_limit(total,next_smaller_dollar(max))+count_dollars_limit(total-max,max)
    return count_dollars_limit(total,100)
```

### Q5: Count Dollars Upward

Write a recursive function `count_dollars_upward` that is just like `count_dollars` except it uses `next_larger_dollar`, which returns the next larger dollar bill value from the input (e.g. `next_larger_dollar(5)` is 10). The function will return `None` if the next dollar bill value does not exist.

```py linenums="1"
def next_larger_dollar(bill):
    """Returns the next larger bill in order."""
    if bill == 1:
        return 5
    elif bill == 5:
        return 10
    elif bill == 10:
        return 20
    elif bill == 20:
        return 50
    elif bill == 50:
        return 100

def count_dollars_upward(total):
    """Return the number of ways to make change using bills.

    >>> count_dollars_upward(15)  # 15 $1 bills, 10 $1 & 1 $5 bills, ... 1 $5 & 1 $10 bills
    6
    >>> count_dollars_upward(10)  # 10 $1 bills, 5 $1 & 1 $5 bills, 2 $5 bills, 10 $1 bills
    4
    >>> count_dollars_upward(20)  # 20 $1 bills, 15 $1 & $5 bills, ... 1 $20 bill
    10
    >>> count_dollars_upward(45)  # How many ways to make change for 45 dollars?
    44
    >>> count_dollars_upward(100) # How many ways to make change for 100 dollars?
    344
    >>> count_dollars_upward(200) # How many ways to make change for 200 dollars?
    3274
    >>> from construct_check import check
    >>> # ban iteration
    >>> check(HW_SOURCE_FILE, 'count_dollars_upward', ['While', 'For'])
    True
    """
    def count_dollars_limit(total,min):
        if total==0:
            return 1
        elif total<0:
            return 0
        elif min==None:
            return 0
        return count_dollars_limit(total,next_larger_dollar(min))+count_dollars_limit(total-min,min)
    return count_dollars_limit(total,1)
```

***

## Homework4

### Q1: Shuffle

Implement `shuffle`, which takes a sequence `s` (such as a list or range) with an even number of elements. It returns a new list that interleaves the elements of the first half of `s` with the elements of the second half. It does not modify `s`.

To interleave two sequences `s0` and `s1` is to create a new list containing the first element of `s0`, the first element of `s1`, the second element of `s0`, the second element of `s1`, and so on. For example, if `s0 = [1, 2, 3]` and `s1 = [4, 5, 6]`, then interleaving `s0` and `s1` would result in `[1, 4, 2, 5, 3, 6]`.

```py linenums="1"
def shuffle(s):
    """Return a shuffled list that interleaves the two halves of s.

    >>> shuffle(range(6))
    [0, 3, 1, 4, 2, 5]
    >>> letters = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h']
    >>> shuffle(letters)
    ['a', 'e', 'b', 'f', 'c', 'g', 'd', 'h']
    >>> shuffle(shuffle(letters))
    ['a', 'c', 'e', 'g', 'b', 'd', 'f', 'h']
    >>> letters  # Original list should not be modified
    ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h']
    """
    assert len(s) % 2 == 0, 'len(seq) must be even'
    s=list(s)
    tuple_list=list(zip(s[:len(s)//2],s[len(s)//2:]))
    return list(sum(tuple_list,()))
```

### Q2: Deep Map

Definition: A nested list of numbers is a list that contains numbers and lists. It may contain only numbers, only lists, or a mixture of both. The lists must also be nested lists of numbers. For example: `[1, [2, [3]], 4]`, `[1, 2, 3]`, and `[[1, 2], [3, 4]]` are all nested lists of numbers.

Write a function `deep_map` that takes two arguments: a nested list of numbers `s` and a one-argument function `f`. It modifies `s` in place by applying `f` to each number within `s` and replacing the number with the result of calling `f` on that number.

`deep_map` returns `None` and should not create any new lists.

```py linenums="1"
def deep_map(f, s):
    """Replace all non-list elements x with f(x) in the nested list s.

    >>> six = [1, 2, [3, [4], 5], 6]
    >>> deep_map(lambda x: x * x, six)
    >>> six
    [1, 4, [9, [16], 25], 36]
    >>> # Check that you're not making new lists
    >>> s = [3, [1, [4, [1]]]]
    >>> s1 = s[1]
    >>> s2 = s1[1]
    >>> s3 = s2[1]
    >>> deep_map(lambda x: x + 1, s)
    >>> s
    [4, [2, [5, [2]]]]
    >>> s1 is s[1]
    True
    >>> s2 is s1[1]
    True
    >>> s3 is s2[1]
    True
    """
    for i in range(len(s)):
        if type(s[i])==list:
            deep_map(f,s[i])
        else:
            s[i]=f(s[i])
```

![alt text](image/16.1.png)

### Q3: Mass

Implement the `planet` data abstraction by completing the `planet` constructor and the `mass` selector. A planet should be represented using a two-element list where the first element is the string `'planet'` and the second element is the planet's mass. The `mass` function should return the mass of the `planet` object that is passed as a parameter.

```py linenums="1"
def planet(mass):
    """Construct a planet of some mass."""
    assert mass > 0
    return ['planet',mass]

def mass(p):
    """Select the mass of a planet."""
    assert is_planet(p), 'must call mass on a planet'
    return p[1]

def is_planet(p):
    """Whether p is a planet."""
    return type(p) == list and len(p) == 2 and p[0] == 'planet'
```

### Q4: Balanced

Implement the `balanced` function, which returns whether `m` is a balanced mobile. A mobile is balanced if both of the following conditions are met:

* The torque applied by its left arm is equal to the torque applied by its right arm. The torque of the left arm is the length of the left rod multiplied by the total mass hanging from that rod. Likewise for the right. For example, if the left arm has a length of 5, and there is a mobile hanging at the end of the left arm of total mass 10, the torque on the left side of our mobile is 50.
* Each of the mobiles hanging at the end of its arms is itself balanced.

Planets themselves are balanced, as there is nothing hanging off of them.

```py linenums="1"
def balanced(m):
    """Return whether m is balanced.

    >>> t, u, v = examples()
    >>> balanced(t)
    True
    >>> balanced(v)
    True
    >>> p = mobile(arm(3, t), arm(2, u))
    >>> balanced(p)
    False
    >>> balanced(mobile(arm(1, v), arm(1, p)))
    False
    >>> balanced(mobile(arm(1, p), arm(1, v)))
    False
    >>> from construct_check import check
    >>> # checking for abstraction barrier violations by banning indexing
    >>> check(HW_SOURCE_FILE, 'balanced', ['Index'])
    True
    """
    if is_mobile(m):
        is_torque_balanced=length(left(m))*total_mass(end(left(m)))==length(right(m))*total_mass(end(right(m)))
        is_sub_balanced=balanced(end(left(m))) and balanced(end(right(m)))
        return is_torque_balanced and is_sub_balanced
    else:
        return True
```

### Q5: Finding Berries!

The squirrels on campus need your help! There are a lot of trees on campus and the squirrels would like to know which ones contain berries. Define the function `berry_finder`, which takes in a tree and returns `True` if the tree contains a node with the value 'berry' and `False` otherwise.

```py linenums="1"
def berry_finder(t):
    """Returns True if t contains a node with the value 'berry' and 
    False otherwise.

    >>> scrat = tree('berry')
    >>> berry_finder(scrat)
    True
    >>> sproul = tree('roots', [tree('branch1', [tree('leaf'), tree('berry')]), tree('branch2')])
    >>> berry_finder(sproul)
    True
    >>> numbers = tree(1, [tree(2), tree(3, [tree(4), tree(5)]), tree(6, [tree(7)])])
    >>> berry_finder(numbers)
    False
    >>> t = tree(1, [tree('berry',[tree('not berry')])])
    >>> berry_finder(t)
    True
    """
    if is_leaf(t):
        return label(t)=='berry'
    else:
        b=branches(t)
        if label(t)=='berry':
            return True
        else:
            return not all(not berry_finder(x) for x in b)
```

### Q6: Maximum Path Sum

Write a function that takes in a tree and returns the maximum sum of the values along any root-to-leaf path in the tree. A root-to-leaf path is a sequence of nodes starting at the root and proceeding to some leaf of the tree. You can assume the tree will have positive numbers for its labels.

```py linenums="1"
def max_path_sum(t):
    """Return the maximum root-to-leaf path sum of a tree.
    >>> t = tree(1, [tree(5, [tree(1), tree(3)]), tree(10)])
    >>> max_path_sum(t) # 1, 10
    11
    >>> t2 = tree(5, [tree(4, [tree(1), tree(3)]), tree(2, [tree(10), tree(3)])])
    >>> max_path_sum(t2) # 5, 2, 10
    17
    """
    def sum_list(t,accumulate):
        if is_leaf(t):
            return [label(t)+accumulate]
        else:
            return sum([sum_list(b,accumulate+label(t)) for b in branches(t)],[])
    return max(sum_list(t,0))
```

***

## Homework5

### Q1: Infinite Hailstone

Write a generator function that yields the elements of the hailstone sequence starting at number `n`. After reaching the end of the hailstone sequence, the generator should yield the value 1 indefinitely.

Here is a quick reminder of how the hailstone sequence is defined:

* Pick a positive integer `n` as the start.
* If `n` is even, divide it by 2.
* If `n` is odd, multiply it by 3 and add 1.
* Continue this process until `n` is 1.

Try to write this generator function recursively. If you are stuck, you can first try writing it iteratively and then seeing how you can turn that implementation into a recursive one.

```py linenums="1"
def hailstone(n):
    """
    Yields the elements of the hailstone sequence starting at n.
    At the end of the sequence, yield 1 infinitely.

    >>> hail_gen = hailstone(10)
    >>> [next(hail_gen) for _ in range(10)]
    [10, 5, 16, 8, 4, 2, 1, 1, 1, 1]
    >>> next(hail_gen)
    1
    """
    yield n
    if n%2==0:
        yield from hailstone(n//2)
    else:
        if n==1:
            yield from hailstone(1)
        else:
            yield from hailstone(n*3+1)
```

### Q2: Merge

Definition: An infinite iterator is a iterator that never stops providing values when `next` is called. For example, `ones()` evaluates to an infinite iterator:

```py linenums="1"
def ones():
    while True:
        yield 1
```

Write a generator function `merge(a, b)` that takes two infinite iterators, `a` and `b`, as inputs. Both iterators yield elements in strictly increasing order with no duplicates. The generator should produce all unique elements from both input iterators in increasing order, ensuring no duplicates.

```py  linenums="1"
def merge(a, b):
    """
    Return a generator that has all of the elements of generators a and b,
    in increasing order, without duplicates.

    >>> def sequence(start, step):
    ...     while True:
    ...         yield start
    ...         start += step
    >>> a = sequence(2, 3) # 2, 5, 8, 11, 14, ...
    >>> b = sequence(3, 2) # 3, 5, 7, 9, 11, 13, 15, ...
    >>> result = merge(a, b) # 2, 3, 5, 7, 8, 9, 11, 13, 14, 15
    >>> [next(result) for _ in range(10)]
    [2, 3, 5, 7, 8, 9, 11, 13, 14, 15]
    """
    a_val, b_val = next(a), next(b)
    while True:
        if a_val == b_val:
            yield a_val
            a_val=next(a)
            b_val=next(b)
        elif a_val < b_val:
            yield a_val
            a_val=next(a)
        else:
            yield b_val
            b_val=next(b)
```

### Q3: Stair Ways

Imagine that you want to go up a staircase that has `n` steps, where `n` is a positive integer. You can take either one or two steps each time you move.

Write a generator function `stair_ways` that yields all the different ways you can climb the staircase.

Each "way" of climbing a staircase can be represented by a list of 1s and 2s, where each number indicates whether you take one step or two steps at a time.

For example, for a staircase with 3 steps, there are three ways to climb it:

* You can take one step each time: `[1, 1, 1]`.
* You can take two steps then one step: `[2, 1]`.
* You can take one step then two steps: `[1, 2]`.

Therefore, `stair_ways(3)` should yield `[1, 1, 1]`, `[2, 1]`, and `[1, 2]`. These can be yielded in any order.

```py linenums="1"
def stair_ways(n):
    """
    Yield all the ways to climb a set of n stairs taking
    1 or 2 steps at a time.

    >>> list(stair_ways(0))
    [[]]
    >>> s_w = stair_ways(4)
    >>> sorted([next(s_w) for _ in range(5)])
    [[1, 1, 1, 1], [1, 1, 2], [1, 2, 1], [2, 1, 1], [2, 2]]
    >>> list(s_w) # Ensure you're not yielding extra
    []
    """
    if n==0:
        yield []
    elif n==1:
        yield [1]
    else:
        for p in stair_ways(n-1):
            yield p+[1]
        for p in stair_ways(n-2):
            yield p+[2]
```

### Q4: Yield Paths

Write a generator function `yield_paths` that takes a tree `t` and a target `value`. It yields each path from the root of `t` to any node with the label `value`.

Each path should be returned as a list of labels from the root to the matching node. The paths can be yielded in any order.

```py linenums="1"
def yield_paths(t, value):
    """
    Yields all possible paths from the root of t to a node with the label
    value as a list.

    >>> t1 = tree(1, [tree(2, [tree(3), tree(4, [tree(6)]), tree(5)]), tree(5)])
    >>> print_tree(t1)
    1
      2
        3
        4
          6
        5
      5
    >>> next(yield_paths(t1, 6))
    [1, 2, 4, 6]
    >>> path_to_5 = yield_paths(t1, 5)
    >>> sorted(list(path_to_5))
    [[1, 2, 5], [1, 5]]

    >>> t2 = tree(0, [tree(2, [t1])])
    >>> print_tree(t2)
    0
      2
        1
          2
            3
            4
              6
            5
          5
    >>> path_to_2 = yield_paths(t2, 2)
    >>> sorted(list(path_to_2))
    [[0, 2], [0, 2, 1, 2]]
    """
    if label(t) == value:
        yield [value]
    for b in branches(t):
        for p in yield_paths(b,value):
            yield [label(t)]+p
```

***

## Homework6

### Q1: Vending Machine

In this question you'll create a vending machine that sells a single product and provides change when needed.

Implement the `VendingMachine` class, which models a vending machine for one specific product. The methods of a `VendingMachine` object return strings to describe the machine’s status and operations. Ensure that your output matches exactly with the strings provided in the doctests, including punctuation and spacing.

```py linenums="1"
class VendingMachine:
    """A vending machine that vends some product for some price.

    >>> v = VendingMachine('candy', 10)
    >>> v.vend()
    'Nothing left to vend. Please restock.'
    >>> v.add_funds(15)
    'Nothing left to vend. Please restock. Here is your $15.'
    >>> v.restock(2)
    'Current candy stock: 2'
    >>> v.vend()
    'Please add $10 more funds.'
    >>> v.add_funds(7)
    'Current balance: $7'
    >>> v.vend()
    'Please add $3 more funds.'
    >>> v.add_funds(5)
    'Current balance: $12'
    >>> v.vend()
    'Here is your candy and $2 change.'
    >>> v.add_funds(10)
    'Current balance: $10'
    >>> v.vend()
    'Here is your candy.'
    >>> v.add_funds(15)
    'Nothing left to vend. Please restock. Here is your $15.'

    >>> w = VendingMachine('soda', 2)
    >>> w.restock(3)
    'Current soda stock: 3'
    >>> w.restock(3)
    'Current soda stock: 6'
    >>> w.add_funds(2)
    'Current balance: $2'
    >>> w.vend()
    'Here is your soda.'
    """
    def __init__(self, product, price):
        """Set the product and its price, as well as other instance attributes."""
        self.product=product
        self.price=price
        self.stock=0
        self.balance=0

    def restock(self, n):
        """Add n to the stock and return a message about the updated stock level.

        E.g., Current candy stock: 3
        """
        self.stock+=n
        return f'Current {self.product} stock: {self.stock}'

    def add_funds(self, n):
        """If the machine is out of stock, return a message informing the user to restock
        (and return their n dollars).

        E.g., Nothing left to vend. Please restock. Here is your $4.

        Otherwise, add n to the balance and return a message about the updated balance.

        E.g., Current balance: $4
        """
        if self.stock<=0:
            return f'Nothing left to vend. Please restock. Here is your ${n}.'
        else:
            self.balance+=n
            return f'Current balance: ${self.balance}'

    def vend(self):
        """Dispense the product if there is sufficient stock and funds and
        return a message. Update the stock and balance accordingly.

        E.g., Here is your candy and $2 change.

        If not, return a message suggesting how to correct the problem.

        E.g., Nothing left to vend. Please restock.
              Please add $3 more funds.
        """
        if self.stock<=0:
            return 'Nothing left to vend. Please restock.'
        else:
            if self.balance>self.price:
                change=self.balance-self.price
                self.balance=0
                self.stock-=1
                return f'Here is your {self.product} and ${change} change.'
            elif self.balance<self.price:
                return f'Please add ${self.price-self.balance} more funds.'
            else:
                self.balance=0
                self.stock-=1
                return f'Here is your {self.product}.'
```

### Q2: Store Digits

Write a function `store_digits` that takes in an integer `n` and returns a linked list containing the digits of `n` in the same order (from left to right).

```py linenums="1"
def store_digits(n):
    """Stores the digits of a positive number n in a linked list.

    >>> s = store_digits(1)
    >>> s
    Link(1)
    >>> store_digits(2345)
    Link(2, Link(3, Link(4, Link(5))))
    >>> store_digits(876)
    Link(8, Link(7, Link(6)))
    >>> store_digits(2450)
    Link(2, Link(4, Link(5, Link(0))))
    >>> store_digits(20105)
    Link(2, Link(0, Link(1, Link(0, Link(5)))))
    >>> # a check for restricted functions
    >>> import inspect, re
    >>> cleaned = re.sub(r"#.*\\n", '', re.sub(r'"{3}[\s\S]*?"{3}', '', inspect.getsource(store_digits)))
    >>> print("Do not use str or reversed!") if any([r in cleaned for r in ["str", "reversed"]]) else None
    """
    s=Link.empty
    while n!=0:
        s=Link(n%10,s)
        n//=10
    return s
```

### Q3: Mutable Mapping

Implement `deep_map_mut(func, s)`, which applies the function `func` to each element in the linked list `s`. If an element is itself a linked list, recursively apply func to its elements as well.

Your implementation should mutate the original linked list. Do not create any new linked lists. The function returns `None`.

```py linenums="1"
def deep_map_mut(func, s):
    """Mutates a deep link s by replacing each item found with the
    result of calling func on the item. Does NOT create new Links (so
    no use of Link's constructor).

    Does not return the modified Link object.

    >>> link1 = Link(3, Link(Link(4), Link(5, Link(6))))
    >>> print(link1)
    <3 <4> 5 6>
    >>> # Disallow the use of making new Links before calling deep_map_mut
    >>> Link.__init__, hold = lambda *args: print("Do not create any new Links."), Link.__init__
    >>> try:
    ...     deep_map_mut(lambda x: x * x, link1)
    ... finally:
    ...     Link.__init__ = hold
    >>> print(link1)
    <9 <16> 25 36>
    """
    if not s:
        return None
    if isinstance(s.first,Link):
        deep_map_mut(func,s.first)
    else:
        s.first=func(s.first)
    deep_map_mut(func,s.rest)
```

### Q4: Two List

Implement a function `two_list` that takes in two lists and returns a linked list. The first list contains the values that we want to put in the linked list, and the second list contains the number of each corresponding value. Assume both lists are the same size and have a length of 1 or greater. Assume all elements in the second list are greater than 0.

```py linenums="1"
def two_list(vals, counts):
    """
    Returns a linked list according to the two lists that were passed in. Assume
    vals and counts are the same size. Elements in vals represent the value, and the
    corresponding element in counts represents the number of this value desired in the
    final linked list. Assume all elements in counts are greater than 0. Assume both
    lists have at least one element.
    >>> a = [1, 3]
    >>> b = [1, 1]
    >>> c = two_list(a, b)
    >>> c
    Link(1, Link(3))
    >>> a = [1, 3, 2]
    >>> b = [2, 2, 1]
    >>> c = two_list(a, b)
    >>> c
    Link(1, Link(1, Link(3, Link(3, Link(2)))))
    """
    if not vals:
        return Link.empty
    s=two_list(vals[1:],counts[1:])
    for i in range(counts[0]):
        s=Link(vals[0],s)
    return s
```

***

## Homework7

### Q1: Pow

Implement a procedure `pow` that raises a number `base` to the power of a nonnegative integer `exp`. The number of recursive `pow` calls should grow logarithmically with respect to `exp`, rather than linearly. For example, `(pow 2 32)` should result in 5 recursive `pow` calls rather than 32 recursive `pow` calls.

```scheme linenums="1"
(define (pow base exp) 
        (cond ((= exp 1) base) 
              ((even? exp) (square (pow base (/ exp 2)))) 
              (else (* base (square (pow base (/ (- exp 1) 2)))))))
```

### Q2: Repeatedly Cube

Implement `repeatedly-cube`, which receives a number `x` and cubes it `n` times.

```scheme linenums="1"
(define (repeatedly-cube n x)
  (if (zero? n)
      x
      (let ((y (repeatedly-cube (- n 1) x)))
        (* y y y))))
```

### Q3: Cadr and Caddr

Define the procedure `cadr`, which returns the second element of a list. Also define `caddr`, which returns the third element of a list.

```scheme linenums="1"
(define (cddr s) (cdr (cdr s)))

(define (cadr s) (car (cdr s)))

(define (caddr s) (car (cddr s)))
```

***

## Homework8

### Q1: Ascending

Implement a procedure called `ascending?`, which takes a list of numbers s and returns `True` if the numbers are in non-descending order, and `False` otherwise.

A list of numbers is non-descending if each element after the first is greater than or equal to the previous element.

```scheme linenums="1"
(define (ascending? s)
    (cond ((null? s) #t)
        ((null? (cdr s)) #t)
        (else
            (if (> (car s) (car (cdr s))) 
                #f
                (ascending? (cdr s)) ))))
```

### Q2: My Filter

Write a procedure `my-filter`, which takes in a one-argument predicate function `pred` and a list `s`, and returns a new list containing only elements in list `s` that satisfy the predicate. The returned list should contain the elements in the same order that they appeared in the original list `s`.

```scheme linenums="1"
(define (my-filter pred s)
    (if (null? s) 
        nil
        (append (if (pred (car s)) 
                    (cons (car s) nil) 
                    nil) 
                (my-filter pred (cdr s)))))
```

### Q3: Interleave

Implement the function `interleave`, which takes two lists `lst1` and `lst2` as arguments, and returns a new list that alternates elements from both lists, starting with `lst1`.

If one of the input lists is shorter than the other, `interleave` should include elements from both lists until the shorter list is exhausted, then append the remaining elements of the longer list to the end. If either `lst1` or `lst2` is empty, the function should simply return the other non-empty list.

```scheme linenums="1"
(define (interleave lst1 lst2) 
        (cond ((null? lst1) lst2) 
              ((null? lst2) lst1) 
              (else (append (cons (car lst1) nil) 
                            (cons (car lst2) nil) 
                            (interleave (cdr lst1) (cdr lst2))))))
```

### Q4: No Repeats

Implement `no-repeats`, which takes a list of numbers `s`. It returns a list that has all of the unique elements of `s` in the order that they first appear, but no repeats.

```scheme linenums="1"
(define (no-repeats s) 
    (if (null? s) 
        nil
        (append (cons (car s) nil) 
                (no-repeats (filter (lambda (x) (not (= x (car s)))) (cdr s))))))
```

***

## Homework9

### Q1: Cooking Curry

Implement the function `curry-cook`, which takes in a Scheme list `formals` and a quoted expression `body`. `curry-cook` should generate a program as a list that is a curried version of a lambda function. The returned program should be a curried version of a lambda function with formal arguments equal to `formals`, and a function body equal to `body`. You may assume that all functions passed in will have more than 0 `formals`; otherwise, it would not be curry-able!

```scheme linenums="1"
(define (curry-cook formals body)
        (if (null? (cdr formals))
           (list 'lambda (list (car formals)) body)
           (list 'lambda (list (car formals)) (curry-cook (cdr formals) body))))
```

### Q2: Consuming Curry

Implement the function `curry-consume`, which takes in a curried lambda function `curry` and applies the function to a list of arguments `args`. You may make the following assumptions:

* If `curry` is an n-curried function, then there will be at most `n` arguments in `args`.
* If there are 0 arguments (`args` is an empty list), then you may assume that `curry` has been fully applied with relevant arguments; in this case, `curry` now contains a value representing the output of the lambda function. Return it.

Note that there can be fewer `args` than `formals` for the corresponding lambda function `curry`! In the case that there are fewer arguments, `curry-consume` should return a curried lambda function, which is the result of partially applying `curry` up to the number of `args` provdied. 

```scheme linenums="1"
(define (curry-consume curry args)
        (if (null? args)
            curry
            (curry-consume (curry (car args)) (cdr args))))
```

### Q3: Switch to Cond

`switch` is a macro that takes in an expression `expr` and a list of pairs `options`, where the first element of each pair is some value and the second element is a single expression. `switch` evaluates the expression contained in the list of `options` that corresponds to the value that `expr` evaluates to. `switch` uses another procedure called `switch-to-cond` in its implementation

Define `switch-to-cond`, a procedure (not a macro) that takes in a quoted `switch` expression and converts it into a `cond` expression with the same behavior.

```scheme linenums="1"
(define-macro (switch expr options)
  (switch-to-cond (list 'switch expr options)))

(define (switch-to-cond switch-expr)
  (cons 'cond
        (map (lambda (option)
               (cons (list 'equal? (car (cdr switch-expr)) (car option)) (cdr option)))
             (car (cdr (cdr switch-expr))))))
```

***

## Homework10

```sql linenums="1"
CREATE TABLE parents AS
  SELECT "ace" AS parent, "bella" AS child UNION
  SELECT "ace"          , "charlie"        UNION
  SELECT "daisy"        , "hank"           UNION
  SELECT "finn"         , "ace"            UNION
  SELECT "finn"         , "daisy"          UNION
  SELECT "finn"         , "ginger"         UNION
  SELECT "ellie"        , "finn";

CREATE TABLE dogs AS
  SELECT "ace" AS name, "long" AS fur, 26 AS height UNION
  SELECT "bella"      , "short"      , 52           UNION
  SELECT "charlie"    , "long"       , 47           UNION
  SELECT "daisy"      , "long"       , 46           UNION
  SELECT "ellie"      , "short"      , 35           UNION
  SELECT "finn"       , "curly"      , 32           UNION
  SELECT "ginger"     , "short"      , 28           UNION
  SELECT "hank"       , "curly"      , 31;

CREATE TABLE sizes AS
  SELECT "toy" AS size, 24 AS min, 28 AS max UNION
  SELECT "mini"       , 28       , 35        UNION
  SELECT "medium"     , 35       , 45        UNION
  SELECT "standard"   , 45       , 60;
```

### Q1: By Parent Height

Create a table `by_parent_height` that has a column of the names of all dogs that have a `parent`, ordered by the height of the parent dog from tallest parent to shortest parent.

```sql linenums="1"
CREATE TABLE by_parent_height AS
  SELECT child
  FROM parents, dogs
  WHERE parent = name
  ORDER BY height DESC;
```

### Q2: Size of Dogs

The Fédération Cynologique Internationale classifies a standard poodle as over 45 cm and up to 60 cm. The `sizes` table describes this and other such classifications, where a dog must be over the `min` and less than or equal to the `max` in `height` to qualify as `size`.

Create a `size_of_dogs` table with two columns, one for each dog's `name` and another for its `size`.

```sql linenums="1"
CREATE TABLE size_of_dogs AS
  SELECT name, size
  FROM dogs, sizes
  WHERE min < height AND height <= max;
```

### Q3: Sentences

There are two pairs of siblings that have the same size. Create a table that contains a row with a string for each of these pairs. Each string should be a sentence describing the siblings by their size.

Each sibling pair should appear only once in the output, and siblings should be listed in alphabetical order (e.g. `"bella and charlie..."` instead of `"charlie and bella..."`).

```sql linenums="1"
CREATE TABLE siblings AS
  SELECT a.child AS child1, b.child AS child2
  FROM parents AS a, parents AS b
  WHERE a.parent = b.parent AND a.child < b.child;

CREATE TABLE sentences AS
  SELECT "The two siblings, " || child1 || " and " || child2 || ", have the same size: " || c.size
  FROM siblings, size_of_dogs AS c, size_of_dogs as d
  WHERE child1 = c.name AND child2 = d.name AND c.size = d.size;
```

### Q4: Low Variance

We want to create a table that contains the height range (defined as the difference between maximum and minimum `height`) of all dogs that share a fur type. However, we'll only consider `fur` types where each dog with that `fur` type is within 30% of the average `height` of all dogs with that `fur` type; we call this the low variance criterion.

```sql linenums="1"
CREATE TABLE low_variance AS
  SELECT fur, max_height - min_height AS height_range
  FROM (SELECT fur, AVG(height) AS avg_height, MAX(height) AS max_height, MIN(height) AS min_height
        FROM dogs
        GROUP BY fur)
  WHERE min_height >= 0.7 * avg_height AND max_height <= 1.3 * avg_height;
```