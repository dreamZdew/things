#include <iostream>
using namespace std;
constexpr int VERTEX_NUM = 30000;
constexpr int INF = 15000;

int dis[VERTEX_NUM];

typedef struct EdgeNode
{
    int weight = INF;      //权
    int adjvex;            //与节点相连的节点序号
    struct EdgeNode *next; //下一个序号
} EdgeNode;
typedef struct
{
    EdgeNode *firstedge; //每个节点的邻接表表头指针
} VNode, AdjList[VERTEX_NUM];
typedef struct
{
    AdjList adjList; //邻接表
    int vexnum, edgenum;
} Graph;
Graph A;

int nodedistance(int a, int b)
{
    if (a == b)
        return 0;
    int t = INF;
    EdgeNode *p = A.adjList[a].firstedge;
    while (p)
    {
        if (p->adjvex == b && p->weight < t)
            t = p->weight;
        p = p->next;
    }
    return t;
}

int main()
{

    EdgeNode *p, *q;
    int u, v, w;
    int s, t;

    cin >> A.vexnum >> A.edgenum >> s >> t;
    for (int i = 1; i <= A.vexnum; i++) //节点标识
    {
        A.adjList[i].firstedge = nullptr;
    }

    for (int i = 1; i <= A.edgenum; i++)
    {
        cin >> u >> v >> w;
        p = new EdgeNode;
        p->adjvex = v;
        p->weight = w;
        p->next = A.adjList[u].firstedge;
        A.adjList[u].firstedge = p;
        q = new EdgeNode;
        q->adjvex = u;
        q->weight = w;
        q->next = A.adjList[v].firstedge;
        A.adjList[v].firstedge = q;
    }

    int visited[VERTEX_NUM] = {0};
    visited[s] = 1;

    for (int i = 1; i <= A.vexnum; i++)
        dis[i] = nodedistance(s, i); // s到i的距离初始化
    dis[s] = 0;

    for (int i = 1; i <= A.vexnum; i++)
    {
        int min = INF;
        int number = s;
        for (int j = 1; j <= A.vexnum; j++)
        {
            if (visited[j] == 0 && min > dis[j])
            {
                min = dis[j];
                number = j;
            }
        }
        visited[number] = 1;
        for (int j = 1; j <= A.vexnum; j++)
            if (dis[j] > dis[number] + nodedistance(number, j))
                dis[j] = dis[number] + nodedistance(number, j);
    }
    cout << dis[t] << endl;
}
