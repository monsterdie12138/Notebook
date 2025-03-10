---
comments: true
---

<span style="font-family: 'Times New Roman';">

# Chapter4 内积空间上的算子

***

## 4.1 自伴算子与正规算子

### 伴随

**伴随算子：**

设 $T\in L(V,W)$，若 $T^{\*}\in L(W,V)$ 满足：对于任意 $v\in V$ 和任意 $w\in W$ 均有 

$$\langle Tv,~w\rangle=\langle v,~T^{\*}w\rangle$$

则称 $T^{\*}$ 是 $T$ 的**伴随**。  

伴随映射是线性映射。  

!!! Example
    **例：定义 $T$：$R^3\rightarrow R^2$ 为 $T(x_1,x_2,x_3)=(x_2+3x_3,2x_1)$，求 $T^*$。**

    $\langle (x_1,x_2,x_3),T^{\*}(y_1,y_2)\rangle$  
    $=\langle T(x_1,x_2,x_3),(y_1,y_2)\rangle$  
    $=\langle (x_2+3x_3,2x_1),(y_1,y_2)\rangle$  
    $=x_2y_1+3x_3y_1+2x_1y_2$  
    $=\langle (x_1,x_2,x_3),(2y_2,y_1,3y_1)\rangle$  
    因此 $T^*(y_1,y_2)=(2y_2,y_1,3y_1)$  

**伴随的性质：**  

* 对于所有 $S$，$T\in L(V,W)$，都有 $(S+T)^{\*}=S^{\*}+T^*$  
* 对于所有 $\lambda\in F$ 和 $T\in L(V,W)$，都有 $(\lambda T)^{\*}=\overline{\lambda}T^*$  
* 对于所有 $T\in L(V,W)$，都有 $(T^{\*})^*=T$  
* 对于所有 $T\in L(V,W)$ 和 $S\in L(W,U)$，都有 $(ST)^{\*}=T^{\*}S^*$  

**$T^*$的零空间和值域：**  

* $null~T^*=(range~T)^{\perp}$  
* $range~T^*=(null~T)^{\perp}$  
* $null~T=(range~T^*)^{\perp}$  
* $range~T=(null~T^*)^{\perp}$  

**$T^*$的矩阵：**  

!!! Note
    下列结论只能对规范正交基使用。  

设 $T\in L(V,W)$，$e_1,···,e_n$ 是 $V$ 的规范正交基，$f_1,···,f_m$ 是 $W$ 的规范正交基，$(T(e_1),···,T(e_n))=(f_1,···,f_m)A$，$(T^{\*}(f_1),···,T^{\*}(f_m))=(e_1,···,e_n)B$，则 $A$ 和 $B$ 互为**共轭转置**。  

### 自伴 

**自伴算子：**  

设 $T\in L(V)$，若 $T=T^{\*}$，即对于任意 $v,w\in V$ 都有 $\langle Tv,w\rangle=\langle v,Tw\rangle$，则称 $T$ 是**自伴**的。

**自伴算子的性质：**  

* 自伴算子关于 $V$ 的规范正交基的矩阵是对称的  
* 两个自伴算子的和是自伴的，实数和自伴算子的乘积也是自伴的  
* 自伴算子的本征值都是实数（无论是实向量空间还是复向量空间）  
* 在 $C$ 上，只有 $0$ 算子才能使得 $Tv$ 总正交于 $v$  
* 在 $C$ 上，$T$ 是自伴的当且仅当对于任意 $v\in V$ 都有$\langle Tv,v\rangle\in R$  
* 若自伴算子对于所有 $v$ 均有 $\langle Tv,v\rangle=0$，则 $T=0$  

### 正规

**正规算子：**  

设 $T\in L(V)$，若 $T$ 和 $T^{\*}$ 可交换，即

$$TT^{\*}=T^{\*}T$$

则称 $T$ 是**正规**的。

自伴算子显然是正规的。  

**正规算子的性质：**  

* $T$ 是正规的当且仅当对于任意 $v\in V$ 都有 $\Vert Tv\Vert=\Vert T^*v\Vert$  
* 若 $T$ 是正规的，则 $T$ 相应于本征值 $\lambda$ 的本征向量也是 $T^*$ 相应于本征值 $\overline{\lambda}$ 的本征向量  
* 若 $T$ 是正规的，则 $T$ 的相应于不同本征值的向量是正交的  

***

## 4.2 谱定理

**实谱定理：**

设 $F=R$ 且 $T\in L(V)$，则以下条件等价：  

* $T$ 是**自伴**的  
* $V$ 有一个由 $T$ 的本征向量组成的规范正交基  
* $T$ 关于 $V$ 的某个规范正交基具有对角矩阵  

**复谱定理：**

设 $F=C$ 且 $T\in L(V)$，则以下条件等价：  

* $T$ 是**正规**的  
* $V$ 有一个由 $T$ 的本征向量组成的规范正交基  
* $T$ 关于 $V$ 的某个规范正交基具有对角矩阵  

***

## 4.3 正算子与等距同构  

### 正算子

**正算子：**

设算子 $T\in L(V)$，若 $T$ 是自伴的且对于任意 $v\in V$ 都有 $\langle Tv,v\rangle\geqslant0$，则称 $T$ 是**正算子**。（其对应矩阵为半正定矩阵）

若 $U$ 是 $V$ 的子空间，则正交投影 $P_U$ 是正算子。  

每个正算子都有唯一的正平方根。 

**正算子的等价条件：**  

设 $T\in L(V)$，则以下条件等价：  

* $T$ 是正的  
* $T$ 是自伴的且 $T$ 的所有本征值非负  
* $T$ 有正的平方根  
* $T$ 有自伴的平方根  
* 存在 $R\in L(V)$ 使得 $T=R^*R$  

### 等距同构

**等距同构：**  

设算子 $S\in L(V)$，若对于任意 $v\in V$ 均有 $\Vert Sv\Vert=\Vert v\Vert$，则 $S$ 称为**等距同构**，（其对应的矩阵为正交矩阵），即保持范数的算子。

**等距同构的等价条件：**  

设 $S\in L(V)$，则以下条件等价：  

* $S$ 是等距同构
* 对任意 $u,v\in V$ 均有 $\langle Su,Sv\rangle=\langle u,v\rangle$  
* 对 $V$ 中的任意规范正交向量组 $e_1,···,e_n$ 均有 $Se_1,···,Se_n$ 是规范正交的  
* $SS^*=S^*S=I$  
* $S^*$ 是等距同构  
* $S$ 是可逆的且 $S^{-1}=S^*$  

可以看出，等距同构的矩阵 $A$ 满足 $AA^T=A^TA=E$，即正交矩阵。同样可以看出，等距同构是正规的。  

当 $F=C$ 时，$S$ 是等距同构当且仅当 $V$ 有一个由 $S$ 的本征向量组成的规范正交基，相应的本征值的绝对值为 $1$。  

***

## 4.4 极分解与奇异值分解

### 极分解

**极分解：**  

设 $T\in L(V)$，则存在等距同构 $S\in L(V)$，使得 

$$T=S\sqrt{T^*T}$$

即 $V$ 上的每个算子都是一个等距同构和一个正算子的乘积。  

考虑 $F=C$ 的情形，设 $T=S\sqrt{T^{\*}T}$，其中 $S$ 是等距同构，则有一个 $S$ 的本征向量组成的规范正交基，$S$ 关于这组基有对角矩阵；同时，$\sqrt{T^*T}$ 是正算子，因此自伴，由实谱定理，其也关于某组规范正交基有对角矩阵，但是请注意：这两组规范正交基未必是同一组。  

### 奇异值分解

**奇异值：**  

设 $T\in L(V)$，则 $T$ 的**奇异值**即为 $\sqrt{T^{\*}T}$ 的本征值，或者说 $TT^{\*}$ 的本征值的非负平方根，且每个本征值 $\lambda$ 重复 $\dim E(\lambda,\sqrt{T^*T})$ 次。  

由于 $\sqrt{T^*T}$ 是正算子，因此其本征值非负，即 $T$ 的奇异值非负。  

!!! Example
    **例：定义 $T\in L(F^4)$ 为：$T(z_1,z_2,z_3,z_4)=(0,3z_1,2z_2,-3z_4)$，求 $T$ 的奇异值。**  

    $T$ 关于 $F^4$ 的标准基的矩阵为 $\begin{pmatrix}
        0&0&0&0\\\
        3&0&0&0\\\
        0&2&0&0\\\
        0&0&0&-3
    \end{pmatrix}$  
    $T^{\*}$ 对应的矩阵为上述矩阵的共轭转置  
    $T^{\*}T$ 对应的矩阵为两个矩阵相乘，即 $\begin{pmatrix}
        9&0&0&0\\\
        0&4&0&0\\\
        0&0&0&0\\\
        0&0&0&9
    \end{pmatrix}$  
    $\sqrt{T^{\*}T}$ 对应的矩阵的平方就等于上述矩阵  
    容易看出即为 $\begin{pmatrix}
        3&0&0&0\\\
        0&2&0&0\\\
        0&0&0&0\\\
        0&0&0&3
    \end{pmatrix}$  
    因此 $\sqrt{T^{\*}T}$ 的本征值为 $3$，$2$，$0$  
    且 $\dim E(3,\sqrt{T^{\*}T})=2$，$\dim E(2,\sqrt{T^{\*}T})=1$，$\dim E(0,\sqrt{T^*T})=1$  
    因此 $T$ 的奇异值为$3$，$3$，$2$，$0$  

!!! Note
    上例中 $T^*T$ 由于是正算子，因此是自伴的，其对应的矩阵 $A$ 是对称的。若 $A$ 不是对角矩阵，则应先求 $A$ 对应的对角矩阵和变换矩阵。 

**奇异值分解：**  

设 $T\in L(V)$ 有奇异值 $s_1,s_2,···,s_n$，其中 $s_i$ 可能相同，则存在 $V$ 的两组规范正交基 $e_1,e_2,···,e_n$，$f_1,f_2,···f_n$，使得对于任意 $v\in V$，都有：  

$$Tv=s_1\langle v,e_1\rangle f_1+···+s_n\langle v,e_n\rangle f_n$$  

经过变换，即 

$$(Te_1,···,Te_n)=(f_1,···,f_n)\begin{pmatrix}
    s_1&&&0\\\
    &·&&\\\
    &&·&\\\
    0&&&s_n
\end{pmatrix}$$  

也就是说，只要允许我们在处理算子时使用两组不同的基，那么 $V$ 上的每个算子关于 $V$ 的某些规范正交基都有对角矩阵，该对角矩阵由 $T$ 的奇异值组成。

设 $T\in L(V)$，则 $T$ 的奇异值是 $T^{\*}T$ 的本征值的非负平方根，且每个本征值 $\lambda$ 要重复 $\dim E(\lambda,T^*T)$ 次。  

因此，对于之前计算奇异值的例子，若遇到 $T^*T$ 对应的矩阵不是对角矩阵的情况，可以考虑直接计算该矩阵对应的本征值，再分别计算对应本征空间的维数。  