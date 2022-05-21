#include <stdio.h>
//邻接矩阵
#define VERTEX_NUM 8
#define EDGE_NUM 9

#define MAXSIZE 10
typedef int QElemType;
typedef int Status;
typedef struct
{
    int data[MAXSIZE];
    int front;
    int rear;
} SqQueue;

char InitQueue(SqQueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
    return 1;
}
int QueueLength(SqQueue Q)
{
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}
Status EnQueue(SqQueue *Q, QElemType e)
{
    if ((Q->rear + 1) % MAXSIZE == Q->front)
        return 0;
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    return 1;
}
Status DeQueue(SqQueue *Q, QElemType *e)
{
    if (Q->front == Q->rear)
        return 0;
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    return 0;
}
typedef struct
{
    char adj[3]; //节点标识
} Vertex;
typedef struct
{
    int Matrix[VERTEX_NUM][VERTEX_NUM]; //邻接矩阵
    int vertexnum;                      //节点数
    int edgenum;                        //边数
    Vertex vertex[VERTEX_NUM];          //节点数组

} Graph;

int visited[VERTEX_NUM] = {0};
void DFS(Graph A, int v)
{
    visited[v] = 1;
    printf("%s ", A.vertex[v].adj);
    for (int i = 0; i < VERTEX_NUM; i++)
    {
        if (A.Matrix[v][i] == 1 && visited[i] == 0)
            DFS(A, i);
    }
}
void BFS(Graph A)
{
    int *e;
    SqQueue Q;
    InitQueue(&Q);
    for (int v = 0; v < VERTEX_NUM; v++)
    {
        if (visited[v] == 0)
        {
            visited[v] = 1;
            printf("%s ", A.vertex[v].adj);
            EnQueue(&Q, v);
            while (QueueLength(Q) != 0)
            {
                DeQueue(&Q, e);
                for (int i = 0; i < VERTEX_NUM; i++)
                {
                    if (A.Matrix[*e][i] == 1)
                    {
                        if (visited[i] == 0)
                        {
                            visited[i] = 1;
                            printf("%s ", A.vertex[i].adj);
                            EnQueue(&Q, i);
                        }
                    }
                }
            }
        }
    }
}
int main()
{
    Graph A;
    printf("输入节点数、边数：\n");
    scanf("%d %d", &A.vertexnum, &A.edgenum);
    printf("输入邻接矩阵：\n");
    for (int i = 0; i < A.vertexnum; i++)
        for (int j = 0; j < A.vertexnum; j++)
            scanf("%d", &A.Matrix[i][j]); //输入邻接矩阵
    printf("输入节点标识：\n");
    for (int i = 0; i < A.vertexnum; i++)
        scanf("%s", A.vertex[i].adj); //输入每个节点的标识
    printf("遍历图：\n");
    DFS(A, 0);
}
/*  无向图输入
    8 9
    0 1 1 0 0 0 0 0
    1 0 0 1 1 0 0 0
    1 0 0 0 0 1 1 0
    0 1 0 0 0 0 0 1
    0 1 0 0 0 0 0 1
    0 0 1 0 0 0 1 0
    0 0 1 0 0 1 0 0
    0 0 0 1 1 0 0 0
    v0 v1 v2 v3 v4 v5 v6 v7
*/
/*  有向图输入
    4 4
    0 1 1 0
    0 0 0 0
    0 0 0 1
    1 0 0 0
    v0 v1 v2 v3
*/