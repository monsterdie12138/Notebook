---
comments: true
---

<span style="font-family: 'Times New Roman';">

# Chapter2 本征值、本征向量、不变子空间

***

## 2.1 不变子空间

**不变子空间：**

设线性映射 $T\in L(V)$，$U$ 是 $V$ 的一个子空间，若对于任意 $\alpha \in U$，都有$T(\alpha)\in U$，则称 $U$ 是 $T$ 的**不变子空间**，即被算子映射到自身的子空间。  

**本征值与本征向量：**

设 $T\in L(V)$，若存在 $v\in V$ 且 $v\neq 0$，使得 $T(v)=\lambda v$，则称 $\lambda\in F$ 为 $T$ 的**本征值（特征值）**，相应的 $v$ 称为**本征向量**。  

本征值可为 $0$，本征向量不为 $0$，本征向量满足 $v\in null(T-\lambda I)$。  

相应于不同本征值的本征向量是线性无关的。  

$V$ 上的算子最多有 $\dim V$ 个不同的本征值。 

**限制算子与商算子：**

设 $T\in L(V)$，若 $U$ 是 $T$ 的不变子空间，则称线性映射 

$$T|_U\in L(U):T|_U(\alpha)=T(\alpha)$$ 

为**限制算子**。  

设 $T\in L(V)$，若 $U$ 是 $T$ 的不变子空间，则称线性映射 

$$T/U\in L(V/U):(T/U)(v+U)=T(v)+U$$ 

为**商算子**。  

***

## 2.2 本征向量与上三角矩阵

### 本征值的存在性

有限维复向量空间上的算子都有本征值，实向量空间不一定，例如旋转变换。 

!!! Tip "Proof"  
    设线性空间 $V$，$\dim V=n$  
    设算子 $T\in L(V)$  
    任取 $v\in V$ 且 $v\neq 0$ 
    考虑 $v,Tv,···,T^nv\in V$，共 $n+1$ 个向量  
    这 $n+1$ 个向量线性相关  
    存在不全为零的 $a_i$ 满足：  
    $a_0v+a_1Tv+···+a_nT^nv=0$  
    即 $p(T)(v)=0,p(T)=a_0I+a_1T+···+a_nT^n\neq 0$  
    若 $p(T)=a_0I$  
    则 $a_0I(v)=0\Longrightarrow v=0$，矛盾  
    $p(T)$ 的次数 $\geqslant 1$  
    设 $(T-\lambda_1I)···(T-\lambda_nI)(v)=0$，$\lambda_i\in C$  
    设 $w=(T-\lambda_2I)···(T-\lambda_nI)(v)$  
    则 $Tw=\lambda_1w$  
    若 $w\neq 0$，则 $w$ 为本征向量，$\lambda_1$ 为本征值  
    若 $w=0$，则 $(T-\lambda_2I)···(T-\lambda_nI)(v)=0$  
    令 $w_1=(T-\lambda_3I)···(T-\lambda_nI)(v)$  
    若 $w_1\neq0$  
    则 $w_1$ 为本征向量，$\lambda_2$ 为本征值  
    若 $w_1=0$  
    继续上述过程，直到取到最小 $i$，使得 $(T-\lambda_iI)···(T-\lambda_n)(v)=0$  
    记为 $w_{i-2}$  
    由于 $i$ 最小  
    $(T-\lambda_{i-1}I)(T-\lambda_iI)···(T-\lambda_nI)(v)=0$  
    即 $(T-\lambda_{i-1}I)w_{i-2}=0$  
    $Tw_{i-2}=\lambda_{i-1}w_{i-2}$  
    $\lambda_{i-1}$ 为本征值，$w_i$ 为本征向量  

### 上三角矩阵  

**上三角矩阵的等价条件：**  

设 $T\in L(V)$，且 $v_1,···,v_n$ 是 $V$ 的一组基，则以下命题等价：  

* $T$ 关于$v_1,···,v_n$的矩阵是上三角矩阵  
* $\forall j\geqslant 1$，$Tv_j\in span(v_1,···,v_j)$  
* $\forall j\geqslant 1$，$span(v_1,···,v_j)$是 $T$ 在 $V$ 上的不变子空间  

**上三角矩阵的相关性质：**

在复向量空间$V$上的任意算子 $T\in L(V)$ 关于 $V$ 的某个基有上三角矩阵。

!!! Tip "Proof" 
    使用第二数学归纳法  
    当 $\dim V=1$ 时，显然成立  
    若 $\dim V<n$ 时成立，求证 $\dim V=n$ 时也成立  
    由于有限维非零复向量空间上的每个算子都有本征值
    所以存在 $v\in V$ 且 $v\neq0$，使得 $Tv=\lambda v$  
    $v\in null(T-\lambda I)$  
    由维数公式可知：$\dim range(T-\lambda I)<\dim V=n$  
    考虑 $\forall \alpha \in range(T-\lambda I)$  
    由于 $range(T-\lambda I)$ 是 $T-\lambda I$ 在 $V$ 上的不变子空间  
    因此 $(T-\lambda I)\alpha\in range(T-\lambda I)$  
    同样地，$\lambda\alpha\in range(T-\lambda I)$  
    于是有 $T\alpha=(T-\lambda I)\alpha+\lambda\alpha\in range(T-\lambda I)$  
    $range(T-\lambda I)$ 是 $T$ 在 $V$ 上的不变子空间  
    考虑限制算子 $T\vert_{range(T-\lambda I)}$  
    存在一组基 $v_1,···,v_m$，使得 $(Tv_1,···,Tv_m)=(v_1,···,v_m)\begin{pmatrix}
    a_{11}&&&\\\
    0&···&&\\\
    ···&···&···&&\\\
    0&···&0&a_{mm}
    \end{pmatrix}$  
    将 $v_1,···,v_m$ 扩充成 $V$ 的基 $v_1,···,v_m,v_{m+1},···,v_n$  
    $\forall j\geqslant m+1$，$Tv_j=(T-\lambda I)v_j+\lambda v_j\in span(v_1,···,v_m,v_j)\subseteq span(v_1,···,v_m,v_{m+1},···,v_j)$  
    由上三角矩阵的等价条件即可得证。 

设 $T$ 关于某组基有上三角矩阵，则 $T$ 可逆当且仅当该上三角矩阵的对角线元素均不等于 $0$。  

!!! Tip "Proof"  
    假设 $\lambda_i\neq0$  
    求证：$null~T=\\{0\\}$  
    若 $null~T\neq\\{0\\}$  
    取 $\alpha\in null~T$ 且 $\alpha\neq0$  
    $\alpha=k_1v_1+···+k_sv_s,k_s\neq0$，$s$取最小  
    $T\alpha=k_1Tv_1+···+k_sTv_s$  
    $=(Tv_1,···,Tv_s)(k_1,···,k_s)^T$  
    $=(v_1,···,v_s)\begin{pmatrix}
    \lambda_1&&&*\\\
    &\lambda_2&&\\\
    &&···&\\\
    0&&&\lambda_s
    \end{pmatrix}(k_1,···,k_s)^T$  
    $=b_1v_1+···+b_{s-1}v_{s-1}+k_s\lambda_sv_s$  
    $=0$  
    由 $k_s\neq0$，$\lambda_s\neq0$可知：  
    $v_1,···,v_s$ 线性相关，矛盾  
    得到 $null~T=\\{0\\}$  
    即 $T$ 是单射  
    又由维数公式得到 $T$ 是满射  
    因此 $T$ 可逆  
    若 $T$ 可逆，求证 $\lambda_i\neq0$  
    假设 $\lambda_1,···,\lambda_{s-1}=0$，$\lambda_s\neq0$  
    $Tv_s=span(v_1,···,v_{s-1})$  
    $T\vert_{span(v_1,···,v_s)}:span(v_1,···,v_s)\rightarrow span(v_1,···,v_{s-1})$  
    由维数公式：$null~T|_{span(v_1,···,v_s)}\neq\\{0\\}$  
    $T$ 不是单射  
    $T$ 不可逆，矛盾  
    $\lambda_i=0$  

设 $T$ 关于某组基有上三角矩阵，则 $T$ 的本征值为对角线上元素。

***

## 2.3 本征空间与对角矩阵

**本征空间：**  

设 $T\in L(V)$，$T$ 关于 $\lambda$ 的**本征空间**定义为 

$$E(\lambda,T)=null(T-\lambda_i)=\\{\alpha\in V|T\alpha=\lambda\alpha\\}$$

也就是说，$E(\lambda,T)$ 是 $T$  $\lambda$ 的全体本征向量加上 $0$ 向量构成的集合。  

本征空间是子空间。  

$E(\lambda_1,T)+···+E(\lambda_m,T)$ 是直和。  

$$\dim E(\lambda_1,T)+···+\dim E(\lambda_m,T)\leqslant\dim V$$  

**可对角化的等价条件：**

下列叙述等价：  

* $T$ 可对角化  
* $V$ 有本征向量组成的基    
* $V$ 有一维的 $T$ 不变子空间 $U_i$，使得 $V=U_1\oplus···\oplus U_n$  
* $V=E(\lambda_1,T)\oplus···\oplus E(\lambda_m,T)$  
* $\dim V=\dim E(\lambda_1,T)+···+\dim E(\lambda_m,T)$  

然而，无论是实向量空间还是复向量空间，都不能保证每个算子都可对角化。  

若 $T\in L(V)$ 有 $\dim V$ 个互异的本征值，则 $T$ 可对角化。  

但是，其逆命题不成立，因为可对角化的算子可以不到 $\dim V$ 个互异的本征值。