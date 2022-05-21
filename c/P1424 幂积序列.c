#include <stdio.h>
int main()
{
    int m, n;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        int a[10000];
        a[1] = 1;
        a[2] = 2;
        int i, j = 3, k;
        for (i = 3; i <= n; i++)
        {
            k = i;
            while (k % 2 == 0)
            {
                k = k / 2;
            }
            while (k % 3 == 0)
            {
                k = k / 3;
            }
            if (k == 1)
            {
                a[j] = i;
                j++;
            }
        }
        j-=1;
        printf("%d\n%d\n",j,a[m]);
    }
}