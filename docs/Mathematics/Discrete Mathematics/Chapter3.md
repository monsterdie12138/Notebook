---
comments: true
---

<span style="font-family: 'Times New Roman';">

# Chapter3 Algorithms

***

## 3.1 Algorithms

**Halting Problem:**

是否存在一个程序 P，对于任意输入的程序 w，能够判断 w 会在有限时间内结束或者死循环？  

不存在证明：用 P 构造新的机器 Q，当 P 判断 Q 无限循环时，则 Q 停机，当 P 判断 Q 停机时，Q 持续输出 “ha”。

***

## 3.2 The Growth of Functions

* **$f(x)=O(g(x))$**  
  存在常量 $C$，$k$，使得当 $x>k$ 时，有 $|f(x)|\leqslant C|g(x)|$

* **$f(x)=\Omega(g(x))$**  
  存在常量 $C$，$k$，使得当 $x>k$ 时，有 $|f(x)|\geqslant C|g(x)|$  

* **$f(x)=\Theta(g(x))$**  
  $f(x)=O(g(x))$ 且 $f(x)=\Omega(g(x))$

***

## 3.3 Complexity of Algorithms

* 线性搜索：$O(n)$

* 二分搜索：$O(\log n)$

* 冒泡排序：$O(n^2)$

* 插入排序：$O(n^2)$

* 矩阵乘法：$O(n^3)$

* 矩阵布尔积：$O(n^3)$

**Tractable Problem（易解问题）:**

能用多项式时间解决的问题，这些问题属于 Class P。