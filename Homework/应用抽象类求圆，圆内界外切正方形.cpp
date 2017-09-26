#include<iostream>
#include<windows.h>
#include<string>
using namespace std;

class Shape                                //����һ��������
{
public:
	Shape(double x)
	{
		r = x;
	}
	virtual void area() = 0;               //���麯��
	virtual void perimeter() = 0;          //���麯��
protected:
	double r;
};

class Circle :public Shape                 //����һ��Բ������
{
public:
	Circle(double x) :Shape(x)
	{}
	void area()                            //�����麯��area
	{
		cout << "���Բ������ǣ�" << 3.14*r*r << endl;
	}
	void perimeter()                       //�����麯��perimeter
	{
		cout << "���Բ���ܳ���:" << 2 * 3.14*r << endl;
	}
};

class In_square :public Shape              //����һ��Բ�ڽ���������
{
public:
	In_square(double x) :Shape(x)
	{}
	void area()                            //�����麯��area
	{
		cout << "���Բ���ڽ������ε������:" << 2 * r*r << endl;
	}
	void perimeter()                       //�����麯��perimeter
	{
		cout << "���Բ�ڽ������ε��ܳ���:" << 4 * 1.414*r << endl;
	}
};

class Ex_square :public Shape              //����һ��Բ������������
{
public:
	Ex_square(double x) :Shape(x)
	{}
	void area()                            //�����麯��area
	{
		cout << "���Բ���������ε������:" << 4 * r*r << endl;
	}
	void perimeter()                       //�����麯��perimeter
	{
		cout << "���Բ���������ε��ܳ���:" << 8 * r << endl; 
	}
};



//������
int main()
{
	Shape *ptr;                            //���������Shape�Ķ���ָ��
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