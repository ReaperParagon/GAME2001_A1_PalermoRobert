#include <iostream>
#include "UnorderedArray.h"

using namespace std;

int main()
{
	cout << "Merge Sort Algorithm" << endl;

	UnorderedArray<int> array(1);

	cout << "Grow Size is: " << array.GetGrowSize() << endl;

	array.push(80);
	array.push(64);

	cout << "Grow Size is: " << array.GetGrowSize() << endl;

	array.push(99);
	array.push(76);

	cout << "Grow Size is: " << array.GetGrowSize() << endl;

	array.push(5);

	cout << "Grow Size is: " << array.GetGrowSize() << endl;

	cout << "Before sort: ";
	for (int i = 0; i < array.GetSize(); i++)
	{
		cout << " " << array[i];
	}

	cout << endl;

	array.MergeSort();

	cout << "After sort: ";
	for (int i = 0; i < array.GetSize(); i++)
	{
		cout << " " << array[i];
	}

	cout << endl << endl;

	return 0;
}