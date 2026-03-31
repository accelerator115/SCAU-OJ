#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int idx = 1;

void solve(const string &s, int pos, int m, string &cur) {
    if (m == 0) {
        cout << idx++ << " " << cur << endl;
        return;
    }
    for (int i = pos; i <= (int)s.size() - m; i++) {
        cur.push_back(s[i]);
        solve(s, i + 1, m - 1, cur);
        cur.pop_back();
    }
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    sort(s.begin(), s.end());

    for (int m = 1; m <= n; m++) {
        string cur;
        solve(s, 0, m, cur);
    }

    return 0;
}
