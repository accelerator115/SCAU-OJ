#include <iostream>
#include <set>

using namespace std;
int main() {
    set<int> s;
    int n,c;
    cin >> n;
    while (n--) {
        cin >> c;
        s.insert(c);
    }
    cout << s.size() << endl;
    return 0;
}
