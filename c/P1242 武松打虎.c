#include <stdio.h>
long a[50000];
int main()
{
    long n, t;
    while (scanf("%d %d", &n, &t) != EOF)
    {
        int i, j, k = 0, m, temp;
        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (i = 0; i < n - 1; i++)
            for (j = 0; j < n - i - 1; j++)
                if (a[j] > a[j + 1])
                {
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
        for (i = 0; t - a[i] >= 0; i++)
        {
            t -= a[i];
            k++;
        }
        printf("%d\n", k);
    }
}