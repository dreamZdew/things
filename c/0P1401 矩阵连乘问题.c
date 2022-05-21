#include <stdio.h>
int Best_Enum(int m[], int left, int right)
{
    if (left == right)
    {
        return 0;
    }

    int min = 2100000000; 
    int i;
    for (i = left; i < right; i++)
    {
        int count = Best_Enum(m, left, i) + Best_Enum(m, i + 1, right);
        count += m[left - 1] * m[i] * m[right];
        if (count < min)
        {
            min = count;
        }
    }
    return min;
}
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int i, j, k, f = 0;
        int b[n][2];
        for (i = 0; i < n; i++)
            scanf("%d %d", &b[i][0], &b[i][1]);
        int c[n + 1];
        for (i = 0; i < n; i++)
            c[i] = b[i][0];
        c[n] = b[n - 1][1];

        for (i = 1; i < n; i++)
            if (b[i][0] != b[i - 1][1])
            {
                printf("invalid argument\n");
                f = 1;
                break;
            }
        if (f == 1)
            continue;

        printf("%d\n", Best_Enum(c, 1, n));
    }
}