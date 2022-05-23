#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f					//���������
#define MAX 10005						//������ҵ��
#define max(x,y) ((x)>(y)?(x):(y))
//�����ʾ
int n;								//��ҵ��
int a[MAX];
int b[MAX];
//�������ʾ
int bestf;							//������ŵ���ʱ��
int f1;								//M1��ִ��ʱ��
int f2[MAX];							//M2��ִ��ʱ��
int x[MAX];							//��ǰ���ȷ���
int bestx[MAX];						//��ŵ�ǰ��ҵ��ѵ���
int tot;							//ȫ����ҵ��bʱ�� 
void swap(int &x,int &y)				//����x��y
{	int tmp=x;
	x=y; y=tmp;
}
int bound(int i)						//������½�ֵ	
{
	int sum=0;
	for (int j=1;j<=i;j++)				//ɨ������ѡ�����ҵ
		sum+=b[x[j]];					//�ۼ�����ѡ����ҵ��bʱ��
	return f2[i]+tot-sum;
}

void dfs(int i)						//�ӵ�i�㿪ʼ����
{	if (i>n)							//����Ҷ���,����һ�ֵ��ȷ���
    {	if (f2[n]<bestf)				//�ҵ����Ž�
		{	bestf=f2[n];
			for(int j=1; j<=n; j++)		//���ƽ�����
				bestx[j] = x[j];  
		}
	}
	else
	{	for(int j=i; j<=n; j++)			//û�е���Ҷ���,����i��n����ҵ
		{
			swap(x[i],x[j]);
			f1 += a[x[i]];				//�ڵ�i��ѡ��ִ����ҵx[j],��M1��ִ�����ʱ��
			f2[i]=max(f1,f2[i-1])+b[x[i]];
			//printf("i=%d, x: ",i);
			//for (int k=1;k<=i;k++)
			//	printf("%d ",x[k]);
			//printf("  bound=%d,bestf=%d f2:",bound(i),bestf);	
			//for (int k=1;k<=i;k++)
			//	printf("%d ",f2[k]);
			//printf("\n");
			//if (f2[i]<bestf)			//��֦:������չ��ǰ��ʱ��С��bestf�Ľ��
			if (bound(i)<bestf)			//��֦:������չ��ǰ��ʱ��С��bestf�Ľ��
			{
				dfs(i+1);
			}
			//else printf("         Cut\n");
			f1 -= a[x[i]];				//���ݣ���������i�����ҵx[j]��ѡ��,�Ա���ѡ��������ҵ
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
		for(int k=1; k<=n; k++)  	//���ó�ʼ����Ϊ��ҵ1,2,��,n��˳��
			x[k]=k;
		tot=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			scanf("%d",&b[i]);
			tot+=b[i];
		}
		dfs(1);						//����ҵ1��ʼ����
		printf("%d\n",bestf);
	}
	return 0;
}
