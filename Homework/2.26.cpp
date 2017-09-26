//【2.26】二分法(dichotomy)求简单方程（二次及以下）的根
#include<iostream> 
#include<windows.h>
#include<cmath>
using namespace std;

double F(int x, int a, int b, int c)
{
	double y;
	y = a*x*x + b*x + c;
	return y;
}

int main()
{
	double a, b, c, fx1, fx2, fx3, x1, x2, x3, i=0, j, k, x, accuracy, m1, m2;
	cout << "Please input a,b,c for establish y=a*x*x+b*x+c" << endl;
	cin >> a >> b >> c;
	cout << "y=" << a << "*x*x+" << b << "*x+" << c << endl;
	if (b*b - 4 * a*c < 0){
		cout << "y=" << a << "*x*x+" << b << "*x+" << c << " has no root." << endl;
		cout << "You should stop right now!\n";
	}
	cout << "Please input the accuracy you want." << endl;
	cin >> accuracy;
	cout << "Please input the interval(m1,m2) where the roots of equation may be(input two numbers)." << endl;
	cin >> m1 >> m2;
	x1 = m1; x2 = m2;
	fx1 = F(x1, a, b, c);
	fx2 = F(x2, a, b, c);
	do
	{
		fx3 =(fx1+fx2)/2;i+=1;
		if (fx1*fx2 > 0)
		{
			fx3 = fx2;
		}
		else
		{
			fx3 = fx1;

		}
		double j=pow(2,(i-1));
	} while (j<accuracy);
	cout << "\nThe root is:" << fx3 << endl;
	return 0;
	Sleep(2000);
}
 
