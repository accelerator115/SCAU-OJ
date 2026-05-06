#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	priority_queue<int> max_heap;
	for (int i = 0; i < n; ++i) {
		max_heap.push(a[i]);
	}
	int max = 0;
	while (max_heap.size() > 1) {
		int a = max_heap.top(); max_heap.pop();
		int b = max_heap.top(); max_heap.pop();
		int merge = a + b;
		max += merge;
		max_heap.push(merge);
	}
	
	int cnt = n;
	while (cnt % (k - 1) != 1) {
		cnt++;
		a.push_back(0);
	}
	
	priority_queue<int, vector<int>, greater<int>> min_heap;
	for (int i = 0; i < a.size(); ++i) {
		min_heap.push(a[i]);
	}
	int min = 0;
	while (min_heap.size() > 1) {
		int merge = 0;
		for (int i = 0; i < k; ++i) {
			merge += min_heap.top();
			min_heap.pop();
		}
		min += merge;
		min_heap.push(merge);
	}
	
	cout << min << " " << max << endl;
	return 0;
}
