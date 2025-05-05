#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr); 
    int n, m; // n表示龙的数量，m表示骑士的数量
    cin >> n >> m;
    while (n != 0 || m != 0) // 当n和m都为0时结束程序
    {
        // 创建两个动态数组，a存储龙的头直径，b存储骑士的高度
        vector<ll> a(n), b(m);
        
        // 输入每个龙头的直径
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        
        // 输入每个骑士的高度
        for (int i = 0; i < m; ++i)
        {
            cin >> b[i];
        }
        
        // 对龙头直径和骑士高度进行排序，方便贪心选择
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        ll totalCost = 0; // 记录雇佣骑士的总花费
        int i = 0, j = 0; // i指向当前需要处理的龙，j指向当前考虑的骑士
        
        // 贪心算法：尽量用高度刚好大于等于龙头直径的骑士来斩杀龙
        while (i < n && j < m)
        {
            if (a[i] <= b[j]) // 如果当前骑士能斩杀当前龙
            {
                totalCost += b[j]; // 添加雇佣该骑士的花费
                i++; // 处理下一个龙
                j++; // 考虑下一个骑士
            }
            else // 当前骑士无法斩杀当前龙
            {
                j++; // 考虑下一个更高的骑士
            }
        }
        
        // 判断是否所有龙都能被斩杀
        if (i < n) // 如果还有龙没有被处理，说明没有足够的骑士
        {
            cout << "Loowater is doomed!" << endl; // 输出世界末日信息
        }
        else // 所有龙都被处理
        {
            cout << totalCost << endl; // 输出最小总花费
        }
        
        // 读入下一组数据
        cin >> n >> m;
    }
    return 0;
}