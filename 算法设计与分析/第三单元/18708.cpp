#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int ans = -10001, sum = 0, x;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        sum = max(x, sum + x);
        ans = max(ans, sum);
    }
    printf("%d\n", ans);
    return 0;
}