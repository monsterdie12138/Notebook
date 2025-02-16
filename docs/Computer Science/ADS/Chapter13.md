---
comments: true
---

<span style="font-family: 'Times New Roman';">

# Chapter13 Randomized Algorithms 随机算法

***

## 13.1 基本概念

**随机的两个层面：**

* **数据的随机：** 用传统算法解决随机的输入，用平均时间复杂度来进行分析
* **算法的随机：** 当遇到最差情况的输入时采取随机的决策

**随机算法的作用：**

对于在线算法，当遇到比较差的数据时，可以加入随机因子，让对方很难设计刁钻的数据。

***

## 13.2 The Hiring Problem 秘书问题

**问题描述：**

对于$N$个候选人，通过比较好坏来选择雇用其中一些人。

面试一人的费用：$C_i$

雇用一人的费用：$C_h$

雇用总人数：$M$

总费用：$O(NC_i+MC_h)$（分析指标）

**第一想法：**

按照顺序进行面试，如果当前面试的人比之前雇用的人都好，则将其雇用。

```c linenums="1"
int Hiring(int N,candidate C[])//N为总面试人数，C[]为候选人数组
{
    int Best=0;//当前已雇用的人中最好的
    int BestQ=the score of C[0];//当前已雇用的人中最好的分数，第0号候选人实际不存在，只是一个dummy head
    for(i=1;i<=N;i++)
    {
        if(the score of C[i]>BestQ)
        {
            BestQ=the score of C[i];
            Best=C[i];//更新当前已雇用的最好的人
            hire(C[i]);//雇用
        }
    }
    return Best;
}
```

最坏情况：若候选人按照分数从低到高排序，则最后会全被雇用（$O(NC_i+NC_h)\approx O(NC_h)$）

**假设候选人顺序随机的情况：**

现在考虑雇用人数$X$的期望。

$$X=\sum\limits_{i=1}^NX_i$$

$$X_i=\begin{cases}
    1,candidate~i~is~hired\\\
    0,candidate~i~is~NOT~hired
\end{cases}$$

$$EX=\sum\limits_{j=1}^Nj\cdot P(X=j)=\sum\limits_{i=1}^NE(X_i)$$

其中，$E(X_i)$表示的是第$i$个候选人被雇用的概率，也就是第$i$个候选人是前$i$个候选人中最厉害的概率，为$\frac{1}{i}$。

!!! Note
    最方便的理解就是，在目前已经面试的$i$个人中，最厉害的人在最后的概率就是$\frac{1}{i}$，而这前$i$个人分别是谁是等可能随机的，无影响。

由于

$$\ln(N+1)<\sum\limits_{i=1}^N\frac{1}{i}<\ln N+1$$

因此

$$EX=ln N+1$$

成本为$O(NC_i+C_h\ln N)$，比最坏情况的要好，因此我们对第一想法进行改进，**在遍历所有候选人之前先提前随机乱序排列**。

**Radomized Permutation Algorithm 随机排列算法：**

解决的是如何随机排列的问题。

给定数组$A[N]$，现要将其随机乱序排列，我们可以考虑给数组$A$的每个位置一个随机元素，然后再按照对应元素的大小重新排序。

```c linenums="1"
void PermuteBySorting (ElemType A[],int N)
{
    for(i=1;i<=N;i++)
    {
        A[i].P=1+rand()%(N^3);//P为数组A每个位置对应的随机元素，范围为1~N^3（也可以是其他范围）
    }
    Sort A, using P as the sort keys;
}
```

若假设对应元素各不相同，则PermuteBySorting产生的是均匀的随机排列。

**Online Hiring Algorithm 在线雇用算法：**

这个算法针对的情况是：每面试一个候选人之后就要立刻决定是否雇用，且$N$个候选人中只雇用一个。

我们可以想到：1号候选人是最难决定是否雇用的，而$N$号候选人是最容易决定是否雇用的。

我们给出的一个想法是：以前$k$个候选人作为参考，这$k$个人一定不会雇用，而是用作评判之后的候选人的指标，只要之后一旦出现比这$k$个人都好的就直接雇用。

```c linenums="1"
int OnlineHiring(EventType C[],int N,int k)
{
    int Best=N;
    int BestQ=-∞;
    for(i=1;i<=k;i++) //前k个炮灰
    {
        Qi=interview(i);
        if(Qi>BestQ)
        {
            BestQ=Qi;
        }
    }
    for(i=k+1;i<=N;i++) 
    {
        Qi=interview(i);
        if(Qi>BestQ) 
        {
            Best=i;
            break;
        }
    }
    return Best;
}
```

产生的问题：
* 在给定$k$时有多大的概率雇佣到最好的？
* 如何确定最好的$k$？

设事件：

* $S$：表示雇用到最好的
* $S_i$：表示第$i$位候选人是最好的，且被雇用
* $A_i$：表示第$i$位候选人是最好的
* $B_i$：表示第$k+1$到第$i-1$位候选人都没有被雇用

（事件$A$和事件$B$相互独立）

$$P(S_i)=P(A)P(B)=\frac{1}{N}\cdot\frac{k}{i-1}=\frac{k}{N(i-1)}$$

!!! Note
    对于事件$B$的概率解释为：考虑前$i-1$个候选人，其中最好的候选人必须要作为$k$个参考中的一员（要在这$i-1$个位置中的前$k$个位置），才能让后面第$k+1$到第$i-1$位候选人不被雇用，否则这个最好的就会被雇用。

$$P(S)=\sum\limits_{i=k+1}^{N}S_i=\frac{k}{N}\sum\limits_{i=k}^{N-1}\frac{1}{i}$$

由不等式：

$$\int_k^N\frac{1}{x}dx\leqslant\sum\limits_{i=k}^{N-1}\frac{1}{i}\leqslant\int_{k-1}^{N-1}\frac{1}{x}dx$$

可知：

$$\frac{k}{N}\ln(\frac{N}{k})\leqslant P(S)\leqslant \ln(\frac{N-1}{k-1})$$

!!! Note
    对于函数$f(k)=\frac{k}{N}\ln(\frac{N}{k})$，可通过求导找到其最大值，也就是雇佣到最好的概率的下界，这时候的$k$就是最好的$k$。

***

## 13.3 Quicksort 快排

回顾：

平均时间复杂度：

$$\Theta(N\log N)$$

最坏时间复杂度：

$$\Theta(N^2)$$

决定其速度快慢的关键在于：如何选择pivot，如果选择的pivot使得剩下的值全集中在一边，则速度会很慢。

**随机算法改良：central splitter**

每一次选择pivot时都进行随机挑选，要求所得的pivot满足：其分出的两半中更短的一半的长度超过$\frac{N}{4}$。如果满足则以该pivot进行区分，否则再次随机寻找pivot，直到满足要求。

$$P(find~a~central~splitter)=\frac{1}{2}$$

每一轮寻找central splitter的预估次数为2。

**随机快排的最坏时间：**

由于Quicksort是不断划分子问题的，每个子问题对应的待排序的元素数量不同，因此我们定义**第$j$类子问题**：元素数量满足

$$N(\frac{3}{4})^{j+1}\leqslant|S|\leqslant N(\frac{3}{4})^j$$

接下来进行推导与放缩：对于给定的$j$，第$j$类子问题最多有$(\frac{4}{3})^{j+1}$个。（$N\div N(\frac{3}{4})^{j+1}=(\frac{4}{3})^{j+1}$）

因此第$j$类子问题总的耗时期望为

$$E(T_{type~j})=O(N(\frac{3}{4})^j)\times(\frac{4}{3})^{j+1}=O(N)$$

而总共的子问题种类数为

$$\log_{\frac{4}{3}}N=O(\log N)$$

相乘即可得到最坏的时间复杂度：

$$O(N\log N)$$