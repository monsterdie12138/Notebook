---
comments: true
---

<span style="font-family: 'Times New Roman';">

# Lec11

***

## 运行时间

之前研究的都是不可计算的函数，现在研究可计算的函数，我们关心它们的时间复杂度。

### 运行时间

定义 TM 的运行时间是一个与输入长度相关的函数：

$$T:N\rightarrow N$$

我们称 TM $M$ 的运行时间为 $T(n)$，当且仅当对于足够大的 $n$（大于某个常数），对于任意长度为 $n$ 的输入，$M$ 最多 $T(n)$ 步就会停止。

!!! Success "Definition"
    我们研究的 $T$ 一般是 **nice function**，即满足：

    * $T(n)\geqslant n$（至少要读一遍输入）
    * 不减（输入越长，则耗时越长）
    * $T$ 本身可计算（耗时就是 $T(n)$）

定义 $\text{TIME}_{\text{TM}}(T(n))$ 为一系列布尔函数的集合，这些布尔函数可计算，且对应 TM 都有运行时间为 $T(n)$。

有了上述定义，就可以定义所有多项式运行时间的函数集合：

$$\text{P}=\bigcup\limits_{c=1,2,3\dots}\text{TIME}_{\text{TM}}(n^c)$$

所有指数运算时间的函数集合：

$$\text{EXP}=\bigcup\limits_{c=1,2,3\dots}\text{TIME}_{\text{TM}}(2^{n^c})$$

有

$$\text{P}\varsubsetneq\text{EXP}$$

我们知道 NAND-RAM 程序与 TM 等价。因此，上面的定义可以基于 NAND-RAM 程序重新表述。

我们称 NAND-RAM 程序的运行时间为 $T(n)$，当且仅当对于足够大的 $n$（大于某个常数），对于任意长度为 $n$ 的输入，程序最多运行 $T(n)$ 行后就会停止。

因此也有 $\text{TIME}_{\text{RAM}}(T(n))$ 的定义，具体不表。

我们可以证明：

$$\text{TIME}\_{\text{TM}}(T(n))\subseteq\text{TIME}\_{\text{RAM}}(10T(n))\subseteq\text{TIME}\_{\text{TM}}(T(n)^4)$$

证明不表。可以看出， TM 与 NAND-RAM 程序的运行时间在多项式因子内是等价的。

有了这个理论之后，上述的 $\text{P}$ 和 $\text{EXP}$ 也可以用 NAND-RAM 程序定义：

$$\text{P}=\bigcup\limits_{c=1,2,3\dots}\text{TIME}_{\text{RAM}}(n^c)$$

$$\text{EXP}=\bigcup\limits_{c=1,2,3\dots}\text{TIME}_{\text{RAM}}(2^{n^c})$$

这两个集合的定义是 robust 的，不依赖于具体的计算模型。

### Time Hierarchy Theorem

首先介绍一个工具。

我们之前有介绍过 universal TM，实际就是一个能够模拟任意 TM 的 TM：

$$U(\langle M \rangle,x)=M(x)$$

类似地，存在universal NAND-RAM 程序 $U$，使得对于任意 NAND-RAM 程序 $P$ 和输入 $x$，都有：

$$U(\langle P \rangle,x)=P(x)$$

如果程序 $P$ 的运行时间是 $T$，在给定输入后的运行时间是 $T(|x|)$；再考虑模拟的其他开销，$U$ 在给定输入后的运行时间是 $a|P|^bT(|x|)$，其中 $a,b$ 是常数，证明不表。

有了这个工具，就可以证明 Time Hierarchy Theorem：

对于任意的 nice function $T:N\rightarrow N$，都存在函数 $F:\\{0,1\\}^*\rightarrow\\{0,1\\}$，满足：

$$F\in\text{TIME}\_{\text{RAM}}(T(n)\log n)\setminus\text{TIME}\_{\text{RAM}}(T(n))$$

!!! Tip "Proof"
    固定 $T$，构造 $F$ 为

    $$\text{HALT}_T(\langle P\rangle,x)=\begin{cases}
        1 & \text{$P$ is NAND-RAM program and $|P|\leqslant\log\log|x|$ and $P$ halts on $x$ within $100T(|P|+|x|)$ steps} \\\
        0 & \text{otherwise}
    \end{cases}$$

    上述函数最主要的特征是限制了多少步内停机，称为 **bounded halting problem**。

    我们要证明两件事：

    1. $\text{HALT}\_T\in\text{TIME}\_{\text{RAM}}(T(n)\log n)$
    2. $\text{HALT}\_T\notin\text{TIME}\_{\text{RAM}}(T(n))$

    **Proof of 1:**

    用如下程序实现 $\text{HALT}_T$：

    ```py linenums="1"
    def HALT_T(P, x):
        if |P| > loglog|x|:
            return 0
        compute T0 = T(|P| + |x|)
        simulate P on x for 100 * T0 steps
        if P halts:
            return 1
        else:
            return 0
    ```

    我们需要知道这个程序的运行时间。

    * 第一个 `if` 判断：耗时 $O(|P|)$，因为想知道程序的长度，需要读一遍程序。
    * `compute` 部分： 耗时 $T(|P|+|x|)$，根据 nice function 的定义即可得到。
    * `simulate` 部分：这里就用到了 universal NAND-RAM 程序这一工具，根据之前的叙述可知：耗时 $a|P|^b\cdot100T_0$

    因此，程序的总运行时间为三者相加，得到 $O(|P|^bT_0)$。由于已知：

    $$|P|\leqslant\log\log|x|\leqslant\log\log(|P|+|x|)$$

    因此：

    $$\begin{align}
    O(|P|^bT_0) & \leqslant O(T_0[\log\log(|P|+|x|)]^b) \\\
    & =O(T(|P|+|x|)\cdot[\log\log(|P|+|x|)]^b) \\\
    & \leqslant O(T(|P|+|x|)\log(|P|+|x|))
    \end{align}$$

    因此证得：$\text{HALT}\_T\in\text{TIME}\_{\text{RAM}}(T(n)\log n)$。

    **Proof of 2:**

    使用反证法：假设 $\text{HALT}\_T\in\text{TIME}\_{\text{RAM}}(T(n))$ 成立，则说明 $\text{HALT}_T$ 可以在 $T(n)$ 时间内计算。

    定义如下程序：

    ```py linenums="1"
    def Q*(z):
        if z is not of form P1^m    # z 要求的形式为，前面为某个 NAND-RAM 程序的编码，且 |P| < 0.1loglogm，后面跟着 m 个 1
            return 0
        b = HALT_T(P, z)
        if b == 1:  # P 在 z 上在规定步数内会停机
            loop forever
        else:
            halt
    ```

    $$Q^{\*}(P1^m)=\begin{cases}
        \text{loop} & \text{if $|P|<0.1\log\log m$ and $P$ halts on $P1^m$ within $100T(|P|+|P|+m)$ steps} \\\
        \text{halt} & \text{otherwise}
    \end{cases}$$

    令 $P=Q^{\*}$，$m=2^{2^{100|Q^{\*}|}}$。
    
    $Q^{\*}(P1^m)$ 不可能一直循环。因为如果这样的话，说明 $P$ 在 $P1^m$ 上会停机，即 $Q^{\*}$ 在 $P1^m$ 上会停机，与假设矛盾。

    $Q^{\*}(P1^m)$ 也不可能停机。如果停机，我们来看一下程序运行时间。第一个 `if` 判断耗时 $|P|+m$；`HALT_T` 部分耗时 $T(|P|+|P|+m)$，这是我们反证的假设得到的；第二个 `if` 判断耗时 $O(1)$。因此总运行时间最多为 $2T(2|P|+m)$（对第一个耗时进行放缩，同时利用了 $T$ 的 nice function 的性质）。但是这样，我们发现满足条件：$P$ 在 $P1^m$ 上在 $100T(|P|+|P|+m)$ 步内停机，因此应该要一直循环，与假设矛盾。

    综上，假设不成立，证得 $\text{HALT}\_T\notin\text{TIME}\_{\text{RAM}}(T(n))$。

***

## 电路规模

除了时间资源，在研究 finite function 时，我们还讨论过需要多少个与非门（NAND-CIRC program 需要多少行）。

而刚刚我们在研究的是，对于 infinite function，对应的 NAND-RAM program 需要多少步。

现在我们要将二者联系起来。

对于任意 infinite function：

$$F:\\{0,1\\}^*\rightarrow\\{0,1\\}$$

如果我们限制输入长度为 $n$，则得到

$$F_{\uparrow n}:\\{0,1\\}^n\rightarrow\\{0,1\\}$$

对于任意 $x\in\\{0,1\\}^n$，都有 $F_{\uparrow n}(x)=F(x)$。

我们称：$F\_{\uparrow n}\in\text{SIZE}\_n(T(n))$，如果计算 $F_{\uparrow n}$ 需要 $T(n)$ 个门。

我们称：$F\in\text{SIZE}(T(n))$，如果对于任意的 $n$，都有 $F\_{\uparrow n}\in\text{SIZE}\_n(T(n))$。

现在来比较 $F\in\text{SIZE}(T(n))$ 和 $F\in\text{TIME}(T(n))$ 区别。

* $F\in\text{SIZE}(T(n))$：
  $\forall n$，$\exists$ NAND-CIRC program，$\forall x\in\\{0,1\\}^n$，$F(x)$ 可以在 $T(n)$ 行内被计算出来。
* $F\in\text{TIME}(T(n))$：
  $\exists$ NAND-TM program，$\forall n$，$\forall x\in\\{0,1\\}^n$，$F(x)$ 可以在 $T(n)$ 行内被计算出来。

如果暂时不考虑 NAND-CIRC program 与 NAND-TM program 之间的差别，看作一样，则有

$$\text{TIME}(T(n))\subseteq\text{SIZE}(T(n))$$

### Theorem

对于任意 nice function $T:N\rightarrow N$，都有

$$\text{TIME}(T(n))\subseteq\text{SIZE}(T(n)^3)$$

!!! Tip "Proof"
    NAND-TM program：

    ```py linenums="1"
    ? = NAND(?, ?)
    ? = NAND(?, ?)
    ...
    ? = NAND(?, ?)
    MODANDJUMP(?, ?)    # 更新数组下标（对应移动读写头）并循环
    ```

    NAND-CIRC program：

    ```py linenums="1"
    ? = NAND(?, ?)
    ? = NAND(?, ?)
    ...
    ? = NAND(?, ?)
    ```

    若 $F\in\text{TIME}(T(n))$，则存在如上形式的 NAND-TM program，$\forall n$，$\forall x\in\\{0,1\\}^n$，$F(x)$ 可以在 $T(n)$ 行内被计算出来。

    如果把 $n$ 定下来，$T(n)$ 也就确定了，NAND-TM program 一共要跑多少行也就确定了，也就知道了会进行多少次循环，从而进行展开，也就变成了一个 NAND-CIRC program，从而说明 $F\in\text{SIZE}(T(n))$？

    这样做有一个问题：NAND-TM program 中有数组变量，每一次循环中的数组变量是多少，是和输入的内容相关的，并不是一个常数。

    怎样才能与输入内容无关？只有 `MODANDJUMP` 对 `i` 的变动与输入内容无关才可以。

    事实上，对于任意的 NAND-TM program，我们都可以构造一个等价的 NAND-TM program，使得 `MODANDJUMP` 对 `i` 的变动与输入内容，只和输入长度有关。

    `MODANDJUMP` 对 `i` 的变动，实际上就是读写头的移动。那么如果每一次都从纸带最左边开始，一直扫到最右边，再扫回来，就和输入内容无关了。在扫的过程当中修改内容。（细节不表）

    但是这样做有代价。总运行时间为 $T(n)$，因此纸带最长为 $T(n)$，本来走一步只需要 $1$ 的时间，现在来回跑需要 $2T(n)$ 的时间。因此，展开后对应的 NAND-CIRC program 会有 $T(n)^2$ 步。

    !!! Warning
        这里不是很理解，因此主要记录了听到的内容。结论和证明似乎不一致。

这个证明实际上是在说：给定一台 TM $M$，一个整数 $t$（表示跑多少步），一个整数 $n$（表示输入长度），一定存在一个电路 $C$，$C$ 有 $n$ 个输入，一个输出，$O(t^2)$ 个门。对于任意输入 $x$，都有 

$$C(x)=\begin{cases}
    M(x) & \text{if $M$ halts within $t$ steps}\\\
    0 & \text{otherwise}
\end{cases}$$

并且， $C$ 可以在 $poly(|M|,t,n)$ 的时间内被构造出来。

### 某个复杂类

定义复杂类：

$$\text{P}\_{/poly}=\bigcup\limits\_{c=1,2,3\dots}\text{SIZE}(n^c)$$

和之前的 $\text{P}$ 满足关系

$$\text{P}\subseteq\text{P}_{/poly}$$

（由上述 theorem 得到）

这里实际上也是真包含，$P_{\text{/poly}}$ 甚至包含了一些不可计算的函数。

构造：

令

$$S:N\rightarrow\\{0,1\\}^*$$

对于输入 $N$，先转换成二进制串，再去掉最高位的 $1$。例如，$S(7)=11$，$S(8)=000$。

定义 Unary Halting Function：

$$\text{UH}(x)=\text{HALTONZERO}(S(|x|))$$

$\text{UH}$ 是不可计算的。尝试将 $\text{HALTONZERO}$ 归约到 $\text{UH}$。例如，TM $M$ 的编码为 $11_{(2)}$，我们要找到一个 $x$，满足 $S(|x|)=11_{(2)}=\langle M\rangle$。

那么，从 $M$ 的编码 $11_{(2)}$ 出发，先在开头添上一位，变成 $111_{(2)}=7$，那么 $x=1111111_{(2)}$ 即可。因此，归约成立，$\text{UH}$ 不可计算。

然后，$\text{UH}$ 的函数值只和输入长度相关，如果限制输入长度，那么 $\text{UH}$ 是一个常数函数。显然，一个常数函数可以用常数多个门去计算。根据定义，可知 $\text{UH}\in\text{P}_{/poly}$。