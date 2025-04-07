#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<string>& maze, int row, int col, vector<vector<bool>>& visited) {
    int n = maze.size();
    int m = maze[0].size();

    if (row < 0 || row >= n || col < 0 || col >= m || maze[row][col] == '1' || visited[row][col]) {
        return false;
    }

    if (row == n - 1 && col == m - 1) {
        return true;
    }

    visited[row][col] = true;

    if (dfs(maze, row + 1, col, visited) ||
        dfs(maze, row - 1, col, visited) ||
        dfs(maze, row, col + 1, visited) ||
        dfs(maze, row, col - 1, visited)) {
        return true;
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> maze(n);
    for (int i = 0; i < n; ++i) {
        cin >> maze[i];
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    if (dfs(maze, 0, 0, visited)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}
