---
comments: true
---

<span style="font-family: 'Times New Roman';">

# Chapter5 重积分

***

## 5.1 有界闭区域上的重积分

### 零面积集

**定义：**

设 $D\subseteq R^2$，若对于任意 $\varepsilon>0$，存在有限个矩形 $D_1,···,D_k$，使得 $D\subseteq\bigcup\limits_{i=1}^kD_i$，且 $\sum\sigma(D_i)<\varepsilon$，则称 $D$ 为**零面积集**。

**定理：**

设$\begin{cases}
    x=x(t)\\\
    y=y(t)
\end{cases}$，$t\in[\alpha,\beta]$ 为连续曲线 $E$，且 $x(t)$ 和 $y(t)$ 中至少有一个关于 $t$ 连续可微，则 $E$ 是零面积集。  

### 可积的判定

设 $f$ 是矩形 $D=[a,b]\times[c,d]$ 上的有界函数，则以下命题等价：  

* $f$ 在 $D$ 上可积  
* 对于 $\forall\varepsilon>0$，都存在 $D$ 的划分 $P$，使得 $\overline{S}(f,P)-\underline{S}(f,P)<\varepsilon$  
* $\overline{\int}_Dfd\sigma=\underline{\int}_Dfd\sigma$  

!!! Tip "Proof"
    **2推3：**   

    由关系式：  
    $\underline{S}(f,P)\leqslant\underline{\int}_Dfd\sigma\leqslant\overline{\int}_Dfd\sigma\leqslant\overline{S}(f,P)$
    即可得证  

    **3推2：**  

    由上下积分的定义：  
    对于 $\forall\varepsilon>0$  
    存在 $P_1$，使得 $\overline{S}(f,P_1)-\overline{\int}_Dfd\sigma<\frac{\varepsilon}{2}$  
    存在 $P_2$，使得 $\underline{\int}  _Dfd\sigma-\underline{S}(f,P_2)<\frac{\varepsilon}{2}$
    令 $P$ 为 $P_1$ 和 $P_2$ 的共同加细即可得证  

    **1推2：**  

    记积分为$A$  
    对于 $\forall\varepsilon>0$，$\exists\delta>0$，使得对于 $D$ 的任意划分 $P$，以及对应的任意介点组，只要 $P$ 的细度小于 $\delta$，都有 $|\sum\limits_{i=1}^nf(\xi_i)\sigma(D_i)-A|<\varepsilon$  
    于是有 $A-\frac{\varepsilon}{2}<\underline{S}(f,P)\leqslant\overline{S}(f,P)<A+\frac{\varepsilon}{2}$  
    于是有 $\overline{S}(f,P)-\underline{S}(f,P)<\varepsilon$，得证  

    **2,3推1：**  

    由2：对于 $\forall\varepsilon>0$，存在划分 $P_1=\{D_1,···,D_n\}$，使得 $\overline{S}(f,P_1)-\underline{S}(f,P_1)<\varepsilon$  
    由3：记上下积分为 $A$     
    令 $\delta_0$ 为所有 $D_i$ 的宽的最小值的一半  
    对于满足 $0<\delta<\delta_0$ 的 $\delta$  
    记区域 $K$ 为所有 $D_i$ 的边界左右各加粗 $\delta$ 得到的区域（由 $\delta_0$ 的定义：任意 $D_i$ 都不会被完全挤占）  
    对于 $\forall\varepsilon>0$，总能找到一个 $\delta$ 在 $0$ 到 $\delta_0$ 之间，使得 $\sigma(K)<\varepsilon$，即 $K$ 的面积趋于 $0$  
    任意给出一个 $D$ 的划分 $P=\{E_1,···,E_t\}$，其细度小于 $\delta$，且任意给出 $P$ 取定后的介点组  
    我们要证明的是：$|\sum\limits_{i=1}^tf(\xi_i)\sigma(E_i)-A|<\varepsilon$  
    注意到：$\underline{S}(f,P)\leqslant\sum\limits_{i=1}^tf(\xi_i)\sigma(E_i)\leqslant\overline{S}(f,P)$  
    且 $\underline{S}(f,P)\leqslant A\leqslant\overline{S}(f,P)$  
    因此：$|\sum\limits_{i=1}^tf(\xi_i)\sigma(E_i)-A|\leqslant\overline{S}(f,P)-\underline{S}(f,P)=\sum\limits_{i=1}^t(M_i-m_i)\sigma(E_i)$  
    接下来，我们把 $E_i$ 分成两组：  
    第一组：$E_i\subseteq K$，对应的 $i$ 的集合为 $\Lambda_1$  
    第二组：$E_i\nsubseteq K$，对应的 $i$ 的集合为 $\Lambda_2$  
    其中，第一组振幅大，但面积可以限制  
    第二组面积大，但振幅可以限制  
    第一组：  
    记 $M$ 为整个 $D$ 的上确界，$m$ 为整个 $D$ 的下确界  
    $\sum\limits_{i\in\Lambda_1}(M_i-m_i)\sigma(E_i)\leqslant(M-m)\sum\limits_{i\in\Lambda_1}\sigma(E_i)\leqslant(M-m)\sigma(K)=(M-m)\varepsilon$  
    第二组：  
    由于 $K$ 中线的宽度为 $2\delta$  
    因此如果 $E_i$ 并没有完全包含于 $K$，则其必然包含于某个 $D_j$  
    记 $M_i$ 为 $E_i$ 的上确界，$M_j$ 为 $D_j$ 的上确界，下确界同理  
    $\sum\limits_{i\in\Lambda_2}(M_i-m_i)\sigma(E_i)$  
    $\leqslant\sum\limits_{j=1}^n\sum\limits_{i:E_i\subseteq D_j}(M_i-m_i)\sigma(E_i)$  
    $\leqslant\sum\limits_{j=1}^n(M_j-m_j)\sigma(D_j)$  
    $=\overline{S}(f,P_1)-\underline{S}(f,P_1)$  
    $<\varepsilon$  
    综上：两组都趋于 $0$，得证

***

## 5.2 重积分的性质与计算

### 性质

**定理一：**

设 $f$ 是 $D=[a,b]\times[c,d]$ 上的有界函数，若 $f$ 的间断点是零面积集，则 $f$ 在 $D$ 上可积。

**定理二：**

设 $f$ 是 $D=[a,b]\times[c,d]$ 上的有界函数，若 $E=\{x\in D|f(x)\neq0\}$ 是一个零面积集，则 $f$ 在 $D$ 上可积，且积分为 $0$。

**定理三：**

设 $f$，$g$ 是 $D=[a,b]\times[c,d]$ 上的有界函数，若 $E=\\{x\in D|f(x)\neq g(x)\\}$ 是一个零面积集，则只要 $f$ 和 $g$ 之中有一个在 $D$ 上可积，那么另一个也可积，且积分相同。 

**定理四：**

设 $f$ 是 $E\in R^2$ 上的有界函数，若 $f$ 的间断点集与 $E$ 的边界点集都是零面积集，则 $f$ 在 $E$ 上可积。  

**积分中值定理：**

设 $K$ 是由 $R^2$ 中有限条光滑曲线围成的有界闭区域，函数 $f$，$g:K\rightarrow R$ 连续且 $g$ 在 $K$ 上不变号，则 $\exists \xi\in K$，使得 

$$\int\limits_{K}fgdxdy=f(\xi)\int\limits_{K}gdxdy$$  

特别地，取 $g=1$，有 

$$\int\limits_{K}fdxdy=f(\xi)\sigma(K)$$

其中 $\sigma(K)$ 为 $K$ 的面积。  

### 计算

**二重积分：**

**矩形区域：**

设 $f$ 在 $D=[a,b]\times[c,d]$ 上可积，则  

$$\iint\limits_{D}f(x,y)dxdy=\int_a^bdx\int_c^df(x,y)dy=\int_c^ddy\int_a^bf(x,y)dx$$  

**x型区域：**

设 $f$ 在 $E=\\{(x,y)|y_1(x)\leqslant y \leqslant y_2(x),x\in[a,b]\\}$上可积，则  

$$\iint\limits_{E}f(x,y)dxdy=\int_a^bdx\int_{y_1(x)}^{y_2(x)}f(x,y)dy$$  

**y型区域：**

设 $f$ 在 $E=\\{(x,y)|x_1(y)\leqslant x \leqslant x_2(y),y\in[c,d]\\}$ 上可积，则  

$$\iint\limits_{E}f(x,y)dxdy=\int_c^ddy\int_{x_1(y)}^{x_2(y)}f(x,y)dx$$  

**三重积分：**

**闭方体区域：**

设 $f$ 在 $\Omega=[a_1,b_1]\times[a_2,b_2]\times[a_3,b_3]$ 上可积，则  

$$\iiint\limits_{\Omega}f(x,y,z)dxdydz=\int_{a_1}^{b_1}dx\int_{a_2}^{b_2}dy\int_{a_3}^{b_3}f(x,y,z)dz$$  

**x-y型区域：**

设 $f$ 在 $E=\\{(x,y,z)|z_1(x,y)\leqslant z\leqslant z_2(x,y),(x,y)\in D\\}$ 上可积，其中 $D$ 是可求面积的有界闭区域，$z_1(x,y)$，$z_2(x,y)$ 在 $D$ 上连续，则  

$$\iiint\limits_{\Omega}f(x,y,z)dxdydz=\iint\limits_{D}dxdy\int_{z_1(x,y)}^{z_2(x,y)}f(x,y,z)dz$$  

若有进一步条件：

$$D=\\{(x,y)|y_1(x)\leqslant y\leqslant y_2(x),x\in[a,b]\\}$$

则  

$$\iiint\limits_{\Omega}f(x,y,z)dxdydz=\int_a^bdx\int_{y_1(x)}^{y_2(x)}dy\int_{z_1(x,y)}^{z_2(x,y)}f(x,y,z)dz$$  

!!! Example
    **例：利用重积分的性质和计算方法证明：设 $f(x)$ 在 $[a,b]$ 上连续，则 $[\int_a^bf(x)dx]^2\leqslant(b-a)\int_a^b[f(x)]^2dx$。**  

    证明：  
    左式 $=\int_a^bf(x)dx·\int_a^bf(y)dy$  
    $=\int_a^bdx(\int_a^bf(x)f(y)dy)$  
    $=\iint\limits_{[a,b]\times[a,b]}f(x)f(y)dxdy$  
    $\leqslant\iint\limits_{D}\frac{f^2(x)+f^2(y)}{2}dxdy$  
    $=\frac{1}{2}\iint\limits_{D}f^2(x)dxdy+\frac{1}{2}\iint\limits_{D}f^2(y)dxdy$  
    $=\frac{1}{2}[(b-a)\int_a^bf^2(x)dx+(b-a)\int_a^bf^2(y)dy]$  
    $=(b-a)\int_a^b[f(x)]^2dx$  

***

## 5.3 重积分的变量替换

### 二重积分变量替换

设映射 $\varphi:\begin{cases}
    x=x(u,v)\\\
    y=y(u,v)
\end{cases}$ 是开集 $U$ 上的连续可微的映射，对于 $\forall (u,v)\in U$，有 $\frac{\partial(x,y)}{\partial(u,v)}\neq0$。

设 $\Delta\subset U$ 是由有限条光滑曲线所围成的闭区域，且 $\varphi$ 是 $\Delta$ 上的单射。 设 $f$ 在 $D=\varphi(\Delta)$ 上连续，则**二重积分变量替换公式**成立，即  

$$\iint\limits_{D}f(x,y)dxdy=\iint\limits_{\Delta}f(x(u,v),y(u,v))|\frac{\partial(x,y)}{\partial(u,v)}|dudv$$  

### $n$重积分变量替换

设 $U$ 是 $R^n$ 中的开集，映射 $T:\begin{cases}
    y_1=y_1(x_1,···,x_n)\\\
    ···\\\
    y_n=y_n(y_1,···,y_n)
\end{cases}$ 是 $U$ 上的单射，$y_1,···,y_n$ 有连续偏导数，且 $\forall(x_1,···,x_n)$ 有 $\frac{\partial(y_1,···,y_n)}{\partial(x_1,···,x_n)}\neq0$。

设 $\Omega_1$ 是 $U$ 内具有分片光滑边界的有界闭区域，且 $f(y_1,···,y_n)$ 在 $\Omega$ 上连续，则  

$$\int\limits_{\Omega}f(y_1,···,y_n)dy_1···dy_n=\int\limits_{\Omega_1}f(y_1(x_1,···,x_n),···,y_n(x_1,···,x_n))|\frac{\partial(y_1,···,y_n)}{\partial(x_1,···,x_n)}|dx_1···dx_n$$  

**柱坐标变换：**

$$\begin{cases}
    x=r\cos\theta\\\
    y=r\sin\theta\\\
    z=z
\end{cases}$$  

$$0\leqslant r<+\infty,~0\leqslant\theta\leqslant 2\pi,~z\in R$$  

$$|\frac{\partial(x,y,z)}{\partial(r,\theta,z)}|=r$$  

**球坐标变换：**

$$\begin{cases}
    x=r\sin\varphi\cos\theta\\\
    y=r\sin\varphi\sin\theta\\\
    z=r\cos\varphi
\end{cases}$$  

$$0\leqslant r<+\infty,~0\leqslant\theta\leqslant 2\pi,~0\leqslant\varphi\leqslant\pi$$  

$$|\frac{\partial(x,y,z)}{\partial(r,\varphi,\theta)}|=r^2\sin\varphi$$  