#include <cstdio>
#include <cmath>

long func(int n)
{
    long s=0;
    int i, q;
    if(n<1) return 0;
    q= sqrt(n);
    for(i=1; i<=q; i++)
        s+=(n/i-n/(i+1))*i;
    for(i=1; i<=n/(q+1); i++)
        s+=n/i;
 
    return s;
}    

int main()
{
    int a;
    int n;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &a);
        printf("%ld\n", func(a));
    }    
}    
