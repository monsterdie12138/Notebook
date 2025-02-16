---
comments: true
---

<span style="font-family: 'Times New Roman';">

# Chapter1 数项级数

***

## 1.1 级数的基本概念

### 级数的相关定义

**级数：**

给定数列 $\\{x_n\\}$，将其各项相加，所得的形式和

$$x_1+x_2+···+x_n+···$$

称为**级数**，记作 $\sum\limits_{n=1}^{\infty}x_n$ 或 $\sum x_n$  
其中 $x_n$ 称为该级数的**通项**。  

**部分和：**

$$S_n=x_1+x_2+···+x_n$$

$S_n$ 称为第 $n$ 个**部分和**。若**部分和数列** $\\{S_n\\}$ 收敛，则称级数 $\sum x_n$ 收敛，并称 $\\{S_n\\}$ 的极限 $S$ 为级数 $\sum x_n$ 的**和**，记作 $\sum x_n=S$。

**余和：**

设级数 $\sum\limits_{n=1}^{\infty}x_n$ 收敛，和为 $S$，则对于 $\forall n\geqslant 1$，有 

$$\sum\limits_{k=n+1}^{\infty}x_k=x_{n+1}+x_{n+2}+···$$

收敛，其和为 

$$S-S_n=S-\sum\limits_{k=1}^nx_k$$  

称 

$$r_n=S-S_n$$

为 $\sum x_n$ 的**余和数列**。易知：$\lim\limits_{n\rightarrow\infty}r_n=0$

### 级数敛散性的判别

**Cauchy收敛原理：**

级数 $\sum x_n$ 收敛

$\Longleftrightarrow$ 部分和数列 $\\{S_n\\}$ 收敛 

$\Longleftrightarrow$ $\forall \varepsilon>0$，$\exists N\in N^*$，$\forall m>n>N$，$|S_m-S_n|<\varepsilon$

$\Longleftrightarrow$ $\forall \varepsilon>0$，$\exists N\in N^{\*}$，$\forall n>N$，$\forall p\in N^*$，$|x_{n+1}+x_{n+2}+···+x_{n+p}|<\varepsilon$  

!!! Example
    **例1：分析几何级数 $\sum\limits_{n=1}^{\infty}q^{n-1}~(q\in R)$ 的敛散性。**

    $S_n=\sum\limits_{k=1}^{n}q^{k-1}=\begin{cases}
    n,~~~~~~~~q=1\\\
    \frac{1-q^n}{1-q},~~~q\neq 1
    \end{cases}$  

    当且仅当 $|q|<1$ 时 $\\{S_n\\}$ 收敛   
    当且仅当 $|q|<1$ 时级数收敛  
    $\sum\limits_{n=1}^{\infty}q^{n-1}=\frac{1}{1-q}$

!!! Example
    **例2：证明调和级数 $\sum\limits_{n=1}^{\infty}\frac{1}{n}$ 发散。**  

    $\sum x_n$ 发散  
    $\Longleftrightarrow$ $\exists \varepsilon_0>0$，$\forall N\in N^{\*}$，$\exists n>N$，$\exists p\in N^{\*}$，$|x_{n+1}+x_{n+2}+···+x_{n+p}|\geqslant \varepsilon_0$    
    由于 $|\frac{1}{n+1}+\frac{1}{n+2}+···+\frac{1}{2n}|\geqslant \frac{1}{2n}·n=\frac{1}{2}$  
    因此取 $\varepsilon_0=\frac{1}{2}$，则 $\forall N\in N^*$，取 $n=N+1$，$p=N+1$，可得 $|x_{n+1}+x_{n+2}+···+x_{n+p}|\geqslant \varepsilon_0$

!!! Example
    **例3：证明p级数 $\sum\limits_{n=1}^{\infty}\frac{1}{n^2}$ 收敛。**  

    由于 $|\frac{1}{(n+1)^2}+\frac{1}{(n+2)^2}+···+\frac{1}{(n+p)^2}|$  
    $\leqslant |\frac{1}{n(n+1)}+\frac{1}{(n+1)(n+2)}+···+\frac{1}{(n+p-1)(n+p)}|$  
    $=|\frac{1}{n}-\frac{1}{n+p}|<\frac{1}{n}$  
    所以对于 $\forall \varepsilon >0$，取 $N=[\frac{1}{\varepsilon}]+1$  
    则 $\forall n>N>\frac{1}{\varepsilon},\forall p\in N^*$，都有 $|x_{n+1}+x_{n+2}+···+x_{n+p}|<\varepsilon$

!!! Example
    **例4：若对任意 $\varepsilon >0$ 和任意正整数 $p$，存在 $N(\varepsilon,p)$，使得 $|x_{n+1}+x_{n+2}+···+x_{n+p}|<\varepsilon$ 对一切 $n>N$ 成立，问级数 $\sum x_n$ 是否收敛。**  

    题目顺序：$\forall \varepsilon>0$，$\forall p\in N^{\*}$，$\exists N\in N^{\*}$，$\forall n>N$，$|x_{n+1}+x_{n+2}+···+x_{n+p}|<\varepsilon$  
    反例：$x_n=\frac{1}{n}$  
    $|x_{n+1}+x_{n+2}+···+x_{n+p}|=|\frac{1}{n+1}+\frac{1}{n+2}+···+\frac{1}{n+p}|<\frac{p}{n+1}$  
    令 $\frac{p}{n+1}<\varepsilon$  
    则 $n>\frac{p}{\varepsilon}-1$  
    $\forall \varepsilon>0$，$\forall p\in N^*$，$\exists N=[\frac{p}{\varepsilon}]$，$\forall n>N>\frac{p}{\varepsilon}-1$，$|x_{n+1}+x_{n+2}+···+x_{n+p}|<\varepsilon$  
    该数列满足要求但级数不收敛，故不确定。

!!! Example
    **例5：利用Cauchy收敛原理证明下列级数发散：$1+\frac{1}{2}-\frac{1}{3}+\frac{1}{4}+\frac{1}{5}-\frac{1}{6}+\frac{1}{7}+\frac{1}{8}-\frac{1}{9}+···$**  

    将三个捆绑为一组：  
    $\frac{1}{3n+1}+\frac{1}{3n+2}-\frac{1}{3n+3}>\frac{1}{3n+1}$  
    $|\frac{1}{3n+1}+\frac{1}{3n+2}-\frac{1}{3n+3}+···+\frac{1}{3(2n-1)+1}+\frac{1}{3(2n-1)+2}-\frac{1}{3(2n-1)+3}|$  
    $>|\frac{1}{3n+1}+···+\frac{1}{3(2n-1)+1}|>n·\frac{1}{3(2n-1)+3}=\frac{1}{6}$  
    $\exists \varepsilon_0=\frac{1}{6}>0$，$\forall N\in N^{\*}$，$\exists n=3N>N$，$\exists p=3N\in N^{\*}$，$|x_{n+1}+···+x_{n+p}|\geqslant \varepsilon_0$

### 级数的基本性质

**线性性：**

设 $\sum x_n$ 和 $\sum y_n$ 是两个收敛的级数，则 $\forall \alpha$，$\beta\in R$，级数 $\sum(\alpha x_n+\beta y_n)$ 也收敛，且  

$$\sum(\alpha x_n+\beta y_n)=\alpha\sum x_n+\beta\sum y_n$$

!!! Example
    **例：求 $\sum\limits_{n=1}^{\infty}(\frac{1}{2^{n-1}}+\frac{1}{3^{n-1}})$ 的和。**  

    由几何级数 $\sum\limits_{n=1}^{\infty}\frac{1}{2^{n-1}}$ 和 $\sum\limits_{n=1}^{\infty}\frac{1}{3^{n-1}}$ 收敛，可得：  
    $\sum\limits_{n=1}^{\infty}(\frac{1}{2^{n-1}}+\frac{1}{3^{n-1}})=\sum\limits_{n=1}^{\infty}\frac{1}{2^{n-1}}+\sum\limits_{n=1}^{\infty}\frac{1}{3^{n-1}}=\frac{7}{2}$  

**加法结合律：**

若 $\sum x_n$ 收敛，则在其求和表达式中任意添加括号，得到的新级数一定收敛，且其和不变，新的级数的部分和数列是原来级数的部分和数列的子列。

若添加括号得到的新级数收敛，不能保证原级数一定收敛。 

***

## 1.2 正项级数

### 正项级数的相关定义

**正项级数：**

设级数 $\sum x_n$ 满足：$\forall n\geqslant 1$，有 $x_n\geqslant 0$，则称该级数为**正项级数**。  

**正项级数的收敛原理：**

正项级数的部分和数列单调递增，因此 $\sum x_n$ 收敛当且仅当 $\\{S_n\\}$ 有上界。（单调有界数列必收敛）

### 正项级数敛散性的判别

**比较判别法：**

**一般形式：**

给定正项级数 $\sum x_n$ 和 $\sum y_n$ ，且 $\exists N_0\in N^{\*}$，对于 $\forall n>N_0$，有 $x_n\leqslant Ay_n$，其中 $A$ 为正实数，则： 

* 若 $\sum y_n$ 收敛，则 $\sum x_n$ 收敛  
* 若 $\sum x_n$ 发散，则 $\sum y_n$ 发散  

**极限形式：**

给定正项级数 $\sum x_n$ 和 $\sum y_n$ ，且 $\exists N_0\in N^{\*}$，对于 $\forall n>N_0$，有 $y_n\neq 0$. 若 $\lim\limits_{n\rightarrow \infty}\frac{x_n}{y_n}=c$，则：  

* 若 $c\in (0,+\infty)$，则 $\sum x_n$ 和 $\sum y_n$ 具有相同的敛散性  
* 若 $c=0$，则 $\sum y_n$ 收敛时，$\sum x_n$ 收敛；$\sum x_n$ 发散时，$\sum y_n$ 发散  
* 若 $c=+\infty$，则 $\sum x_n$ 收敛时，$\sum y_n$ 收敛；$\sum y_n$ 发散时，$\sum x_n$ 发散  

!!! Example
    **例1：判断 $\sum 2^n\sin\frac{\pi}{3^n}$ 的敛散性。**  

    $\frac{2^n\sin\frac{\pi}{3^n}}{(\frac{2}{3})^n}=\pi·\frac{\sin \frac{\pi}{3^n}}{\frac{\pi}{3^n}}\stackrel{n\rightarrow \infty}\longrightarrow \pi·1=\pi$  
    $ \sum (\frac{2}{3})^n$ 收敛  
    由比较判别法可得：$\sum 2^n\sin\frac{\pi}{3^n}$ 收敛  

!!! Example
    **例2：判断 $\sum(e^{\frac{1}{n^2}}-\cos\frac{\pi}{n})$ 的敛散性。**   

    由Taylor公式：  
    $e^x=1+x+o(x)$，$x\rightarrow 0$  
    $\cos x=1-\frac{x^2}{2}+o(x^2)$，$x\rightarrow 0$  
    $e^{\frac{1}{n^2}}=1+\frac{1}{n^2}+o(\frac{1}{n^2})$，$n\rightarrow \infty$  
    $\cos \frac{\pi}{n}=1-\frac{\pi^2}{2n^2}+o(\frac{\pi^2}{n^2})$，$n\rightarrow \infty$  
    $\frac{e^{\frac{1}{n^2}}-\cos\frac{\pi}{n}}{\frac{1}{n^2}}=\frac{\frac{1}{n^2}(1-\frac{\pi^2}{2})+o(\frac{1}{n^2})}{\frac{1}{n^2}}\stackrel{n\rightarrow \infty}\longrightarrow1-\frac{\pi^2}{2}$  
    $\sum \frac{1}{n^2}$ 收敛  
    由比较判别法可得：$\sum(e^{\frac{1}{n^2}}-\cos\frac{\pi}{n})$ 收敛  

!!! Example
    **例3：判断$\sum(\sqrt[n]{a}-1)$的敛散性。**  

    $a^x=e^{\ln a·x}$  
    代入 $e^x$ 的Taylor公式得：$a^{\frac{1}{n}}=1+\frac{\ln a}{n}+o(\frac{1}{n})$，$n\rightarrow \infty$  
    $\frac{\sqrt[n]{a}-1}{\frac{1}{n}}=\frac{\frac{\ln a}{n}+o(\frac{1}{n})}{\frac{1}{n}}\stackrel{n\rightarrow \infty}\longrightarrow \ln a$  
    $\sum \frac{1}{n}$ 发散  
    由比较判别法可得：$\sum(\sqrt[n]{a}-1)$ 发散  

**根式判别法：**

给定正项级数 $\sum x_n$，若 $\lim\limits_{n\rightarrow \infty}\sqrt[n]{x_n}=r$，则： 

* 若 $r\in [0,1)$，则 $\sum x_n$ 收敛  
* 若 $r>1$，则 $\sum x_n$ 发散  
* 若 $r=1$，则 $\sum x_n$ 可能收敛（$\sum \frac{1}{n^2}$），也可能发散（$\sum \frac{1}{n}$）  

!!! Example
    **例：判断 $\sum n^2e^{-n}$ 的敛散性。**  

    $\lim\limits_{n \rightarrow \infty}\sqrt[n]{n^2e^{-n}}=\lim\limits_{n \rightarrow \infty}\frac{\sqrt[n]{n^2}}{e}=\frac{1}{e}\in(0,1)$  
    由根式判别法可得：$\sum n^2e^{-n}$ 收敛  
    （解题技巧：看到**n次方**要想到**根式判别法**）   

**比式判别法：**

给定正项级数 $\sum x_n$，若 $\lim\limits_{n \rightarrow \infty}\frac{x_{n+1}}{x_n}=r$，则：

* 若 $r\in [0,1)$，则 $\sum x_n$ 收敛  
* 若 $r>1$，则 $\sum x_n$ 发散  
* 若 $r=1$，则 $\sum x_n$ 可能收敛（$\sum \frac{1}{n^2}$），也可能发散（$\sum \frac{1}{n}$）  

!!! Example
    **例：判断$\sum \frac{n^n}{3^nn!}$的敛散性。**  

    令 $x_n=\frac{n^n}{3^nn!}$  
    $\lim\limits_{n \rightarrow \infty}\frac{x_{n+1}}{x_n}=\lim\limits_{n \rightarrow \infty}\frac{(1+\frac{1}{n})^n}{3}=\frac{e}{3}\in(0,1)$  
    由比式判别法可得：$\sum \frac{n^n}{3^nn!}$ 收敛   
    （解题技巧：看到**阶乘**要想到**比式判别法**）  

!!! Note
    若一个正项级数的敛散性可以用比式判别法判定，则其一定可以用根式判别法判定； 
    反之，若一个正项级数的敛散性可以用根式判别法判定，则其未必可以用比式判别法判定。  
    因此，根式判别法的适用范围比比式判别法更广。  

**积分判别法：**

若 $f(x)$ 是定义在 $[N_0,+\infty)$ 上的非负递减函数，则：  

$\int_{N_0}^{+\infty}f(x)dx$ 收敛 $\Longleftrightarrow$ $\sum\limits_{n=N_0}^{\infty}f(n)$ 收敛，即 $\sum x_n$ 收敛（前有限项不影响）  

!!! Tip "Proof"
    **左推右：**  

    由 $\int_{N_0}^{+\infty}f(x)dx$ 收敛，可得  
    $F(x)=\int_{N_0}^{x}f(t)dt$ 在 $[N_0,+\infty)$ 上有上界 $M$  
    $f(x)$ 非负递减  
    $f(n+1)\leqslant\int_{n}^{n+1}f(x)dx\leqslant f(n)$  
    $\sum\limits_{k=N_0}^{n}f(k)\leqslant \sum\limits_{k=N_0}^{n-1}[\int_{k}^{k+1}f(x)dx]+f(N_0)=\int_{N_0}^{n}f(x)dx+f(N_0)\leqslant M+f(N_0)$  
    $\sum\limits_{k=N_0}^{n}f(k)$ 有上界，其为 $\sum\limits_{n=N_0}^{\infty}f(n)$ 部分和  
    因此 $\sum\limits_{n=N_0}^{\infty}f(n)$ 收敛，即 $\sum x_n$ 收敛  

    **右推左：**  

    由 $\sum\limits_{n=N_0}^{\infty}f(n)$ 收敛，可得  
    $\sum\limits_{k=N_0}^{n}f(k)$ 有上界 $M$  
    $f(n+1)\leqslant\int_{n}^{n+1}f(x)dx\leqslant f(n)$  
    $\forall n\geqslant N_0$，有 $\int_{N_0}^{n+1}f(x)dx=\sum\limits_{k=N_0}^{n}\int_{k}^{k+1}f(x)dx\leqslant \sum\limits_{k=N_0}^{n+1}f(k)\leqslant M$  
    $\forall x\geqslant N_0$，有 $F(x)=\int_{N_0}^{x}f(t)dt\leqslant \int_{N_0}^{[x]+1}f(t)dt\leqslant M$  
    $F(x)$ 有上界，$\int_{N_0}^{+\infty}f(x)dx$ 收敛  

!!! Example
    **例1：讨论p级数 $\sum\frac{1}{n^p}$ 的敛散性。（$p\in R$）**  

    当 $p<0$ 时，$\frac{1}{n^p}$ 发散，级数发散  
    当 $p\geqslant 0$ 时  
    令 $f(x)=\frac{1}{x^p}$  
    $\int_{1}^{+\infty}f(x)dx$ 收敛当且仅当 $p>1$  
    由积分判别法可得：p级数收敛当且仅当 $p>1$  

!!! Example
    **例2：证明：反常积分 $\int_{0}^{+\infty}\frac{dx}{1+x^2\sin^2x}$ 发散。**  

    设 $x_n=\int_{n\pi}^{(n+1)\pi}\frac{dx}{1+x^2\sin^2x}=\int_{0}^{\pi}\frac{dt}{1+(n\pi+t)^2\sin^2t}\geqslant\int_{0}^{\frac{1}{(n+1)\pi}}\frac{dt}{1+(n\pi+t)^2\sin^2t}$  
    当 $0<t<\frac{1}{(n+1)\pi}$ 时  
    $(n\pi+t)^2\sin^2t<(n\pi+t)^2t^2<(n\pi+\pi)^2t^2=(n+1)^2\pi^2t^2<1$  
    $x_n>\int_0^{\frac{1}{(n+1)\pi}}\frac{dt}{2}=\frac{1}{2\pi(n+1)}$  
    已知 $\sum\frac{1}{2\pi(n+1)}$ 发散  
    由比较判别法和积分判别法：原反常积分发散  

!!! Example
    **例3：讨论$\sum\limits_{n=2}^{\infty}\frac{1}{n^p(\ln n)^q}$的敛散性。（$p,q\in R$）** 

    * 当 $p>1$ 时  
    $\lim\limits_{n \rightarrow \infty}\frac{\frac{1}{n^p(\ln n)^q}}{\frac{1}{n^{\frac{p+1}{2}}}}=\lim\limits_{n \rightarrow \infty}\frac{\frac{1}{(\ln n)^q}}{n^{\frac{p-1}{2}}}\stackrel{n \rightarrow \infty}\longrightarrow0$  
    由 $\frac{p+1}{2}>1$ 可得 $\sum\frac{1}{n^{\frac{p+1}{2}}}$ 收敛  
    由比较判别法可得：$\sum\frac{1}{n^p(\ln n)^q}$收敛  

    * 当 $p<1$ 时  
    $\lim\limits_{n \rightarrow \infty}\frac{\frac{1}{n^p(\ln n)^q}}{\frac{1}{n^{\frac{p+1}{2}}}}=\lim\limits_{n \rightarrow \infty}\frac{1}{(\ln n)^q}·{n^{\frac{1-p}{2}}}\stackrel{n \rightarrow \infty}\longrightarrow+\infty$  
    由 $\frac{p+1}{2}<1$ 可得 $\sum\frac{1}{n^{\frac{p+1}{2}}}$ 发散  
    由比较判别法可得：$\sum\frac{1}{n^p(\ln n)^q}$ 发散  

    * 当 $p=1$ 时  
    令 $f(x)=\frac{1}{x(\ln x)^q}$  
    经求导可得：$\forall q\in R,\exists x_0>2$，当 $x>x_0$ 时，$f(x)$ 非负递减  
    $\int_{2}^{+\infty}f(x)dx=\int_{2}^{+\infty}\frac{1}{(\ln x)^q}d(\ln x)$  
    $\int_{2}^{+\infty}f(x)dx$ 收敛当且仅当 $q>1$  
    由积分判别法：$\sum\limits_{n=2}^{\infty}\frac{1}{n^p(\ln n)^q}$ 收敛当且仅当 $q>1$  

***

## 1.3 任意项级数

### 任意项级数敛散性的判别

**Leibiniz判别法：**

若级数 $\sum x_n$ 满足：

$$\forall n\geqslant1,~x_n=(-1)^{n+1}u_n,~u_n>0$$ 

则该级数为**交错级数**。  

若交错级数 $\sum (-1)^{n+1}u_n$ 满足 $\\{u_n\\}$ 单调递减且趋于零，则该级数收敛。  

!!! Tip "Proof" 
    $|x_{n+1}+x_{n+2}+···+x_{n+p}|=|(-1)^{n+2}u_{n+1}+(-1)^{n+3}u_{n+2}+···+(-1)^{n+p+1}u_{n+p}|$  
    $=|u_{n+1}-u_{n+2}+···+(-1)^{p+1}u_{n+p}|$  
    当$p$为奇数时  
    $u_{n+1}-u_{n+2}+···+(-1)^{p+1}u_{n+p}=\begin{cases}  
    (u_{n+1}-u_{n+2})+···+(u_{n+p-2}-u_{n+p-1})+u_{n+p}>0\\\  
    u_{n+1}-(u_{n+2}-u_{n+3})-···-(u_{n+p-1}-u_{n+p})\leqslant u_{n+1}  
    \end{cases}$  
    当$p$为偶数时  
    $u_{n+1}-u_{n+2}+···+(-1)^{p+1}u_{n+p}=\begin{cases}  
    (u_{n+1}-u_{n+2})+···+(u_{n+p-1}-u_{n+p})\geqslant 0\\\  
    u_{n+1}-(u_{n+2}-u_{n+3})-···-(u_{n+p-2}-u_{n+p-1})-u_{n+p}<u_{n+1}  
    \end{cases}$  
    因此：$|u_{n+1}-u_{n+2}+···+(-1)^{p+1}u_{n+p}|\leqslant u_{n+1}$  
    由于 $\lim\limits_{n\rightarrow\infty}u_n=0$  
    于是 $|x_{n+1}+x_{n+2}+···x_{n+p}|$ 趋于0，原级数收敛  

**Abel引理：**

已知数列 $\\{a_n\\},\\{b_n\\}$，$\\{a_n\\}$ 单调  
令 

$$a^{\*}=\max\\{|a_1|,···,|a_n|\\}$$

$$B^{\*}=\max\\{|B_1|,···,|B_n|\\}$$  

其中 

$$B_n=\sum\limits_{i=1}^nb_i$$  

则 

$$|a_1b_1+···+a_nb_n|\leqslant 3a^{\*}B^{\*}$$  

!!! Tip "Proof"  
    如上所设  
    $a_1b_1+···+a_nb_n$  
    $=a_1B_1+a_2(B_2-B_1)+···+a_n(B_n-B_{n-1})$  
    $=(a_1-a_2)B_1+(a_2-a_3)B_2+···+(a_{n-1}-a_n)B_{n-1}+a_nB_n$  
    $|a_1b_1+···+a_nb_n|\leqslant|a_1-a_2||B_1|+···+|a_{n-1}-a_n||B_{n-1}|+|a_n||B_n|$  
    $\leqslant (|a_1-a_2|+|a_2-a_3|+···+|a_{n-1}-a_n|+|a_n|)B^{\*}$  
    由于 $\\{a_n\\}$ 单调  
    $|a_1b_1+···+a_nb_n|\leqslant (|a_1-a_n|+|a_n|)B^*\leqslant3a^{\*}B^{\*}$  

**A-D判别法:**

若以下两个条件之一成立，则级数 $\sum a_nb_n$ 收敛：  

* **Abel判别法：**$\\{a_n\\}$ 单调有界，$\sum b_n$ 收敛  
* **Dirichlet判别法：**$\\{a_n\\}$ 单调趋于0，$\{\sum\limits_{i=1}^{n}b_i\}$ 有界  

!!! Tip "Proof"  
    **Dirichlet判别法:**  

    由于 $\sum b_n$ 的部分和数列有界  
    所以 $\exists M>0$，使得：$\forall n\geqslant 1$，有 $|\sum\limits_{i=1}^nb_i|\leqslant M$  
    对于 $\forall m,n\geqslant1$ 有 $|\sum\limits_{i=n+1}^{n+m}b_i|=|\sum\limits_{i=1}^{n+m}b_i-\sum\limits_{i=1}^nb_i|\leqslant 2M$  
    由于 $\\{a_n\\}$ 单调趋于0  
    所以 $\forall\varepsilon>0$，$\exists N\in N^{\*}$，当 $n>N$ 时有 $|a_n|<\frac{\varepsilon}{6M}$  
    当 $n>N$ 时，对于 $\forall m\geqslant 1$，由Abel引理，有 $|\sum\limits_{i=n+1}^{n+m}a_ib_i|<3·\frac{\varepsilon}{6M}·2M=\varepsilon$  
    （注意：Abel判别法不一定要从第一项开始）  
    由Cauchy收敛准则：原级数收敛  

    **Abel判别法:**  

    由 $\\{a_n\\}$ 单调有界可得  $\\{a_n\\}$收敛，极限记为 $A$  
    $\sum a_nb_n=\sum[(a_n-A)b_n+Ab_n]$  
    $\sum b_n$ 收敛  
    $\sum Ab_n$ 收敛  
    $\\{a_n-A\\}$ 单调趋于0且 $\sum b_n$ 的部分和数列有界  
    由Dirichlet判别法：$\sum (a_n-A)b_n$ 收敛  
    原级数收敛  

### 绝对收敛与条件收敛

**绝对收敛与条件收敛：**

给定任意项级数 $\sum x_n$，可定义新级数 $\sum|x_n|$: 

* 若 $\sum |x_n|$ 收敛，则 $\sum x_n$ 也收敛，称为**绝对收敛**  
* 若 $\sum x_n$ 收敛，但 $\sum|x_n|$ 发散，则称为**条件收敛**  

!!! Example
    **例：讨论级数 $\sum \frac{x^n}{n^p}$ 的敛散性。**  

    $\lim\limits_{n\rightarrow \infty}\sqrt[n]{\frac{|x|^n}{n^p}}=|x|$ 
 
    * 若 $|x|<1$  
    由根式判别法：对于 $\forall p$ 都有 $\sum |\frac{x^n}{n^p}|$ 收敛，原级数绝对收敛  

    * 若 $|x|>1$  
    对于 $\forall p$ 都有 $\lim\limits_{n\rightarrow \infty}\frac{x^n}{n^p}\neq 0$  
    原级数发散  

    * 若 $x=1$  
    原级数为 $\sum \frac{1}{n^p}$  
    当 $p>1$ 时原级数绝对收敛  
    当 $p\leqslant 1$ 时原级数发散  

    * 若 $x=-1$  
    原级数为 $\sum (-1)^n\frac{1}{n^p}$  
    当 $p>1$ 时原级数绝对收敛  
    当 $0< p\leqslant1$  时原级数条件收敛  
    当 $p\leqslant 0$时原级数发散  

!!! Note  
    一般说来，由 $\sum|x_n|$ 发散并不能得出 $\sum x_n$ 发散，但若用根式判别法或比式判别法判断出 $\sum|x_n|$ 发散，则级数 $\sum x_n$ 本身一定发散，这是因为两个判别法判定发散的依据是级数的通项不趋于0，即不满足级数收敛的必要条件。 

**$\sum x_n^+$ 和 $\sum x_n^-$：**  

给定任意项级数 $\sum x_n$  
令 

$$x_n^+=\frac{x_n+|x_n|}{2}=\begin{cases}  
x_n,~~~~~x_n\geqslant 0\\\  
0,~~~~~~~x_n<0  
\end{cases}$$

令 

$$x_n^-=\frac{|x_n|-x_n}{2}=\begin{cases}  
0,~~~~~~~x_n\geqslant 0\\\  
-x_n,~~~x_n<0  
\end{cases}$$

则 

$$x_n^++x_n^-=|x_n|$$

$$x_n^+-x_n^-=x_n$$  

* **性质一：** 若 $\sum x_n$ 绝对收敛，则 $\sum x_n^+$ 和 $\sum x_n^-$ 也绝对收敛  

!!! Tip "Proof" 
    $0 \leqslant x_n^+\leqslant |x_n|$  
    $0 \leqslant x_n^-\leqslant |x_n|$  
    由比较判别法即可得证  

* **性质二：** 若 $\sum x_n$ 条件收敛，则 $\sum x_n^+$ 和 $\sum x_n^-$ 均发散  

!!! Tip "Proof"  
    不妨设  $\sum x_n^+$收敛  
    由 $x_n^+-x_n^-=x_n$ 可得 $\sum x_n^-$ 收敛  
    又由 $x_n^++x_n^-=|x_n|$ 可得 $\sum |x_n|$ 收敛，矛盾  

### 级数的重排

**绝对收敛级数的加法交换律：**

若级数 $\sum x_n$ 绝对收敛，则它重排后的更序级数 $\sum x_n'$ 也绝对收敛，且和不变。  

!!! Tip "Proof"  
    设 $x_n'=x_{\varphi(n)}$  
    只需证 $\sum x_{\varphi(n)}$ 收敛且和不变  
    （因为 $\sum |x_{\varphi(n)}|$ 是 $\sum|x_n|$ 的重排） 
    令 $S_n=\sum\limits_{k=1}^nx_k$，$S_n'=\sum\limits_{k=1}^nx_{\varphi(k)}$  
    由 $\sum x_n$ 绝对收敛得：  
    $\forall \varepsilon>0$，$\exists N\in N^{\*}$，当 $n>N$ 时，对于 $\forall p\in Z^+$ 有 $|x_{n+1}|+···+|x_{n+p}|<\varepsilon$  
    令 $n^{\*}=\max\\{\varphi(1),···,\varphi(n)\\}$  
    则 $n^{\*}\geqslant n \geqslant N$  
    $|S_n'-S_n|=|(S_n'-S_N)-(S_n-S_N)|$  
    $\leqslant |S_n'-S_N|+|S_n-S_N|$  
    $|S_n'-S_N|=|x_{\varphi(1)}+···+x_{\varphi(n)}-x_1-···-x_N|$  
    $\leqslant |x_1+···+x_{n^{\*}}-x_1-···-x_N|$  
    $\leqslant |x_{N+1}+···+x_{n^{\*}}|$  
    $\leqslant \sum\limits_{k=N+1}^{n^{\*}}|x_k|$  
    $< \varepsilon$  
    $|S_n-S_N|\leqslant \sum\limits_{k=N+1}^n|x_k|< \varepsilon$  
    因此 $|S_n'-S_n|< 2\varepsilon$  
    $\lim\limits_{n\rightarrow \infty}S_n=\lim\limits_{n\rightarrow \infty}S_n'$  
    $\sum x_{\varphi(n)}$ 收敛，和不变  
    综上：更序级数绝对收敛且和不变  

**Riemann定理：**

若 $\sum x_n$ 条件收敛，则对于任意给定的 $a$，$-\infty \leqslant a\leqslant+\infty$，必定存在 $\sum x_n$ 的更序级数 $\sum x_n'$ 满足：

$$\sum x_n'=a$$

### 级数的乘法

**Cauchy乘积与正方形乘积：**

给定级数 $\sum a_n, \sum b_n$，设 

$$c_n=a_1b_n+a_2b_{n-1}+···+a_{n-1}b_2+a_nb_1=\sum\limits_{k=1}^na_kb_{n+1-k},~n\geqslant 1$$

称 $\sum c_n$为$\sum a_n$ 和 $\sum b_n$ 的**Cauchy乘积**。  

给定级数 $\sum a_n, \sum b_n$，设 

$$c_n=a_1b_n+a_2b_n+···+a_nb_n+a_nb_{n-1}+a_nb_{n-2}+···+a_nb_1,~n\geqslant 1$$

称 $\sum c_n$ 为 $\sum a_n$ 和 $\sum b_n$ 的**正方形乘积**。  

**Cauchy定理：**

若 $\sum x_n$ 和 $\sum y_n$ 绝对收敛，和分别为 $A$，$B$，则对于所有乘积 $x_iy_j$ 按任意顺序排列所得到的级数 $\sum c_n$ 也绝对收敛，且其和为 $AB$。  

!!! Tip "Proof"
    设 $c_n=a_{i_n}b_{j_n}$  
    $\forall n\geqslant 1$，令 $N=\max\\{i_1,···,i_n,j_1,···,j_n\\}$  
    $\sum\limits_{k=1}^n|c_k|=\sum\limits_{k=1}^n|a_{i_k}||b_{j_k}|\leqslant(\sum\limits_{k=1}^N|a_k|)(\sum\limits_{k=1}^N|b_k|)\leqslant(\sum\limits_{k=1}^{\infty}|a_k|)(\sum\limits_{k=1}^{\infty}|b_k|)$  
    右式为确定的实数  
    即 $\sum\limits_{k=1}^n|c_k|$ 有界  
    由于 $\sum\limits_{k=1}^n|c_k|$ 单调  
    可得 $\sum\limits_{k=1}^n|c_k|$ 收敛  
    $\sum c_n$ 绝对收敛  
    接下来只需证 $\sum c_n=AB$  
    由于绝对收敛的级数的重排、加括号都不改变级数的和  
    因此只需证某一特殊情况成立  
    考虑正方形序列  
    $\sum\limits_{k=1}^nc_k=(\sum\limits_{k=1}^na_k)(\sum\limits_{k=1}^nb_k)\longrightarrow AB (n\rightarrow \infty)$  
    因此 $\sum c_n=AB$  

!!! Example
    **例1：考察 $\sum\limits_{n=0}^{\infty} r^n$ 和 $\sum \limits_{n=0}^{\infty}r^n$ 的Cauchy乘积，其中 $|r|<1$。**  

    由 $|r|<1$ 可知 $\sum\limits_{n=0}^{\infty} r^n$ 绝对收敛  
    令 $\sum\limits_{n=0}^{\infty}c_n$ 为其Cauchy乘积  
    则 $c_n=\sum\limits_{k=0}^nr^k·r^{n-k}=(n+1)r^n, n\geqslant 0$  
    由Cauchy定理：$\sum\limits_{n=0}^{\infty}(n+1)r^n=\sum\limits_{n=0}^{\infty} r^n·\sum\limits_{n=0}^{\infty} r^n=\frac{1}{(1-r)^2}$  

!!! Example
    **例2：考察 $\sum\limits_{n=0}^{\infty} \frac{x^n}{n!}$ 和 $\sum\limits_{n=0}^{\infty} \frac{y^n}{n!}$ 的Cauchy乘积，$x$，$y\in R$。**  

    当 $x\neq 0$ 时  
    由比式判别法：$\sum\limits_{n=0}^{\infty} |\frac{x^n}{n!}|$ 收敛，$\sum\limits_{n=0}^{\infty} \frac{x_n}{n!}$ 绝对收敛  
    （$x=0$时也绝对收敛）  
    $\sum\limits_{n=0}^{\infty} \frac{y^n}{n!}$ 同理  
    令 $\sum\limits_{n=0}^{\infty} c_n$ 为其Cauchy乘积  
    则 $c_n=\sum\limits_{k=0}^n\frac{x^k}{k!}·\frac{y^{n-k}}{(n-k)!}=\frac{1}{n!}\sum\limits_{k=0}^{n} C_n^kx^ky^{n-k}=\frac{(x+y)^n}{n!}$  
    由Cauchy定理：$\sum\limits_{n=0}^{\infty} \frac{(x+y)^n}{n!}=\sum\limits_{n=0}^{\infty} x_n·\sum\limits_{n=0}^{\infty} y_n=e^x·e^y=e^{x+y}$  

**Mertens定理：**

若 $\sum a_n$ 绝对收敛，$\sum b_n$ 收敛，和分别为 $A$，$B$，则其Cauchy乘积也收敛，且其和为 $AB$。  