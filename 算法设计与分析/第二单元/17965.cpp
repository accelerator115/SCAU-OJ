#include <iostream>
using namespace std;

int lucky1(int n) {
  int p = 1;
  while (p * 2 <= n)
    p *= 2;
  return p ;
}

int lucky2(int n, int m) {
  int res = 1;
  for (int i = 2; i <= n; ++i) {
    res = (res + m - 1) % i + 1;
  }
  return res;
}

int main() {
  int n, m;
  cin >> n >> m;
  cout << lucky1(n) << " " << lucky2(n, m) << endl;
  return 0;
}