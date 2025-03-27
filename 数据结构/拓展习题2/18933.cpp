#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        string ans(s.length(), ' ');
        stack<int> left_brackets;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                left_brackets.push(i);
            } else if (s[i] == ')') {
                if (!left_brackets.empty()) {
                    left_brackets.pop();
                } else {
                    ans[i] = '?';
                }
            }
        }

        while (!left_brackets.empty()) {
            ans[left_brackets.top()] = '$';
            left_brackets.pop();
        }

        cout << s << endl;
        cout << ans << endl;
    }

    return 0;
}