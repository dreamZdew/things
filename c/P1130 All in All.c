#include <stdio.h>
#include <string.h>
#define N 100000
int main()
{
    char a[N], b[N];
    while (scanf("%s %s", a, b) != EOF)
    {
        int i, j, k = 1, m = strlen(a), n = strlen(b), x = 0;
        for (i = 0; i < m; i++)
        {
            if (k)
                for (j = x; j < n; j++)
                {
                    if (a[i] == b[j])
                    {
                        x = j;
                        k = 1;
                        break;
                    }
                    k = 0;
                }
        }
        if (k)
            printf("Yes\n");
        else
            printf("No\n");
    }
}