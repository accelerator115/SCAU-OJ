#include <iostream>
#include <map>
using namespace std;

// 记忆化数组，用于存储已计算过的状态
// key: n*100001 + pos（使用大数避免冲突）
// value: 在n个人中，位置pos的人是否能被选中
map<long long, bool> memo;

/**
 * 判断在n个人中，位置pos的人是否能被选中
 * 这是约瑟夫环问题的变形，使用分治法求解
 * 
 * @param n 总人数
 * @param pos 当前位置（从1开始）
 * @return 该位置的人是否能被选中
 */
bool canBeChosen(int n, int pos)
{
    // 基本情况：只有当n=3时，才能被选中
    // 约瑟夫环问题中的特殊情况
    if (n <= 3)
    {
        return n == 3;
    }
    
    // 构造唯一键值用于记忆化搜索
    long long key = (long long)n * 100001 + pos;
    
    // 检查是否已计算过该状态
    if (memo.find(key) != memo.end())
    {
        return memo[key];
    }

    bool result = false;
    
    // 如果位置是偶数，可以从n/2大小的子问题中映射
    if (pos % 2 == 0)
    {
        int newN = n / 2;         // 新的总人数
        int newPos = pos / 2;     // 新的位置
        if (canBeChosen(newN, newPos))
        {
            result = true;
        }
    }
    
    // 如果位置是奇数且前面的情况不能被选中，尝试另一种映射
    if (!result && pos % 2 == 1)
    {
        int newN = n / 2;
        // 如果原始总人数是奇数，需要调整新的总人数
        if (n % 2 == 1)
        {
            newN++;
        }
        int newPos = (pos + 1) / 2;  // 新的位置
        if (canBeChosen(newN, newPos))
        {
            result = true;
        }
    }
    
    // 记录计算结果到记忆化数组
    memo[key] = result;

    return result;
}

int main()
{
    int n, pos;
    
    // 读取输入，直到遇到 n=0 且 pos=0 时结束
    while (cin >> n >> pos && (n != 0 || pos != 0))
    {
        // 判断并输出结果
        if (canBeChosen(n, pos))
        {
            cout << "Y" << endl;  // 该位置的人能被选中
        }
        else
        {
            cout << "N" << endl;  // 该位置的人不能被选中
        }
    }

    return 0;
}