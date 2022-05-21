#include <iostream>
using namespace std;
#define VERTEX_NUM 2500
typedef struct EdgeNode
{
    int weight;
    int adjvex;            //与节点相连的节点序号
    struct EdgeNode *next; //下一个序号
} EdgeNode;
typedef struct
{
    int data;            //节点标识
    EdgeNode *firstedge; //每个节点的邻接表表头指针
} VNode, AdjList[VERTEX_NUM];
typedef struct
{
    AdjList adjList; //邻接表
    int vexnum, edgenum;
} Graph;
int main()
{
    Graph G;
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    G.vexnum = n;
    G.edgenum = m;
    for (int i = 0; i < G.vexnum; i++)
    {
        G.adjList[i].data = i;
        G.adjList[i].firstedge = NULL;
    }
    EdgeNode *p, *q;
    for (int i = 0; i < G.edgenum; i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        if (G.adjList[a].firstedge == NULL || G.adjList[a].firstedge->weight > c)
        {
            p = (EdgeNode *)malloc(sizeof(EdgeNode));
            p->adjvex = b;
            p->weight = c;
            p->next = G.adjList[a].firstedge;
            G.adjList[a].firstedge = p;
            q = (EdgeNode *)malloc(sizeof(EdgeNode));
            q->adjvex = a;
            q->weight = c;
            q->next = G.adjList[b].firstedge;
            G.adjList[b].firstedge = q;
        }
    }




}