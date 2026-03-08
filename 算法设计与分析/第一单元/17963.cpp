#include <iostream>
using namespace std;

int main() {

    int p[] = {2, 3, 5, 7, 13, 17, 19, 31};
    
    for (int i = 0; i < 8; i++) {
        unsigned long long n = (1ULL << (p[i] - 1)) * ((1ULL << p[i]) - 1);
        cout << (i + 1) << " " << n << endl;
    }
    
    return 0;
}
