#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main() {
    int x1, x2, x3;
    cin >> x1 >> x2 >> x3;
    
    vector<int> candidates;
    
    if (x2 - x1 == x3 - x2) {
        int d = x2 - x1;
        int missing = x1 - d;
        candidates.push_back(missing);
    }

    if (x2 - x1 == 2 * (x3 - x2)) {
        int d = x3 - x2;
        int missing = x1 + d;
        candidates.push_back(missing);
    }
    
    if (x3 - x2 == 2 * (x2 - x1)) {
        int d = x2 - x1;
        int missing = x2 + d;
        candidates.push_back(missing);
    }
    
    if (x2 - x1 == x3 - x2) {
        int d = x2 - x1;
        int missing = x3 + d;
        candidates.push_back(missing);
    }

    cout << *min_element(candidates.begin(), candidates.end()) << endl;

    return 0;
}