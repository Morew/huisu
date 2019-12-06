/*在8×8格的国际象棋盘上摆放八个皇后，使其不能互相攻击，
即任意两个皇后都不能处于同一行、同一列或同一斜线上，
问有多少种摆法。(马克斯·贝瑟尔于1848年提出)*/

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define Max 20
int pos[Max+1];
//用pos[i]表示棋子所放位置，第i列的皇后放在第pos[i]行上，
// 也就是说，pos[i]的索引i代表皇后所在的列，它的值pos[i]代表皇后所在的行
int n;//棋盘大小
int sum;//解法数量
bool check(int tol)
{
	for(int i=1;i<tol;i++)//对tol之前的列进行检查 
	{ 
		if(pos[i]==pos[tol]||abs(i-tol)==abs(pos[i]-pos[tol]))
		//如果行数相同，或者列数相减的绝对值与行数相减的绝对值相等，此时不能放皇后 
		{ 
			return false;
		}
	}
	return true; 
}
void dfs(int tol,int n)
{
	if(tol==n+1)//遍历成功，数量+1 
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

