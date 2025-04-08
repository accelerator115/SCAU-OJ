#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define INT_MAX 2147483647
using namespace std;

void dfs(vector<int>& songs, int index, int currentSum, set<int>& sums, bool hasSelected) {
    if (index == songs.size()) {
        if (hasSelected) sums.insert(currentSum);
        return;
    }
    dfs(songs, index + 1, currentSum, sums, hasSelected);
    dfs(songs, index + 1, currentSum + songs[index], sums, true);
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> roommates(4, vector<int>(n));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++) {
            cin >> roommates[i][j];
        }
    }

    vector<set<int>> possibleSums(4);
    for (int i = 0; i < 4; i++) {
        dfs(roommates[i], 0, 0, possibleSums[i], false);
    }
    
    int minDifference = INT_MAX;

    for (int p = 0; p < 4; p++) {
        for (auto minSum : possibleSums[p]) {
            int maxSum = minSum;
            bool valid = true;
            
            for (int j = 0; j < 4; j++) {
                if (j == p) continue;

                auto it = possibleSums[j].lower_bound(minSum);
                if (it == possibleSums[j].end()) {
                    valid = false;
                    break;
                }
                
                maxSum = max(maxSum, *it);
            }
            
            if (valid) {
                minDifference = min(minDifference, maxSum - minSum);
            }
        }
    }
    
    cout << minDifference << endl;
    
    return 0;
}
