#include <iostream>     // 包含输入输出流库
#include <algorithm>    // 包含算法库，提供sort和next_permutation等函数
using namespace std;

int main()
{
    int n;              // 定义整数n，表示数组的大小
    cin>>n;             // 输入数组大小
    int *arr = new int(n);  // 动态分配内存，创建大小为n的整数数组
                        // 注意：这里有一个bug，应该是 new int[n]
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];    // 输入数组的n个元素
    }
    sort(arr,arr+n);    // 对数组进行排序，确保从最小的排列开始
    do
    {
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";  // 输出当前排列的每个元素
        }
        cout<<endl;     // 每个排列输出完成后换行
    }while(next_permutation(arr,arr+n));  // 生成下一个排列，直到没有下一个排列为止
                        // next_permutation函数会按字典序生成下一个排列
    delete[] arr;       // 释放动态分配的内存
    return 0;
}