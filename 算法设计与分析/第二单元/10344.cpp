#include <iostream>
using namespace std;

long long p[21];

int main() {
    int n;
    cin >> n;

    p[1] = 1;
    for (int i = 2; i <= n; i++) {
        p[i] = 0;
        for (int k = 1; k <= i - 1; k++)
            p[i] += p[k] * p[i - k];
    }

    cout << p[n] << endl;
    return 0;
}
