---
comments: true
---

<span style="font-family: 'Times New Roman';">

# Lec9

***

## Universal Turing Machine

存在 TM $U$，输入为 $M$、$x$，其中 $M$ 是任意 TM 的编码：

$$U(M,x)=\begin{cases}
    M(x) & \text{if $M$ is encoding of some TM} \\\
    M,x(\text{停机}) & \text{otherwise}
\end{cases}$$

只要找到一种合适的编码方式即可。

$M$ 的所有状态编码成 $0,1,2,\dots,|K|-1$，其中 $0$ 为初始状态。

$M$ 的所有符号编码成 $0,1,2,\dots,|\Sigma|-1$。

四个读写头操作 $\\{L,R,S,H\\}$ 分别编码成 $0,1,2,3$。

因此，最复杂的转移函数可以用五元组的形式描述。有了这些五元组（一共 $|K|\times|\Sigma|$ 个），就像有了一张表。给定输入 $x$，通过连续地查表，就能模拟 $M$ 的运行。

***

## Uncomputable Functions

**Theorem:**

存在布尔函数 $F^{\*}:\\{0,1\\}^{\*}\rightarrow\\{0,1\\}$，其不可以被任何 TM 计算（uncomputable）。

!!! Tip "Proof"
    **Proof 1:**

    可以给出非构造性证明：布尔函数不可数（证明省略），TM 可数（因为可编码），所以前者数量远多于后者，必然存在无法被 TM 计算的布尔函数。

    **Proof 2:**

    可以给出构造性证明，构造一个不可计算的布尔函数 $F^{\*}$：

    $$F^{\*}(x)=\begin{cases}
    0 & \text{if $x$ is encoding of some TM $M$ and $M(x)=1$} \\\
    1 & \text{$x$ is not valid encoding of any TM, or $x$ is encoding of some TM $M$ but $M(x)\neq 1$}
    \end{cases}$$

    对于任意 TM $M$：

    * 若 $M(M)=1$，则 $F^{\*}(M)=0$
    * 若 $M(M)\neq 1$，则 $F^{\*}(M)=1$

    如果有某个 $M$ 能计算 $F^{\*}$，那么当输入为 $M$ 自身编码时，$M(M)$ 应该等于 $F^{\*}(M)$。然而只会发生上面两种情况之一，都会导致矛盾，说明任意 TM 都无法计算 $F^{\*}$。

其中，Proof 2 运用了**对角化原理（Diagonalization）**。例如下表：

TM \ Encoding|$M_1$|$M_2$|$M_3$|$\cdots$
:---:|:---:|:---:|:---:|:---:
**$M_1$**|$1$|$\neq1$|$1$|$\cdots$
**$M_2$**|$\neq1$|$1$|$\neq1$|$\cdots$
**$M_3$**|$1$|$1$|$\neq1$|$\cdots$

其中，表格的每个元素表示将某个 TM 的编码作为另一个 TM 的输入后得到的结果。我们构造的布尔函数恰好与对角线上的元素相反，因此和每一行都不能做到完全相同，从而无法被任何 TM 计算。

***

## Halting Problem

给定一个 TM $M$ 和一个字符串 $x$，输出 $M$ 在 $x$ 上是否会停机：

$$\text{HALT}(M,x)=\begin{cases}
    1 & \text{if $M$ is a TM which halts on $x$} \\\
    0 & \text{otherwise}
\end{cases}$$

下面证明这个函数也是不可计算的。

!!! Tip "Proof"
    我们已经知道了前面构造的函数 $F^{\*}$ 是不可计算的。我们可以使用**反证法**：假设 $\text{HALT}$ 可计算，可以推出 $F^*$ 也可计算，从而推出矛盾。

    设 $\text{HALT}$ 对应的 TM 为 $M_{\text{HALT}}$。既然假设 $\text{HALT}$ 可计算，那么 $M_{\text{HALT}}$ 就是一个可以直接使用的黑盒。用以下伪代码构造 $F^*$ 对应的 TM $M_F$：

    ```py linenums="1"
    def M_F(x):
        compute M_HALT(x,x)
        if M_HALT(x,x) == 0:    # 说明 x 不是某个 TM 的编码，或者 x 在 x 上不停机，对应到 F* 的定义即返回 1
            return 1
        if M_HALT(x,x) == 1:    # 说明 x 在 x 上停机
            compute x(x)
            if x(x) == 1:       # 对应到 F* 的定义即返回 0
                return 0
            if x(x) != 1:       # 对应到 F* 的定义即返回 1
                return 1
    ```

    既然有对应的 TM $M_F$，说明 $F^{\*}$ 可计算，推出矛盾，因此 $\text{HALT}$ 不可计算。

***

## 归约 Reduction

我们可以从 halting problem 出发，证明更多不可计算的函数。

**例一：**

给定一个 TM $M$，输出 $M$ 在 $0$ 上是否会停机：

$$\text{HALTONZERO}(M)=\begin{cases}
    1 & \text{if $M$ is a TM which halts on $0$} \\\
    0 & \text{otherwise}
\end{cases}$$

下面证明其不可计算。

!!! Tip "Proof"
    同样地，使用反证法。假设 $\text{HALTONZERO}$ 可计算，可以推出 $\text{HALT}$ 也可计算，从而推出矛盾。

    设 $\text{HALTONZERO}$ 对应的 TM 为 $M_{\text{Z}}$。既然假设 $\text{HALTONZERO}$ 可计算，那么 $M_{\text{Z}}$ 就是一个可以直接使用的黑盒。用以下伪代码构造 $\text{HALT}$ 对应的 TM $M_\text{HALT}$：

    ```py linenums="1"
    def M_HALT(M,x):
        construct a new TM N    # 这个 TM 要满足 M 在 x 上停机当且仅当 N 在 0 上停机
        compute M_Z(N)
        return M_Z(N)

    def N(y):
        compute M(x)            # 与输入无关，注意这里的 M 和 x 是写死的
        return M(x)
    ```

    既然有对应的 TM $M_\text{HALT}$，说明 $\text{HALT}$ 可计算，推出矛盾，因此 $\text{HALTONZERO}$ 不可计算。

**例二：**

给定一个 TM $M$，输出 $M$ 是否满足 $M(x)\equiv 0$：

$$\text{ZEROFUNC}(M)=\begin{cases}
    1 & \text{if $M$ is a TM which computes the zero function} \\\
    0 & \text{otherwise}
\end{cases}$$

下面证明其不可计算。

!!! Tip "Proof"
    同样地，使用反证法。假设 $\text{ZEROFUNC}$ 可计算，可以推出 $\text{HALT}$ 也可计算，从而推出矛盾。

    设 $\text{ZEROFUNC}$ 对应的 TM 为 $M_{\text{Z}}$。既然假设 $\text{ZEROFUNC}$ 可计算，那么 $M_{\text{Z}}$ 就是一个可以直接使用的黑盒。用以下伪代码构造 $\text{HALT}$ 对应的 TM $M_\text{HALT}$：

    ```py linenums="1"
    def M_HALT(M,x):
        construct a new TM N    # 这个 TM 要满足 M 在 x 上停机当且仅当 N 是零函数
        compute M_Z(N)
        return M_Z(N)
    
    def N(y):
        compute M(x)            # 若 M 在 x 上停机，则对于任意输入 y 都返回 0，N 是零函数；若 M 在 x 上不停机，则 N 在任意输入上都不停机，N 不是零函数
        return 0
    ```

    既然有对应的 TM $M_\text{HALT}$，说明 $\text{HALT}$ 可计算，推出矛盾，因此 $\text{ZEROFUNC}$ 不可计算。

**归约（Reduction）：**

通过以上两个例子，我们发现证明的格式很类似。唯一不同的是 $N$ 的构造。

核心是把 $\text{HALT}$ 的输入转换成 $\text{HALTONZERO}$（或 $\text{ZEROFUNC}$）的输入，且满足 $\text{HALT}(M,x)=\text{HALTONZERO}(N)$（或$\text{HALT}(M,x)=\text{ZEROFUNC}(N)$）。

这个转换就是：从 $\text{HALT}$ 到 $\text{HALTONZERO}$（或 $\text{ZEROFUNC}$）的。

归约的本质是一个函数映射，设从函数 $F$ 到函数 $G$ 的归约为 $R$，则

$$R:\\{0,1\\}^{\*}\rightarrow\\{0,1\\}^{\*}$$

$$F(x)=G(R(x))$$

例如例二：

* $\text{HALT}$ 即为 $F$
* $\text{ZEROFUNC}$ 即为 $G$
* $M,x$ 即为 $x$
* $N$ 即为 $R(x)$

**Lemma:**

假设函数 $F$ 和 $G$，若存在一个从 $F$ 到 $G$ 的归约 $R$，且 $G$ 可计算，则 $F$ 也可计算。

```py linenums="1"
def M_F(x):
    compute R(x)
    compute M_G(R(x))
    return M_G(R(x))
```

实际上，我们通常使用其逆否命题：假设函数 $F$ 和 $G$，若存在一个从 $F$ 到 $G$ 的归约 $R$，且 $F$ 不可计算，则 $G$ 也不可计算。

因此，要证明某个函数不可计算，只要找到一个已知的不可计算的函数，再找到一个归约就行了。

!!! Note
    若存在一个从 $F$ 到 $G$ 的归约 $R$，则说明 $F$ 的计算难度不大于 $G$ 的计算难度。

**Rice's Theorem:**

给定一个 TM $M$，判断 $M$ 是否满足某个性质 $P$：

$$P(M)=\begin{cases}
    1 & \text{if $M$ is a TM which satisfies property $P$} \\\
    0 & \text{otherwise}
\end{cases}$$

如果 $P$ 是 **semantic and non-trivial** 的，那么上述判定问题不可计算。

!!! Success "Definition"
    **functionally equivalent:**

    两个 TM $M$ 和 $M'$ 是 functionally equivalent 的，当且仅当对于任意输入 $x$，$M(x)$ 和 $M'(x)$ 都有相同的输出。

    **semantic:**

    性质 $P$ 是 semantic 的，当且仅当对于任意两个 functionally equivalent 的 TM $M$ 和 $M'$，都有 $P(M)=P(M')$。（$P$ 只关注输入和输出，不关注 TM 本身内容）

    **trivial:**

    性质 $P$ 是 trivial 的，当且仅当 $P$ 是常数函数（对于所有 TM 都成立，或者对于所有 TM 都不成立）。

!!! Tip "Proof"
    使用**归约**。

    定义 TM $M_{\text{INF}}$，其接受一个输入 $x$，但无论输入是什么都不停机。

    假设 $P(M_{\text{INF}})=0$。（可以这么假设是因为：若 $P(M_{\text{INF}})=1$，那么只需要考虑 $P$ 的反性质就行了）

    由于 $P$ 是 non-trivial 的，因此存在 TM $M_{\text{YES}}$，使得 $P(M_{\text{YES}})=1$。

    现在把 $\text{HALT}$ 归约到 $P$，即将输入 $(M,x)$ 转换为 $N$。$N$ 的构造方式如下：

    ```py linenums="1"
    def N(y):
        compute M(x)
        compute M_YES(y)
        return M_YES(y)
    ```

    那么此时是否有 $\text{HALT}(M,x)=P(N)$？

    若 $\text{HALT}(M,x)=0$，说明 $M$ 在 $x$ 上不停机，那么 $N$ 也不会停机，由于 $P$ 是 semantic 的，因此 $P(N)=P(M_{\text{INF}})=0$。

    若 $\text{HALT}(M,x)=1$，说明 $M$ 在 $x$ 上停机，那么 $N$ 会输出 $M_{\text{YES}}(y)$ 的结果，由于 $P$ 是 semantic 的，因此 $P(N)=P(M_{\text{YES}})=1$。

    综上所述，存在一个从 $\text{HALT}$ 到 $P$ 的归约，因此由于 $\text{HALT}$ 不可计算，推出 $P$ 也不可计算。