---
comments: true
---

<span style="font-family: 'Times New Roman';">

# Lec10

***

## Recursion Theorem

### 打印自身的程序

能否写一个程序，把自己的代码打印出来？

```py linenums="1"
def f():
    print("def f():")
    print("print("def f():")")
    print("print("print("def f():")")")
    ...
```

看上去是反直觉的，因为会陷入逻辑循环，但是实际上是可以做到的。

构造一个 TM $M$，用 $\langle M\rangle$ 表示其编码，我们的目标是让 $M$ 在纸带上输出 $\langle M\rangle$。

最简单的想法是：将 $M$ 拆成 $A$ 和 $B$，$A$ 先将 $\langle B\rangle$ 写到纸带上；$B$ 再将 $\langle A\rangle$ 写到纸带上，然后互换 $\langle A\rangle$ 和 $\langle B\rangle$。最后得到的 $\langle A\rangle\langle B\rangle$ 即为 $\langle M\rangle$。

这样定义之后依然有问题： $A$ 需要知道 $\langle B\rangle$， $B$ 需要知道 $\langle A\rangle$，形成死锁。

我们可以先定义函数 $q:\\{0,1\\}^\*\to\\{0,1\\}^\*$，令 $q(w)=\langle M_w\rangle$，即函数值是一台 TM 的编码。

然后定义 $M_w$：

```py linenums="1"
def Mw(x):
    write w to the tape     # 不管输入 x 是什么，只将 w 写到纸带上
```

显然，$q$ 是可计算的，因此可以用 $q$ 来构造 $B$：

```py linenums="1"
def B(w):
    compute q(w)
    write q(w) to the tape and swap it with w
```

这样之后，原本纸带上为 $w$，经过 $B$ 之后，纸带上就变成了 $q(w)w$。

这个时候 $B$ 是 well-defined 的，不依赖 $A$。而 $A$ 的定义为：

```py linenums="1"
def A(x)
    erase the input
    write <B> to the tape
```

$A$ 的定义是依赖于 $B$ 的，可以先定义 $B$ 再定义 $A$，逻辑上没有问题。

综上，整个过程为：

先跑 $A$，纸带上变成 $\langle B\rangle$；

再跑 $B$，纸带上变成 $q(\langle B\rangle)\langle B\rangle$。其中，$q(\langle B\rangle)$ 是一台 TM 的编码，这个 TM 做的事情就是输出 $\langle B\rangle$，也就是 $A$ 做的事情。因此，$q(\langle B\rangle)=\langle A\rangle$。

再扩充一点：对于任意一台 TM $M$，其都可以先获得自己的编码 $\langle M\rangle$，然后再基于此编码做计算：

```py linenums="1"
def M(x):
    obtain <M>
    compute f(<M>, x)
```

之前讲的便是 $f$ 为 `print` 的特例。

### Recursion Theorem

对于任意的 TM $T$，若其有两个输入 $\langle M\rangle$（TM 编码）和 $x$（字符串），则存在 TM $R$，满足

$$\forall x\in\\{0,1\\}^{\*},R(x)=T(\langle R\rangle, x)$$
也就是上面内容的更规范表述。

!!! Tip "Proof"
    证明思路和之前打印自身的函数类似。有一个 $T$，如何构造 $R$？

    将 $R$ 拆成 $A$、$B$、$T$。

    $A$ 的作用是将 $\langle B\rangle$ 和 $\langle T\rangle$ 写到纸带上。因此给定输入 $x$，经过 $A$ 之后，纸带上变成 $x\langle B\rangle\langle T\rangle$。

    $B$ 的作用是将 $\langle A\rangle$ 写到纸带上并重新排序。因此经过 $B$ 之后，纸带上变成 $\langle A\rangle\langle B\rangle\langle T\rangle x$。

    最后跑 $T$，其对应的两部分输入即为 $\langle R\rangle=\langle A\rangle\langle B\rangle\langle T\rangle$ 和 $x$。因此，$R(x)=T(\langle R\rangle, x)$。

    关于 $A$ 和 $B$ 死锁的问题，同样可以参考之前利用函数 $q$ 来解决，不再赘述。

### Recursion Theorem 的应用

**应用一：证明停机问题不可计算**

Recursion Theorem 可以很方便地证明停机问题不可计算。

!!! Tip "Proof"
    反证法：假设 $\text{HALT}$ 可计算，那么可以构造TM $M$：

    ```py linenums="1"
    def M(w):
        obtain <M>
        compute HALT(<M>, w)
        if HALT(<M>, w) == 1:   # 若 HALT 输出为 1，说明 M 在输入 w 时会停机，那么反而让 M 不停机，矛盾
            loop forever
        else:                   # 若 HALT 输出为 0，说明 M 在输入 w 时不会停机，那么反而让 M 停机，矛盾
            halt
    ```

**应用二：证明判断代码是否最简不可计算**

定义一台 TM $M$ 为**最简的（minimal）**，当且仅当对于任何与其 functionally equivalent 的 TM $M'$，都有 $|\langle M'\rangle|\geqslant|\langle M\rangle|$。

Recursion Theorem 也可以用来证明“判断代码是否最简”是不可计算的，即

$$\text{MINI}(\langle M\rangle)=\begin{cases}
    1 & \text{if $M$ is minimal} \\\
    0 & \text{otherwise}
\end{cases}$$

不可计算。

!!! Tip "Proof"
    反证法：假设 $\text{MINI}$ 可计算，那么可以构造 TM $M$：

    ```py linenums="1"
    def M(x):
        obtain <M>
        for s in {0,1}* in increasing order of length:
            if MINI(s) == 1 and |s| > |<M>|:
                compute s(x)
                return s(x)
    ```

    也就是说，我们先找到能对应到一台 TM 编码，且长度最短的字符串 $s$，然后返回 $s(x)$，那么 $M$ 和 $s$ 对应的 TM 是 functionally equivalent 的，但 $|s|>|\langle M\rangle|$，与 $s$ 是最简的（$\text{MINI(s)==1}$）矛盾。

**应用三：证明 fixed point theorem**

fixed point theorem 定义：

对于任意一个可计算的函数 $t:\\{0,1\\}^{\*}\to\\{0,1\\}^{\*}$，其一定存在一个不动点，这个不动点是一台 TM $F$，满足 $t(\langle F\rangle)=\langle M\rangle$，其中 $M$ 与 $F$ functionally equivalent。

!!! Tip "Proof"
    构造 $F$：

    ```py linenums="1"
    def F(w):
        obtain <F>
        compute t(<F>)      # 设 <M>=t(<F>)
        simulate M on w
    ```

***

## Godel's Incompleteness Theorem

### Proof System

一个 statement 可以看作一个字符串 $x$，例如 “HALT is uncomputable”。

如果这个 statement 是正确的，那么需要一个 proof，也可以看作一个字符串 $t$。

proof system 可以如下定义：

假设 $\mathcal{T}\subseteq\\{0,1\\}^{\*}$ 是一个由 true statements 组成的集合，它的 proof system 是一个 TM $V$，满足：

* **effectiveness**：对于 $\forall x,t\in\\{0,1\\}^{\*}$，$V(x,t)$ 总能停机，且输出只有 $0$ 或 $1$
* **soundness**：对于 $\forall x\notin\mathcal{T}$（false statement），都有 $\forall t\in\\{0,1\\}^{\*}$，$V(x,t)=0$
* **completeness**：对于 $\forall x\in\mathcal{T}$（true statement），都存在 $t\in\\{0,1\\}^{\*}$，使得 $V(x,t)=1$
### Godel's Incompleteness Theorem

$\exists\mathcal{T}$，其没有任何 proof system。（有无法判断真假的 statement）

!!! Tip "Proof"
    构造一个 $\mathcal{T}$，其是如下形式的 true statements 的集合：

    * "a TM $M$ halts on $0$"
    * "a TM $M$ does not halt on $0$"

    反证：若 $\mathcal{T}$ 有 proof system $V$，那么我们可以推出 $\text{HALTONZERO}$ 是可计算的，矛盾。

    如何推出？可以将 $\text{HALTONZERO}$ 的计算过程（输入为 $M$，输出为 $M$ 是否在 $0$ 上停机）看作两个并行的子过程：

    * 子过程一：直接跑 $M(0)$
    * 子过程二：令 $x=$ "M does not halt on 0"，寻找能够证明这个 statement 的 proof $t$：
        ```py linenums="1"
        for t in {0, 1}* in increasing length:
            compute V(x, t)
            if V(x, t) == 1:
                return
        ```

    我们发现：这两个子过程必然会有一个停机，一个不停机。若 $M$ 在 $0$ 上停机，那么子过程一会停机；若 $M$ 在 $0$ 上不停机，那么子过程二会停机。也就是说，这个程序能够判断 $M$ 是否在 $0$ 上停机，从而说明 $\text{HALTONZERO}$ 是可计算的，矛盾。

    !!! Note
        这里的并行可以通过交替执行两个子过程（一先跑一行代码，二再一行代码之类）来实现。

### Quantified Integer Statement

不止上面一个 $\mathcal{T}$ 没有 proof system，实际上更常见的数学相关的 $\mathcal{T}$ 也可能没有 proof system。

考虑 quantified integer statement，这一类 statement 的组成包括整数、整数变量、数值运算符（$+,-,\times,\div,=$）、逻辑运算符（$\land,\lor,\neg$）、量词（$\forall,\exists$）。

!!! Example
    Fermat's Last Theorem:

    $$\neg\exists a\exists b\exists c\exists n,(a>0)\land(b>0)\land(c>0)\land(n>2)\land(a^n+b^n=c^n)$$

    Twin Prime Conjecture:

    $$\forall n\exists x\exists y,(n>2)\land(p>n)\land(x>1)\land(y>1)\land(xy\neq p)\land(xy\neq p+2)$$

判断某个 quantified integer statement 是否为真，是不可计算的，即

$$\text{EVAL}(\Phi)=\begin{cases}
    1 & \text{if statement $\Phi$ is true} \\\
    0 & \text{otherwise}
\end{cases}$$

!!! Tip "Proof"
    尝试将 $\text{HALTONZERO}$ 归约到 $\text{EVAL}$。

    一台 TM $M$ 的 snapshot 由三部分组成：状态（$q$）、纸带内容（$a_1a_2\dots a_n$）、读写头位置（$k$），可以记为 $(q,a_1a_2\dots a_{k-1},a_k\dots a_n)$，称为一个 **configuration**。

    $M$ 的计算就是一连串 configuration 组成的序列，称为 **computation history**。

    $M$ 在 $0$ 上停机，当且仅当存在一个字符串 $s$，能描述 $M$ 输入 $0$ 时的 computation history。这个条件可以被转换成 “某个$\Phi_M$ 为 true”。（$01$ 编码的不同解释？）

    证明较复杂，过程省略。

类似地，让 $\mathcal{T}$ 为所有 true quantified integer statement 组成的集合，可以证明 $\mathcal{T}$ 没有任何 proof system。

证明与上面类似，通过反证 $\text{HALTONZERO}$ 可计算，过程省略。