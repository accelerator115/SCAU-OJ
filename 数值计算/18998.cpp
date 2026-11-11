// 18998 求对数函数值ln(x)
// Description
// 求对数函数值，输入实数x>0 ，输出x对应的对数函数值ln(x)（使用双精度double类型精确到小数点后14位有效数）。
// 输入格式
// 实验输入数据格式
// m(整数，实验数据总数)
// x1(实数>0)
// x2(实数>0)
// ...
// xm(实数>0)
// 输出格式
// 实验输出数据格式
// y1(实数，x1的对数函数值)  
// y2(实数，x2的对数函数值)
// ...
// ym(实数，xm的对数函数值)
// 输入样例
// 3
// 1.5
// 3.5
// 8.5
// 输出样例
// 0.40546510810816
// 1.25276296849537
// 2.14006616349627

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        double x;
        cin >> x;

        int exp= 0;
        while (x >= 2.0)
        {
            x /= 2.0;
            ++exp;
        }
        while (x < 0.5)
        {
            x *= 2.0;
            --exp;
        }

        double z = (x - 1.0) / (x + 1.0);
        double z2 = z * z;
        double term = z;
        double sum = 0.0;
        for (int k = 1; k <= 120; ++k)
        {
            sum += term / (2.0 * k - 1.0);
            term *= z2;
        }

        const double ln2 = 0.69314718055994530942;
        double result = 2.0 * sum + exp * ln2;
        cout << fixed << setprecision(14) << result << '\n';
    }
    return 0;
}
