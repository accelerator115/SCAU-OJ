#include <iostream>
#define ll long long
using namespace std;

int main()
{
    ll k;  // 定义变量k，表示要分解的分数1/k
    cin>>k;  // 输入k的值
    
    // 枚举所有可能的a值，从1到k
    for(ll a=1LL; a<=k; a++)
    {
        // 检查k²是否能被a整除，这是方程有整数解的必要条件
        // 基于等式：1/k = 1/x + 1/y 推导出: xy = k(x+y)，即 xy-kx-ky = 0
        // 变形得到：(x-k)(y-k) = k²
        // 令 a = y-k, b = x-k，则 ab = k²
        if(k*k % a == 0)
        {
            ll b = k*k/a;  // 计算b = k²/a
            ll x = k+b;    // 计算x = k+b
            ll y = k+a;    // 计算y = k+a
            
            // 确保x和y都不为0（实际上这个条件在这里总是满足的，因为a≥1且k≥1）
            if(x != 0 && y != 0) 
                cout << "1/" << k << "=1/" << x << "+1/" << y << endl;  // 输出找到的分解式
        }
    }
    return 0;
}
