#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n+1);
	for (int i = 1; i <= n; ++i) cin >> a[i];

	vector<int> sum(2*n+2, 0);
	for (int i = 1; i <= 2*n; ++i) {
		sum[i] = sum[i-1] + a[(i-1)%n+1];
	}

	vector<vector<int>> dpmin(n+2, vector<int>(n+2, 0x3f3f3f3f));
	vector<vector<int>> dpmax(n+2, vector<int>(n+2, 0));
	for (int i = 1; i <= n; ++i) dpmin[i][i] = dpmax[i][i] = 0;
	for (int len = 2; len <= n; ++len) {
		for (int i = 1; i+len-1 <= n; ++i) {
			int j = i+len-1;
			for (int k = i; k < j; ++k) {
				int s = sum[j]-sum[i-1];
				dpmin[i][j] = min(dpmin[i][j], dpmin[i][k]+dpmin[k+1][j]+s);
				dpmax[i][j] = max(dpmax[i][j], dpmax[i][k]+dpmax[k+1][j]+s);
			}
		}
	}
	cout << dpmin[1][n] << " " << dpmax[1][n] << endl;

	int ringmin = 0x3f3f3f3f, ringmax = 0;
	vector<vector<int>> dp2min(2*n+2, vector<int>(2*n+2, 0x3f3f3f3f));
	vector<vector<int>> dp2max(2*n+2, vector<int>(2*n+2, 0));
	for (int i = 1; i <= 2*n; ++i) dp2min[i][i] = dp2max[i][i] = 0;
	for (int len = 2; len <= n; ++len) {
		for (int i = 1; i+len-1 <= 2*n; ++i) {
			int j = i+len-1;
			for (int k = i; k < j; ++k) {
				int s = sum[j]-sum[i-1];
				dp2min[i][j] = min(dp2min[i][j], dp2min[i][k]+dp2min[k+1][j]+s);
				dp2max[i][j] = max(dp2max[i][j], dp2max[i][k]+dp2max[k+1][j]+s);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		ringmin = min(ringmin, dp2min[i][i+n-1]);
		ringmax = max(ringmax, dp2max[i][i+n-1]);
	}
	cout << ringmin << " " << ringmax << endl;
	return 0;
}
