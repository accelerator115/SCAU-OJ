#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 0;
    cin >> n;

    vector<vector<long long>> p(n, vector<long long>(n));
    vector<vector<long long>> q(n, vector<long long>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> p[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> q[i][j];
        }
    }

    vector<vector<long long>> score(n, vector<long long>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            score[i][j] = p[i][j] * q[j][i];
        }
    }

    vector<vector<long long>> dp(n + 1, vector<long long>(1 << n, -1));
    dp[0][0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int mask = 0; mask < (1 << n); ++mask) {
            if (dp[i][mask] == -1) continue;
            for (int j = 0; j < n; ++j) {
                if (mask & (1 << j)) continue;
                int new_mask = mask | (1 << j);
                dp[i + 1][new_mask] = max(dp[i + 1][new_mask], dp[i][mask] + score[i][j]);
            }
        }
    }

    cout << dp[n][(1 << n) - 1];
    return 0;
}