---
comments: true
---

<span style="font-family: 'Times New Roman';">

# Chapter4 多元函数的微分学

***

## 4.1 偏导数和全微分的基本概念

### 偏导数的基本定义

**偏导数：**

设 $D\in R^2$ 为开集，$f(x,y)$ 为定义在 $D$ 上的二元函数，$(x_0,y_0)\in D$，若极限  

$$\lim\limits_{\Delta x\rightarrow0}\frac{f(x_0+\Delta x,y_0)-f(x_0,y_0)}{\Delta x}$$

存在，则称 $f$ 在$(x_0,y_0)$ 关于 $x_0$ **可偏导**，记为$\frac{\partial f}{\partial x}(x_0,y_0)$或$f_x(x_0,y_0)$，对于 $y_0$ 的偏导同理。  

若 $f$ 在 $(x_0,y_0)$ 关于 $x_0$ 和 $y_0$ 都可求偏导，则称 $f$ 在 $(x_0,y_0)$ **可偏导**。偏导数反映的是二元函数沿 $x$ 轴方向或 $y$ 轴方向的变化率。对某个变量求偏导数，只要在求导时将其他变量看作常数就可以了，这一点同样可推广到一般的 $n$ 元函数上。  

**方向导数：**

设 $D\in R^2$ 为开集，$f(x,y)$ 为定义在 $D$ 上的二元函数，$(x_0,y_0)\in D$，$v=(\cos\alpha,\sin\alpha)$ 为一个方向，若极限  

$\lim\limits_{t\rightarrow 0+}\frac{f(x_0+t\cos\alpha,y_0+t\sin\alpha)-f(x_0,y_0)}{t}$  

存在，则称此极限为 $f$ 在 $(x_0,y_0)$ 处沿 $v$ 方向的**方向导数**，记为$\frac{\partial f}{\partial v}(x_0,y_0)$。  

设方向导数 $e_1=(1,0)$，$e_2=(0,1)$，则$f$ 在 $(x_0,y_0)$ 处关于 $x$（或 $y$）可偏导$\Longleftrightarrow$$f$ 沿方向 $e_1$ 和 $-e_1$（$e_2$ 和 $-e_2$）的方向导数都存在且互为相反数，且此时成立  

$$\frac{\partial f}{\partial x}(x_0,y_0)=\frac{\partial f}{\partial e_1}(x_0,y_0)$$   

或 

$$\frac{\partial f}{\partial y}(x_0,y_0)=\frac{\partial f}{\partial e_2}(x_0,y_0)$$ 

**梯度：**

设 $D\in R^2$ 为开集，$f(x,y)$ 为定义在 $D$ 上的二元函数，$(x_0,y_0)\in D$，若 $f$ 在$(x_0,y_0)$处可偏导，则称向量  

$$(f_x(x_0,y_0),f_y(x_0,y_0))$$  

为 $f$ 在 $(x_0,y_0)$ 处的**梯度**，记为  

$$grad~f(x_0,y_0)=f_x(x_0,y_0)i+f_y(x_0,y_0)j$$   
 
**高阶偏导数：**

* $\frac{\partial^2f}{\partial x^2}=\frac{\partial}{\partial x}(\frac{\partial f}{\partial x})=f_{xx}$  
* $\frac{\partial^2f}{\partial x\partial y}=\frac{\partial}{\partial x}(\frac{\partial f}{\partial y})=f_{yx}$  
* $\frac{\partial^2f}{\partial y\partial x}=\frac{\partial}{\partial y}(\frac{\partial f}{\partial x})=f_{xy}$  
* $\frac{\partial^2f}{\partial y^2}=\frac{\partial}{\partial y}(\frac{\partial f}{\partial y})=f_{yy}$  

如果 $f$ 的两个混合偏导数 $f_{xy}$ 和 $f_{yx}$ 在 $(x_0,y_0)$ 处连续，则  

$$f_{xy}(x_0,y_0)=f_{yx}(x_0,y_0)$$  

**向量值函数的导数：**  

设函数 $y=f(x): D\rightarrow R^m$，$D\subset R^n$，其中 $x$，$y$ 为向量
写成坐标形式：  

$\begin{cases}
y_1=f_1(x_1,···,x_n)\\\
···\\\
y_m=f_m(x_1,···,x_n)
\end{cases}$  

其中 $x_i$，$y_i$ 为向量中第 $i$ 个位置的分量。

设 $x^0=(x_1^0,···,x_n^0)\in D$，若 $f$ 的每一个分量函数 $f_i$ 都在 $x^0$ 处可偏导，则称向量值函数 $f$ 在 $x^0$ 处可导，并称矩阵  

$\begin{pmatrix}
    \frac{\partial f_1}{\partial x_1}(x^0)&\frac{\partial f_1}{\partial x_2}(x^0)&···&\frac{\partial f_1}{\partial x_n}(x^0)\\\
    \frac{\partial f_2}{\partial x_1}(x^0)&\frac{\partial f_2}{\partial x_2}(x^0)&···&\frac{\partial f_2}{\partial x_n}(x^0)\\\
    ···&···&&···\\\
    \frac{\partial f_m}{\partial x_1}(x^0)&\frac{\partial f_m}{\partial x_2}(x^0)&···&\frac{\partial f_m}{\partial x_n}(x^0)
\end{pmatrix}$  

为向量值函数 $f$ 在 $x^0$ 处的导数，或者**Jacobi矩阵**。 

### 全微分的基本定义

**全微分：**

设 $D\in R^2$ 为开集，$f(x,y)$ 为定义在 $D$ 上的二元函数，$(x_0,y_0)\in D$，记 $f$ 的**全增量**为  

$$\Delta f=f(x_0+\Delta x,y_0+\Delta y)-f(x_0,y_0)$$

若存在只与 $(x_0,y_0)$ 有关而与 $\Delta x$，$\Delta y$ 无关的常数 $A$，$B$，使得  

$$\Delta f=A\Delta x+B\Delta y+o(\sqrt{(\Delta x)^2+(\Delta y)^2})$$  

则称 $f$ 在 $(x_0,y_0)$ 处是**可微**的，$A\Delta x+B\Delta y$ 为 $f$ 在 $(x_0,y_0)$ 处的**全微分**。

**高阶微分：**

$$d_kf=(dx\frac{\partial}{\partial x}+dy\frac{\partial}{\partial y})^kz$$  

其中将 $\frac{\partial}{\partial x}$ 和 $\frac{\partial}{\partial y}$ 看作求偏导数的运算符号，并规定  

* $(\frac{\partial}{\partial x})^2=\frac{\partial^2}{\partial x^2}$  
* $(\frac{\partial}{\partial y})^2=\frac{\partial^2}{\partial y^2}$  
* $(\frac{\partial}{\partial x})(\frac{\partial}{\partial y})=\frac{\partial^2}{\partial x\partial y}$  

### 可微与可偏导的关系

若 $f$ 在 $(x_0,y_0)$ 处可微，则 $f$ 在 $(x_0,y_0)$ 处连续，即**可微必连续**。  

**可微必可导**，于是得到**全微分公式**：  
  
$$df(x_0,y_0)=f_x(x_0,y_0)dx+f_y(x_0,y_0)dy$$

**可微必定存在方向导数**，只要 $f$ 在 $(x_0,y_0)$ 处可微，则对于任意方向 $v=(\cos\alpha,\sin\alpha)$，都有**方向导数公式**：  

$$\frac{\partial f}{\partial v}(x_0,y_0)=\frac{\partial f}{\partial x}(x_0,y_0)\cos\alpha+\frac{\partial f}{\partial y}(x_0,y_0)\sin\alpha$$  

!!! Tip "Proof"  
    $\frac{\partial f}{\partial v}(x_0,y_0)=\lim\limits_{t\rightarrow 0+}\frac{f(x_0+t\cos\alpha,y_0+t\sin\alpha)-f(x_0,y_0)}{t}$  
    $=\lim\limits_{t\rightarrow 0+}\frac{\frac{\partial f}{\partial x}(x_0,y_0)t\cos\alpha+\frac{\partial f}{\partial y}(x_0,y_0)t\sin\alpha+o(t)}{t}$  
    $=\frac{\partial f}{\partial x}(x_0,y_0)\cos\alpha+\frac{\partial f}{\partial y}(x_0,y_0)\sin\alpha$  

用同样的思想可以定义 $n$ 元函数的全微分，即  

$$du=\frac{\partial f}{\partial x_1}dx_1+\frac{\partial f}{\partial x_2}dx_2+···+\frac{\partial f}{\partial x_n}dx_n$$  

**可偏导不一定可微**。  

!!! Example
    **反例：**  

    $f(x,y)=\begin{cases}
    \frac{xy}{x^2+y^2},~~(x,y)\neq(0,0)\\\
    0,~~~~~~~~(x,y)=(0,0)    
    \end{cases}$  
    $f_x(0,0)=\lim\limits_{\Delta x\rightarrow0}\frac{f(0+\Delta x,0)-f(0,0)}{\Delta x}=0$  
    同理，$f_y(0,0)=0$  
    因此 $f$ 在 $(0,0)$ 处可求偏导  
    但我们已知 $f$ 在 $(0,0)$ 处不连续，因此不可微。  

**连续且方向导数都存在也不一定可微**。  

!!! Example
    **反例：**  

    $f(x,y)=\begin{cases}
        \frac{2xy^3}{x^2+y^4},~~~x^2+y^2\neq 0\\\
        0,~~~~~~~~~~x^2+y^2=0
    \end{cases}$  
    由于 $|f(x,y)|=|\frac{2xy^2}{x^2+y^4}y|\leqslant|\frac{x^2+y^4}{x^2+y^4}y|=|y|$  
    所以 $f(x,y)$ 在 $(0,0)$ 处连续  
    且 $\lim\limits_{t\rightarrow 0+}\frac{f(0+t\cos\alpha,0+t\sin\alpha)-f(0,0)}{t}=\lim\limits_{t\rightarrow 0+}\frac{2\cos\alpha\sin^3\alpha}{\cos^2\alpha+t^2\sin^4\alpha}t=0$  
    即方向导数均存在  
    假设其可微  
    则 $\Delta f-A\Delta x-B\Delta y=f(0+\Delta x,0+\Delta y)-f(0,0)-f_x(0,0)\Delta x-f_y(0,0)\Delta y=f(\Delta x,\Delta y)$  
    令 $\Delta x=\Delta y^2$  
    则 $\lim\limits_{\Delta y\rightarrow0+}\frac{\Delta f-A\Delta x-B\Delta y}{\sqrt{\Delta x^2+\Delta y^2}}=\lim\limits_{\Delta y\rightarrow 0+}\frac{\frac{2\Delta y^5}{\Delta y^4+\Delta y^4}}{\Delta y\sqrt{1+\Delta y^2}}=\lim\limits_{\Delta y\rightarrow 0+}\frac{1}{\sqrt{1+\Delta y^2}}=1\neq0$  
    因此 $f$ 不可微。

**可微的充分条件**：若 $f$ 在 $(x_0,y_0)$ 处的某个邻域内存在偏导数，且偏导数在 $(x_0,y_0)$ 处连续，则 $f$ 在 $(x_0,y_0)$ 处可微。

综上：  

* 偏导数连续$\Longrightarrow$可微  
* 可微$\Longrightarrow$连续，方向导数存在  
* 方向导数存在$\Longrightarrow$偏导数存在  

***

## 4.2 偏导数和全微分的应用

### 链式法则

**二元函数：**

设 $g:(u,v)\mapsto(x(u,v),y(u,v))$  

设 $f:(x,y)\mapsto f(x,y)$  

若 $g$ 在 $(u_0,v_0)$ 处可偏导，$f$ 在 $(x_0,y_0)$ 处可微，则  

$$\frac{\partial f}{\partial u}(u_0,v_0)=\frac{\partial f}{\partial x}(x_0,y_0)\frac{\partial x}{\partial u}(u_0,v_0)+\frac{\partial f}{\partial y}(x_0,y_0)\frac{\partial y}{\partial u}(u_0,v_0)$$  

$$\frac{\partial f}{\partial v}(u_0,v_0)=\frac{\partial f}{\partial x}(x_0,y_0)\frac{\partial x}{\partial v}(u_0,v_0)+\frac{\partial f}{\partial y}(x_0,y_0)\frac{\partial y}{\partial v}(u_0,v_0)$$  

!!! Note
    “$f$ 可微”不能减弱为“$f$ 可偏导”。

!!! Example
    **反例：**  

    $f(x,y)=\begin{cases}
        \frac{x^2y}{x^2+y^2},~~~x^2+y^2\neq0\\\
        0,~~~~~~~~~~x^2+y^2=0
    \end{cases}$  
    $\begin{cases}
        x=t\\\
        y=t
    \end{cases}$  
    $\frac{\partial f}{\partial x}(0,0)=\frac{\partial f}{\partial y}(0,0)=0$  
    直接代入 $t$ 可得：$f=\frac{t}{2}$  
    $f'(0,0)=\frac{1}{2}$  
    但由链式求导法则：$\frac{\partial f}{\partial t}(0,0)=\frac{\partial f}{\partial x}\frac{\partial x}{\partial t}+\frac{\partial f}{\partial y}\frac{\partial y}{\partial t}=0$，矛盾。  

**$n$元函数：**

设 $g:(x_1,···,x_n)\mapsto (y_1,···,y_m)$  

设 $f:(y_1,···,y_m)\mapsto f(y_1,···,y_m)$  

若 $g$ 在 $x^0=(x_1^0,···,x_n^0)$ 处可偏导，$f$ 在 $y^0=g(x^0)$ 处可微，则  

$$\frac{\partial f}{\partial x_i}(x^0)=\frac{\partial f}{\partial y_1}(y^0)\frac{\partial y_1}{\partial x_i}(x^0)+···+\frac{\partial f}{\partial y_m}(y^0)\frac{\partial y_m}{\partial x_i}(x^0)$$  

**向量值函数：**

设向量值函数 $f$ 和 $g$，其分别在定义域内有连续导数，记 $u=g(x)$，那么复合向量值函数 $f\circ g$ 在定义域内也有连续导数，且  

$$(f\circ g)'(x)=f'(u)·g'(x)=f'(g(x))·g'(x)$$  

其中 $f'(u)$，$g'(x)$ 和 $(f\circ g)'(x)$ 是相应的导数，即Jacobi矩阵。  

### 中值定理

**凸区域：**

设 $D\in R^n$，若连结 $D$ 中任意两点的线段都完全属于 $D$，即：

$$\forall x_0,~x_1\in D,~\forall \lambda\in(0,1),~\lambda x_0+(1-\lambda)x_1\in D$  

则称 $D$ 为**凸区域**。  

**中值定理：**

设二元函数 $f(x,y)$ 在凸区域 $D\in R^2$ 上可微，则对于 $D$ 内任意两点 $(x_0,y_0)$ 和 $(x_0+\Delta x,y_0+\Delta y) $，都存在 $\theta\in(0,1)$，使得  

$$f(x_0+\Delta x,y_0+\Delta y)-f(x_0,y_0)=f_x(x_0+\theta\Delta x,y_0+\theta\Delta y)\Delta x+f_y(x_0+\theta\Delta x,y_0+\theta\Delta y)\Delta y$$  

推论：若二元函数 $f(x,y)$ 在区域 $D$（不一定是凸区域）上的两个偏导数 $f_x$，$f_y$ 恒为 $0$，则 $f$ 在 $D$ 上为常值函数。 

### Taylor公式

设函数 $f(x,y)$ 在 $(x_0,y_0)$ 的邻域内具有 $k+1$ 阶连续偏导数，则邻域内每一点 $(x_0+\Delta x,y_0+\Delta y)$ 都成立  

$$f(x_0+\Delta x,y_0+\Delta y)=f(x_0,y_0)+(\Delta x\frac{\partial}{\partial x}+\Delta y\frac{\partial}{\partial y})f(x_0,y_0)+\frac{1}{2!}(\Delta x\frac{\partial}{\partial x}+\Delta y\frac{\partial}{\partial y})^2f(x_0,y_0)+···+\frac{1}{k!}(\Delta x\frac{\partial}{\partial x}+\Delta y\frac{\partial}{\partial y})^kf(x_0,y_0)+R_k$$  

其中：  

$$R_k=\frac{1}{(k+1)!}(\Delta x\frac{\partial}{\partial x}+\Delta y\frac{\partial}{\partial y})^{k+1}f(x_0+\theta\Delta x,y_0+\theta\Delta y),~0<\theta<1$$  

称为**Lagrange余项**。  

$$(\Delta x\frac{\partial}{\partial x}+\Delta y\frac{\partial}{\partial y})^pf(x_0,y_0)=\sum\limits_{i=0}^pC_p^i\frac{\partial^pf}{\partial x^{p-i}\partial y^i}(x_0,y_0)(\Delta x)^{p-i}(\Delta y)^i$$  

若使用**Peano余项**：  

$$f(x_0+\Delta x,y_0+\Delta y)=f(x_0,y_0)+(\Delta x\frac{\partial}{\partial x}+\Delta y\frac{\partial}{\partial y})f(x_0,y_0)+\frac{1}{2!}(\Delta x\frac{\partial}{\partial x}+\Delta y\frac{\partial}{\partial y})^2f(x_0,y_0)+···+\frac{1}{k!}(\Delta x\frac{\partial}{\partial x}+\Delta y\frac{\partial}{\partial y})^kf(x_0,y_0)+o((\sqrt{(\Delta x)^2+(\Delta y)^2})^k)$$  

### 隐函数

**一元隐函数存在定理：**

若二元函数 $F(x,y)$ 满足条件：  

* $F(x_0,y_0)=0$  
* 在闭矩形 $D=\{(x,y)||x-x_0|\leqslant a,|y-y_0|\leqslant b\}$ 上，$F$ 连续且有连续偏导数  
* $F_y(x_0,y_0)\neq 0$  

则  

* 在 $(x_0,y_0)$ 附近可由 $F(x,y)=0$ 唯一确定隐函数 $y=f(x)$  
* 隐函数 $y=f(x)$ 在 $x_0$ 的邻域内连续  
* 隐函数 $y=f(x)$ 在 $x_0$ 的邻域内有连续的导数，且  
  $\frac{dy}{dx}=-\frac{F_x(x,y)}{F_y(x,y)}$

**多元函数隐函数存在定理：**

若 $n+1$ 元函数 $F(x_1,x_2,···,x_n,y)$ 满足条件：

* $F(x_1^0,x_2^0,···,x_n^0,y^0)=0$
* 在闭长方体 $D=\{(x_1,x_2,···,x_n,y)||y-y_0|\leqslant b,|x_i-x_i^0|\leqslant a_i\}$ 上，函数 $F$ 连续，且有连续偏导数  
* $F_y(x_1^0,x_2^0,···,x_n^0,y_0)\neq 0$  

则  

* 在 $(x_1^0,x_2^0,···,x_n^0,y_0)$ 附近可由 $F(x_1,x_2,···,x_n,y)=0$ 唯一确定隐函数 $y=f(x_1,x_2,···,x_n)$  
* 隐函数 $y=f(x_1,x_2,··,x_n)$ 在 $(x_1^0,x_2^0,···,x_n^0)$ 的邻域内连续  
* 隐函数 $y=f(x_1,x_2,··,x_n)$ 在 $(x_1^0,x_2^0,···,x_n^0)$ 的邻域内有连续的偏导数，且  
  $\frac{\partial y}{\partial x_i}=-\frac{F_{x_i}(x_1,x_2,···,x_n,y)}{F_y(x_1,x_2,···,x_n,y)}$  

在具体计算中，方程  

$$F(x_1,x_2,···,x_n,y)=0$$  

所确定的隐函数 $y=f(x_1,x_2,···,x_n)$ 的偏导数通常可如下计算：在方程两边对 $x_i$ 求偏导，利用链式法则即可得到：  

$$\frac{\partial F}{\partial x_i}+\frac{\partial F}{\partial y}\frac{\partial y}{\partial x_i}=0$$  

**多元向量值隐函数存在定理：**

设 $F(x,y,u,v)$ 和 $G(x,y,u,v)$ 满足条件：

* $F(x_0,y_0,u_0,v_0)=G(x_0,y_0,u_0,v_0)=0$  
* 在与前两种情况类似的闭长方体中 $F$，$G$ 连续，且有连续偏导数  
* 在 $(x_0,y_0,u_0,v_0)$ 处，行列式  
  $\frac{\partial (F,G)}{\partial (u,v)}=
  \left|\begin{array}{c}
  F_u&F_v\\\
  G_u&G_v
  \end{array}\right|\neq 0$  

则  

* 在 $(x_0,y_0,u_0,v_0)$ 附近可以由函数方程组  
  $\begin{cases}
    F(x,y,u,v)=0\\\
    G(x,y,u,v)=0
  \end{cases}$  
  唯一确定向量值隐函数  
  $\begin{pmatrix}
  u\\\
  v
  \end{pmatrix}=
  \begin{pmatrix}
  f(x,y)\\\
  g(x,y)
  \end{pmatrix}$  

* 这个向量值隐函数在 $(x_0,y_0)$ 附近连续  
* 这个向量值隐函数在 $(x_0,y_0)$ 附近有连续的导数，且  
  $\begin{pmatrix}
    \frac{\partial u}{\partial x}&\frac{\partial u}{\partial y}\\\
    \frac{\partial v}{\partial x}&\frac{\partial v}{\partial y}
  \end{pmatrix}=-
  \begin{pmatrix}
  F_u&F_v\\\
  G_u&G_v
  \end{pmatrix}^{-1}
  \begin{pmatrix}
  F_x&F_y\\\
  G_x&G_y
  \end{pmatrix}$  

### 空间几何

**曲线的法平面与切线：**

**类型一：**

$$\begin{cases}
    F(x,y,z)=0\\\
    G(x,y,z)=0
\end{cases}$$  

法平面方程：  

$$\frac{\partial(F,G)}{\partial(y,z)}\vert_{(P_0)}(x-x_0)+\frac{\partial(F,G)}{\partial(z,x)}\vert_{(P_0)}(y-y_0)+\frac{\partial(F,G)}{\partial(x,y)}\vert_{(P_0)}(z-z_0)=0$$  

切线方程：  

$$\frac{x-x_0}{\frac{\partial (F,G)}{\partial (y,z)}\vert_{(P_0)}}=\frac{y-y_0}{\frac{\partial (F,G)}{\partial (z,x)}\vert_{(P_0)}}=\frac{z-z_0}{\frac{\partial (F,G)}{\partial (x,y)}\vert_{(P_0)}}$$  

**类型二：**

$$\begin{cases}
    x=x(t)\\\
    y=y(t)\\\
    z=z(t)
\end{cases}$$  

法平面方程：  

$$x'(t_0)(x-x_0)+y'(t_0)(y-y_0)+z'(t_0)(z-z_0)=0$$

切线方程：  

$$\frac{x-x_0}{x'(t_0)}=\frac{y-y_0}{y'(t_0)}=\frac{z-z_0}{z'(t_0)}$$  

**曲面的切平面与法线：**

**类型一：$z=f(x,y)$**

切平面方程：  

$$z-z_0=f_x(x_0,y_0)(x-x_0)+f_y(x_0,y_0)(y-y_0)$$  

法线方程：  

$$\frac{x-x_0}{f_x(x_0,y_0)}=\frac{y-y_0}{f_y(x_0,y_0)}=\frac{z-z_0}{-1}$$  

**类型二：$F(x,y,z)=0$**

切平面方程：  

$$F_x(P_0)(x-x_0)+F_y(P_0)(y-y_0)+F_z(P_0)(z-z_0)=0$$  

法线方程：  

$$\frac{x-x_0}{F_x(P_0)}=\frac{y-y_0}{F_y(P_0)}=\frac{z-z_0}{F_z(P_0)}$$  

**类型三：**

$$\begin{cases}
x=x(u,v)\\\
y=y(u,v)\\\
z=z(u,v)
\end{cases}$$

切平面方程：  

$$\frac{\partial (y,z)}{\partial (u,v)}\vert_{(u_0,v_0)}(x-x_0)+\frac{\partial (z,x)}{\partial (u,v)}\vert_{(u_0,v_0)}(y-y_0)+\frac{\partial (x,y)}{\partial (u,v)}\vert_{(u_0,v_0)}(z-z_0)=0$$  

法线方程： 

$$\frac{x-x_0}{\frac{\partial (y,z)}{\partial (u,v)}\vert_{(u_0,v_0)}}=\frac{y-y_0}{\frac{\partial (z,x)}{\partial (u,v)}\vert_{(u_0,v_0)}}=\frac{z-z_0}{\frac{\partial (x,y)}{\partial (u,v)}\vert_{(u_0,v_0)}}$$  

!!! Example
    **例：求证：曲面$S:f(\frac{x-a}{z-c},\frac{y-b}{z-c})=0$ 的任一切平面都经过某一定点，其中 $f$ 连续可微。**  

    令 $F(x,y,z)=f(\frac{x-a}{z-c},\frac{y-b}{z-c})=0$  
    则 $F_x=f_1·\frac{1}{z-c}$  
    $F_y=f_2·\frac{1}{z-c}$  
    $F_z=-\frac{1}{(z-c)^2}[f_1·(x-a)+f_2·(y-b)]$  
    于是对于 $\forall P_0(x_0,y_0,z_0)\in S$  
    $S$ 在 $P_0$ 处的切平面方程为 $F_x(P_0)(x-x_0)+F_y(P_0)(y-y_0)+F_z(P_0)(z-z_0)=0$  
    将在 $P_0$ 处的偏导数代入得到：  
    $f_1(u_0,v_0)(x-x_0)+f_2(u_0,v_0)(y-y_0)-\frac{1}{z_0-c}(f_1(u_0,v_0)(x_0-a)+f_2(u_0,v_0)(y_0-b))(z - z_0)=0$  
    其中 $u_0=\frac{x_0-a}{z_0-c}$，$v_0=\frac{y_0-b}{z_0-c}$  
    令 $(x,y,z)=(a,b,c)$  
    则左式 $=0$  
    定点即为 $(a,b,c)$  

### 无条件极值

**驻点：**

设开区域 $D\subset R^n$，$f(x)$ 为定义在 $D$ 上的函数，$x_0=(x_1^0,x_2^0,···,x_n^0)$ 为 $D$ 上一点，若 $f$ 在 $x_0$ 可偏导，且  

$$f_{x_1}(x_0)=f_{x_2}(x_0)=···=f_{x_n}(x_0)=0$$  

则称 $x_0$ 为 $f$ 的**驻点**。  

若 $f$ 可偏导，则**驻点是极值点的必要条件。**  

偏导数不存在的点也可能是极值点。  

**二元函数的极值点：**

设 $(x_0,y_0)$ 为 $f$ 的驻点，$f$ 在 $(x_0,y_0)$ 附近有二阶连续偏导数，记

* $A=f_{xx}(x_0,y_0)$  
* $B=f_{xy}(x_0,y_0)$  
* $C=f_{yy}(x_0,y_0)$  

并记  

$$H=\left|\begin{array}{c}
   A&B\\\
   B&C
\end{array}\right|=AC-B^2$$  

则  

* 若 $H>0$ 且 $A>0$（正定），则 $f(x_0,y_0)$ 为极小值  
* 若 $H>0$ 且 $A<0$（负定），则 $f(x_0,y_0)$ 为极大值  
* 若 $H<0$，则 $f(x_0,y_0)$ 不是极值  
* 若 $H=0$，则 $f(x_0,y_0)$ 可能是极值，也可能不是极值  

**$n$元函数的极值点：**  

已知驻点和二阶连续偏导数，记  

$$A_k=\begin{pmatrix}
    a_{11}&a_{12}&···&a_{1n}\\\
    a_{21}&a_{22}&···&a_{2n}\\\
    ···&···&&···\\\
    a_{k1}&a_{k2}&···&a_{kk}
\end{pmatrix}$$  

为 $f$ 的 $k$ 阶**Hessian矩阵**，其中 $a_{ij}=f_{x_ix_j}(x_0)$  

则  

* 若 $\det A_k>0(k=1,2,···,n)$，则 $f(x_0)$ 为极小值
* 若 $k$ 为奇数时 $\det A_k<0$，$k$ 为偶数时 $\det A_k>0$，则 $f(x_0)$ 为极大值  
* 其余情况 $f(x_0)$ 不是极值  

### 条件极值

**二元函数的条件极值：**

设函数 $f(x,y)$，已知限制条件 $\varphi(x,y)=0$，则对于 $f$ 的条件极值点 $P_0=(x_0,y_0)$，存在 $\lambda_0$，使得：  

$$\begin{cases}
    L_x(x_0,y_0,\lambda_0)=0\\\
    L_y(x_0,y_0,\lambda_0)=0\\\
    L_\lambda(x_0,y_0,\lambda_0)=0
\end{cases}$$  

其中 

$$L(x,y,\lambda)=f(x,y)+\lambda\varphi(x,y)$$  

**一般情形的条件极值：**

设函数 $f(x_1,x_2,···,x_n)$，已知限制条件 $\varphi_k(x_1,x_2,···,x_n)=0$，$k=1,2,···,m(m<n)$，则对于 $f$ 的条件极值点 $P_0(x_1^0,x_2^0,···,x_n^0)$，存在 $\lambda_1^0,\lambda_2^0,···,\lambda_m^0$，使得：  

$$\begin{cases}
    L_{x_1}=0\\\
    L_{x_2}=0\\\
    ···\\\
    L_{x_n}=0\\\
    L_{\lambda_1}=0\\\
    L_{\lambda_2}=0\\\
    ···\\\
    L_{\lambda_m}=0
\end{cases}$$  

其中 

$$L(x_1,x_2,···,x_n,\lambda_1,\lambda_2,···,\lambda_m)=f(x_1,x_2,···,x_n)+\sum\limits_{k=1}^m\lambda_k\varphi_k(x_1,x_2,···,x_n)$$

!!! Example
    **例：求原点到直线 $\begin{cases}
        x+y+z=1\\\
        x+2y+3z=6
    \end{cases}$ 的最短距离。**  
    求 $f(x,y,z)=x^2+y^2+z^2$ 在上述限制之下的最小值  
    令 $L(x,y,z,\lambda,\mu)=(x^2+y^2+z^2)+\lambda(x+y+z-1)+\mu(x+2y+3z-6)$  
    $\begin{cases}
        2x+\lambda+\mu=0\\\
        2y+\lambda+2\mu=0\\\
        2z+\lambda+3\mu=0\\\
        x+y+z-1=0\\\
        x+2y+3z-6=0
    \end{cases}\Longrightarrow\begin{cases}
    x=-\frac{5}{3}\\\
    y=\frac{1}{3}\\\
    z=\frac{7}{3}\\\
    \lambda=\frac{22}{3}\\\
    \mu=-4
    \end{cases}$  
    由于要求点到直线的最小距离，因此这个问题的最小值必然存在  
    因此唯一可能的极值点 $(-\frac{5}{3},\frac{1}{3},\frac{7}{3})$ 必定为最小值点  
    所求距离 $d=\sqrt{x^2+y^2+z^2}=\frac{5}{\sqrt{3}}$  