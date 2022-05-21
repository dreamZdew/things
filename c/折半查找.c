#include <stdio.h>
typedef struct
{
    int elem[30];
    int length;

} SSTable;
int Search_half(SSTable ST, int key)
{
    int low = 1, high = ST.length;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (key == ST.elem[mid])
            return mid;
        else if (key < ST.elem[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return 0;
}
// 5 13 19 21 37 56 64 75 80 88 92
int main()
{
    SSTable ST;
    ST.length = 11;
    for (int i = 1; i <= ST.length; i++)
        scanf("%d", &ST.elem[i]);
    printf("%d", Search_half(ST, 64));
}