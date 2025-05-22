#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 105;
vector<pair<int, int>> adj[MAXN];
int dp[MAXN];
int n, m;

int dfs(int u) {
    if (dp[u] != -1) return dp[u];
    dp[u] = 0;
    
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i].first;
        int w = adj[u][i].second;
        dp[u] = max(dp[u], dfs(v) + w);
    }
    return dp[u];
}

int main() {
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int a, b, x;
        cin >> a >> b >> x;
        adj[a].push_back({b, x});
    }
    
    memset(dp, -1, sizeof(dp));
    
    cout << dfs(1) << endl;
    
    return 0;
}
