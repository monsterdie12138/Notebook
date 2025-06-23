---
comments: true
---

<span style="font-family: 'Times New Roman';">

# Chapter2 排序

***

## 2.1 选择排序 $O(N^2)$

* 在n个元素中逐一比对选择出最小的元素
* 将选出来的元素放在数列的最前面
* 在数列后n-1个元素中逐一比对再次选择出最小的元素
* 将选出来的元素放在数列的第二个位置
* 重复上述步骤，直到剩下数列最后一个数

```c linenums="1"
void selectionsort(int a[], int n)
{
    int i,j,index;
    for(i=0;i<n-1;i++) //进行n-1次数列的排序
    {
        index=i;
        for(j=i+1;j<n;j++)//在数列中逐一比对，寻找最小的数
        {
            if(a[j]<a[index])
            {
                index=j;
            }
        }
        int t=a[i];//将找到的最小数放到前面
        a[i]=a[index];
        a[index]=t;
    }
}
```

## 2.2 冒泡排序 $O(N^2)$

* 从头开始两项两项地比较大小，如果前面一个数比后面一个数大则交换位置，直到最大的数到达最后一个位置
* 再次从头比较大小并交换顺序，直到第二大的数到达倒数第二个位置
* 重复上述步骤，直到剩下数列最前面的一个数，即最小数

```c linenums="1"
void bubblesort(int a[],int n)
{
    int i,j;
    for(i=0;i<n-1;i++)//进行n-1次数列的排序
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])//两项两项地比较，让大的数逐渐上浮
            {
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}
```

优化方案：

例如已经有m个数浮到最后，这个时候倒数第m个数前面可能已经有一连串的数已经排好顺序，此时只需记录最后一次交换的位置，下一次的排序只要排到最后一次交换的位置即可。

## 2.3 插入排序 $O(N^2)$

得到一段有序数列后将元素插入所处位置（递归）。

```c linenums="1"
void insertionSort(int a[], int n)
{
    if(n<=1)//如果数列只剩一个元素就不需要排列了
    {
        return;
    }
    else
    {
        insertionSort(a,n-1);//保证去掉a[n-1]后的数列是有序数列(递归)
        int i=n-2,key=a[n-1];//key用于将a[n-1]插入有序数列中的所处位置
        while(a[i]>key)
        {
            a[i+1]=a[i];
            i--;
        }
        a[i+1]=key;
    }
}
```

## 2.4 归并排序 $O(N\log N)$

得到两段有序的数列后将其归并(分治法)。

```c linenums="1"
void mergesort(int a[],int low,int high)
{
    int b[high];//用来存放归并后的数列
    if(low>=high)return;
    int mid=(high+low)/2;//确定划分点
    mergesort(a,low,mid);//对前后两个分区分别进行排序
    mergesort(a,mid+1,high);
    int i=low,j=mid+1,k=low;//i和j分别作为前后两个数列的移动指针
    while(k<=high)
    {
        if(((j==high+1)||(a[i]<a[j]))&&(i<=mid))
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
}
```

## 2.5 快速排序  $O(N\log N)$

* 从数列中挑出一个元素，称为 "基准"(常取第一个或最后一个数)
* 重新排序数列，所有元素比基准值小的摆放在基准前面，所有元素比基准值大的摆在基准的后面(相同的数可以到任一边)
* 递归地把小于基准值元素的子数列和大于基准值元素的子数列排序

**Lomuto算法(单头)：**

```c linenums="1"
void quicksort(int a[],int low,int high)
{
    if(low<high)
    {
        int i=low,j,t;//以i,j作为移动的指针
        for(j=low;j<high;j++)
        {
            if(a[j]<a[high])//j如果找到比基准(最后一个数)小的数就和i对应的数交换
            {
                t=a[j];
                a[j]=a[i];
                a[i]=t;
                i++;
            }
        }
        t=a[i];//让基准处于两块分区的中间
        a[i]=a[high];
        a[high]=t;
        quicksort(a,low,i-1);//分别对两块分区再次快速排序
        quicksort(a,i+1,high);
    }
}
```

**Hoare算法(双头):**

```c linenums="1"
void quicksort(int a[],int low, int high)
{
    if(low>=high)return;
    int left=low,right=high,t;//以数组的第一个数为基准，left和right分别为两头的指针
    while(left<right)
    {
        while(left<right&&a[right]>=a[low])//让right指向比基准小的数
        {
            right--;
        }
        while(left<right&&a[left]<=a[low])//让left指向比基准大的数
        {
            left++;
        }
        if(left<right)//指针对应的值交换
        {
            t=a[right];
            a[right]=a[left];
            a[left]=t;
        }
    }
    t=a[right];//让基准处于两块分区中间
    a[right]=a[low];
    a[low]=t;
    quicksort(a,low,right-1);//分别对两块分区再次快速排序
    quicksort(a,right+1,high);
}
```