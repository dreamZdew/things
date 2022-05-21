#include <stdio.h>
#include <stdlib.h>
typedef char ElemType;
struct PNode
{
    ElemType data;
    int parent;
};
struct Ptree
{
    PNode nodes[100];
    int r, n;
};
int main()
{
    Ptree T;
    int n; //总结点数
    scanf("%d", &n);
    int k = n;
    for (; n; n--)
    {
        int nn, par, ch;
        scanf("%d  %c %d", &nn, &ch, &par);
        /*
       9
       0 A -1 
       1 B 0
       2 C 0
       3 D 1
       4 E 1
       5 F 2
       6 G 4
       7 H 4
       8 I 4
      */
        T.nodes[nn].data = ch;
        T.nodes[nn].parent = par;
    }
    for (int i = 0; i < k; i++)
    {
        printf("%c", T.nodes[i].data);
    }
}
