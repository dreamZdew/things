#include <stdio.h>
int main()
{
    int k;
    scanf("%d", &k);
    for (; k; k--)
    {
        int n;
        scanf("%d",&n);
        for (int i = 1; n - i > 0; i++)
        {
            n -= i;
        }
        for(;n>9;)
        n-=9;
        printf("%d\n",n);
    }
}