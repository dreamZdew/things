#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int i = 0, j = 0, k, t = 0, a[10];
        if (n < 0)
        {
            t = 1;
            n *= (-1);
        }
        while (n)
        {
            k = n % 2;
            a[i] = k;
            i++;
            n /= 2;
        }
        printf("%d", t);
        for (j = i - 1; j >= 0; j--)
        {
            if (t == 1)
                a[j] = !a[j];
        }
        if (t == 1)
        {
            a[0] += 1;
            for (j = 0; j < i; j++)
            {
                if (a[j] > 1)
                {
                    a[j + 1] += 1;
                    a[j] -= 2;
                }
            }
        }
        for (j = i - 1; j >= 0; j--)
            printf("%d", a[j]);
    }
}