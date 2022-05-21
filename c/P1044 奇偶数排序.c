#include <stdio.h>
int main()
{
    int n = 0, a[10], i, j, k, m;
    while (n < 10)
    {
        scanf("%d", &a[n]);
        n++;
    }
    for (i = 0; i < 10; i++)
        for (j = 0; j < 10; j++)
            if (a[j] < a[j + 1])
            {
                k = a[j + 1];
                a[j + 1] = a[j];
                a[j] = k;
            }
    for (i = 0; i < 10; i++)
        if (a[i] % 2 == 1)
            printf("%d ", a[i]);
    for (i = 9; i > -1; i--)
        if (a[i] % 2 == 0)
            printf("%d ", a[i]);
}