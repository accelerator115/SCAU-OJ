#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

class Stu
{
public:
    int cnt;
    int time;
    string name;
    Stu(int cnt, int time, string name) : cnt(cnt), time(time), name(name) {};
    Stu() : cnt(0), time(0), name("") {};
    bool operator<(const Stu &stu) const
    {
        if(cnt == stu.cnt)
        {
            if(time == stu.time)
            {
                return false;
            }
            return time < stu.time;
        }
        return cnt > stu.cnt;
    }
};

Stu stu[500000];

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int cnt, time;
        string name;
        cin >> cnt >> time >> name;
        stu[i] = Stu(cnt, time, name);
    }
    stable_sort(stu, stu + n);
    for(int i = 0; i < n; i++)
    {
        cout << stu[i].name << endl;
    }
    return 0;
}