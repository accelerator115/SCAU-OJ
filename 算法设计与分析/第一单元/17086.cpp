#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    sort(s.begin(), s.end());
    
    int cnt = 1;
    do {
        cout << cnt++ << " " << s << endl;
    } while (next_permutation(s.begin(), s.end()));
    
    return 0;
}
