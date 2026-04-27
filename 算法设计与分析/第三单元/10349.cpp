#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int R, C;
vector<vector<int>> h, dp;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dfs(int x, int y) {
	if (dp[x][y]) return dp[x][y];
	int res = 1;
	for (int d = 0; d < 4; ++d) {
		int nx = x + dx[d], ny = y + dy[d];
		if (nx >= 0 && nx < R && ny >= 0 && ny < C && h[nx][ny] < h[x][y]) {
			res = max(res, dfs(nx, ny) + 1);
		}
	}
	return dp[x][y] = res;
}

int main() {
	cin >> R >> C;
	h.assign(R, vector<int>(C));
	dp.assign(R, vector<int>(C, 0));
	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
			cin >> h[i][j];
	int ans = 0;
	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
			ans = max(ans, dfs(i, j));
	cout << ans << endl;
	return 0;
}
