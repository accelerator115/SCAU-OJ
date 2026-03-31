#include <iostream>

using namespace std;
int X[100000], Y[100000];
int m, n, k;
int findKth( int xBeg, int xEnd, int yBeg, int yEnd, int k) {
    if (xBeg > xEnd) {
        return Y[yBeg + k - 1];
    }

    if (yBeg > yEnd) {
        return X[xBeg + k - 1];
    }

    int xMid = xBeg + (xEnd - xBeg) / 2;
    int yMid = yBeg + (yEnd - yBeg) / 2;

    int halfLen = xMid - xBeg + yMid - yBeg + 2;
    
    if (X[xMid] < Y[yMid]) {
        if (k < halfLen) {
            return findKth(xBeg, xEnd,yBeg, yMid - 1, k);
        } else {
            return findKth(xMid + 1, xEnd, yBeg, yEnd, k - (xMid - xBeg + 1));
        }
    } else {
        if (k < halfLen) {
            return findKth(xBeg, xMid - 1, yBeg, yEnd, k);
        } else {
            return findKth(xBeg, xEnd, yMid + 1, yEnd, k - (yMid - yBeg + 1));
        }
    }
}

int main() {
    cin >> m >> n >> k;
    
    for (int i = 0; i < m; i++) {
        cin >> X[i];
    }
    
    for (int i = 0; i < n; i++) {
        cin >> Y[i];
    }
    
    int result = findKth(0, m - 1, 0, n - 1, k);
    cout << result << endl;
    
    return 0;
}
