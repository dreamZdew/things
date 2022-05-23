//���ý�һ����֦���0/1����������㷨
#include <stdio.h>
#include <string.h>
#include<algorithm>
using namespace std;
#define MAXN 20					//�����Ʒ��
struct PNode
{
	int no;			//��Ʒ��� 
	int w;			//��Ʒ���� 
	int v;			//��Ʒ��ֵ
	double p;		//��λ������ֵ
	bool operator<(struct PNode &s)
	{
		return p>s.p;			//���ڰ�p�ݼ����� 
	} 
};
//�����ʾ
int n=4;						//4����Ʒ
int W=6;						//��������Ϊ6
struct PNode A[]={{0,0,0},{1,5,4},{2,3,4},{3,2,3},{4,1,1}};
//�������ʾ
int x[MAXN];					//������ս�
int maxv=0; 					//������Ž���ܼ�ֵ
int bound(int i,int tw,int tv)	//���Ͻ�
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
void dfs(int i,int tw,int tv,int op[]) //���0/1��������
{
	if (i>n)							//�ҵ�һ��Ҷ�ӽ��
	{	maxv=tv;						//��Ÿ��Ž�
		for (int j=1;j<=n;j++)
			x[j]=op[j];
	}
	else								//��δ����������Ʒ
	{	if (tw+A[i].w<=W)  				//���ӽ���֦
		{
			op[i]=1;					//ѡȡ��i����Ʒ
			dfs(i+1,tw+A[i].w,tv+A[i].v,op);
		}
		op[i]=0;						//��ѡȡ��i����Ʒ,����
		if (bound(i,tw,tv)>maxv)		//�Һ��ӽ���֦
			dfs(i+1,tw,tv,op);
	}
}
void dispasolution()					//������Ž�
{
	printf("���װ�����:\n");
	for (int i=1;i<=n;i++)
		if (x[i]==1)
			printf("  ѡȡ��%d����Ʒ\n",A[i].no);
	printf("������=%d,�ܼ�ֵ=%d\n",W,maxv);
}
int main()
{
	int op[MAXN];						//�����ʱ��
	memset(op,0,sizeof(op));
	for (int i=1;i<=n;i++)
		A[i].p=A[i].v*1.0/A[i].w;

	sort(A+1,A+n+1);
	for(int j=1;j<=n;j++)
		printf("��Ʒ%d,w=%d,v=%d\n",A[j].no,A[j].w,A[j].v);
	dfs(1,0,0,op);
	dispasolution();
	return 0;
}
