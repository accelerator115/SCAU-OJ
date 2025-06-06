#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[10000];

void print()
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++)
    {
        int p, now = 1e9;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < now)
            {
                p = j;
                now = a[j];
            }
        }
        if (a[i] > a[p])
            swap(a[i], a[p]);
        print();
    }
    return 0;
}
