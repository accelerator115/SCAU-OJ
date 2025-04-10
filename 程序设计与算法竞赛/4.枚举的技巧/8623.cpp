#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

void solve()
{
    ll n;
    scanf("%lld", &n);
    if(n<0)
    {
        printf("0\n");
        return;
    }
    ll res=0;
    ll i=1;
    ll m=0;
    ll lst=0;
    while(1)
    {
        ll tmp=n/i;
        res+=tmp;
        if(tmp==lst)
        {
            res-=tmp*2;
            m=tmp;
            break;
        }
        i++;
        lst=tmp;
    }
    for(i=1; i<=m; i++)
    {
        res+=(n/i-n/(i+1))*i;
    }
    printf("%lld\n", res);
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        solve();
    }
    return 0;
}