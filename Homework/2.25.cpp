//��2.25�� ����������������С�������
#include<iostream> 
using namespace std;

int min(int &m,int &n)
{
	if(m<=n) return m;
	else return n;
}

int max(int &m,int &n)
{
	if(m>=n) return m;
	else return n;
}
int main()
{
	int a,b;
	cout<<"Please input two numbers: "<<endl;
	cin>>a>>b;
	cout<<min(a,b)<<"   "<<max(a,b)<<endl;
}
