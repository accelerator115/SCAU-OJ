#include <iostream>
#include <algorithm>

using namespace std;

int n,a[100];

void print()
{
    for(int i=1;i<=n;i++)
    {
        printf("%03d ",a[i]);
    }
    printf("\n");
}

bool cmp1(int x,int y)
{
    return x%10<y%10;
}

bool cmp2(int x,int y)
{
    return x/10%10<y/10%10;
}

bool cmp3(int x,int y)
{
    return x/100%10<y/100%10;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    stable_sort(a+1,a+n+1,cmp1);
    print();
    stable_sort(a+1,a+n+1,cmp2);
    print();
    stable_sort(a+1,a+n+1,cmp3);
    print();
    return 0;
}
