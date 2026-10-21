#include <iostream>

using namespace std;

int m, n, ans;
int a[6][6];
bool rowUsed[6][6];

void dfs(int x, int y) {
	if (x == m) {
		++ans;
		return;
	}
	if (y == n) {
		dfs(x + 1, 0);
		return;
	}

	for (int v = 0; v < n; ++v) {
		if (rowUsed[x][v]) {
			continue;
		}
		bool ok = true;
		for (int i = 0; i < x; ++i) {
			if (a[i][y] == v) {
				ok = false;
				break;
			}
		}
		if (!ok) {
			continue;
		}

		a[x][y] = v;
		rowUsed[x][v] = true;
		dfs(x, y + 1);
		rowUsed[x][v] = false;
	}
}

int main() {
	cin >> m >> n;
	dfs(0, 0);
	cout << ans << endl;
	return 0;
}
