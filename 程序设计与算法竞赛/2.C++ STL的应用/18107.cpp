#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

struct Stu
{
    int cnt;
    int time;
    string name;
};

// 全局比较函数，用于排序
bool cmp(const Stu &a, const Stu &b)
{
    if(a.cnt == b.cnt)
    {
        if(a.time == b.time)
        {
            return false;
        }
        return a.time < b.time;
    }
    return a.cnt > b.cnt;
}

Stu stu[500000];

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> stu[i].cnt >> stu[i].time >> stu[i].name;
    }
    stable_sort(stu, stu + n, cmp);
    for(int i = 0; i < n; i++)
    {
        cout << stu[i].name << endl;
    }
    return 0;
}