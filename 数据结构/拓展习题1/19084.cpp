#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

string correctString(const string& s) {
    stack<char> st;
    for (char ch : s) {
        if (st.size() >= 2 && st.top() == ch) {
            char top1 = st.top();
            st.pop();
            char top2 = st.top();
            st.pop();
            if (top1 == top2 && top2 == ch) {
                st.push(top2);
                st.push(top1);
                continue;
            } else {
                st.push(top2);
                st.push(top1);
            }
        }
        if (st.size() >= 3) {
            char top1 = st.top();
            st.pop();
            char top2 = st.top();
            st.pop();
            char top3 = st.top();
            st.pop();
            if (top2 == top3 && top1 == ch) {
                st.push(top3);
                st.push(top2);
                st.push(top1);
                continue;
            } else {
                st.push(top3);
                st.push(top2);
                st.push(top1);
            }
        }
        st.push(ch);
    }
    string result;
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    int N;
    cin >> N;
    while (N--) {
        string s;
        cin >> s;
        cout << correctString(s) << endl;
    }
    return 0;
}