#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> c;
vector<int> p;
vector<int> res;
int minC;
int curC;

void backtrack(int d) {
	if (d == n) {
		if (curC < minC) {
			minC = curC;
			res = p;
		}
		return;
	}

	for (int i = 0; i < n; ++i) {
		if (find(p.begin(), p.begin() + d, i) == p.begin() + d) {
			p[d] = i;
			int cost = c[d][i];
			curC += cost;

			if (curC < minC) {
				backtrack(d + 1);
			}

			curC -= cost;
		}
	}
}

int main() {
	cin >> n;

	c.resize(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> c[i][j];
		}
	}

	p.resize(n);
	res.resize(n);
	minC = 1 << 30;
	curC = 0;

	backtrack(0);

	cout << minC << endl;
	for (int i = 0; i < n; ++i) {
		if (i > 0) cout << ' ';
		cout << res[i] + 1;
	}
	cout << endl;

	return 0;
}
