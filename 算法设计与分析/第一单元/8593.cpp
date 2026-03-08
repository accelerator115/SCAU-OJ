#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int l = 0;
    int i = n - 1, j = n - 1;
    while (j > 0)
    {
        while (i >= 0 && a[i] <= abs(a[j]))
            i--;
        l = max(l, j - (i + 1) + 1);
        j--;
    }
    cout << l << endl;
    return 0;
}
