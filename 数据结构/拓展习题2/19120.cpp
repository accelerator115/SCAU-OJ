#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    int n, m, x;
    cin >> n >> m >> x;
    
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<vector<bool>> infected(n, vector<bool>(m, false));
    queue<pair<pair<int, int>, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '@') {
                q.push({{i, j}, 0});
                infected[i][j] = true;
            }
        }
    }

    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        
        int row = current.first.first;
        int col = current.first.second;
        int time = current.second;

        if (time >= x) {
            continue;
        }

        for (int i = 0; i < 8; i++) {
            int newRow = row + dx[i];
            int newCol = col + dy[i];

            if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= m) {
                continue;
            }

            if (grid[newRow][newCol] == '*' && !infected[newRow][newCol]) {
                infected[newRow][newCol] = true;
                q.push({{newRow, newCol}, time + 1});
            }
        }
    }

    int totalInfected = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (infected[i][j]) {
                totalInfected++;
            }
        }
    }
    
    cout << totalInfected << endl;
    
    return 0;
}
