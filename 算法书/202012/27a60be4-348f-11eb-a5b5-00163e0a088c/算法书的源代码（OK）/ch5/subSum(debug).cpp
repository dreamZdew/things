#include <stdio.h>
#define MAXN 20					//最多整数个数
//问题表示
int n=4,W=31;
int w[]={0,11,13,24,7};				//存放所有整数,不用下标0的元素
int count=0;						//累计解个数
void dispasolution(int x[])			//输出一个解
{	int i;
	printf("第%d个解:\n",++count);
	printf("  选取的数为");
	for (i=1;i<=n;i++)
		if (x[i]==1)
			printf("%d ",w[i]);
	printf("\n");
}
void dfs(int i,int tw,int rw,int x[]) 	//求解子集和
{	//tw为考虑第i个整数时选取的整数和，rw为剩下的整数和
	if (i>n)							//找到一个叶子结点
	{
		if (tw==W)					//找到一个满足条件的解,输出它
			dispasolution(x);
	}
	else								//尚未找完所有整数
	{	if (tw+w[i]<=W)				//左孩子结点剪枝：选取满足条件的整数w[i]
		{
			printf("  选择整数%d,进入i=%d,dfs(%d,%d)\n",w[i],i+1,tw+w[i],rw-w[i]);
			x[i]=1;					//选取第i个整数
			dfs(i+1,tw+w[i],rw-w[i],x);
		}
		else
			printf("  选择整数%d,i=%d,剪枝\n",w[i],i);

		if (tw+rw-w[i]>=W)				//右孩子结点剪枝：剪除不可能存在解的结点
		{
			printf("  不选择整数%d,进入i=%d,dfs(%d,%d)\n",w[i],i+1,tw,rw-w[i]);
			x[i]=0;					//不选取第i个整数,回溯
			dfs(i+1,tw,rw-w[i],x);
		}
		else
			printf("  不选择整数%d,i=%d,剪枝\n",w[i],i);

	}
}
void main()
{	int x[MAXN];						//存放一个解向量
	int rw=0;
	for (int j=1;j<=n;j++)				//求所有整数和rw
		rw+=w[j];
	printf("dfs(0,%d)\n",rw);
	dfs(1,0,rw,x);					//i从1开始
}
