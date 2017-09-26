#include<iostream>
#include<windows.h>
#include<string>
using namespace std;

class complex
{
public:
	complex(double r = 0, double i = 0);
	friend complex operator+(const complex c1, const complex c2);  //声明友元运算符重载函数
	void print();                                                  //声明
private:
	double real, imag;
};

complex::complex(double r, double i)
{
	real = r;
	imag = i;
}

complex operator+(const complex c1, const complex c2)             //定义友元运算符重载函数
{
	complex temp;
	temp.real = c1.real + c2.real;
	temp.imag = c1.imag + c2.imag;
	return temp;
}

void complex::print()
{
	cout << "(" << real << "," << imag << ")" << endl;
}

//主程序
int main() 
{
	complex c1(2.5, 3.7), c2(4.2, 6.5);
	complex c;
	c = c1 + c2;
	c.print();
		Sleep(40000);
	return 0;
}