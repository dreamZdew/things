#include <stdio.h>
int a[120][120];
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int  m = 1, i, j;
        for (i = 0; i < n; i++)
        {
            if (i % 2 != 0 )
                for (j = n - 1; j >= 0; j--)
                {
                    a[j][i] = m;
                    m++;
                }
            if (i % 2 == 0)
                for (j = 0; j < n; j++)
                {
                    a[j][i] = m;
                    m++;
                }
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
                printf("%d ", a[i][j]);
            printf("\n");
        }
        printf("\n");
    }
}