#include <iostream>
#include <algorithm>

using namespace std;

void dfs(int n, int max, int cnt, int parts[],int on)
{
    if (n == 0)
    {
        cout << on <<"=";
        for (int i = 0; i < cnt; i++)
        {
            if (parts[i] == 0)
            {
                continue;
            }
            else if (i == 0)
            {
                cout << parts[i];
            }
            else
            {
                cout << "+" << parts[i];
            }
        }
        cout << endl;
        return;
    }
    for (int i = min(max,n); i >=1; i--)
    {
        parts[cnt] = i;        
        cnt++;
        dfs(n-i, i, cnt+1, parts,on);
        cnt--;
    }
}

int main()
{
    int n;
    cin >> n;
    int parts[100]={0};
    dfs(n, n, 0, parts,n);
    return 0;
}