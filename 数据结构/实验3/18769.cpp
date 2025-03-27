#include <iostream>
#include <algorithm>
 
using namespace std;
typedef long long i64;
 
int main()
{
    int T=1;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        int a[n];
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        for(int i=0,j=n-1;i<j;i++,j--)
        {
            if(a[i]>0)
            {
                while(a[j]>0 and i<j)
                    j--;
                swap(a[i],a[j]);
            }
            if(a[j]<0)
            {
                while(a[i]<0 and i<j)
                    i++;
                swap(a[i],a[j]);
            }
        }
        for(int i=0;i<n;i++) printf("%d ",a[i]);
        printf("\n");
    }
    return 0;
}