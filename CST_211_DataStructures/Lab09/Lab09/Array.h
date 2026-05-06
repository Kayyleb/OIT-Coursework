/*************************************************************
* Author: Kayleb Cook
* Filename: Lab06.cpp
* Date Created: 1/27/25
* Modifications:
*	1/27/25 - Created & Defined entire Stack class & wrote all tests
*	1/28/25 - Wrote all comment & comment blocks & checked for memory leaks
**************************************************************/

/************************************************************************
* Class: Array
*
* Purpose: This class creates a dynamic one-dimensional array that can be
* started at any base.
*
* Manager functions:
*	Array(); default ctor
*	Array(int length, int start_index = 0); 2 arg ctor
*	Array(const Array<T>& copy); copy ctor
*	Array(Array<T>&& move) noexcept; move ctor
*	Array<T>& operator=(const Array<T> &rhs); copy assignment
*	Array<T>& operator=(Array<T>&& rhs) noexcept; move assignment
*	~Array(); default dtor
*
* Methods:
* 	T& operator [](int index);
*	- Subscript operator will access the array at the set index
*	int getStartIndex();
*	- returns the start index
*	void setStartIndex(int start_index);
*	- sets the start index to whatever is inputed
*	int getLength();
*	- returns the length of the array
*	int setLength(int length);
*	- sets the length of the array to whatever inputed
* 
*************************************************************************/
#pragma once
#include <stdexcept>
#include "Exception.h"

template <typename T>
class Array {
private: 
	T* m_array;
	int m_start_index;
	int m_length;

public:
	Array();
	Array(int length, int start_index = 0);
	Array(const Array<T>& copy);
	Array(Array<T>&& move) noexcept;
	Array<T>& operator=(const Array<T> &rhs);
	Array<T>& operator=(Array<T>&& rhs) noexcept;
	~Array();

	T& operator [](int index);
	const T& operator[](int index) const;
	int getStartIndex();
	void setStartIndex(int start_index);
	int getLength() const;
	int setLength(int length);

};

/**********************************************************************
* Purpose: This function creates our Array object, and sets it to a default
*			state.
*
* Precondition:
* No precondition other than the class being made and initialized
*
* Postcondition:
* Will create our Array and set it to a default state
*
************************************************************************/

template<typename T>
Array<T>::Array() : m_array(nullptr) , m_start_index(0) , m_length(0)
{
}

/**********************************************************************
* Purpose: This function is to set our created array's size to an inputed
*			length and start index.
*
* Precondition:
* The precondition is that the inputed length must be positive.
*
* Postcondition:
* A new array is created with the set length, and if inputed will set the
* start index to an inputed value, but if nothing is inputed, will set the
* start index to 0, which is a c++ standard 
* 
************************************************************************/
template<typename T>
Array<T>::Array(int length, int start_index) : m_length(length) , m_start_index(start_index)
{
	if (length < 0) 
	{
		throw Exception("The length cannot be negative");
	}

	m_array = new T[length];
}

/**********************************************************************
* Purpose: This function creates a new array and copies all of the elements
*			into a new array.
*
* Precondition:
* The only precondition is that the array being copied, must exist first
* otherwise no precondition.
*
* Postcondition:
* Will create a new array with the same length and deep copy everything 
* from the old array into it using a loop.
*
************************************************************************/
template<typename T>
Array<T>::Array(const Array<T>& copy) : m_array(nullptr) , m_start_index(copy.m_start_index) , m_length(copy.m_length)
{
	if (copy.m_array != nullptr) // same thing as " if (copy.m_array) "
	{
		m_array = new T[copy.m_length];
		for (int e = 0; e < copy.m_length; e++)
		{
			m_array[e] = copy.m_array[e];
		}
	}
}

/**********************************************************************
* Purpose: This function moves our array to a different location
*
* Precondition:
* The only precondition is that the array being moved, must exist first
* otherwise no precondition.
*
* Postcondition:
* Will move the array to a new position, and then delete the old position
*
************************************************************************/
template<typename T>
Array<T>::Array(Array<T>&& move) noexcept
{
	m_array = move.m_array;
	m_start_index = move.m_start_index;
	m_length = move.m_length;

	move.m_array = nullptr;
	move.m_start_index = 0;
	move.m_length = 0;
}

/**********************************************************************
* Purpose: This function copies our array into an andress that already exists
*
* Precondition:
* preconditon is that the current array must not be the same one we are 
* copying to.
*
* Postcondition:
* Will create a new array with the same length and deep copy all the elements
* into the new array using a loop
*
************************************************************************/
template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& rhs)
{
	if (this != &rhs)
	{
		if (m_length != rhs.m_length)
		{
			delete[] m_array;
			m_array = new T[rhs.m_length];
		}
		for (int e = 0; e < rhs.m_length; e++)
		{
			m_array[e] = rhs.m_array[e];
		}
		m_length = rhs.m_length;
		m_start_index = rhs.m_start_index;

	} return *this;
}

/**********************************************************************
* Purpose: This function moves our array into an andress that already exists
*
* Precondition:
* preconditon is that the current array must not be the same one we are
* moving to.
*
* Postcondition:
* Will move the array to a new position, and then delete the old position
*
************************************************************************/
template<typename T>
Array<T>& Array<T>::operator=(Array<T>&& rhs) noexcept
{
	if (this != &rhs)
	{
		delete[] m_array;
		
		m_length = rhs.m_length;
		m_start_index = rhs.m_start_index;
		m_array = rhs.m_array;
		
		rhs.m_array = nullptr;
		rhs.m_length = 0;
		rhs.m_start_index = 0;
	}
	return *this;
}

/**********************************************************************
* Purpose: This function destroys everything and cleans up deleted objects
*
* Precondition:
* No precondition
*
* Postcondition:
* Will delete the array, but then will set all our member variables to
* a default state.
*
************************************************************************/
template<typename T>
Array<T>::~Array()
{
	delete[] m_array;

	m_array = nullptr;
	m_start_index = 0;
	m_length = 0;
}
/**********************************************************************
* Purpose: This function will access our array at a certain index
*
* Precondition:
* The precondition is the inputed index cannot be smaller than the current
* start index, as in it cannot be negative (since index in c++ starts at 0)
*
* Postcondition:
* Will access the designated column that was inputed
*
************************************************************************/
template<typename T>
T& Array<T>::operator[](int index)
{
	if (index < 0)
	{
		throw Exception("Index cannot be negative");
	}

	if (index >= m_start_index + m_length)
	{
		throw Exception("Index out of bounds");
	}

	return m_array[index - m_start_index];
}

template<typename T>
const T& Array<T>::operator[](int index) const
{
	if (index < 0)
	{
		throw Exception("Index cannot be negative");
	}

	if (index >= m_start_index + m_length)
	{
		throw Exception("Index out of bounds");
	}

	return m_array[index - m_start_index];
}

/**********************************************************************
* Purpose: This function will return our start index
*
* Precondition:
* No precondition, other than the array must exist
*
* Postcondition:
* Will return the current start index
*
************************************************************************/
template<typename T>
int Array<T>::getStartIndex()
{
	return m_start_index;
}

/**********************************************************************
* Purpose: This function will set the start index to whatever inputed
*
* Precondition:
* No precondition, other than the array must exist
*
* Postcondition:
* Will set the start index to whatever is inputed
*
************************************************************************/
template<typename T>
void Array<T>::setStartIndex(int start_index)
{
	m_start_index = start_index;
}

/**********************************************************************
* Purpose: This function will return the length of the array
*
* Precondition:
* No precondition, other than the array must exist
*
* Postcondition:
* Will return the length of the array
*
************************************************************************/
template<typename T>
int Array<T>::getLength() const
{
	return m_length;
}

/**********************************************************************
* Purpose: This function will set the length of the array
*
* Precondition:
* The length inputed cannot be negative & the array must exist
*
* Postcondition:
* Will create a new array with the inputed length, but will choose how
* much to copy to the new array. If the inputed length is smaller, will 
* only copy what it can hold, and if the inputed length is larger, then it
* will copy everything, and leave some space. 
*
************************************************************************/
template<typename T>
int Array<T>::setLength(int length)
{
	if (length < 0)
	{
		throw Exception("Length cannot be negative");
	}   // throwing an exception if the range is negative 


	T* nArray = new T[length];
    	
	if (length < m_length)
	{
		for (int e = 0; e < length; e++)
		{
			nArray[e] = m_array[e];
		}
	}
	if (length > m_length)
	{
		for (int e = 0; e < m_length; e++)
		{
			nArray[e] = m_array[e];
		}
	}

	delete[] m_array;
	
	m_array = nArray;
	m_length = length;

	return m_length;
}