#include <cstdio>
#include <algorithm>
using namespace std;

int dp[205];

int main() {
    int M, N, w, c;
    scanf("%d%d", &M, &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d%d", &w, &c);
        for (int j = M; j >= w; --j) {
            dp[j] = max(dp[j], dp[j - w] + c);
        }
    }
    printf("%d\n", dp[M]);
    return 0;
}