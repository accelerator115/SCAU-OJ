#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> l(n + 1), h(n + 1);
    for (int i = 1; i <= n; i++) cin >> l[i];
    for (int i = 1; i <= n; i++) cin >> h[i];

    vector<long long> d(n + 1, 0);
    d[1] = l[1];
    if (n >= 2) d[2] = max(l[1] + l[2], h[2]);
    for (int i = 3; i <= n; i++) {
        d[i] = max(d[i - 1] + l[i], d[i - 2] + h[i]);
    }
    cout << d[n] << endl;
    return 0;
}
