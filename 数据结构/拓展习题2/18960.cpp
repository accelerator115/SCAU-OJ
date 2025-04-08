#include <iostream>
#include <cstring>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

bool backtrack(int n, int result[], bool used[], int pos) {
    if (pos == n) {
        return isPrime(result[0] + result[n-1]);
    }
    
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            if (isPrime(result[pos-1] + i)) {
                result[pos] = i;
                used[i] = true;
                if (backtrack(n, result, used, pos + 1))
                    return true;
                used[i] = false;
            }
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    
    if (n < 2 || n > 20) {
        cout << -1 << endl;
        return 0;
    }
    
    int result[21];
    bool used[21];
    
    memset(used, false, sizeof(used));
    memset(result, 0, sizeof(result));
    
    result[0] = 1;
    used[1] = true;
    
    if (backtrack(n, result, used, 1)) {
        for (int i = 0; i < n; i++) {
            cout << result[i]<<" ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}