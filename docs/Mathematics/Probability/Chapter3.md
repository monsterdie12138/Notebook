---
comments: true
---

<span style="font-family: 'Times New Roman';">

# Chapter3 数字特征

***

## 3.1 数学期望

### 数学期望的定义

#### 离散型随机变量

$$X\sim\begin{pmatrix}
    x_1&x_2&···&x_N\\\
    p_1&p_2&···&p_N
\end{pmatrix}$$

$$EX=\sum\limits_{k=1}^Nx_kp_k$$

!!! Note
    当$N\rightarrow\infty$时，要求绝对可和，即$\sum\limits_{k=1}^{\infty}|x_k|p_k$存在。  

**二项Bernoulli分布：$X\sim B(n,p)$**

$$P(X=k)=C_n^kp^k(1-p)^{n-k}$$

$$EX=np$$

**Poisson分布：$X\sim P(\lambda)$**

$$P(X=k)=\frac{\lambda^k}{k!}e^{-\lambda}$$

$$EX=\lambda$$

**几何分布：$X\sim G(p)$**

$$P(X=k)=p(1-p)^{k-1}$$

$$EX=\frac{1}{p}$$

#### 连续型随机变量

$$X\sim p(x)$$

$$EX=\int_{-\infty}^{+\infty}xp(x)dx$$

!!! Note
    要求绝对可积，即$\int_{-\infty}^{+\infty}|x|p(x)dx$存在。

**正态分布：$X\sim N(\mu,\sigma^2)$**

$$p(x)=\frac{1}{\sqrt{2\pi}\sigma}e^{-\frac{(x-\mu)^2}{2\sigma^2}}$$

$$EX=\mu$$

**指数分布：$X\sim\exp(\lambda)$**

$$p(x)=\lambda e^{-\lambda x}$$

$$EX=\frac{1}{\lambda}$$

**柯西分布：$X\sim C(\mu,\sigma)$**

$$p(x)=\frac{1}{\pi\sigma}\frac{1}{1+(\frac{x-\mu}{\sigma})^2}$$

$EX$不存在。

### 数学期望的性质

**性质1：**

$$E(a+bX)=a+bEX$$

**性质2：**

$$E(X+Y)=EX+EY$$

!!! note
    $X$和$Y$无论是否相互独立，上式均成立。

!!! Tip "Proof"
    若$(X,Y)\sim p(x,y)$  
    $p_Z(z)=\int_{-\infty}^ {+\infty}p(x,z-x)dx$  
    $E(X+Y)=\int_{-\infty}^{+\infty}zp_{Z}(z)dz$  
    $=\int_{-\infty}^{+\infty}z(\int_{-\infty}^{+\infty}p(x,z-x)dx)dz$  
    $=\int_{-\infty}^{+\infty}\int_{-\infty}^{+\infty}(x+y)p(x,y)dxdy$（令$z=x+y$）  
    $=\int_{-\infty}^{+\infty}\int_{-\infty}^{+\infty}xp(x,y)dxdy+\int_{-\infty}^{+\infty}\int_{-\infty}^{+\infty}yp(x,y)dxdy$  
    $=\int_{-\infty}^{+\infty}xp_X(x)dx+\int_{-\infty}^{+\infty}yp_{Y}(y)dy$
    $=EX+EY$  

推广：

$$E(a_1X_1+a_2X_2+···a_mX_m)=a_1E(X_1)+a_2E(X_2)+···+a_mE(X_m)$$

!!! Example
    **例1：设$X_1,X_2,···,X_m$是非负的独立同分布的随机变量，求$E(\frac{X_1+···+X_k}{X_1+···+X_m})$。**

    由加法定理：$1=E(\frac{X_1+···+X_m}{X_1+···+X_m})=E(\frac{X_1}{X_1+···+X_m})+···+E(\frac{X_m}{X_1+···+X_m})$  
    由独立同分布：$\frac{X_1}{X_1+···+X_m}=···=\frac{X_m}{X_1+···+X_m}$  
    $E(\frac{X_1}{X_1+···+X_m})=···=E(\frac{X_m}{X_1+···+X_m})=\frac{1}{m}$  
    综上：$E(\frac{X_1+···=X_k}{X_1+···+X_m})=\frac{k}{m}$  

    **例2：计算二项分布$S_n\sim B(n,p)$的数学期望。**

    将$n$次试验分别看作独立随机变量  
    $X_i=\begin{cases}
        1,p\\\
        0,1-p
    \end{cases}~i=1,2,···,n$  
    $S_n=\sum\limits_{i=1}^nX_i$  
    $E(S_n)=\sum\limits_{i=1}^nE(X_i)=np$  

    **例3：计算超几何分布$S_n\sim H(N,M,n)$的数学期望。**

    与例2同理：将$n$次抽取分别看作独立随机变量  
    $X_i=\begin{cases}
    1,p\\\
    0,1-p
    \end{cases}~i=1,2,···,n$  
    该情况下$X_i$不相互独立，但加法原则依然适用  
    $S_n=\sum\limits_{i=1}^nX_i$  
    $E(S_n)=\sum\limits_{i=1}^nE(X_i)=np=n\frac{M}{N}$  

**性质3：**

若$X$，$Y$相互独立，则

$$E(XY)=EX\cdot EY$$

### 随机变量函数的数学期望

#### 离散型随机变量的函数

$$P(X=x_k)=p_k$$

$$E[f(X)]=\sum\limits_{k=1}^Nf(x_k)p_k$$

#### 连续型随机变量的函数

$$X\sim p(x)$$

$$E[f(X)]=\int_{-\infty}^{+\infty}f(x)p(x)dx$$

!!! Note
    若$Z=f(X,Y)$，则  
    $EZ=\sum f(x_i,y_j)P(X=x_i,Y=y_j)$（离散型）  
    $EZ=\iint f(x,y)p(x,y)dxdy$（连续型）  

***

## 3.2 方差

### 方差的定义

$$Var(X)=E[(X-EX)^2]=E(X^2)-(EX)^2$$

**二项Bernoulli分布：$X\sim B(n,p)$**

$$P(X=k)=C_n^kp^k(1-p)^{n-k}$$

$$Var(X)=np(1-p)$$

**Poisson分布：$X\sim P(\lambda)$**

$$P(X=k)=\frac{\lambda^k}{k!}e^{-\lambda}$$

$$Var(X)=\lambda$$

**均匀分布：$X\sim U(a,b)$**

$$p(x)=\frac{1}{b-a}$$

$$Var(X)=\frac{(b-a)^2}{12}$$

**指数分布：$X\sim\exp(\lambda)$**

$$p(x)=\lambda e^{-\lambda x}$$

$$Var(X)=\frac{1}{\lambda^2}$$

**正态分布：$X\sim N(\mu,\sigma^2)$**

$$p(x)=\frac{1}{\sqrt{2\pi}\sigma}e^{-\frac{(x-\mu)^2}{2\sigma^2}}$$

$$Var(X)=\sigma^2$$

### 方差的性质

**性质1：**

$$Var(a+bX)=b^2Var(X)$$

**性质2：**

$$Var(X+Y)=Var(X)+Var(Y)+2E[(X-EX)(Y-EY)]$$

若$X$，$Y$相互独立，则

$$Var(X+Y)=Var(X)+Var(Y)$$

推广：若$X_1,X_2,···,X_m$相互独立，则

$$Var(\sum\limits_{k=1}^mX_k)=\sum\limits_{k=1}^mVar(X_k)$$

!!! Example
    **计算二项分布$S_n\sim B(n,p)$的方差。**  
    将$n$次试验分别看作独立随机变量  
    $X_i=\begin{cases}
    1,p\\\
    0,1-p
    \end{cases}~i=1,2,···,n$  
    $S_n=\sum\limits_{i=1}^nX_i$  
    $Var(S_n)=\sum\limits_{i=1}^nVar(X_i)=np(1-p)$  
    此时，若我们想要用同样方法计算超几何分布的方差，则代入的公式就比较麻烦，因为$X_i$并不相互独立。

**性质3：**

当$c\neq EX$时

$$Var(X)<E[(X-c)^2]$$

**性质4：Chebyschev不等式**

对于任意$\varepsilon>0$，都有

$$P(|X-EX|>\varepsilon)\leqslant\frac{Var(X)}{\varepsilon^2}$$

!!! Tip "Proof"
    $P(|X-EX|>\varepsilon)=\int_{x:|x-EX|>\varepsilon}p(x)dx$  
    $\leqslant\int_{x:|x-EX|>\varepsilon}\frac{|x-EX|^2}{\varepsilon^2}p(x)dx$（$\frac{|x-EX|^2}{\varepsilon^2}\geqslant 1$）  
    $\leqslant\frac{1}{\varepsilon^2}\int_{-\infty}^{+\infty}|x-EX|^2p(x)dx$  
    $=\frac{Var(X)}{\varepsilon^2}$  

推广：若$f$是单调不减严格正函数，则

$$P(X>\varepsilon)\leqslant\frac{E[f(X)]}{f(\varepsilon)}$$

!!! Tip "Proof"
    $P(X>\varepsilon)\leqslant P(f(X)>f(\varepsilon))\leqslant\frac{E[f(X)]}{f(\varepsilon)}$  
    前一个不等号是因为$f$是单调不减的，因此当$X>\varepsilon$时，一定有$f(X)>f(\varepsilon)$  

!!! Example
    **证明：若$Var(X)=0$，则$P(X=EX)=1$。**  
    不妨设$EX=0$  
    求证：$P(X=0)=1$  
    即：$P(|X|>0)=0$  
    由切比雪夫不等式，对$\forall\varepsilon>0$，都有  
    $P(|X|>\varepsilon)\leqslant\frac{Var(X)}{\varepsilon^2}=0$  
    因此  
    $P(|X|>0)=P(\bigcup\limits_{n=1}^{\infty}\{|X|>\frac{1}{n}\})\leqslant\sum\limits_{n=1}^{\infty}P(|X|>\frac{1}{n})=0$  

***

## 3.3 协方差、协方差矩阵与相关系数

### 协方差

$$Cov(X,Y)=E[(X-EX)(Y-EY)]=E(XY)-EX\cdot EY$$

**Cauchy-Schwarz不等式**

$$E(|X-EX||Y-EY|)\leqslant\sqrt{E[(X-EX)^2]\cdot E[(Y-EY)^2]}$$

!!! Note
    若$S_n=\sum\limits_{k=1}^n\xi_k$，则$Var(S_n)=\sum\limits_{k=1}^nVar(\xi_k)+2\sum\limits_{k<l}Cov(\xi_k,\xi_l)$

可以推得：

$$Cov(X,Y)\leqslant\sqrt{Var(X)\cdot Var(Y)}$$

### 协方差矩阵

$$\Sigma=\begin{pmatrix}
    Var(X)&Cov(X,Y)\\\
    Cov(X,Y)&Var(Y)
\end{pmatrix}$$

协方差矩阵是**非负定**的，即对于任意$x,y$

$$\begin{pmatrix}
    x&y
\end{pmatrix}\begin{pmatrix}
 Var(X)&Cov(X,Y)\\\
    Cov(X,Y)&Var(Y)    
\end{pmatrix}\begin{pmatrix}
    x\\\
    y
\end{pmatrix}\geqslant 0$$

### 相关性与独立性

若$X$，$Y$相互独立，则

$$Cov(X,Y)=0$$

反过来，$Cov(X,Y)=0$并不意味着$X$，$Y$相互独立。

若$Cov(X,Y)=0$，则称$X$，$Y$**不相关**。**独立一定不相关，不相关不一定独立。**

!!! Example
    **二元联合正态分布$(X,Y)\sim N(\mu_1,\sigma_1^2,\mu_2,\sigma_2^2,\rho)$。**  

    简单起见，设$\mu_1=\mu_2=0$，$\sigma_1^2=\sigma_2^2=1$   
    $Cov(X,Y)=E(XY)$  
    $=\int_{-\infty}^{+\infty}\int_{-\infty}^{+\infty}xy\frac{1}{2\pi\sqrt{1-\rho^2}}e^{-\frac{1}{2(1-\rho^2)}(x^2-2\rho xy+y^2)}dxdy$  
    $=\int_{-\infty}^{+\infty}x\frac{1}{\sqrt{2\pi}}e^{-\frac{x^2}{2}}(\int_{-\infty}^{+\infty}y\frac{1}{\sqrt{2\pi(1-\rho^2)}}e^{-\frac{1}{2(1-\rho^2)}(y-\rho x)^2}dy)dx$（括号内的是$Y\sim N(\rho x,\sqrt{1-\rho^2})$的期望）  
    $=\rho\int_{-\infty}^{+\infty}x^2\frac{1}{\sqrt{2\pi}}e^{-\frac{x^2}{2}}dx$  
    $=\rho$  
    若$(X,Y)\sim N(\mu_1,\sigma_1^2,\mu_2,\sigma_2^2,\rho)$  
    $Cov(X,Y)=E[(X-EX)(Y-EY)]$  
    $=E(\frac{X-EX}{\sigma_1}\cdot\frac{Y-EY}{\sigma_2})\cdot\sigma_1\sigma_2$  
    记$U=\frac{X-EX}{\sigma_1}$，$V=\frac{Y-EY}{\sigma_2}$  
    则$(U,V)\sim N(0,1,0,1,\rho)$  
    因此  
    $Cov(X,Y)=E(UV)\cdot\sigma_1\sigma_2$  
    $=\rho\sigma_1\sigma_2$  

### 相关系数

$$\gamma=\frac{Cov(X,Y)}{\sqrt{Var(X)\cdot Var(Y)}}$$

由Cauchy-Schwarz不等式：$|\gamma|\leqslant 1$

若$\gamma=1$，则存在$t_0=\sqrt{\frac{Var(X)}{Var(Y)}}$，使得

$$P(X-EX=t_0(Y-EY))=1$$

即：$X$和$Y$是正线性相关的。

若$\gamma=-1$，则存在$t_0=-\sqrt{\frac{Var(X)}{Var(Y)}}$，使得

$$P(X-EX=t_0(Y-EY))=1$$

即：$X$和$Y$是负线性相关的。

若$\gamma=0$，则$X$和$Y$不相关（不线性相关）。

!!! Example
    考虑二元联合正态分布，若$\rho=1$，则$\gamma=1$，$X$，$Y$线性相关。

***

## 3.4 条件期望与全期望公式

### 条件期望

给定$Y=y_j$，$X$的条件期望定义为

$$E(X|Y=y_j)=\sum\limits_{i=1}^{\infty}x_iP(X=x_i|Y=y_j)$$

（离散型）

$$E(X|Y=y_j)=\int_{-\infty}^{+\infty}x\frac{p(x,y_j)}{p_Y(y_j)}dx$$

（连续型）

!!! Example
    **二元联合正态分布$(X,Y)\sim N(\mu_1,\sigma_1^2,\mu_2,\sigma_2^2,\rho)$在给定$Y=y$的条件期望。**  

    给定$Y=y$的条件下  
    $X\sim N(\mu_1+\frac{\rho\sigma_1}{\sigma_2}(y-\mu_2),(1-\rho^2)\sigma_1^2)$  
    $E(X|Y=y)=\mu_1+\frac{\rho\sigma_1}{\sigma_2}(y-\mu_2)$  

### 全期望公式

回忆条件期望：一个$y_j$对应一个$E(X|Y=y_j)$，为一个映射。

定义

$$g(y_j)=E(X|Y=y_j)$$

即

$$g(Y)=E(X|Y)$$

为一个新的随机变量。

$$E[g(Y)]=E[E(X|Y)]=EX$$

类似的

$$E[E(Y|X)]=EY$$

以上结论对离散型、连续型或一般型随机变量均成立。

***

## 3.5 矩

### 矩的定义

定义$E(X^k)$为随机变量$X$的 **$k$阶矩**。

定义$E[(X-EX)^k]$为随机变量$X$的 **$k$阶中心矩**。

!!! Note
    并不是所有$X$都有任意$k$阶矩。

!!! Example
    **例1：求$X\sim N(0,1)$的$k$阶矩。**  

    考虑偶数：  
    $E(X^{2k})=\int_{-\infty}^{+\infty}x^{2k}\frac{1}{\sqrt{2\pi}}e^{-\frac{x^2}{2}}dx$  
    $=-\int_{-\infty}^{+\infty}x^{2k-1}\frac{1}{\sqrt{2\pi}}d(e^{-\frac{x^2}{2}})$  
    $=-x^{2k-1}\frac{1}{\sqrt{2\pi}}e^{-\frac{x^2}{2}}\vert_{-\infty}^{+\infty}+(2k-1)\int_{-\infty}^{+\infty}x^{2k-2}\frac{1}{\sqrt{2\pi}}e^{-\frac{x^2}{2}}dx$  
    $=(2k-1)E(X^{2k-2})$  
    因此  
    $E(X^{2k})=(2k-1)!!$  
    考虑奇数：  
    $X^{2k+1}$分布为偶函数，即正负概率相等  
    $E(X^{2k+1})=0$  

    **例2：求$X\sim P(\lambda)$的$k$阶矩。**  

    $EX=\lambda$  
    $E[X(X-1)]=\sum\limits_{k=0}^{\infty}k(k-1)\frac{\lambda^k}{k!}e^{-\lambda}=\sum\limits_{k=2}^{\infty}\frac{\lambda^ke^{-\lambda}}{(k-2)!}=\sum\limits_{k=0}^{\infty}\frac{\lambda^{k+2}e^{-\lambda}}{k!}=\lambda^2$  
    以此类推：  
    $E[X(X-1)···(X-(k-1))]=\lambda^k$  
    $E(X^2)=E[X(X-1)]+EX$  
    $E(X^3)=E[X(X-1)(X-2)]+2E[X(X-1)]+EX$  
    以此类推，$E(X^k)$均可以表示成$E[X(X-1)···(X-(m-1))]$的求和形式。  

### 随机变量分布与矩的关系

考虑随机变量$X$，$Y$。

若$X$，$Y$分布一致，则对于$\forall k$，都有$E(X^k)=E(Y^k)$。

但是，若对于$\forall k$，都有$E(X^k)=E(Y^k)$，并不一定有$X$，$Y$分布一致。

!!! Example
    **反例：**  

    设$\xi\sim N(0,1)$，$X=e^{\xi}$，则$X\sim p_X(x)$：  
    $P_X(x)=\frac{1}{\sqrt{2\pi}x}e^{-\frac{1}{2}(\ln x)^2}$（公式见Chapter2）  
    定义$Y\sim P_Y(y)$：  
    $P_Y(y)=p_X(y)(1+\sin(2\pi\ln y))$  
    可以证明$P_Y(y)$确实是密度函数，且$E(X^k)=E(Y^k),\forall k$  

**随机变量分布与矩关系唯一确定的条件：**

设随机变量$X$，$Y$，且对于$\forall k$，$E(X^k)=E(Y^k)=m_k$，若以下三个条件之一成立：

$$\exists t>0,~\sum\limits_{k=1}^{\infty}\frac{m_{2k}t^{2k}}{(2k)!}<\infty$$

或

$$\sum\limits_{k=1}^{\infty}m_{2k}^{-\frac{1}{2k}}=\infty$$

或

$$\lim\limits_{k\rightarrow\infty}\sup|m_k|^{\frac{1}{k}}<\infty$$

则$X$和$Y$分布一致。

!!! Note
    正态分布与泊松分布都是可以与矩一一对应的。

***

## 3.6 特征函数

### 特征函数的定义

$$\varphi(t)=E(e^{itX})=E(\cos tX)+iE(\sin tX),~t\in R$$

若$X\sim F(x)$，则

$$\varphi(t)=\int_{-\infty}^{\infty}e^{itx}d[F(x)]$$

**二项Bernoulli分布：$X\sim B(n,p)$**

$$\varphi(t)=(pe^{it}+1-p)^n$$

**Poisson分布：$X\sim P(\lambda)$**

$$\varphi(t)=e^{\lambda e^{it}-\lambda}$$

**均匀分布：$X\sim U(a,b)$**

$$\varphi(t)=\frac{e^{itb}-e^{ita}}{it(b-a)}$$

**指数分布：$X\sim \exp(\lambda)$**

$$\varphi(t)=\frac{\lambda}{\lambda-it}$$

**正态分布：$X\sim N(0,1)$**

$$\varphi(t)=e^{-\frac{t^2}{2}}$$

!!! Tip "Proof"
    $\varphi(t)=E(e^{itX})$  
    $=\int_{-\infty}^{+\infty}e^{itx}\frac{1}{\sqrt{2\pi}}e^{-\frac{x^2}{2}}dx$  
    $=\int_{-\infty}^{+\infty}\cos tx\frac{1}{\sqrt{2\pi}}e^{-\frac{x^2}{2}}dx+i\int_{-\infty}^{+\infty}\sin tx\frac{1}{\sqrt{2\pi}}e^{-\frac{x^2}{2}}dx$（后一项为0）  
    $=\sum\limits_{k=0}^{\infty}\frac{(-1)^kt^{2k}}{(2k)!}\frac{1}{\sqrt{2\pi}}\int_{-\infty}^{+\infty}x^{2k}e^{-\frac{x^2}{2}}dx$（前一项泰勒展开）  
    $=\sum\limits_{k=0}^{\infty}\frac{(-1)^kt^{2k}}{(2k)!}(2k-1)!!$（使用之前$k$阶矩的计算结论）  
    $=\sum\limits_{k=0}^{\infty}\frac{(-1)^kt^{2k}}{2^kk!}$  
    $=e^{-\frac{t^2}{2}}$（再次使用泰勒公式）  

### 特征函数的分析性质

**性质1：**

$$|\varphi(t)|\leqslant\varphi(0)=1$$

**性质2：**

$$\varphi(-t)=\overline{\varphi(t)}$$

**性质3：一致连续性**

$\varphi(t)$在$R$上一致连续。

**性质4：Bochner非负定性**

对任意实数$t_1,t_2,···,t_n$，任意复数$a_1,a_2,···,a_n$，都有

$$\sum\limits_{k,l=1}^na_k\overline{a_l}\varphi(t_k-t_l)\geqslant 0$$

**性质5：可微性**

若$E(|X|)$存在，$EX=\mu$，则

$\varphi(t)$可微，且

$$\varphi'(0)=i\mu$$

$$\varphi'(t)=i\int_{-\infty}^{+\infty}xe^{itx}d[F(x)]$$

$$\varphi^{(k)}(t)=i^k\int_{-\infty}^{+\infty}x^ke^{itx}d[F(x)]$$

特别的，$\varphi(t)$在0处可以进行泰勒展开：

$$\varphi(t)=\varphi(0)+\varphi'(0)t+\frac{\varphi''(0)}{2!}t^2+···+\frac{\varphi^{(k)}(0)}{k!}+o(t^k),~t\rightarrow 0$$

### 特征函数的运算性质

**性质1：**

令$X$的特征函数为$\varphi_X(t)$，则

$$E[e^{it(aX+c)}]=e^{itc}\varphi_X(at)$$

!!! Example
    若$Y\sim N(\mu,\sigma^2)$，则可写成  
    $Y=\sigma X+\mu$，$X\sim N(0,1)$  
    因此  
    $\varphi_Y(t)=E[e^{it(\sigma X+\mu)}]=e^{it\mu}\varphi_X(\sigma t)=e^{it\mu-\frac{\sigma^2t^2}{2}}$  

**性质2：乘法公式**

若$X$和$Y$相互独立，则$Z=X+Y$的特征函数为

$$\varphi_Z(t)=\varphi_X(t)\cdot\varphi_Y(t)$$

推广：若$X_1,X_2,···,X_n$相互独立，则$Z=X_1+X_2+···+X_n$的特征函数为

$$\varphi_Z(t)=\prod\limits_{k=1}^n\varphi_{X_k}(t)$$

!!! Example
    若$S_n\sim B(n,p)$，$S_n=\sum\limits_{k=1}^n\xi_k$  
    则  
    $\varphi_{S_n}(t)=\prod\limits_{k=1}^n\varphi_{\xi_k}(t)=(pe^{it}+1-p)^n$  

### 唯一性定理

对于随机变量$X$，$Y$，若$\varphi_X(t)=\varphi_Y(t)$，则$F_X(x)=F_Y(x)$，反之亦然。

### 二元随机向量的特征函数

若$(X,Y)$是二元随机向量，则其特征函数是一个二元函数

$$\phi(t_1,t_2)=E[e^{i(t_1X+t_2Y)}],~t_1,t_2\in R$$

当$X$和$Y$相互独立时

$$\phi(t_1,t_2)=\varphi_X(t_1)\varphi_Y(t_2)$$