---
comments: true
---

<span style="font-family: 'Times New Roman';">

# Chapter2 随机变量与分布函数

***

## 2.1 随机变量

**随机变量**是以概率空间$\Omega$为定义域，以实数域$R$为值域的函数，可记作：

$$\xi=\xi(\omega),~\omega\in\Omega,~\xi(\omega)\in R$$

**个人观点：随机变量就是让每个基本事件对应到一个实数，从而方便概率计算。**

!!! Example
    某段时间内某寻呼台接到的呼叫数可用$\xi$取非负整数值表示，例如：$\xi=2$表示随机事件{这段时间有两人要求传呼}。  

### 离散型随机变量

取有限个或者可列个值的随机变量称为**离散型随机变量**。

假定概率空间$(\Omega,A,P)$，离散型随机变量

$$X:\Omega\rightarrow R$$

设$X$的可能取值$x_1,x_2,···,x_N$，取每个值的概率大小

$$P(X=x_i)=p_i$$

则可得**分布列**：

$$X\sim\begin{pmatrix}
    x_1&x_2&···&x_N\\\  
    p_1&p_2&···&p_N
\end{pmatrix}$$

#### 典例

**1.退化分布**

$$X\sim\begin{pmatrix}
    c\\\
    1
\end{pmatrix}$$

**2.两点分布**

$$X\sim\begin{pmatrix}
    1&0\\\
    p&q
\end{pmatrix},~p+q=1$$

两点分布适用于描述“正面/反面”“成功/失败”“正常/维修”等随机现象。

**3.二项分布（Bernoulli分布）：$X\sim B(n,p)$**

$$X\sim\begin{pmatrix}
    0&1&···&k&···&n\\\
    q^n&npq^{n-1}&···&C_n^kp^kq^{n-k}&···&p^n
\end{pmatrix},~p+q=1$$

$$P(X=k)=C_n^kp^kq^{n-k}$$

二项分布适用于n重Bernoulli试验。

**4.Poisson分布：$X\sim P(\lambda)$（$\lambda>0$）**

$$X\sim\begin{pmatrix}
    0&1&···&k&···\\\
    e^{-\lambda}&\lambda e^{-\lambda}&···&\frac{\lambda^k}{k!}e^{-\lambda}&···&
\end{pmatrix}$$

$$P(X=k)=\frac{\lambda^k}{k!}e^{-\lambda}$$

**5.几何分布：$X\sim G(p)$**

$$X\sim\begin{pmatrix}
    1&2&···&k&···\\\
    p&pq&···&pq^{k-1}&···
\end{pmatrix},~p+q=1$$

$$P(X=k)=pq^{k-1}$$

考虑随机试验$E$和事件$A$，$P(A)=p$，独立重复$E$，直至$A$发生，记录所做的试验次数，即得到几何分布。

**6.超几何分布**

$$P(X=k)=\frac{C_M^kC_{N-M}^{n-k}}{C_N^n}$$

假设$N$件样品中有$M$件次品，随机抽样$n$件，用$X$表示$n$件产品中的次品数，即得到超几何分布。

### 连续型随机变量

* 随机变量取值是一个或几个区间，对于单一取值，$P(X=x)=0$
* 存在一个**密度函数**$p(x)$，满足$\int_{-\infty}^{\infty}p(x)dx=1$，$P(X\in B)=\int_Bp(x)dx$
  
简记为

$$X\sim p(x)$$

#### 典例

**1.均匀分布：$X\sim U(a,b)$**

$$p(x)=\begin{cases}
    \frac{1}{b-a},x\in(a,b)\\\
    0,else
\end{cases}$$

$$P(X\in A)=\frac{|A|}{b-a},~A\subseteq(a,b)$$

向一维空间$(a,b)$随机投点，落点的位置对应为$X$，$X$落在$(a,b)$上任何一个子区间的概率只与区间长度有关，与区间位置无关。

**2.指数分布：$X\sim\exp(\lambda)$（$\lambda>0$）**

$$p(x)=\begin{cases}
    \lambda e^{-\lambda x},x\geqslant0\\\
    0,else
\end{cases}$$

$$P(X>x)=e^{-\lambda x}$$

指数分布通常用于描述人、零件等的寿命，其具有**无记忆性**（$P(X>x+y|X>y)=P(X>x)$）。

**3.正态分布：$X\sim N(\mu,\sigma^2)$**

$$p(x)=\frac{1}{\sqrt{2\pi}\sigma}e^{-\frac{(x-\mu)^2}{2\sigma^2}},~x\in R$$

!!! tip "Proof"
    **证明：$\int_{-\infty}^{\infty}p(x)dx=1$。**  
    换元：令$y=\frac{x-\mu}{\sigma}$  
    则求证：$\int_{-\infty}^{\infty}\frac{1}{\sqrt{2\pi}}e^{-\frac{x^2}{2}}dx=1$  
    $(\int_{-\infty}^{\infty}\frac{1}{\sqrt{2\pi}}e^{-\frac{x^2}{2}}dx)^2=\int_{-\infty}^{\infty}\int_{-\infty}^{\infty}\frac{1}{2\pi}e^{-\frac{x^2+y^2}{2}}dxdy$  
    令$\begin{cases}  
    x=\rho\cos\theta\\\
    y=\rho\sin\theta
    \end{cases}$  
    则$\int_{-\infty}^{\infty}\int_{-\infty}^{\infty}\frac{1}{2\pi}e^{-\frac{x^2+y^2}{2}}dxdy=\int_0^{\infty}\int_0^{2\pi}\frac{1}{2\pi}e^{-\frac{\rho^2}{2}}\rho d\rho d\theta=1$  
    因此$\int_{-\infty}^{\infty}\frac{1}{\sqrt{2\pi}}e^{-\frac{x^2}{2}}dx=1$，证毕。  

正态分布的重要性质：

* 对称性：关于$x=\mu$对称
* 渐近线：$y=0$
* 最大值：$p(x)$在$x=\mu$处取最大值$\frac{1}{\sqrt{2\pi}\sigma}$
* $\sigma$增大，曲线变平坦；$\sigma$减小，曲线变陡峭
* 无法精确计算概率，只有估值$P(X>\mu+\sigma x)=P(X<\mu-\sigma x)\approx\frac{1}{\sqrt{2\pi}x}e^{-\frac{x^2}{2}}$，$x\rightarrow\infty$
* $P(|X-\mu|\leqslant3\sigma)\approx0.9997$

### 一般随机变量

既不是离散型随机变量，也不是离散型随机变量。

!!! Example
    $P(X=0)=\frac{1}{2}$  
    $P(X>x)=\frac{1}{2}e^{-x}$，$x>0$

***

## 2.2 分布函数

假定$X$是概率空间$(\Omega,A,P)$上的随机变量，定义$X$的**分布函数**$F:R\mapsto[0,1]$：

$$F(x)=P(X\leqslant x),~x\in R$$

**分布函数的性质：**

* $F(-\infty)=0$，$F(+\infty)=1$
* $F(x)$单调不减
* $F(x)$左极限存在，右连续（$P(X<x)=F_{-}(x)$）

给定满足上述三点的实函数$F$，一定能找到一个概率空间$(\Omega,A,P)$和一个随机变量$X$，使得$F(x)=P(X\leqslant x)$。

### 连续型随机变量的分布函数

$$F(x)=\int_{-\infty}^{x}p(u)du$$

$$F'(x)=p(x)$$

**1.均匀分布：$X\sim U(a,b)$**

$$F(x)=\begin{cases}
    0,x<a\\\
    \frac{x-a}{b-a},a\leqslant x<b\\\
    1,x\geqslant b
\end{cases}$$

**2.指数分布：$X\sim\exp(\lambda)$**

$$F(x)=\begin{cases}
    0,x<0\\\
    1-e^{-\lambda x},x\geqslant 0
\end{cases}$$

**3.正态分布（以标准正态分布为例）**

$$F(x)=\int_{-\infty}^x\frac{1}{\sqrt{2\pi}}e^{-\frac{u^2}{2}}du$$

$F(x)$没有显性表达式，通常用$\Phi(x)$（Probit函数）表示其分布函数，查表可得。

!!! Note
    制表方法不尽相同，仔细甄别。

**4.Logistic分布**

$$p(x)=\frac{e^{-x}}{(1+e^{-x})^2}$$

$$F(x)=\frac{1}{1+e^{-x}}$$

***

## 2.3 随机变量的函数

已知随机变量$X$，则可定义关于$X$的函数

$$Y=f(X),~Y(\omega)=f(X(\omega))$$

当$f$是**可测函数**时，$Y$是一个随机变量。

!!! Success "Definition"
    **可测：** 对于任意波雷尔集$B$，$f(B)$的原像集（$f^{-1}(B)$）也是波雷尔集。  
    我们目前接触到的$f$大部分都为可测函数。

    **波雷尔集：** 直线上由左开右闭区间经过并、交、逆等运算得到的点集。  

### 离散型随机变量

**当$X$是离散型随机变量时，$Y$也是离散型随机变量。**


!!! Example
    **已知$X\sim\begin{pmatrix}
    -1&0&1&2\\\
    \frac{1}{8}&\frac{1}{2}&\frac{1}{8}&\frac{1}{4}
    \end{pmatrix}$，求$Y=X^2$的分布列.** 

    $Y\sim\begin{pmatrix}
    1&0&4\\\
    \frac{1}{8}+\frac{1}{8}&\frac{1}{2}&\frac{1}{4}
    \end{pmatrix}$  

一般的，若

$$X\sim\begin{pmatrix}
    x_1&x_2&···&x_i&···&x_N\\\
    p_1&p_2&···&p_i&···&p_N
\end{pmatrix},~Y=f(X)$$

则用$f$将$X$的可能取值进行映射：

$$\{f(x_1),f(x_2),···,f(x_N)\}=\{y_1,y_2,···,y_k\}$$

其中$y_1,···,y_k$互不相同。

$$P(Y=y_j)=\sum\limits_{i:f(x_i)=y_j}p_i$$

### 连续型随机变量

**当$X$是连续型随机变量时，$Y$不一定是连续型随机变量。**

!!! Example
    **例1：已知$X\sim N(0,1)$，$f(x)=\begin{cases}
    -1.x<0\\\
    0,x=0\\\
    1,x>0
    \end{cases}$，求$Y=f(X)$的分布。**  

    $Y\sim\begin{pmatrix}
    -1&1\\\
    \frac{1}{2}&\frac{1}{2}
    \end{pmatrix}$

    **例2：已知$X\sim N(\mu,\sigma^2)$，求$Y=\frac{X-\mu}{\sigma}$的分布。**  

    $Y$的分布函数  
    $F(y)=P(Y\leqslant y)$  
    $=P(\frac{X-\mu}{\sigma}\leqslant y)$  
    $=P(X\leqslant \mu+\sigma y)$  
    $=\int_{-\infty}^{\mu+\sigma y}\frac{1}{\sqrt{2\pi}\sigma}e^{-\frac{(u-\mu)^2}{2\sigma^2}}du$  
    $=\int_{-\infty}^y\frac{1}{\sqrt{2\pi}}e^{-\frac{u^2}{2}}du$  
    此式恰好为标准正态分布的分布函数  
    因此$Y\sim N(0,1)$  
    （非标准正态与标准正态的灵活转换）  

例1和例2说明了$Y$可能是离散型随机变量，也可能是连续型随机变量。

**定理：**

设随机变量$X$的密度函数为$p_X(x)$，$f$严格单调，具有反函数$f^{-1}$，且$f^{-1}$可导，则$Y=f(X)$仍然是连续型随机变量，且具有密度函数：

$$p_Y(y)=p_X(f^{-1}(y))\cdot|(f^{-1})'(y)|$$

!!! tip "Proof"
    $F_Y(y)=P(Y\leqslant y)$  
    $=P(f(X)\leqslant y)$  
    $=P(X\leqslant f^{-1}(y))$（不妨设$f$严格单调递增）  
    $=F_X(f^{-1}(y))$  
    两边同时求导：  
    $p_Y(y)=p_X(f^{-1}(y))\cdot(f^{-1})'(y)$  
    同理：若$f$严格单调递减：  
    $F_Y(y)=1-F_X(f^{-1}(y))$  
    $p_Y(y)=-p_X(f^{-1}(y))\cdot(f^{-1})'(y)$  
    综上：$p_Y(y)=p_X(f^{-1}(y))\cdot|(f^{-1})'(y)|$  

!!! Example
    **设$X\sim U(0,1)$，$F(x)$是给定的分布函数（满足分布函数的三个条件），求$Y=F^{-1}(X)$的分布。**  

    由于$F(x)$单调不减且右连续，因此定义：  
    $F^{-1}(y)=\sup\{x:F(x)<y\}$  
    $P(Y\leqslant y)=P(F^{-1}(X)\leqslant y)=P(X\leqslant F(y))=F(y)$  
    因此$Y$的分布函数也是$F(x)$。  

上例说明：不论$F(x)$是什么函数，只要满足分布函数的三个条件，就存在随机变量使其分布函数为$F(x)$。

!!! Example
    **设$X$具有连续的分布函数$F(x)$，求$Y=F(X)$的分布。**

    $P(Y\leqslant y)=P(F(X)\leqslant y)=P(X\leqslant F^{-1}(y))=F(F^{-1}(y))=y$  
    因此$Y$的分布函数为1。

***

## 2.4 随机向量

给定概率区间$(\Omega,A,P)$

$$X:\Omega\mapsto R^m$$

$$X(\omega)=(X_1(\omega),X_2(\omega),···,X_m(\omega))$$

其中$X_1,X_2,···,X_m$都是随机变量，称$X$为 **m维随机向量**。

### 离散型随机向量（以二维为例）

若$X$取值为$x_1,x_2,···$，$Y$取值为$y_1,y_2,···$，则称$(X,Y)$为**离散型随机向量**。

#### 联合分布

$$p_{ij}=P(X=x_i,Y=y_i),~\sum\limits_{i,j}p_{ij}=1$$

#### 边际分布

$$p_{i.}=P(X=x_i)=\sum\limits_{j=1}^{\infty}p_{ij},~\sum\limits_{i=1}^{\infty}p_{i.}=1$$

$$p_{.j}=P(Y=y_j)=\sum\limits_{i=1}^{\infty}p_{ij},~\sum\limits_{j=1}^{\infty}p_{.j}=1$$

!!! Example
    **有2个白球，3个黑球，现随机依次抽取两球，每次一个，分别用$X$，$Y$表示第一、二次取得的白球个数，求$(X,Y)$的联合分布和边际分布。** 

    $x_1=0$，$x_2=1$，$y_1=0$，$y_2=1$  
    $(X,Y)$有四种取值情况。

    **情况一：有放回**  
    联合分布：  
    $p_{00}=\frac{3}{5}\times\frac{3}{5}$  
    $p_{01}=\frac{3}{5}\times\frac{2}{5}$  
    $p_{10}=\frac{2}{5}\times\frac{3}{5}$  
    $p_{11}=\frac{2}{5}\times\frac{2}{5}$  
    边际分布：  
    $p_{0.}=p_{00}+p_{01}=\frac{3}{5}$  
    $p_{1.}=p_{10}+p_{11}=\frac{2}{5}$  
    $p_{.0}=p_{00}+p_{10}=\frac{3}{5}$  
    $p_{.1}=p_{01}+p_{11}=\frac{2}{5}$  

    **情况二：无放回**  
    联合分布：  
    $p_{00}=\frac{3}{5}\times\frac{2}{4}$  
    $p_{01}=\frac{3}{5}\times\frac{2}{4}$  
    $p_{10}=\frac{2}{5}\times\frac{3}{4}$  
    $p_{11}=\frac{2}{5}\times\frac{1}{4}$  
    边际分布：  
    $p_{0.}=p_{00}+p_{01}=\frac{3}{5}$  
    $p_{1.}=p_{10}+p_{11}=\frac{2}{5}$  
    $p_{.0}=p_{00}+p_{10}=\frac{3}{5}$  
    $p_{.1}=p_{01}+p_{11}=\frac{2}{5}$  

从上例我们可以看出，**联合分布唯一决定边际分布，边际分布不能唯一决定联合分布**。

#### 条件分布

给定$X=x_i$的条件下，$Y$可取值$y_1,y_2,···$

$$P(Y=y_j|X=x_i)=\frac{p_{ij}}{p_{i.}}$$

$$Y|X=x_i\sim\begin{pmatrix}
    y_1&y_2&···&y_j&···\\\
    \frac{p_{i1}}{p_{i.}}&\frac{p_{i2}}{p_{i.}}&···&\frac{p_{ij}}{p_{i.}}&···
\end{pmatrix}$$

!!! Note
    同理，也有$X|Y=y_j$。但没有$Y=y_j|X$，因为后者的概率之和不为1。

#### 独立性

若离散型随机变量$(X,Y)$中$X$和$Y$相互独立，则对于任意$i,j$，都有

$$P(X=x_i,Y=y_j)=P(X=x_i)P(Y=y_j)$$

即

$$p_{ij}=p_{i.}p_{.j}$$


### 连续型随机向量（以二维为例）

对于$(X,Y)$，若存在$p(x,y)$，使得

$$p(x,y)\geqslant 0,~\int_{-\infty}^{\infty}\int_{-\infty}^{\infty}p(x,y)dxdy=1$$

且对于任意波雷尔集$A,B\subseteq R$

$$P(X\in A,Y\in B)=\int_A\int_Bp(x,y)dxdy$$

则称$(X,Y)$是**连续型随机向量**，具有密度函数$p(x,y)$。

#### 联合分布

$$P(X\in A,Y\in B)=\int_A\int_Bp(x,y)dxdy$$

$$P(X\leqslant x,Y\leqslant y)=\int_{-\infty}^x\int_{-\infty}^yp(u,v)dudv$$

#### 边际分布

设$X$的边际密度函数为$p_X(x)$，$Y$的边际密度函数为$p_Y(y)$：

$$p_X(x)=\int_{-\infty}^{\infty}p(x,y)dy$$

$$p_Y(y)=\int_{-\infty}^{\infty}p(x,y)dx$$

同样的，**联合分布唯一决定边际分布，边际分布不能唯一决定联合分布**。

!!! Example
    **二元联合正态分布** 

    若随机向量$(X,Y)$的密度函数  
    $p(x,y)=\frac{1}{2\pi\sigma_1\sigma_2\sqrt{1-\rho^2}}e^{-\frac{1}{2(1-\rho^2)}[\frac{(x-\mu_1)^2}{\sigma_1^2}-\frac{2\rho(x-\mu_1)(y-\mu_2)}{\sigma_1\sigma_2}+\frac{(y-\mu_2)^2}{\sigma_2^2}]}$  
    则称$(X,Y)$服从二元联合正态分布，记为$(X,Y)\sim N(\mu_1,\sigma_1^2,\mu_2,\sigma_2^2,\rho)$  
    其边际分布：  
    $p_X(x)=\frac{1}{\sqrt{2\pi}\sigma_1}e^{-\frac{(x-\mu_1)^2}{2\sigma_1^2}}$，$X\sim N(\mu_1,\sigma_1^2)$  
    $p_Y(y)=\frac{1}{\sqrt{2\pi}\sigma_2}e^{-\frac{(y-\mu_2)^2}{2\sigma_2^2}}$，$Y\sim N(\mu_2,\sigma_2^2)$  
    二元正态分布的边际分布仍是正态分布。  

#### 条件分布

$$P(Y\leqslant y|X=x)=\frac{\int_{-\infty}^yp(x,v)dv}{p_X(x)}$$

给定$X=x$，则在此条件下$Y$具有密度函数：

$$p_{Y|X}(y|x)=\frac{p(x,y)}{p_X(x)}$$

#### 独立性

若连续型随机变量$(X,Y)$中$X$和$Y$相互独立，则对于任意$x,y$，都有

$$p(x,y)=p_X(x)p_Y(y)$$

!!! Example
    **例1：**  
    若$(X,Y)$是矩形区域$(a,b)\times(c,d)$上的均匀分布，则$X$，$Y$相互独立。 

    **例2：**  
    若$(X,Y)$是单位圆$((0,0),1)$上的均匀分布，则$X$，$Y$不相互独立。

    **例3：**  
    若$(X,Y)\sim N(\mu_1,\sigma_1^2,\mu_2,\sigma_2^2,\rho)$，则  
    当$\rho=0$时，$X$，$Y$相互独立；   
    当$\rho\neq0$时，$X$，$Y$不相互独立。

### 随机向量分布函数（以二维连续型为例）

#### 联合分布

$$F(x,y)=\int_{-\infty}^x\int_{-\infty}^yp(u,v)dudv$$

$F(x,y)$的基本性质：

* $F(-\infty,y)=F(x,-\infty)=0$，$F(+\infty,+\infty)=1$
* $F(x,y)$关于$x$和$y$分别单调不减
* $F(x,y)$关于$x$和$y$分别存在左极限，右连续
* $P(a<X\leqslant b,c< Y\leqslant d)=F(a,c)+F(b,d)-F(a,d)-F(b,c)\geqslant 0$

#### 边际分布

$$F_X(x)=F(x,+\infty)$$

$$F_Y(y)=F(+\infty,y)$$

#### 独立性

若连续型随机变量$(X,Y)$中$X$和$Y$相互独立，则对于任意$x,y$，都有

$$F(x,y)=F_X(x)F_Y(y)$$

若$X$，$Y$相互独立，则对于任意可测函数$f$，$g$，都有$f(X)$，$g(Y)$相互独立。

若$X_1,X_2,···$和$Y_1,Y_2,···$相互独立，则对于任意可测函数$f$，$g$，都有$f(X_1,X_2,···)$，$g(Y_1,Y_2,···)$相互独立。

***

## 2.5 随机向量的运算

### 随机向量的四则运算

#### 离散型加减法

若$(X,Y)$是离散型随机向量，其联合分布为

$$P(X=x_i,Y=y_i)=p_{ij}$$

设随机变量$Z=X+Y$，则其分布为

$$P(Z=z_k)=\sum\limits_{i,j:x_i+y_j=z_k}p_{ij}$$

若$X$，$Y$相互独立，则

$$P(Z=z_k)=\sum\limits_{i,j:x_i+y_j=z_k}p_{i.}p_{.j}$$

!!! Example
    **例1：Bernoulli随机变量之和**   
    **设$X\sim B(n,p)$，$Y\sim B(m,p)$，$X$，$Y$相互独立，求$Z=X+Y$的分布。**  

    $P(Z=k)=P(X+Y=k)$  
    $=\sum\limits_{l=0}^kP(X=l,Y=k-l)$  
    $=\sum\limits_{l=0}^kP(X=l)P(Y=k-l)$  
    $=\sum\limits_{l=0}^kC_n^lp^l(1-p)^{n-l}C_m^{k-l}p^{k-l}(1-p)^{m-(k-l)}$  
    $=p^k(1-p)^{m+n-k}\sum\limits_{l=0}^kC_n^lC_m^{k-l}$  
    $=C_{n+m}^kp^k(1-p)^{m+n-k}$  
    因此，$Z\sim B(m+n,p)$    
    **对于相同的$p$，独立Bernoulli随机变量之和仍是Bernoulli随机变量。**  

    **例2：Poisson随机变量之和**   
    **设$X\sim P(\lambda)$，$Y\sim P(\mu)$，$X$，$Y$相互独立，求$Z=X+Y$的分布。** 

    $P(Z=k)=P(X+Y=k)$  
    $=\sum\limits_{l=0}^kP(X=l,Y=k-l)$  
    $=\sum\limits_{l=0}^kP(X=l)P(Y=k-l)$  
    $=\sum\limits_{l=0}^k\frac{\lambda^l}{l!}e^{-\lambda}\cdot\frac{\mu^{k-l}}{(k-l)!}e^{-\mu}$  
    $e^{-(\lambda+\mu)}\frac{1}{k!}\sum\limits_{l=0}^k\frac{k!}{l!(k-l)!}\lambda^l\mu^{k-l}$  
    $\frac{(\lambda+\mu)^k}{k!}e^{-(\lambda+\mu)}$  
    因此$Z\sim P(\lambda+\mu)$  
    **独立Poisson随机变量之和仍是Poisson随机变量。**  

#### 连续型加法

若$(X,Y)$是连续型随机向量，其联合分布密度函数为$p(x,y)$

设随机变量$Z=X+Y$，则其密度函数为

$$p_Z(z)=\int_{-\infty}^{\infty}p(x,z-x)dx$$

若$X$，$Y$相互独立，则

$$p_Z(z)=\int_{-\infty}^{\infty}p_X(x)p_Y(z-x)dx$$

!!! Example
    **例1：均匀随机变量之和**  
    **设$X\sim U(0,1)$，$Y\sim U(0,1)$，$X$，$Y$相互独立，求$Z=X+Y$的分布。**  

    $Z$的取值为$(0,2)$，因此当$z\leqslant 0$或$z\geqslant 2$时，$p_Z(z)=0$  
    当$0<z\leqslant 1$时  
    $p_Z(z)=\int_{-\infty}^{\infty}p_X(x)p_Y(z-x)dx=\int_0^zdx=z$  
    当$1<z<2$时  
    $p_Z(z)=\int_{-\infty}^{\infty}p_X(x)p_Y(z-x)dx=\int_{z-1}^1dx=2-z$  

    **例2：正态随机变量之和**  
    **设$X\sim N(\mu_1,\sigma_1^2)$，$Y\sim N(\mu_2,\sigma_2^2)$，$X$，$Y$相互独立，求$Z=X+Y$的分布。**  

    $p_Z(z)=\int_{-\infty}^{\infty}p_X(x)p_Y(z-x)dx$  
    $=\int_{-\infty}^{\infty}\frac{1}{\sqrt{2\pi}\sigma_1}e^{-\frac{(x-\mu_1)^2}{2\sigma_1^2}}\frac{1}{\sqrt{2\pi}\sigma_2}e^{-\frac{(z-x-\mu_2)^2}{2\sigma_2^2}}dx$  
    $=\frac{1}{\sqrt{2\pi}\sqrt{\sigma_1^2+\sigma_2^2}}e^{-\frac{[x-(\mu_1+\mu_2)]^2}{2(\sigma_1^2+\sigma_2^2)}}$  
    因此，$Z\sim N(\mu_1+\mu_2,\sigma_1^2+\sigma_2^2)$  
    **独立正态随机变量之和仍是正态随机变量。**  

#### 连续型减法

若$(X,Y)$是连续型随机向量，其联合分布密度函数为$p(x,y)$

设随机变量$Z=Y-X$，则其密度函数为

$$p_Z(z)=\int_{-\infty}^{\infty}p(x,z+x)dx$$

若$X$，$Y$相互独立，则

$$p_Z(z)=\int_{-\infty}^{\infty}p_X(x)p_Y(z+x)dx$$

#### 连续型乘法

若$(X,Y)$是连续型随机向量，其联合分布密度函数为$p(x,y)$

设随机变量$Z=XY$，则其密度函数为

$$p_Z(z)=\int_{-\infty}^{\infty}\frac{1}{|x|}p(x,\frac{z}{x})dx$$

若$X$，$Y$相互独立，则

$$p_Z(z)=\int_{-\infty}^{\infty}\frac{1}{|x|}p_X(x)p_Y(\frac{z}{x})dx$$

!!! Note
    我们可能会习惯性地将$p(x,\frac{z}{x})$理解为$x$取定某个值时$xy=z$的概率，用点概率积分得到取$z$的点概率，即$p_Z(z)=\int_{-\infty}^{\infty}p(x,\frac{z}{x})dx$，但这是错误的，当我们进行乘法变换$Z=XY$时，变换后的区域会受到$X$值的影响。例如，如果$X$非常小，则$Y$对$Z$的影响会被放大，因此需要引入比例因子来调整变换后的密度，保证最后总积分仍为1。

#### 连续型除法

若$(X,Y)$是连续型随机向量，其联合分布密度函数为$p(x,y)$

设随机变量$Z=\frac{Y}{X}$，则其密度函数为

$$p_Z(z)=\int_{-\infty}^{\infty}|x|p(x,zx)dx$$

若$X$，$Y$相互独立，则

$$p_Z(z)=\int_{-\infty}^{\infty}|x|p_X(x)p_Y(zx)dx$$

!!! Example
    **设$X\sim N(0,1)$，$Y\sim N(0,1)$，$X$，$Y$相互独立，求$Z=\frac{Y}{X}$的分布。**  

    $p_Z(z)=\int_{-\infty}^{\infty}|x|p_X(x)p_Y(zx)dx$  
    $=\frac{1}{2\pi}\int_{-\infty}^{\infty}|x|e^{-\frac{x^2(1+z^2)}{2}}dx$  
    $=\frac{1}{\pi}\int_{0}^{\infty}xe^{-\frac{x^2(1+z^2)}{2}}dx$  
    $=\frac{1}{\pi}\frac{1}{1+z^2}$  
    称$Z$为**标准Cauchy分布**。  

### 随机向量的变换

若$(X,Y)$是连续型随机向量，其联合分布密度函数为$p_{(X,Y)}(x,y)$

若变换如下：

$$\begin{cases}
    U=f_1(X,Y)\\\
    V=f_2(X,Y)
\end{cases}$$

则随机向量$(U,V)$的分布函数为

$$F_{(U,V)}(u,v)=\int\limits_{(x,y):f_1(x,y)\leqslant u,f_2(x,y)\leqslant v}p(x,y)dxdy$$

若$f_1$，$f_2$存在逆变换，即

$$\begin{cases}
    X=g_1(U,V)\\\
    Y=g_2(U,V)
\end{cases}$$

则可得到Jaccobi行列式

$$J=\det\begin{pmatrix}
    \frac{\partial g_1}{\partial u}&\frac{\partial g_1}{\partial v}\\\
    \frac{\partial g_2}{\partial u}&\frac{\partial g_2}{\partial v}
\end{pmatrix}$$

则随机向量$(U,V)$的联合分布密度函数为

$$p_{(U,V)}(u,v)=p_{(X,Y)}(g_1(u,v),g_2(u,v))|J|$$

#### 正态随机向量与其变换

考虑$(X,Y)\sim N(\mu_1,\sigma_1^2,\mu_2,\sigma_2^2,\rho)$

$$\frac{(x-\mu_1)^2}{\sigma_1^2}-\frac{2\rho(x-\mu_1)(y-\mu_2)}{\sigma_1\sigma_2}+\frac{(y-\mu_2)^2}{\sigma_2^2}=\begin{pmatrix}
    x-\mu_1&x-\mu_2\\\
\end{pmatrix}
\begin{pmatrix}
    \frac{1}{\sigma_1^2}&-\frac{\rho}{\sigma_1\sigma_2}\\\
    -\frac{\rho}{\sigma_1\sigma_2}&\frac{1}{\sigma_2^2}
\end{pmatrix}
\begin{pmatrix}
    x-\mu_1\\\
    y-\mu_2
\end{pmatrix}$$

记中间的矩阵为$A$。

设

$$\Sigma=\begin{pmatrix}
    \sigma_1^2&\sigma_1\sigma_2\rho\\\
    \sigma_1\sigma_2\rho&\sigma_2^2
\end{pmatrix}$$

则

$$\Sigma^{-1}=\frac{1}{1-\rho^2}A$$

$$|\Sigma|=\sigma_1^2\sigma_2^2(1-\rho^2)$$

因此，$(X,Y)$的联合密度函数可写为

$$p_{(X,Y)}(x,y)=\frac{1}{(\sqrt{2\pi})^2|\Sigma|^{\frac{1}{2}}}e^{-\frac{1}{2}\begin{pmatrix}
    x-\mu_1&y-\mu_2\\\
\end{pmatrix}\Sigma^{-1}
\begin{pmatrix}
x-\mu_1\\\
y-\mu_2
\end{pmatrix}}$$

**推广到三维：**

$$\Sigma=\begin{pmatrix}
    \sigma_1^2&\sigma_1\sigma_2\rho_{12}&\sigma_1\sigma_3\rho_{13}\\\
    \sigma_2\sigma_1\rho_{12}&\sigma_2^2&\sigma_2\sigma_3\rho_{23}\\\
    \sigma_3\sigma_1\rho_{13}&\sigma_3\sigma_2\rho_{23}&\sigma_3^2
\end{pmatrix}$$

$$p_{(X,Y,Z)}(x,y,z)=\frac{1}{(\sqrt{2\pi})^3|\Sigma|^{\frac{1}{2}}}e^{-\frac{1}{2}\begin{pmatrix}
    x-\mu_1&y-\mu_2&z-\mu_3\\\
\end{pmatrix}\Sigma^{-1}
\begin{pmatrix}
x-\mu_1\\\
y-\mu_2\\\
z-\mu_3
\end{pmatrix}}$$

**推广到n维：**

记向量$\mathbf{x}=(x_1,x_2,···,x_n)$，$\mathbf{u}=(\mu_1,\mu_2,···,\mu_n)$，则

$$p(\mathbf{x})=\frac{1}{(\sqrt{2\pi})^n|\Sigma|^{\frac{1}{2}}}e^{-\frac{1}{2}(\mathbf{x}-\mathbf{u})\Sigma^{-1}(\mathbf{x}-\mathbf{u})^T}$$

!!! Example
    **设$(X,Y)\sim N(\mu_1,\sigma_1^2,\mu_2,\sigma_2^2,\rho)$，定义：**  
    **$\begin{pmatrix}
    U\\\
    V
    \end{pmatrix}=
    \begin{pmatrix}
    a&b\\\
    c&d
    \end{pmatrix}\cdot
    \begin{pmatrix}
    X\\\
    Y
    \end{pmatrix}$**  
    **求$(U,V)$的分布密度。** 

    记$A=\begin{pmatrix}
    a&b\\\
    c&d
    \end{pmatrix}$  
    $\begin{pmatrix}
    X\\\
    Y
    \end{pmatrix}=A^{-1}\cdot
    \begin{pmatrix}
    U\\\
    V
    \end{pmatrix}$  
    $J=|A^{-1}|=|A|^{-1}$  
    最后，$(U,V)$的联合密度函数可写作：  
    $P_{(U,V)}(u,v)=\frac{1}{2\pi|A\Sigma A^T|^{\frac{1}{2}}}e^{-\frac{1}{2}(\mathbf{x}-A\mathbf{u})(A\Sigma A^T)^{-1}(\mathbf{x}-A\mathbf{u})^T}$  
    $(U,V)\sim N(A\mathbf{u},A^T\Sigma A)$  
    结论：**联合正态随机向量的线性组合仍然是联合正态随机向量。（$X$，$Y$不一定独立）**  

***

## 2.6 极值随机变量

设$X_1,X_2,···,X_n$是概率空间$(\Omega,A,P)$上的随机变量。

对于任意给定的事件$\omega$，对$X_1(\omega),X_2(\omega),···,X_n(\omega)$可以重新排序：

$$X_{(1)}(\omega)\leqslant X_{(2)}(\omega)\leqslant···\leqslant X_{(n)}(\omega)$$

称$X_{(1)},X_{(2)},···,X_{(n)}$为**次序随机变量**。

其中，$X_{(1)}$为极小随机变量，$X_{(n)}$为极大随机变量，$X_{(k)}$为第$k$小随机变量。

**极大值：**

若$X_1,X_2,···,X_n$独立同分布，分布函数为$F(x)$，则$X_{(n)}$的分布函数：

$$F_{X_{(n)}}(x)=F^n(x)$$

密度函数：

$$p_{X_{(n)}}(x)=nF(x)^{n-1}F'(x)$$

**极小值：**

若$X_1,X_2,···,X_n$独立同分布，分布函数为$F(x)$，则$X_{(1)}$的分布函数：

$$F_{X_{(1)}}(x)=1-[1-F(x)]^n$$

密度函数：

$$p_{X_{(1)}}(x)=n[1-F(x)]^{n-1}F'(x)$$

**第$k$小值：**

若$X_1,X_2,···,X_n$独立同分布，分布函数为$F(x)$，则$X_{(k)}$的密度函数：

$$p_{X_{(k)}}(x)=(n-k+1)C_n^{k-1}F^{k-1}(x)p(x)[1-F(x)]^{n-k}$$

**联合分布：**

$(X_{(1)},X_{(2)},···,X_{(n)})$的联合概率密度函数：

$$p(X_{(1)}=x_1,X_{(2)}=x_2,···,X_{(n)}=x_n)=n!p(x_1)p(x_2)···p(x_n)$$