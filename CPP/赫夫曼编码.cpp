#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char data;
    int weight;
    int parent, lchild, rchild;
} HNode, *HuffmanTree;
typedef char **HuffmanCode;

void Select(HuffmanTree &HT, int ii, int &s1, int &s2)
{
    int m1 = 100, m2 = 100;
    for (int i = 1; i <= ii; i++)
    {
        if (HT[i].weight < m1 && HT[i].parent == 0)
        {
            m2 = m1;
            s2 = s1;
            m1 = HT[i].weight;
            s1 = i;
        }
        else if (HT[i].weight < m2 && HT[i].parent == 0)
        {
            m2 = HT[i].weight;
            s2 = i;
        }
    }
    //printf("%d %d\n", s1, s2);
}

void Huffman(HuffmanTree &HT, HuffmanCode &HC, int *w, char *ww, int n)
{
    if (n <= 1)
        return;
    int m = 2 * n - 1, i;
    HT = (HuffmanTree)malloc((m + 1) * sizeof(HNode));
    HuffmanTree p;
    for (p = HT + 1, i = 1; i <= n; i++, p++, w++, ww++)
    {
        p->data = *ww;
        p->weight = *w;
        p->lchild = 0;
        p->rchild = 0;
        p->parent = 0;
    }
    for (; i <= m; i++, p++)
    {
        p->weight = 0;
        p->lchild = 0;
        p->rchild = 0;
        p->parent = 0;
    }
    for (i = n + 1; i <= m; i++)
    {
        int s1, s2;
        Select(HT, i - 1, s1, s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
    HC = (HuffmanCode)malloc((n + 1) * sizeof(char *));
    char *cd = (char *)malloc(n * sizeof(char));
    cd[n - 1] = '\0';
    for (i = 1; i <= n; i++)
    {
        int start = n - 1;
        for (int c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent)
            if (HT[f].lchild == c)
                cd[--start] = '0';
            else
                cd[--start] = '1';
        HC[i] = (char *)malloc((n - start) * sizeof(char));
        strcpy(HC[i], &cd[start]);
    }
    free(cd);
}
int main()
{
    printf("权 名 编码\n");
    HuffmanTree HT;
    HuffmanCode HC;
    int w[] = {5, 29, 7, 8, 14, 23, 3, 11};
             //a  b   c  d  e   f   g  h
             //1  2   3  4  5   6   7  8
    char ww[] = "abcdefgh";
    int n = 8;
    Huffman(HT, HC, w, ww, n);
    for (int i = 1; i <= 8; i++)
    {
        printf("%2d  %c  ", HT[i].weight, HT[i].data);
        printf("%s\n", HC[i]);
    }
}