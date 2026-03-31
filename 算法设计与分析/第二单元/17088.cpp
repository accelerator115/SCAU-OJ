#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m = -1;
int cnt  = 0;

void find(vector<int>& a, int l, int r) {
    if (l > r) return;
    
    int mid = (l + r) / 2;
    int v = a[mid];

    int c = 0;
    int f = -1, ls = -1;

    for (int i = l; i <= r; ++i) {
        if (a[i] == v) {
            if (f == -1) f = i;
            ls = i;
            c++;
        }
    }

    if (c > cnt) {
        cnt = c;
        m = v;
    } else if (c == cnt) {
        if (v < m) {
            m = v;
        }
    }

    if (f - l > cnt) {
        find(a, l, f - 1);
    }

    if (r - ls > cnt) {
        find(a, ls + 1, r);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    find(a, 0, n - 1);

    cout << m << " " << cnt << endl;

    return 0;
}
