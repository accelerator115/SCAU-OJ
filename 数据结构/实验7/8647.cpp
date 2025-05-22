#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int M[100][100] = {0};

    for (int k = 0; k < m; ++k)
    {
        int i, j;
        cin >> i >> j;
        M[i - 1][j - 1] = 1;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << M[i][j];
            cout << " ";
        }
        cout << endl;
    }

    return 0;
}