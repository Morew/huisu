#include<iostream>
using namespace std;
#define MAX 1000
int g[100][100],x[100],bestx[100];//x[100]��ʾ��������,bestx[100]��¼����·�� 
 
int cl=0,bestl=MAX,n;//cl��ʾ��ǰ·���� ��best��ʾ���·���� 
 
void dfs(int t)
{
    int j;
    if(t>n) //����Ҷ�ӽ��
    {
        if(g[x[n]][1] && (cl+g[x[n]][1]<bestl))//����Ա�������һ������������ĳ���֮����·�����ҵ�ǰ�ܾ���ȵ�ǰ����ֵС
        {
            for(j=1; j<=n; j++)
                bestx[j]=x[j];
            bestl=cl+g[x[n]][1];
        }
    }
    else    //û�е���Ҷ�ӽ��
    {
        for(j=t; j<=n; j++)//������չ�������ҷ�֧���������뵱ǰ���ڳ����ٽ��ĳ���
        {
            if(g[x[t-1]][x[j]] && (cl+g[x[t-1]][x[j]]<bestl))//������t-1���������t������֮����·���ҿ��Եõ����̵�·��
            {
                swap(x[t],x[j]);     //����Ҫȥ�ĵ�t�����е�x[t]��
                cl+=g[x[t-1]][x[t]]; //·�߳�������
                dfs(t+1);      //������һ������
                cl-=g[x[t-1]][x[t]];
                swap(x[t],x[j]);
            }
        }
    }
}
int main()
{
    int i,j;
    cout<<"������һ���м������У�"<<endl;
    cin>>n;
    cout<<"���������֮��ľ���"<<endl;
 
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            cin>>g[i][j];
 
    for(i=1; i<=n; i++)
    {
        x[i]=i;
        bestx[i]=0;
    }
 
    dfs(2);
    cout<<"����·�ߣ�"<<endl;
    for(i=1; i<=n; i++)
        cout<<bestx[i]<<' ';
    cout<<bestx[1];
    cout<<endl;
    cout<<"���·�߳��ȣ�"<<endl;
    cout<<bestl<<endl;
    return 0;
}
/*
�������ݣ�
5
0 10 0 4 12
10 0 15 8 5
0 15 0 7 30
 4 8  7 0 6
12 5 30  6 0
*/

