#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int n;
    cin >> n;
    double sum = 0, x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        sum += x;
        printf("%.2f ", sum / (i + 1));
    }
    cout << endl;
    return 0;
}