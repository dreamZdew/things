#include <stdio.h>
int a[600][600];
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        a[0][0] = 1;
        int k = n * n, i, j;
        for (i = 1; i < n; i++)
            a[i][i] = 2 * i + a[i - 1][i - 1];
        for (i = 1; i < n; i++)
        {
            if (i % 2 != 0)
            {
                for (j = i; j > 0; j--)
                    a[j - 1][i] = a[j][i] - 1;
                for (j = i; j > 0; j--)
                    a[i][j - 1] = a[i][j] + 1;
            }
            if (i % 2 == 0)
            {
                for (j = i; j > 0; j--)
                    a[j - 1][i] = a[j][i] + 1;
                for (j = i; j > 0; j--)
                    a[i][j - 1] = a[i][j] - 1;
            }
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
                printf("%d ", a[i][j]);
            printf("\n");
        }
    }
}