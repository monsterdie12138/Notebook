---
comments: true
---

<span style="font-family: 'Times New Roman';">

# Chapter6 曲线积分与曲面积分

***

## 6.1 曲线积分

### 第一类曲线积分

**具体情境：**

对于空间上一条具有质量的曲线 $L$，在每一点 $(x,y,z)$ 处都有线密度 $\rho(x,y,z)$，求曲线的质量。  

**计算公式：**

设 $L$ 是由参数方程 $\vec{x}(t)=(x_1(t),···,x_n(t))$，$t\in[\alpha,\beta]$ 定义的光滑曲线，且其满足：  

* $\forall1\leqslant i\leqslant n$，$x_i(t)$ 在 $t\in[\alpha,\beta]$ 上有连续导数  
* $\forall t\in[\alpha,\beta]$，$x_i'(t)$ 不同时为零  

$f$ 是 $L$ 上连续的实值函数，则 $f$ 在 $L$ 上的第一类曲线积分存在，且：  

**一般形式：**

$$\int\limits_Lf(x_1,···,x_n)ds=\int_{\alpha}^{\beta}f[\vec{x}(t)]\sqrt{[x_1'(t)]^2+···[x_n'(t)]^2}dt$$  

**n=3：**

$$\int\limits_Lf(x,y,z)ds=\int_{\alpha}^{\beta}f[x(t),y(t),z(t)]\sqrt{[x'(t)]^2+[y'(t)]^2+[z'(t)]^2}dt$$  

**n=2：**

$$\int\limits_Lf(x,y)ds=\int_{\alpha}^{\beta}f[x(t),y(t)]\sqrt{[x'(t)]^2+[y'(t)]^2}dt$$  

!!! Example
    **例：计算 $I=\int\limits_L(x^2+y^2+2z)ds$，其中 $L$ 为球面 $x^2+y^2+z^2=a^2$ 和平面 $x+y+z=0$ 的交线。**  

    由对称性可得：  
    $\int\limits_Lx^2ds=\int\limits_Ly^2ds=\int\limits_Lz^2ds=\frac{1}{3}\int\limits_L(x^2+y^2+z^2)ds=\frac{1}{3}\int\limits_La^2ds=\frac{2\pi a^3}{3}$  
    $\int\limits_Lxds=\int\limits_Lyds=\int\limits_Lzds=\frac{1}{3}\int\limits_L(x+y+z)ds=0$  
    因此：$I=\frac{4\pi a^3}{3}$  

### 第二类曲线积分

**具体情境：**

对于空间上一条具有方向的曲线 $L$，在每一点 $(x,y,z)$ 处都有力 $\vec{F}(x,y,z)=P(x,y,z)\vec{i}+Q(x,y,z)\vec{j}+R(x,y,z)\vec{k}$，求质点沿着 $L$ 从起点运动到终点 $\vec{F}$ 所做的功。

**计算公式：**

设 $L$ 是由参数方程 $\vec{x}(t)=(x_1(t),···,x_n(t))$，$t:\alpha\rightarrow\beta$ 定义的光滑定向曲线. 设$\vec{F}=(F_1(\vec{x}),···,F_n(\vec{x}))$ 是 $L$ 上连续的向量值函数，则 $\vec{F}$ 在 $L$ 上的第二类曲线积分存在，且：  

**一般形式：**

$$\int\limits_L\vec{F}·d\vec{x}=\int_{\alpha}^{\beta}\sum\limits_{i=1}^nF_i[\vec{x}(t)]·x_i'(t)dt$$  

**n=3：**

$$\int\limits_LP(x,y,z)dx+Q(x,y,z)dy+R(x,y,z)dz=\int_{\alpha}^{\beta}[P(t)x'(t)+Q(t)y'(t)+R(t)z'(t)]dt$$  

**n=2：**

$$\int\limits_LP(x,y)dx+Q(x,y)dy=\int_{\alpha}^{\beta}[P(t)x'(t)+Q(t)y'(t)]dt$$  

***

## 6.2 曲面积分

### 第一类曲面积分  

**具体情境：**

对于空间上一个具有质量的曲面 $\Sigma$，在每一点 $(x,y,z)$ 处都有面密度 $\rho(x,y,z)$，求曲面的质量。

**计算公式：**

设 $\Sigma$ 是由 $\vec{r}(u,v)=(x(u,v),y(u,v),z(u,v))$，$(u,v)\in D$ 确定的光滑平面，设 $f(x,y,z)$ 是定义在 $\Sigma$ 上的实值函数，若 $f$ 在 $\Sigma$ 上连续，则 $f$ 在 $\Sigma$ 上的第一类曲面积分存在，且：  

**参数形式：**

$$\iint\limits_{\Sigma}f(x,y,z)dS=\iint\limits_Df(u,v)\sqrt{[\frac{\partial(y,z)}{\partial(u,v)}]^2+[\frac{\partial(z,x)}{\partial(u,v)}]^2+[\frac{\partial(x,y)}{\partial(u,v)}]^2}dudv$$  

**非参数形式：**

$$\int\limits_{\Sigma}f(x,y,z)dS=\iint\limits_Df(x,y,z(x,y))\sqrt{1+z_x^2(x,y)+z_y^2(x,y)}dxdy$$  

### 第二类曲面积分

**具体情境：**

对于空间上一个双侧曲面 $\Sigma$，在每一点 $(x,y,z)$ 处都有水流流过，其流速为 $\vec{v}=P(x,y,z)\vec{i}+Q(x,y,z)\vec{j}+R(x,y,z)\vec{k}$，求单位时间内通过曲面 $\Sigma$ 的流量。  

**计算公式：**

**参数形式：**

$$\iint\limits_{\Sigma}P(x,y,z)dydz+Q(x,y,z)dzdx+R(x,y,z)dxdy=\pm\iint\limits_D[P(u,v)\frac{\partial(y,z)}{\partial(u,v)}+Q(u,v)\frac{\partial(z,x)}{\partial(u,v)}+R(u,v)\frac{\partial(x,y)}{\partial(u,v)}]dudv$$  

根据定向来决定正负。  

**非参数形式：**

$$\iint\limits_{\Sigma}P(x,y,z)dydz+Q(x,y,z)dzdx+R(x,y,z)dxdy=\pm\iint\limits_D[-P(x,y,z(x,y))·z_x-Q(x,y,z(x,y))·z_y+R(x,y,z(x,y))]dxdy$$  

当曲面的定向为上侧时，积分号前取 $+$；当曲面的定向为下侧时，积分号前取 $-$。  

***

## 6.3 三大公式

### Green公式

**Green公式：**

设 $D$ 是 $R^2$ 中由有限条分段光滑的曲线所围成的闭区域，若函数 $P(x,y)$，$Q(x,y)$ 在 $D$ 上具有连续偏导数，则  

$$\int\limits_{\partial D}Pdx+Qdy=\iint\limits_D(\frac{\partial Q}{\partial x}-\frac{\partial P}{\partial y})dxdy$$

（第二类曲线积分—二重积分）

其中 $\partial D$ 为 $D$ 的边界，取正向，即诱导定向  

推论：面积计算公式  

$$\sigma(D)=\int\limits_{\partial D}xdy=-\int\limits_{\partial D}ydx=\frac{1}{2}\int\limits_{\partial D}(xdy-ydx)$$  

!!! Example
    **例1：计算 $I=\int\limits_L(e^x\sin y-my)dx+(e^x\cos y-m)dy$，其中 $L$ 为圆 $(x-a)^2+y^2=a^2$，$a>0$ 的上半圆周，方向从 $A(2a,0)$ 到原点 $O(0,0)$。**  

    添加一条直线 $\overline{OA}$，方向从 $O$ 指向 $A$，形成闭区域 $D$  
    令 $P=e^x\sin y-my$  
    $Q=e^x\cos y-m$  
    则 $\frac{\partial P}{\partial y}=e^x\cos y-m$  
    $\frac{\partial Q}{\partial x}=e^x\cos y$  
    由Green公式：  
    $I+\int\limits_{\overline{OA}}[(e^x\sin y-my)dx+(e^x\cos y-m)dy]=\iint\limits_Dmdxdy=\frac{m\pi a^2}{2}$  
    再计算沿 $\overline{OA}$ 方向的曲线积分  
    $\int\limits_{\overline{OA}}[(e^x\sin y-my)dx+(e^x\cos y-m)dy]=\int_0^{2a}(0dx+0)=0$  
    综上：$I=\frac{m\pi a^2}{2}$  

!!! Example
    **例2：计算 $I=\int\limits_L\frac{xdy-ydx}{x^2+y^2}$，其中 $L$ 为单位圆周 $x^2+y^2=1$，方向取逆时针方向。**  

    由于 $\frac{\partial Q}{\partial x}$ 和 $\frac{\partial P}{\partial y}$ 在 $(0,0)$ 处均不连续  
    因此不能盲目套用公式  
    正确做法：  
    取充分小的正数 $\varepsilon$  
    使得曲线 $C_{\varepsilon}:x^2+y^2=\varepsilon^2$ 位于 $L$ 所围曲线的内部  
    令 $D_{\varepsilon}$ 为曲线$ L$ 与曲线 $C_{\varepsilon}$ 所围的区域，取 $C_{\varepsilon}$ 的方向为逆时针  
    令 $P(x,y)=-\frac{y}{x^2+y^2}$，$Q(x,y)=\frac{x}{x^2+y^2}$  
    由Green公式可得：$\int\limits_{D_{\varepsilon}}Pdx+Qdy=0$  
    从而 $0=\int\limits_L\*+\int\limits_{-C_{\varepsilon}}\*$  
    （因为在Green中，$C_{\varepsilon}$ 应当是顺时针的）

!!! Note
    $I=\int\limits_{C_{\varepsilon}}*=\frac{1}{\varepsilon^2}·2\pi·\varepsilon^2=2\pi$  

**Green定理：**

设 $D$ 是平面上的单连通区域，若函数 $P$，$Q$，$\frac{\partial P}{\partial y}$，$\frac{\partial Q}{\partial x}$ 都在 $D$ 上连续，则下列命题等价：  

* 对于 $D$ 内任意一条分段光滑的闭曲线 $L$，都有 $\oint\limits_LPdx+Qdy=0$  
* 对于 $D$ 内任意一条分段光滑的曲线 $L$，第二类曲线积分 $\int\limits_LPdx+Qdy$ 与路径无关，只与起点和终点有关  
* 存在 $D$ 上的可微函数 $U(x,y)$，使得 $dU=Pdx+Qdy$，即 $Pdx+Qdy$ 为 $U(x,y)$ 的全微分  
* 在 $D$ 内处处成立 $\frac{\partial P}{\partial y}=\frac{\partial Q}{\partial x}$  

!!! Tip "Proof"
    **1推2：**      

    取两点 $A$，$B$，从 $A$ 到 $B$ 有两条曲线 $L_1$，$L_2$
    $L_1$，$L_2$ 构成封闭曲线 $L=L_1\cup(-L_2)$  
    由1可知：$\oint\limits_L\*=0$  
    因此 $\int\limits_{L_1}\*+\int\limits_{-L_2}\*=0$  
    $\int\limits_{L_1}\*=\int\limits_{L_2}\*$  
    路径无关性得证  

    **4推1：**

    由Green公式即可得证

    **3推4：**

    由全微分公式：  
    $P=\frac{\partial U}{\partial x}$，$Q=\frac{\partial U}{\partial y}$  
    因此：$\frac{\partial Q}{\partial x}=\frac{\partial}{\partial x}(\frac{\partial U}{\partial y})$  
    $\frac{\partial P}{\partial y}=\frac{\partial}{\partial y}(\frac{\partial U}{\partial x})$  
    于是 $\frac{\partial P}{\partial y}=\frac{\partial Q}{\partial x}$ 得证  

    **2推3：**  

    在 $D$ 内任意取定一点 $A(x_0,y_0)$  
    对于 $D$ 内任意一点 $(x,y)$  
    由2可定义：$U(x,y)=\int\limits_LPdx+Qdy$  
    取 $B(x,y)$，$C(x+\Delta x,y)$  
    则 $U(x+\Delta x,y)-U(x,y)=\int\limits_{BC}Pdx+Qdy=\int_x^{x+\Delta x}P(t,y)dt$  
    由积分中值定理：上式 $=P(x+\theta\Delta x,y)·\Delta x$  
    其中 $0\leqslant\theta\leqslant 1$  
    因此：$\frac{\partial U}{\partial x}=\lim\limits_{\Delta x\rightarrow 0}\frac{U(x+\Delta x,y)-U(x,y)}{\Delta x}=\lim\limits_{\Delta x\rightarrow 0}P(x+\theta\Delta x,y)=P(x,y)$  
    同理：$\frac{\partial U}{\partial y}=Q(x,y)$  
    又由 $P$，$Q$ 连续  
    $U(x,y)$ 在 $D$ 内可微，即对应的全微分，3得证  

对于 $U$，可以有如下取法：  

* $U(x,y)=\int_{x_0}^xP(x,y_0)dx+\int_{y_0}^yQ(x,y)dy+C$  
* $U(x,y)=\int_{x_0}^xP(x,y)dx+\int_{y_0}^yQ(x_0,y)dy+C$  

### Gauss公式

设 $\Omega$ 是由 $R^3$ 中分片光滑的曲面所围成的有界闭区域，假设其可以同时分解为有限个 $xy$，$yz$，$zx$ 型区域，若函数 $P$，$Q$，$R$，$\frac{\partial P}{\partial x}$，$\frac{\partial Q}{\partial y}$，$\frac{\partial R}{\partial z}$ 都在 $\Omega$ 上连续，则  

$$\iint\limits_{\partial\Omega}Pdydz+Qdzdx+Rdxdy=\iiint\limits_{\Omega}(\frac{\partial P}{\partial x}+\frac{\partial Q}{\partial y}+\frac{\partial R}{\partial z})dxdydz$$

（第二类曲面积分-三重积分）

其中 $\partial \Omega$ 为 $\Omega$ 的边界，取外侧为正向，即诱导定向.  

推论：体积计算公式  

$$V=\iiint\limits_{\Omega}dxdydz=\iint\limits_{\partial\Omega}xdydz=\iint\limits_{\partial\Omega}ydzdx=\iint\limits_{\partial\Omega}zdxdy=\frac{1}{3}\iint\limits_{\partial\Omega}xdydz+ydzdx+zdxdy$$  

### Stokes公式

设 $\Sigma$ 为光滑曲面，其边界 $\partial\Sigma$ 为分段光滑闭曲线，若函数 $P(x,y,z)$，$Q(x,y,z)$，$R(x,y,z)$在$\Sigma$ 及其边界 $\partial\Sigma$ 上具有连续偏导数，则  

$$\int\limits_{\partial\Sigma}Pdx+Qdy+Rdz=\iint\limits_{\Sigma}\left|\begin{array}{c}
dydz&dzdx&dxdy\\\
\frac{\partial}{\partial x}&\frac{\partial}{\partial y}&\frac{\partial}{\partial z}\\\
P&Q&R  
\end{array}\right|=\iint\limits_{\Sigma}(\frac{\partial R}{\partial y}-\frac{\partial Q}{\partial z})dydz+(\frac{\partial P}{\partial z}-\frac{\partial R}{\partial x})dzdx+(\frac{\partial Q}{\partial x}-\frac{\partial P}{\partial y})dxdy$$

（第二类曲线积分—第二类曲面积分）  