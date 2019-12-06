#include<iostream>
#include<cstring> 
using namespace std;
int n,m,cnt=0,ans=0;//n行m列 
int startx,starty,endx,endy;
char str[10][10];
bool vis[10][10];
int dir[4][2]={{0,1},{-1,0},{0,-1},{1,0}};//上下左右移动 
//int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
void dfs(int x,int y){
	if(x==endx&&y==endy){
		cnt++;
		return;
	}
	if(str[x][y]=='*') 
	{
		return;
	}
	vis[x][y]=true;
	for(int i=0;i<4;i++){
		int xx=x+dir[i][0];
		int yy=y+dir[i][1];
		if(xx>=0&&xx<n&&yy>=0&&yy<m&&!vis[xx][yy]&&str[xx][yy]!='*')
		{
			dfs(xx,yy);
			vis[xx][yy]=false;
    	}
	} 
}
int main()
{	
    memset(vis,false,sizeof(vis));
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>str[i][j];
			if(str[i][j]=='S')
			{
				startx=i;
				starty=j;
			}
			if(str[i][j]=='T')
			{
				endx=i;
				endy=j;
			}
		}
	}
   dfs(startx,starty);
   if(cnt>0){
		cout<<"yes"<<endl;
	}
	else{
		cout<<"no"<<endl;
	}
	return 0;
}
