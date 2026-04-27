#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 305;
int dp[MAXN][MAXN], sum[MAXN];

int main() {
    int n, m[MAXN];
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &m[i]);
        sum[i] = sum[i-1] + m[i];
    }
    memset(dp, 0, sizeof(dp));
    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            dp[i][j] = 1e9;
            for (int k = i; k < j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + sum[j] - sum[i-1]);
            }
        }
    }
    printf("%d\n", dp[1][n]);
    return 0;
}