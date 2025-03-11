#include <iostream>
#include <vector>
#define INT_MIN -40000
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int max_diff = INT_MIN; 
    int min_val = a[0];   

    for (int i = 1; i < n; ++i) {
        max_diff = max(max_diff, a[i] - min_val);
        min_val = min(min_val, a[i]);
    }

    if (max_diff == INT_MIN) {
        cout << 0 << endl;
    } else {
        cout << max_diff << endl;
    }

    return 0;
}