//�ж��Ӽ��������Ƿ���ڽ���㷨
#include <stdio.h>
#define MAXN 20						//�����������
//�����ʾ
int n=4,W;
int w[]={0,11,13,24,7};				//�����������,�����±�0��Ԫ��
bool dfs(int i,int tw,int rw)		//����Ӽ���
{
	if (i>n)						//�ҵ�һ��Ҷ�ӽ��
	{	if (tw==W)					//�ҵ�һ�����������Ľ�,����true
			return true;
	}
	else							//��δ����������Ʒ
	{
		if (tw+w[i]<=W)				//���ӽ���֦��ѡȡ��������������w[i]
			return dfs(i+1,tw+w[i],rw-w[i]);	//ѡȡ��i������
		if (tw+rw-w[i]>=W)				//�Һ��ӽ���֦�����������ܴ��ڽ�Ľ��
			return dfs(i+1,tw,rw-w[i]);	//��ѡȡ��i������,����
	}
	return false;
}
bool solve()						//�ж��Ӽ��������Ƿ���ڽ�
{
	int rw=0;
	for (int j=1;j<=n;j++)			//������������rw
		rw+=w[j];
	return dfs(1,0,rw);				//i��1��ʼ
}
void main()
{
	W=7;
	printf("W=%dʱ%s\n",W,(solve()?"���ڽ�":"û�н�"));
	W=15;
	printf("W=%dʱ%s\n",W,(solve()?"���ڽ�":"û�н�"));
	W=21;
	printf("W=%dʱ%s\n",W,(solve()?"���ڽ�":"û�н�"));
	W=24;
	printf("W=%dʱ%s\n",W,(solve()?"���ڽ�":"û�н�"));
}
