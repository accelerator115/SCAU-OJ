#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

ll n,k,a[12],b[12],c[12],ans=1e18;  // n:数字个数, k:整除的数, a:输入的数字, b:当前排列, c:标记数组, ans:最小答案

/**
 * 将当前排列转换为长整型数字
 * @return 转换后的长整型数字
 */
ll toLL()
{
    ll res=0;
    for(int i=1;i<=n;i++)
        res=res*10+b[i];  // 将每一位数字依次加入结果中
    return res;
}

/**
 * 深度优先搜索函数，生成所有可能的排列
 * @param x 当前处理的位置
 */
void dfs(int x)
{
    // 如果已经处理完所有位置，找到一个完整排列
    if(x==n+1)
    {
        ll res=toLL();  // 将排列转换为数字
        if(res%k==0)    // 检查是否能被k整除
            ans=min(ans,res);  // 更新最小答案
        return ;
    }
    // 尝试在当前位置放置每一个可用的数字
    for(int i=1;i<=n;i++)
    {
        if(x==1&&a[i]==0)  // 如果是第一位且数字为0，跳过（避免前导0）
            continue;
        if(c[i]==0)  // 如果该数字尚未使用
        {
            c[i]=1;      // 标记该数字已使用
            b[x]=a[i];   // 在当前位置放置该数字
            dfs(x+1);    // 递归处理下一个位置
            c[i]=0;      // 回溯，取消标记
        }
    }
}

int main()
{
    cin>>n>>k;  // 输入数字个数n和整除数k
    for(int i=1;i<=n;i++)
        cin>>a[i];  // 输入n个数字
    
    // 特殊情况处理：只有一个数字且为0
    if(n==1&&a[1]==0)
    {
        cout<<0;  // 直接输出0
        return 0;
    }
    
    sort(a+1,a+n+1);  // 对输入的数字进行排序（为了保证找到最小的解）
    dfs(1);  // 从第1个位置开始搜索
    
    // 输出结果
    if(ans==1e18)  // 如果没有找到解
        cout<<-1;
    else
        cout<<ans;
    return 0;
}
