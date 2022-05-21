// 12 5 20 3 8 17 21 14 18 22 13
#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int bf;
    int data;
    struct Node *lch;
    struct Node *rch;
} Node, *BSTree;

void R_Rotate(BSTree p)
{
    Node *lc=p->lch;
    p->lch=lc->rch;
    lc->rch=p;
    p=lc;
}
void L_Rotate(BSTree p)
{
    Node *rc=p->rch;
    p->rch=rc->lch;
    rc->lch=p;
    p=rc;
}




int Input(BSTree B, int k)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = k;
}

int main()
{
    BSTree B;
    B->lch = NULL;
    B->rch = NULL;
}
