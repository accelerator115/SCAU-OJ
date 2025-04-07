#include <iostream>
#include <queue>
#include <string>
using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int MAX_N = 100; 
const int MAX_M = 100;

int main() {
    int n, m;
    cin >> n >> m;

    char maze[MAX_N][MAX_M];
    for (int i = 0; i < n; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < m; ++j) {
            maze[i][j] = row[j];
        }
    }
    
    if (maze[0][0] == '1' || maze[n-1][m-1] == '1') {
        cout << -1 << endl;
        return 0;
    }

    char steps[MAX_N][MAX_M];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            steps[i][j] = -1;
        }
    }
    steps[0][0] = 0;

    queue<int> q;
    q.push(0);
    
    while (!q.empty()) {
        int pos = q.front();
        q.pop();
        int x = pos / m;
        int y = pos % m;

        if (x == n-1 && y == m-1) {
            cout << (int)steps[x][y] << endl;
            return 0;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }

            if (maze[nx][ny] == '0' && steps[nx][ny] == -1) {
                steps[nx][ny] = steps[x][y] + 1;
                q.push(nx * m + ny);
            }
        }
    }

    cout << -1 << endl;
    
    return 0;
}