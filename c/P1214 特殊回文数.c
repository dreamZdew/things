#include <stdio.h>
int qiuhe(int n)
{
    int i, j = 0, k;
    for (; n;)
    {
        j += n % 10;
        n /= 10;
    }
    return j;
}
int fanwei(int n)
{
    int i, k = 10, t = 0;
    for (i = n; i != 0; i /= 10)
    {
        t += i % 10;
        t *= 10;
    }
    return t /= 10;
}
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int i, j, k, m;
        for (i = 10000; i < 1000000; i++)
        {
            if (fanwei(i) == i)
                if (qiuhe(i) == n)
                    printf("%d\n", i);
        }
        printf("\n");
    }
}