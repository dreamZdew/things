#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f					//最大整数∞
#define MAX 1001						//最多的作业数
#define max(x,y) ((x)>(y)?(x):(y))
//问题表示
int n=4;								//作业数
int a[MAX]={0,5,12,4,8};				//M1上的执行时间,不用下标0的元素
int b[MAX]={0,6,2,14,7};				//M2上的执行时间,不用下标0的元素
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
			f1 += a[x[i]];				//在第i层选择执行作业x[i],在M1上执行完的时间
			f2[i]=max(f1,f2[i-1])+b[x[i]];
			if (bound(i)<bestf)			//剪枝:仅仅扩展当前总时间小于bestf的结点
			{
				dfs(i+1);
			}
			f1 -= a[x[i]];				//回溯:撤销第i层对作业x[i]的选择,以便再选择其他作业
			swap(x[i],x[j]);
		}
	}
}
int main()
{	f1=0;
	bestf=INF;
	memset(f2,0,sizeof(f2));
	for(int k=1; k<=n; k++)  			//设置初始调度为作业1,2,…,n的顺序
		x[k]=k;
	dfs(1);							//从作业1开始搜索
	printf("最少时间: %d, 最优调度方案:",bestf);
	for (int j=1;j<=n;j++)
		printf("%d ",bestx[j]);
	printf("\n");
	return 0;
}

