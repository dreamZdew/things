#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VERTEX_NUM 12
typedef struct EdgeNode
{
    int adjvex;            //与节点相连的节点序号
    struct EdgeNode *next; //下一个序号
} EdgeNode;
typedef struct
{
    char data[3];        //节点标识
    EdgeNode *firstedge; //每个节点的邻接表表头指针
} VNode, AdjList[VERTEX_NUM];
typedef struct
{
    AdjList adjList; //邻接表
    int vexnum, edgenum;
} Graph;
int main()
{
int k; //图种类标识
    printf("输入无向图1还是有向图2:\n");
    scanf("%d", &k);
    Graph A;
    EdgeNode *p, *q;
    int a, b;
    printf("输入节点数、边数：\n");
    scanf("%d %d", &(A.vexnum), &(A.edgenum));
    printf("输入节点标识：\n");
    for (int i = 0; i < A.vexnum; i++)
    {
        scanf("%s", A.adjList[i].data);
        A.adjList[i].firstedge = NULL;
    }
    if (k == 1)
    {
        printf("输入边：\n");
        for (int i = 0; i < A.edgenum ; i++)
        {
            scanf("%d %d", &a, &b);
            p = (EdgeNode *)malloc(sizeof(EdgeNode));
            p->adjvex = b;
            p->next = A.adjList[a].firstedge;
            A.adjList[a].firstedge = p;
            q = (EdgeNode *)malloc(sizeof(EdgeNode));
            q->adjvex = a;
            q->next = A.adjList[b].firstedge;
            A.adjList[b].firstedge = q;
        }
    }
    else if (k == 2)
    {
        printf("输入边：\n");
        for (int i = 0; i < A.edgenum; i++)
        {
            scanf("%d %d", &a, &b);
            p = (EdgeNode *)malloc(sizeof(EdgeNode));
            p->adjvex = b;
            p->next = A.adjList[a].firstedge;
            A.adjList[a].firstedge = p;
        }
    }
    printf("显示输入：\n");
    for (int i = 0; i < A.vexnum; i++)
    {
        EdgeNode *p = A.adjList[i].firstedge;
        printf("%s: ", A.adjList[i].data);
        while (p)
        {
            printf("%d ", p->adjvex);
            p = p->next;
        }
        printf("\n");
    }
}
/*   
    1
    8 9
    v0 v1 v2 v3 v4 v5 v6 v7
    0 1
    0 2
    1 3
    1 4
    2 5
    2 6
    3 7
    4 7
    5 6
*/
/*   
    2
    4 4
    v0 v1 v2 v3
    0 1
    0 2
    2 3
    3 0
*/
