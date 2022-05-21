#include <stdio.h>
#include <string.h>
int l[10000] = {0};
int main()
{
    char a[100], b[100];
    scanf("%s%s", a, b);
    int m[100], n[100], z, x, j, i;
    z = strlen(a);
    x = strlen(b);
    for (i = 0; i < z; i++)
        m[i] = a[z - i - 1] - '0';
    for (i = 0; i < x; i++)
        n[i] = b[x - i - 1] - '0';
    for (i = 0; i < z; i++)
        for (j = 0; j < x; j++)
            l[i + j] += m[i] * n[j];
    for (i = 0; i < z + x - 1; i++)
        if (l[i] >= 10)
        {
            l[i + 1] += l[i] / 10;
            l[i] = l[i] % 10;
        }
    int k = 1;
    for (i = z + x - 1; i >= 0; i--)
    {
        if (l[i] == 0 && k)
            continue;
        if (l[i] != 0)
            k = 0;
        printf("%d", l[i]);
    }
    printf("\n");
}