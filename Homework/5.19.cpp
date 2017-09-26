#include<iostream>
#include<windows.h>
#include<string>
using namespace std;

class complex
{
public:
	complex(double r = 0, double i = 0);
	friend complex operator+(const complex c1, const complex c2);  //������Ԫ��������غ���
	void print();                                                  //����
private:
	double real, imag;
};

complex::complex(double r, double i)
{
	real = r;
	imag = i;
}

complex operator+(const complex c1, const complex c2)             //������Ԫ��������غ���
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

//������
int main() 
{
	complex c1(2.5, 3.7), c2(4.2, 6.5);
	complex c;
	c = c1 + c2;
	c.print();
		Sleep(40000);
	return 0;
}