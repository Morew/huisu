#include<iostream>
#define maxn 100
using namespace std;
int wi[maxn];//��Ʒ���� 
int vi[maxn];//��Ʒ��ֵ
int n,c;//��Ʒ�����Լ������������
int cw,cv;//��ǰ���������͵�ǰ������ֵ
int bestcv;//��ĿǰΪֹ�������� 
int x[maxn];//x[i]=1ʱѡ������ݣ�Ϊ0���෴ 
void dfs(int i)
{
	if(i>=n)
	{
		if(cv>bestcv)
		{
			bestcv=cv;
		}
		return;
	}
	if(cw+wi[i]<=c)//����ֵΪ1�ĺ��� 
	{
		x[i]=1;
		cw+=wi[i];
		cv+=vi[i];
		dfs(i+1);
		cw-=wi[i];//���� 
		cv-=vi[i];	
	}
	x[i]=0;//����ֵΪ0�ĺ��� 
	dfs(i+1);
	
} 
int main()
{
	cin>>n>>c; 
	for(int i=0;i<n;i++){//����1������Ʒ�������ͼ�ֵ 
		cin>>wi[i]>>vi[i];
	}
	dfs(0);
	cout<<bestcv<<endl;
	return 0;
}
