#include <iostream>
#include <cmath>
using namespace std;

void fillBoxFractal(char** grid, int n, int row, int col) {
    if (n == 1) {
        grid[row][col] = 'X';
        return;
    }
    
    int size = pow(3, n - 2);
    
    fillBoxFractal(grid, n - 1, row, col);     
    fillBoxFractal(grid, n - 1, row, col + 2 * size); 
    fillBoxFractal(grid, n - 1, row + size, col + size); 
    fillBoxFractal(grid, n - 1, row + 2 * size, col);
    fillBoxFractal(grid, n - 1, row + 2 * size, col + 2 * size);
}

int main() {
    int n;
    cin >> n;
    
    if (n < 1 || n > 6) {
        cout << "输入应在1到6之间" << endl;
        return 0;
    }
    
    int size = pow(3, n - 1);
    
    char** grid = new char*[size];
    for (int i = 0; i < size; i++) {
        grid[i] = new char[size];
        for (int j = 0; j < size; j++) {
            grid[i][j] = ' ';
        }
    }
    
    fillBoxFractal(grid, n, 0, 0);
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
    
    for (int i = 0; i < size; i++) {
        delete[] grid[i];
    }
    delete[] grid;
    
    return 0;
}