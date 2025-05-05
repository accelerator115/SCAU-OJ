#include <iostream>
#include <algorithm>

using namespace std;


int countImpossible(int n, int head, int del)
{
    // 基本情况：如果人数小于3，直接返回起始编号
    if(n < 3)
        return head;
    
    // 特殊情况：根据题目要求返回0
    if(n == 3)
        return 0;
    
    // 分治递归求解：
    // 将问题分为两部分，前(n+1)/2个人和后n/2个人
    // a表示前半部分最后剩下的人的编号
    int a = countImpossible((n+1)/2, head, del*2);
    // b表示后半部分最后剩下的人的编号，注意头部偏移了del
    int b = countImpossible(n/2, head+del, del*2);
    
    // 如果两个子问题都有解，返回较小的编号
    if(a > 0 && b > 0)
        return min(a, b);
    // 如果只有一个子问题有解，返回那个解
    else if(a > 0)
        return a;
    else if(b > 0)
        return b;
    
    // 隐含的返回：如果都没有解，返回0（根据题意，此情况可能不会出现）
    return 0;
}

int main()
{
    // 优化输入输出速度
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    // 循环读入测试用例，直到输入0表示结束
    while(cin >> n && n != 0)
    {
        // 调用函数求解并输出结果
        cout << countImpossible(n, 1, 1) << endl;
    }
    return 0;
}
