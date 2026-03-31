#include <iostream>

long long d[51][51];

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    for (int j = 0; j <= n; j++) d[0][j] = 1;
    for (int i = 1; i <= m; i++) {
        d[i][0] = 0;
        for (int j = 1; j <= n; j++)
            d[i][j] = d[i][j - 1] + (j > i ? 0 : d[i - j][j]);
    }
    cout << d[m][n] << endl;
    return 0;
}
