
#include <iostream>
#include <vector>
using namespace std;
struct node /**< 边的邻接点和权值，也可用pair */
{
    int adj,quan;
};
vector<node> e[2005];
int n,m,v[2005],d[2005];
int getMin()
{
    int i,minv=0;
    for(i=1;i<=n;i++)
        if(v[i]==0&&d[i]<d[minv])
          minv=i;
    return minv;
}
int prim()
{
    int i,j,ans=0;
    for(i=0;i<=n;i++)
        d[i]=1e9;
    d[1]=0;
    for(i=1;i<=n;i++)
    {
        int x=getMin();
        v[x]=1; ans+=d[x];
        for(j=0;j<e[x].size();j++)
        {
            int y=e[x][j].adj,z=e[x][j].quan;
            d[y]=min(d[y],z);
        }
    }
    return ans;
}
int main()
{
    int i,x,y,z;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>x>>y>>z;
        if(x==y) continue;
        e[x].push_back({y,z});
        e[y].push_back({x,z});
    }
    cout<<prim();
    return 0;
}

//克鲁斯卡尔
//#include <iostream>
//#include <algorithm>
//using namespace std;
//int n,m,f[2005];/**< f数组用于并查集 */
//struct node
//{
//    int s,e,v;/**< s和e为两个邻接点，v为边权值 */
//    bool operator <(const node y)const
//    {
//        return v<y.v;
//    }
//} e[20000];
//int findx(int x)/**< 并查集的查操作 */
//{
//    return f[x]==x?x:f[x]=findx(f[x]);
//}
//int main()
//{
//    int i,j,sum=0;
//    cin>>n>>m;
//    for(i=1; i<=n; i++) /**< 并查集初始化 */
//        f[i]=i;
//    for(i=1; i<=m; i++)
//        cin>>e[i].s>>e[i].e>>e[i].v;
//    sort(e+1,e+m+1);
//    for(i=1; i<=m; i++)
//    {
//        int r1=findx(e[i].s),r2=findx(e[i].e);
//        if(r1!=r2)/**< 第i条边不会形成环，选中 */
//        {
//            sum+=e[i].v;
//            f[r1]=r2;/**< 并查集的并操作，将r1集合并入r2集合 */
//        }
//    }
//    cout<<sum;
//    return 0;
//}
