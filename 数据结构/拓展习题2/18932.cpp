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

    vector<int> pop_seq(n);
    for (int i = 0; i < n; ++i) {
        cin >> pop_seq[i];
    }

    stack<int> s;
    int push_idx = 0;
    int pop_idx = 0;

    while (pop_idx < n) {
        if (!s.empty() && s.top() == pop_seq[pop_idx]) {
            s.pop();
            pop_idx++;
        } else if (push_idx < n) {
            s.push(push_seq[push_idx]);
            push_idx++;
        } else {
            cout << "no" << endl;
            return 0;
        }
    }

    cout << "yes" << endl;
    return 0;
}