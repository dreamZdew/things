#include <stdio.h>
#define N 1000
int a[N][N];
int main()
{
    int n, i, j, k;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        for (j = 0; j <= i; j++)
        {
            scanf("%d", &a[i][j]);
        }
    for (i = n - 2; i >= 0; i--)
        for (j = 0; j <= i; j++)
        {
            if (a[i + 1][j] < a[i + 1][j + 1])
                a[i][j] += a[i + 1][j];
            else
                a[i][j] += a[i + 1][j + 1];
        }
    printf("%d",a[0][0]);
}