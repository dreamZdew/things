#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int* base;
    int* top;
    int stacksize;
} Sqstack;
int InitStack(Sqstack* S) //初始化
{
    S->base = (int*)malloc(100 * sizeof(int));
    if (!S->base)
        exit(-2);
    S->top = S->base;
    S->stacksize = 100;
    return 1;
}
int Push(Sqstack* S, int e) //入栈
{
    if (S->top - S->base >= S->stacksize)
    {
        S->base = (int*)realloc(S->base, (S->stacksize + 10) * sizeof(int));
        if (!S->base)
            exit(-2);
        S->top = S->base + S->stacksize;
        S->stacksize += 10;
    }
    *S->top = e;
    *S->top++;
    return 1;
}
int Pop(Sqstack* S) //出栈
{
    if (S->base == S->top)
        exit(-2);
    *S->top--;
    return 1;
}
int GetTop(Sqstack* S) //返回栈顶元素
{
    int e;
    if (S->top == S->base)
        return 0;
    e = *(S->top - 1);
    return e;
}

#define VERTEX_NUM 12
typedef struct EdgeNode
{
    int adjvex;            //与节点相连的节点序号
    struct EdgeNode* next; //下一个序号
} EdgeNode;
typedef struct
{
    char data[3];        //节点标识
    EdgeNode* firstedge; //每个节点的表头指针
} VNode, AdjList[VERTEX_NUM];
typedef struct
{
    AdjList adjList; //邻接表
    int vexnum, edgenum;
} Graph;

int visited[VERTEX_NUM] = { 0 };
void DFS(Graph A, int v)
{
    visited[v] = 1;
    printf("%s ", A.adjList[v].data);
    EdgeNode* p = A.adjList[v].firstedge;
    while (p)
    {
        if (visited[p->adjvex] == 0)
            DFS(A, p->adjvex);
        p = p->next;
    }
}

void DFS_Non_recursive(Graph A, int v, Sqstack* S)
{
   
    Push(S, v);                //首先把顶点进栈
    printf("v%d ", GetTop(S)); //访问顶点
    visited[v] = 1;
    EdgeNode* p = A.adjList[v].firstedge;
    for (;; p = p->next)
    {
        if (p==NULL) //如果节点不存在
        {
            if (v == GetTop(S)) //若栈内顶点和最开始的v相同，遍历结束
                break;
            Pop(S);                          //出栈
            p = A.adjList[GetTop(S)].firstedge; //寻找栈顶元素的邻接点
        }
        if (visited[p->adjvex] == 0)
        {
            visited[p->adjvex] = 1; //遇到未访问的i的邻接节点，访问并入栈
            Push(S, p->adjvex);
            printf("v%d ", GetTop(S));
            p = A.adjList[p->adjvex].firstedge;
        }
    }
}

int main()
{

    int k; //图种类标识
    printf("输入无向图1还是有向图2:\n");
    scanf("%d", &k);
    Graph A;
    EdgeNode* p, * q;
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
        for (int i = 0; i < A.edgenum; i++)
        {
            scanf("%d %d", &a, &b);
            p = (EdgeNode*)malloc(sizeof(EdgeNode));
            p->adjvex = b;
            p->next = A.adjList[a].firstedge;
            A.adjList[a].firstedge = p;
            q = (EdgeNode*)malloc(sizeof(EdgeNode));
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
            p = (EdgeNode*)malloc(sizeof(EdgeNode));
            p->adjvex = b;
            p->next = A.adjList[a].firstedge;
            A.adjList[a].firstedge = p;
        }
    }
    printf("显示输入：\n");
    for (int i = 0; i < A.vexnum; i++)
    {
        EdgeNode* p = A.adjList[i].firstedge;
        printf("%s: ", A.adjList[i].data);
        while (p)
        {
            printf("%d ", p->adjvex);
            p = p->next;
        }
        printf("\n");
    } 
}
/*  无向图
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
/*  有向图
    2
    4 4
    v0 v1 v2 v3
    0 1
    0 2
    2 3
    3 0
*/