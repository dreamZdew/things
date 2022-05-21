#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    for (; n; n--)
    {
        int a, k, i, m = 0;
        scanf("%d", &a);
        for (i = 1; a > 0; a /= 6, i *= 10)
        {
            k = a % 6;
            m += k * i;
        }
        printf("%d\n", m);
    }
}