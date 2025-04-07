#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int i,j,n,q[100005],f=0,r=0,s=0,M=100000,mod=1000000007;
    cin>>n;
    q[r++]=1;
    for(i=2;i<=n;i++)
    {
        q[r]=0;
        r=(r+1)%M;
        for(j=1;j<=i;j++)
        {
            q[r]=(s+q[f])%mod;
            r=(r+1)%M;
            s=q[f];
            f=(f+1)%M;
        }
    }
    while(f!=r)
    {
        cout<<q[f]<<' ';
        f=(f+1)%M;
    }
    return 0;
}
