#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> cows(n);
    for (int i = 0; i < n; ++i) {
        cin >> cows[i];
    }

    vector<int> prefix_black(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix_black[i] = prefix_black[i - 1] + (cows[i - 1] == 2);
    }

    vector<int> suffix_white(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
        suffix_white[i] = suffix_white[i + 1] + (cows[i] == 1);
    }

    int min_changes = n;
    for (int k = 0; k <= n; ++k) {
        int changes = prefix_black[k] + suffix_white[k];
        min_changes = min(min_changes, changes);
    }

    cout << min_changes << endl;

    return 0;
}