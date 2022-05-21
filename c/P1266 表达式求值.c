#include <stdio.h>
#include <string.h>
int main()
{
    char a[200];
    while (scanf("%s", a) != EOF)
    {
        int i, k = 0, sum = 0;
        for (i = 0; i < strlen(a); i++)
        {
            if (a[i] >= '0' && a[i] <= '9')
            {
                k = k * 10 + a[i]-'0';
            }
            if (a[i] == '+')
            {
                sum += k;
                k = 0;
            }
        }
        sum+=k;
        printf("%d\n", sum);
    }
}