#include <stdio.h>
#include <math.h>
int shizhuaner(int n)
{
    int i = 0, k = 1;
    for (; n > 0;)
    {
        i += k * (n % 2);
        n /= 2;
        k *= 10;
    }
    return i;
}
int erzhuanshi(int n)
{
    int i = 0, j, k = 0, m;
    for (; n > 0;)
    {
        if (n % 10 == 1)
            i += pow(2, k);
        k += 1;
        n /= 10;
    }
    return i;
}
int main()
{
    int n;
    scanf("%d", &n);
    n = shizhuaner(n);
    printf("%d", n);
}
