#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 0));
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<int>> path(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= i; ++j)
            cin >> a[i][j];

    for (int j = 0; j < n; ++j)
        dp[n-1][j] = a[n-1][j];

    for (int i = n-2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            if (dp[i+1][j] > dp[i+1][j+1]) {
                dp[i][j] = a[i][j] + dp[i+1][j];
                path[i][j] = 0;
            } else {
                dp[i][j] = a[i][j] + dp[i+1][j+1];
                path[i][j] = 1;
            }
        }
    }

    cout << dp[0][0] << endl;

    int x = 0, y = 0;
    cout << a[0][0];
    for (int i = 0; i < n-1; ++i) {
        if (path[x][y] == 1) ++y;
        ++x;
        cout << " " << a[x][y];
    }
    cout << endl;
    return 0;
}