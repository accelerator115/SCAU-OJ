#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
	int v;
	int w;
	int t;
};

int main() {
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

	int n, V, W;
	cin >> n >> V >> W;

	vector<Item> items;
	items.reserve(n * 8);

	for (int i = 0; i < n; ++i) {
		int vi, wi, ci, ti;
		cin >> vi >> wi >> ci >> ti;

		int k = 1;
		while (k <= ci) {
			items.push_back({vi * k, wi * k, ti * k});
			ci -= k;
			k <<= 1;
		}
		if (ci > 0) {
			items.push_back({vi * ci, wi * ci, ti * ci});
		}
	}

	vector<vector<int>> dp(V + 1, vector<int>(W + 1, 0));

	for (const auto& it : items) {
		for (int x = V; x >= it.v; --x) {
			for (int y = W; y >= it.w; --y) {
				dp[x][y] = max(dp[x][y], dp[x - it.v][y - it.w] + it.t);
			}
		}
	}

	cout << dp[V][W];
	return 0;
}
