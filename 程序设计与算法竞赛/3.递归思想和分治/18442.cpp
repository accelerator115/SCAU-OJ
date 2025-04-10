#include <iostream>
#include <algorithm>

using namespace std;

int countImpossible(int n,int head,int del)
{
    if(n<3)
        return head;
    if(n==3)
        return 0;
    int a = countImpossible((n+1)/2,head,del*2);
    int b = countImpossible(n/2,head+del,del*2);
    if(a>0&&b>0)
        return min(a,b);
    else if(a>0)
        return a;
    else if(b>0)
        return b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    while(cin>>n && n!=0)
    {
        cout<<countImpossible(n,1,1)<<endl;
    }
    return 0;
}
