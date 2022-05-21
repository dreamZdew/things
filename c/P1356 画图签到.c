#include <stdio.h>
int main()
{
    int n, i, j, k, m;
    while (scanf("%d", &n) != EOF)
    {
        printf("%d:\n", n);
        k = 1;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < k; j++)
            {
                if (j % 2 == 0)
                    printf("*");
                else
                    printf("-");
            }
            k++;
            printf("\n");
        }
    }
}