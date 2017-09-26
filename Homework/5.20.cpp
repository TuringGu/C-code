#include<iostream>
#include<windows.h>
#include<string>
using namespace std;

class Container
{
protected:
	double radius;                   //�뾶
	double height;                   //��
public:
	Container(double ra)
	{
		Container::radius = ra;
	}
	double print_ra()
	{
		return radius;
	}
	double print_he()
	{
		return height;
	}
	virtual double surface_area() = 0;    //�麯����������
	virtual double volume() = 0;          //�麯������������ݻ���
};

class Sphere :public Container            //�����ࣺ����
{
public:
	Sphere(double ra) :Container(ra){}
	double surface_area()
	{
		return 4 * 3.1416*radius*radius;
	}
	double volume()
	{
		return 3.1416*radius*radius*radius * 4 / 3;
	}
};

class Cylinder :public Container          //�����ࣺԲ����
{
public:
	Cylinder(double ra, double he) :Container(ra)
	{
		height = he;
	}
	double surface_area()
	{
		return 2 * 3.1416*radius*(height + radius);
	}
	double volume()
	{
		return 3.1416*radius*radius*height;
	}
};

class Cube :public Container              //�����ࣺ������
{
public:
	Cube(double ra): Container(ra){};
	double surface_area()
	{
		return radius*radius * 6;
	}
	double volume()
	{
		return radius*radius*radius;
	}
};

//������
int main() 
{
	Container *ptr;
	Sphere obj1(8);
	Cylinder obj2(3, 5);
	Cube obj3(5);
	ptr = &obj1;
	cout << "The radius of the sphere: " << ptr->print_ra() << endl;
	cout << "The surface area of the sphere: " << ptr->surface_area() << endl;
	cout << "The volume of the sphere: " << ptr->volume() << endl;
	ptr = &obj2;
	cout << "The radius of the cylinder: " << ptr->print_ra() << endl;
	cout << "The height of the cylinder: " << ptr->print_he() << endl;
	cout << "The surface area of the cylinder: " << ptr->surface_area() << endl;
	cout << "The volume of the cylinder: " << ptr->volume() << endl;
	ptr = &obj3;
	cout << "The length of the cube's sides: " << ptr->print_ra() << endl;
	cout << "The surface area of the cube: " << ptr->surface_area() << endl;
	cout << "The volume of the cube: " << ptr->volume() << endl;
		Sleep(40000);
	return 0;
}