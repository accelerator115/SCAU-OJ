#include <iostream>
#include <cstring>
using namespace std;

int n;
int grid[5][5];
int color[5][5];

bool isValid(int row, int col, int shape, int c) {
    for (int j = 0; j < col; j++) {
        if (grid[row][j] == shape) return false;
    }
    
    for (int i = 0; i < row; i++) {
        if (grid[i][col] == shape) return false;
    }

    for (int j = 0; j < col; j++) {
        if (color[row][j] == c) return false;
    }

    for (int i = 0; i < row; i++) {
        if (color[i][col] == c) return false;
    }
    
    return true;
}

bool checkShapeColorConstraint() {
    for (int shape = 0; shape < n; shape++) {
        bool colorUsed[5];
        memset(colorUsed, 0, sizeof(colorUsed));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == shape) {
                    if (colorUsed[color[i][j]]) {
                        return false;
                    }
                    colorUsed[color[i][j]] = true;
                }
            }
        }
    }
    return true;
}

long long solve(int pos) {
    if (pos == n * n) {
        if (checkShapeColorConstraint()) {
            return 1;
        }
        return 0;
    }
    
    int row = pos / n;
    int col = pos % n;
    long long count = 0;

    for (int shape = 0; shape < n; shape++) {
        for (int c = 0; c < n; c++) {
            if (isValid(row, col, shape, c)) {
                grid[row][col] = shape;
                color[row][col] = c;
                count += solve(pos + 1);
                grid[row][col] = -1;
                color[row][col] = -1;
            }
        }
    }
    
    return count;
}

int main() {
    cin >> n;
    memset(grid, -1, sizeof(grid));
    memset(color, -1, sizeof(color));
    cout << solve(0) << endl;
    return 0;
}
