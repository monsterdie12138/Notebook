---
comments: true
---

<span style="font-family: 'Times New Roman';">

# Chapter7 Fourier级数

***

## 7.1 Fourier级数的基本概念

### Fourier级数的相关定义

**Fourier级数和Fourier系数：**  

若 $f$ 以 $2\pi$ 为周期，且在 $[-\pi,\pi]$ 上可积，那么  

$$f(x)\sim \frac{a_0}{2}+\sum\limits_{n=1}^{\infty}(a_n\cos nx+b_n\sin nx)$$  

称等式右边为 $f$ 在 $[-\pi,\pi]$ 上的**Fourier级数**。  

* $a_n=\frac{1}{\pi}\int_{-\pi}^{\pi}f(x)\cos nxdx$  
* $b_n=\frac{1}{\pi}\int_{-\pi}^{\pi}f(x)\sin nxdx$  

称为 $f$ 的 **Fourier系数**。  

**Fourier展开的基础：正交性：**  

假设函数 $\varphi$ 和 $\psi$ 都在 $[a,b]$ 上可积，且  
  
$$\int_a^b\varphi(x)\psi(x)dx=0$$

则称 $\varphi$ 和 $\psi$ 在 $[a,b]$ 上**正交**。  

* $\int_{-\pi}^{\pi}\cos nxdx=\int_{-\pi}^{\pi}\sin nxdx=0$，$n\geqslant1$  
* $\int_{-\pi}^{\pi}\cos nx\cos mxdx=\int_{-\pi}^{\pi}\sin nx\sin mxdx=0$，$m\neq n$  
* $\int_{-\pi}^{\pi}\cos nx\sin mx=0$，$n$，$m\geqslant1$  
* $\int_{-\pi}^{\pi}1dx=2\pi$，$\int_{-\pi}^{\pi}\cos^2nxdx=\pi$，$\int_{-\pi}^{\pi}\sin^2nxdx=\pi$   

### 正弦级数和余弦级数

若 $f$ 以 $2\pi$ 为周期，且 $f$ 为奇函数，则  

$$a_n=0,~b_n=\frac{2}{\pi}\int_0^{\pi}f(x)\sin nx dx$$  

此时 

$$f(x)\sim\sum\limits_{n=1}^{\infty}b_n\sin nx$$

该Fourier级数称为**正弦级数**。  

同样地，若 $f$ 是**偶函数**，则  

$$b_n=0,~a_n=\frac{2}{\pi}\int_0^{\pi}f(x)\cos nx dx$$  

此时 

$$f(x)\sim\frac{a_0}{2}+\sum\limits_{n=1}^{\infty}a_n\cos nx$$

该Fourier级数称为**余弦级数**。 

!!! Example
    **例：将 $f(x)=x$，$x\in[0,\pi]$ 分别展开为余弦级数和正弦级数。**  

    余弦级数：  
    对 $f(x)$ 进行偶延拓：
    $\tilde{f}(x)=\begin{cases}
    -x,~~~x\in[-\pi,0]\\\
    x,~~~~~~x\in[0,\pi]
    \end{cases}$  
    $\tilde{f}(x)$ 为偶函数  
    $b_n=0$  
    $a_0=\pi$  
    当 $n\geqslant1$ 时  
    $a_n=\frac{2}{\pi}\tilde{f}(x)\cos nx dx=\begin{cases}
    0,~~~~~~~~~~~~~~~~~n=2k\\\
    -\frac{4}{(2k+1)^2\pi},~~x=2k+1
    \end{cases}$  
    $f(x)\sim\frac{\pi}{2}-\frac{4}{\pi}\sum\limits_{k=0}^{\infty}\frac{\cos(2k+1)x}{(2k+1)^2}$  
    正弦级数：  
    对 $f(x)$ 进行奇延拓：  
    $\tilde{f}(x)=x$，$x\in(-\pi,\pi]$  
    同理可得：$f(x)\sim\sum\limits_{n=1}^{\infty}\frac{2(-1)^{n+1}}{n}\sin nx$  

### 不以 $2\pi$ 为周期的Fourier级数

设 $f(x)$ 是以 $2T$ 为周期的函数，且在 $[-T,T]$ 上可积  
令 

$$\varphi(t)=f(\frac{T}{\pi}·t),~t\in R$$

则 $\varphi(t)$ 是以 $2\pi$ 为周期，且在 $[-\pi,\pi]$ 上可积的函数，从而 $\varphi$ 的Fourier级数为  

$$\varphi(t)\sim\frac{a_0}{2}+\sum\limits_{n=1}^{\infty}(a_n\cos nt+b_n\sin nt)$$  

其中 

$$a_n=\frac{1}{\pi}\int_{-\pi}^{\pi}\varphi(t)\cos ntdt$$

$$=\frac{1}{\pi}\int_{-\pi}^{\pi}f(\frac{T}{\pi}t)\cos ntdt$$

$$\stackrel{x=\frac{T}{\pi}·t}\Longrightarrow\frac{1}{T}\int_{-T}^Tf(x)\cos\frac{n\pi x}{T}dx$$

$$b_n=\frac{1}{T}\int_{-T}^Tf(x)\sin\frac{n\pi x}{T}dx$$  

综上：  

* $f(x)\sim\frac{a_0}{2}+\sum\limits_{n=1}^{\infty}(a_n\cos\frac{n\pi x}{T}+b_n\sin\frac{n\pi x}{T})$  
* $a_n=\frac{1}{T}\int_{-T}^Tf(x)\cos\frac{n\pi x}  {T}dx$
* $b_n=\frac{1}{T}\int_{-T}^Tf(x)\sin\frac{n\pi x}{T}dx$  

!!! Example
    **例：计算 $f(x)=\begin{cases}
    0,~~~x\in[-1,0)\\\
    x^2,~x\in[0,1)
    \end{cases}$ 的Fourier级数。**  

    将 $f$ 延拓成以 $2T$ 为周期的函数，$T=1$  
    此时Fourier系数为：  
    $a_0=\frac{1}{3}$  
    $a_n=\frac{2(-1)^n}{n^2\pi^2}$  
    $b_n=\frac{(-1)^{n+1}}{n\pi}+\frac{2[(-1)^n-1]}{n^3\pi^3}$  
    从而 $f$ 的Fourier级数为 $f(x)\sim\sum\limits_{n=1}^{\infty}(\frac{2(-1)^n\cos n\pi x}{n^2\pi^2}+(\frac{(-1)^{n+1}}{n\pi}+\frac{2[(-1)^n-1]}{n^3\pi^3})\sin n\pi x)$  

***

## 7.2 Fourier级数敛散性的判别

!!! Note
    以下定理都是为了推演出最后的结论，具体的证明过程过于繁琐，因此省略。

**Bessel不等式：**

设 $f$ 在 $[-\pi,\pi]$ 上可积，则  

$$\frac{a_0^2}{2}+\sum\limits_{n=1}^{\infty}(a_n^2+b_n^2)\leqslant\frac{1}{\pi}\int_{-\pi}^{\pi}f^2(x)dx$$

**推论一：**

设 $f$ 在 $[-\pi,\pi]$ 上可积，则  

$$\lim\limits_{n\rightarrow\infty}a_n=\lim\limits_{n\rightarrow\infty}b_n=0$$  

即  

$$\lim\limits_{n\rightarrow\infty}\int_{-\pi}^{\pi}f(x)\cos nx dx=\lim\limits_{n\rightarrow\infty}\int_{-\pi}^{\pi}f(x)\sin nx dx=0$$  

**推论二：**

设 $f$ 在 $[0,\pi]$ 上可积，则  

$$\lim\limits_{n\rightarrow\infty}\int_0^{\pi}f(x)\sin(n+\frac{1}{2})xdx=0$$

**Dirichlet积分：**

设 $f$ 以 $2\pi$ 为周期，且在 $[-\pi,\pi]$ 上可积，则其Fourier级数的部分和函数满足：  

$$S_m(x)=\frac{1}{\pi}\int_{-\pi}^{\pi}[f(t+x)D_m(t)]dt$$

其中 

$$D_m(t)=\begin{cases}
\frac{\sin(m+\frac{1}{2})t}{2\sin\frac{t}{2}},~t\neq0\\\
\frac{1}{2}+m,~~~~~t=0
\end{cases}$$  

该积分形式称为**Dirichlet积分**。  

**收敛定理：**

只要 $f$ 在 $x$ 处的广义右导数存在，则 $\frac{1}{\pi}\int_0^{\pi}[f(t+x)D_m(t)]dt$ 会收敛到 $\frac{f(x+o)}{2}$ ；同理，只要 $f$ 在 $x$ 处的广义左导数存在，则 $\frac{1}{\pi}\int_{-\pi}^0[f(t+x)D_m(t)]dt$ 会收敛到 $\frac{f(x-o)}{2}$。特别地，当 $f$ 在 $0$ 处的广义左右导数均存在时，有  

$$S_m(x)\stackrel{m\rightarrow\infty}\longrightarrow\frac{f(x+o)+f(x-o)}{2}$$  

**Fourier级数敛散性判别的结论：**

若 $f$ 的导数在 $[a,b]$ 上连续，则称 $f$ 在 $[a,b]$ 上**光滑**。对于定义在 $[a,b]$ 上的函数 $f$ **按段光滑**的，当且仅当存在 $[a,b]$ 的一个分割 $a=x_0<x_1<···<x_n=b$，使得：  

* $\forall 1\leqslant i\leqslant n$，都有 $f$ 在 $(x_{i-1},x_i)$ 上存在连续的导数.  
* $\forall 0\leqslant i\leqslant n$，都有 $f$ 在 $x_i$ 处存在左右极限（$f$ 在 $x_0$ 和 $x_n$ 处分别存在右极限和左极限）  
* $\forall 0\leqslant i\leqslant n$，都有 $f'$ 在 $x_i$ 处存在左右极限（$f'$ 在 $x_0$ 和 $x_n$ 处分别存在右极限和左极限）  

若 $f$ 是以 $2\pi$ 为周期，且在 $[-\pi,\pi]$ 上**按段光滑**的函数，则 $\forall x\in[-\pi,\pi]$，都有 $f$ 的Fourier级数：  

$$\frac{a_0}{2}+\sum\limits_{n=1}^{\infty}(a_n\cos nx+b_n\sin nx)=\frac{f(x+o)+f(x-o)}{2}$$

!!! Example
    **例：求 $f(x)=\begin{cases}
    1,x\in[-\pi,0)\\\
    0,x\in[0,\pi)
    \end{cases}$ 的Fourier级数，并求级数的和。**  

    $a_n=\begin{cases}
    1,n=0\\\
    0,n\geqslant1
    \end{cases}$  
    $b_n=\frac{(-1)^n-1}{n\pi}$  
    $f$ 的Fourier级数为  
    $f\sim\frac{1}{2}+\sum\limits_{n=1}^{\infty}\frac{(-1)^n-1}{n\pi}\sin nx$  
    由于 $f$ 在 $[-\pi,\pi)$ 上按段光滑  
    因此当 $x\in[-\pi,0)$ 时，级数收敛于 $1$  
    当 $x\in(0,\pi)$ 时，级数收敛于 $0$  
    当 $x=0$ 或 $-\pi$ 时，级数收敛于 $\frac{f(x+o)+f(x-o)}{2}=\frac{1}{2}$  

***

## 7.3 Fourier级数的性质

**性质一：**

$\frac{a_0}{2}+\sum\limits_{n=1}^{\infty}(a_n\cos nx+b_n\sin nx)$ 是某个在 $[-\pi,\pi]$ 上可积的函数的Fourier级数的必要条件是 $\sum\limits_{n=1}^{\infty}(a_n^2+b_n^2)$ 收敛。

**性质二：**

设 $f$ 为 $[-\pi,\pi]$ 上的光滑函数，且 $f(-\pi)=f(\pi)$ ，则 $f$ 的Fourier级数在 $[-\pi,\pi]$ 上一致收敛于 $f$ ，即 

$$f(x)=\frac{a_0}{2}+\sum\limits_{n=1}^{\infty}(a_n\cos nx+b_n\sin nx)$$

且 

$$f'(x)\sim\sum\limits_{n=1}^{\infty}(-na_n\sin nx+nb_n\cos nx)$$  

**性质三：**

令 $T_n$ 表示 $n$ 阶三角多项式 $\frac{A_0}{2}+\sum\limits_{k=1}^n(A_k\cos kx+B_k\sin kx)$ 的全体，设 $f$ 为在 $[-\pi,\pi]$ 上可积的函数，$a_0$，$a_k$，$b_k$ 为 $f$ 的Fourier系数，则 $f$ 的Fourier级数的部分和函数 

$$S_n(x)=\frac{a_0}{2}+\sum\limits_{k=1}^n(a_k\cos kx+a_k\sin kx)$$

是 $f$ 在 $T_n$ 中的最佳平方逼近元素，即  

$$\int_{-\pi}^{\pi}[f(x)-S_n(x)]^2dx=\min\{\int_{-\pi}^{\pi}[f(x)-g(x)]^2dx,g\in T_n\}$$  

**性质四：Weierstrass第二逼近定理：**

对周期为 $2\pi$ 的任意一个连续函数 $f$，都存在三角多项式序列  

$$\\{\psi_n(x)=\frac{A_0}{2}+\sum\limits_{k=1}^n(A_k\cos kx+B_k\sin kx)\\}$$  

使得 $\\{\psi_n\\}$ 在 $R$ 上一致收敛于 $f$。 