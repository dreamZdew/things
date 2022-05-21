#include <stdio.h>
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
    printf("显示输入：\n");
    for (int i = 0; i < A.vertexnum; i++)
    {
        printf("%s ", A.vertex[i].adj);
        for (int j = 0; j < A.vertexnum; j++)
            printf("%d ", A.Matrix[i][j]);
        printf("\n");
    }
}
/*   
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
/*   
    4 4
    0 1 1 0
    0 0 0 0
    0 0 0 1
    1 0 0 0
    v0 v1 v2 v3
*/
