//��2.24����Ǯ���⣺һԪӲ�һ���1��2��5��Ӳ���м��ֻ���
#include<iostream> 
using namespace std;
int main()
{
	int x,i,j,k,n=0,y;
	cout<<"Input the number of RMB that will be divided into 1,2,5 penny of RMB."<<"The number is: "<<endl;
	cin>>x;
	for(i=0;i<=x;i++)
	    for(j=0;j<=(x/2);j++)
	        for(k=0;k<=(x/5);k++)
	        {
	        	y=i+2*j+5*k;
				if(y==x)  
				{
					n+=1;
					cout<<"method "<<n<<endl<<"1penny: "<<i<<"   2penny: "<<j<<"   5penny: "<<k<<endl;
				}
	        }
	        cout<<"\nThere are "<<n<<" ways to divided it.\n";
}
