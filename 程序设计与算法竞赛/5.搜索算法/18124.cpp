#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n,res;  // n表示棋盘大小（n*n），res用于记录解的数量
int mp[15]={0};  // mp[i]=j 表示第i行的皇后放在第j列

/**
 * 深度优先搜索函数
 * @param x 当前处理的行号
 */
void dfs(int x)
{
    // 如果已经处理完所有行，找到一个合法解
    if(x==n)
    {
        res++;  // 解的数量加1
        return ;
    }
    // 尝试在当前行的每一列放置皇后
    for(int i=0;i<n;i++)
    {
        mp[x]=i;  // 在第x行第i列放置皇后
        int j=0;
        // 检查当前放置的皇后是否与前面已放置的皇后冲突
        for(j=0;j<x;j++)
        {
            if(mp[x]==mp[j])  // 检查是否在同一列
                break;
            if(mp[x]-x==mp[j]-j||mp[x]+x==mp[j]+j)  // 检查是否在同一对角线
                break;
        }
        // 如果没有冲突，继续处理下一行
        if(j==x)
            dfs(x+1);
    }
}

int main()
{
    int T;  // 测试用例数量
    cin>>T;
    while(T--)
    {
        cin>>n;  // 输入棋盘大小
        memset(mp,0,sizeof(mp));  // 初始化棋盘
        res=0;  // 重置解的数量
        dfs(0);  // 从第0行开始搜索
        cout<<res<<endl;  // 输出解的数量
    }
    return 0;
}