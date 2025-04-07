#include <iostream>

using namespace std;

int nums[10];
int n;
void dfs(int start, int sum) {
    if (sum > 0) {
        cout << sum << endl;
    }
    
    for (int i = start; i < n; i++) {
        dfs(i + 1, sum + nums[i]);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    dfs(0, 0);
    
    return 0;
}
