#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n,res;
int mp[15]={0};

void dfs(int x)
{
    if(x==n)
    {
        res++;
        return ;
    }
    for(int i=0;i<n;i++)
    {
        mp[x]=i;
        int j=0;
        for(j=0;j<x;j++)
        {
            if(mp[x]==mp[j])
                break;
            if(mp[x]-x==mp[j]-j||mp[x]+x==mp[j]+j)
                break;
        }
        if(j==x)
            dfs(x+1);
    }
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        memset(mp,0,sizeof(mp));
        res=0;
        dfs(0);
        cout<<res<<endl;
    }
    return 0;
}