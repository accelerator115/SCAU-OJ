#include <iostream>
#include <map>
using namespace std;

map<long long, bool> memo;

bool canBeChosen(int n, int pos)
{
    if (n <= 3)
    {
        return n == 3;
    }
    long long key = (long long)n * 100001 + pos;
    if (memo.find(key) != memo.end())
    {
        return memo[key];
    }

    bool result = false;
    if (pos % 2 == 0)
    {
        int newN = n / 2;
        int newPos = pos / 2;
        if (canBeChosen(newN, newPos))
        {
            result = true;
        }
    }
    if (!result && pos % 2 == 1)
    {
        int newN = n / 2;
        if (n % 2 == 1)
        {
            newN++;
        }
        int newPos = (pos + 1) / 2;
        if (canBeChosen(newN, newPos))
        {
            result = true;
        }
    }
    memo[key] = result;

    return result;
}

int main()
{
    int n, pos;
    while (cin >> n >> pos && (n != 0 || pos != 0))
    {
        if (canBeChosen(n, pos))
        {
            cout << "Y" << endl;
        }
        else
        {
            cout << "N" << endl;
        }
    }

    return 0;
}