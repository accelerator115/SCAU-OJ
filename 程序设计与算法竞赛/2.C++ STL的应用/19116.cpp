#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll ugly[100000];
void init()
{
    int l2=1,l3=1,l5=1;
    ugly[1]=1;
    for(ll i=2;i<100000;i++)
    {
        ugly[i]=min(ugly[l2]*2,min(ugly[l3]*3,ugly[l5]*5));
        if(ugly[i]==ugly[l2]*2) l2++;
        if(ugly[i]==ugly[l3]*3) l3++;
        if(ugly[i]==ugly[l5]*5) l5++;
    }
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    init();
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        cout<<ugly[n]<<endl;
    }
    return 0;
}