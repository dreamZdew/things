#include <iostream>
#include<vector>
using namespace std;

constexpr int VERTEX_NUM = 2500;
constexpr int EDGE_NUM = 6200;
constexpr int INF = 1000;



	int vertexnum;                            //节点数
	int edgenum;                              //边数



int dis[VERTEX_NUM];

int main()
{
	int s, t;
	cin >> vertexnum >> edgenum >> s >> t;
	vector< vector<int> > Matrix(vertexnum+1, vector<int>(vertexnum+1, 0));
	

	for (int i = 1; i <= vertexnum; i++)
		for (int j = 1; j <= vertexnum; j++)
			if (i == j)
				Matrix[i][j] = 0;
			else
				Matrix[i][j] = INF;

	for (int i = 1; i <= edgenum; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		if (w < Matrix[u][v])
		{
			Matrix[u][v] = w;
			Matrix[v][u] = w;
		}
	}
	int visited[VERTEX_NUM] = { 0 };
	visited[s] = 1;
	dis[s] = 0;
	for (int i = 1; i <= vertexnum; i++)
		dis[i] = Matrix[s][i];//s到i的距离初始化
	for (int i = 1; i <= vertexnum; i++)
	{
		int min = INF;
		int number = s;
		for (int j = 1; j <= vertexnum; j++)
		{
			if (visited[j] == 0 && min > dis[j])
			{
				min = dis[j];
				number = j;
			}
		}
		visited[number] = 1;
		for (int j = 1; j <= vertexnum; j++)
			if (dis[j] > dis[number] + Matrix[number][j])
				dis[j] = dis[number] + Matrix[number][j];

	}
	
	cout << dis[t] << endl;
}
