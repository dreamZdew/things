#include <stdio.h>
#include <stdlib.h>
#define DEFAULT 10000
int Hash(int k)
{
    return k % 11;
}
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    int count;
    int size;
    Node first[30];
} HashTable;
int Input(HashTable *H, int k)
{

    int p = Hash(k);
    if (H->first[p].data == DEFAULT)
    {
        H->first[p].data = k;
        return 1;
    }
    else
    {
        Node *q = (Node *)malloc(sizeof(Node));
        q->data = k;
        Node *info = &(H->first[p]);
        q->next = info->next;
        info->next = q;
        return 1;
    }
    return 0;
}
int Search(HashTable H, int k, int *c)
{

    *c = 1;
    int p = Hash(k);
    Node *info = &(H.first[p]);
    while (info->data != k)
    {
        info = info->next;
        (*c)++;
        if (*c > 12)
            return 0;
    }
    if (k == info->data)
        return 1;
}
int main()
{
    HashTable H;
    H.count = 9;
    H.size = 11;
    for (int i = 0; i < 30; i++) //初始化哈希表为DEFAULT值
    {
        H.first[i].data = DEFAULT;
        H.first[i].next = NULL;
    }
    int *c = NULL; //  c标记查找次数
    c = (int *)malloc(sizeof(int));
    double ASL = 0;
    for (int i = 0; i < H.count; i++)
    {
        int k;
        // 19 1 23 14 55 68 11 82 36
        scanf("%d", &k);
        Input(&H, k);
        Search(H, k, c);
        printf("%2d: 寻址次数：%d\n", k, *c);
        ASL += *c;
    }
    printf("ASL: %.2lf\n", ASL / H.count);
    for (int i = 0; i < H.count; i++)
    {
        Node *p = &(H.first[i]);
        if (H.first[i].data != DEFAULT)
        {
            printf("%d: ", i);
            while (p)
            {
                printf("%d ", p->data);
                p = p->next;
            }
            printf("\n");
        }
    }
}