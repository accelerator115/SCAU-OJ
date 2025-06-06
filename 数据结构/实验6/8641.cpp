#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int flag = 1;
    for (int i = n - 1; i >= 1 && flag > 0; i--)
    {
        flag = 0;
        for (int j = 0; j < i; j++)
        {
            if (a[j] > a[j + 1])
            {
                flag = 1;
                swap(a[j], a[j + 1]);
            }
        }
        for (int j = 0; j < n; j++)
            cout << a[j] << " ";
        cout << endl;
    }
    return 0;
}
