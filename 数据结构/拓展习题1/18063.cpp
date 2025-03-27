#include <stdio.h>
int lastRemaining(int n) 
{
    int i, last = 0; 
    for (i = 2; i <= n; i++)
        last = (last + 3) % i;
    return last+1 ; 
}
int main() 
{
    int n;
    scanf("%d", &n);
    printf("%d\n", lastRemaining(n));
    return 0;
}