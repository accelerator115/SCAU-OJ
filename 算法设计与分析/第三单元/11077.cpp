#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string X, Y;
    cin >> X >> Y;
    int m = X.size();
    int n = Y.size();
    vector<int> prev(n + 1, 0);
    vector<int> curr(n + 1, 0);
    int maxlen = 0;
    int endindex_x = -1;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (X[i - 1] == Y[j - 1]) {
                curr[j] = prev[j - 1] + 1;
                if (curr[j] > maxlen) {
                    maxlen = curr[j];
                    endindex_x = i - 1;
                } else if (curr[j] == maxlen) {
                    if (endindex_x == -1 || (i - 1 - maxlen + 1) < (endindex_x - maxlen + 1)) {
                        endindex_x = i - 1;
                    }
                }
            } else {
                curr[j] = 0;
            }
        }
        prev = curr;
        fill(curr.begin(), curr.end(), 0);
    }
    cout << maxlen << endl;
    if (maxlen > 0) {
        cout << X.substr(endindex_x - maxlen + 1, maxlen) << endl;
    } else {
        cout << endl;
    }
    return 0;
}
