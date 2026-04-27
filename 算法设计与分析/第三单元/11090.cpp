#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, m;
string S;
vector<vector<long long>> f, g;
vector<vector<int>> pre1, pre2;

int getNum(int l, int r) {
    string t = S.substr(l - 1, r - l + 1);
    int i = 0;
    while (i < t.size() - 1 && t[i] == '0') i++;
    t = t.substr(i);
    return stoi(t);
}

void getMaxExpr(int i, int j, vector<string>& segs) {
    if (j == 1) {
        string t = S.substr(0, i);
        int k = 0;
        while (k < t.size() - 1 && t[k] == '0') k++;
        segs.push_back(t.substr(k));
        return;
    }
    int k = pre1[i][j];
    getMaxExpr(k, j - 1, segs);
    string t = S.substr(k, i - k);
    int p = 0;
    while (p < t.size() - 1 && t[p] == '0') p++;
    segs.push_back(t.substr(p));
}

void getMinExpr(int i, int j, vector<string>& segs) {
    if (j == 1) {
        string t = S.substr(0, i);
        int k = 0;
        while (k < t.size() - 1 && t[k] == '0') k++;
        segs.push_back(t.substr(k));
        return;
    }
    int k = pre2[i][j];
    getMinExpr(k, j - 1, segs);
    string t = S.substr(k, i - k);
    int p = 0;
    while (p < t.size() - 1 && t[p] == '0') p++;
    segs.push_back(t.substr(p));
}

int main() {
    cin >> n >> m >> S;
    f.assign(n + 1, vector<long long>(m + 1, -1000000000000000000LL)); // -1e18
    g.assign(n + 1, vector<long long>(m + 1, 1000000000000000000LL));  // 1e18
    pre1.assign(n + 1, vector<int>(m + 1, -1));
    pre2.assign(n + 1, vector<int>(m + 1, -1));

    for (int i = 1; i <= n; ++i) {
        f[i][1] = g[i][1] = getNum(1, i);
    }

    for (int j = 2; j <= m; ++j) {
        for (int i = j; i <= n; ++i) {
            for (int k = j - 1; k <= i - 1; ++k) {
                long long num = getNum(k + 1, i);
                if (f[k][j - 1] * num > f[i][j]) {
                    f[i][j] = f[k][j - 1] * num;
                    pre1[i][j] = k;
                }
                if (g[k][j - 1] + num < g[i][j]) {
                    g[i][j] = g[k][j - 1] + num;
                    pre2[i][j] = k;
                }
            }
        }
    }

    cout << f[n][m] << " " << g[n][m] << endl;

    vector<string> maxSegs, minSegs;
    getMaxExpr(n, m, maxSegs);
    getMinExpr(n, m, minSegs);

    for (int i = 0; i < maxSegs.size(); ++i) {
        if (i) cout << "*";
        cout << maxSegs[i];
    }
    cout << "=" << f[n][m] << endl;

    for (int i = 0; i < minSegs.size(); ++i) {
        if (i) cout << "+";
        cout << minSegs[i];
    }
    cout << "=" << g[n][m] << endl;

    return 0;
}