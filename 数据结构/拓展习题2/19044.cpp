#include <iostream>
using namespace std;
int t,n,a[20],Asum,Bsum,sum,ans;
void dfs(int cur)
{
    if(cur==n+1)
    {
        if(Asum==Bsum)
          ans=min(ans,sum-Asum-Bsum);
        return;
    }
    Asum+=a[cur];
    dfs(cur+1);
    Asum-=a[cur];
    Bsum+=a[cur];
    dfs(cur+1);
    Bsum-=a[cur];
    dfs(cur+1);
}
int main()
{
    int i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        Asum=0,Bsum=0,sum=0;
        for(i=1;i<=n;i++)
           cin>>a[i],sum+=a[i];
        ans=sum;
        dfs(1);
        cout<<ans<<endl;
    }
    return 0;
}