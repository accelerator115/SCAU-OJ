#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll a, b;
int dep;
vector<ll> cur, ans;

ll gcdll(ll x, ll y) {
    return y == 0 ? x : gcdll(y, x % y);
}

ll ceilDiv(ll x, ll y) {
    return (x + y - 1) / y;
}

bool better() {
    if (ans.empty()) {
        return true;
    }
    for (int i = dep - 1; i >= 0; --i) {
        if (cur[i] != ans[i]) {
            return cur[i] < ans[i];
        }
    }
    return false;
}

void dfs(int d, ll x, ll y, ll last) {
    if (d == dep - 1) {
        if (y % x != 0) {
            return;
        }
        ll t = y / x;
        if (t <= last) {
            return;
        }
        cur[d] = t;
        if (better()) {
            ans = cur;
        }
        return;
    }

    ll l = max(last + 1, ceilDiv(y, x));
    ll r = (y * (dep - d)) / x;

    for (ll i = l; i <= r; ++i) {
        ll nx = x * i - y;
        ll ny = y * i;
        if (nx <= 0) {
            continue;
        }
        ll g = gcdll(nx, ny);
        nx /= g;
        ny /= g;

        cur[d] = i;
        dfs(d + 1, nx, ny, i);
    }
}

int main() {
    cin >> a >> b;

    ll g = gcdll(a, b);
    a /= g;
    b /= g;

    if (a == 1) {
        cout << b << '\n';
        return 0;
    }

    for (dep = 2; ; ++dep) {
        cur.assign(dep, 0);
        ans.clear();
        dfs(0, a, b, 0);
        if (!ans.empty()) {
            for (int i = 0; i < dep; ++i) {
                if (i) {
                    cout << ' ';
                }
                cout << ans[i];
            }
            cout << '\n';
            break;
        }
    }

    return 0;
}
