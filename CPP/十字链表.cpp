#include <stdio.h>
#include <stdlib.h>
struct OLNode
{
    int i, j;
    int e;
    struct OLNode *right, *down;
};
struct CrossList
{
    struct OLNode *rhead, *chead;
    int mu, nu, tu;
};

void CreateSM(CrossList &M)
{
    scanf("%d %d %d", &M.mu, &M.nu, &M.tu);
    M.rhead = (OLNode *)malloc((M.mu + 1) * sizeof(OLNode));
    M.chead = (OLNode *)malloc((M.nu + 1) * sizeof(OLNode));
    struct OLNode *p = M.rhead;

    for (int i = 0; i < M.mu; i++)
    {
        p->down = (OLNode *)malloc(sizeof(OLNode));
        p->right = NULL;
        p = p->down;
    }
    struct OLNode *q = M.chead;

    for (int i = 0; i < M.nu; i++)
    {
        q->right = (OLNode *)malloc(sizeof(OLNode));
        q->down = NULL;
        q = q->right;
    }
    //此时q与p都是最后一个指针后面的指针

    int i, j, e;
    for (scanf("%d %d %d", &i, &j, &e); i != 0; scanf("%d %d %d", &i, &j, &e))
    {
        struct OLNode *info, *ptr, *qtr; //info为建立的指针 ptr用来指示头指针指定的位置
        info = (OLNode *)malloc(sizeof(OLNode));
        info->i = i;
        info->j = j;
        info->e = e;
        ptr = M.rhead;
        for (int temp = 1; temp < i; temp++)

            ptr = ptr->down;

        if (ptr->right == NULL || ptr->right->j > j)
        {
            info->right = ptr->right;
            ptr->right = info;
        }
        else
        {
            for (qtr = ptr; (qtr->right) && qtr->right->j < j; qtr = qtr->right)
                ;
            info->right = qtr->right;
            qtr->right = info;
        }
        ptr = M.chead;
        for (int temp = 1; temp < j; temp++)
            ptr = ptr->right;
        if (ptr->down == NULL || ptr->down->i > i)
        {
            info->down = ptr->down;
            ptr->down = info;
        }
        else
        {
            for (qtr = ptr; (qtr->down) && qtr->down->i < i; qtr = qtr->down)
                ;
            info->down = qtr->down;
            qtr->down = info;
        }
    }
}
void output(CrossList M)
{
    struct OLNode *p = M.rhead, *q = M.chead, *line = M.rhead;
    printf("\n");
    int i, j;
    for (i = 1; i <= M.mu; i++)
    {
        for (j = 1; j <= M.nu; j++)
        {
            if (p->right != NULL && q->down != NULL && p->right->i == i && p->right->j == j)
            {
                printf("%4d", p->right->e);
                q = q->right;
                p = p->right;
            }
            else
            {
                printf("%4d", 0);
                q = q->right;
            }
        }
        printf("\n");
        q = M.chead;
        p = line->down;
        line = line->down;
    }
    printf("\n");
}
int main()
{
    CrossList M;
    CreateSM(M);
    output(M);
    /*
    3 4 4
    1 1 3
    1 4 5
    2 2 -1
    3 1 2
    0 0 0
    */
}