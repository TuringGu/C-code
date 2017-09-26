#include<iostream>
#include<windows.h>
using namespace std;
class area_c1                            //基类
{
protected:
	double height;
	double width;
public:
	area_c1(double r, double s)          //构造函数area_c1
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
	double area()                            //返回矩形面积
	{
		return height*width;
	}
};

class isosceles :public area_c1
{
public:
	isosceles(double r, double s) :area_c1(r, s)
	{ };
	double area()                            //返回三角形面积
	{
		return height*width / 2;
	}
};


//主程序
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