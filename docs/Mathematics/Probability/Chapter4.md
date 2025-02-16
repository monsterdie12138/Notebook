---
comments: true
---

<span style="font-family: 'Times New Roman';">

# Chapter4 概率极限理论

***

## 4.1 经典概率极限理论

以下三个定理都只涉及Bernoulli随机变量。

$$X\sim B(n,p)$$

$$P(X=k)=C_n^kp^k(1-p)^{n-k}$$

$$EX=np$$

$$Var(X)=np(1-p)$$

### Bernoulli大数律

若$S_n\sim B(n,p)$，则

$$\frac{S_n}{n}\stackrel{P}\rightarrow p$$

即对于$\forall \varepsilon>0$，都有

$$\lim\limits_{n\rightarrow\infty}P(|\frac{S_n}{n}-p|>\varepsilon)=0$$

意义：随着试验次数的增大，事件的频率逐步稳定到事件的概率。

### De Moivre-Laplace中心极限定理

若$S_n\sim B(n,p)$，则

$$\frac{S_n-np}{\sqrt{np(1-p)}}\stackrel{d}\rightarrow N(0,1)$$

即

$$\lim\limits_{n\rightarrow\infty}P(\frac{S_n-np}{\sqrt{np(1-p)}}\leqslant x)=\Phi(x)$$

其中，左边是$S_n$规范化后的分布函数，右边是标准正态分布的分布函数$\int_{-\infty}^x\frac{1}{\sqrt{2\pi}}e^{-\frac{t^2}{2}}dt$。

意义：给出近似计算公式：

$$P(a\leqslant S_n\leqslant b)\asymp\Phi(\frac{b-np}{\sqrt{np(1-p)}})-\Phi(\frac{a-np}{\sqrt{np(1-p)}})$$



### Poisson极限定理

若$S_n\sim B(n,p_n)$，$np_n\rightarrow\lambda$，且$0<\lambda<1$，则对于$\forall k\in N$，都有

$$\lim\limits_{n\rightarrow\infty}P(S_n=k)=\frac{\lambda^k}{k!}e^{-\lambda}$$

!!! Tip "Proof"  
    $P(S_n=k)=\frac{n!}{k!(n-k)!}(\frac{\lambda}{n})^k(1-\frac{\lambda}{n})^k$  
    $=\frac{\lambda^k}{k!}\cdot\frac{n(n-1)(n-2)···(n-k+1)}{n^k}\cdot\frac{(1-\frac{\lambda}{n})^n}{(1-\frac{\lambda}{n})^k}$  
    $\rightarrow\frac{\lambda^k}{k!}\cdot1\cdot\frac{e^{-\lambda}}{1}$，$n\rightarrow\infty$  
    因此，对于二项分布，当$n$很大，$p$很小，而$np$不很大时，可近似取$np=\lambda$，从而将复杂的二项分布计算转换为相对比较简单的Poisson分布计算。

***

## 4.2 经典极限定理的推广

三个定理分别从Bernoulli随机变量推广到任意随机变量。

### Chebyschev大数律

设$\xi_k,k\geqslant 1$是一列随机变量，且$E(\xi_k)=\mu$。记$S_n=\sum\limits_{k=1}^n\xi_k$，若

$$\lim\limits_{n\rightarrow
\infty}\frac{Var(S_n)}{n^2}=0$$

则

$$\frac{S_n}{n}\stackrel{P}\rightarrow\mu$$

更一般地，设$\xi_k,k\geqslant 1$是一列随机变量，且$E(\xi_k)=\mu_k$。记$S_n=\sum\limits_{k=1}^n\xi_k$，若

$$\lim\limits_{n\rightarrow
\infty}\frac{Var(S_n)}{n^2}=0$$

则

$$\frac{S_n}{n}\stackrel{P}\rightarrow\frac{\sum\limits_{k=1}^n\mu_k}{n} $$

意义：样本均值渐近总体均值，且没有独立性要求。

### Khinchine 大数律

设$\xi_k,k\geqslant 1$是一列**独立同分布**的随机变量，且$E(\xi_k)=\mu$。记$S_n=\sum\limits_{k=1}^n\xi_k$，则

$$\frac{S_n}{n}\stackrel{P}\rightarrow\mu$$

### Levy-Feller中心极限定理

设$\xi_k,k\geqslant 1$是一列**独立同分布**的随机变量，且$E(\xi_k)=\mu$，$Var(\xi_k)=\sigma^2$。记$S_n=\sum\limits_{k=1}^n\xi_k$，则

$$\frac{S_n-n\mu}{\sigma\sqrt{n}}\stackrel{d}\rightarrow N(0,1)$$

!!! Example
    **例1：设$\xi_k$是一列独立同分布的随机变量，服从如下分布：**  
    **$P(\xi_k=0)=P(\xi_k=-1)=P(\xi_k=1)=\frac{1}{3}$**  
    **记$S_n=\sum\limits_{k=1}^n\xi_k$，求$P(S_{10000}>100)$。**  

    $E(\xi_k)=0$，$Var(\xi_k)=\frac{2}{3}$  
    $P(S_{10000}>100)=1-P(S_{10000}\leqslant 100)$  
    $=1-P(\frac{S_{10000}}{\sqrt{10000\times\frac{2}{3}}}\leqslant\frac{100}{\sqrt{10000\times\frac{2}{3}}})$  
    $=1-\Phi(\frac{100}{81.65})$  
    $=0.11$  

    **例2：某车间有200台车床，工作时每台车床60%的时间再开动，每台开动时耗电1千瓦，应供给多少电力才能有0.999把握保证正常生产？**  

    $E(\xi_k)=0.6$，$Var(\xi_k)=0.6\times 0.4$  
    $P(S_{200}<x)=0.999$  
    $P(S_{200}<x)=P(\frac{S_{200}-200\times 0.6}{\sqrt{200\times 0.6\times 0.4}}<\frac{x-200\times 0.6}{\sqrt{200\times 0.6\times 0.4}})$  
    $=\Phi(\frac{x-120}{\sqrt{48}})$  
    $=0.999$  
    $x\approx 141$  
    应供电141千瓦。  

### Lyapunov中心极限定理

设$\xi_k,k\geqslant 1$是一列**独立**的随机变量（**不一定同分布**），且$E(\xi_k)=\mu_k$，$Var(\xi_k)=\sigma_k^2$，记$S_n=\sum\limits_{k=1}^n\xi_k$，若$\exists\delta>0$，使得

$$\lim\limits_{n\rightarrow\infty}\frac{\sum\limits_{k=1}^nE(|\xi_k-\mu_k|^{2+\delta})}{(\sum\limits_{k=1}^n\sigma_k^2)^{1+\frac{\delta}{2}}}=0$$

则

$$\frac{S_n-\sum\limits_{k=1}^{n}\mu_k}{\sqrt{\sum\limits_{k=1}^n\sigma_k^2}}\stackrel{d}\rightarrow N(0,1)$$

***

## 4.3 随机变量的收敛性

### 依概率收敛

$(\Omega,\Sigma,P)$是一个概率空间，$X$和$X_n,n\geqslant1$是随机变量，若对于$\forall\varepsilon>0$，都有

$$\lim\limits_{n\rightarrow\infty}P(|X_n-X|>\varepsilon)=0$$

则称$X_n$**依概率收敛**到$X$，记作

$$X_n\stackrel{P}\rightarrow X$$

**极限唯一性：**

若$X_n\stackrel{P}\rightarrow X$，$X_n\stackrel{P}\rightarrow Y$，则

$$P(X=Y)=1$$

**判别法则：**

若$\exists r>0$，使得

$$\lim\limits_{n\rightarrow\infty}E(|X_n-X|^r)=0$$

则

$$X_n\stackrel{P}\rightarrow X$$

**运算性质：**

若$X_n\stackrel{P}\rightarrow X$，$Y_n\stackrel{P}\rightarrow Y$，则

* $X_n\pm Y_n\stackrel{P}\rightarrow X\pm Y$
* $X_n\cdot Y_n\stackrel{P}\rightarrow X\cdot Y$
* 若$P(Y\neq 0)=1$，则$\frac{X_n}{Y_n}\stackrel{P}\rightarrow\frac{X}{Y}$
* 若$f:R\mapsto R$是连续映射，则$f(X_n)\stackrel{P}\rightarrow f(X)$

!!! Example
    **设$\xi_k$独立同分布，服从$[0,1]$上的均匀分布，记$\eta_n=(\prod\limits_{k=1}^n\xi_k)^{\frac{1}{n}}$，求证：$\eta_n\stackrel{P}\rightarrow C$，$n\rightarrow \infty$。**  

    $\log\eta_n=\frac{1}{n}\sum\limits_{k=1}^n\log\xi_k$  
    由Chebyschev大数律：  
    $\frac{1}{n}\sum\limits_{k=1}^n\log\xi_k\stackrel{P}\rightarrow E(\log\xi_1)=\int_0^1\log xdx=-1$  
    因此$\log \eta_n\stackrel{P}\rightarrow-1$  
    $\eta_n=e^{\log\eta_n}\stackrel{P}\rightarrow e^{-1}$  
    **几何平均与算数平均的关系**  

### 依分布收敛

$(\Omega,\Sigma,P)$是一个概率空间，$X$和$X_n,n\geqslant1$是随机变量，$F$，$F_n,n\geqslant 1$是对应的分布函数，若对于$F$的任意**连续点**$x$

$$F_n(x)\rightarrow F(x)$$

则称$X_n$**依分布收敛**到$X$，记作

$$X_n\stackrel{d}\rightarrow X$$

**依概率收敛和依分布收敛的关系：**

依概率收敛意味着依分布收敛；依分布收敛并不意味着依概率收敛。

**判别法则：Levy连续性定理**

设$X,X_n$是一列随机变量，具有特征函数$\varphi,\varphi_n$，则

$$X_n\stackrel{d}\rightarrow X\Leftrightarrow \varphi_n(t)\rightarrow\varphi(t)$$

另一种形式：

设$X_n$是一列随机变量，具有特征函数$\varphi_n(t)$，若

$$\varphi(t)\rightarrow\varphi(t),~\forall t\in R$$

且$\varphi$在0处连续，则$\varphi$一定是特征函数，对应的随机变量为$X$，那么

$$X_n\stackrel{d}\rightarrow X$$

**运算性质：**

若$X_n\stackrel{d}\rightarrow X$，$a_n\rightarrow a$，$b_b\rightarrow b$，则

$$a_nX_n+b_n\stackrel{d}\rightarrow aX+b$$

若$X_n\stackrel{d}\rightarrow X$，$Y_n\stackrel{P}\rightarrow c$，则

$$X_n\cdot Y_n\stackrel{d}\rightarrow cX$$

若$f$是连续映射，$X_n\stackrel{d}\rightarrow X$，则

$$f(X_n)\stackrel{d}\rightarrow f(X)$$

!!! Example

    **设$\xi_k$是一列独立同分布的随机变量，$P(\xi_k=\pm 1)=\frac{1}{2}$。定义$U_n=\sum\limits_{k=1}^n\frac{\xi_k}{2^k}$，求证：$U_n\stackrel{d}\rightarrow U\sim U(-1,1)$。**

    计算$U_n$的特征函数。  
    $\varphi_n(t)=E(e^{itU_n})$  
    $=\prod\limits_{k=1}^E(e^{it\frac{\xi_k}{2^k}})$  
    $=\prod\limits_{k=1}^n[\frac{1}{2}(e^{\frac{it}{2^k}}+e^{-\frac{it}{2^k}})]$  
    $=\prod\limits_{k=1}^n\cos(\frac{t}{2^k})$  
    $=\frac{1}{\sin(\frac{t}{2^n})}\prod\limits_{k=1}^n\cos(\frac{t}{2^k})\cdot \sin(\frac{t}{2^n})$  
    $=\frac{\sin t}{2^n\sin(\frac{t}{2^n})}\rightarrow\frac{\sin t}{t}$  
    计算$U$的特征函数。  
    $\varphi(t)=E(e^{itU})=\frac{1}{2}\int_{-1}^1e^{itx}dx=\frac{\sin t}{t}$  
    因此  
    $\lim\limits_{n\rightarrow\infty}\varphi_n(t)=\varphi(t)$  
    由Levy连续性定理：$U_n\stackrel{d}\rightarrow U$  

### 几乎处处收敛

$(\Omega,\Sigma,P)$是一个概率空间，$X$和$X_n,n\geqslant1$是随机变量，若存在$\Omega_0$使得：

* $P(\Omega_0)=0$
* 对$\forall\omega\in\Omega-\Omega_0$，都有$\lim\limits_{n\rightarrow\infty}X_n(\omega)\rightarrow X(\omega)$

则称$X_n$**几乎处处收敛**到$X$，记作

$$X_n\stackrel{a.s.}\rightarrow X$$

**判别法则：**

$X_n\stackrel{a.s.}\rightarrow X$当且仅当对于$\forall\varepsilon>0$，都有

$$\lim\limits_{N\rightarrow\infty}P(\bigcup\limits_{n=N}^{\infty}\{|X_n(\omega)-X(\omega)|>\varepsilon\})=0$$

**几乎处处收敛**强于**依概率收敛**强于**依分布收敛**。

**Borel大数律：**

设$\xi_k,k\geqslant 1$是一列**独立同分布**的随机变量，且$P(\xi_k=1)=p$，$P(\xi_k=0)=1-p$。记$S_n=\sum\limits_{k=1}^n\xi_k$，则

$$\frac{S_n}{n}\stackrel{a.s.}\rightarrow p$$

**Kolmogorov强大数律：**

设$\xi_k,k\geqslant 1$是一列**独立同分布**的随机变量，且$E(\xi_k)=\mu$。记$S_n=\sum\limits_{k=1}^n\xi_k$，则

$$\frac{S_n}{n}\stackrel{a.s.}\rightarrow\mu$$