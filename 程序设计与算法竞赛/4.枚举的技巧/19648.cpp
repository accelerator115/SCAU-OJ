#include <iostream>
#define ll long long
using namespace std;

int main()
{
    ll k;
    cin>>k;
    for(ll a=1LL;a<=k;a++)
    {
        if(k*k%a==0)
        {
            ll b=k*k/a;
            ll x=k+b;
            ll y=k+a;
            if(x!=0&&y!=0) cout<<"1/"<<k<<"=1/"<<x<<"+1/"<<y<<endl;
        }
    }
    return 0;
}
