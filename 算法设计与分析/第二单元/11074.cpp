#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long Ln = (long long)n * (n + 1) / 2 + 1;
    long long Cn = (long long)n * n - n + 2;
    long long Zn = 2LL * n * n - n + 1;
    long long ZZn = (9LL * n * n - 7LL * n + 2) / 2;

    cout << Ln << " " << Cn << " " << Zn << " " << ZZn << endl;

    return 0;
}
