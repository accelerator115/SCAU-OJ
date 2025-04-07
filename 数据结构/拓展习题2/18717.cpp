#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    queue<int> male, female;
    
    for (int i = 1; i <= n; i++) {
        male.push(i);
    }
    for (int i = 1; i <= m; i++) {
        female.push(i);
    }
    
    int count = 0;
    
    while (count < k) {
        if (male.empty()) {
            for (int i = 1; i <= n; i++) {
                male.push(i);
            }
        }
        if (female.empty()) {
            for (int i = 1; i <= m; i++) {
                female.push(i);
            }
        }
        
        int man = male.front();
        male.pop();
        
        int woman = female.front();
        female.pop();
        
        count++;
        
        if (count == k) {
            cout << man << " " << woman << endl;
            break;
        }
    }
    
    return 0;
}