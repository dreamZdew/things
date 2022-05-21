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
Status InitList_Sq(SqList &L)//构造顺序表L
{
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem)
		exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}
Status ListInsert_Sq(SqList &L, int position, ElemType e)//将元素e插入L的第position个位置
{
	if (position < 1 || position > L.length + 1)
		return ERROR;
	if (L.length >= L.listsize)
	{
		L.elem = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!L.elem)
			exit(OVERFLOW);
		L.listsize += LISTINCREMENT;
	}
	for (int i = L.length - 1; i >= position - 1; i--)
		L.elem[i + 1] = L.elem[i];
	L.elem[position - 1] = e;
	L.length++;
	return OK;
}
Status ListDelete_Sq(SqList &L, int position)//删除L的第position个元素
{
	if (position < 1 || position > L.length)
		return ERROR;
	for (int i = position - 1; i < L.length; i++)
		L.elem[i] = L.elem[i + 1];
	L.length--;
	return OK;
}
void display(SqList L)//输出顺序表L
{
	for (int i = 0; i < L.length; i++)
		printf("%c", L.elem[i]);//注意类型更改
	printf("\n");
}
void MergeList_Sq(SqList La, SqList Lb, SqList &Lc)//合并字符串La,Lb到Lc从小到大排列
{
    Lc.listsize = La.length + Lb.length;
    Lc.length = Lc.listsize;
    Lc.elem = (ElemType *)malloc(Lc.listsize * sizeof(ElemType));
    if (!Lc.elem)
        exit(OVERFLOW);
    ElemType *pa, *pb, *pa_last, *pb_last, *pc;
    pa = La.elem, pb = Lb.elem, pa_last = La.elem + La.length - 1, pb_last = Lb.elem + Lb.length - 1, pc = Lc.elem;
    while (pa <= pa_last && pb <= pb_last)
    {
        if (*pa <= *pb)
            *pc++ = *pa++;
        else
            *pc++ = *pb++;
    }
    while (pa <= pa_last)
    {
        *pc++ = *pa++;
    }
    while (pb <= pb_last)
    {
        *pc++ = *pb++;
    }
}
void ReverseSqList(SqList &L )//反转顺序组
{
	ElemType k;
	for(int i=0;i<L.length/2;i++)
	{
		k=L.elem[i];
		L.elem[i]=L.elem[L.length-1-i];
		L.elem[L.length-1-i]=k;
	}
}
int main()
{
	SqList L;
	InitList_Sq(L);
	strcpy(L.elem, "ajcniydu");
	L.length = 8;
	printf("原来的字符串：\n");
	display(L);
	ListInsert_Sq(L, 3, 'p');
	printf("插入p到第三个位置：\n");
	display(L);
	ListDelete_Sq(L, 3);
	printf("删除第三个位置的元素：\n");
	display(L);
	ReverseSqList(L);
} 


