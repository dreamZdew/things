#include <stdio.h>
#include <stdlib.h>
struct Sqstack
{
    int *base;
    int *top;
    int stacksize;
};

int InitStack(Sqstack &S)
{
    S.base = (int *)malloc(100 * sizeof(int));
    if (!S.base)
        exit(-2);
    S.top = S.base;
    S.stacksize = 100;
    return 1;
}

int Push(Sqstack &S, int e) //插入
{
    if (S.top - S.base >= S.stacksize)
    {
        S.base = (int *)realloc(S.base, (S.stacksize + 10) * sizeof(int));
        if (!S.base)
            exit(-2);
        S.top = S.base + S.stacksize;
        S.stacksize += 10;
    }
    *S.top++;
    *S.top = e;
}

int Pop(Sqstack &S, int &e) //以e输出
{
    if (S.base == S.top)
        exit(-2);
    e = *S.top;
    *S.top--;
}


int main()
{
    conversion();
}
