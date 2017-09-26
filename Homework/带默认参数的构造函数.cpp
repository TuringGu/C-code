//带默认参数的构造函数
#include<iostream>
#include<cmath>
#include<windows.h>
using namespace std;
class Complex
{
public:
	Complex(double r = 0.0, double i = 0.0);
	double abscomplex();
private:
	double real;
	double imag;
};
Complex::Complex(double r, double i)   //不可再构造函数上指定返回值类型，void也不行
{
	real = r; imag = i;
}
double Complex::abscomplex()
{
	double t;
	t = real*real + imag*imag;
	return sqrt(t);
}
int main()
{
	Complex S1;
	cout << "复数1的绝对值是:" << S1.abscomplex() << endl;
	Complex S2(1.1);
	cout << "复数2的绝对值是:" << S2.abscomplex() << endl;
	Complex S3(1.1, 2.2);
	cout << "复数3的绝对值是:" << S3.abscomplex() << endl;
	Sleep(5000);
	return 0;
}