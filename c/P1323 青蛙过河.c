#include <stdio.h>
int fun(int a)
{
    if(a==1)
    return 1;
    if (a==2)
    return 2;
    if(a>2)
    return fun(a-1)+fun(a-2);
    
}
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        printf("%d\n",fun(n));
    }
}