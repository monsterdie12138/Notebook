---
comments: true
---

<span style="font-family: 'Times New Roman';">

# Lec12

***

## 多项式时间归约

我们之前讲过**归约**：

给定两个布尔函数 $F$ 和 $G$，$F\to G$ 的归约是一个可计算的函数 $R:\\{0,1\\}^{\*}\to\\{0,1\\}^{\*}$，满足对于任意 $F$ 的输入 $x\in\\{0,1\\}^{\*}$，可以转换成 $G$ 的输入 $R(x)$，且满足 $F(x)=G(R(x))$，说明 $G$ 的计算难度不低于 $F$。

现在，如果我们进一步限制归约 $R$ 在多项式时间内可计算，那么我们称之为**多项式时间归约（polynomial-time reduction）**，记为 $F\leqslant_p G$。

**Lemma1:**

若 $F\leqslant_p G$ 且 $G\in P$，则 $F\in P$。

**Lemma2:**

若 $F\leqslant_p G$ 且 $G\leqslant_p H$，则 $F\leqslant_p H$。

### Common Problems Still Not in P

以下的问题为一些常见问题，它们还没有找到在多项式时间内计算的方法（暂时不属于 $\text{P}$）。

**3SAT Problem:**

给定一个布尔公式 $\phi$，例如：

$$\phi=(x_0\lor\overline{x_1}\lor x_2)\land(x_1\lor x_2\lor\overline{x_3})\land(\overline{x_0}\lor\overline{x_1}\lor x_3)$$

其中：

* $x_0\sim x_3$ 为 variables
* $x_0\sim x_3,\overline{x_0}\sim\overline{x_3}$ 为 literals
* 每个括号中有三个 literals，称为 clause

我们称 $\phi$ 可满足，当且仅当存在一种变量赋值方式，使得 $\phi$ 为真。因此可定义函数：

$$\text{3SAT}(\phi)=\begin{cases}
    1 & \text{if satisfiable}\\\
    0 & \text{otherwise}
\end{cases}$$

**01EQ Problem:**

给定线性方程组。例如：

$$x_0+x_1+x_2=0$$

$$x_0+x_1=1$$

$$x_1+x_2=2$$

每个等式的右边都是非负整数，变量的系数为 $0$ 或 $1$。判断这样一个线性方程组是否有 $01$ 解（每个 $x$ 只能取 $0$ 或 $1$）。

**Subset Sum Problem:**

给定 $n$ 个正整数 $a_1\sim a_n$，以及一个目标整数 $t$，判断能否从 $a_1\sim a_n$ 中选出一些数，使得它们的和等于 $t$。

### $\text{3SAT}\leqslant_p \text{01EQ}$

过程有三步：

* 构造归约 $R$
* 证明 $R$ 在多项式时间内可计算
* 证明归约后输出一致

**第一步：**

怎样的 $R$ 可以将 3SAT 的输入转换成 01EQ 的输入？

例如，3SAT 的某个输入为

$$(x_0\lor x_1\lor x_2)\land(x_1\lor \overline{x_2}\lor x_3)$$

如果上面的布尔式子要为真，则每个 clause 中至少有一个 literal 为真。

$$x_0\lor x_1\lor x_2\to x_0+x_1+x_2\geqslant 1$$

$$x_1\lor \overline{x_2}\lor x_3\to x_1+(1-x_2)+x_3\geqslant 1$$

这与 ）01EQ 的输入形式还有一定差别。首先，系数只能为 $0$ 或 $1$，因此，令

$$x_2'=1-x_2$$

则上式变为

$$x_1+x_2'+x_3\geqslant 1$$

且 $x_2$ 和 $x_2'$ 不能同时为 $1$，因此新增等式

$$x_2+x_2'=1$$

接着，01EQ 要求输入均为等式，因此可以增加**松弛变量**，将不等式转换为等式：

$$x_0+x_1+x_2\geqslant 1\to x_0+x_1+x_2+y_1+z_1=3$$

左右两边实际上等价。

因此，3SAT 的输入最终转换为 01EQ 的输入：

$$x_0+x_1+x_2+y_1+z_1=3$$

$$x_1+x_2'+x_3+y_2+z_2=3$$

$$x_2+x_2'=1$$

我们进行更严谨的泛化：

令 $\phi$ 为 3CNF 公式，有 $n$ 个 variables $x_1\sim x_n$，有 $m$ 个 clauses $C_1\sim C_m$。

```py linenums="1"
def R(phi)
    让 x1~xn, x1'~xn' 对应每个 literal
    松弛变量 y1~ym, z1~zm
    for i in range(n):
        构造等式 xi + xi' = 1
    for j in range(m):
        设 Cj 为 (w1, w2, w3)
        构造等式 w1 + w2 + w3 + yj + zj = 3
```

**第二步：**

有两个循环，一共循环 $n+m$ 遍，循环内部为 $O(1)$，因此总的时间复杂度为 $O(n+m)$，也就是说 $R$ 在多项式时间内可计算。

**第三步：**

求证：$\phi$ 可满足当且仅当 $R(\phi)$ 有 $01$ 解。

左推右：

若存在可满足 $\phi$ 的一个变量赋值方式，则从它出发构造 $01$ 解：

$$\begin{cases}
  x_i=1,x_i'=0 & \text{if $x_i$ is true} \\\
  x_i=0,x_i'=1 & \text{if $x_i$ is false}
\end{cases}$$

显然，这些变量满足所有

$$x_i+x_i'=1$$

同时，对于每个 $w_1+w_2+w_3+y_j+z_j=3$，由于 $\phi$ 可满足，因此 $w_1,w_2,w_3$ 中至少有一个为 $1$，加起来最多为 $3$，因此可以找到合适的 $y_j,z_j$ 使得该等式成立。

右推左：

若 $R(\phi)$ 有 $01$ 解，由于 $x_i+x_i'=1$，因此

$$\begin{cases}
  x_i=\text{true} & \text{if } x_i=1 \\\
  x_i=\text{false} & \text{if } x_i=0
\end{cases}$$

再看 $\phi$ 的每个括号 $C_j=(w_1\lor w_2 \lor w_3)$，由于已知 $w_1+w_2+w_3+y_j+z_j=3$，且 $y_j+z_j\leqslant 2$，因此 $w_1+w_2+w_3\geqslant 1$，说明在 $C_j$ 中至少有一个 literal 为真，因此 $\phi$ 可满足。

### $\text{01EQ}\leqslant_p \text{Subset Sum}$

例如：

$$x_0+x_1+x_2=3$$

$$x_0+x_1=1$$

$$x_1+x_2=2$$

怎样将如上 01EQ 的输入转换成 Subset Sum 的输入？

将上面的三个等式用矩阵表示：

$$\begin{bmatrix}
  1 & 1 & 1 \\\
  1 & 1 & 0 \\\
  0 & 1 & 1
\end{bmatrix}
\begin{bmatrix}
  x_0 \\\
  x_1 \\\
  x_2
\end{bmatrix}=
\begin{bmatrix}
  3 \\\
  1 \\\
  2
\end{bmatrix}$$

$$\begin{bmatrix}
  1 \\\
  1 \\\
  0
\end{bmatrix}x_0+
\begin{bmatrix}
  1 \\\
  1 \\\
  1
\end{bmatrix}x_1+
\begin{bmatrix}
  1 \\\
  0 \\\
  1
\end{bmatrix}x_2=
\begin{bmatrix}
  3 \\\
  1 \\\
  2
\end{bmatrix}$$

其中，$x_i\in\\{0,1\\}$。这样来看，就相当于这三个向量是选还是不选，已经初具 Subset Sum 的形式了。

然后，我们要将向量转换为数。设有 $n$ 个变量，为了保证不进位，我们设每个向量为 $2n$ 进制编码。例如，上面的例子中为 $6$ 进制编码，向量第一个元素为最低位，最后一个元素为最高位：

$$7x_0+43x_1+37x_2=81$$

无法从 $7,43,37$ 中选出一些数，使得它们的和为 $81$。这可以解释，因为原本的线性方程组无解。

***

## P、NP and NP-complete

上述三个问题暂时都不能在多项式时间内计算，但都可以在多项式时间内验证。

**可验证性：**

对于一个布尔函数 $F:\\{0,1\\}^{\*}\rightarrow\\{0,1\\}$，如果其能在多项式时间内验证，当且仅当存在一台 TM $V$，作为证明系统，其满足：

* 运行时间为多项式时间
* 对于任意输入 $x\in\\{0,1\\}^{\*}$，$F(x)=1$ 当且仅当存在证据/赋值 $t\in\\{0,1\\}^{\*}$，使得  
  
  * $V(x,t)=1$
  * $|t|<poly(|x|)$（其实意思是不要太长）

例如，对于 3SAT，$F=\text{3SAT}$，$V$ 如下：

```py linenums="1"
def V(x, t):
    if x is not 3CNF formula or t is not an assignment of variables in x:
       return 0
    if x evaluates to true:
        return 1
    else:
        return 0
```

从上面的伪代码可以知道， $V$ 在多项式时间内运行。

**$\text{NP}$:**

$\text{NP}$ 是所有多项式时间内可验证的布尔函数的集合。

**Lemma1:**

$$\text{P}\subseteq \text{NP}\subseteq \text{EXP}$$

!!! Tip "Proof"
    **证明：$\text{P}\subseteq \text{NP}$：**

    若 $F\in\text{P}$，则存在一台 TM $M$，在多项式时间内计算 $F$。我们构造 TM $V$，其与 $t$ 无关，直接计算 $M(x)$ 并返回，且这个 $V$ 满足上述所有条件。

    **证明：$\text{NP}\subseteq \text{EXP}$：**

    若 $F\in\text{NP}$，则存在一台 TM $V$，在多项式时间内验证 $F$。我们构造 TM $M$：

    ```py
    def M(x):
        for all string t with |t|<= |x|^a: # 枚举
            run V(x, t)
            if V(x, t) == 1:
                return 1
        return 0
    ```

**Theorem1:**

$\text{3SAT}\in\text{P}$ 当且仅当 $\text{P}=\text{NP}$。

**NP-complete:**

函数 $G:\\{0,1\\}^{\*}\to\\{0,1\\}^{\*}$ 是 NP-complete，当且仅当：

* $G\in\text{NP}$
* 对任意 $F\in\text{NP}$，都有 $F\leqslant_p G$。

!!! Note
    如果只满足第二个条件，则称 $G$ 为 NP-hard。

**Lemma2:**

若 $G$ 是 NP-complete，且 $G\in\text{P}$，则 $\text{P}=\text{NP}$。

**Cook-Levin Theorem:**

$\text{3SAT}$ 是 NP-complete。