#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int M, n;
	cin >> M >> n;

	vector<int> x(n), r(n);
	for (int i = 0; i < n; ++i) cin >> x[i];
	for (int i = 0; i < n; ++i) cin >> r[i];

	vector<pair<int, int>> ads(n);
	for (int i = 0; i < n; ++i) ads[i] = {x[i], r[i]};

	vector<int> pos(n + 1, 0);
	vector<long long> gain(n + 1, 0), dp(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		pos[i] = ads[i - 1].first;
		gain[i] = ads[i - 1].second;
	}

	for (int i = 1; i <= n; ++i) {
		int j = int(lower_bound(pos.begin() + 1, pos.begin() + i, pos[i] - 5) - pos.begin()) - 1;
		long long take = gain[i] + (j >= 1 ? dp[j] : 0LL);
		dp[i] = max(dp[i - 1], take);
	}

	cout << dp[n] << endl;
	return 0;
}
