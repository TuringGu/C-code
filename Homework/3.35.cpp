#include<iostream>
#include<string>
using namespace std;
const int MAXSIZE=100;
class Stock{
public:
	Stock()
	{
		strcpy_s(stockcode, " ");
	}
	Stock(char na[MAXSIZE], int q = 1000, double p = 8.98)
	{
		strcpy_s(stockcode, na);
		quan = q;
		price = p;
	}
	void print()
	{
		cout << stockcode<<"  " << quan <<"  "<< price << endl;
	}
private:
	char stockcode[MAXSIZE];
	int quan;
	double price;
};



int main()
{
	Stock A("600001",3000,5.67);
	Stock B("600001");
	A.print();
	B.print();
	char x;
	cin >> x;
	return 0;
}