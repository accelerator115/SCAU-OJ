#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll; // 定义长整型别名

/**
 * 检查两个数字a和b是否满足题目要求的数字不重复条件
 * 
 * @param a 第一个数(被除数)
 * @param b 第二个数(除数)
 * @return 如果a和b的所有非零数字都不重复，返回true；否则返回false
 */
bool check(int a, int b)
{
    int bl[15]={0}; // 标记数组，记录每个数字出现的次数
    
    // 处理第一个数a的每一位
    for (int i = 0; i <= 5; i++)
    {
        int lmt = a%10; // 获取a的最低位
        if(bl[lmt]>0 && lmt!=0) // 如果该数字(非0)已经出现过，则返回false
            return false;
        bl[lmt]++; // 标记该数字已出现
        a/= 10;    // 去除最低位
    }
    
    // 处理第二个数b的每一位
    for(int i = 0; i <= 5; i++)
    {
        int lmt = b%10; // 获取b的最低位
        if(bl[lmt]>0 && lmt!=0) // 如果该数字(非0)已经出现过，则返回false
            return false;
        bl[lmt]++; // 标记该数字已出现
        b/= 10;    // 去除最低位
    }
    
    return true; // 所有非零数字都不重复，返回true
}

/**
 * 解决单个测试用例
 * 寻找满足条件的除法表达式：o/i=n，且o和i的非零数字不重复
 * 
 * @param n 指定的除法结果
 */
void solve(int n)
{
    // 枚举可能的除数i
    for(int i=1; i<=98765; i++)
    {
        int o = n*i; // 计算对应的被除数
        
        if(o>99999) // 如果被除数超过5位数，后续的i只会更大，直接结束
            break;
            
        // 检查o和i是否满足数字不重复的条件
        if(check(o, i))
          printf("%05d/%05d=%d\n", o, i, n); // 按格式输出结果
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    
    // 处理多个测试用例，直到输入0结束
    while(n != 0)
    {
        solve(n);     // 解决当前测试用例
        printf("\n"); // 用例之间输出空行
        scanf("%d", &n); // 读取下一个测试用例
    }
    
    return 0;
}