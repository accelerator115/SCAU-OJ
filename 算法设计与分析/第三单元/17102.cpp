#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> w(n + 1);
    for (int i = 1; i <= n; i++) cin >> w[i];

    if (n == 1) {
        cout << w[1] << endl;
        return 0;
    }

    long long f1 = w[1];
    long long f2 = max(w[1], w[2]);
    if (n == 2) {
        cout << f2 << endl;
        return 0;
    }

    long long fi;
    for (int i = 3; i <= n; i++) {
        fi = max({f2, f1 + w[i], w[i]});
        f1 = f2;
        f2 = fi;
    }
    cout << f2 << endl;
    return 0;
}
