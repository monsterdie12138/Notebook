---
comments: true
---

<span style="font-family: 'Times New Roman';">

# Chapter1 线性映射

***

## 1.1 向量空间的积与商

### 向量空间的积

**积的定义：**

设 $V_1,V_2,···V_n$ 为 $F$ 上的 $n$ 个线性空间，定义:  

$$V_1\times V_2\times ··· \times V_n=\\{(v_1,v_2,···,v_n)|v_1 \in V_1,v_2 \in V_2,···,v_n \in V_n\\}= \prod\limits_{i=1}^{n}V_i$$  

为这些线性空间的**积**。（其为线性空间）  

$$\dim(V_1\times V_2\times ··· \times V_n)=\dim V_1+\dim V_2+···+\dim V_n$$ 

**积与直和：**

设 $U_1,···,U_m$ 均为 $V$ 的子空间，线性映射 $\Gamma$：$U_1\times···\times U_m\rightarrow U_1+···+U_m$，定义为  

$$\Gamma(u_1,···,u_m)=u_1+···+u_m$$ 

则 $U_1+···+U_m$ 为直和当且仅当 $\Gamma$ 是单射。

$U_1+···+U_m$ 是直和当且仅当 

$$\dim(U_1+···+U_m)=\dim U_1+···+\dim U_m$$  

**仿射子集：**

设线性空间 $V(F)$，$U$ 是其一子空间，任取 $v\in V$，$v+U:=\\{v+\alpha|\alpha\in U\\}$ 是 $V$ 的子集合，称为**仿射子空间（仿射子集）**（不等于子空间），称仿射子集 $v+U$ **平行**于 $U$（$v+U//U$）  

### 向量空间的商

**商空间：**

设 $U$ 是 $V$ 的子空间，

$$V/U=\\{v+U|v\in V\\}$$

为**商空间**，即仿射子集组成的集合。  

商空间是向量空间，平行于$U$的两个仿射子集相等或不相交。以下命题等价：  

* $v-w\in U$  
* $v+U=w+U$  
* $(v+U)\cap (w+U)\neq\emptyset$  

!!! Tip "Proof"  

    **a 推 b：**

    若 $u\in U$  
    则 $v+u=w+[(v-w)+u]\in w+U$  
    $v+U\subseteq w+U$  
    反之亦然，证毕。  

    **b 推 c：**

    显然。   

    **c 推 a：**

    存在 $u_1,u_2\in U$  
    $v+u_1=w+u_2$  
    $v-w=u_2-u_1\in U$，证毕。  

**商映射：**  

设线性空间 $V$，$U$ 为 $V$ 的子空间，定义映射 $\pi:V\rightarrow V/U$：

$$\pi(\alpha)=\alpha+U$$

$\pi$为**商映射**。（其为线性映射）  

$$\dim V/U=\dim V-\dim U$$  

**$T$诱导的线性映射$\tilde{T}$：**  

设 $T\in L(V,W)$，定义 $\tilde{T}:V/(null~T)\rightarrow W$：  

$$\tilde{T}(v+null~T)=T(v)$$  

其中 $v+null~T$ 是仿射子集，为商空间 $V/(null~T)$ 的一个元素。

* $\tilde{T}$ 是线性映射  
* $\tilde{T}$ 是单射  
* $range~\tilde{T}=range~T$  
* $V/(null~T)$ 与 $range~T$ 同构  

若将 $\tilde{T}$ 视为到 $range~T$ 的映射，则 $\tilde{T}$ 是 $V/(null~T)$ 到 $range~T$ 的同构。

***

## 1.2 对偶

### 对偶空间与对偶映射

**线性泛函：**

$V$ 上的**线性泛函**是 $V$ 到 $F$ 上的线性映射，即为 $L(V,F)$ 中的元素。 

**对偶空间：**

$V$ 上所有的线性泛函构成的线性空间称为 **对偶空间**，记为 $V'$，即 $V'=L(V,F)$  

$$\dim V'=\dim V$$  

**对偶基：**

设 $V$ 的一组基为 $v_1,v_2,···,v_n$，则 $v_1,v_2,···,v_n$ 的**对偶基**是 $V'$ 中的元素组 $\varphi_1,\varphi_2,···,\varphi_n$，其中每个 $\varphi$ 都是 $V$ 上的线性泛函，且满足：  

$$\varphi_i(v_j)=\begin{cases}
1, i=j\\\
0, i\neq j
\end{cases}$$  

对偶基是对偶空间的一组基。例如：在 $R^5$ 中，对偶基 $\varphi_j(x_1,x_2,x_3,x_4,x_5)=x_j$  

**对偶映射：**

若 $T\in L(V,W)$，则 $T$ 的**对偶映射**是线性映射  $T'\in L(W',V')$:  

$$\forall \varphi\in W',~T'(\varphi)=\varphi\circ T$$  

对偶映射是线性映射。  

!!! Example
    **例：**  

    定义 $D:P(R)\rightarrow P(R)$ 为 $D(p)=p'$，表示求导   
    设线性泛函 $\varphi$：$\varphi(p)=p(3)$  
    对偶映射 $D'(\varphi)=\varphi\circ D$  
    $D'(\varphi)(p)=\varphi\circ D(p)=p'(3)$  
    也就是说，$D'(\varphi)$ 是 $P(R)$ 上将 $p$ 变为 $p'(3)$ 的线性泛函  

**对偶映射的性质：**

* 若 $S$，$T\in L(V,W)$，则 $(S+T)'=S'+T'$  
* $(\lambda T)'=\lambda T'$  
* 若 $S\in L(V,W)$，$ T\in L(U,V)$，则 $(S\circ T)'=T'\circ S'$   

### 对偶的零空间和值域

**零化子：**  

设 $U\subseteq V$，即 $U$ 是 $V$ 的子集（不一定是子空间），则**零化子**  

$$U^0=\\{\varphi \in V'|\varphi(u)=0,\forall u\in U\\}$$  

即：$U$ 的零化子是所有能将 $U$ 中元素映射到 $0$ 的线性泛函组成的集合。

$U^0$ 是 $V'$ 的子空间。当 $U$ 是 $V$ 的子空间时，有 

$$\dim U+\dim U^0=\dim V$$  

**$T$，$T'$的核空间与像空间：**  

设 $V$，$W$ 都为有限维，$T\in L(V,W)$  

* $null~T'=(range~T)^0$  
* $range~T'=(null~T)^0$  
* $\dim null~T'=\dim null~T+\dim W-\dim V$  
* $\dim range~T'=\dim range~T$  
* $T$ 是满的 $\Longleftrightarrow$ $T'$ 是单的  
* $T$ 是单的 $\Longleftrightarrow$ $T'$是满的  

!!! Tip "Proof"
    **证明：（第一条）**  

    **正包含：**

    设 $\varphi\in null~T'$  
    则 $T'(\varphi)=\varphi\circ T=0$  
    $\forall v\in V$  
    有 $\varphi(T(v))=0$  
    因此 $\varphi\in range~T^0$  
    $null~T'\subseteq range~T^0$

    **反包含：**

    设 $\varphi\in range~T^0$  
    则 $\forall v\in V$  
    有 $\varphi(Tv)=T'(\varphi)(v)=0$  
    因此 $\varphi\in null~T'$  
    $range~T^0\subseteq null~T'$

    综上：$null~T'=(range~T)^0$，证毕。    