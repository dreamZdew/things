#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f					//���������
#define MAX 1001						//������ҵ��
#define max(x,y) ((x)>(y)?(x):(y))
//�����ʾ
int n=4;								//��ҵ��
int a[MAX]={0,5,12,4,8};				//M1�ϵ�ִ��ʱ��,�����±�0��Ԫ��
int b[MAX]={0,6,2,14,7};				//M2�ϵ�ִ��ʱ��,�����±�0��Ԫ��
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
			f1 += a[x[i]];				//�ڵ�i��ѡ��ִ����ҵx[i],��M1��ִ�����ʱ��
			f2[i]=max(f1,f2[i-1])+b[x[i]];
			if (bound(i)<bestf)			//��֦:������չ��ǰ��ʱ��С��bestf�Ľ��
			{
				dfs(i+1);
			}
			f1 -= a[x[i]];				//����:������i�����ҵx[i]��ѡ��,�Ա���ѡ��������ҵ
			swap(x[i],x[j]);
		}
	}
}
int main()
{	f1=0;
	bestf=INF;
	memset(f2,0,sizeof(f2));
	for(int k=1; k<=n; k++)  			//���ó�ʼ����Ϊ��ҵ1,2,��,n��˳��
		x[k]=k;
	dfs(1);							//����ҵ1��ʼ����
	printf("����ʱ��: %d, ���ŵ��ȷ���:",bestf);
	for (int j=1;j<=n;j++)
		printf("%d ",bestx[j]);
	printf("\n");
	return 0;
}

