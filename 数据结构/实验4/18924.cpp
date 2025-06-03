#include <iostream>
#include <queue>

using namespace std;
int n,child[105][3],ans=1;
int main()
{
    int i,j,x,y;
    cin>>n;
    for(i=1; i<n; i++)
    {
        cin>>x>>y;
        if(!child[x][1])
            child[x][1]=y;
        else
            child[x][2]=y;
    }
    queue<int>q;
    q.push(1);
    while(q.size())
    {
        int len=q.size();
        ans=max(ans,len);
        for(i=0;i<len;i++)
        {
            int t=q.front();
            q.pop();
            if(child[t][1])
                q.push(child[t][1]);
            if(child[t][2])
                q.push(child[t][2]);
        }
    }
    cout<<ans;
    return 0;
}