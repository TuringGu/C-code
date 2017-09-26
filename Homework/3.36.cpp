#include<iostream>
#include<string>
const int MAXSIZE=33;
using namespace std;
class student{
public:
	student(string num1, string name1, float score1);
	void show();
	void show_count_sum_ave();
private:
	string num;
	string name;
	float score;
	static int count;
	static float sum;
	static float ave;
};

student::student(string num1, string name1, float score1)
{
	num = num1;
	name = name1;
	score = score1;
	++count;
	sum = sum + score;
	ave = sum / count;
}

void student::show()
{
	cout << "\n学号：" << num;
	cout << "\n姓名：" << name;
	cout << "\n成绩：" << score;
}

void student::show_count_sum_ave()
{
	cout << "\n学生人数：" << count;
	cout << "\n平均成绩：" << ave;
}

int student::count = 0;
float student::sum = 0.0;
float student::ave = 0.0;

int main()
{
	student stu1("Willium", "8008208820", 100);
	stu1.show();
	stu1.show_count_sum_ave();
	cout << "\n-------------\n";
	student stu2("Convict", "8008208821", 90);
	stu2.show();
	stu2.show_count_sum_ave();
	char x;
	cin >> x;
	return 0;
}


