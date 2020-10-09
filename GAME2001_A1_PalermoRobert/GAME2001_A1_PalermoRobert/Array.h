#pragma once
#include <cassert>

template<class T>
class Array
{
public:
	Array(int size, int growBy = 2) :
		m_array(NULL), m_maxSize(0), m_growSize(0), m_numElements(0)
	{
		if (size)
		{
			m_maxSize = size;
			m_array = new T[m_maxSize];		// Dynamically allocating an array to m_maxSize
			memset(m_array, 0, sizeof(T) * m_maxSize);	// Explicitly allocating memory based on the type T

			m_growSize = ((growBy > 0) ? growBy : 0);
		}
	}
	// Destructor
	~Array()
	{
		if (m_array != NULL)
		{
			delete[] m_array;
			m_array = NULL;
		}
	}
	// Deletion (2 ways)
	// Remove the last item inserted into the array
	void pop()
	{
		if (m_numElements > 0)
		{
			m_numElements--;
		}
	}
	// Remove an item given an index
	// (Almost) Brute-force execution -- Big-O = O(N)
	void remove(int index)
	{
		assert(m_array != NULL);

		if (index >= m_numElements)
		{
			return;
		}

		for (int i = index; i < m_numElements; i++)
		{
			if (i + 1 < m_numElements)
			{
				m_array[i] = m_array[i + 1];
			}
		}
		m_numElements--;
	}
	// Overload the [] operator
	T& operator[](int index)
	{
		assert(m_array != NULL && index < m_numElements);
		return m_array[index];
	}
	// Clear -- Big-O = O(1)
	void clear()
	{
		m_numElements = 0;
	}
	// Virtual Functions
	virtual int push(T val) = 0;
	// Gets and Sets
	int GetSize()
	{
		return m_numElements;
	}
	int GetMaxSize()
	{
		return m_maxSize;
	}
	int GetGrowSize()
	{
		return m_growSize;
	}
	void SetGrowSize(int val)
	{
		assert(val >= 0);
		m_growSize = val;
	}
protected:
	// Expansion
	bool Expand()
	{
		if (m_growSize <= 0)
		{
			return false;
		}

		// Create the new array
		T* temp = new T[m_maxSize + m_growSize];
		assert(temp != NULL);

		// Copy the contents of the original array to the new array
		memcpy(temp, m_array, sizeof(T) * m_maxSize);

		// Delete the old array
		delete[] m_array;

		// Clean up variable assignments
		m_array = temp;
		temp = NULL;

		m_maxSize += m_growSize;

		// Increasing grow size
		SetGrowSize(GetGrowSize() << 1);

		return true;
	}
protected:
	// Variables
	T* m_array;			// Pointer to the beginning of the array

	int m_maxSize;		// Maximum size of my array
	int m_growSize;		// Amount the array can grow through expansion
	int m_numElements;	// Number of items currently in my array
};
