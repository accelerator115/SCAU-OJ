#include <iostream>
#include <algorithm>
using namespace std;

struct I {
    int l, r;
} a[55];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].l >> a[i].r;
        if (a[i].l > a[i].r) swap(a[i].l, a[i].r);
    }

    sort(a, a + n, [](const I& x, const I& y) {
        if (x.r != y.r) return x.r < y.r;
        return x.l > y.l;
    });

    int cnt = 0, last = -2e9;
    for (int i = 0; i < n; i++) {
        if (a[i].l >= last) {
            cnt++;
            last = a[i].r;
        }
    }

    cout << n - cnt << endl;
    return 0;
}
