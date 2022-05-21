#include <stdio.h>
/*判断素数*/
int prime(int n)
{
    int i, t, k;
    for (i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return 0; /*不是素数*/
        }
    }
    return 1; /*是素数*/
}
/*反位数*/
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
    scanf("%d", &n);
    int i, b;
    int a[100];
    for (i = 0; i < n; i++) /*输入数组*/
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++)
    {
        if (prime(a[i]))
        {
            if (prime(fanwei(a[i])))
                printf("1\n");
            else
                printf("0\n");
        }
        else
            printf("0\n");
    }

    return 0;
}