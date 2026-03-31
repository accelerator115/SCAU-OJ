#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    unsigned long long f[37];
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[2 * i] = 0;
        for (int j = 1; j <= i; j++)
            f[2 * i] += f[2 * j - 2] * f[2 * i - 2 * j];
    }

    cout << f[2 * n] << endl;
    return 0;
}
