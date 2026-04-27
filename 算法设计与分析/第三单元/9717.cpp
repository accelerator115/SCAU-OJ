#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<long long> prefix(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + a[i];
    }
    vector<vector<long long>> dp(n + 2, vector<long long>(n + 2, 0));
    for (int i = 1; i <= n; ++i) {
        dp[i][i] = a[i];
    }
    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            long long sum = prefix[j] - prefix[i - 1];
            dp[i][j] = sum - min(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    long long first = dp[1][n];
    long long total = prefix[n];
    long long second = total - first;
    
    cout << first << " " << second;
    return 0;
}
