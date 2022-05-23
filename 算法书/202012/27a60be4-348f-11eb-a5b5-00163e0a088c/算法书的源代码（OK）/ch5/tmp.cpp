#include <stdio.h>
#include <queue>
using namespace std;
#define MAX 11
#define INF 0x3f3f3f3f
int A[MAX][MAX]={						//һ����Ȩ����ͼ
		{0,1,4,INF,INF},
		{INF,0,INF,1,5},
		{INF,INF,0,INF,1},
		{INF,INF,2,0,3},
		{INF,INF,INF,INF,INF} };
int n=5;
int bestlen=INF;							//����·����·������
int bestcount=0;							//����·��������
struct NodeType
{	int vno;							//����ı��
	int length;							//��ǰ����·������
	bool operator>(const NodeType &s) const	//����>��ϵ����
	{	return length>s.length;  }	//lengthԽСԽ����
};
void solve(int s,int t)					//�����·������
{	NodeType e,e1;					//����2�����
	priority_queue<NodeType,vector<NodeType>,greater<NodeType> > qu; //����һ������qu
	e.vno=s;							//��������
	e.length=0;
	qu.push(e);							//��������
	while (!qu.empty())					//�Ӳ���ѭ��
	{	e=qu.top(); qu.pop();				//���ӽ��e��Ϊ��ǰ���
		if (e.vno==t)						//e��һ��Ҷ���
		{	if (e.length<bestlen)			//�Ƚ������Ž�
			{	bestcount=1;
				bestlen=e.length;			//�������·������
			}
			else if (e.length==bestlen)
				bestcount++;
		}
		else							//e����Ҷ���
		{	for (int j=0; j<n; j++)			//���e���������ڶ���
				if (A[e.vno][j]!=INF && A[e.vno][j]!=0)  //����e.vno������j�б�
				{	if (e.length+A[e.vno][j]<bestlen)	  //��֦
					{	e1.vno=j;
						e1.length=e.length+A[e.vno][j];
						qu.push(e1);	 //��Ч�ӽ��e1����
					}
				}
		}
	}
}
int main()
{	int s=0,t=4;
	solve(s,t);
	if (bestcount==0)
		printf("%d��%dû��·��\n",s,t);
	else
	{	printf("%d��%d����·��\n",s,t);
		printf("   ���·������=%d,����=%d\n", bestlen,bestcount);
		//�����5 3
	}
	return 0;
}

