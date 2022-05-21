#include <stdio.h>
#include <string.h>
#define N 3000
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
        {
            printf("1\n");
            continue;
        }
        int a[N] = {0}, i, k;
        a[0] = n;
        while (n > 1)
        {
            n--;
            for (i = 0; i < N; i++)
                a[i] *= n;
            for (i = 0; i < N; i++)
                if (a[i] >= 10)
                {
                    a[i + 1] += (a[i] / 10);
                    a[i] = a[i] % 10;
                }
        }
        for (i = N - 1; i >= 0; i--)
            if (a[i] != 0)
                break;
        for (; i >= 0; i--)
            printf("%d", a[i]);
        printf("\n");
    }
}
