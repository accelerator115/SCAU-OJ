#include <iostream>
#include <string.h>
using namespace std;

int m, n;
int minRobots;

bool allCovered(int covered[20][20]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (covered[i][j] == 0) return false;
        }
    }
    return true;
}

void cover(int covered[20][20], int i, int j, int val) {
    covered[i][j] = val;
    if (i > 0) covered[i-1][j] = val;
    if (i < m-1) covered[i+1][j] = val;
    if (j > 0) covered[i][j-1] = val;
    if (j < n-1) covered[i][j+1] = val;
}

void solve(int covered[20][20], int robots) {
    if (robots >= minRobots) return;
    
    if (allCovered(covered)) {
        minRobots = robots;
        return;
    }

    int x = -1, y = -1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (covered[i][j] == 0) {
                x = i;
                y = j;
                break;
            }
        }
        if (x != -1) break;
    }
    
    int positions[5][2] = {
        {x, y},      
        {x-1, y},    
        {x+1, y},    
        {x, y-1},    
        {x, y+1}     
    };
    
    for (int k = 0; k < 5; k++) {
        int i = positions[k][0];
        int j = positions[k][1];
        
        if (i >= 0 && i < m && j >= 0 && j < n) {
            int backup[20][20];
            for (int ii = 0; ii < 20; ii++) {
                for (int jj = 0; jj < 20; jj++) {
                    backup[ii][jj] = covered[ii][jj];
                }
            }

            cover(covered, i, j, 1);

            solve(covered, robots + 1);

            for (int ii = 0; ii < 20; ii++) {
                for (int jj = 0; jj < 20; jj++) {
                    covered[ii][jj] = backup[ii][jj];
                }
            }
        }
    }
}

int main() {
    cin >> m >> n;
    int covered[20][20];
    memset(covered, 0, sizeof(covered));
    minRobots = m * n;
    solve(covered, 0);
    cout << minRobots << endl;
    return 0;
}
