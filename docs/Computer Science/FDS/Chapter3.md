---
comments: true
---

<span style="font-family: 'Times New Roman';">

# Chapter3 Sorting and Hashing

***

## 3.1 Sorting

### Insertion Sort 插入排序

```c linenums="1"
void InsertionSort(int a[],int n)
{
    int i,j;
    for(i=1;i<n;i++)
    {
        int tmp=a[i];//选择要进行插入的元素，记为tmp
        for(j=i;j>0&&a[j-1]>tmp;j--)
        {
            a[j]=a[j-1];//把比tmp大的元素向后移位
        }
        a[j]=tmp;//找到插入位置后放入tmp
    }
    return;
}
```

最坏时间复杂度（逆序）：

$$T(N)=O(N^2)$$

最好时间复杂度（顺序）：

$$T(N)=O(N)$$

平均时间复杂度：

$$T(N)=O(N^2)$$

**Inversion 逆序对:**

序偶$(i,j)$满足$i{<}j$但$A[i]{\>}A[j]$，也就是说没有排好序。

$T(N,I)=O(N+I)$，其中$I$是序列中的逆序对数。

定理一：在$N$个元素的序列中，平均逆序对数为$\frac{N(N-1)}{4}$。

定理二：任何依靠交换相邻元素进行排序的算法，平均时间复杂度均为$\Omega(N^2)$。

### Shell Sort 希尔排序

适用于中等大小序列的排序。

步骤一：确定一个递增序列

$$1=h_1<h_2<···<h_t$$

步骤二：$k$从$t$一直到1，依次进行$h_k$排序，即对依次间隔$h_k$的元素进行排序，此处的排序可以是插入排序

!!! Example
    $81,94,11,96,12,35,17,95,28,58,41,75,15$  
    $5$排序即对上述元素分组排序：  
    $81,35,41$为一组，下标为$5k$  
    $94,17,75$为一组，下标为$5k+1$  
    $11,95,15$为一组，下标为$5k+2$  
    $96,28$为一组，下标为$5k+3$  
    $12,58$为一组，下标为$5k+4$  
    每组排完序后还是在原本的下标范围中  

值得注意的是，对于进行完$h_{k-1}$排序的序列，之前$h_k$排序的结果依旧保留。

**Shell序列：**

$$h_t=\lfloor\frac{N}{2}\rfloor$$

$$h_k=\lfloor\frac{h_{k+1}}{2}\rfloor$$

```c linenums="1"
void ShellSort(int a[],int n)
{
    int i,j,increment;//increment表示Shell序列
    for(increment=n/2;increment>0;increment/=2)
    {
        for(i=increment;i<n;i++)
        {
            int tmp=a[i];//每一个increment内部进行插入排序
            for(j=i;j>=increment;j-=increment)
            {
                if(tmp<a[j-increment])
                {
                    a[j]=a[j-increment];
                }
                else
                {
                    break;
                }
            }
            a[j]=tmp;
        }
    }
    return;
}
```

使用Shell序列进行希尔排序的最坏时间复杂度：

$$T(N)=\Theta(N^2)$$

!!! Example
    $1,9,2,10,3,11,4,12,5,13,6,14,7,15,8,16$  
    由于其间隔递增，因此直到$1$排序才能对序列进行改动  

**Hibbard序列：**

$$h_k=2^k-1$$

使用Hibbard序列进行希尔排序的最坏时间复杂度：

$$T(N)=\Theta(N^{\frac{3}{2}})$$

### Heap Sort 堆排序

构建最小堆，每次DeleteMin删掉最小元素，并依次组成排好序的序列。

$$T(N)=O(N\log N)$$

优化：我们不一定需要额外的数组来存储排好序的序列，我们可以如下操作：

* 构建最大堆
* 上移，将堆中的可移动的最大元上移至根部
* 将根部的元素与堆末尾的元素互换
* 堆末尾的元素固定，堆的大小减一
* 重复2~4步

定理：在$N$个元素的堆排序中，平均的比较次数为

$$2N\log N-O(N\log\log N)$$

### Merge Sort 归并排序

对已有的两个有序序列进行归并的时间复杂度：

$$T(N)=O(N)$$

```c linenums="1"
void MergeSort(int a[],int low,int high)
{
    int b[high];//用来存放归并后的数列
    if(low>=high)return;
    int mid=(high+low)/2;//确定划分点
    MergeSort(a,low,mid);//对前后两个分区分别进行排序
    MergeSort(a,mid+1,high);
    int i=low,j=mid+1,k=low;//i和j分别作为前后两个数列的移动指针
    while(k<=high)
    {
        if(((j==high+1)||(a[i]<a[j]))&&(i<=mid))//后一个序列已经全部读完，或者前一个序列所指的数小于后一个序列所指的数（此时前一个序列未全部读完）
        {
            b[k]=a[i];
            k++;
            i++;
        }
        else
        {
            b[k]=a[j];
            k++;
            j++;
        }
    }
    int l;
    for(l=low;l<=high;l++)//将存放在b中的数据放回a
    {
        a[l]=b[l];
    }
    return;
}
```

时间复杂度：

$$T(N)=O(N\log N)$$

归并排序需要额外的空间资源，适合外部排序而不是内部排序。

!!! Success "Definition"
    **内部排序：** 待排序记录存放在计算机随机存储器中（内存）进行的排序过程  
    **外部排序：** 待排序记录的数量很大，以致于内存不能一次容纳全部记录，所以在排序过程中需要对外存进行访问的排序过程

### Quick Sort 快速排序

pivot的选择：

取序列最左、序列最右、序列中间三个数的中间值。

```c linenums="1"
void Median(int a[],int low,int mid,int high)//将序列最左、序列最右和序列中间的三个值从小到大重排
{
    int t;
    if(a[low]>a[mid])
    {
        t=a[low];
        a[low]=a[high];
        a[high]=t;
    }
    if(a[mid]>a[high])
    {
        t=a[mid];
        a[mid]=a[high];
        a[high]=t;
    }
    if(a[low]>a[mid])
    {
        t=a[low];
        a[low]=a[mid];
        a[mid]=t;
    }
    return;
}

void QuickSort(int a[],int low,int high)
{
    if(low>=high)return;//结束条件
    int mid=(low+high)/2;
    Median(a,low,mid,high);
    int t;
    t=a[mid];
    a[mid]=a[high-1];
    a[high-1]=t;//将中间值与右数第二值交换，因为序列最左肯定小于pivot，序列最右肯定大于pivot
    int pivot=a[high-1];//确定pivot
    int i=low,j=high-1;
    while(1)
    {
        while(a[++i]<pivot){}//从左往右数
        while(a[--j]>pivot){}//从右往左数
        if(i<j)//指针对应的值交换
        {
            t=a[j];
            a[j]=a[i];
            a[i]=t;
        }
        else break;
    }
    t=a[i];
    a[i]=a[high-1];
    a[high-1]=t;//让pivot处于两块分区中间
    QuickSort(a,low,i-1);//分别对两块分区再次快速排序
    QuickSort(a,i+1,high);
    return;
}
```

最坏时间复杂度：

$$T(N)=O(N^2)$$

最好时间复杂度：

$$T(N)=O(N\log N)$$

平均时间复杂度：

$$T(N)=O(N\log N)$$

### Bucket Sort 桶排序

针对元素取值少的情况（总元素数量$N$远大于可能取值数量$M$）。

!!! Example
    100个学生有5个等级，我们只需要用5个桶表示5个等级，将100个学生按照各自的等级放到5个桶里，再从小到大遍历输出每个桶中的元素即可。

### Radix Sort 基数排序

原理是将整数按位数切割成不同的数字，然后按每个位数分别比较。

以以下序列为例：

$$64,8,216,512,27,729,0,1,343,125$$

**MSD 从高位到低位排:**

先排百位：

0|1|2|3|4|5|6|7|8|9
---|---|---|---|---|---|---|---|---|---
64，8，27，0，1|125|216|343||512||729||

再在百位的基础上对每一组排十位（以百位为0的组为例）：

0|1|2|3|4|5|6|7|8|9
---|---|---|---|---|---|---|---|---|---
8，0，1||27||||64|||

再在十位的基础上对每一组排个位（以十位为0的组为例）：

0|1|2|3|4|5|6|7|8|9
---|---|---|---|---|---|---|---|---|---
0|1|||||||8|

**LSD 从低位到高位排:**

先排个位：

0|1|2|3|4|5|6|7|8|9
---|---|---|---|---|---|---|---|---|---
0|1|512|343|64|125|216|27|8|729

再在个位的基础上排十位：

0|1|2|3|4|5|6|7|8|9
---|---|---|---|---|---|---|---|---|---
0，1，8|512，216|125，27，729||343||64|||

再在十位的基础上排百位：

0|1|2|3|4|5|6|7|8|9
---|---|---|---|---|---|---|---|---|---
0，1，8，27，64|125|216|343||512||729||

$$T=O(P(N+B))$$

$P$表示位数，$N$表示待排序的元素个数，$B$表示每一位的可能数。

***

## 3.2 Hashing

哈希表的每一行称为一个bucket，带有自己的标签，所有满足对应这个标签的元素$x$都会被放进这个bucket中；每个bucket对应若干列slot，在这个bucket中的$x$会依次放进每一个slot，直到放不下为止。

!!! Success "Definition"
    **identifier density 标识符密度：**$\frac{n}{T}$  
    **loading density 载入密度：**$\lambda=\frac{n}{sb}$
* $T$表示$x$可能的不同值
* $n$表示要放入表中的元素个数
* $s$表示slot的个数，即哈希表的列数
* $b$表示bucket的个数，即哈希表的行数

对于每一个元素$x$，我们定义一个哈希函数$f(x)$，函数的值决定了$x$在哈希表里所在的行，即起到标签的作用。

**Collision 冲突：**

当两个不同的$x$经过计算得到$f(x)$相同时，称发生了冲突。

**Overflow 溢出：**

当一个bucket满了之后又有新的$x$要放进去时，称发生了溢出。

在不考虑溢出的情况下：

$$T_{search}=T_{insert}=T_{delete}=O(1)$$

#### Open Addressing

遇到溢出的情况，则考虑以一定规律放到其他的空位上。

**Linear Probing 线性探测：**

规律：

$$f(i)=i$$

根据$x$计算得到$f(x)$，$f(x)$对应的bucket如果已经满了，则去下一个bucket寻找空位，如果有则将其放入，并记录search time为2（因为在本来的bucket需要一次搜索，没找到后到下一个bucket又需要一次搜索），如果下一个bucket也没有空位，则继续寻找，直到找到能放的空位，search time也是依次增加。

若已知载入密度$\lambda$，则可粗略估算出线性探测预期的探测次数：

成功搜索：

$$p=\frac{1}{2}(1+\frac{1}{1-\lambda})$$

插入/不成功的搜索：

$$p=\frac{1}{2}(1+\frac{1}{(1-\lambda)^2})$$

缺点：造成primary clustering，即物理上聚集在一起。

**Quadratic Probing 二次探测：**

规律：

$$f(i)=i^2$$

根据$x$计算得到$f(x)$，$f(x)$对应的bucket如果已经满了，则看一下往下1位的bucket是否有空位，如果有则放入，否则看一下往下4位的bucket，往下9位的bucket，···，往下$i^2$的bucket···并记录对应的search time。

定理：如果使用二次探测，且bucket的个数为质数，则当哈希表至少半空的时候，总能插入元素。

此外，如果质数形如$4k+3$，则二次探测$f(i)=\pm i^2$（此时向上或者向下探测都可以）可以保证探测满整张表。

缺点：造成second clustering，即对应到同一个bucket上的那些元素将探测相同的备选单元。

### Double Hashing

当出现冲突的时候通过另外一个函数来计算下一个可用位置。

例如，$x$通过第一个哈希函数计算得到$i$，通过第二个哈希函数计算得到$j$，则依次检查的是：

* i位置
* i+j位置
* i+2j位置
* i+3j位置
* ···

可考虑的第二个哈希函数：

$$hash_2(x)=R-(x\%R)$$

其中$R$是一个比bucket数少的质数。

### Rehashing

* 建立一个两倍大的表
* 扫描原始散列表
* 利用新的散列函数将元素映射到新的散列值，并插入

$$T(N)=O(N)$$

适用情况：

* 表填满一半的时候
* 插入失败的时候
* 达到某一个特定的装填因子的时候