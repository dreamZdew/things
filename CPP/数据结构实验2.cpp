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
typedef char ElemType; //elemtype
typedef struct//顺序表结构体
{
    ElemType *elem;
    int length;
    int listsize;
} SqList;
Status InitList_Sq(SqList &L) //构造顺序表L
{
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem)
        exit(OVERFLOW);
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return 1;
}
void display(SqList L) //输出顺序表L
{
    for (int i = 0; i < L.length; i++)
        printf("%c", L.elem[i]); //注意类型更改
    printf("\n");
}
void ReverseSqList(SqList &L) //反转顺序组
{
    ElemType k;
    for (int i = 0; i < L.length / 2; i++)
    {
        k = L.elem[i];
        L.elem[i] = L.elem[L.length - 1 - i];
        L.elem[L.length - 1 - i] = k;
    }
}
typedef struct LNode//链表结构体
{
    ElemType data;
    struct LNode *next;
};
void PrintLink(LNode *L)//输出链表
{
    LNode *p = L->next;
    while (p != NULL)
    {
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n");
}
void tailinput(LNode *L, int i)//尾插法
{
    LNode *p, *r = L;
    ElemType n;
    while (i--)
    {
        scanf("%c", &n);
        p = (LNode *)malloc(sizeof(LNode));
        p->data = n;
        r->next = p;
        r = p;
    }
    r->next = NULL;
}
void ReverseLinkList(LNode *L)//反转链表
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
    SqList L1;
    InitList_Sq(L1);
    strcpy(L1.elem, "hello");
    L1.length = 5;
    display(L1);
    ReverseSqList(L1);
    display(L1);
    LNode *L2;
    L2 = (LNode *)malloc(sizeof(LNode));
    L2->next = NULL;
    tailinput(L2,6);
    PrintLink(L2);
    ReverseLinkList(L2);
    PrintLink(L2);
}
