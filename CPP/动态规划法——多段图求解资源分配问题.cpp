#include <stdio.h>
#define VERTEX_NUM 30
#define EDGE_NUM 30
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
int main()
{
    Graph A;
    printf("输入节点数、边数：\n");
    scanf("%d %d", &A.vertexnum, &A.edgenum);
    printf("输入邻接矩阵：\n");
    for (int i = 1; i <= A.vertexnum; i++)
        for (int j = 1; j <= A.vertexnum; j++)
            scanf("%d", &A.Matrix[i][j]); //输入邻接矩阵
    printf("输入节点标识：\n");
    for (int i = 1; i <= A.vertexnum; i++)
        scanf("%s", A.vertex[i].adj); //输入每个节点的标识
    printf("显示输入：\n");
    for (int i = 1; i <= A.vertexnum; i++)
    {
        printf("%s ", A.vertex[i].adj);
        for (int j = 1; j <= A.vertexnum; j++)
            printf("%d ", A.Matrix[i][j]);
        printf("\n");
    }
    //输入邻接矩阵
    int dp[VERTEX_NUM]; //节点到A的最长距离
    int road[VERTEX_NUM];
    road[1] = 0; //前一个节点
    for (int i = 1; i <= A.vertexnum; i++)
    {
        dp[i] = A.Matrix[1][i];
        if (A.Matrix[1][i] != -1)
            road[i] = 1;
    }
    for (int i = 1; i <= A.vertexnum; i++)
    {
        for (int j = 1; j <= A.vertexnum; j++)
        {
            if (dp[i] + A.Matrix[i][j] > dp[j] && A.Matrix[i][j] != -1)
            {
                dp[j] = dp[i] + A.Matrix[i][j];
                road[j] = i;
            }
        }
    }
    for (int i = 1; i <= A.vertexnum; i++)
        printf("序号：%d 到A点最长距离：%d 前一步：%d\n", i, dp[i], road[i]);
}
/*
14 28
0 4 4 5 8 -1 -1 -1 -1 -1 -1 -1 -1 -1
-1 0 -1 -1 -1 3 5 6 7 -1 -1 -1 -1 -1
-1 -1 0 -1 -1 -1 3 5 6 -1 -1 -1 -1 -1
-1 -1 -1 0 -1 -1 -1 3 5 -1 -1 -1 -1 -1
-1 -1 -1 -1 0 -1 -1 -1 3 -1 -1 -1 -1 -1
-1 -1 -1 -1 -1 0 -1 -1 -1 5 6 8 8 -1
-1 -1 -1 -1 -1 -1 0 -1 -1 -1 5 6 8 -1
-1 -1 -1 -1 -1 -1 -1 0 -1 -1 -1 5 6 -1
-1 -1 -1 -1 -1 -1 -1 -1 0 -1 -1 -1 5 -1
-1 -1 -1 -1 -1 -1 -1 -1 -1 0 -1 -1 -1 8
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 0 -1 -1 7
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 0 -1 4
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 0 2
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 0
A B1 B2 B3 B4 C1 C2 C3 C4 D1 D2 D3 D4 E
*/
