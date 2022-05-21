#include <stdio.h>
int main()
{
    int m, n;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        int a[1000];
        int i, j, k=n, t, count = 0;
        for (i = 1; i <= n; i++)
            a[i] = i;
        while (k)
        {
            for (i = 1; i <= n; i++)
            {
                if (a[i] != 0)
                    count++;
                if (count == m)
                {
                    a[i]=0;
                    count=0;
                    k--;
                    t=i;
                }
            }
        }
        printf("%d\n",t);
    }
}