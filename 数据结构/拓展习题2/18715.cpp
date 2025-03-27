#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> push_seq(n);
    for (int i = 0; i < n; ++i) {
        cin >> push_seq[i];
    }

    stack<int> s;
    vector<int> pop_seq;
    int current_max = n;
    int push_idx = 0;

    while (push_idx < n || !s.empty()) {
        // Try to pop elements from the stack that are equal to current_max
        while (!s.empty() && s.top() == current_max) {
            pop_seq.push_back(s.top());
            s.pop();
            current_max--;
        }

        // If there are elements left to push, push the next element
        if (push_idx < n) {
            s.push(push_seq[push_idx++]);
        }
        // If there are no elements left to push, pop the remaining elements from the stack in reverse order
        else {
            while (!s.empty()) {
                pop_seq.push_back(s.top());
                s.pop();
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << pop_seq[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}