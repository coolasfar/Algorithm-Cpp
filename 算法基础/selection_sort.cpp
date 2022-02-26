#include <iostream>
#include <vector>
using namespace std;

/****************************************************************************
            | 选择排序算法 |
找出数组中最小的元素与第一个元素交换，然后找出次最小的元素与第二个元素交换，以此类推
            | 复杂度 |
时间复杂度为O(n^2),空间复杂度为O(1) (不需要额外的数组)
*****************************************************************************/

void selection_sort(vector<int> &a)
{
    int min_index;
    for(int i=0;i<a.size()-1;++i)
    {
        min_index=i;
        for(int j=i+1;j<a.size();++j)
        {
            if (a[j]<a[min_index])
            {
                min_index=j;
            }
        }
        swap(a[i],a[min_index]);       
    }
}

int main()
{
    vector<int> a={2,4,7,1,8};

    selection_sort(a);

    for(auto it:a)
    {
        cout<<it<<" ";
    }

    return 0;
}