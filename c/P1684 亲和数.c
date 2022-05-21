#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    for (; n; n--)
    {
        int a, b, suma = 0, sumb = 0, i;
        scanf("%d %d", &a, &b);
        for (i = 1; i < a; i++)
            if (a % i == 0)
                suma += i;
        for (i = 1; i < b; i++)
            if (b % i == 0)
                sumb += i;
        if (b == suma && a == sumb)
            printf("Yes\n");
        else
            printf("No\n");
    }
}