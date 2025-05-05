#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1005;  // 定义最大字符串长度

int main() {
    char str1[MAXN], str2[MAXN];  // 存储输入的两个字符串
    cin >> str1 >> str2;  // 输入两个字符串
    
    int len1 = strlen(str1);  // 计算第一个字符串长度
    int len2 = strlen(str2);  // 计算第二个字符串长度
    
    // dp[i][j]表示str1前i个字符和str2前j个字符的LCS长度
    int dp[MAXN][MAXN] = {0};  // 初始化DP表
    
    // 动态规划填表过程
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i-1] == str2[j-1]) {  // 当前字符相同
                dp[i][j] = dp[i-1][j-1] + 1;  // LCS长度+1
            } else {  // 当前字符不同
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);  // 取上方或左方的最大值
            }
        }
    }
    
    // 输出结果，dp[len1][len2]就是最终的LCS长度
    cout << dp[len1][len2] << endl;
    return 0;
}
