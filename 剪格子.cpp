#include<bits/stdc++.h>
using namespace std;
int m,n;//m x n 的格子
int str[10][10];
int sum=0,ans=1000;
int dir[4][2]={{0,1},{-1,0},{1,0},{0,-1}};//上下左右移动 
bool vis[10][10];
void dfs(int x,int y,int cnt,int num)//cnt为走过的格子加起来的和 ，num为走过的格子数 
{
	if(cnt>(sum/2)) return;
	if(cnt==(sum/2)){
		if(num<ans){
			ans=num;
		}
		return;
	}
	vis[x][y]=true;
	for(int i=0;i<4;i++)
	{
		int xx=x+dir[i][0];
		int yy=y+dir[i][1];
		if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&!vis[xx][yy])
		{
			vis[xx][yy]=true;
			dfs(xx,yy,cnt+str[xx][yy],num+1);
			vis[xx][yy]=false;
		}
	}
}
int main()
{
	memset(str,false,sizeof(str));
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>str[i][j];
			sum+=str[i][j];
		}
	}
	dfs(1,1,str[1][1],1);
	cout<<ans<<endl;
} 
