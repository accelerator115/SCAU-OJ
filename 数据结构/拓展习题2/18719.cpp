#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 30;
int grid[MAXN][MAXN];
bool visited[MAXN][MAXN];
int n;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs() {
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        if (grid[0][i] == 0 && !visited[0][i]) {
            q.push(make_pair(0, i));
            visited[0][i] = true;
        }
        if (grid[n-1][i] == 0 && !visited[n-1][i]) {
            q.push(make_pair(n-1, i));
            visited[n-1][i] = true;
        }
    }
    
    for (int i = 1; i < n-1; i++) {
        if (grid[i][0] == 0 && !visited[i][0]) {
            q.push(make_pair(i, 0));
            visited[i][0] = true;
        }
        if (grid[i][n-1] == 0 && !visited[i][n-1]) {
            q.push(make_pair(i, n-1));
            visited[i][n-1] = true;
        }
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            visited[i][j] = false;
        }
    }

    bfs();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0 && !visited[i][j]) {
                grid[i][j] = 2;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j];
            if (j < n-1) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}