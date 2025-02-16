---
comments: true
---

<span style="font-family: 'Times New Roman';">

# Chapter1 事件及其概率

***

## 1.1 随机事件和概率

**随机现象的基本属性：**

* 该试验可重复进行或该现象可重复观察（定性）
* 试验之前（或现象发生之前），并不知道结果（定性）
* 该试验（或现象）所有可能的结果是已知的（定量）

**样本空间和样本点：**

考虑某随机现象，记所有可能的结果为$\Omega$，则称$\Omega$为该随机现象的**样本空间**。

记每一个结果为$\omega$，并称为**样本点**，显然$\omega\in\Omega$。

**事件：**

具有某种属性的基本结果构成**事件**，通常用$A$表示，记为$A\subseteq\Omega$。

**概率：**

一次试验中事件$A$发生的可能性，用$P(A)$表示。

统计方法：用频率估计概率

**事件的运算：**

* $\emptyset$：不可能事件
* $\Omega$：必然事件
* $A\subseteq B$：事件$A$发生意味着事件$B$发生
* $A\cap B$：事件$A$和事件$B$同时发生，也记作$AB$
* $A\cup B$：事件$A$或事件$B$发生
* $\overline{A}$：事件$A$的对立事件，即$A$不发生
* $A\setminus B$：事件$A$发生，事件$B$不发生
* $A\cap B=\emptyset$：事件$A$和事件$B$互不相交，此时记$A\cup B=A+B$
* De Morgan对偶运算原理：$\overline{(\cap A_n)}=\cup A_n$，$\overline{(\cup A_n)}=\cap A_n$

***

## 1.2 基本概率模型

### 古典概率模型

* 有限个基本结果
* 每个结果等可能发生

$$P(A)=\frac{|A|}{N}$$

对于一个古典概率模型，关键在于计算所有可能的基本结果数$N$和事件$A$所包含的基本结果个数。

!!! Example
    **某人在口袋里放着两盒牙签，每盒$n$根，使用时随机取一盒，并在其中随机取一根，直到某次他发现取出的一盒已经用完为止，此时另一盒中恰好有$m$根牙签的概率。**

    考虑前$2n-m+1$次抽取，其中第$2n-m+1$次抽取时发现是空的  
    总共有$2^{2n-m+1}$种抽取方法  
    假设第$2n-m+1$次抽的是甲盒，发现为空  
    则在之前的$2n-m$次抽取中刚好抽取甲盒$n$次  
    乙盒同理  
    $P=2\cdot\frac{C_{2n-m}^n}{2^{2n-m+1}}=\frac{C_{2n-m}^n}{2^{2n-m}}$  

### 几何概率模型

* 样本空间是一个区域（$R,R^2,···,R^k$上的可测区域），含有不可数个基本结果
* 所有基本结果均等可能发生，且每个基本结果出现的概率为0
* 事件$A$是样本空间$\Omega$上的可测子集

$$P(A)=\frac{|A|}{|\Omega|}$$

!!! Example
    **例1：Buffon投针问题：平面上画很多平行线，间距为$a$，向此平面投掷长为$l(l<a)$的针，求此针与任一平行线相交的概率。**

    令$\theta$表示针与平行线之间的夹角，则$\theta\in[0,\frac{\pi}{2}]$  
    令$x$表示针的中心与平行线之间的距离，则$x\in[0,\frac{a}{2}]$  
    因此，样本空间为$\Omega=[0,\frac{a}{2}]\times[0,\frac{\pi}{2}]$  
    若针与平行线相交，则$x\leqslant\frac{l}{2}\sin\theta$  
    $P(A)=\frac{\int_0^\frac{\pi}{2}\frac{l}{2}\sin\theta d\theta}{\frac{a}{2}\cdot\frac{\pi}{2}}=\frac{2l}{\pi a}$  

    **例2：约会问题：甲乙两人相约晚上7:00至8:00在电影院门口见面，每人最多等候20分钟，假定甲乙两人在该时间段随机出现，求两人能见面的概率。**

    考虑正方形区域：$\Omega=[0,60]\times[0,60]$  
    甲乙两人到达时间形成序偶$(x,y)$，等可能落在该区域  
    若两人相见，则$|x-y|\leqslant 20$  
    $P(A)=\frac{|A|}{|\Omega|}=\frac{60^2-40^2}{60^2}=\frac{5}{9}$  

### 概率空间公理化体系

$$(\Omega,A,P)$$

* $\Omega$：样本空间
* $A$：事件类（又称$\sigma-$域，为各种事件$A_1,A_2,···,A_n$组成的集合）
* $P$：概率

$$P(\bigcup\limits_{i=1}^nA_i)=\sum\limits_{i=1}^nP(A_i)-\sum\limits_{i<j}P(A_iA_j)+···+(-1)^{n-1}P(\bigcap\limits_{i=1}^nA_i)$$

!!! Example
    **例1：匹配问题：某人写$n$封信，现随机地将$n$封信放入$n$个信封，每个信封装一封信，求至少有一封信装入正确的信封的概率。**

    记事件$A_i$表示第$i$封信装入正确的信封  
    本题即求$P(\bigcup\limits_{i=1}^nA_i)$  
    $P(A_i)=\frac{A_{n-1}^{n-1}}{A_n^n}=\frac{1}{n}$  
    $P(A_iA_j)=\frac{A_{n-2}^{n-2}}{A_n^n}=\frac{1}{n(n-1)}$  
    ···  
    $P(\bigcap\limits_{i=1}^nA_i)=\frac{1}{n!}$  
    综上：$P(\bigcup\limits_{i=1}^nA_i)=\sum\limits_{i=1}^nP(A_i)-\sum\limits_{i<j}P(A_iA_j)+···+(-1)^{n-1}P(\bigcap\limits_{i=1}^nA_i)$  
    $=C_n^1\cdot\frac{1}{n}-C_n^2\cdot\frac{1}{n(n-1)}+···+(-1)^{n-1}C_n^n\cdot\frac{1}{n!}$  
    $=1-\frac{1}{2!}+···+(-1)^{n-1}\frac{1}{n!}$  
    $\sim 1-\frac{1}{e}$  

    **例2：涂色问题：记$n$个点和两两连接而成的连线组成完全图$G$，给定整数$k$，$G$中任意$k$个顶点以及对应的边组成完全子图，记这些子图为$G_i$，$i=1,2,···,C_n^k$，先将$G$中的每一条边涂成红色或蓝色，问：是否有一种涂色方法，使得没有一个子图$G_i$的所有边是同一颜色的?**

    一条边为红色和蓝色的概率各为$\frac{1}{2}$  
    记事件$E_i$为子图$G_i$的各条边颜色相同  
    $P(E_i)=P(G_i-all-red)+P(G_i-all-blue)=\frac{2}{2^{C_k^2}}=(\frac{1}{2})^{\frac{k(k-1)}{2}-1}$  
    $P(\bigcup\limits_iE_i)\leqslant\sum\limits_iP(E_i)=C_n^k(\frac{1}{2})^{\frac{k(k-1)}{2}-1}$  
    所以当$C_n^k<2^{\frac{k(k-1)}{2}-1}$时  
    $P(\bigcup\limits_iE_i)<1$  
    此时有涂色方法可以满足要求（$n$和$k$要满足一定关系）  

***

## 1.3 条件概率

### 条件概率

$$P(A|B)=\frac{P(AB)}{P(B)}$$

称$P(A|B)$是在$B$发生的条件下，$A$发生的**条件概率**。

链式法则推广：

$$P(ABC)=P(A|BC)P(BC)=P(A|BC)P(B|C)P(C)$$

上式可推广到多个情形。

### 全概率公式

假设$(\Omega,A,P)$是一个概率空间，$B_k(1\leqslant k\leqslant N)$是$N$个互不相交的事件，且$\Omega=\sum\limits_{k=1}^NB_k$，那么事件$A$发生的概率为

$$P(A)=\sum\limits_{k=1}^NP(A|B_k)P(B_k)$$

事件$A$可以在$N$个不同条件下发生，因此其概率大小为各种条件的加权平均。

### 贝叶斯公式

假设$(\Omega,A,P)$是一个概率空间，$B_k(1\leqslant k\leqslant N)$是$N$个互不相交的事件，且$\Omega=\sum\limits_{k=1}^NB_k$，那么

$$P(B_k|A)=\frac{P(A|B_k)P(B_k)}{\sum\limits_{k=1}^NP(A|B_k)P(B_k)}$$

称$P(B_k)$为**先验概率**，$P(B_k|A)$为**后验概率**。

右式的分子即为$P(AB_k)$（条件概率公式），分母即为$P(A)$（全概率公式）。

!!! Example
    **某公司下设甲、乙、丙、丁四家分厂，生产同一商品，产量分别占18%、28%、20%、34%，已知甲、乙、丙、丁四家分厂的次品率分别为0.5%、1%、0.8%、0.5%，现某顾客购买到一件次品，向公司索赔10000元，四家分厂各自应该赔付多少？**   

    记事件$A$为生产出次品  
    事件$B_k$为产品为$k$号分厂生产  
    次品为甲厂生产的概率  
    $P(B_1|A)=\frac{P(A|B_1)P(B_1)}{\sum\limits_{k-1}^4P(A|B_k)P(B_k)}=\frac{0.5\%\times 18\%}{0.5\%\times 18\%+1\%\times28\%+0.8\times20\%+0.5\%\times34\%}=\frac{9}{70}$  
    甲厂应该赔付  
    $10000\times\frac{9}{70}=\frac{9000}{7}$  
    其它厂类似  

***

## 1.4 独立性

### 独立性

#### 两个事件的独立性

假设$(\Omega,A,P)$是一个概率空间，$A$，$B$是两个事件，若

$$P(A|B)=P(A)$$

或

$$P(AB)=P(A)P(B)$$

则称$A$和$B$**独立**。

如果$A$和$B$独立，那么$A$和$\overline{B}$独立，$\overline{A}$和$B$独立，$\overline{A}$和$\overline{B}$独立。

!!! Note
    注意与加法的区别：  
    $A$，$B$互不相交：$P(A+B)=P(A)+P(B)$；  
    $A$，$B$相互独立：$P(AB)=P(A)P(B)$。

#### 三个事件的独立性

假设$A$，$B$，$C$是三个事件，若

$$P(AB)=P(A)P(B)$$
$$P(AC)=P(A)P(C)$$
$$P(BC)=P(B)P(C)$$

则称$A$，$B$，$C$**两两独立**。

!!! Note
    **两两独立**并不等于**相互独立**。

在两两独立的基础上，若

$$P(ABC)=P(A)P(B)P(C)$$

则称$A$，$B$，$C$**相互独立**。

!!! Example
    **一个正四面体的三面分别涂成红、黑、白三种颜色，而第四面则涂上三种颜色，现随机一扔，考虑底面涂有红色、黑色、白色这三个事件的独立性。**  
    用$A$，$B$，$C$分别表示底面涂有红色、黑色、白色，则  
    $P(A)=P(B)=P(C)=\frac{1}{2}$  
    $P(AB)=P(AC)=P(BC)=\frac{1}{4}$  
    此时  
    $P(AB)=P(A)P(B)$  
    $P(AC)=P(A)P(C)$  
    $P(BC)=P(B)P(C)$  
    因此$A$，$B$，$C$两两独立  
    但是  
    $P(ABC)=\frac{1}{4}\neq P(A)P(B)P(C)$  
    因此$A$，$B$，$C$并不是相互独立  

**延伸：$m$个事件相互独立**

假设$A_k(1\leqslant k\leqslant m)$是$m$个事件，如果$A_k$中任意$r<m$个事件都相互独立，且

$$P(\bigcap\limits_{1\leqslant k\leqslant m}A_k)=\prod\limits_{1\leqslant k\leqslant m}P(A_k)$$

则称$A_k$相互独立。

### 二项试验（n重Bernoulli试验）

试验$E$：包括若干个基本结果；

事件$A$：具有某种属性的基本结果的集合，发生的概率为$p$；

对于每次试验，若$A$发生，记为1；反之记为0；

独立重复进行$n$次试验$E$，所得结果为

$$\omega=(\omega_1,\omega_2,···,\omega_n),~\omega_i=0,1$$

用$\Omega_n$表示所有$\omega$的集合，这样，$\Omega_n$中含有$2^n$个不同的$\omega$
对于每个$\omega$，其出现的概率为

$$P_n(\omega)=p^{\sum\omega_i}(1-p)^{n-\sum\omega_i}$$

于是我们得到了新的概率空间$(\Omega_n,P_n)$。

考虑事件$B=\{\omega:n_A(\omega)=k\}$，其中$n_A$为$n$次试验中$A$发生的次数
那么

$$P_n(B)=C_n^kp^k(1-p)^{n-k}$$

### 乘积概率空间

考虑两个试验$E_1$，$E_2$，对应的概率空间分别为$(\Omega_1,F_1,P_1)$，$(\Omega_2,F_2,P_2)$
现独立进行试验$E_1$，$E_2$，记录其结果

$$\omega=(\omega_1,\omega_2)$$
所有结果的全体

$$\Omega=\{\omega=(\omega_1,\omega_2),\omega_1\in\Omega_1,\omega_2\in\Omega_2\}$$

考虑事件

$$A=A_1\times A_2=\{\omega=(\omega_1,\omega_2),\omega_1\in A_1,\omega_2\in A_2\}$$

其概率为

$$P(A)=P(A_1)P(A_2)$$

***

## 补充：事件的极限

假设$A_n$是一系列递增事件：

$$A_1\subseteq A_2\subseteq···\subseteq A_n\subseteq···$$

则

$$\lim\limits_{n\rightarrow\infty}A_n=\bigcup\limits_{n=1}^{\infty}A_n$$

$$P(\lim\limits_{n\rightarrow\infty}A_n)=\lim\limits_{n\rightarrow\infty}P(A_n)$$

假设$A_n$是一系列递减事件：

$$A_1\supseteq A_2\supseteq···\supseteq A_n\supseteq···$$

则

$$\lim\limits_{n\rightarrow\infty}A_n=\bigcap\limits_{n=1}^{\infty}A_n$$