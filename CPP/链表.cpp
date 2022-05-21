#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int Status;
typedef char ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
};
void PrintLink(LNode *L)
{
    LNode *p = L->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
void headinput(LNode *L, int i)
{
    ElemType n;
    while (i--)
    {
        scanf("%d", &n);
        LNode *p;
        p = (LNode *)malloc(sizeof(LNode));
        p->data = n;
        p->next = L->next;
        L->next = p;
    }
}
void tailinput(LNode *L, int i)
{
    LNode *p, *r = L;
    ElemType n;
    while (i--)
    {
        scanf("%d", &n);
        p = (LNode *)malloc(sizeof(LNode));
        p->data = n;
        r->next = p;
        r = p;
    }
    r->next = NULL;
}
void ReverseLinkList(LNode *L)
{
    LNode *p, *s;
    p = L->next;
    L->next = NULL;
    while (p)
    {
        s = p;
        p = p->next;
        s->next = L->next;
        L->next = s;
    }
}

int main()
{
    LNode *L;
    L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL;
    tailinput(L, 3);
    PrintLink(L);
    ReverseLinkList(L);
    PrintLink(L);
}