// 18999 求指数函数值
// Description
// 求指数函数值，输入实数x ，输出x对应的指数函数值exp(x)
// （使用双精度double类型精确到小数点后14位有效数）。
// 输入格式
// 实验输入数据格式
// m(整数，实验数据总数)
// x1(实数)
// x2(实数)
// ...
// xm(实数)
// 输出格式
// 实验输出数据格式
// y1(实数，x1的指数函数值)  
// y2(实数，x2的指数函数值)
// ...
// ym(实数，xm的指数函数值)
// 输入样例 拷贝到剪贴板
// 3
// -1.0
// 0
// 1.5
// 输出样例
// 0.36787944117144
// 1.00000000000000
// 4.48168907033806

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int m;
    const double e = 2.71828182845904523536; // e
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        double x;
        cin >> x;

        int exp = 0;
        while (x > 1.0)
        {
            x -= 1.0;
            ++exp;
        }
        while (x < -1.0)
        {
            x += 1.0;
            --exp;
        }

        double term = 1.0;
        double sum = 1.0;
        for (int k = 1; k <= 120; ++k)
        {
            term *= x / k;
            sum += term;
        }

        double result = sum;
        if (exp > 0)
        {
            for (int j = 0; j < exp; ++j)
                result *= e;
        }
        else if (exp < 0)
        {
            for (int j = 0; j < -exp; ++j)
                result /= e; 
        }

        cout << fixed << setprecision(14) << result << endl;
    }
    return 0;
}