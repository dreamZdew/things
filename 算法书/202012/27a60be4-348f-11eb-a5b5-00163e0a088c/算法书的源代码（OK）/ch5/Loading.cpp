#include <stdio.h>
#include <string.h>
#define MAXN 20						//最多集装箱个数
//问题表示
int w[]={0,5,2,6,4,3};				//各集装箱重量,不用下标0的元素
int	n=5,W=10;
int maxw=0;							//存放最优解的总重量
int x[MAXN];						//存放最优解向量
void dfs(int i,int tw,int rw,int op[]) //考虑第i个集装箱
{
	if (i>n)						//找到一个叶子结点
	{
		if (tw>maxw)
		{	maxw=tw;				//找到一个满足条件的更优解,保存它
			for (int j=1;j<=n;j++)	//复制最优解
				x[j]=op[j];
		}
	}
	else						//尚未找完所有集装箱
	{	
		if (tw+w[i]<=W)			//左孩子结点剪枝：装载满足条件的集装箱
		{
			op[i]=1;				//选取第i个集装箱
			dfs(i+1,tw+w[i],rw-w[i],op);
		}
		if (tw+rw-w[i]>maxw)			//右孩子结点剪枝
		{
			op[i]=0;				//不选取第i个集装箱,回溯
			dfs(i+1,tw,rw-w[i],op);
		}
	}
}
void dispasolution(int n)		//输出一个解
{
	for (int i=1;i<=n;i++)
		if (x[i]==1)
			printf("  选取第%d个集装箱\n",i);
	printf("总重量=%d\n",maxw);
}
void main()
{
	int op[MAXN];				//存放临时解
	memset(op,0,sizeof(op));
	int rw=0;
	for (int i=1;i<=n;i++)
		rw+=w[i];
	dfs(1,0,rw,op);
	printf("最优方案\n");
	dispasolution(n);
}
