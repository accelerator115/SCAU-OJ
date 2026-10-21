#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Ans {
    int a;
    int b;
    int cnt;
};

int n, c1, c2;
vector<int> wt;

vector<int> pickFirst(int cap, const vector<int>& use) {
    vector<vector<char>> can(n + 1, vector<char>(cap + 1, 0));
    can[n][0] = 1;

    for (int i = n - 1; i >= 0; --i) {
        for (int s = 0; s <= cap; ++s) {
            can[i][s] = can[i + 1][s];
            if (use[i] && s >= wt[i] && can[i + 1][s - wt[i]]) {
                can[i][s] = 1;
            }
        }
    }

    int best = 0;
    for (int s = cap; s >= 0; --s) {
        if (can[0][s]) {
            best = s;
            break;
        }
    }

    vector<int> chosen(n, 0);
    int remain = best;
    for (int i = 0; i < n; ++i) {
        if (use[i] && remain >= wt[i] && can[i + 1][remain - wt[i]]) {
            chosen[i] = 1;
            remain -= wt[i];
        }
    }
    return chosen;
}

int sumWeight(const vector<int>& chosen) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (chosen[i]) {
            sum += wt[i];
        }
    }
    return sum;
}

int sumCount(const vector<int>& chosen) {
    int cnt = 0;
    for (int x : chosen) {
        cnt += x;
    }
    return cnt;
}

Ans solve12(int firstCap, int secondCap) {
    vector<int> use(n, 1);
    vector<int> p1 = pickFirst(firstCap, use);

    for (int i = 0; i < n; ++i) {
        if (p1[i]) {
            use[i] = 0;
        }
    }

    vector<int> p2 = pickFirst(secondCap, use);

    Ans ans;
    ans.a = sumWeight(p1);
    ans.b = sumWeight(p2);
    ans.cnt = sumCount(p1) + sumCount(p2);
    return ans;
}

int solve3() {
    vector<vector<char>> dp(c1 + 1, vector<char>(c2 + 1, 0));
    dp[0][0] = 1;

    for (int x : wt) {
        for (int i = c1; i >= 0; --i) {
            for (int j = c2; j >= 0; --j) {
                if (!dp[i][j]) {
                    continue;
                }
                if (i + x <= c1) {
                    dp[i + x][j] = 1;
                }
                if (j + x <= c2) {
                    dp[i][j + x] = 1;
                }
            }
        }
    }

    int best = 0;
    for (int i = 0; i <= c1; ++i) {
        for (int j = 0; j <= c2; ++j) {
            if (dp[i][j]) {
                best = max(best, i + j);
            }
        }
    }
    return best;
}

int solve4() {
    const int NEG = -1000000000;
    vector<vector<int>> dp(c1 + 1, vector<int>(c2 + 1, NEG));
    dp[0][0] = 0;

    for (int x : wt) {
        for (int i = c1; i >= 0; --i) {
            for (int j = c2; j >= 0; --j) {
                if (dp[i][j] == NEG) {
                    continue;
                }
                if (i + x <= c1) {
                    dp[i + x][j] = max(dp[i + x][j], dp[i][j] + 1);
                }
                if (j + x <= c2) {
                    dp[i][j + x] = max(dp[i][j + x], dp[i][j] + 1);
                }
            }
        }
    }

    int best = 0;
    for (int i = 0; i <= c1; ++i) {
        for (int j = 0; j <= c2; ++j) {
            best = max(best, dp[i][j]);
        }
    }
    return best;
}

int main() {
    cin >> n >> c1 >> c2;
    wt.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> wt[i];
    }

    Ans x = solve12(c1, c2);
    Ans y = solve12(c2, c1);

    cout << x.a << ' ' << x.b << ' ' << x.cnt << '\n';
    cout << y.b << ' ' << y.a << ' ' << y.cnt << '\n';
    cout << solve3() << '\n';
    cout << solve4() << '\n';

    return 0;
}
