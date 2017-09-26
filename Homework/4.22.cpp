#include<iostream>
#include<windows.h>
#include<string>
using namespace std;
class person             //基类
{
public:
	void input()
	{
		cout << "number: "; cin >> num;
		cout << "name: "  ; cin >> name;
	}
	void disp()
	{
		cout << "number: " << num << endl;
		cout << "name: "   << name << endl;
	}
private:
	string num;
	string name;
};

class student :public person         //student派生类
{
public:
	void input()
	{
		person::input();
		cout << "classnum: ";
		cin >> classnum;
		cout << "score: ";
		cin >> score;
	}
	void disp()
	{
		person::disp();
		{
			cout << "classnum: " << classnum << endl;
			cout << "score: " << score << endl;
		}
	}

private:
	string classnum;
	float score;
};

class teacher :public person         //teacher派生类
{
public:
	void input()
	{
		person::input();
		cout << "title: ";
		cin >> title;
		cout << "department: ";
		cin >> department;
	}
	void disp()
	{
		person::disp();
		{
			cout << "title: " << title << endl;
			cout << "department: " << department << endl;
		}
	}
private:
	string title;
	string department;
};


//主程序
int main()
{
	student s1;
	teacher t1;
	cout << "Input a student's data:\n";
	s1.input();
	cout << "Input a teacher's data:\n";
	t1.input();
	cout << "Display a student's data:\n";
	s1.disp();
	cout << "Display a teacher's data:\n";
	t1.disp();	
	Sleep(40000);
	return 0;
}