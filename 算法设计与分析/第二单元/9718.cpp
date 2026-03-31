#include <iostream>
using namespace std;

int solve(int n)
{
    if (n == 1)
        return 1;
    int num = 0;
    for (int i = 2; i <= n; ++i)
    {
        if (n % i == 0)
            num += solve(n / i);
    }
    return num;
}

int main()
{
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
