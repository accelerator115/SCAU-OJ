#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    vector<int> prefixSum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i - 1] + ((s[i - 1] == 'E') ? 1 : -1);
    }
    
    
    int minPrefixSum = prefixSum[0];
    int maxDiff = 0;
    
    for (int i = 1; i <= n; i++) {
        maxDiff = max(maxDiff, prefixSum[i] - minPrefixSum);
        minPrefixSum = min(minPrefixSum, prefixSum[i]);
    }
    
    cout << maxDiff << endl;
    
    return 0;
}
