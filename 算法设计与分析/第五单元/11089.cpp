#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> t;
vector<int> ord;
vector<int> gLoad;
vector<int> dLoad;
vector<int> pick;
int gBest;
int best;

int greedy() {
	gLoad.assign(m, 0);
	vector<int> jobs = t;
	sort(jobs.begin(), jobs.end(), greater<int>());

	for (int job : jobs) {
		int pos = 0;
		for (int i = 1; i < m; ++i) {
			if (gLoad[i] < gLoad[pos]) {
				pos = i;
			}
		}
		gLoad[pos] += job;
	}

	int finish = 0;
	for (int load : gLoad) {
		finish = max(finish, load);
	}
	return finish;
}

void backtrack(int dep) {
	if (dep == n) {
		int finish = 0;
		for (int load : dLoad) {
			finish = max(finish, load);
		}
		best = min(best, finish);
		return;
	}

	int job = t[ord[dep]];
	for (int i = 0; i < m; ++i) {
		if (i > 0 && dLoad[i] == dLoad[i - 1]) {
			continue;
		}

		dLoad[i] += job;
		pick[dep] = i + 1;

		int currentMax = 0;
		for (int load : dLoad) {
			currentMax = max(currentMax, load);
		}

		if (currentMax < best) {
			backtrack(dep + 1);
		}

		dLoad[i] -= job;
	}
}

int main() {
    cin >> n >> m;

	t.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> t[i];
	}

	if (n == 0 || m == 0) {
		cout << 0 << '\n' << 0 << '\n';
		return 0;
	}

	gBest = greedy();

	ord.resize(n);
	for (int i = 0; i < n; ++i) {
		ord[i] = i;
	}
	sort(ord.begin(), ord.end(), [](int a, int b) {
		if (t[a] != t[b]) return t[a] > t[b];
		return a < b;
	});

	dLoad.assign(m, 0);
	pick.assign(n, 0);
	best = 1 << 30;

    backtrack(0);

	cout << gBest << '\n' << best << '\n';
	return 0;
}
