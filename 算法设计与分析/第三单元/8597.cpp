#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 1005;
int a[MAXN], dp[MAXN][MAXN];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) 
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);

    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i][1] = (a[i] - a[1]) * (a[i] - a[1]);
    }
    for (int j = 2; j <= m; ++j) {
        for (int i = j; i <= n; ++i) {
            for (int k = 1; k <= i - j + 1; ++k) {
                int cost = (a[i] - a[i - k + 1]) * (a[i] - a[i - k + 1]);
                dp[i][j] = min(dp[i][j], dp[i - k][j - 1] + cost);
            }
        }
    }
    printf("%d\n", dp[n][m]);
    return 0;
}