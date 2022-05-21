#include <stdio.h>
int fun(int B, int n) /*将B进制转换成十进制（B为纯数字）*/
{

    int a = 0, b = 1;
    while (n)
    {
        if (n % 10 >= B)
            return 2000000000;
        a += n % 10 * b;
        b *= B;
        n /= 10;
    }
    return a;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (; n; n--)
    {
        int p, q, r, i;
        scanf("%d%d%d", &p, &q, &r);
        for (i = 2; i <= 17; i++)
        {
            if (i == 17)
            {
                printf("0\n");
                break;
            }
            if (fun(i, p) * fun(i, q) == fun(i, r))
            {
                printf("%d\n", i);
                break;
            }
        }
    }
}