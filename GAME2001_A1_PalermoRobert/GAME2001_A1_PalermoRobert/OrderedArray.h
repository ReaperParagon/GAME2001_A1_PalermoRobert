#pragma once
#include <cassert>
#include "Array.h"

template<class T>
class OrderedArray : public Array<T>
{
public:
	// Constructor
	OrderedArray(int size, int growBy = 2, bool allowDuplicates = false) 
		: Array<T>(size, growBy), m_allowDuplicates(allowDuplicates)
	{}
	// Insertion - Big-O = O(N)
	virtual int push(T val)
	{
		assert(this->m_array != NULL);

		if (this->m_numElements >= this->m_maxSize)
		{
			this->Expand();
		}

		int i, k;
		// Step 1: Find the index to insert val
		for (i = 0; i < this->m_numElements; i++)
		{
			if (this->m_array[i] > val)
			{
				break;
			}

			// Checking for Duplicate Data, return if there is
			if (!m_allowDuplicates && this->m_array[i] == val)
			{
				return -1;
			}
		}

		// Step 2: Shift everything to the right of the index forward by one
		for (k = this->m_numElements; k > i; k--)		// Moving backwards through the array starting at m_numElements
		{
			this->m_array[k] = this->m_array[k - 1];
		}

		// Step 3: Insert val into index
		this->m_array[i] = val;

		this->m_numElements++;

		return i;
	}
	// Searching
	int search(T searchKey)
	{
		// Call to binarysearch recursive function
		return binarySearch(searchKey, 0, this->m_numElements - 1);
	}
private:
	// Recursive Binary Search
	int binarySearch(T searchKey, int lowerBound, int upperBound)
	{
		assert(this->m_array != NULL);
		assert(lowerBound >= 0);
		assert(upperBound < this->m_numElements);

		// Bitwise divide by 2
		int current = (lowerBound + upperBound) >> 1;		// 2^1 == >> 1

		// Did we find the searchKey at current
		if (this->m_array[current] == searchKey)
		{
			// We have found the searchKey in the array. Return the index
			return current;
		}
		// Are we done searching?
		else if (lowerBound > upperBound)
		{
			// Did not find searchKey within m_array
			return -1;
		}
		// Which half is searchKey in?
		else
		{
			if (this->m_array[current] < searchKey)
			{
				// Search the upper half of the array
				return binarySearch(searchKey, current + 1, upperBound);
			}
			else
			{
				// Search the lower half of the array
				return binarySearch(searchKey, lowerBound, current - 1);
			}
		}

		return -1;
	}
private:
	// Variables
	bool m_allowDuplicates;
};