#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 35;
const int MAXM = 205;
int W[MAXN];
int C[MAXN];
int main() {
    int M, N;
    cin >> M >> N;
    for (int i = 1; i <= N; i++) {
        cin >> W[i] >> C[i];
    }
    int dp[MAXM] = {0};
    for (int i = 1; i <= N; i++) {
        for (int j = M; j >= W[i]; j--) {
            dp[j] = max(dp[j], dp[j - W[i]] + C[i]);
        }
    }
    cout << dp[M] << endl;
    return 0;
}
