#include <iostream>
#include "OrderedArray.h"
#include "UnOrderedArray.h"

using namespace std;

int main()
{
	// Creation of both Ordered and Unordered arrays
	UnorderedArray<int> arrayUnOrd(1);
	OrderedArray<int> arrayOrd(1);

	// 1) Shared Array Functionality
	cout << "Shared Array functionality" << endl;
	cout << "--------------------" << endl;

	// Growing by increasing value (2,4,8,16...)
	cout << "Expanding by an increasing value:" << endl;
	cout << "Array Max Size: " << arrayUnOrd.GetMaxSize() << endl;

	cout << "First we Push 2 items into the array..." << endl;
	arrayUnOrd.push(80);
	arrayUnOrd.push(94);	// Grows by 2	

	cout << "Array Max Size: " << arrayUnOrd.GetMaxSize() << endl;

	cout << "Array grew by 2, and now we push 2 more items into the array..." << endl;
	arrayUnOrd.push(99);
	arrayUnOrd.push(76);	// Grows by 4

	cout << "Array Max Size: " << arrayUnOrd.GetMaxSize() << endl;

	cout << "Array grew by 4..." << endl;
	cout << endl;

	// 2) Demonstrating Unoredered Array Functionality
	cout << "Unordered Array Sorting Functionality:" << endl;
	cout << "--------------------" << endl;
	cout << "Before sort: ";
	for (int i = 0; i < arrayUnOrd.GetSize(); i++)
	{
		cout << " " << arrayUnOrd[i];
	}

	cout << endl;

	// arrayUnOrd.BubbleSort();
	// arrayUnOrd.SelectionSort();
	// arrayUnOrd.InsertionSort();
	arrayUnOrd.MergeSort();

	cout << "After sort: ";
	for (int i = 0; i < arrayUnOrd.GetSize(); i++)
	{
		cout << " " << arrayUnOrd[i];
	}
	cout << endl << endl;

	// 3) Demonstrating Ordered Array Functionality
	// I. Preventing Duplicate data
	cout << "Ordered Array, Preventing duplicate data:" << endl;
	cout << "--------------------" << endl;

	cout << "First we push 5 numbers into the array..." << endl;
	arrayOrd.push(32);
	arrayOrd.push(64);
	arrayOrd.push(72);
	arrayOrd.push(94);
	arrayOrd.push(13);

	cout << "Ordered Array: ";
	for (int i = 0; i < arrayOrd.GetSize(); i++)
	{
		cout << " " << arrayOrd[i];
	}

	// Trying to add duplicate data
	cout << endl << "Now we try to push 72 and 13 into the array again..." << endl;
	arrayOrd.push(72);
	arrayOrd.push(13);

	cout << "Ordered Array: ";
	for (int i = 0; i < arrayOrd.GetSize(); i++)
	{
		cout << " " << arrayOrd[i];
	}
	cout << endl << "There are no duplicate numbers!" << endl;

	// II. Search Functionality
	cout << endl << "Ordered Array's Binary Search" << endl;
	cout << "--------------------" << endl;
	cout << "Searching for index of 72" << endl;

	cout << "Found 72 at index: " << arrayOrd.search(72) << endl;

	cout << endl << endl;

	return 0;
}