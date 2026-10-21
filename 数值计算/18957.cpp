// 18957 计算自然对数ln(x)的导数
// Description
// 求自然对数ln(x)的导数，输入双精度实数x>=1，输出自然对数ln(x)的导数（精确到小数点后2位有效数，小数点后第2位四舍五入所得）。
// 输入格式
// m(整数，实验数据总数)
// x1(实数，自然对数ln(x)的自变量)
// X2实数，自然对数ln(x)的自变量)
// ...
// xm(实数，自然对数ln(x)的自变量)
// 输出格式
// y1(实数，自然对数ln(x1)的导数)
// y2实数，自然对数ln(x2)的导数)
// ...
// ym(实数，自然对数ln(xm)的导数)
// 输入样例 拷贝到剪贴板
// 3
// 1.0
// 2.0
// 3.0
// 输出样例
// 1.00
// 0.50
// 0.33

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    double array[n],ans[n];
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
        ans[i]=1.0/array[i];
    }
    for(int i=0;i<n;i++)
    {
        printf("%.2lf\n",ans[i]);
    }
    return 0;
}

