#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

ll n,k,a[12],b[12],c[12],ans=1e18;

ll toLL()
{
    ll res=0;
    for(int i=1;i<=n;i++)
        res=res*10+b[i];
    return res;
}

void dfs(int x)
{
    if(x==n+1)
    {
        ll res=toLL();
        if(res%k==0)
            ans=min(ans,res);
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(x==1&&a[i]==0)
            continue;
        if(c[i]==0)
        {
            c[i]=1;
            b[x]=a[i];
            dfs(x+1);
            c[i]=0;
        }
    }
}

int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n==1&&a[1]==0)
    {
        cout<<0;
        return 0;
    }
    sort(a+1,a+n+1);
    dfs(1);
    if(ans==1e18)
        cout<<-1;
    else
        cout<<ans;
    return 0;
}
