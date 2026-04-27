#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T, n, m;
	cin >> T >> n >> m;
	vector<int> x(n), r(n);
	for (int i = 0; i < n; ++i) cin >> x[i];
	for (int i = 0; i < n; ++i) cin >> r[i];

	vector<pair<int, int>> pos_r(n);
	for (int i = 0; i < n; ++i) pos_r[i] = {x[i], r[i]};
	sort(pos_r.begin(), pos_r.end());
	for (int i = 0; i < n; ++i) {
		x[i] = pos_r[i].first;
		r[i] = pos_r[i].second;
	}

	vector<vector<int>> dp(n, vector<int>(m+1, 0));
	for (int i = 0; i < n; ++i) dp[i][1] = r[i];

	for (int i = 0; i < n; ++i) {
		for (int j = 2; j <= m; ++j) {
			for (int k = 0; k < i; ++k) {
				if (x[i] - x[k] > 5) {
					dp[i][j] = max(dp[i][j], dp[k][j-1] + r[i]);
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) ans = max(ans, dp[i][m]);
	cout << ans << endl;
	return 0;
}
