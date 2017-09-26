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
		cout << "���Բ������ǣ�" << 3.14*r*r << endl;
	}
	void perimeter()
	{
		cout << "���Բ���ܳ���:" << 2 * 3.14*r << endl;
	}
};

class In_square :public Shape
{
public:
	In_square(double x) :Shape(x)
	{}
	void area()
	{
		cout << "���Բ���ڽ������ε������:" << 2 * r*r << endl;
	}
	void perimeter()
	{
		cout << "���Բ�ڽ������ε��ܳ���:" << 4 * 1.414*r << endl;
	}
};

class Ex_square :public Shape
{
public:
	Ex_square(double x) :Shape(x)
	{}
	void area()
	{
		cout << "���Բ���������ε������:" << 4 * r*r << endl;
	}
	void perimeter()
	{
		cout << "���Բ���������ε��ܳ���:" << 8 * r << endl;p
	}
};



//������
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