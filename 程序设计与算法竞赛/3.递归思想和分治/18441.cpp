#include <iostream>
#include <map>
using namespace std;

// 记忆化存储，避免重复计算
map<long long, long long> memo;

long long countImpossible(long long n)
{
    // 基本情况: 当 n <= 2 时，直接返回 n
    if (n <= 2)
        return n;
    // 特殊情况: n = 3 时, 可以表示为 1+2, 所以返回 0
    if (n == 3)
        return 0;
    // 如果已经计算过，直接返回记忆化的结果
    if (memo.count(n))
        return memo[n];

    long long result;
    if (n % 2 == 0)
    {
        // 对于偶数 n，使用递归关系式
        // 不可能情况数 = n - 2 * (n/2 - 不可能情况数(n/2))
        result = n - 2 * (n / 2 - countImpossible(n / 2));
    }
    else
    {
        // 对于奇数 n，使用不同的递归关系式
        // 不可能情况数 = n - ((n+1)/2 - 不可能情况数((n+1)/2)) - (n/2 - 不可能情况数(n/2))
        result = n - ((n + 1) / 2 - countImpossible((n + 1) / 2)) - (n / 2 - countImpossible(n / 2));
    }

    // 存储计算结果到记忆化表中
    memo[n] = result;
    return result;
}

int main()
{
    long long n;
    // 读入多组测试数据，当输入为 0 时结束
    while (cin >> n && n != 0)
    {
        // 输出对于数字 n，不能表示为连续正整数之和的情况数
        cout << countImpossible(n) << endl;
    }
    return 0;
}
