---
comments: true
---

<span style="font-family: 'Times New Roman';">

# Chapter3 内积空间

***

## 3.1 内积与范数

### 内积

**内积：**

$V$ 上的内积是一个函数，把 $V$ 中元素的每个有序对 $(u,v)$ 都映成一个数b$\langle u,v\rangle\in F$，且满足：  

* 正性：$\forall v\in V$，$\langle v,v\rangle\geqslant0$  
* 定性：$\langle v,v\rangle=0\Longleftrightarrow v=0$  
* 加性和齐性：$\langle ku_1+\lambda u_2,v\rangle=k\langle u_1,v\rangle+\lambda\langle u_2,v\rangle$  
$\langle u,kv_1+\lambda v_2\rangle=\overline{k}\langle u,v_1\rangle+\overline{\lambda}\langle u,v_2\rangle$  
* 对称性：$\langle u,v\rangle=\overline{\langle v,u\rangle}$  

$F^n$ 上的**欧几里得内积**定义为：  

$$\langle(w_1,w_2,···,w_n),(z_1,z_2,···,z_n)\rangle=w_1\overline{z_1}+w_2\overline{z_2}+···+w_n\overline{z_n}$$  

### 范数

**范数：**  

$\forall v\in V$，定义 $v$ 的**范数** 

$$\Vert v\Vert=\sqrt{\langle v,v\rangle}$$  

对所有 $\lambda\in F$ 都有 

$$||\lambda v||=|\lambda|·||v||$$  

**正交：**

若 $u,v\in V$，$\langle u,v\rangle=0$，则称 $u$ 和 $v$ **正交（垂直）**。（$0$ 与任何向量都垂直）

$u$，$v$ 的夹角 $\theta$ 满足 

$$\cos\theta=\frac{\langle u,v\rangle}{\Vert u\Vert\Vert v\Vert}$$  

**勾股定理：**

若 $u$ 和 $v$ 正交，则 

$$\Vert u+v\Vert^2=\Vert u\Vert^2+\Vert v\Vert^2$$  

勾股定理的逆命题在实内积空间上成立。  

**正交分解：**  

设 $u$，$v\in V$ 且 $v\neq 0$，令 $c=\frac{\langle u,v\rangle}{||v||^2}$，$w=u-\frac{\langle u,v\rangle}{||v||^2}v$，则 $\langle w,v\rangle=0$ 且$u=cv+w$。  

**柯西-施瓦茨不等式：**

$$|\langle u,v\rangle|\leqslant \Vert u\Vert·\Vert v\Vert$$  

$$|x_1y_1+···x_ny_n|^2\leqslant(x_1^2+···x_n^2)(y_1^2+···+y_n^2)$$  

**三角不等式：**  

$$\Vert u+v\Vert\leqslant\Vert u\Vert+\Vert v\Vert$$  

**平行四边形恒等式：**  

$$\Vert u+v\Vert^2+\Vert u-v\Vert^2=2(\Vert u\Vert^2+\Vert v\Vert^2)$$  

***

## 3.2 规范正交基

**规范正交基：**  

给定维数为 $n$ 的内积空间 $V$，若向量组 $e_1,···,e_n$满足  

* $||e_1||=···=||e_n||=1$  
* $\langle e_i,e_j\rangle=\begin{cases}
1,i=j\\\  
0,i\neq j
\end{cases}$  

则称 $e_1,···,e_n$ 为 $V$ 的**规范正交基**。  

**向量在规范正交基下的坐标表示：**  

设内积空间 $V$ 的规范正交基为 $e_1,···,e_n$，则对于 $\forall v\in V$，有  

$$v=\langle v,e_1\rangle e_1+···+\langle v,e_n\rangle e_n$$  

$$\Vert v\Vert^2=|\langle v,e_1\rangle|^2+···+|\langle v,e_n\rangle|^2$$  

**格拉姆-施密特过程：**  

设 $v_1,v_2,···,v_n$ 是 $V$ 的一组基，设 $e_1=\frac{v_1}{\Vert v_1\Vert}$，当 $i\geqslant2$ 时，定义：  

$$e_i=\frac{v_i-\langle v_i,e_1\rangle e_1-···-\langle v_i,e_{i-1}\rangle e_{i-1}}{\Vert v_i-\langle v_i,e_1\rangle e_1-···-\langle v_i,e_{i-1}\rangle e_{i-1}\Vert}$$  

则 $e_1,e_2,···e_n$ 是 $V$ 的一组规范正交基。

!!! Example
    **例：已知 $P_2(R)=span\\{1,x,x^2\\}$，规定内积 $\langle p,q\rangle=\int_{-1}^1p(x)q(x)dx$，求其一组规范正交基。**  

    $\Vert1\Vert^2=\int_{-1}^1dx=2$  
    $e_1=\frac{1}{\Vert1\Vert}=\frac{1}{\sqrt{2}}$  
    $\beta_2=x-\langle x,e_1\rangle e_1=x-\int_{-1}^1\frac{x}{\sqrt{2}}dx·\frac{1}{\sqrt{2}}=x$  
    $\Vert\beta_2\Vert^2=\int_{-1}^1x^2dx=\frac{2}{3}$  
    $e_2=\frac{\beta_2}{\Vert\beta_2\Vert}=\sqrt{\frac{3}{2}}x$  
    $\beta_3=x^2-\langle x^2,e_1\rangle e_1-\langle x^2,e_2\rangle e_2=x^2-\frac{1}{3}$  
    $\Vert\beta_3\Vert^2=\int_{-1}^1(x^2-\frac{1}{3})^2dx=\frac{8}{45}$  
    $e_3=\frac{\beta_3}{\Vert\beta_3\Vert}=\sqrt{\frac{45}{8}}(x^2-\frac{1}{3})$  

每个有限维内积空间都有规范正交基。

假设存在一组基使得 $T$ 关于这组基有上三角矩阵，则存在一组规范正交基，使得 $T$ 关于这组规范正交基也具有上三角矩阵，这个命题在实向量空间和复向量空间上均成立，但在实向量空间上，前提假设不一定成立。  

之前已经知道：在复向量空间上，每个算子都关于某组基有上三角矩阵，由此可以引出舒尔定理：  

**舒尔定理：**  

设 $V$ 是有限维的复向量空间且 $T\in L(V)$，则 $T$ 关于 $V$ 的某组规范正交基有上三角矩阵。  

**里斯表示定理：**  

设 $V$ 是有限维的内积空间，$\varphi\in V'$，则存在唯一向量 $v\in V$，使得对于 $\forall u\in V$，有 $\varphi(u)=\langle u,v\rangle$。  

其中：

$$v=\overline{\varphi(e_1)}e_1+···+\overline{\varphi(e_n)}e_n$$  

!!! Example
    **例：求 $u\in P_2(R)$ 使得对每个 $p\in P_2(R)$ 均有 $\int_{-1}^1p(t)(\cos (\pi t))dt=\int_{-1}^1p(t)u(t)dt$。**  

    设 $\varphi(p)=\int_{-1}^1p(t)(\cos (\pi t))dt$  
    则 $\int_{-1}^1p(t)u(t)dt=\langle v,u\rangle$  
    使用之前求得的一组规范正交基 $\{\sqrt{\frac{1}{2}},\sqrt{\frac{3}{2}}x,\sqrt{\frac{45}{8}}(x^2-\frac{1}{3})\}$  
    代入公式可得：$u(x)=(\int_{-1}^1\sqrt{\frac{1}{2}}(\cos(\pi t))dt)\sqrt{\frac{1}{2}}+(\int_{-1}^1\sqrt{\frac{3}{2}}t(\cos(\pi t))dt)\sqrt{\frac{3}{2}}x+(\int_{-1}^1\sqrt{\frac{45}{8}}(t^2-\frac{1}{3})(\cos(\pi t))dt)\sqrt{\frac{45}{8}}(x^2-\frac{1}{3})=-\frac{45}{2\pi^2}(x^2-\frac{1}{3})$  

***

## 3.3 正交补与极小化问题

### 正交补

**正交补：**

设 $U$ 是 $V$ 的子集（不一定是子空间），则 $U$ 的**正交补** $U^{\perp}$ 是由 $V$ 中与 $U$ 的每个向量都正交的向量组成的集合，即  

$$U^{\perp}=\\{v\in V|\langle v,u\rangle =0,\forall u\in U\\}$$  

若 $U$ 和 $W$ 均为 $V$ 的子集，且  $U\subseteq W$，则$W^{\perp}\subseteq U^{\perp}$。

若 $U$ 是 $V$ 的有限子空间，则 $V=U\oplus U^{\perp}$。

$$\dim U+\dim U^{\perp}=\dim V$$  

**正交投影：**

设 $U$ 是 $V$ 的有限维子空间，则 $V$ 到 $U$ 上的**正交投影** $P_U$ 满足：

对于任意 $v\in V$，将其写成 $v=u+w$，其中 $u\in U$，$w\in U^{\perp}$，则 $P_U(v)=u$  

* 对每个 $u\in U$ 都有 $P_U(u)=u$  
* 对每个 $w\in U^{\perp}$ 都有 $P_U(w)=0$  
* $range~P_U=U$  
* $null~P_U=U^{\perp}$  
* 对 $U$ 的每个规范正交基 $e_1,···,e_m$，都有 $P_U(v)=\langle v,e_1\rangle e_1+···\langle v,e_m\rangle e_m$  

### 极小化问题

**极小化问题：**

设 $U$ 是 $V$ 的有限维子空间，$c\in V$ 且 $u\in U$，则  

$$||v-P_U(v)||\leqslant||v-u||$$

等号成立当且仅当 $u=P_U(v)$。