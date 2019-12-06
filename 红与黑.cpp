#include<iostream>
#include<cstring>
using namespace std;
int sum=0;//总共能够到达多少块黑色的瓷砖
int W,H;//分别表示 x方向和 y方向瓷砖的数量	
int book[21][21]={0};
char str[21][21];
int dirx[4]={-1,0,1,0};//上下左右 
int diry[4]={0,-1,0,1}; 
void dfs(int x,int y)
{
	sum++;
	book[x][y]=1;
		for(int i=0;i<4;i++)
		{
			int xx=x+dirx[i];
			int yy=y+diry[i];
			if(!book[xx][yy]&&str[xx][yy]!='#'&&xx>=0&&xx<H&&yy>=0&&yy<W)
			{
				dfs(xx,yy);
			}
		}
	
} 
int main()
{int startx=0,starty=0;//开始位置 
	cin>>W>>H;
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			cin>>str[i][j];			
			if(str[i][j]=='@')
			{
				startx=i;
				starty=j;
			}
		}
	}
	dfs(startx,starty);
	cout<<sum<<endl;
	return 0;
}
    
