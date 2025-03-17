#include <iostream>
#include <algorithm>

using namespace std;

void solve(int n, char a, char b, char c) {
    if (n == 1) {
        cout << a << "->" << n << "->" << b << endl;
        return;
    }
    solve(n - 1, a, c, b);
    cout << a << "->" << n << "->" << b << endl;
    solve(n - 1, c, b, a);
}

int main() {
    int n;
    char a , b, c;
    cin >> n >> a >> b >> c;
    solve(n, a, b, c);
    return 0;
}