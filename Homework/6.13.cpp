#include<iostream>
using namespace std;
template<class Type>
void sort(Type *Array, int size)
{
	int i, j;
	for (i = 0; i<size; i++)
		for (j = 0; j<size; j++)
			if (Array[i]<Array[j])
			{
				Type temp = Array[j];
				Array[j] = Array[i];
				Array[i] = temp;
			}
	for (i = 0; i < size; i++)
		cout << Array[i] << " ";
	cout << endl;
}

int main()
{
	int intArray[] = { 11, 12, 13, 14, 7, 8, 9 };
	double doubleArray[] = { 11.2, 12.3, 13.2, 14.5, 14.8, 8.7, 9.3 };
	sort(intArray, 7);
	sort(doubleArray, 7);
	system("pause");
	return 0;
}

