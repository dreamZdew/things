#include <stdio.h>
#include <stdlib.h>
#define VERTEX_NUM 6
typedef struct
{
    char adj;
    char *info;
} ArcCell, AdjMatrix[VERTEX_NUM][VERTEX_NUM];
typedef struct
{
    char vexs[VERTEX_NUM][3];
    AdjMatrix arcs;
    int vexnum, arcnum;
} MGraph;
typedef struct
{
    char adjvex;
    int lowcost;
} closedge[VERTEX_NUM];
closedge theclose;
int minimun(MGraph G, closedge close)
{
    int min = 10000;
    int min_i = -1;
    for (int i = 0; i < G.vexnum; i++)
    {
        if (close[i].lowcost > 0 && close[i].lowcost < min)
        {
            min = close[i].lowcost;
            min_i = i;
        }
    }
    return min_i;
}
void miniSpanTreePrim(MGraph G, int k)
{

    for (int i = 0; i < G.vexnum; i++)
    {
        if (i != k)
        {
            theclose[i].adjvex = k;
            theclose[i].lowcost = G.arcs[k][i].adj;
        }
    }
    theclose[k].lowcost = 0;
    printf("%s ", G.vexs[k]);
    for (int i = 1; i < G.vexnum; i++)
    {
        k = minimun(G, theclose);
        printf("%s ", G.vexs[k]);

        theclose[k].lowcost = 0;

        for (int j = 0; j < G.vexnum; j++)
        {
            if (G.arcs[k][j].adj < theclose[j].lowcost)
            {
                theclose[j].adjvex = k;
                theclose[j].lowcost = G.arcs[k][j].adj;
            }
        }
    }
    printf("\n");
}
int main()
{
    MGraph G;
    G.vexnum = VERTEX_NUM;
    G.arcnum = 10;
    for (int i = 0; i < VERTEX_NUM; i++)
    {
        scanf("%s", &(G.vexs[i]));
    }
    for (int i = 0; i < VERTEX_NUM; i++)
        for (int j = 0; j < VERTEX_NUM; j++)
        {

            scanf("%d", &(G.arcs[i][j]));
        }
    miniSpanTreePrim(G, 0);
}
/*
v0 v1 v2 v3 v4 v5
 10000 6 1 5 10000 10000
 6 10000 5 10000 3 10000
 1 5 10000 5 6 4
 5 10000 5 10000 10000 2
 10000 3 6 10000 10000 6
 10000 10000 4 2 6 10000
 */