#include<iostream>
using namespace std;
template<class Type>           //函数模板
Type max(Type *Array, int size)
{
	int i; int j = 0;
	for (i = 1; i<size; i++)
	{
		if (Array[j]<Array[i])
			j = i;
	}
	return Array[j];
}

int main()
{
	int intArray[] = { 11, 12, 13, 14, 7, 8, 9 };
	double doubleArray[] = { 11.2, 12.3, 13.2, 14.5, 14.8, 8.7, 9.3 };
	cout << max(intArray, 7) << endl;
	cout << max(doubleArray, 7) << endl;
	system("pause");
	return 0;
}