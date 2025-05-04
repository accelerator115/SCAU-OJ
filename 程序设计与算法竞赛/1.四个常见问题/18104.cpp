#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b)
{
    return b==0?a:gcd(b,a%b);
}

ll lcd(ll a,ll b)
{
    return a*b/gcd(a,b);
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        ll a,b;
        cin>>a>>b;
        cout<<lcd(a,b)<<endl;
    }
    cout<<"group 1 done"<<endl;
    ll a,b;
    while(cin>>a>>b&&(a!=0||b!=0))
    {
        cout<<lcd(a,b)<<endl;
    }
    cout<<"group 2 done"<<endl;
    while(scanf("%lld%lld",&a,&b)!=-1)
    {
        cout<<lcd(a,b)<<endl;
    }
    cout<<"group 3 done"<<endl;
    return 0;
}