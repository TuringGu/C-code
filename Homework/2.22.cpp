//【2.22】用动态分配空间方法计算Fibonacci前n项和
#include<iostream> 
using namespace std;
int main()
{
	int i,n;
	cout<<"Input the Fibonacci's number of terms:n-1(n<=46):"<<endl;
	cin>>n;
	int *p=new int[n];
	p[0]=0;p[1]=1;
	cout<<p[0]<<"   "<<p[1]<<"   ";
	for(i=2;i<=n;i++)
	{
		p[i]=p[i-2]+p[i-1];
		cout<<p[i]<<"   ";
	}
	if(!p)
	{
		cout<<"allocation failure\n";
		return 1;
	}
}
