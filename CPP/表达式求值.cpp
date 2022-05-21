#include <stdio.h>
#include <stdlib.h>
struct Sqstack
{
    char *base;
    char *top;
    int stacksize;
};
int InitStack(Sqstack &S)
{
    S.base = (char *)malloc(100 * sizeof(char));
    if (!S.base)
        exit(-2);
    S.top = S.base;
    S.stacksize = 100;
    return 1;
}
int Push(Sqstack &S, char e) //插入
{
    if (S.top - S.base >= S.stacksize)
    {
        S.base = (char *)realloc(S.base, (S.stacksize + 10) * sizeof(char));
        if (!S.base)
            exit(-2);
        S.top = S.base + S.stacksize;
        S.stacksize += 10;
    }
    *S.top = e;
    *S.top++;
}
int Pop(Sqstack &S, char &e) //以e输出
{
    if (S.base == S.top)
        exit(-2);
    e = *--S.top;
}
char GetTop(Sqstack &S)
{
    char e;
    if (S.top == S.base)
        return 0;
    e = *(S.top - 1);
    return e;
}
char Precede(char a, char b)
{
    if (a == '+' || a == '-')
    {
        if (b == '+' || b == '-' || b == '#'||b==')')
            return '>';
        else
            return '<';
    }
    if (a == '*' || a == '/')
    {
        if (b == '(')
            return '<';
        else
            return '>';
    }
    if (a == '(')
    {
        if (b == ')')
            return '=';
        else
            return '<';
    }
    if (a == ')')
    {
        return '>';
    }
    if (a == '#')
    {
        if (b == '#')
            return '=';
        else
            return '<';
    }
}
int Operate(int a, char x, int b)
{
    switch (x)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
}
void eva()
{
    char c, x;
    Sqstack OPTR,OPND;
    InitStack(OPTR);
    Push(OPTR, '#');
    InitStack(OPND);
    c = getchar();
    while (c != '#' || GetTop(OPTR) != '#')
    {
        if (c != '+' && c != '-' && c != '*' && c != '/' && c != '(' && c != ')'&&c != '#' )
        {
            Push(OPND, c-'0');
            c = getchar();
           
        }
        else
            switch (Precede(GetTop(OPTR), c))
            {
            case '<':
                Push(OPTR, c);
                c = getchar();
                break;
            case '=':
                Pop(OPTR, x);
                c = getchar();
                break;
            case '>':
                Pop(OPTR, x);
                char a, b;
                Pop(OPND, b);
                Pop(OPND, a);
                Push(OPND, Operate(a, x, b));
                break;
            }
    }
    printf("%d",GetTop(OPND));
}
int main()
{
    eva();
}