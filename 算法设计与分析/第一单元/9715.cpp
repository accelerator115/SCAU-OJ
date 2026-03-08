#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0),cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    stack<int> st;
    int m = 0;
    for (int i = 0; i <= n; ++i) {
        int cur = (i < n) ? a[i] : 0; 
        while (!st.empty() && cur < a[st.top()]) {
            int h = a[st.top()];
            st.pop();
            int w = st.empty() ? i : i - st.top() - 1;
            m = max(m, h * w);
        }
        st.push(i);
    }
    cout << m << endl;
    return 0;
}