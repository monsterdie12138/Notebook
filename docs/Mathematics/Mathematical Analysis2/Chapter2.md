---
comments: true
---

<span style="font-family: 'Times New Roman';">

# Chapter2 函数项级数

***

## 2.1 函数项级数的基本概念

### 函数列的相关定义

**函数列：**

设 $E\subseteq R$，$f_1,f_2,···,f_n,···$ 是定义在 $E$ 上的一系列函数，这一列函数称为 $E$ 上的一个**函数列**，记作$\\{f_n\\}$。  

设 $x_0\in E$，若 $\\{f_n(x_0)\\}$ 收敛（$n\rightarrow\infty$），则称函数列 $\\{f_n\\}$ 在**点 $x_0$ 处收敛**。  

称 $\\{x_0\in E|\\{f_n(x_0)\\}$收敛$\\}$ 为 $\\{f_n\\}$ 的**收敛域**。  

设 $D$ 为 $\\{f_n\\}$ 的收敛域，则可定义  

$$f:D\rightarrow R$$

$$x\mapsto \lim\limits_{n\rightarrow \infty}f_n(x)$$  
称 $f$ 为 $\\{f_n\\}$ 在 $D$ 上的**极限函数**，即 $\\{f_n\\}$ 在 $D$ 上收敛于 $f$。  

### 函数项级数的相关定义

**函数项级数：**

设 $E\subseteq R$，$\\{u_n(x)\\}$ 是定义在 $E$ 上的一个函数列，取表达式（形式和）  

$$u_1(x)+u_2(x)+···+u_n(x)+···,~x\in E$$

为 $E$ 上的**函数项级数**，记作 $\sum\limits_{n=1}^{\infty}u_n(x)$ 或 $\sum u_n(x)$。  

设 

$$S_n(x)=\sum\limits_{k=1}^nu_n(x)$$

$\\{S_n(x)\\}$ 为 $\sum u_n(x)$ 的**部分和函数列**。  

设 $x_0\in E$，若 $\\{S_n(x)\\}$ 在点 $x_0$ 收敛（或发散），则称 $\sum u_n(x)$ 在点 $x_0$ 收敛（或发散），$\sum u_n(x)$ 的收敛域定义为 $\\{S_n(x)\\}$ 的收敛域。

设 $D\subseteq E$，若 $\\{S_n(x)\\}$ 在 $D$ 上收敛，其极限函数为 $S(x)$，则称函数项级数 $\sum u_n(x)$ 在 $D$上收敛，其和函数为 $S(x)$，记作 

$$\sum u_n(x)=S(x),~x\in D$$

**综上：研究函数项级数 $\sum\limits_{n=1}^{\infty}u_n(x)$ 的性质，实际上就是在研究函数列 $\\{S_n(x)\\}$ 的性质。**

### 一致收敛的相关定义

**点态收敛：**

$ \forall \varepsilon>0$，$\forall x\in D$，$\exists N_{(\varepsilon,x)}\in N^*$，使得当 $n>N$ 时，有 $|f_n(x)-f(x)|<\varepsilon$

**一致收敛：**

$\forall \varepsilon>0$，$\exists N_{\varepsilon}\in N^*$，使得当 $n>N$ 时，对于 $\forall x\in D$，有 $|f_n(x)-f(x)|<\varepsilon$

**内闭一致收敛：**

设函数列 $\\{f_n\\}$ 和 $f$ 定义在区间 $I$ 上，若对于 $I$ 的任何一个闭子区间 $[a,b]$，都有 $\\{f_n\\}$ 在 $[a,b]$ 上一致收敛于 $f$，则称 $\\{f_n\\}$ 在 $I$ 上**内闭一致收敛**。

!!! Example
    **例：证明：$f_n(x)=x^n$ 在 $[0,1]$ 上不一致收敛。**  

    $f(x)=\begin{cases}
    0,~~~~0\leqslant x<1\\\
    1,~~~~x=1
    \end{cases}$  
    取 $\varepsilon_0=\frac{1}{2}$，$\forall N\in N^*$，取 $n=N+1$，取 $x=(\frac{1}{2})^{\frac{1}{n}}$  
    有 $|f_n(x)-f(x)|=\frac{1}{2}\geqslant \varepsilon_0$  
    因此不一致收敛。

***

## 2.2 一致收敛

### 一致收敛的性质

**连续性定理：**

若函数列 $\\{f_n(x)\\}$ 满足：  

* 在 $[a,b]$ 上一致收敛于 $f$  
* 每一项 $f_n(x)$ 都在 $[a,b]$ 上连续  

则其极限函数 $f$ 也在 $[a,b]$ 上连续。 

若函数项级数 $\sum\limits_{n=1}^{\infty}u_n(x)$ 满足：  

* 在 $[a,b]$ 上一致收敛于 $S(x)$  
* 每一项 $u_n(x)$ 都在 $[a,b]$ 上连续

则其和函数 $S(x)$ 也在 $[a,b]$ 上连续，且对于任意 $x_0\in[a,b]$，成立  

$$\lim\limits_{x\rightarrow x_0}\sum\limits_{n=1}^{\infty}u_n(x)=\sum\limits_{n=1}^{\infty}\lim\limits_{x\rightarrow x_0}u_n(x)$$  

即**极限运算和无限求和计算可以交换次序。**  

!!! Note  
    若任意 $u_n(x)$ 在 $(a,b)$ 上连续，只要 $\sum u_n(x)$ **内闭一致收敛**于 $S(x)$，就足以保证 $S(x)$ 在 $(a,b)$ 上连续。

**逐项积分定理：**

若函数列 $\\{f_n(x)\\}$ 满足：  

* 在 $[a,b]$ 上一致收敛于 $f$  
* 每一项 $f_n(x)$ 都在 $[a,b]$ 上连续  

则其极限函数 $f$ 在 $[a,b]$ 上可积。

若函数项级数 $\sum\limits_{n=1}^{\infty}u_n(x)$ 满足：  

* 在 $[a,b]$ 上一致收敛于 $S(x)$
* 每一项 $u_n(x)$ 都在 $[a,b]$ 上连续

则其和函数 $S(x)$ 在 $[a,b]$ 上可积，且  

$$\int_a^b\sum\limits_{n=1}^{\infty}u_n(x)dx=\sum\limits_{n=1}^{\infty}\int_a^bu_n(x)dx$$

即**积分运算可以和无限求和运算交换顺序**。  

**逐项求导定理：**

设函数列 $\\{f_n\\}$ 满足：

* $f_n(x)$ 在 $[a,b]$ 上有连续的导数  
* $\\{f_n\\}$ 在 $[a,b]$ 上点态收敛于 $f$  
* $\\{f_n'\\}$ 在 $[a,b]$ 上一致收敛  

则 $f$ 在 $[a,b]$ 上可导。

设函数项级数 $\sum u_n(x)$ 满足：  

* 任意一项 $u_n(x)$ 在 $[a,b]$ 上有连续的导数  
* $\sum u_n(x)$ 在 $[a,b]$ 上点态收敛于 $S(x)$  
* $\sum u_n'(x)$ 在 $[a,b]$ 上一致收敛  

则 $S(x)$ 在 $[a,b]$ 上可导，且  

$$\frac{d}{dx}\sum\limits_{n=1}^{\infty}u_n(x)=\sum\limits_{n=1}^{\infty}\frac{d}{dx}u_n(x)$$ 

即**求导运算可以和无限求和运算交换次序**。  

!!! Note  
    若 $\sum u_n(x)$ 在 $(a,b)$ 上收敛于 $S(x)$，且每个 $u_n(x)$ 在 $(a,b)$ 上都有连续的导数，则只要 $\sum u_n'(x)$ 在 $(a,b)$ 上内闭一致收敛，就足以保证 $S(x)$ 在 $(a,b)$ 上可导。

### 一致收敛的判别

**充要条件一：**

$\\{f_n\\}$ 在收敛域 $D$ 上一致收敛于 $f$ 的充要条件是：  

$$\lim\limits_{n\rightarrow\infty}\sup\limits_{x\in D}|f_n(x)-f(x)|=0$$

!!! Example
    **例1：令 $f_n(x)=nxe^{-nx^2},$，$x\in(0,+\infty)$，判别 $\\{f_n\\}$ 在 $(0,+\infty)$ 上的一致收敛性。**  

    极限函数 $f(x)=0$  
    令 $M_n=\sup\\{|f_n(x)-f(x)|:x\in (0,+\infty)\\}=\sup\\{nxe^{-nx^2}:x\in(0,+\infty)\\}$  
    取 $x=\frac{1}{\sqrt{n}}$  
    则 $M_n\geqslant\frac{\sqrt{n}}{e}$，不趋于0  
    $\\{f_n\\}$ 不一致收敛  
    （或者可以通过求导的方式直接算出 $nxe^{-nx^2}$ 的最大值，也就是 $M_n$）  

!!! Example
    **例2：设 $S_0(x)$ 在 $[0,a]$ 上连续，令 $S_n(x)=\int_0^xS_{n-1}(t)dt$，证明：$\{S_n(x)\}$ 在 $[0,a]$ 上一致收敛于 $0$。**  

    令 $M_n=\sup\\{|S_n(x)|:x\in[0,a]\\}$  
    由 $S_0\in C[0,a]$，可知 $S_0$ 有界  
    $\exists k>0$ 使得 $|S_0(x)|\leqslant k$  
    $|S_1(x)|\leqslant kx$  
    $|S_2(x)|\leqslant k·\frac{x^2}{2}$  
    ······  
    $|S_n(x)|\leqslant k·\frac{x^n}{n!}$  
    $M_n\leqslant k·\frac{a^n}{n!}$  
    $\lim\limits_{n\rightarrow\infty}M_n=0$  
    因此一致收敛。 

!!! Example
    **例3：设 $S'(x)$ 在区间 $(a,b)$ 上连续，$S_n(x)=n[S(x+\frac{1}{n})-S(x)]$，证明：$\{S_n(x)\}$ 在区间 $(a,b)$ 上一致收敛于 $S'(x)$。**  

    对于 $\forall [c,d]\subseteq(a,b)$，$S'(x)$ 在 $[c,d]$ 上一致连续   
    $\Longrightarrow \forall\varepsilon>0$，$\exists \delta>0$，当 $x'$，$x''\in[c,d]$ 时，只要 $|x'-x''|<\delta$，就有 $|S'(x')-S'(x'')|<\varepsilon$  
    令 $N=\frac{1}{\delta}$，当 $n>N$ 时，$\forall x\in[c,d]$，由Lagrange中值定理：  
    $\exists \xi\in(x,x+\frac{1}{n})$，使得 $S_n(x)=\frac{S(x+\frac{1}{n})-S(x)}{(x+\frac{1}{n})-x}=S'(\xi)$  
    于是由 $|\xi-x|\leqslant\frac{1}{n}<\frac{1}{N}=\delta$  
    有 $|S_n(x)-S'(x)|=|S'(\xi)-S'(x)|<\varepsilon$

**充要条件二：**

$\\{f_n\\}$ 在收敛域 $D$ 上一致收敛于 $f$ 的充要条件是：对任意数列 $\{x_n\}$，$x_n\in D$，成立  

$$\lim\limits_{n\rightarrow\infty}(f_n(x_n)-f(x_n))=0$$

该充要条件常用于判断函数列的不一致收敛。  

!!! Example
    **例：证明函数列 $\\{f_n\\}$，$f_n(x)=x^n$ 在 $[0,1)$ 上不一致收敛。**  

    $f=0$  
    取 $x_n=1-\frac{1}{n}\in[0,1)$  
    $f_n(x_n)-f(x_n)=(1-\frac{1}{n})^n\longrightarrow\frac{1}{e}(n\rightarrow\infty)$  
    因此该函数列在 $[0,1)$ 上不一致收敛。    

**Cauchy收敛准则：**

$\sum u_n(x)$ 在收敛域 $D$ 上一致收敛的充要条件是：  

$\forall \varepsilon>0$，$\exists N_{(\varepsilon)}\in N^*$，$\forall n>N$，$\forall p\in Z^+$，$\forall x\in D$，有 $|u_{n+1}(x)+···+u_{n+p}(x)|<\varepsilon$

若取 $p=1$，则可得到函数项级数一致收敛的必要条件为 $\\{u_n(x)\\}$ 在 $D$ 上一致收敛于 $0$。  

推论：$\sum u_n(x)$ 在 $D$ 上一致收敛于 $S(x)\Longleftrightarrow\lim\limits_{n\rightarrow\infty}\sup\limits_{x\in D}\{|S_n(x)-S(x)|\}=0$  

!!! Example
    **例：求 $\sum\limits_{n=0}^{\infty}x^n$ 的收敛域，并判断其在收敛域内的一致收敛性。**  

    $S_n(x)=\begin{cases}
    \frac{1-x^{n+1}}{1-x}, x\neq 1\\\
    n+1, x=1
    \end{cases}$  
    当且仅当 $|x|<1$ 时，$S_n(x)$ 收敛，且 $S(x)=\frac{1}{1-x}$  
    $\sup\limits_{|x|<1}\\{|S_n(x)-S(x)|\\}=\sup\limits_{|x|<1}\\{|\frac{x^{n+1}}{1-x}|\\}$  
    取 $x=1-\frac{1}{n}$ 满足 $|x|<1$  
    则上式 $\geqslant \frac{(1-\frac{1}{n})^{n+1}}{\frac{1}{n}}=n(1-\frac{1}{n})^n(1-\frac{1}{n})$，发散到 $+\infty$  
    由Cauchy收敛原理：该函数项级数在收敛域 $(-1,1)$ 内不一致收敛。  

**Weierstrass判别法：**

设 $D$ 上的函数项级数 $\sum u_n$，若存在收敛的正项级数 $\sum a_n$，使得存在 $N\in N^*$，对于任意 $n>N$ 及$x\in D$，都有 $|u_n(x)|\leqslant a_n$，则 $\sum u_n(x)$ 在 $D$ 上一致收敛。

$\sum a_n$ 也称作 $\sum u_n(x)$ 的**优级数**。

**Dirichlet判别法：**

若函数项级数 $\sum u_n(x)$，$\sum v_n(x)$ 满足：  

* $\sum u_n(x)$ 的部分和数列 $\\{S_n(x)\\}$ 在 $D$ 上一致有界，即存在 $N\in N^*$，对于 $\forall n>N$ 及 $\forall x\in D$，都有 $|S_n(x)|=|\sum\limits_{k=1}^{n}u_k(x)|\leqslant M$  
* 对于 $\forall x\in D$，$\\{v_n(x)\\}$ 关于 $n$ 单调，且 $\\{v_n(x)\\}$ 在 $D$ 上一致收敛于 $0$

则 $\sum u_n(x)v_n(x)$ 在 $D$ 上一致收敛。

!!! Example
    **例：若 $\\{a_n\\}$ 单调收敛于 $0$，求证：$\sum a_n\cos nx$ 在 $(0,2\pi)$ 上内闭一致收敛。**  

    任取闭区间 $[a,b]\subseteq (0,2\pi)$  
    存在 $\theta$ 使得 $\sin \frac{x}{2}$ 取最小  
    令 $v_n(x)=a_n$，$u_n(x)=\cos nx$  
    $|2\sin \frac{x}{2}\sum\limits_{k=1}^n\cos kx|=|\sum\limits_{k=1}^n(\sin(k+\frac{1}{2})x-\sin(k-\frac{1}{2})x)|\leqslant 2$  
    $|\sum\limits_{k=1}^nu_k(x)|\leqslant\frac{1}{2\sin \frac{x}{2}}\leqslant\frac{1}{\sin \frac{\theta}{2}}$  
    $\sum u_n(x)$ 的部分和数列一致有界  
    $\sum v_n(x)$ 关于 $n$ 单调趋于 $0$  
    由Dirichlet判别法：该函数项级数在 $(0,2\pi)$ 上内闭一致收敛。  

**Abel判别法：**

若函数项级数 $\sum u_n(x)$，$\sum v_n(x)$ 满足：  

* $\sum u_n(x)$ 在 $D$ 上一致收敛  
* 对于 $\forall x\in D$，$\\{v_n(x)\\}$ 关于 $n$单调，且 $\\{v_n(x)\\}$ 在 $D$ 上一致有界

则 $\sum u_n(x)v_n(x)$ 在 $D$ 上一致收敛。

!!! Example
    **例1：若 $\sum a_n$ 收敛，求证：$\sum a_nx^n$ 在 $[0,1]$ 上一致收敛。**  

    令 $u_n(x)=a_n$  
    则$\sum u_n(x)$ 在 $[0,1]$ 上一致收敛  
    令 $v_n(x)=x^n$  
    则对 $\forall x\in D$，$\\{v_n(x)\\}$ 关于 $n$ 单调，且 $|x^n|\leqslant 1$ 一致有界  
    由Abel判别法：该函数项级数在 $[0,1]$ 上一致收敛。  

!!! Example
    **例2：判断 $\sum\frac{(-1)^n(x+n)^n}{n^{n+1}}$，$x\in [0,1]$ 的一致收敛性。**  

    令 $u_n(x)=\frac{(-1)^n}{n}$  
    则 $\sum u_n(x)$ 一致收敛  
    令 $v_n(x)=(\frac{x+n}{n})^n=(1+\frac{x}{n})^n$  
    取对数求导可得：$\\{v_n(x)\\}$ 关于 $n$ 单调递增  
    $v_n(x)\leqslant v_n(1)=(1+\frac{1}{n})^n\leqslant e$  
    $\\{v_n(x)\\}$ 一致有界  
    由Abel判别法：该函数项级数在 $[0,1]$ 上一致收敛。  

***

## 2.3 幂级数

### 幂级数的相关定义

**幂级数：**

称形如  

$$\sum\limits_{n=0}^{\infty}a_n(x-x_0)^n=a_0+a_1(x-x_0)+···+a_n(x-x_0)^n+···$$  

的函数项级数为**幂级数**。其中 $a_i$ 为常数，称为幂级数的**级数**，$x_0$ 也是常数。

!!! Note
    我们一般研究 $x_0=0$ 时的情形：$\sum\limits_{n=0}^{\infty}a_nx^n=a_0+a_1x+···+a_nx^n+···$。

**收敛半径：**

令 

$$A=\lim\limits_{n\rightarrow\infty}\sqrt[n]{|a_n|}$$

或 

$$A=\lim\limits_{n\rightarrow\infty}|\frac{a_{n+1}}{a_n}|$$

定义 

$$R=\frac{1}{A}$$

则： 

* 当 $|x|<R$ 时，$\sum a_nx^n$ 在 $x$ 处**绝对收敛**  
* 当 $|x|>R$ 时，$\sum a_nx^n$ 在 $x$ 处**发散**  
* 当 $|x|=R$ 时，$\sum a_nx^n$**可能收敛，也可能发散**  

称 $R$ 为幂级数的**收敛半径**，$(-R,R)$ 为幂级数的**收敛区间**。  

* 若 $R=0$，则幂级数仅在 $x=0$ 处收敛  
* 若 $R=+\infty$，则幂级数在任意 $x$ 处收敛

### 幂级数的性质

**Abel第一定理：**

若幂级数 $\sum a_nx^n$ 在点 $\xi$ 处收敛，则对于任意满足 $|x|<\xi$ 的 $x$，必有幂级数在点 $x$ 处绝对收敛。

**Abel第二定理：**

若幂级数 $\sum a_nx^n$ 的收敛半径 $R>0$，则：  

* 幂级数 $\sum a_nx^n$ 在 $(-R,R)$ 内闭一致收敛.  
* 若幂级数 $\sum a_nx^n$ 在 $x=R$ 处收敛，则其在$[0,R]$ 上一致收敛.（$x=-R$ 同理）

**连续性：**

**幂级数在其收敛域上连续。**  

设 $\sum\limits_{n=0}^{\infty}a_nx^n$ 的收敛半径为 $R$，则其和函数在 $(-R,R)$ 上连续.

若 $\sum\limits_{n=0}^{\infty}a_nx^n$ 在 $x=R$（或 $-R$）收敛，则其和函数在 $x=R$（或 $-R$）左（右）连续.  

**逐项可积性：**

**幂级数在包含于收敛域中的任意闭区间上可以逐项求积分.**  

$\forall a$，$b$ 位于 $\sum\limits_{n=0}^{\infty}a_nx^n$ 的收敛域中，都有：  

$$\int_a^b(\sum\limits_{n=0}^{\infty}a_nx^n)dx=\sum\limits_{n=0}^{\infty}\int_a^b(a_nx^n)dx$$  

特别地：取 $a=0$，$b=x$，$x$在收敛域内，有：  

$$\int_0^x(\sum\limits_{n=0}^{\infty}a_nt^n)dt=\sum\limits_{n=0}^{\infty}\frac{a_n}{n+1}x^{n+1}$$

!!! Note
    逐项积分所得幂级数 $\sum\limits_{n=0}^{\infty}\frac{a_n}{n+1}x^{n+1}$ 与原幂级数 $\sum\limits_{n=0}^{\infty}a_nx^n$ 具有相同的收敛半径，但收敛域有可能扩大。  

**逐项可导性：**

设 $\sum\limits_{n=0}^{\infty}a_nx^n$ 的收敛半径为 $R$，则其在 $(-R,R)$ 上可逐项求导，即：  

$$\frac{d}{dx}(\sum\limits_{n=0}^{\infty}a_nx^n)=\sum\limits_{n=0}^{\infty}na_nx^{n-1}$$

!!! Note
    逐项求导所得幂级数 $\sum\limits_{n=0}^{\infty}na_nx^{n-1}$ 与原幂级数 $\sum\limits_{n=0}^{\infty}a_nx^n$ 具有相同的收敛半径，但收敛域有可能缩小。 

!!! Example
    **例1：求 $\sum\limits_{n=1}^{\infty}(-1)^{n-1}n^2x^n$ 的和函数。**  

    收敛域为 $(-1,1)$  
    设和函数为 $S(x)$  
    $S(x)=x\sum\limits_{n=1}^{\infty}(-1)^{n-1}n^2x^{n-1}$  
    记为$xf(x)$，$x\in(-1,1)$  
    有 $\int_0^xf(t)dt=\sum\limits_{n=1}^{\infty}(-1)^{n-1}n^2\int_0^xt^{n-1}dt=\sum\limits_{n=1}^{\infty}(-1)^{n-1}nx^n=x\sum\limits_{n=1}^{\infty}(-1)^{n-1}nx^{n-1}$  
    记为 $xg(x)$  
    则 $\int_0^xg(t)dt=\sum\limits_{n=1}^{\infty}(-1)^{n-1}n·\frac{x^n}{n}=\frac{x}{1+x}$  
    $g(x)=(\frac{x}{1+x})'=\frac{1}{(1+x)^2}$  
    $f(x)=(xg(x))'=\frac{1-x}{(1+x)^3}$  
    $S(x)=xf(x)=\frac{x-x^2}{(1+x)^3}$  

!!! Example
    **例2：求 $\sum\limits_{n=1}^{\infty}(-1)^{n-1}\frac{x^{2n+1}}{(2n)^2-1}$ 的收敛域及和函数。**  

    令 $u_n(x)=(-1)^{n-1}\frac{x^{2n+1}}{(2n)^2-1}$  
    则 $|\frac{u_{n+1}(x)}{u_n(x)}|$ 趋于 $x^2$  
    由比式判别法：$|x|>1$ 时，$\sum u_n(x)$ 发散  
    $|x|<1$ 时，$\sum u_n(x)$ 收敛  
    收敛半径为 $1$  
    当 $|x|=1$ 时，$\sum|u_n(x)|=\sum\frac{1}{(2n)^2-1}$ 收敛  
    故收敛域为 $[-1,1]$  
    令 $S(x)$ 为和函数，先考虑 $x\in(-1,1)$  
    则对于 $\forall x\in(-1,1)$
    $S'(x)=\sum\limits_{n=1}^{\infty}(-1)^{n-1}\frac{x^{2n}}{2n-1}=x\sum\limits_{n=1}^{\infty}(-1)^{n-1}\frac{x^{2n-1}}{2n-1}$  
    记为 $xf(x)$  
    $f'(x)=\sum\limits_{n=1}^{\infty}(-1)^{n-1}x^{2n-2}=\frac{1}{1+x^2}$  
    可推出 $f(x)=\int_0^xf'(t)dt+f(0)=\arctan x$  
    于是 $S(x)=\int_0^xS'(t)dt+S(0)=\frac{1}{2}x^2\arctan x-\frac{x}{2}+\frac{1}{2}\arctan x$  
    由于上式在 $-1$，$1$ 处均连续  
    因此结合幂级数和函数的连续性，可知  
    $S(x)=\frac{1}{2}x^2\arctan x-\frac{x}{2}+\frac{1}{2}\arctan x$  

### 函数的幂级数展开

**Taylor级数：**

设 $f$ 在点 $x_0$ 无穷次可导，称  

$$\sum\limits_{n=0}^{\infty}\frac{f^{(n)}(x_0)}{n!}(x-x_0)^n$$  

为 $f$ 在点 $x_0$ 处的**Taylor级数**。

若存在 $r>0$，使得  

$$f(x)=\sum\limits_{n=0}^{\infty}\frac{f^{(n)}(x_0)}{n!}(x-x_0)^n$$  

对于 $\forall x\in(x_0-r,x_0+r)$ 恒成立，则称 $f$ 在 $(x_0-r,x_0+r)$ 上**可以展开成Taylor级数**。此时的Taylor级数被称为 $f$ 的**Taylor展开式（幂级数展开式）**。

若已知 

$$f(x)=\sum\limits_{n=0}^{\infty}a_n(x-x_0)^n,~x\in(x_0-r,x_0+r),~r>0$$

则必有 

$$a_n=\frac{f^{(n)}(x_0)}{n!}$$

其称为 $f$ 在点$x_0$ 处的**Taylor系数**。

**函数展开成Taylor级数的条件：**

**充要条件：余项趋于0** 

$$f(x)=T_n(x)+R_n(x)=\sum\limits_{k=0}^n\frac{f^{(k)}(x_0)}{k!}(x-x_0)^k+R_n(x)$$

其中 $R_n(x)$ 为余项。  

$$\lim\limits_{n\rightarrow\infty}f(x)=\lim\limits_{n\rightarrow\infty}T_n(x)+\lim\limits_{n\rightarrow\infty}R_n(x)$$  

$$f(x)=Taylor+\lim\limits_{n\rightarrow\infty}R_n(x)$$  

$f$ 在收敛域内等于其Taylor级数当且仅当 $\lim\limits_{n\rightarrow\infty}R_n(x)=0$。

**充分条件：导数的一致有界**

若对于 $\forall x\in(x_0-r,x_0+r)$，当 $n$ 充分大时，有 $|f^{(n)}(x)|\leqslant M$，即一致有界，则对于 $\forall x\in(x_0-r,x_0+r)$，有 $f$ 等于其Taylor级数。

**初等函数的Maclaurin展开式：**

* $e^x=\sum\limits_{n=0}^{\infty}\frac{1}{n!}x^n=1+x+\frac{x^2}{2!}+\frac{x^3}{3!}+···+\frac{x^n}{n!}+···$，$x\in R$  

* $\sin x=\sum\limits_{n=1}^{\infty}\frac{(-1)^{n-1}}{(2n-1)!}x^{2n-1}=x-\frac{x^3}{3!}+\frac{x^5}{5!}-···+(-1)^n\frac{x^{2n+1}}{(2n+1)!}+···$，$x\in R$

* $(1+x)^{\alpha}=\sum\limits_{n=0}^{\infty}\begin{pmatrix}\alpha\\\n\end{pmatrix}x^n=1+\sum\limits_{n=1}^{\infty}\frac{\alpha(\alpha-1)···(\alpha-n+1)}{n!}x^n$，$x\in\begin{cases}(-1,1),~~~\alpha\leqslant-1\\\
(-1,1],~~~ -1<\alpha<0\\\ 
[-1,1],~~~\alpha>0\end{cases}$  

* $\ln(1+x)=\sum\limits_{n=0}^{\infty}\frac{(-1)^n}{n+1}x^{n+1}=x-\frac{x^2}{2}+\frac{x^3}{3}-\frac{x^4}{4}+···+(-1)^{n-1}\frac{x^n}{n}+···$，$x\in(-1,1]$  

!!! Example
    **例1：求 $f(x)=\frac{1}{x^2}$ 在 $x=1$ 处的Taylor展开式。**  

    $\frac{1}{x}=\frac{1}{1+(x-1)}=\sum\limits_{n=0}^{\infty}(-1)^n(x-1)^n$，$x\in(0,2)$  
    逐项求导：$-\frac{1}{x^2}=\sum\limits_{n=0}^{\infty}(-1)^nn(x-1)^{n-1}$  
    $\frac{1}{x^2}=-\sum\limits_{n=0}^{\infty}(-1)^nn(x-1)^{n-1}$，$x\in(0,2)$  

!!! Example
    **例2：求 $f(x)=\frac{1}{3+5x-2x^2}$ 的Maclaurin展开式。**  

    $f(x)=\frac{1}{(3-x)(1+2x)}=\frac{1}{7}(\frac{1}{3-x}+\frac{2}{1+2x})$  
    由于 $\frac{1}{3-x}=\frac{1}{3}·\frac{1}{1+(-\frac{x}{3})}=\frac{1}{3}\sum\limits_{n=0}^{\infty}(\frac{x}{3})^n$，$x\in(-3,3)$  
    $\frac{1}{1+2x}=\sum\limits_{n=0}^{\infty}(-1)^n(2x)^n$，$x\in(-\frac{1}{2},\frac{1}{2})$  
    所以当 $x\in(-\frac{1}{2},\frac{1}{2})$时  
    $f(x)=\frac{1}{7}\sum\limits_{n=0}^{\infty}[\frac{1}{3^{n+1}}+(-1)^n2^{n+1}]x^n$  