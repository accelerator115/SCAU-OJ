#include <iostream>
#include <vector>

using namespace std;

vector<long long> dp;

long long solve(int n) {
    if (n < 2) return 0;
    if (n == 2 || n == 3) return 1;
    
    if (dp[n] != -1) return dp[n];
    
    long long result = 0;
    for (int i = 2; i < n; i++) {
        result += solve(i) * solve(n + 1 - i);
    }
    
    dp[n] = result;
    return result;
}

int main() {
    int n;
    cin >> n;
    
    if (n < 3) {
        cout << "No answer" << endl;
    } else {
        dp.assign(n + 1, -1);
        dp[2] = 1;
        dp[3] = 1;
        cout << solve(n) << endl;
    }
    
    return 0;
}
