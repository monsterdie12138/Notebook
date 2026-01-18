---
comments: true
---

<span style="font-family: 'Times New Roman';">

# Lec1

***

## 字符串 Binary String

**字符集：**

$$\Sigma=\\{0,1\\}$$

由字符集元素所构成的长度为 $n$ 的字符串集合：

$$\Sigma^n=\underbrace{\Sigma\times\Sigma\times...\times\Sigma}_{n\text{ times}}=\\{a_1a_2...a_n:a_i\in\Sigma\\}$$

特殊的集合表示：

$$\Sigma^0=\\{e~\text{(empty string)}\\}$$

$$\Sigma^*=\Sigma^0\cup\Sigma^1\cup...=\bigcup\limits_{n\geqslant 0}\Sigma^n$$

**字符拼接：**

设字符串 $x=a_1...a_n$，$y=b_1...b_m$，则它们的拼接为：

$$xy=a_1...a_n b_1...b_m$$

* $x$ 是 $y$ 的**前缀（prefix）** 当且仅当 $\exists z\in\Sigma^*,y=xz$
* $x$ 是 $y$ 的**后缀（suffix）** 当且仅当 $\exists z\in\Sigma^*,y=zx$

***

## 编码 Encoding

怎样将图、矩阵等编码成 $01$ 字符串？

编码的本质是集合 $A$ 上的函数映射 $E$：

$$E:A\rightarrow\\{0,1\\}^*$$

$E$ 需要满足的条件是**单射（one-to-one）**，即：

$$E(x)\neq E(x')\text{ if } x\neq x'$$

!!! Example
    **自然数编码：**

    $$\text{NtS}(n)=\begin{cases}
        0&n=0\\\
        1&n=1\\\
        \text{NtS}(\lfloor\frac{n}{2}\rfloor)\text{parity}(n)&n>1
    \end{cases}$$

    其中，parity 为奇偶校验，奇数为 1，偶数为 0。

    **自然数对编码：**

    前后两个数分别用自然数编码，中间用逗号隔开，然后重新编码：

    $$\begin{cases}
        0\rightarrow 00\\\
        1\rightarrow 11\\\
        ,\rightarrow 01
    \end{cases}$$

    例如：$(1,6)\rightarrow 1,110\rightarrow 1101111100$

通过联想[霍夫曼编码](../../Mathematics/Discrete%20Mathematics/Chapter10.md#102-applications-of-trees)，我们可以知道，编码需要满足 **prefix-free**，即没有一个编码是另一个编码的前缀。

### Lemma 1

如果编码

$$E:A\rightarrow \\{0,1\\}^*$$

是 **prefix-free** 的，其中 $A$ 是一个字符集，则

$$\overline{E}:A^\*\rightarrow\\{0,1\\}^\*$$

是 **one-to-one** 的。

!!! Tip "Proof"
    **反证法：**
    
    假设存在

    $$(a_1,a_2,...,a_{k_a})\neq(b_1,b_2,...,b_{k_b})\in A^*$$

    但

    $$\overline{E}(a_1,a_2,...,a_{k_a})=\overline{E}(b_1,b_2,...,b_{k_b})$$
    依次比较 $a_1$ 和 $b_1$，$a_2$ 和 $b_2$，...，直到第一对不同的字符 $a_i\neq b_i$，若能找到，则

    $$\overline{E}(a_1,a_2,...,a_{k_a})=E(a_1)E(a_2)...E(a_{i-1})E(a_i)E(a_{i+1})...E(a_{k_a})$$

    $$\overline{E}(b_1,b_2,...,b_{k_b})=E(b_1)E(b_2)...E(b_{i-1})E(b_i)E(b_{i+1})...E(b_{k_b})$$

    其中

    $$E(a_1)E(a_2)...E(a_{i-1})=E(b_1)E(b_2)...E(b_{i-1})$$

    因此有

    $$E(a_i)E(a_{i+1})...E(a_{k_a})=E(b_i)E(b_{i+1})...E(b_{k_b})$$

    从上式我们可以看出，$E(a_i)$ 和 $E(b_i)$ 的其中一个肯定是另一个的前缀。但由于 $a_i\neq b_i$ 且 $E$ 是 prefix-free 的，因此产生矛盾。

    如果找不到 $i$，假设 $k_a<k_b$，则

    $$E(b_{i+1})...E(b_{k_b})=e$$

    这同样不成立。

### Lemma 2

如果编码

$$E:A\rightarrow \\{0,1\\}^*$$

是 **one-to-one** 的，其中 $A$ 是一个字符集，则存在

$$E':A\rightarrow\\{0,1\\}^*$$

是 **prefix-free** 的，且有

$$|E'(a)|\leqslant 2|E(a)|+2 \text{ for }\forall a\in A$$

!!! Tip "Proof"
    例如，$E(a)=010$

    将老编码的每个 0 替换为 00，每个 1 替换为 11，最后加上 01 作为结尾。则有 $E'(a)=00110001$。

    若 $a\neq b$，则 $E'(a)$ 不可能是 $E'(b)$ 的前缀，因为分别在奇数位和偶数位的 01 只能出现在末尾。也不可能相等，因为 $E$ 是 one-to-one 的。

    不等式也不证自明。

### Theorem 1

前面有两个引理：

* 如果字符集上的编码是 prefix-free 的，则字符串集上的编码是 one-to-one 的
* 如果字符集上的编码是 one-to-one 的，则存在 prefix-free 的编码

结合起来，我们可以得到：

如果存在

$$E:A\rightarrow \\{0,1\\}^*$$

是 **one-to-one** 的，其中 $A$ 是一个字符集，则存在

$$E':A^\*\rightarrow\\{0,1\\}^\*$$

也是 **one-to-one** 的。

***

## 可数 Countable

* 集合 $A$ 可数
* $A$ 是有限集或存在双射 $f:A\rightarrow N$
* 存在单射 $g:A\rightarrow N$
* 存在满射 $h:N\rightarrow A$

这四个条件是等价的。

### Lemma 3

$\\{0,1\\}^*$ 是可数的。

!!! Tip "Proof"
    利用第三条构造单射。

    先对 $\\{0,1\\}^*$ 的元素排序，在集合角度上先按照 $\\{0,1\\}^0,\\{0,1\\}^1,\\{0,1\\}^2,...$ 排序，然后在每个子集中按照字典序排序。

    我们可以构造出单射函数：

    $$f(x)=\begin{cases}
        0,x=e\\\
        2^{|x|}+\text{NtS}(|x|),|x|\geqslant 1
    \end{cases}$$

### Theorem 2

集合 $A$ 可数，当且仅当存在 **one-to-one** 的编码

$$E:A\rightarrow\\{0,1\\}^*$$

!!! Tip "Proof"
    **左推右：**

    因为 $A$ 可数，所以存在单射 $f:A\rightarrow N$。

    又因为 lemma3 说 $\\{0,1\\}^{\*}$ 可数，因此存在双射 $g:N\rightarrow\\{0,1\\}^{\*}$。

    结合这两个映射，便可得证。

    **右推左：**

    同样我们可以得知：存在双射 $g:\\{0,1\\}^*\rightarrow N$。

    再结合右边的结论，便可得到 $A$ 到 $N$ 也有一个单射，因此 $A$ 可数，得证。

***

## 问题 Problem

problem 是否可数？No！

!!! Tip "Proof"
    problem 实质就是函数。考虑某个特殊的函数集合 $\\{f:f:N\rightarrow\\{0,1\\}\\}$，通过反证法证明这个集合不可数。

    若可数，则进行排序：$f_1,f_2,f_3,...$

    构造函数 $g$，满足

    $$g(i)=\begin{cases}
        0&f_i(i)=1\\\
        1&f_i(i)=0
    \end{cases}$$

    此时，$g$ 不等于任何一个 $f_i$，但 $g$ 依然属于这个函数集合，因此产生矛盾。

    !!! Note
        $\\{f:f:\\{0,1\\}^*\rightarrow\\{0,1\\}\\}$ 和 $\\{f:f:\\{0,1\\}^\*\rightarrow\\{0,1\\}^\*\\}$ 均不可数。