#include<iostream>
#include<windows.h>
#include<string>
using namespace std;

class Shape                                //声明一个抽象类
{
public:
	Shape(double x)
	{
		r = x;
	}
	virtual void area() = 0;               //纯虚函数
	virtual void perimeter() = 0;          //纯虚函数
protected:
	double r;
};

class Circle :public Shape                 //声明一个圆派生类
{
public:
	Circle(double x) :Shape(x)
	{}
	void area()                            //定义虚函数area
	{
		cout << "这个圆的面积是：" << 3.14*r*r << endl;
	}
	void perimeter()                       //定义虚函数perimeter
	{
		cout << "这个圆的周长是:" << 2 * 3.14*r << endl;
	}
};

class In_square :public Shape              //声明一个圆内接正方形类
{
public:
	In_square(double x) :Shape(x)
	{}
	void area()                            //定义虚函数area
	{
		cout << "这个圆的内接正方形的面积是:" << 2 * r*r << endl;
	}
	void perimeter()                       //定义虚函数perimeter
	{
		cout << "这个圆内接正方形的周长是:" << 4 * 1.414*r << endl;
	}
};

class Ex_square :public Shape              //声明一个圆外切正方形类
{
public:
	Ex_square(double x) :Shape(x)
	{}
	void area()                            //定义虚函数area
	{
		cout << "这个圆外切正方形的面积是:" << 4 * r*r << endl;
	}
	void perimeter()                       //定义虚函数perimeter
	{
		cout << "这个圆外切正方形的周长是:" << 8 * r << endl; 
	}
};



//主程序
int main()
{
	Shape *ptr;                            //定义抽象类Shape的对象指针
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
	ptr->perimeter();
		Sleep(40000);
	return 0;
}