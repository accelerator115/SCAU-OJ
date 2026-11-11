// 19000 二分法解非线性方程
// Description
// 二分法解非线性方程：给定非线性方程(x*x*x-2.0*x-2=0)，输入区间起点实数A和终点实数B ，
// 输出满足最大误差（EPS=0.4E-14）时，最后的区间起点，区间终点，非线性方程根的近似值
// （使用双精度double类型精确到小数点后15位有效数）。
// 输入格式
// m(整数，实验数据总数)
// A1 B1(实数，区间起点与终点)
// A2 B2(实数，区间起点与终点)
// ...
// Am Bm(实数，区间起点与终点)
// 输出格式
// A B X(输出满足最大误差（EPS=0.4E-14）时，最后的区间起点，区间终点，非线性方程根的近似值)
  
// A B X(输出满足最大误差（EPS=0.4E-14）时，最后的区间起点，区间终点，非线性方程根的近似值)
// ...
// A B X(输出满足最大误差（EPS=0.4E-14）时，最后的区间起点，区间终点，非线性方程根的近似值)
// 输入样例
// 3
// 1.0 2.0
// 0.0 2.5
// 1.5 3.0
// 输出样例
// 1.769292354238630 1.769292354238637 1.769292354238633
// 1.769292354238630 1.769292354238634 1.769292354238632
// 1.769292354238630 1.769292354238635 1.769292354238632

#include <iomanip>
#include <iostream>

using namespace std;

double equation(double x)
{
    return x * x * x - 2.0 * x - 2.0;
}

int main()
{
    int m;
    cin >> m;

    const double EPS = 0.4E-14;
    cout << fixed << setprecision(15);

    for (int i = 0; i < m; ++i)
    {
        double a, b;
        cin >> a >> b;

        if (a > b)
        {
            double temp = a;
            a = b;
            b = temp;
        }

        double fa = equation(a);
        while ((b - a) / 2.0 > EPS)
        {
            double mid = (a + b) / 2.0;
            double fm = equation(mid);

            if ((fa <= 0.0 && fm >= 0.0) || (fa >= 0.0 && fm <= 0.0))
            {
                b = mid;
            }
            else
            {
                a = mid;
                fa = fm;
            }
        }

        double root = (a + b) / 2.0;
        cout << a << ' ' << b << ' ' << root << endl;
    }

    return 0;
}
