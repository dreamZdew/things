#include<iostream>
using namespace std;
#define VERTEX_NUM 1000
int dp[1000] = { 0 };
typedef struct EdgeNode
{
    int adjvex;            //与节点相连的节点序号
    struct EdgeNode* next; //下一个序号
} EdgeNode;
typedef struct VNode
{
    int beforenum = 0;
    int data;            //节点标识
    EdgeNode* firstedge; //每个节点的邻接表表头指针
} VNode, AdjList[VERTEX_NUM];
typedef struct Graph
{
    AdjList adjList; //邻接表
    int vexnum, edgenum;
} Graph;
int main()
{
    
    int t1, t2;
    while (cin>>t1>>t2)
    {
        Graph A;
        A.vexnum = t1;
        A.edgenum = t2;
        for (int i = 1; i <= A.vexnum; i++)
        {
            A.adjList[i].data = i;
            A.adjList[i].firstedge = NULL;
        }
        EdgeNode* p = NULL;
        int a, b;
        for (int i = 0; i < A.edgenum; i++)
        {
            cin>>a>>b;
            A.adjList[b].beforenum++;
            p = new EdgeNode;
            p->adjvex = b;
            p->next = A.adjList[a].firstedge;
            A.adjList[a].firstedge = p;
        }

        for (int i = 1; i <= A.vexnum; i++)
        {
            if (A.adjList[i].beforenum == 0)
                dp[i] = 1;
            else
                dp[i] = 0;
        }

        int cutvexnum = A.vexnum;
        for (int i = 1; cutvexnum; i++)
        {
            EdgeNode* p = A.adjList[i].firstedge;

            if (A.adjList[i].beforenum == 0)
            {
                A.adjList[i].beforenum = -1;
                cutvexnum--;
                while (p)
                {
                    if (dp[p->adjvex] < dp[i] + 1)
                        dp[p->adjvex] = dp[i] + 1;
                    A.adjList[p->adjvex].beforenum--;
                    p = p->next;
                }
            }
            if (i == A.vexnum && cutvexnum != 0)
                i = 1;
        }
        int max = dp[1];
        for (int i = 1; i <= A.vexnum; i++)
        {
            if (dp[i] > max)
                max = dp[i];
        }
        printf("%d\n", max);
    }
}

/*
10 16
1 2
1 4
1 10
2 3
2 5
4 3
4 5
4 8
6 8
7 6
7 9
8 5
9 8
10 6
10 7
10 9
*/
