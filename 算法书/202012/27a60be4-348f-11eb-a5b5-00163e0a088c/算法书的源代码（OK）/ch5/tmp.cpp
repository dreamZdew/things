#include <stdio.h>
#include <queue>
using namespace std;
#define MAX 11
#define INF 0x3f3f3f3f
int A[MAX][MAX]={						//一个带权有向图
		{0,1,4,INF,INF},
		{INF,0,INF,1,5},
		{INF,INF,0,INF,1},
		{INF,INF,2,0,3},
		{INF,INF,INF,INF,INF} };
int n=5;
int bestlen=INF;							//最优路径的路径长度
int bestcount=0;							//最优路径的条数
struct NodeType
{	int vno;							//顶点的编号
	int length;							//当前结点的路径长度
	bool operator>(const NodeType &s) const	//重载>关系函数
	{	return length>s.length;  }	//length越小越优先
};
void solve(int s,int t)					//求最短路径问题
{	NodeType e,e1;					//定义2个结点
	priority_queue<NodeType,vector<NodeType>,greater<NodeType> > qu; //定义一个队列qu
	e.vno=s;							//构造根结点
	e.length=0;
	qu.push(e);							//根结点进队
	while (!qu.empty())					//队不空循环
	{	e=qu.top(); qu.pop();				//出队结点e作为当前结点
		if (e.vno==t)						//e是一个叶结点
		{	if (e.length<bestlen)			//比较找最优解
			{	bestcount=1;
				bestlen=e.length;			//保存最短路径长度
			}
			else if (e.length==bestlen)
				bestcount++;
		}
		else							//e不是叶结点
		{	for (int j=0; j<n; j++)			//检查e的所有相邻顶点
				if (A[e.vno][j]!=INF && A[e.vno][j]!=0)  //顶点e.vno到顶点j有边
				{	if (e.length+A[e.vno][j]<bestlen)	  //剪枝
					{	e1.vno=j;
						e1.length=e.length+A[e.vno][j];
						qu.push(e1);	 //有效子结点e1进队
					}
				}
		}
	}
}
int main()
{	int s=0,t=4;
	solve(s,t);
	if (bestcount==0)
		printf("%d到%d没有路径\n",s,t);
	else
	{	printf("%d到%d存在路径\n",s,t);
		printf("   最短路径长度=%d,条数=%d\n", bestlen,bestcount);
		//输出：5 3
	}
	return 0;
}

