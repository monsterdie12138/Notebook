---
comments: true
---

<span style="font-family: 'Times New Roman';">

# Lec14

***

## 随机问题

**问题一：**

给定两个多项式：

* $F(x)=\prod\limits_{i=1}^d(x-a_i)$
* $G(x)=\sum\limits_{i=0}^db_ix^i$

这两个多项式是否一致？

最普通的思路是：将 $F(x)$ 展开，然后逐项比较系数，但是很慢。

另一个思路是：$F(x)$ 和 $G(x)$ 的 $d$ 个根一致，则 $F(x)$ 和 $G(x)$ 一致。从 $F(x)$ 可以很容易地得到 $d$ 个根，代入 $G(x)$ 即可。每代入一次需要 $O(d)$ 的时间，代入 $d$ 次需要 $O(d^2)$ 的时间。

如果使用随机：从 $1\sim 100d$ 随机采样一个 $r$，代到两个多项式中比较它们的结果，结果一致则认为多项式一致。这样只需要 $O(d)$ 的时间。

但这样可能会犯错：两个多项式不一致，但在 $r$ 上的取值恰好相等。令 $D(x)=F(x)-G(x)$，则这个事件发生的概率记为 $\text{Pr}(D(r)=0\mid D(x)\neq 0)$。由于 $D(x)$ 最多只有 $d$ 个根，因此

$$\text{Pr}(D(r)=0\mid D(x)\neq 0)\leqslant\frac{d}{100d}=\frac{1}{100}$$

**问题二：**

给定三个 $n\times n$ 的矩阵 $A$、$B$、$C$，是否有 $AB=C$？

最直接的方法是直接做矩阵乘法，但无法在 $O(n^2)$ 时间内解决，但随机可以。

随机采样一个长度为 $n$ 的 $01$ 向量 $\vec{r}=\\{r_1,r_2,\dots,r_n\\}$，分别计算 $AB\vec{r}=A\cdot(B\cdot\vec{r})$ 和 $C\vec{r}$，如果结果一致则认为 $AB=C$。

当 $Ab\neq C$ 且 $AB\vec{r}=C\vec{r}$ 时犯错。令 $D=AB-C$，分析 $\text{Pr}(D\vec{r}=0\mid D\neq 0)$。

由于 $D\neq0$，因此不妨设 $d_{11}\neq0$。如果希望 $D\vec{r}=0$，则至少要满足 $D$ 的第一行与 $\vec{r}$ 相乘结果为 $0$，因此

$$\text{Pr}(D\vec{r}=0\mid D\neq0)\leqslant\text{Pr}(d_{11}r_1+d_{12}r_2+\dots+d_{1n}r_n=0\mid d_{11}\neq 0)$$

如果 $r_2\sim r_n$ 都定好了，$r_1$ 等概率取 $0$ 和 $1$，且 $d_{11}\neq 0$，则 $r_1$ 要么为 $0$ 要么为 $1$ 才可以满足 $d_{11}r_1+d_{12}r_2+\dots+d_{1n}r_n=0$，且两种中最多只有一种可以满足，因此

$$\text{Pr}(d_{11}r_1+d_{12}r_2+\dots+d_{1n}r_n=0\mid d_{11}\neq 0)\leqslant\frac{1}{2}$$

如果认为最多有一半的概率犯错无法接受，可以多跑几次。例如独立地跑 $k$ 次，每一次都犯错的概率不超过 $\frac{1}{2^k}$，令 $k=\log n$，则每一次都犯错的概率不超过 $\frac{1}{n}$。

***

## 模型扩展

在原有的 NAND-TM program 的基础上新增指令 `?=RAND()`，即随即返回 $0$ 或 $1$，得到 **RNAND-TM program**。

在原有的 TM 的基础上，将状态转移函数 $\delta(p,a)=(q,b,D)$ 修改为

$$\delta(p,a)=\begin{cases}
    (q_1,b_1,D_1) \\\
    (q_2,b_2,D_2)
\end{cases}$$

等概率随机选择，得到 **probabilist TM**。

**BPP 类：**

布尔函数 $F:\\{0,1\\}^\*\to\\{0,1\\}$ 属于 BPP 类，当且仅当存在 RNAND-TM program $P$，对于任意输入 $x\in\\{0,1\\}^\*$，

* $P$ 在多项式步内停机（$a|x|^b$，$a$ 和 $b$ 为常数）
* $\text{Pr}(P(x)=F(x))\geqslant\frac{2}{3}$

!!! Note
    $\frac{2}{3}$ 可以替换成任意一个大于 $\frac{1}{2}$ 的数，都是等价的。

**Amplification Lemma:**

对于任意布尔函数 $F:\\{0,1\\}^\*\to\\{0,1\\}$，如果存在一个多项式时间的 RNAND-TM program $P$，对于任意 $x\in\\{0,1\\}^\*$，

$$\text{Pr}[P(x)=F(x)]\geqslant 1-\delta\quad\text{for some $\delta<\frac{1}{2}$}$$

那么存在另一个多项式时间的 RNAND-TM program $Q$，对于任意 $x\in\\{0,1\\}^*$，

$$\text{Pr}[Q(x)=F(x)]\geqslant 1-2^{-p(n)}$$

其中 $p(n)$ 是关于 $n$ 的多项式。

!!! Tip "Proof"

    构造 $Q$：

    ```py linenums="1"
    def Q(x):
        run P on x for 2k times
        return the majority
    ```

    $$
    \begin{align}
    \text{Pr}(Q\text{ fails}) & =\text{Pr}(P\text{ fails for at least $k$ times}) \\\
    & =\sum\limits_{i=k}^{2k}\text{Pr}(P\text{ fails for $i$ times}) \\\
    & =\sum\limits_{i=k}^{2k}C_{2k}^i\cdot\delta^i\cdot(1-\delta)^{2k-i} \\\
    & \leqslant\sum\limits_{i=1}^{2k}C_{2k}^i\cdot\delta^k(1-\delta)^k \\\
    & \leqslant\delta^k\cdot(1-\delta)^k\cdot2^{2k}\\\
    & =[4\delta(1-\delta)]^k
    \end{align}$$

    因为 $\delta<\frac{1}{2}$，因此 $2\delta(1-\delta)<1$，可以选择合适的 $k$ 让上式无限小。令 $k=\frac{-p(n)}{\log[4\delta(1-\delta)]}$，则 $\text{Pr}(Q\text{ fails})\leqslant 2^{-p(n)}$。

关于随机，还有另一个看待的角度。以 RNAND-TM program 为例，我们之前是输入一个 $x$，在运算过程中会出现一连串的 `?=RAND()`；我们也可以想象成有两个输入 $x$ 和 $r$，其中 $r$ 是随机生成的 $01$ 串，每到一个 `?=RNAD()`，就把 $r$ 中对应位置的字符赋给它。

也就是说，对于随机的 RNAND-TM program $P(x)$，其有一个对应的确定性的 NAND-TM program $Q(x,r)$，只不过 $r$ 是随机产生的。

**Lemma1:**

$F\in \text{BPP}$ 当且仅当存在 $G\in\text{P}$，满足对于任意的 $x\in\\{0,1\\}^*$，

$$\operatorname*{Pr}_{r\sim\\{0,1\\}^{a|x|^b}}[G(xr)=F(x)]\geqslant\frac{2}{3}$$

**Lemma2:**

$$\text{P}\subseteq\text{BPP}\subseteq\text{EXP}$$

**Lemma3:**

若 $F\in\text{BPP}$ 且 $|r|\leqslant\log|x|$，则 $F\in\text{P}$。

**Lemma4:**

$$\text{BPP}\subseteq\text{P}_{/poly}$$

!!! Tip "Proof"
    选择任意一个 $F\in\text{BPP}$，都存在一个不带随机的多项式时间的 NAND-TM program $Q$，满足

    $$\operatorname*{Pr}_{r\sim\\{0,1\\}^{a|x|^b}}[Q(xr)=F(x)]\geqslant\frac{2}{3}$$

    将 $\frac{2}{3}$ 放大到 $1-\frac{0.1}{2^n}$，对于所有长度为 $n$ 的 $x$，出错的概率之和

    $$\sum\limits_{|x|=n}\operatorname*{Pr}_{r\sim\\{0,1\\}^{a|x|^b}}[Q(xr)\neq F(x)]\leqslant\frac{0.1}{2^n}\cdot 2^n=0.1$$

    现在，考虑随机采样一个 $r$，对所有长度为 $n$ 的 $x$ 都成功的概率，反过来算为至少一个 $x$ 出错的概率，我们已知每个 $x$ 出错的概率之和，又有 $P(A\cup B\cup\dots)\leqslant P(A)+P(B)+\dots$，因此至少一个 $x$ 出错的概率不超过 $0.1$，

    $$\operatorname*{Pr}_{r\sim\\{0,1\\}^{a|x|^b}}[Q(xr)=F(x)\text{ for all $x$ with length $n$}]\geqslant 0.9$$

    概率为正，说明事件存在，存在这样一个 $r$ 满足上式。此时不需要随机，只需要使用并固定这个 $r$，就能去掉随机，并将 $Q$ 展开即可。

***

## Pseudorandom Generator

$G:\\{0,1\\}^l\to\\{0,1\\}^m$ 是一个 $(T,\epsilon)$-pseudorandom generator，当且仅当对于任意的电路 $C$，$C$ 有 $m$ 个输入、$1$ 个输出和最多 $T$ 个门，都有

$$|\operatorname\*{Pr}\_{s\sim\\{0,1\\}^l}[C(G(s))=1]-\operatorname\*{Pr}\_{r\sim\\{0,1\\}^m}[C(r)=1]|\leqslant\epsilon$$

直观上理解，就是用长度为 $l$ 的随机串模拟长度为 $m$ 的随机串，如果 $l<m$，则相当于在减小随机性。

最理想的情况：$m=2^l$，$\epsilon=2^{-l}$。此时为 **optimal pseudorandom generator**。