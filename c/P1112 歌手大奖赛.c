#include <stdio.h>
int main()
{
    int m, n, k, i, j, sum;
    int x[100];
    scanf("%d", &m);
    for (; m; m--)
    {
        sum = 0;
        scanf("%d", &n);
        for (i = 0; i < n; i++)
        {
            scanf("%d", &x[i]);
        }
        for (i = 0; i < n - 1; i++)
            for (j = 0; j < n - 1 - i; j++)
            {
                if (x[j] > x[j + 1])
                {
                    k = x[j];
                    x[j] = x[j + 1];
                    x[j + 1] = k;
                }
            }
        for (i = 1; i < n - 1; i++)
            sum += x[i];
        float grade;
        grade = (float)sum / (n - 2);
        grade = (int)((grade * 100) + 0.5) / 100.0;
        printf("%.2f\n", grade);
    }
}