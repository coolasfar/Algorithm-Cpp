#include <iostream>
#include <vector>
using namespace std;

/****************************************************************************
            | 插入排序算法 |
对于少量元素的排序，它算一个有效的算法。插入排序的工作方式类似于在手中排序扑克牌，
最终使牌按顺序排列。
            | 时间复杂度 |
最好情况下，数组已排序好，这时while loop不执行，所以运行时间为n。
最坏情况，数组完全是倒序，需要的运行时间为n^2。
所以根据最坏情况，插入排序的算法时间复杂度为O(n^2)
*****************************************************************************/


void insertion_sort(vector<int> &a)
{
    for(int i=1;i<a.size();++i)
    {
        int key = a[i];
        //insert a[i] into sorted sequence a[0..i-1]
        int j = i-1;
        while(j>=0 && a[j]>key)  //如果是降序则a[j]<key
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

int main()
{
    vector<int> a{2,4,7,1,8};

    insertion_sort(a);

    for(auto it:a)
    {
        cout<<it<<" ";
    }

    return 0;
}