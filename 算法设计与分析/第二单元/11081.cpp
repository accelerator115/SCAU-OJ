#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    int mx = x[n / 2];
    int my = y[n / 2];
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += abs(x[i] - mx) + abs(y[i] - my);
    }
    cout << ans << endl;
    return 0;
}