#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
constexpr int VERTEX_NUM = 1005;
constexpr int EDGE_NUM = 10005;
constexpr int INF = 2000000000;

vector<int> dis(VERTEX_NUM);

typedef struct EdgeNode
{
    int weight = INF;      //权
    int adjvex;            //与节点相连的节点序号
    struct EdgeNode* next; //下一个序号
} EdgeNode;
typedef struct
{
    EdgeNode* firstedge; //每个节点的邻接表表头指针
} VNode, AdjList[VERTEX_NUM];
typedef struct
{
    AdjList adjList; //邻接表
    int vexnum, edgenum;
} Graph;
Graph A, B;

int nodedistance(int a, int b, Graph T) //直接相邻的距离（模仿邻接矩阵）
{
    if (a == b)
        return 0;
    int t = INF;
    EdgeNode* p = T.adjList[a].firstedge;
    while (p)
    {
        if (p->adjvex == b && p->weight < t)
            t = p->weight;
        p = p->next;
    }
    return t;
}

void dij(int a, Graph T)
{
    int visited[VERTEX_NUM] = { 0 };
    visited[a] = 1;

    for (int i = 1; i <= T.vexnum; i++)
        dis[i] = nodedistance(a, i, T); // a到i的距离初始化
    dis[a] = 0;

    for (int i = 1; i <= T.vexnum; i++)
    {
        int min = INF;
        int number = a;
        for (int j = 1; j <= T.vexnum; j++)
        {
            if (visited[j] == 0 && min > dis[j])
            {
                min = dis[j];
                number = j;
            }
        }
        visited[number] = 1;
        for (int j = 1; j <= T.vexnum; j++)
            if (dis[j] > dis[number] + nodedistance(number, j, T))
                dis[j] = dis[number] + nodedistance(number, j, T);
    }
    return; // a到b的最短距离dis[b]
}
int uu[EDGE_NUM], vv[EDGE_NUM], ww[EDGE_NUM];
int main()
{


    int u, v, w;
    int x;

    cin >> A.vexnum >> A.edgenum >> x;
    B.vexnum = A.vexnum;
    B.edgenum = A.edgenum;
    for (int i = 1; i <= A.vexnum; i++) //节点标识
    {
        A.adjList[i].firstedge = nullptr;
        B.adjList[i].firstedge = nullptr;
    }

    for (int i = 1; i <= A.edgenum; i++) //正向
    {
        cin >> u >> v >> w;
        uu[i] = u;
        vv[i] = v;
        ww[i] = w;
        EdgeNode* p = new EdgeNode;
        p->adjvex = v;
        p->weight = w;
        p->next = A.adjList[u].firstedge;
        A.adjList[u].firstedge = p;
    }

    vector<int> xtotemp;
    xtotemp.push_back(0);
    dij(x, A);
    for (int temp = 1; temp <= A.vexnum; temp++)
        xtotemp.push_back(dis[temp]);

    for (int i = 1; i <= A.edgenum; i++) //反向
    {
        u = vv[i];
        v = uu[i];
        w = ww[i];
        EdgeNode* p = new EdgeNode;
        p->adjvex = v;
        p->weight = w;
        p->next = B.adjList[u].firstedge;
        B.adjList[u].firstedge = p;
    }
    vector<int> temptox;
    temptox.push_back(0);
    dij(x, B);
    for (int temp = 1; temp <= A.vexnum; temp++)
        temptox.push_back(dis[temp]);

    int ans = temptox[1] + xtotemp[1];
    for (int temp = 2; temp <= A.vexnum; temp++)
    {
        if (temptox[temp] + xtotemp[temp] > ans)
            ans = temptox[temp] + xtotemp[temp];
    }

    cout << ans << endl;
}