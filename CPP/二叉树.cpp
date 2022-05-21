#include <stdio.h>
#include <stdlib.h>
typedef char ElemType;
struct BiNode
{
    ElemType data;
    struct BiNode *lch, *rch;
};
void input(BiNode *&T)
{
    T = (BiNode *)malloc(sizeof(BiNode));
    char ch;
    ch = getchar();
    if (ch == '.')
        T = NULL;
    else
    {
        T->data = ch;
        input(T->lch);
        input(T->rch);
    }
}
void previsit(struct BiNode *T)
{
    if (T)
    {
        printf("%c", T->data);
        previsit(T->lch);
        previsit(T->rch);
    }
}
void midvisit(BiNode *T)
{
    if (T)
    {
        midvisit(T->lch);
        printf("%c", T->data);
        midvisit(T->rch);
    }
}
void lastvisit(BiNode *T)
{
    if (T)
    {
        lastvisit(T->lch);
        lastvisit(T->rch);
        printf("%c", T->data);
    }
}
int main()
{
    struct BiNode *T = NULL;
    input(T); //-+a..*b..-c..d../e..f..
    printf("先序遍历：");
    previsit(T);
    printf("\n");
    printf("中序遍历：");
    midvisit(T);
    printf("\n");
    printf("后序遍历：");
    lastvisit(T);
}
