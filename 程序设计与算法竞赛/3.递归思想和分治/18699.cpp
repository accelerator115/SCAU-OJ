#include <iostream>
using namespace std;

// n: 待排序数组的元素个数
int n;
// data: 存储输入数据的数组
int data[1001];
// temp: 归并排序过程中用于临时存储的辅助数组
int temp[1001];


void merge_sort(int *A, int x, int y, int *T)
{
    // 如果区间长度大于1，才需要排序
    if (y - x > 1)
    {
        // 计算中间点，将区间分成两部分
        int m = (x + y) / 2;
        
        // 递归排序左半部分 [x, m)
        merge_sort(A, x, m, T);
        // 递归排序右半部分 [m, y)
        merge_sort(A, m, y, T);
        
        // 合并两个已排序的子区间
        // p指向左半部分的起始位置，q指向右半部分的起始位置
        // i是临时数组的当前填充位置
        int p = x, q = m, i = x;
        
        // 当左半部分或右半部分还有元素时，继续合并
        while (p < m || q < y)
        {
            // 如果右半部分已经没有元素，或者左半部分的当前元素小于等于右半部分的当前元素
            // 则将左半部分的当前元素放入临时数组
            if (q >= y || (p < m && A[p] <= A[q]))
                T[i++] = A[p++];
            // 否则将右半部分的当前元素放入临时数组
            else
                T[i++] = A[q++];
        }
        
        // 将临时数组中的已排序元素复制回原数组
        for (i = x; i < y; i++)
            A[i] = T[i];
    }
    // 对于长度为1或0的区间，不需要进行任何操作（已经是有序的）
}

int main()
{
    // 读取数组大小
    cin >> n;
    
    // 读取n个整数到data数组
    for (int i = 0; i < n; i++)
        cin >> data[i];
    
    // 调用归并排序函数对整个data数组进行排序
    merge_sort(data, 0, n, temp);
    
    // 按顺序输出排序后的数组元素
    for (int i = 0; i < n; i++)
        cout << data[i] << endl;
}
