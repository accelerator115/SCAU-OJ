#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

// 存储前100000个丑数的数组
ll ugly[100000];

void init()
{
    // l2、l3、l5是三个"指针"，分别指向下一个要乘以2、3、5的丑数的位置
    int l2=1,l3=1,l5=1;
    
    // 1是第一个丑数
    ugly[1]=1;
    
    // 生成剩余的丑数
    for(ll i=2;i<100000;i++)
    {
        // 取三种可能的下一个丑数中的最小值
        ugly[i]=min(ugly[l2]*2,min(ugly[l3]*3,ugly[l5]*5));
        
        // 如果当前丑数等于某个指针指向的丑数乘以对应的因子，则该指针前进
        // 注意：这里不用else if是因为可能有重复值，如ugly[2]*2 == ugly[3]*3 == 6
        if(ugly[i]==ugly[l2]*2) l2++;
        if(ugly[i]==ugly[l3]*3) l3++;
        if(ugly[i]==ugly[l5]*5) l5++;
    }
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    // 预先计算所有需要的丑数
    init();
    
    // T表示测试用例数量
    int T;
    cin>>T;
    
    // 处理每个测试用例
    while(T--)
    {
        // 输入n，表示要找第n个丑数
        int n;
        cin>>n;
        
        // 输出第n个丑数
        cout<<ugly[n]<<endl;
    }
    return 0;
}