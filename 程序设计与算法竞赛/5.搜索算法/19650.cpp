#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[11];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    do
    {
        int flag = 0;
        for(int i=0; i<n; i++)
        {
            if(i!=n&&a[i]%2&&a[i+1]%2)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            for(int i=0;i<n;i++)
            {
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }
    }
    while(next_permutation(a,a+n));
    return 0;
}