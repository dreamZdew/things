#include <stdio.h>
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int i = 0, a, b, c;
        for (; n; n--)
        {
            scanf("%d+%d=%d", &a, &b, &c);
            if (a + b != c)
                i++;
        }
        if (i == 0)
            printf("Accepted\n");
        else
            printf("Wrong Answer\n");
    }
}