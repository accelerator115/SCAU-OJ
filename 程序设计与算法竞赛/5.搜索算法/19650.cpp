#include <iostream>  // 包含输入输出流库
#include <algorithm> // 包含算法库，提供sort和next_permutation等函数
using namespace std;

int main()
{
    int n;     // 定义整数n，表示数组的大小
    cin >> n;  // 输入数组大小
    int a[11]; // 定义一个最大容量为11的整数数组
    for (int i = 0; i < n; i++)
    {
        cin >> a[i]; // 输入数组的n个元素
    }
    sort(a, a + n); // 对数组进行排序，确保从最小的排列开始
    do
    {
        int flag = 0; // 标记变量，用于判断当前排列是否满足条件
        for (int i = 0; i < n; i++)
        {
            if (i < n - 1 && a[i] % 2 && a[i + 1] % 2) // 检查是否存在相邻的两个奇数
            {
                flag = 1; // 如果存在相邻的奇数，设置标记为1
                break;    // 跳出循环
            }
        }
        if (flag == 0) // 如果不存在相邻的奇数
        {
            for (int i = 0; i < n; i++)
            {
                cout << a[i] << " "; // 输出当前排列的每个元素
            }
            cout << endl; // 每个排列输出完成后换行
        }
    } while (next_permutation(a, a + n)); // 生成下一个排列，直到没有下一个排列为止
                                          // next_permutation函数会按字典序生成下一个排列
    return 0;
}