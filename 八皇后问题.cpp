/*��8��8��Ĺ����������ϰڷŰ˸��ʺ�ʹ�䲻�ܻ��๥����
�����������ʺ󶼲��ܴ���ͬһ�С�ͬһ�л�ͬһб���ϣ�
���ж����ְڷ���(���˹����ɪ����1848�����)*/

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define Max 20
int pos[Max+1];
//��pos[i]��ʾ��������λ�ã���i�еĻʺ���ڵ�pos[i]���ϣ�
// Ҳ����˵��pos[i]������i����ʺ����ڵ��У�����ֵpos[i]����ʺ����ڵ���
int n;//���̴�С
int sum;//�ⷨ����
bool check(int tol)
{
	for(int i=1;i<tol;i++)//��tol֮ǰ���н��м�� 
	{ 
		if(pos[i]==pos[tol]||abs(i-tol)==abs(pos[i]-pos[tol]))
		//���������ͬ��������������ľ���ֵ����������ľ���ֵ��ȣ���ʱ���ܷŻʺ� 
		{ 
			return false;
		}
	}
	return true; 
}
void dfs(int tol,int n)
{
	if(tol==n+1)//�����ɹ�������+1 
	{
	     sum++;
	}
	for(int i=1;i<=n;i++)
	{
		pos[tol]=i;
		if(check(tol)) 
		{
			dfs(tol+1,n);
		}
	}
	
} 
int main()
{
	int n;
	cin>>n;
	dfs(1,n);
	cout<<sum<<endl;
	return 0;
}

