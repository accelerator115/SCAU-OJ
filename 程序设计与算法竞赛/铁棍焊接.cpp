#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<long long> rods(n);
    for (int i = 0; i < n; i++) {
        cin >> rods[i];
    }
    
    set<long long> results;
    
    // 枚举所有可能的子集 (1 到 2^n - 1)
    for (int mask = 1; mask < (1 << n); mask++) {
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                sum += rods[i];
            }
        }
        results.insert(sum);
    }
    
    // 输出结果
    for (long long length : results) {
        cout << length << " ";
    }
    cout << endl;
    
    return 0;
}