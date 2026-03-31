#include <iostream>
#include <cstring>
using namespace std;

long long dp1[101][101];
long long dp2[101][101];
long long dp3[101][101];
long long dp4[101][101];

int main() {
    int n, m;
    cin >> n >> m;

    memset(dp1, 0, sizeof(dp1));
    for (int j = 0; j <= m; j++) dp1[0][j] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp1[i][j] = dp1[i][j - 1];
            if (i >= j) dp1[i][j] += dp1[i - j][j];
        }
    }
    memset(dp2, 0, sizeof(dp2));
    for (int j = 0; j <= m; j++) dp2[0][j] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp2[i][j] = dp2[i][j - 1];
            if (i >= j) dp2[i][j] += dp2[i - j][j];
        }
    }

    memset(dp3, 0, sizeof(dp3));
    dp3[0][0] = 1;
    for (int i = 0; i <= n; i++) {
        for (int k = 1; k <= n; k++) {
            dp3[i][k] = dp3[i][k - 1]; 
            if (k % 2 == 1 && i >= k) dp3[i][k] += dp3[i - k][k];
        }
    }

    memset(dp4, 0, sizeof(dp4));
    dp4[0][0] = 1;
    for (int i = 0; i <= n; i++) {
        for (int k = 1; k <= n; k++) {
            dp4[i][k] = dp4[i][k - 1]; 
            if (i >= k) dp4[i][k] += dp4[i - k][k - 1]; 
        }
    }

    cout << dp1[n][m] << " " << dp2[n][m] << " " << dp3[n][n] << " " << dp4[n][n] << endl;

    return 0;
}
