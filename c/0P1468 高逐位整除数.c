#include <stdio.h>
int chu(int a[], int b)
{
    int i, j, k = 10, m = a[0], n;
    for (i = 0; i < b - 1; i++)
        m = m * k + a[i + 1];
    if (m % b == 0)
        return 1;
    else
        return 0;
}
int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        int a[n];
        int i, j, k;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < 10; j++)
            {
                a[i] = j;
                if (chu(a, i))
                {
                    continue;
                }
                else
                {
                    i = 0;
                    break;
                }
            }
        }
    }
}