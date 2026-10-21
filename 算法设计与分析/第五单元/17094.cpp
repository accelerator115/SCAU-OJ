#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> g;  
vector<int> x;          
vector<int> a;          
vector<int> b;          
int c1;                 
int c2;                 

bool check1(int d) {
	for (int i = 0; i < d; ++i) {
		if (x[i] == 1) {
			for (int j = i + 1; j < d; ++j) {
				if (x[j] == 1) {
					for (int v : g[i]) {
						if (v == j) {
							return false;
						}
					}
				}
			}
		}
	}
	return true;
}

bool check2(int d) {
	for (int i = 0; i < d; ++i) {
		if (x[i] == 0) {
			bool ok = false;
			for (int v : g[i]) {
				if (v < d && x[v] == 1) {
					ok = true;
					break;
				}
			}
			if (!ok) {
				return false;
			}
		}
	}
	return true;
}

void dfs1(int d) {
	if (d == n) {
		if (check1(n)) {
			int cnt = 0;
			for (int i = 0; i < n; ++i) {
				cnt += x[i];
			}
			if (cnt > c1) {
				c1 = cnt;
				a = x;
			}
		}
		return;
	}

	x[d] = 1;
	dfs1(d + 1);
	
	x[d] = 0;
	dfs1(d + 1);
}

void dfs2(int d) {
	if (d == n) {
		if (check2(n)) {
			int cnt = 0;
			for (int i = 0; i < n; ++i) {
				cnt += x[i];
			}
			if (cnt < c2) {
				c2 = cnt;
				b = x;
			}
		}
		return;
	}

	int cnt = 0;
	for (int i = 0; i <= d; ++i) {
		cnt += x[i];
	}
	if (cnt >= c2) {
		return;
	}

	x[d] = 1;
	dfs2(d + 1);
	
	x[d] = 0;
	dfs2(d + 1);
}

int main() {
	cin >> n >> m;

	g.resize(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u--; v--; 
		g[u].push_back(v);
		g[v].push_back(u);
	}

	x.assign(n, 0);
	a.assign(n, 0);
	c1 = 0;
	dfs1(0);

	cout << c1 << endl;
	for (int i = 0; i < n; ++i) {
		if (i > 0) cout << ' ';
		cout << a[i];
	}
	cout << endl;

	x.assign(n, 0);
	b.assign(n, 0);
	c2 = n + 1;
	dfs2(0);

	cout << c2 << endl;
	for (int i = 0; i < n; ++i) {
		if (i > 0) cout << ' ';
		cout << b[i];
	}
	cout << endl;

	return 0;
}
