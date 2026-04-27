#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

int main() {
    int n, m;
    cin >> n;
    vector<int> v(n), k(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    for (int i = 0; i < n; ++i) cin >> k[i];
    cin >> m;

    vector<long long> ways(m + 1, 0), prevWays(m + 1, 0);
    ways[0] = 1;
    for (int i = 0; i < n; ++i) {
        prevWays = ways;
        fill(ways.begin(), ways.end(), 0);

        if (v[i] == 0) {
            for (int j = 0; j <= m; ++j) {
                ways[j] = prevWays[j] * (k[i] + 1LL);
            }
            continue;
        }

        for (int j = 0; j <= m; ++j) {
            for (int c = 0; c <= k[i] && j >= c * v[i]; ++c) {
                ways[j] += prevWays[j - c * v[i]];
            }
        }
    }
    cout << ways[m] << endl;

    vector<int> minc(m + 1, INF), prevMin(m + 1, INF);
    minc[0] = 0;
    for (int i = 0; i < n; ++i) {
        prevMin = minc;

        if (v[i] == 0) {
            continue;
        }

        for (int j = 0; j <= m; ++j) {
            int best = prevMin[j];
            for (int c = 1; c <= k[i] && j >= c * v[i]; ++c) {
                if (prevMin[j - c * v[i]] != INF && prevMin[j - c * v[i]] + c < best) {
                    best = prevMin[j - c * v[i]] + c;
                }
            }
            minc[j] = best;
        }
    }
    if (minc[m] == INF)
        cout << "no possible" << endl;
    else
        cout << minc[m] << endl;
    return 0;
}