#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, c;
    cin >> n >> m >> c;
    vector<vector<int>> color_pos(c + 1);

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        for (int j = 0; j < num; ++j) {
            int x;
            cin >> x;
            color_pos[x].push_back(i);
        }
    }

    int ans = 0;
    for (int x = 1; x <= c; ++x) {
        auto& v = color_pos[x];
        if (v.size() < 2) continue;

        sort(v.begin(), v.end());
        bool valid = true;

        for (size_t i = 0; i < v.size(); ++i) {
            size_t j = (i + 1) % v.size();
            int diff;
            if (j == 0) {
                diff = (v[j] + n) - v[i];
            } else {
                diff = v[j] - v[i];
            }
            if (diff <= m - 1) {
                valid = false;
                break;
            }
        }

        if (!valid) {
            ++ans;
        }
    }

    cout << ans << endl;
    return 0;
}