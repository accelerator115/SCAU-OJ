#include <iostream>
#include <vector>
#include <algorithm>

#define INT_MIN -2147483648
using namespace std;

struct Station {
    int position;
    int cost;
    
    bool operator < (const Station& other) const {
        return position < other.position;
    }
};

bool canReachDestination(int N, int L, int M, int S, vector<Station>& stations) {
    sort(stations.begin(), stations.end());
    
    if (L <= M) {
        return true;
    }
    
    vector<int> dp(N, INT_MIN);
    
    for (int i = 0; i < N; i++) {
        if (stations[i].position <= M) { 
            if (S >= stations[i].cost) { 
                dp[i] = S - stations[i].cost;
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        if (dp[i] < 0) continue;
        
        for (int j = i + 1; j < N; j++) {
            if (stations[j].position - stations[i].position <= M) {
                if (dp[i] >= stations[j].cost) {
                    dp[j] = max(dp[j], dp[i] - stations[j].cost);
                }
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        if (dp[i] >= 0 && L - stations[i].position <= M) {
            return true;
        }
    }
    
    return false;
}

int main() {
    int N, L, M, S;
    cin >> N >> L >> M >> S;
    
    vector<Station> stations(N);
    for (int i = 0; i < N; i++) {
        cin >> stations[i].position >> stations[i].cost;
    }
    
    if (canReachDestination(N, L, M, S, stations)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}