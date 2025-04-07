#include <iostream>
#include <map>
using namespace std;

// 使用哈希表来记忆化搜索，避免重复计算
map<unsigned int, unsigned int> memo;

unsigned int pocess(unsigned int n)
{
    if(n<3) return 0;
    else if(n==3) return 1;
    
    // 检查是否已经计算过该值
    if(memo.find(n) != memo.end())
        return memo[n];
    
    unsigned int result;
    if(n%2==0) 
        result = 2*pocess(n/2);
    else 
        result = pocess(n/2+1)+pocess(n/2);
    
    // 保存计算结果
    memo[n] = result;
    return result;
}

int main()
{
    unsigned int n;
    while(cin >> n && n != 0)
    {
        cout << pocess(n) << endl;
    }
    return 0;
}