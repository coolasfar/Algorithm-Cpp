#include <iostream>
#include <vector>
using namespace std;

/****************************************************************************
            | 合并排序算法 |
合并排序采用分治策略。用递归的方式把数组分成两半，然后分别排序，最后再把两组排序好的数组
结合。递归到数组为单个元素为止。

分治算法的主要步骤分为：
1.分解
2.解决
3.合并
            | 复杂度 |
时间复杂度为O(nlog2n) (优于O(n^2))

*****************************************************************************/


//该部分代码负责"合并"步骤
//负责将两个排序好的数组a[p,q]和a[q+1,r]合成一个排序好的数组
void Merge(int a[], int p,int q,int r)
{
    //两个数组的长度分别为
    int n1 = q-p+1;
    int n2 = r-q;

    //两个新的数组L,R, L=a[p,q],R=a[p+1,r]
    int L[n1],R[n1];
    for(int i=0;i<n1;++i) L[i]=a[p+i];
    for(int j=0;j<n2;++j) R[j]=a[q+1+j];

    int i=0,j=0;
    //从头比较两组数组，选取更小的
    int k=p;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k]=R[j];
            j++;
        }
        k++;
    }
    //R组已经排完
    while(i<n1)
    {
        a[k]=L[i];
        i++;
        k++;
    }
    //L组已经排完
    while(j<n2)
    {
        a[k]=R[j];
        j++;
        k++;
    }
}
//数组a的合并排序算法
void Merge_sort(int a[] ,int p,int r)
{
    if(p<r)
    {
        int q = (p+r)/2;
        Merge_sort(a,p,q);   
        Merge_sort(a,q+1,r);
        Merge(a,p,q,r);
    }
}

int main()
{
    int a[]={5,2,4,7,1,3,2,6};
    int size = sizeof(a)/sizeof(a[0]);
    Merge_sort(a,0,size-1);

    for(auto it:a)
    {
        cout<<it<<" ";
    }

    return 0;
}