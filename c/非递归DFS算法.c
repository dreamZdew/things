#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int *base;
    int *top;
    int stacksize;
} Sqstack;
int InitStack(Sqstack *S) //初始化
{
    S->base = (int *)malloc(100 * sizeof(int));
    if (!S->base)
        exit(-2);
    S->top = S->base;
    S->stacksize = 100;
    return 1;
}
int Push(Sqstack *S, int e) //入栈
{
    if (S->top - S->base >= S->stacksize)
    {
        S->base = (int *)realloc(S->base, (S->stacksize + 10) * sizeof(int));
        if (!S->base)
            exit(-2);
        S->top = S->base + S->stacksize;
        S->stacksize += 10;
    }
    *S->top = e;
    *S->top++;
    return 1;
}
int Pop(Sqstack *S) //出栈
{
    if (S->base == S->top)
        exit(-2);
    *S->top--;
    return 1;
}
int GetTop(Sqstack *S) //返回栈顶元素
{
    int e;
    if (S->top == S->base)
        return 0;
    e = *(S->top - 1);
    return e;
}

#define VERTEX_NUM 8
#define EDGE_NUM 9
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
void DFS_Non_recursive(Graph A, int v, Sqstack *S);
int main()
{
    Sqstack S;
    InitStack(&S);
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
    DFS_Non_recursive(A, 0, &S);
}
int visited[VERTEX_NUM] = {0};
void DFS_Non_recursive(Graph A, int v, Sqstack *S)
{
    Push(S, v);                //首先把顶点进栈
    printf("v%d ", GetTop(S)); //访问顶点
    int i = v;
    visited[v] = 1;
    for (int j = i;; j++)
    {
        if (A.Matrix[i][j] == 1 && visited[j] == 0)
        {
            visited[j] = 1; //遇到未访问的i的邻接节点，访问并入栈
            Push(S, j);
            printf("v%d ", GetTop(S));
            i = j;
            j = 0; //查找j的邻接点
        }
        if (j == A.vertexnum) //如果序号为j的节点不存在
        {
            if (v == GetTop(S)) //若栈内顶点和最开始的v相同，遍历结束
                break;
            Pop(S);     //出栈
            i = GetTop(S); //寻找栈顶元素的邻接点
            j = 0;
        }
    }
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
