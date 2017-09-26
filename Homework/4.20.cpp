#include<iostream>
#include<windows.h>
using namespace std;
class area_c1                            //����
{
protected:
	double height;
	double width;
public:
	area_c1(double r, double s)          //���캯��area_c1
	{
		height = r;
		width = s;
	}
	virtual double area() = 0;
};

class rectangle:public area_c1
{
public:           
	rectangle(double r, double s) :area_c1(r, s)
	{ };
	double area()                            //���ؾ������
	{
		return height*width;
	}
};

class isosceles :public area_c1
{
public:
	isosceles(double r, double s) :area_c1(r, s)
	{ };
	double area()                            //�������������
	{
		return height*width / 2;
	}
};


//������
int main()
{
	area_c1 *p;
	rectangle b(10.0, 5.0);
	isosceles i(4.0, 6.0);
	p = &b;
	cout << "the rectangle's area is: " << p->area() << endl;
	p = &i;
	cout << "the isosceles's area is: " << p->area() << endl;
	Sleep(40000);
	return 0;
}