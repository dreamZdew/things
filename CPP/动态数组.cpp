#include<stdio.h>
#include<stdlib.h>
typedef  char ElemType;
struct BiNode
{
	ElemType data;
	struct BiNode *lch,*rch;
};
void input(BiNode *T);
void previsit(BiNode *T);
void midvisit(BiNode *T);
void lastvisit(BiNode *T);

int main()
{
	struct BiNode *T;
	input(T);//-+a..*b..-c..d../e..f..
	previsit(T);
}


void input(BiNode *T)
{
	char ch;
	BiNode *p=T;
	ch=getchar();
	if(ch=='.')
		p=NULL;
	else
	{
		p=(BiNode *)malloc(sizeof(BiNode));
		p->data=ch;
		input(p->lch);
		input(p->rch);
	}

}

void previsit(struct BiNode *T)
{
	if(T)
	{
		printf("%c",T->data);
		previsit(T->lch);
		previsit(T->rch);
	}
}
void midvisit(BiNode *T)
{
	if(T)
	{
		midvisit(T->lch);
		printf("%c",T->data);
		midvisit(T->rch);
	}

}
void lastvisit(BiNode *T)
{
	if(T)
	{
		lastvisit(T->lch);
		lastvisit(T->rch);
		printf("%c",T->data);
	}
}
