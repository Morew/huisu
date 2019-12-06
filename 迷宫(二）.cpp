#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int dir[4][2]={{0,1},{-1,0},{0,-1},{1,0}};//ÉÏÏÂ×óÓÒÒÆ¶¯ 
int n,m,startx,starty,endx,endy;
int ans=0,step[10][10];
char str[10][10];
bool vis[10][10];
void dfs(int x,int y)
{	
	if(x==endx&&y==endy)
	{
		ans++;
		return;
	} 		
	if(str[x][y]=='*')
	{
			return;
	}
	vis[x][y]=true;
	for(int i=0;i<4;i++)
	{
		int xx=x+dir[i][0];
		int yy=y+dir[i][1];
		if(xx>=0&&xx<n&&yy>=0&&yy<m&&str[xx][yy]!='*'&&!vis[xx][yy])
		{
			if(step[x][y]+1<step[xx][yy])
			{
				step[xx][yy]=step[x][y]+1;
				dfs(xx,yy);
				vis[xx][yy]=false;
			}
			
		}
	}
}
int main()
{
	memset(vis,false,sizeof(vis));
	//memset(step,0x3f3f,sizeof(step));
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>str[i][j];
			step[i][j]=1000;
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
	step[startx][starty]=0;
	dfs(startx,starty);
	if(ans)
	{
		cout<<step[endx][endy]<<endl;
	}
	else
	{
		cout<<"-1"<<endl;
	}
	//cout<<ans;
	return 0;
}
