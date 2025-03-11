#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> prefix(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        int num;
        cin >> num;
        prefix[i] = prefix[i - 1] + num;
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; ++i) {
        int L, R;
        cin >> L >> R;
        cout << prefix[R] - prefix[L - 1] << '\n';
    }

    return 0;
}