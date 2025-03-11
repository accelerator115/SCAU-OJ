#include <iostream>
#include <set>

using namespace std;
int main() {
    set<char> s;
    char c;
    int n;
    cin >> n;
    while (n--) {
        cin >> c;
        s.insert(c);
    }
    for (auto it = s.begin(); it!= s.end(); it++) {
        cout << *it;
    }
    cout << endl;
    return 0;
}
