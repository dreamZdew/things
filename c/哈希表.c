#include <stdio.h>
#include <stdlib.h>
#define DEFAULT 10000
int Hash(int k)
{
    return k % 11;
}
typedef struct
{
    int elem[30];
    int count;
    int size;

} HashTable;
int Search(HashTable H, int k, int *p, int *c)
{

    *c = 1;
    *p = Hash(k);
    while (H.elem[*p] != DEFAULT && H.elem[*p] != k)
    {
        (*p)++;
        (*c)++;
        if (*p > H.size)
            *p = 0;
        if (*c > 12)
            return 0;
    }
    if (k == H.elem[*p])
        return 1;
}
int Input(HashTable *H, int k)
{

    int p = Hash(k);
    if (H->elem[p] == DEFAULT)
    {
        H->elem[p] = k;
        return 1;
    }
    else
    {
        for (int i = 0; i < H->size; i++)
        {
            p++;
            if (p > H->size)
                p = 0;
            if (H->elem[p] == DEFAULT)
            {
                H->elem[p] = k;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    HashTable H;
    H.count = 9;
    H.size = 11;
    for (int i = 0; i < H.count; i++) //初始化哈希表为DEFAULT值
        H.elem[i] = DEFAULT;
    int *p = NULL, *c = NULL; // p标记存储位置 c标记查找次数
    c = (int *)malloc(sizeof(int));
    p = (int *)malloc(sizeof(int));
    double ASL = 0;
    for (int i = 0; i < H.count; i++)
    {
        int k;
        // 19 1 23 14 55 68 11 82 36
        scanf("%d", &k);
        Input(&H, k);
        Search(H, k, p, c);
        printf("%2d: 储存地址：%d 寻址次数：%d\n", k, *p, *c);
        ASL += *c ;
    }
    printf("ASL: %.2lf\n", ASL / H.count);
    for (int i = 0; i < H.count; i++)
        printf("%d ", H.elem[i]);
}