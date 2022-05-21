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
typedef struct
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
    return OK;
}
void MergeList_Sq(SqList La, SqList Lb, SqList &Lc)
{
    Lc.listsize = La.length + Lb.length;
    Lc.length = Lc.listsize;
    Lc.elem = (ElemType *)malloc(Lc.listsize * sizeof(ElemType));
    if (!Lc.elem)
        exit(OVERFLOW);
    ElemType *pa, *pb, *pa_last, *pb_last, *pc;
    pa = La.elem, pb = Lb.elem, pa_last = La.elem + La.length - 1, pb_last = Lb.elem + Lb.length - 1, pc = Lc.elem;

    while (pa <= pa_last)
    {
        *pc++ = *pa++;
    }
    while (pb <= pb_last)
    {
        *pc++ = *pb++;
    }
}
void display(SqList L) //输出顺序表L
{
    for (int i = 0; i < L.length; i++)
        printf("%c", L.elem[i]); //注意类型更改
    printf("\n");
}
int main()
{
    SqList La, Lb, Lc;
    InitList_Sq(La);
    InitList_Sq(Lb);
    InitList_Sq(Lc);
    strcpy(La.elem, "adfi");
    La.length = 4;
    printf("字符串一：\n");
    display(La);
    strcpy(Lb.elem, "cefi");
    Lb.length = 4;
    printf("字符串二：\n");
    display(Lb);
    MergeList_Sq(La, Lb, Lc);
    printf("合并后的字符串：\n");
    display(Lc);
}