#include <iostream>
#include <map>
using namespace std;

map<long long, long long> memo;

long long countImpossible(long long n)
{
    if (n <= 2)
        return n;
    if (n == 3)
        return 0;
    if (memo.count(n))
        return memo[n];
    long long result;
    if (n % 2 == 0)
        result = n - 2 * (n / 2 - countImpossible(n / 2));
    else
        result = n - ((n + 1) / 2 - countImpossible((n + 1) / 2)) - (n / 2 - countImpossible(n / 2));
    memo[n] = result;
    return result;
}

int main()
{
    long long n;
    while (cin >> n && n != 0)
    {
        cout << countImpossible(n) << endl;
    }
    return 0;
}
