#include <iostream>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  if (n == 1) {
    cout << k << endl;
    return 0;
  }

  if (n >= 3 && n % 2 == 1 && k < 3) {
    cout << 0 << endl;
    return 0;
  }
  
  if (n % 2 == 0 && k < 2) {
    cout << 0 << endl;
    return 0;
  }

  long long a1 = k;
  long long a2 = (long long)k * (k - 1);
  long long a3 = (long long)k * (k - 1) * (k - 2);

  if (n == 1) {
    cout << a1 << endl;
    return 0;
  }
  if (n == 2) {
    cout << a2 << endl;
    return 0;
  }
  if (n == 3) {
    cout << a3 << endl;
    return 0;
  }

  long long an;
  for (int i = 4; i <= n; i++) {
    an = (long long)(k - 2) * a3 + (long long)(k - 1) * a2;
    a2 = a3;
    a3 = an;
  }

  cout << an << endl;
  return 0;
}
