#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;

bool check(int a, int b)
{
    int bl[15]={0};
    for (int i = 0; i <= 5; i++)
    {
        int lmt = a%10;
        if(bl[lmt]>0&&lmt!=0)
            return false;
        bl[lmt]++;
        a/= 10;
    }
    for(int i = 0; i <= 5; i++)
    {
        int lmt = b%10;
        if(bl[lmt]>0&&lmt!=0)
            return false;
        bl[lmt]++;
        b/= 10;
    }
    return true;
}

void solve(int n)
{
    for(int i=1;i<=98765;i++)
    {
        int o=n*i;
        if(o>99999)
            break;
        if(check(o,i))
          printf("%05d/%05d=%d\n",o,i,n);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n!=0)
    {
        solve(n);
        printf("\n");
        scanf("%d",&n);
    }
    return 0;
}