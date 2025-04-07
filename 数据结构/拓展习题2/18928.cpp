#include <iostream>
#include <vector>

using namespace std;

vector<int> p;
bool used[100];

void dfs(int n) {
    if (p.size() == n) {
        for (int i = 0; i < n; i++) {
            cout << p[i];
            if (i < n - 1) cout << " ";
        }
        cout << endl;
        return;
    }
    
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            used[i] = true;
            p.push_back(i);
            dfs(n);
            p.pop_back();  
            used[i] = false;
        }
    }
}

int main() {
    int n;
    cin >> n;
    dfs(n);
    return 0;
}