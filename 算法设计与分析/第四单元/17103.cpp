#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
    cin >> n;

	vector<long long> h(n);
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
	}

	sort(h.begin(), h.end());

	int s = 0;
	int i = 0;
	while (i < n) {
		++s;
		long long c = h[i] + 4;
		long long r = c + 4;
		while (i < n && h[i] <= r) {
			++i;
		}
	}

	cout << s << endl;
	return 0;
}
