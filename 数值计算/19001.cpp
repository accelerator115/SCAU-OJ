#include <math.h>
#include <stdio.h>

#define MN 51

double GOLDEN = 0.6180339887498948L;
double EPS = 0.4E-8;
double A[MN], B[MN], AX[MN], BX[MN];
double X1[MN], X2[MN], Y1[MN], Y2[MN];

double f(double x) { return exp(x) - 2 * x * x; }

int main() {
  int m;
  if (scanf("%d", &m) != 1)
    return 0;
  while (m--) {
    double a, b;
    scanf("%lf%lf", &a, &b);
    A[0] = a;
    B[0] = b;
    BX[0] = (B[0] - A[0]) * GOLDEN;
    AX[0] = BX[0] * GOLDEN;
    X2[0] = A[0] + BX[0];
    Y2[0] = f(X2[0]);
    X1[0] = A[0] + AX[0];
    Y1[0] = f(X1[0]);

    int last = 0;
    for (int k = 1; k < MN; ++k) {
      BX[k] = AX[k - 1];
      AX[k] = BX[k] * GOLDEN;
      if (Y1[k - 1] < Y2[k - 1]) {
        A[k] = A[k - 1];
        B[k] = X2[k - 1];
        X2[k] = X1[k - 1];
        Y2[k] = Y1[k - 1];
        X1[k] = A[k] + AX[k];
        Y1[k] = f(X1[k]);
      } else {
        A[k] = X1[k - 1];
        B[k] = B[k - 1];
        X1[k] = X2[k - 1];
        Y1[k] = Y2[k - 1];
        X2[k] = A[k] + BX[k];
        Y2[k] = f(X2[k]);
      }
      last = k;
      if (AX[k] < EPS)
        break;
    }

    printf("%.9f %.9f %.9f %.9f %.9f %.9f\n", A[last], X1[last], X2[last],
           B[last], Y1[last], Y2[last]);
  }
  return 0;
}
