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

void maxHeapify(int l,int r)
{
    int f=l,s=l*2;
    while(s<=r)
    {
        if(s+1<=r&&a[s+1]>a[s]) s++;
        if(a[f]>a[s]) return ;
        swap(a[f],a[s]);
        f=s;
        s=f*2;
    }
}

int main()
{
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=n;i>0;i--)
    {
        maxHeapify(i,n);
    }
    print();
    for(int i=n;i>1;i--)
    {
        swap(a[1],a[i]);
        maxHeapify(1,i-1);
        print();
    }
    return 0;
}