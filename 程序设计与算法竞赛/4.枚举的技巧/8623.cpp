#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll; // 定义长整型别名，避免多次书写 long long

/**
 * 解决单个测试用例
 * 该函数计算从1到n的所有整数的所有约数之和
 * 使用了数学优化技巧，避免暴力枚举每个数的所有约数
 */
void solve()
{
    ll n;
    scanf("%lld", &n);
    // 处理无效输入（负数）
    if(n < 0)
    {
        printf("0\n");
        return;
    }
    
    ll res = 0; // 存储结果：所有约数之和
    ll i = 1;   // 从1开始枚举
    ll m = 0;   // 记录n的平方根取整（算法中的优化点）
    ll lst = 0; // 记录上一次的n/i值
    
    // 第一阶段：找到n的平方根
    while(1)
    {
        ll tmp = n / i; // 计算n/i的商
        res += tmp;     // 累加到结果中
        
        // 当两次商相等时，我们已经超过了n的平方根
        if(tmp == lst)
        {
            res -= tmp * 2; // 修正重复计算的部分
            m = tmp;        // 记录m值（近似为n的平方根）
            break;
        }
        i++;
        lst = tmp;
    }
    
    // 第二阶段：使用数学技巧计算约数和
    // 这里利用了整数除法的性质，合并相同商的区间
    for(i = 1; i <= m; i++)
    {
        // n/i - n/(i+1) 表示有多少个数的约数包含i
        // 乘以i表示这些约数的和
        res += (n / i - n / (i + 1)) * i;
    }
    
    printf("%lld\n", res);
}

int main()
{
    int t; // 测试用例数量
    scanf("%d", &t);
    // 处理每个测试用例
    while(t--)
    {
        solve();
    }
    return 0;
}