#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    priority_queue<int, vector<int>, greater<int>> minHeap;

    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (minHeap.size() < k) {
            minHeap.push(x);
        } else if (x > minHeap.top()) {
            minHeap.pop();
            minHeap.push(x);
        }
    }

    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top()); 
        minHeap.pop();
    }

    for (int i = result.size() - 1; i >= 0; i--) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
