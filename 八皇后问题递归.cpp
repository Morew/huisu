#include <bits/stdc++.h>
using namespace std;
//�ݹ��㷨����˻ʺ����⡣�ܹ���92�ֽⷨ��
int c[20], n, cnt=0;
//c[i]�±��ʾ�У���Ӧ��ֵ��ʾ�� 
//n��ʾ���ƴ�С cnt��ʾ������С 
void print(){

    for(int i=0; i<n; ++i)
	{
        for(int j=0; j<n; ++j)
		{
            if(j == c[i]) 
			{
				cout<<"1 ";
			}
            else 
			{
				cout<<"0 ";
			}
        }
        cout<<endl;
    }
    cout<<endl;
}
void search(int r){
    if(r == n){
        print();
        ++cnt;
        return;
    }
    for(int i=0; i<n; ++i)
	{
        c[r] = i;
        int ok = 1;
        for(int j=0; j<r; ++j)
        {
           if(c[r]==c[j] || r-j==c[r]-c[j] || r-j==c[j]-c[r])
		   {
                ok = 0;
                break;
           }
        }
        if(ok)
		{ 
		   search(r+1);
		} 
    }
}
int main(){
	cin>>n;
    search(0);
    cout<<cnt<<endl;
    return 0;
}
