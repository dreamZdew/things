#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f					//最大整数∞
#define MAX 10005						//最多的作业数
#define max(x,y) ((x)>(y)?(x):(y))
//问题表示
int n;								//作业数
int a[MAX];
int b[MAX];
//求解结果表示
int bestf;							//存放最优调度时间
int f1;								//M1的执行时间
int f2[MAX];							//M2的执行时间
int x[MAX];							//当前调度方案
int bestx[MAX];						//存放当前作业最佳调度
int tot;							//全部作业的b时间 
void swap(int &x,int &y)				//交换x和y
{	int tmp=x;
	x=y; y=tmp;
}
int bound(int i)						//求结点的下界值	
{
	int sum=0;
	for (int j=1;j<=i;j++)				//扫描所有选择的作业
		sum+=b[x[j]];					//累计所有选择作业的b时间
	return f2[i]+tot-sum;
}

void dfs(int i)						//从第i层开始搜索
{	if (i>n)							//到达叶结点,产生一种调度方案
    {	if (f2[n]<bestf)				//找到更优解
		{	bestf=f2[n];
			for(int j=1; j<=n; j++)		//复制解向量
				bestx[j] = x[j];  
		}
	}
	else
	{	for(int j=i; j<=n; j++)			//没有到达叶结点,考虑i到n的作业
		{
			swap(x[i],x[j]);
			f1 += a[x[i]];				//在第i层选择执行作业x[j],在M1上执行完的时间
			f2[i]=max(f1,f2[i-1])+b[x[i]];
			//printf("i=%d, x: ",i);
			//for (int k=1;k<=i;k++)
			//	printf("%d ",x[k]);
			//printf("  bound=%d,bestf=%d f2:",bound(i),bestf);	
			//for (int k=1;k<=i;k++)
			//	printf("%d ",f2[k]);
			//printf("\n");
			//if (f2[i]<bestf)			//剪枝:仅仅扩展当前总时间小于bestf的结点
			if (bound(i)<bestf)			//剪枝:仅仅扩展当前总时间小于bestf的结点
			{
				dfs(i+1);
			}
			//else printf("         Cut\n");
			f1 -= a[x[i]];				//回溯，即撤销第i层对作业x[j]的选择,以便再选择其他作业
			swap(x[i],x[j]);
		}
	}
}
int main()
{
	freopen("abc.in","r",stdin);
	while(scanf("%d",&n)==1 && n)
	{
		f1=0;
		bestf=INF;
		memset(f2,0,sizeof(f2));
		for(int k=1; k<=n; k++)  	//设置初始调度为作业1,2,…,n的顺序
			x[k]=k;
		tot=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			scanf("%d",&b[i]);
			tot+=b[i];
		}
		dfs(1);						//从作业1开始搜索
		printf("%d\n",bestf);
	}
	return 0;
}
