#include <stdio.h>
#include <string.h>
#define N 1000
int max(int a, int b)
{
    if (a >= b)
        return a;
    else
        return b;
}
int main()
{
    char a[N], b[N], c[N];
    while (scanf("%s%s", a, b) != EOF)
    {
        int aa[N] = {0}, bb[N] = {0}, d[N];
        int i, j, k, n, m;
        m = strlen(a);
        for (i = 0; i < m; i++)
            c[i] = a[m - i - 1];
        strcpy(a, c);
        for (i = 0; i < m; i++)
            aa[i] = a[i] - '0';
        n = strlen(b);
        for (i = 0; i < n; i++)
            c[i] = b[n - i - 1];
        strcpy(b, c);
        for (i = 0; i < n; i++)
            bb[i] = b[i] - '0'; /*倒*/
        k = max(m, n);
        for (i = 0; i < k + 1; i++)
            d[i] = aa[i] + bb[i];
        for (i = 0; i < k + 1; i++)
        {
            if (d[i] >= 10)
                d[i + 1] += (d[i] / 10);
            d[i] = d[i] % 10;
        }
        if (d[k] != 0)
            printf("%d", d[k]);
        for (i = k - 1; i >= 0; i--)
            printf("%d", d[i]);
        printf("\n");
    }
}