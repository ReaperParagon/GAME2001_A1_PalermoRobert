#pragma once
#include <cassert>
#include "Array.h"

template<class T>
class UnorderedArray : public Array<T>
{
public:
	// Constructor
	UnorderedArray(int size, int growBy = 1) : Array<T>(size, growBy)
	{}
	// Insertions
	// Fast insertion for UnorderedArray -- Big-O is O(1)
	virtual int push(T val)
	{
		assert(Array<T>::m_array != NULL);	// Debugging purposes

		if (Array<T>::m_numElements >= Array<T>::m_maxSize)
		{
			Array<T>::Expand();
		}

		// My array has space for the new value
		Array<T>::m_array[Array<T>::m_numElements] = val;
		Array<T>::m_numElements++;

		return Array<T>::m_numElements - 1;
	}
	// Searching (Linear search) -- Big-O = O(N)
	int search(T val)
	{
		assert(Array<T>::m_array != NULL);

		// Brute-froce search
		for (int i = 0; i < Array<T>::m_numElements; i++)
		{
			if (Array<T>::m_array[i] == val)
			{
				return i;
			}
		}

		return -1;
	}
	// ------------ SORTING ALGORITHMS ------------
	// Bubble Sort -- Big O = O(N^2)
	void BubbleSort()
	{
		assert(Array<T>::m_array != NULL);

		T temp;

		for (int k = Array<T>::m_numElements - 1; k > 0; k--)
		{
			// Comparing 2 adjacent elements
			for (int i = 0; i < k; i++)
			{
				if (Array<T>::m_array[i] > Array<T>::m_array[i + 1])
				{
					// Swap the elements
					temp = Array<T>::m_array[i];
					Array<T>::m_array[i] = Array<T>::m_array[i + 1];
					Array<T>::m_array[i + 1] = temp;
				}
			}
		}
	}
	// Selection Sort -- Big O = O(N^2)
	void SelectionSort()
	{
		assert(Array<T>::m_array != NULL);

		T temp;
		int min = 0;

		// The lowest position to swap the smallest element to...
		for (int k = 0; k < Array<T>::m_numElements - 1; k++)
		{
			min = k;

			// Iterate through the array to find the smallest value
			for (int i = k + 1; i < Array<T>::m_numElements; i++)
			{
				if (Array<T>::m_array[i] < Array<T>::m_array[min])
				{
					// Store the index to the smallest element
					min = i;
				}
			}

			// Swapping of the lowest element with the lowest available index
			if (Array<T>::m_array[k] > Array<T>::m_array[min])
			{
				// Swap
				temp = Array<T>::m_array[k];
				Array<T>::m_array[k] = Array<T>::m_array[min];
				Array<T>::m_array[min] = temp;
			}
		}
	}
	// Insertion Sort -- Big O = O(N^2)
	void InsertionSort()
	{
		assert(Array<T>::m_array != NULL);

		T temp;
		int i = 0;

		for (int k = 1; k < Array<T>::m_numElements; k++)
		{
			temp = Array<T>::m_array[k];
			i = k;

			// Shifting of elements if necessary. Create a space for an element
			// to be inserted in the correct location
			while (i > 0 && Array<T>::m_array[i - 1] >= temp)
			{
				// Push elements to the right
				Array<T>::m_array[i] = Array<T>::m_array[i - 1];
				i--;
			}

			// Place the item in the correct location
			Array<T>::m_array[i] = temp;
		}
	}
	// Merge Sort -- Big O = O(N logN)
	void MergeSort()
	{
		assert(Array<T>::m_array != NULL);

		T* tempArray = new T[Array<T>::m_numElements];
		assert(tempArray != NULL);

		MergeSort(tempArray, 0, Array<T>::m_numElements - 1);
		delete[] tempArray;
	}
private:
	// Recursive Merge Sort
	void MergeSort(T* tempArray, int lowerBound, int upperBound)
	{
		// Base case
		if (lowerBound == upperBound)
		{
			return;
		}

		// Determine the middle of the array
		int mid = (lowerBound + upperBound) >> 1;

		MergeSort(tempArray, lowerBound, mid);		// Lower half MergeSort
		MergeSort(tempArray, mid + 1, upperBound);	// Upper half MergeSort

		// Merge
		Merge(tempArray, lowerBound, mid + 1, upperBound);
	}
	void Merge(T* tempArray, int low, int mid, int upper)
	{
		// LowerBound, Mid + 1, UpperBound
		int tempLow = low, tempMid = mid - 1;
		int index = 0;

		while (low <= tempMid && mid <= upper)
		{
			// Lower of the 2 values is smaller, move it to the tempArray
			if (Array<T>::m_array[low] < Array<T>::m_array[mid])
			{
				tempArray[index++] = Array<T>::m_array[low++];
			}
			else
			{
				tempArray[index++] = Array<T>::m_array[mid++];
			}
		}

		while (low <= tempMid)
		{
			tempArray[index++] = Array<T>::m_array[low++];
		}
		while (mid <= upper)
		{
			tempArray[index++] = Array<T>::m_array[mid++];
		}

		// Place the stored tempArray into the main array in the correct locations
		for (int i = 0; i < upper - tempLow + 1; i++)
		{
			Array<T>::m_array[tempLow + i] = tempArray[i];
		}
	}
private:
};