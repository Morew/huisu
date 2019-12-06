#include<iostream>
#define maxn 100
using namespace std;
int wi[maxn];//物品重量 
int vi[maxn];//物品价值
int n,c;//物品数量以及背包最大容量
int cw,cv;//当前背包重量和当前背包价值
int bestcv;//到目前为止最大的收益 
int x[maxn];//x[i]=1时选择该数据，为0则相反 
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
	if(cw+wi[i]<=c)//进入值为1的孩子 
	{
		x[i]=1;
		cw+=wi[i];
		cv+=vi[i];
		dfs(i+1);
		cw-=wi[i];//回溯 
		cv-=vi[i];	
	}
	x[i]=0;//进入值为0的孩子 
	dfs(i+1);
	
} 
int main()
{
	cin>>n>>c; 
	for(int i=0;i<n;i++){//输入1到个物品的重量和价值 
		cin>>wi[i]>>vi[i];
	}
	dfs(0);
	cout<<bestcv<<endl;
	return 0;
}
