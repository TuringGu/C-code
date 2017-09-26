#include<iostream>
#include<windows.h>
#include<string>
using namespace std;

class Shape
{
public:
	Shape(double x)
	{
		r = x;
	}
	virtual void area() = 0;
	virtual void perimeter() = 0;
protected:
	double r;
};

class Circle :public Shape
{
public:
	Circle(double x) :Shape(x)
	{}
	void area()
	{
		cout << "这个圆的面积是：" << 3.14*r*r << endl;
	}
	void perimeter()
	{
		cout << "这个圆的周长是:" << 2 * 3.14*r << endl;
	}
};

class In_square :public Shape
{
public:
	In_square(double x) :Shape(x)
	{}
	void area()
	{
		cout << "这个圆的内接正方形的面积是:" << 2 * r*r << endl;
	}
	void perimeter()
	{
		cout << "这个圆内接正方形的周长是:" << 4 * 1.414*r << endl;
	}
};

class Ex_square :public Shape
{
public:
	Ex_square(double x) :Shape(x)
	{}
	void area()
	{
		cout << "这个圆外切正方形的面积是:" << 4 * r*r << endl;
	}
	void perimeter()
	{
		cout << "这个圆外切正方形的周长是:" << 8 * r << endl;p
	}
};



//主程序
int main()
{
	Shape *ptr;
	Circle ob1(5);
	In_square ob2(5);
	Ex_square ob3(5);
	ptr = &ob1;
	ptr->area();
	ptr->perimeter();
	ptr = &ob2;
	ptr->area();
	ptr->perimeter();
	ptr = &ob3;
	ptr->area();
	ptr->perimeter():
	Sleep(40000);
	return 0;
}