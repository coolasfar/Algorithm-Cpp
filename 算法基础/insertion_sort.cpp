#include <iostream>
#include <vector>
using namespace std;

/**********************************************
            | 插入排序算法 |
对于少量元素的排序，它算一个有效的算法。插入排序的
工作方式类似于在手中排序扑克牌，最终使牌按顺序排列。

**********************************************/


void insertion_sort(vector<int> &a)
{
    for(int i=1;i<a.size();++i)
    {
        int key = a[i];
        //insert a[i] into sorted sequence a[0..i-1]
        int j = i-1;
        while(j>-1 && a[j]>key)
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