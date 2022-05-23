//采用进一步剪枝求解0/1背包问题的算法
#include <stdio.h>
#include <string.h>
#include<algorithm>
using namespace std;
#define MAXN 20					//最多物品数
struct PNode
{
	int no;			//物品编号 
	int w;			//物品重量 
	int v;			//物品价值
	double p;		//单位重量价值
	bool operator<(struct PNode &s)
	{
		return p>s.p;			//用于按p递减排序 
	} 
};
//问题表示
int n=4;						//4种物品
int W=6;						//限制重量为6
struct PNode A[]={{0,0,0},{1,5,4},{2,3,4},{3,2,3},{4,1,1}};
//求解结果表示
int x[MAXN];					//存放最终解
int maxv=0; 					//存放最优解的总价值
int bound(int i,int tw,int tv)	//求上界
{
	i++;
	while (i<=n && tw+A[i].w<=W)
	{
		tw+=A[i].w;
		tv+=A[i].v;
		i++;
	}
	if (i<=n) return tv+(W-tw)*A[i].p;
	else return tv;
}
void dfs(int i,int tw,int tv,int op[]) //求解0/1背包问题
{
	if (i>n)							//找到一个叶子结点
	{	maxv=tv;						//存放更优解
		for (int j=1;j<=n;j++)
			x[j]=op[j];
	}
	else								//尚未找完所有物品
	{	if (tw+A[i].w<=W)  				//左孩子结点剪枝
		{
			op[i]=1;					//选取第i个物品
			dfs(i+1,tw+A[i].w,tv+A[i].v,op);
		}
		op[i]=0;						//不选取第i个物品,回溯
		if (bound(i,tw,tv)>maxv)		//右孩子结点剪枝
			dfs(i+1,tw,tv,op);
	}
}
void dispasolution()					//输出最优解
{
	printf("最佳装填方案是:\n");
	for (int i=1;i<=n;i++)
		if (x[i]==1)
			printf("  选取第%d个物品\n",A[i].no);
	printf("总重量=%d,总价值=%d\n",W,maxv);
}
int main()
{
	int op[MAXN];						//存放临时解
	memset(op,0,sizeof(op));
	for (int i=1;i<=n;i++)
		A[i].p=A[i].v*1.0/A[i].w;

	sort(A+1,A+n+1);
	for(int j=1;j<=n;j++)
		printf("物品%d,w=%d,v=%d\n",A[j].no,A[j].w,A[j].v);
	dfs(1,0,0,op);
	dispasolution();
	return 0;
}
