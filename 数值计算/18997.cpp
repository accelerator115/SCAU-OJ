// 18997 求余弦函数值
// Description
// 求余弦函数值，输入实数x(弧度，0到π) ，输出x对应的余弦函数值（使用双精度double类型精确到小数点后14位有效数）。
// 输入格式
// 实验输入数据格式
// m(整数，实验数据总数)
// x1(弧度，0到π)
// x2(弧度，0到π)
// ...
// xm(弧度，0到π)
// 输出格式
// 实验输出数据格式
// y1(实数，x1的余弦函数值)  
// y2(实数，x2的余弦函数值)
// ...
// ym(实数，x2的余弦函数值)
// 输入样例
// 3
// 0.0
// 0.5
// 1.0
// 输出样例
// 1.00000000000000
// 0.87758256189037
// 0.54030230586814

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        long double x;
        cin >> x;

        long double c[16];
        c[0] = 1.0L;
        for (int k = 1; k < 16; k++)
        {
            c[k] = -c[k - 1] / ((2 * k - 1) * (2 * k));
        }

        long double s = x * x;
        long double p = c[15];
        for (int k = 14; k >= 0; k--)
        {
            p = p * s + c[k];
        }

        printf("%.14Lf\n", p);
    }
    return 0;
}