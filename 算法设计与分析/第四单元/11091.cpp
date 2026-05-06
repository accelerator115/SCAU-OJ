#include <iostream>
using namespace std;

// 问题1：互不相同的自然数分解
long long solve1(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 2;      
    if (n == 4) return 3;      

    int k = 2;
    long long sum = 2;
    while (sum + k + 1 <= n) {
        k++;
        sum += k;
    }

    int len = k - 1;
    long long r = n - sum;

    int add_base = r / len;       
    int add_extra = r % len;       
    
    long long result = 1;
    for (int i = 2; i <= k; i++) {
        int add = (i < k + 1 - add_extra) ? add_base : add_base + 1;
        result *= (i + add);
    }
    
    return result;
}

long long solve2(int n) {
    int rem = n % 3;
    
    if (rem == 0) {
        long long result = 1;
        for (int i = 0; i < n / 3; i++) {
            result *= 3;
        }
        return result;
    } else if (rem == 1) {
        long long result = 4;
        for (int i = 0; i < (n - 4) / 3; i++) {
            result *= 3;
        }
        return result;
    } else {
        long long result = 2;
        for (int i = 0; i < (n - 2) / 3; i++) {
            result *= 3;
        }
        return result;
    }
}

int main() {
    int n;
    cin >> n;
    
    long long ans1 = solve1(n);
    long long ans2 = solve2(n);
    
    cout << ans1 << " " << ans2 << endl;
    
    return 0;
}
