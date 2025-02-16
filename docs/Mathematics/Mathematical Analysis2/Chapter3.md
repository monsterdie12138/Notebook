---
comments: true
---

<span style="font-family: 'Times New Roman';">

# Chapter3 Euclid空间

***

## 3.1 Euclid空间的基本概念

### 点集的相关定义

**定义：**
 
$\forall x\in R^n$，$\forall E\subseteq R^n$  

* 称 $x$ 是 $E$ 的一个**内点**，若 $\exists\delta>0$，使得 $O(x,\delta)\subseteq E$  
*  $x$ 是 $E$ **外点**，若 $\exists\delta>0$，使得 $O(x,\delta)\cap E=\emptyset$  
* 称 $x$ 是 $E$ 的一个**边界点**，若 $\forall\delta>0$，有 $O(x,\delta)\cap E\neq\emptyset$ 且 $O(x,\delta)\cap(C_{R^n}E)\neq\emptyset$  
* $E$ 的全体内点组成的集合称为 $E$ 的**内部**，记作 $E^o$ 或 $intE$  
* $E$ 的全体边界点组成的集合称为 $E$ 的**边界**，记作 $\partial E$  
* 称 $x$ 是 $E$ 的一个**聚点**，若 $\forall\delta>0$，$O(x,\delta)$ 中有 $E$ 的无穷多个点  
* $E$ 的全体聚点组成的集合称为 $E$ 的**导集**，记作 $E'$  
* 称 $x$ 是 $E$ 的一个**孤立点**，若 $\exists\delta>0$，使得 $O(x,\delta)\cap E=\{x\}$  
* 定义 $\bar{E}=E\cup E'$ 为 $E$ 的**闭包**.  
* 称 $E$ 是 $R^n$ 中的**开集**，如果 $E$ 中的每一个点都是 $E$ 的内点，即 $E^o=E$  
* 称 $E$ 是 $R^n$ 中的**闭集**，如果 $E$ 中的每一个聚点都属于 $E$，即 $E=\bar{E}$  
* 称 $E$ 是 $R^n$ 中的**紧集**，如果 $E$ 的任意一个开覆盖中总存在一个有限子覆盖包含 $E$  

**性质：**

* 内点必属于 $E$，外点必不属于 $E$，边界点可能属于 $E$，也可能不属于 $E$  
* 孤立点必是边界点  
* 内点必是聚点，不是孤立点的边界点必是聚点. 聚点可能属于 $E$，也可能不属于 $E$  

### Euclid空间上的基本定理

**聚点的充要条件：**

$x$ 是点集 $E$ 的聚点的充要条件为：存在点列 $\\{x_k\\}$ 满足 $x_k\in E$ 且 $x_k\neq x$，使得 $\lim\limits_{k\rightarrow\infty}x_k=x$。  

**Cauchy收敛原理：**

$R^n$ 上的点列 $\\{x_n\\}$ 收敛的充要条件为：对于 $\forall\varepsilon>0$，$\exists N\in N^*$，使得对于$\forall m,n>N$，都有 $|x_m-x_n|<\varepsilon$。 

**闭集套原理：**

设$\\{E_m\\}$是$R_n$中的一列非空闭集，且满足：  

* $\forall m\geqslant 1$，$E_{m+1}\subset E_m$  
* $\lim\limits_{m\rightarrow\infty}diamE_m=0$，其中 $diamE=\sup\{|x-y||x,y\in E\}$  

则存在唯一的 $x\in R^n$，使得 $x\in\bigcap\limits_{m=1}^{\infty}E_m$  

推论：对于$\forall\varepsilon>0$，$\exists N\in N^*$，当 $n>N$ 时，有 $E_n\subset U(x,\varepsilon)$  

**Bolzano-Weierstrass定理：**

$R^n$ 中的任一有界点列必有收敛子列。

**聚点定理：**

$R^n$ 中的有界无限点集必存在聚点。

**Heine-Borel定理：**

设 $E\in R^n$，则下列命题等价：  

* $E$ 是 $R^n$ 中的紧集  
* $E$ 是 $R^n$ 中的有界闭集  
* $E$ 的任何一个无限子集在 $E$ 中都有聚点 

***

## 3.2 多元连续函数

### 多元函数的极限

**多元函数的收敛与极限：**

设 $D$ 是 $R^n$ 上的开集，$x_0=(x_1^0,x_2^0,···,x_n^0)\in D$，$f(x)$ 为 $D\backslash\{x_0\}$ 上的 $n$ 元函数，$A\in R$，若  

$$\forall \varepsilon>0,~\exists\delta>0,~\forall x\in O^o(x_0,\delta),~|f(x)-A|<\varepsilon$$  

则称 $x$ 趋于 $x_0$ 时 $f(x)$ **收敛**，**极限**为 $A$，记为  

$$\lim\limits_{x\rightarrow x_0}f(x)=A$$  

注意：在上面的定义中，$x\in O^o(x_0,\delta)$ 可以换成：  

$$|x_1-x_1^0|<\delta,|x_2-x_2^0|<\delta,···,|x_n-x_n^0|<\delta$$

**极限的性质：**

若自变量沿不同曲线趋于同一定点时，极限不同或不存在，则该点极限一定不存在。

!!! Example 
    $f(x,y)=\frac{xy}{x^2+y^2}$，$(x,y)\neq(0,0)$  
    考虑沿直线 $y=mx$ 趋于 $(0,0)$  
    则 $\lim\limits_{x\rightarrow 0}f(x,y)=\lim\limits_{x\rightarrow 0}\frac{mx^2}{x^2+m^2x^2}=\frac{m}{1+m^2}$  
    对于不同的 $m$ 极限不同，因此极限不存在     

即使点 $x$ 沿任意直线趋于 $x_0$ 的极限均存在且相等，$f$ 在 $x_0$ 处仍不一定有极限。

!!! Example  
    $f(x,y)=\frac{(y^2-x)^2}{y^4+x^2}$，$(x,y)\neq(0,0)$  
    同样地，设直线 $y=mx$  
    计算可得沿直线趋于 $(0,0)$ 时 $f$ 极限均为 $1$  
    但考虑曲线 $y^2=x$  
    $\lim\limits_{x\rightarrow 0}f(x,y)=\lim\limits_{x\rightarrow 0}\frac{(x-x)^2}{2x^2}=0$   
    极限不同，因此极限不存在  

### 累次极限

**二次极限：**

设 $D$ 为 $R^2$ 上的开集，$(x_0,y_0)\in D$，$f(x,y)$为 $D\backslash\\{x_0\\}$ 上的二元函数，若对于每个固定的 $y\neq y_0$，极限 $\lim\limits_{x\rightarrow x_0}f(x,y)$ 均存在，且极限  

$$\lim\limits_{y\rightarrow y_0}\lim\limits_{x\rightarrow x_0}f(x,y)$$  

存在，则此极限为 $f$ 在 $(x_0,y_0)$ 处先对 $x$ 后对 $y$ 的**二次极限**。

二次极限存在不能保证二重极限存在。

**二次极限和二重极限的关系：**  

若二重极限存在，则两个二次极限可能都不存在。

!!! Example
    $f(x,y)=\begin{cases}
        (x^2+y^2)\sin\frac{1}{x}\cos\frac{1}{y},~~~~x,y\neq0\\\
        0,~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~x=0||y=0
    \end{cases}$    
    由于 $|f(x,y)|\leqslant x^2+y^2$    
    因此 $\lim\limits_{(x,y)\rightarrow (0,0)}f(x,y)=0$，即二重极限存在     
    但在 $(0,0)$ 处两个二次极限均不存在。 

若二重极限存在，则两个二次极限可能一个存在，一个不存在。

!!! Example
    $f(x,y)=\begin{cases}
        y\sin\frac{1}{x},~~~~~x,y\neq0\\\
        0,~~~~~~~~~~~~~~x=0||y=0
    \end{cases}$  
    在 $(0,0)$ 处显然有 $\lim\limits_{(x,y)\rightarrow (0,0)}f(x,y)=0$，即二重极限存在  
    且 $\lim\limits_{x\rightarrow 0}(\lim\limits_{y\rightarrow 0}y\sin\frac{1}{x})=0$  
    但先对 $x$ 后对 $y$ 的二次极限不存在。  

若 $f(x,y)$ 在 $(x_0,y_0)$ 点存在二重极限  

$$\lim\limits_{(x,y)\rightarrow (x_0,y_0)}f(x,y)=A$$  

且当 $x\neq x_0$ 时存在极限  

$$\lim\limits_{y\rightarrow y_0}f(x,y)=\varphi(x)$$  

则 $f$ 在 $(x_0,y_0)$ 点的先对 $y$ 后对 $x$ 的二次极限存在，且等于 $A$。  

同理：在二重极限存在的情况下，若当 $y\neq y_0$ 时有 $\lim\limits_{x\rightarrow x_0}f(x,y)$ 存在，则 $f$ 在 $(x_0,y_0)$ 点的先对 $x$ 后对 $y$ 的二次极限存在，且等于 $A$.  

综上，若 $f$ 的二重极限和两个二次极限均存在，则三者相等，此时极限运算可以交换次序。  

### 多元函数的连续性

设 $D$ 是 $R^n$ 上的开集，$f$ 是定义在 $D$ 上的函数，$x_0\in D$，若  

$$\lim\limits_{x\rightarrow x_0}f(x)=f(x_0)$$  

则称 $f$ 在 $x_0$ 处**连续**。  

$\varepsilon-\delta$ 语言：  

$$\forall \varepsilon>0,~\exists \delta>0,~\forall x\in O(x_0,\delta),~|f(x)-f(x_0)|<\varepsilon$$  

***

## 3.3 连续函数的性质

**定理一：**

连续映射将紧集映射成紧集。  

**定理二：**

设 $K$ 是 $R^n$ 中紧集，$f$ 是 $K$ 上的连续函数，则 $f$ 在 $K$ 上有界。  

**定理三：**

设 $K$ 是 $R^n$ 中紧集，$f$ 是 $K$ 上的连续函数，则 $f$ 在 $K$ 上能取到最大值和最小值。  

**定理四：**

设 $K$ 是 $R^n$ 中紧集，$f:K\rightarrow R^m$ 为连续映射，则 $f$ 在 $K$ 上一致连续。  