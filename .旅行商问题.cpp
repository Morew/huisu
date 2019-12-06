#include<iostream>
using namespace std;
#define MAX 1000
int g[100][100],x[100],bestx[100];//x[100]表示各个顶点,bestx[100]记录最优路径 
 
int cl=0,bestl=MAX,n;//cl表示当前路径长 ，best表示最短路径长 
 
void dfs(int t)
{
    int j;
    if(t>n) //到达叶子结点
    {
        if(g[x[n]][1] && (cl+g[x[n]][1]<bestl))//推销员到的最后一个城市与出发的城市之间有路径，且当前总距离比当前最优值小
        {
            for(j=1; j<=n; j++)
                bestx[j]=x[j];
            bestl=cl+g[x[n]][1];
        }
    }
    else    //没有到达叶子结点
    {
        for(j=t; j<=n; j++)//搜索扩展结点的左右分支，即所有与当前所在城市临近的城市
        {
            if(g[x[t-1]][x[j]] && (cl+g[x[t-1]][x[j]]<bestl))//若果第t-1个城市与第t个城市之间有路径且可以得到更短的路线
            {
                swap(x[t],x[j]);     //保存要去的第t个城市到x[t]中
                cl+=g[x[t-1]][x[t]]; //路线长度增加
                dfs(t+1);      //搜索下一个城市
                cl-=g[x[t-1]][x[t]];
                swap(x[t],x[j]);
            }
        }
    }
}
int main()
{
    int i,j;
    cout<<"请输入一共有几个城市："<<endl;
    cin>>n;
    cout<<"请输入城市之间的距离"<<endl;
 
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            cin>>g[i][j];
 
    for(i=1; i<=n; i++)
    {
        x[i]=i;
        bestx[i]=0;
    }
 
    dfs(2);
    cout<<"城市路线："<<endl;
    for(i=1; i<=n; i++)
        cout<<bestx[i]<<' ';
    cout<<bestx[1];
    cout<<endl;
    cout<<"最短路线长度："<<endl;
    cout<<bestl<<endl;
    return 0;
}
/*
测试数据：
5
0 10 0 4 12
10 0 15 8 5
0 15 0 7 30
 4 8  7 0 6
12 5 30  6 0
*/

