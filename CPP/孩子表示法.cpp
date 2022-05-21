#include<stdio.h>
#include<stdlib.h>
struct CNode
{
    int child;
    CNode *next;
};
struct Cbox
{
    char data;
    CNode *firstchild;
};
struct Ctree
{
    Cbox nodes[100];
    int n,r;
};
int main()
{
    Ctree T;
    int n; //总结点数
    scanf("%d", &n);
    int k = n;
    for (; n; n--)
    {
        int nn, child, ch;
        scanf("%d  %c %d", &nn, &ch, &child);
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

