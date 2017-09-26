// [2.21] eg: "const" replace the "define" to eliminate the insecurity

#include<iostream>
using namespace std;
int main()
{
#define M1 a+b
#define M2 c*d
	int q, a = 1, b = 2, c = 3, d = 4;
	q = M1*M2;
	cout << "The incorrect result is " << q << "(define)" << endl;	// q = 25
	const int T1 = a + b;
	const int T2 = c*d;
	q = T1*T2;
	cout << "The correct result is " << q << "(const)" << endl;		// q = 14
}
