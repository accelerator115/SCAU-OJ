#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    // dp数组初始化，大小为2^n，初始值为-1
    vector<int> dp(1 << n, -1);
    // 全部气球被打破时得分为0
    dp[(1 << n) - 1] = 0;
    // 从所有气球状态向下遍历
    for (int mask = (1 << n) - 1; mask >= 0; --mask)
    {
        // 遍历每个气球
        for (int i = 0; i < n; ++i)
        {
            // 如果气球i未被打破
            if (!(mask & (1 << i)))
            {
                int left = 1, right = 1;
                // 检查左侧气球状态
                if (i > 0)
                    left = (mask & (1 << (i - 1))) ? 1 : a[i - 1];
                // 检查右侧气球状态
                if (i < n - 1)
                    right = (mask & (1 << (i + 1))) ? 1 : a[i + 1];
                // 计算当前气球的得分
                int coins = left * a[i] * right;
                // 计算下一个状态
                int next_mask = mask | (1 << i);
                // 如果下一个状态已计算过
                if (dp[next_mask] != -1)
                {
                    // 初始化当前状态得分
                    if (dp[mask] == -1)
                        dp[mask] = 0;
                    // 更新当前状态得分
                    dp[mask] = max(dp[mask], coins + dp[next_mask]);
                }
            }
        }
    }

    // 输出最终得分
    cout << dp[0] << endl;
    return 0;
}