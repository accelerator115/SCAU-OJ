#include <iostream>
#include <cstdio>

using namespace std;

int judge(int n, int a, int step, int f)
{
    if(n<3) return 0;
    if(n==3) return 1;
    if((f-a)%(2*step)==0) return judge((n+1)/2, a, step*2, f);
    else return judge(n/2, a+step, step*2, f);
}

int main()
{
    int n, loc;
    while(scanf("%d%d", &n, &loc), n!=0||loc!=0)
        if(judge(n,1,1,loc)) cout<<"Y"<<endl;
        else cout<<"N"<<endl;
    return 0;
}
