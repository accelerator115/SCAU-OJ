#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> dp(n + 1, 0);
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i - 1; ++j) {
            dp[i] += dp[j] * dp[i - j];
        }
    }
    cout << dp[n] << endl;
    return 0;
}