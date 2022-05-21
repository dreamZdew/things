#include <stdio.h>
int main()
{
    int n, k;
    while (scanf("%d%d", &n, &k) != EOF)
    {
        int  i, j, l=0;
        for (i = 0; i <= 20; i++)
        {
            if (i * n >= 200 + i * k)
            {
                l=1;
                printf("%d", i);
                break;
            }
        }
        if(l==0)
        printf("Impossible");
        printf("\n");
    }
}