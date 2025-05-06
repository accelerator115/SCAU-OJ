#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[10000];

void print()
{
    for(int i=1; i<=n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int Qsort(int l, int r)
{
    int temp=a[l];
    while(l<r)
    {
        while(l<r&&a[r]>=temp) r--;
        a[l]=a[r];
        while(l<r&&a[l]<=temp) l++;
        a[r]=a[l];
    }
    a[l]=temp;
    return l;
}

void solve(int l, int r)
{
    if(l<r)
    {
        int mid=Qsort(l,r);
        print();
        solve(l,mid-1);
        solve(mid+1,r);
    }
}

int main()
{
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    solve(1,n);
    return 0;
}
