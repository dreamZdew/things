#include <stdio.h>
#include <string.h>
#define MAXN 20						//��༯װ�����
//�����ʾ
int w[]={0,5,2,6,4,3};				//����װ������,�����±�0��Ԫ��
int	n=5,W=10;
int maxw=0;							//������Ž��������
int x[MAXN];						//������Ž�����
void dfs(int i,int tw,int rw,int op[]) //���ǵ�i����װ��
{
	if (i>n)						//�ҵ�һ��Ҷ�ӽ��
	{
		if (tw>maxw)
		{	maxw=tw;				//�ҵ�һ�����������ĸ��Ž�,������
			for (int j=1;j<=n;j++)	//�������Ž�
				x[j]=op[j];
		}
	}
	else						//��δ�������м�װ��
	{	
		if (tw+w[i]<=W)			//���ӽ���֦��װ�����������ļ�װ��
		{
			op[i]=1;				//ѡȡ��i����װ��
			dfs(i+1,tw+w[i],rw-w[i],op);
		}
		if (tw+rw-w[i]>maxw)			//�Һ��ӽ���֦
		{
			op[i]=0;				//��ѡȡ��i����װ��,����
			dfs(i+1,tw,rw-w[i],op);
		}
	}
}
void dispasolution(int n)		//���һ����
{
	for (int i=1;i<=n;i++)
		if (x[i]==1)
			printf("  ѡȡ��%d����װ��\n",i);
	printf("������=%d\n",maxw);
}
void main()
{
	int op[MAXN];				//�����ʱ��
	memset(op,0,sizeof(op));
	int rw=0;
	for (int i=1;i<=n;i++)
		rw+=w[i];
	dfs(1,0,rw,op);
	printf("���ŷ���\n");
	dispasolution(n);
}
