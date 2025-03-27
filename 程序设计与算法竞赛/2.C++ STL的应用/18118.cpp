#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    while (n != 0 || m != 0)
    {
        vector<ll> a(n), b(m);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        for (int i = 0; i < m; ++i)
        {
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        ll totalCost = 0;
        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (a[i] <= b[j])
            {
                totalCost += b[j];
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        if (i < n)
        {
            cout << "Loowater is doomed!" << endl;
        }
        else
        {
            cout << totalCost << endl;
        }
        cin >> n >> m;
    }
    return 0;
}