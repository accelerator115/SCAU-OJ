#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long NEG_INF = -(1LL << 60);

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n + 1, 0);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    vector<long long> endAt(m + 1, NEG_INF), best(m + 1, NEG_INF);
    best[0] = 0;

    for (int i = 1; i <= n; ++i) {
        int up = min(i, m);
        for (int j = up; j >= 1; --j) {
            endAt[j] = max(endAt[j] + a[i], best[j - 1] + a[i]);
            best[j] = max(best[j], endAt[j]);
        }
    }

    cout << max(0LL, best[m]) << endl;
    return 0;
}