---
comments: true
---

<span style="font-family: 'Times New Roman';">

# Chapter5 Induction and Recursion

***

## 5.1 Strong Induction and Well-Ordering

**Strong Induction:**

假设前 $n-1$ 项都为真，推第 $n$ 项。 

**Computational Geometry:**

* polygon 多边形
* convex 凸
* diagonal 对角线
* triangulation 三角形化

每个简单多边形都至少有一条内部的对角线。  

有 $n$ 条边的简单多边形可以分成 $n-2$ 个三角形。

**Well-Ordering:**

良序原理：每个非空非负整数的集合有最小元。  

良序原理的泛化：如果一个集合的每一个子集都有最小元，则这个集合是良序的。  

***

## 5.2 Recursive Definitions and Structural Induction

**Lame’s Theorem:**

$a$，$b$ 为两个正整数，$a\geqslant b$，则用辗转相除法求 $\gcd(a,b)$ 的步骤次数小于等于 $b$ 的十进制下的位数的 $5$ 倍。