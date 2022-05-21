#include <stdio.h>
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int i, j, k = 1, m = 0;
        for (i = 2; i < n; i++, k = 1)
        {
            for (j = 2; j < i; j++)
                if (i % j == 0)
                    k = 0;
            if (k != 0)
                m += i;
        }
        printf("%d\n", m);
    }
}