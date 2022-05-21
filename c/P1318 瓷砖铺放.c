#include <stdio.h>
int fun(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    if (n > 2)
        return (fun(n - 1) + fun(n - 2));
}
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        printf("%d\n", fun(n));
    }
}