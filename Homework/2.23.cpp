//【2.23】编写使用sroot函数，运用重载知识。
#include<iostream> 
#include<cmath>

int sroot(int x)
{
	return sqrt(x);
}

long sroot(long x)
{
	return sqrt(x);
}

double sroot(double x)
{ 
	return sqrt(x);
}


using namespace std;
int main()
{
	double a;
	cout<<"Input a nummber: "<<endl;
	cin>>a;
	cout<<"double : "<<sroot(a)<<endl;
	long b=long(a); 
	cout<<"long : "<<sroot(b)<<endl;
	int c=int(b);
	cout<<"int : "<<sroot(c)<<endl;
}

