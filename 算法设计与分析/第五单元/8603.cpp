#include <iostream>
#include <vector>

using namespace std;

static bool found = false;
static vector<long long> solution;

void dfs(int index, long long sum, const vector<long long> &v, long long t, vector<long long> &cur) {
	if (found) {
		return;
	}
	if (index == static_cast<int>(v.size())) {
		if (sum == t) {
			found = true;
			solution = cur;
		}
		return;
	}

	cur.push_back(v[index]);
	dfs(index + 1, sum + v[index], v, t, cur);
	if (found) {
		return;
	}
	cur.pop_back();

	dfs(index + 1, sum, v, t, cur);
}

int main() {
	int n = 0;
	long long t = 0;
    cin >> n >> t;

	vector<long long> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	vector<long long> cur;
	dfs(0, 0, v, t, cur);

	if (!found) {
		cout << "No Solution";
		return 0;
	}

	for (size_t i = 0; i < solution.size(); ++i) {
		if (i > 0) {
			cout << ' ';
		}
		cout << solution[i];
	}
	return 0;
}
