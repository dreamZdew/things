#include <string.h>
#include <stdio.h>
void bubble(int p[], int b[], int len)
{
    int i, j, temp;
    for (i = 0; i < len - 1; i++)
        for (j = 0; j < len - 1 - i; j++)
        {
            if (p[j] < p[j + 1])
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
            if (p[j] == p[j + 1] && b[j] < b[j + 1])
            {
                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
}
int main()
{
    int n, k;
    while (scanf("%d %d", &n, &k) != EOF)
    {
        int a[n], p[n], i, j, money = 0;
        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (i = 0; i < n; i++)
            scanf("%d", &p[i]);
        bubble(p, a, n);

        for (i = 0; i < k && i < n; i++)
        {
            money += a[i];
            for (j = i; j < n; j++)
            {
                a[j] -= p[j];
                if (a[j] < 0)
                    a[j] = 0;
            }
        }
        printf("%d\n", money);
    }
}