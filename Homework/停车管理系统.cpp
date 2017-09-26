#include<iostream>
#include<string>
using namespace std;
typedef int status;
typedef char ElemType;
int const MaxSize = 100;         //定义最大停车辆数

struct Time                      //定义结构体：时间
{
	int year; int month;  int day;
	int hour; int minute; int second;
}StartTime,LimitTime;

class Car                        //定义基类:车
{
private:
	string PlateNum;             //车牌号
	int LocationNum;             //停车位号码
	Time StartTime;              //停入时间
	Time LimitTime;              //截止时间
	int Money;                   //所交金额
public:
	Car()                        //初始化
	{
		PlateNum = "Empty"; LocationNum = 0;
		StartTime.year = StartTime.month = StartTime.day = StartTime.hour = StartTime.minute = StartTime.second = 0;
		LimitTime.year = LimitTime.month = LimitTime.day = LimitTime.hour = LimitTime.minute = LimitTime.second = 0;
		Money = 0;
	}
	void Input();              //声明Input
	void Disp();               //声明Disp
	virtual int CutOut();              //定义虚函数CutOut
	string Visit_PlateNum(){ return PlateNum; };        //声明成员函数Visit_PlateNum      
};

void Car::Input()              //录入数据
{
	string name; int ln; Time st; Time lt; int m;
	cout << "Please input these informations:" << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "PlateNum:  "; cin >> name;
	cout << "LocationNum: "; cin >> ln;
	cout << "StartTime: "<<endl;
	cout << "year: month: day: hour: minute: second: " << endl;
	cin >> st.year >> st.month >> st.day >> st.hour >> st.minute >> st.second;
	cout << "LimitTime: "<<endl;
	cout << "year: month: day: hour: minute: second: " << endl;
	cin >> lt.year >> lt.month >> lt.day >> lt.hour >> lt.minute >> lt.second;
	cout << "Money: "; cin >> m;
	cout << "------------------------------------------------------------------------------" << endl;
	PlateNum = name;
	LocationNum = ln;
	StartTime = st;
	LimitTime = lt;
	Money = m;
}

void Car::Disp()               //显示数据
{
	cout << "Display:" << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "PlateNum:  " << PlateNum << "        " << "LocationNum: " << LocationNum << endl;
	cout << "StartTime: " << endl;
	cout <<StartTime.year<<"/"<<StartTime.month<<"/"<<StartTime.day<<"  "<< StartTime.hour<<":"<<StartTime.minute<<":"<<StartTime.second << endl;
	cout << "LimitTime: " << endl;
	cout << LimitTime.year << "/" << LimitTime.month << "/" << LimitTime.day << "  " << LimitTime.hour << ":" << LimitTime.minute << ":" << LimitTime.second << endl;
	cout << "Money: " << Money << endl;
	cout << "------------------------------------------------------------------------------" << endl;
}

//删除
int Car::CutOut()
{
	PlateNum = "Empty"; LocationNum = 0;
	StartTime.year = StartTime.month = StartTime.day = StartTime.hour = StartTime.minute = StartTime.second = 0;
	LimitTime.year = LimitTime.month = LimitTime.day = LimitTime.hour = LimitTime.minute = LimitTime.second = 0;
	Money = 0;
	return 0;
}


//查找
void Seek(Car C[], int &pn)
{
	string name; int i = 0; pn = 0;
	cout <<"seek"<<endl<< "Please input the plate number of the car you want:"; cin >> name;
	for (i = 1; i <= MaxSize;i++)
	{
		if (name == C[i].Visit_PlateNum())
		{
			pn=i; break;
		}
	}
}



//主函数
int main()
{
	int i = 0; int j = 1; int n = 0; int k = 1; int pn = 0;
	Car C[MaxSize+1];                                            //定义最大停车辆数：1~100
	while (j)
	{
		cout << "Please input a order you want:" << endl;
		cout << "1:add" << "     " << "2:cut out" << endl;           //命令指示
		cout << "3:alter" << "   " << "4:show"<<"     "<<"5:end" << endl;
		cin >> i;
		switch (i)
		{
		case 1:                                                  //添加
		{
			if (k > 100){ cout << "OVERFLOW!" << endl; break; }
			C[k].Input(); k++;
			break;
		}
		case 2:                                                   //删除
		{
			Seek(C, pn);
			if (pn == 0){ cout << "Don't have such car's plate numbers." << endl; break; }
			else
			{
				if (!C[pn].CutOut()){ cout << "Cut out information successfully!" << endl; break; };
			}
		}
		case 3:                                                   //修改
		{
			Seek(C, pn);
			if (pn == 0){ cout << "Don't have such car's plate numbers." << endl; break; }
			else{ C[pn].Input(); break; }
		}
		case 4:                                                   //显示
		{
			Seek(C, pn);
			if (pn == 0){ cout << "Don't have such car's plate numbers." << endl; break; }
			else{ C[pn].Disp(); break; }
		}
		case 5:                                                   //结束 
		{
			j = 0;
			cout << "Thanks for your using!" << endl;
			break;
		}
		cout << "error order!" << endl;
		}
	}
	system("pause");
}