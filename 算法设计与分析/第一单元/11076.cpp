#include <iostream>
#include <string>
using namespace std;

long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long pow10(int n)
{
    long long res = 1;
    for (int i = 0; i < n; i++)
    {
        res *= 10;
    }
    return res;
}

int main()
{
    string s;
    cin >> s;

    s = s.substr(2);

    long long z, m;

    int pos = s.find('(');

    if (pos == string::npos)
    {
        z = stoll(s);
        m = pow10(s.length());
    }
    else
    {
        string a = s.substr(0, pos);                        
        string b = s.substr(pos + 1, s.length() - pos - 2);

        int n = a.length();
        int mm = b.length();

        long long a_val = (a.empty() ? 0 : stoll(a));
        long long b_val = stoll(b);

        long long pow10m = pow10(mm);
        long long pow10n = pow10(n);

        z = a_val * (pow10m - 1) + b_val;
        m = (pow10m - 1) * pow10n;
    }

    long long g = gcd(z, m);
    z /= g;
    m /= g;

    cout << z << " " << m << endl;

    return 0;
}
