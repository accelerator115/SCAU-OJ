#include <iostream>
#include <algorithm>

using namespace std;
int n,child[105][3],ans=0;
int dfs(int root)
{
    if(!root)
        return 0;
    int lchild=dfs(child[root][1]),rchild=dfs(child[root][2]);
    int len=max(lchild,rchild)+1;
    ans=max(ans,lchild+rchild);
    return len;
}
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
    dfs(1);
    cout<<ans;
    return 0;
}