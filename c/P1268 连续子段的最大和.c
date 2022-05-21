#include <stdio.h>
int a[10000];
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int i, j, max, sum;
        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);
        max = a[0];
        for (i = 0; i < n; i++)
        {
            sum = a[i];
            for (j = i + 1; j < n; j++)
            {
                sum += a[j];
                if (sum > max)
                    max = sum;
            }
        }
        printf("%d\n",max);
    }
}