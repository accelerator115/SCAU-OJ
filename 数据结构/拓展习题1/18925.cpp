
#include <cstdio>

const int MAXN = 100010;

int prev[MAXN], nxt[MAXN];

int main() {
    int n;
    scanf("%d", &n);

    prev[1] = 0;
    nxt[1] = 0;
    int head = 1;

    for (int i = 2; i <= n; ++i) {
        int x, p;
        scanf("%d %d", &x, &p);

        if (p == 0) {

            prev[i] = prev[x];
            nxt[i] = x;
            if (prev[x] != 0) {
                nxt[prev[x]] = i;
            }
            prev[x] = i;
            if (x == head) {
                head = i;
            }
        } else {

            nxt[i] = nxt[x];
            prev[i] = x;
            if (nxt[x] != 0) {
                prev[nxt[x]] = i;
            }
            nxt[x] = i;
        }
    }
    int current = head;
    while (current != 0) {
        printf("%d ", current);
        current = nxt[current];
    }

    return 0;
}
