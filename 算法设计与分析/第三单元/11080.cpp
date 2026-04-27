#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int m, n;
	cin >> m >> n;
	vector<vector<int>> a(m, vector<int>(n));
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			cin >> a[i][j];

	vector<vector<int>> b(2*m-1, vector<int>(2*n-1));
	for (int i = 0; i < 2*m-1; ++i)
		for (int j = 0; j < 2*n-1; ++j)
			b[i][j] = a[i%m][j%n];

	vector<vector<int>> sum(2*m, vector<int>(2*n, 0));
	for (int i = 1; i <= 2*m-1; ++i)
		for (int j = 1; j <= 2*n-1; ++j)
			sum[i][j] = b[i-1][j-1] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];

	int ans = b[0][0];
	for (int top = 1; top <= m; ++top) {
		for (int bottom = top; bottom < top + m && bottom <= 2*m-1; ++bottom) {
			for (int left = 1; left <= n; ++left) {
				for (int right = left; right < left + n && right <= 2*n-1; ++right) {
					int cur = sum[bottom][right] - sum[top-1][right] - sum[bottom][left-1] + sum[top-1][left-1];
					ans = max(ans, cur);
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
