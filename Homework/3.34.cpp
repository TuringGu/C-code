#include<iostream>
using namespace std;
class book{
public:
	book(int a);
	void show();
private:
	int qu;
	int price;
};

book::book(int a)
{
	qu = a;
	price = 10 * qu;
}

void book::show()
{
	cout << qu*price << endl;
}

int main()
{
	book A[5] = {
		book(1),
		book(2),
		book(3),
		book(4),
		book(5)
	};
	book *ptr;
	ptr = A;
	for (int i = 4; i>=0; i--)
	{
		(ptr+i)->show();
	}
	char x;
	cin >> x;
	return 0;
}

