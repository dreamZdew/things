#include <stdio.h>
#include<math.h>
#define N 2000
int a[N][N];
int main()
{
    int n;
    scanf("%d", &n);
    int i, j, k = 0;
        a[0][0] = 1;
    for (i = 1; i < N; i++)
    {
        for (j = 1; j <= i; j++)
        {
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
            if(a[i][j]==n)
            {
                printf("%d",i*(i-1)/2+j);
                return 0;
            }
        }
    }
    k=sqrt(n*2)+1;
    if(k*(k-1)/2==n)
    {
        printf("%d",k*(k+1)/2+3);
    }
    else
    {
        printf("%d",n*(n+1)/2+2);
    }
}