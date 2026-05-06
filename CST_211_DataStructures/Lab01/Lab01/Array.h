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
	int getStartIndex();
	void setStartIndex(int start_index);
	int getLength();
	int setLength(int length);

};

// Default Ctor : Creates the object we're creating and sets it to the base initializers 
template<typename T>
Array<T>::Array() : m_array(nullptr) , m_start_index(0) , m_length(0)
{
}
// Two Arg. Ctor: This lets the consumer initialize the new array to to the correct size
template<typename T>
Array<T>::Array(int length, int start_index) : m_length(length) , m_start_index(start_index)
{
	if (length < 0) 
	{
		throw Exception("The length cannot be negative");
	}

	m_array = new T[length];
}

/* Copy Ctor : this ctor creates a new array with the data type T, with the same length as the originally, this dynamically allocates the space needed for the copy
			  then in the function we are going to loop through the array setting the size to the size needed, then copying the data to the new copy for each index
*/
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
//you can use base member initializion with every ctor and you should use it whenever you can

// Move Ctor : Here instead of creating a new array that needs to be copied one by one, we will just move what was created to the old spot, then delete that old data by setting it to 0/null
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

// Copy Assignment: We again are going to copy everything using a loop, making sure to copy everything needed into "this" first and dynamically  allocating the space needed
//                  Then using the loop we deep copy everything from "rhs" into "this" which is the current object for the code
template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& rhs)
{
	if (this != &rhs)
	{
		delete[] m_array;
		m_array = new T[rhs.m_length];

		for (int e = 0; e < rhs.m_length; e++)
		{
			m_array[e] = rhs.m_array[e];
		}

		m_length = rhs.m_length;
		m_start_index = rhs.m_start_index;

	} return *this;
}

// Move Assignment: This is the current objects data, we first clear up space needed, then move everything into "this", after moving eveything, we then clear up space in the original places
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

//Default Dtor: Cleans up all dynamically allocated memory  for cleanup
template<typename T>
Array<T>::~Array()
{
	delete[] m_array;

	m_array = nullptr;
	m_start_index = 0;
	m_length = 0;
}

template<typename T>
T& Array<T>::operator[](int index)
{
	if (index < m_start_index)
	{
		throw Exception("Index cannot be negative");
	}

	if (index >= m_length + m_start_index)
	{
		throw Exception("Index out of bounds");
	}

	return m_array[index - m_start_index];
}

template<typename T>
int Array<T>::getStartIndex()
{
	return m_start_index;
}

template<typename T>
void Array<T>::setStartIndex(int start_index)
{
	m_start_index = start_index;
}

template<typename T>
int Array<T>::getLength()
{
	return m_length;
}

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