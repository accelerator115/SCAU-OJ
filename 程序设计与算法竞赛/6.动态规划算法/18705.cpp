#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 35;  // 最大物品数量
const int MAXM = 205; // 最大背包容量

int W[MAXN];  // 物品重量数组，W[i]表示第i件物品的重量
int C[MAXN];  // 物品价值数组，C[i]表示第i件物品的价值

int main() {
    int M, N;  // M:背包容量，N:物品数量
    cin >> M >> N;
    
    // 输入每件物品的重量和价值
    for (int i = 1; i <= N; i++) {
        cin >> W[i] >> C[i];
    }
    
    // dp[j]表示容量为j的背包能装的最大价值
    int dp[MAXM] = {0};  // 初始化DP数组
    
    // 动态规划过程
    for (int i = 1; i <= N; i++) {  // 遍历每件物品
        // 逆序遍历背包容量，确保每件物品只被考虑一次
        for (int j = M; j >= W[i]; j--) {
            // 状态转移方程：比较不装和装当前物品两种情况
            dp[j] = max(dp[j], dp[j - W[i]] + C[i]);
        }
    }
    
    // 输出结果：容量为M的背包能装的最大价值
    cout << dp[M] << endl;
    return 0;
}
