#include <iostream>
#include <algorithm>

using namespace std;
int a[15], res[15];
long long n, k;

long long toLL()
{
    long long ll = 0LL;
    for (int i = 1; i <= n; i++)
        ll = res[i] + ll * 10;
    return ll;
}

void solve()
{
    do
    {
        if (a[1] == 0)
            continue;
        for (int i = 1; i <= n; i++)
        {
            res[i] = a[i];
        }
        long long ll = toLL();
        if (ll % k == 0)
        {
            cout << ll;
            break;
        }
    } while (next_permutation(a + 1, a + n + 1));
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    if (n == 1 && a[1] == 0)
    {
        cout << 0;
        return 0;
    }
    solve();
    return 0;
}
