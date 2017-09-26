/******************************************************** 
 Project:	Student Management System 
 Author :	TuringGu
 Data   :	2015/5/26
*********************************************************/

#include<iostream>
#include<string>
using namespace std;
typedef int status;
typedef char ElemType;
#define MaxSize 100

//---------------------------------------------------------
typedef struct                   // Define element type Achievement
{
	int Math; int C; int English; int Sports;
}Achievement;
typedef struct                   // Define element type Sum
{
	int Math; int C; int English; int Sports;
}Sum;
typedef struct                   // Define element type Max
{
	int Math; int C; int English; int Sports;
}Max;
typedef struct                   // Define element type Min
{
	int Math; int C; int English; int Sports;
}Min;
typedef struct                   // Define element type Rate
{
	float Math; float C; float English; float Sports;
}Rate;                           
typedef struct                   // Define element type Average
{
	float Math; float C; float English; float Sports;
}Average;
//----------------------------------------------------------

class Student                    // Define base class Student
{
private:
	string ID;
	Achievement score;
public:
	Student()                    // Initialize
	{
		ID = "Empty";
		score.Math = score.C = score.English = score.Sports = 0;
	}
	void Input();              // Declare Input
	void Disp();               // Declare Disp
	virtual int CutOut();              // Define virtual function CutOut
	string Visit_ID(){ return ID; }        // Define member function Visit_PlateNum   
	virtual int Visit_score_Math(){ return score.Math; }
	virtual int Visit_score_C(){ return score.C; }
	virtual int Visit_score_English(){ return score.English; }
	virtual int Visit_score_Sports(){ return score.Sports; }
};


// Data entered
void Student::Input()              
{
	string num; Achievement S;
	cout << "Please input these informations:" << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "ID     : "; cin >> num; 
	cout << "Math   : "; cin >> S.Math;
	cout << "C      : "; cin >> S.C;
	cout << "English: "; cin >> S.English;
	cout << "Sports : "; cin >> S.Sports;
	cout << "------------------------------------------------------------------------------" << endl;
	ID = num;
	score.Math = S.Math;       score.C = S.C;
	score.English = S.English; score.Sports = S.Sports;
	system("cls");
}


// Data print
void Student::Disp()              
{
	cout << "Display:" << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "ID:  " << ID << "        " << endl;
	cout << "Math   :" << score.Math << "      " << "C:" << score.C++ << endl;
	cout << "English:" << score.English << "      " << "Sports:" << score.Sports << endl;
	cout << "------------------------------------------------------------------------------" << endl;
}


// Data delete
int Student::CutOut()
{
	ID = "Empty";
	score.Math = score.C = score.English = score.Sports = 0;
	return 0;
}


// Search
void Seek(Student C[], int &pn)
{
	string num; int i = 0; pn = 0;
	cout << "seek" << endl << "ID:"; cin >> num;
	for (i = 1; i <= MaxSize; i++)
	{
		if (num == C[i].Visit_ID())
		{
			pn = i; break;
		}
	}
	system("cls");
}


// Main function
int main()
{
	int i = 0; int j = 1; int n = 0; int k = 1; int pn = 0; int m=0;
	Sum sum; Max max; Min min; Rate rate; Average average; float num = 0.0;
	int rm, rc, re, rs; rm = rc = re = rs = 0; int nopass = 0; int hehe[MaxSize + 1]; int he = 0; int h = 0;
	sum = { 0, 0, 0, 0 }; max = { 0, 0, 0, 0 }; min = { 101, 101, 101, 101 };
	rate = { 0.0, 0.0, 0.0, 0.0 }; average = { 0.0, 0.0, 0.0, 0.0 };
	Student S[MaxSize + 1];                                      // Define the max size of the stuents
	while (j)
	{
		cout << "Orders:" << endl;
		cout << "1:add    2:cut out    3:alter " << endl;        // Command prompt
		cout << "4:show   5:show all   6:information processing"<< endl;
		cout << "7:end" << endl;
		cin >> i;
		system("cls");
		switch (i)
		{
		case 1:                                                  // Add
		{
			if (k > 100)
			{
				system("cls");
				cout << "OVERFLOW!" << endl;
				system("pause"); system("cls");
				break;
			}
			system("cls");
			S[k].Input(); k++;
			break;
		}
		case 2:                                                   // Delete
		{
			Seek(S, pn);
			if (pn == 0)
			{
				system("cls");
				cout << "not found!" << endl;
				system("pause"); system("cls");
				break;
			}
			else
			{
				if (!S[pn].CutOut())
				{
					system("cls");
					cout << "succeed!" << endl;
					system("pause"); system("cls");
					break;
				};
			}
		}
		case 3:                                                   // Update
		{
			Seek(S, pn);
			if (pn == 0)
			{
				system("cls");
				cout << "not found!" << endl;
				system("pause"); system("cls");
				break;
			}
			else
			{
				system("cls");
				S[pn].Input();
				break;
			}
		}
		case 4:                                                   // Print
		{
			Seek(S, pn);
			if (pn == 0)
			{
				system("cls");
				cout << "not found!" << endl;
				system("pause"); system("cls");
				break;
			}
			else
			{
				system("cls");
				S[pn].Disp();
				system("pause"); system("cls");
				break;
			}
		}
		case 5:                                                   // Print all
		{
			for (m = 0; m < MaxSize + 1; m++)
			{
				if (S[m].Visit_ID() != "Empty")
					S[m].Disp();
			}
			system("pause"); system("cls");
			break;
		}
		case 6:                                                   // Information processing
		{
			for (m = 0; m < MaxSize + 1; m++)
			{
				if (S[m].Visit_ID() != "Empty")
				{
					num++; 
					if (max.C < S[m].Visit_score_C()) max.C = S[m].Visit_score_C();    //max
					if (max.English < S[m].Visit_score_English()) max.English = S[m].Visit_score_English();
					if (max.Math < S[m].Visit_score_Math()) max.Math = S[m].Visit_score_Math();
					if (max.Sports < S[m].Visit_score_Sports()) max.Sports = S[m].Visit_score_Sports();
					if (min.C > S[m].Visit_score_C()) min.C = S[m].Visit_score_C();    //min
					if (min.English > S[m].Visit_score_English()) min.English = S[m].Visit_score_English();
					if (min.Math > S[m].Visit_score_Math()) min.Math = S[m].Visit_score_Math();
					if (min.Sports > S[m].Visit_score_Sports()) min.Sports = S[m].Visit_score_Sports();
					sum.C += S[m].Visit_score_C();                                   //sum
					sum.English += S[m].Visit_score_English();
					sum.Math += S[m].Visit_score_Math();
					sum.Sports += S[m].Visit_score_Sports();
					average.C = sum.C / num;                                       //average
					average.English = sum.English / num;
					average.Math = sum.Math / num;
					average.Sports = sum.Sports / num;
					if (S[m].Visit_score_Math() >= 60) rm++;
					else nopass = 1;
					if (S[m].Visit_score_C() >= 60) rc++;
					else nopass = 1;
					if (S[m].Visit_score_English() >= 60) re++;
					else nopass = 1;
					if (S[m].Visit_score_Sports() >= 60) rs++;
					else nopass = 1;
				}
				if (nopass){ hehe[he] = m; he++; }
				nopass = 0;
			}
			rate.C = rc / num; rate.English = re / num; rate.Math = rm / num; rate.Sports = rs / num;
			cout << "--------------------------------------------------------------------------" << endl;
			cout << "student(s) number: " << num << endl;
			cout << "       |max     min     average          rate(%)" << endl;
			cout << "math   |" << max.Math << "\t" << min.Math << "\t" << average.Math << "\t         " << rate.Math*100<< endl;
			cout << "C++    |" << max.C << "\t" << min.C << "\t" << average.C << "\t         " << rate.C * 100 << endl;
			cout << "English|" << max.English << "\t" << min.English << "\t" << average.English << "\t         " << rate.English * 100 << endl;
			cout << "Sports |" << max.Sports << "\t" << min.Sports << "\t" << average.Sports << "\t         " << rate.Sports * 100 << endl;
			cout << "--------------------------------------------------------------------------" << endl;
			cout << "These students didn't pass:" << endl;
			for (h = 0; h < he; h++)
			{
				cout << S[hehe[h]].Visit_ID(); cout << "\t";
			}
			system("pause"); system("cls");
			break;
		}
		case 7:                                                   // End 
		{
			system("cls"); j = 0;
			cout << "Thanks for your using!" << endl;
			system("pause");
			break;
		}
		default:
		{
			cout << "error order!" << endl;
			system("pause"); system("cls");
		}
		}
	}
	return 0;
}

