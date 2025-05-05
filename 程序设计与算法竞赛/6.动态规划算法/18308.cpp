#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1005;

int main() {
    char str1[MAXN], str2[MAXN];
    cin >> str1 >> str2;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int dp[MAXN][MAXN] = {0};
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[len1][len2] << endl;
    return 0;
}
