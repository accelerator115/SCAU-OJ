#include <cstdio>
int list[20][20];
int main()
{
    int n;
    scanf("%d",&n);
    int x=1,y=0;
    for(int i=1;i<=n*n;)
    {
        while(y<n&&list[x][y+1]==0) list[x][++y]=i++;
        while(x<n&&list[x+1][y]==0) list[++x][y]=i++;
        while(y>1&&list[x][y-1]==0) list[x][--y]=i++;
        while(x>1&&list[x-1][y]==0) list[--x][y]=i++;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%3d",list[i][j]);
        }
        printf("\n");
    }
    return 0;
}