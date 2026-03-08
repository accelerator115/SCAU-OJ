#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    vector<long long> results;
    long long k = 1;

    while (true)
    {
        long long num = k * 3125 - 4;
        if (num <= n)
        {
            results.push_back(num);
            k++;
        }
        else
        {
            break;
        }
    }

    if (results.empty())
    {
        cout << "impossible" << endl;
    }
    else
    {
        for (int i = 0; i < results.size(); i++)
        {
            cout << results[i]<<" ";
        }
        cout << endl;
    }

    return 0;
}
