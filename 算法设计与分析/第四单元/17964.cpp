#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int n, r;
    cin >> n >> r;

	vector<long long> t(n);
	for (int i = 0; i < n; ++i) {
		cin >> t[i];
	}

	sort(t.begin(), t.end());

	priority_queue<long long, vector<long long>, greater<long long>> taps;
	for (int i = 0; i < r; ++i) {
		taps.push(0);
	}

	long long total = 0;
	for (int i = 0; i < n; ++i) {
		long long a = taps.top();
		taps.pop();

		long long b = a + t[i];
		total += b;
		taps.push(b);
	}

	cout << total << endl;
	return 0;
}
