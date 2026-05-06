/*************************************************************
* Author: Kayleb Cook
* Filename: Lab04.cpp
* Date Created: 1/22/25
* Modifications:
*	1/22/25 - Created Files & Classes
*	1/23/25 - Fixed SetRow, and SetColumn functions
*				As well as finished lab
**************************************************************/

/************************************************************************
* Class: Array2D
*
* Purpose: This class creates a dynamic two-dimensional array that can be
* started at any base.
*
* Manager functions:
*	Array2D(); default ctor
*	Array2D(int rows, int columns); 2 arg ctor
*	Array2D(const Array2D<T>& copy); copy ctor
*	Array2D<T>(Array2D<T>&& move) noexcept; move ctor
*	Array2D<T>& operator=(const Array2D<T>& copy); copy assignment
*	Array2D<T>& operator=(Array2D<T>&& move) noexcept; move assignment
*	~Array2D(); default dtor
*
* Methods:
*	int getRow() const; 
*	- returns rows
*	int getColumns() const;
*	- returns columns
*
*	void setRows(int rows);
*	- sets the amount of rows 
*	void setColumns(int columns);
*	- sets the amount of columns
*
*	Row<T> operator[](int row);
*	- Accesses our array at a certain row
* 
*	T& Select(int desired_row, int desired_column);
*	- Accesses our array at a certain row and certain collumn 
*
*************************************************************************/

#pragma once
#include <stdexcept>
#include "Exception.h"
#include "Row.h"

template <typename T>
class Array2D {
private: 
	T** m_array;
	int m_rows;
	int m_columns;

public: 
	Array2D();
	Array2D(int rows, int columns);
	Array2D(const Array2D<T>& copy);
	Array2D<T>(Array2D<T>&& move) noexcept;
	Array2D<T>& operator=(const Array2D<T>& copy);
	Array2D<T>& operator=(Array2D<T>&& move) noexcept;
	~Array2D();
	
	int getRow() const;
	int getColumns() const;
	
	void setRows(int rows);
	void setColumns(int columns);
	
	Row<T> operator[](int row);
	T& Select(int desired_row, int desired_column);
};

/**********************************************************************
* Purpose: This function creates our 2D-Array object, and sets it to a 
*			default state
*
* Precondition:
* No precondition other than the class being made and initialized
*
* Postcondition:
* Will create our Array and set it to a default state
*
************************************************************************/
template<typename T>
Array2D<T>::Array2D() : m_array(nullptr) , m_rows(0) , m_columns(0)
{
}

/**********************************************************************
* Purpose: This function is to set our created array's size to an inputed
*			amount of rows and columns.
*
* Precondition:
* The precondition is that the inputed amount of rows must be positive.
* and the inputed amount of columns must be positive
*
* Postcondition:
* A new Array is created with a certain amount of rows, as well as a
* certain amount of columns, and then calls setLength in our array class
* to create the 2D array
*
************************************************************************/
template<typename T>
Array2D<T>::Array2D(int rows, int columns) : m_rows(rows) , m_columns(columns) , m_array(nullptr)
{							     // use base member initialization to make sure m_array is clear
	if (rows < 0 || columns < 0) // throw exception if the inputed numbers are negative 
	{
		throw Exception("out of bounds");
	}

	m_array = new T * [rows];        // create new array with the number of rows we want
	for (int e = 0; e < rows; e++)
	{
		m_array[e] = new T[columns]; // now create another array with the number of collumns we want and copy all the rows 
	}
}

/**********************************************************************
* Purpose: This function will copy the array and all the rows and columns 
*
* Precondition:
* The only precondition is that the array being copied, must exist first
* otherwise no precondition.
*
* Postcondition:
* Will copy the array as well as the amount of rows and columns 
*
************************************************************************/
template<typename T>
Array2D<T>::Array2D(const Array2D<T>& copy) : m_array(nullptr) , m_rows(copy.m_rows) , m_columns(copy.m_columns)
{
	m_array = new T * [m_rows];
	for (int i = 0; i < m_rows; i++)
	{
		m_array[i] = new T[m_columns];
		for (int e = 0; e < m_columns; e++)
		{
			m_array[i][e] = copy.m_array[i][e];
		}
	}
}

/**********************************************************************
* Purpose: This function will copy the array and all the rows and columns
*			into an address that already exists
*
* Precondition:
* The only precondition is that the array being copied, must exist first
* otherwise no precondition.
*
* Postcondition:
* Will copy the array as well as the amount of rows and columns
*
************************************************************************/
template<typename T>
Array2D<T>& Array2D<T>::operator=(const Array2D<T>& copy)
{
	if (this != &copy)
	{
		for (int e = 0; e < m_rows; e++)
		{
			delete[] m_array[e];
		}
		delete[] m_array;

		m_rows = copy.m_rows;
		m_columns = copy.m_columns;

		m_array = new T * [m_rows];
		for (int i = 0; i < m_rows; i++)
		{
			m_array[i] = new T[m_columns];
			for (int e = 0; e < m_columns; e++)
			{
				m_array[i][e] = copy.m_array[i][e];
			}
		}
	}
	return *this;
}

/**********************************************************************
* Purpose: This function will move the array and all the rows and columns
*
* Precondition:
* The only precondition is that the array being moved, must exist first
* otherwise no precondition.
*
* Postcondition:
* Will move the array as well as the amount of rows and columns
*
************************************************************************/
template<typename T>
Array2D<T>::Array2D(Array2D<T>&& move) noexcept : m_array(move.m_array), m_rows(move.m_rows), m_columns(move.m_columns)
{
	move.m_array = nullptr;
	move.m_rows = 0;
	move.m_columns = 0;
}

/**********************************************************************
* Purpose: This function will move the array and all the rows and columns
*			into an address that already exists 
*
* Precondition:
* The only precondition is that the array being moved, must exist first
* otherwise no precondition.
*
* Postcondition:
* Will move the array as well as the amount of rows and columns
*
************************************************************************/
template<typename T>
Array2D<T>& Array2D<T>::operator=(Array2D<T>&& move) noexcept
{
	if (this != &move)
	{
		m_array = move.m_array;
		m_rows = move.m_rows;
		m_columns = move.m_columns;

		move.m_array = nullptr;
		move.m_rows = 0;
		move.m_columns = 0;
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
* Will set the rows and columns to a default state (as in 0) to delete
* the array
*
************************************************************************/
template<typename T>
Array2D<T>::~Array2D()
{
	for (int i = 0; i < m_rows; i++)
	{
		delete[] m_array[i];
	}
	delete[] m_array;
	m_rows = 0;
	m_columns = 0;
}

/**********************************************************************
* Purpose: This function returns the amount of rows
* 
* Precondition:
* No precondition, other than the array existing
*
* Postcondition:
* Will return the amount of rows
*
************************************************************************/
template<typename T>
int Array2D<T>::getRow() const
{
	return m_rows;
}

/**********************************************************************
* Purpose: This function returns the amount of columns
*
* Precondition:
* No precondition, other than the array existing
*
* Postcondition:
* Will return the amount of columns
*
************************************************************************/
template<typename T>
int Array2D<T>::getColumns() const
{
	return m_columns;
}

/**********************************************************************
* Purpose: This function sets the amount of rows
*
* Precondition:
* Precondition is that the inputed amount of rows canot be negative 
*
* Postcondition:
* Will set the new amount of rows in our 2D array by creating a new array
* for the amount of rows, then copy the same amount of columns, and copy
* all the data into that new array with the new amount of rows. Then will
* set that new array as our default array.
*
************************************************************************/
template<typename T>
void Array2D<T>::setRows(int rows)
{
	if (rows < 0) // If the inputed amount of rows is negative, throw exception
	{
		throw Exception("Rows cannot be negative");
	}
	
	T** newArray = new T * [rows];          // create a new array of pointers with the inputed row values
	for (int i = 0; i < rows; i++)
	{
		if (i < m_rows)                        // checking if the inputed rows are less than the set rows
		{									   // if they are, then we account the columns different so the data is stored correctly. So we can store the data in the missing amount of columns
			newArray[i] = new T[m_columns];    // create the columns for the Array
			for (int e = 0; e < m_columns; e++)
			{
				newArray[i][e] = m_array[i][e]; // now copy all the columns into the newArray
			}
		}
		else
		{
			newArray[i] = new T[m_columns];     // if the inputed rows is greater than the the old amount, then we can copy the columns normally
		}
	}
	
	for (int e = 0; e < m_rows; e++)
	{
		delete[] m_array[e];
	}
	delete[] m_array;

	m_array = newArray;
	m_rows = rows;
}

/**********************************************************************
* Purpose: This function sets the amount of columns
*
* Precondition:
* Precondition is that the inputed amount of columns canot be negative
*
* Postcondition:
* Will create a new array with the desired amount of columns, then copy
* everything from that old array into the new array with the new amount 
* of columns.
*
************************************************************************/
template<typename T>
void Array2D<T>::setColumns(int columns)
{
	if (columns < 0) // If the inputed amount of columns is negative, throw exception
	{
		throw Exception("Columns cannot be negative");
	}

	int columnCount = std::min(m_columns, columns);
	for (int i = 0; i < m_rows; i++)
	{
		T* newRow = new T[columns];
		
		for (int e = 0; e < columnCount; e++)
		{
			newRow[e] = m_array[i][e];
		}
		delete[]m_array[i];
		m_array[i] = newRow;
	}
	m_columns = columns; // set m_columns to the inputed columns
}

/**********************************************************************
* Purpose: This function accesses a row at a desired index
*
* Precondition:
* Precondition is that the inputed index of rows canot be negative
* and cannot be greater than the already set amount of rows
*
* Postcondition:
* Will return a row with the slected row input
*
************************************************************************/
template<typename T>
Row<T> Array2D<T>::operator[](int row)
{
	if (row < 0 || row >= m_rows)
	{
		throw Exception("Index out of bounds");
	}
	return Row<T> (*this , row);
}

/**********************************************************************
* Purpose: This function will access data at a specific row and column
*
* Precondition:
* Precondition is that the inputed row and inputed column we want to access
* cannot be negative and cannot be greater than the already set amount of 
* rows and columns 
*
* Postcondition:
* Will access the array at the deisred row and column
************************************************************************/
template<typename T>
T& Array2D<T>::Select(int desired_row, int desired_column)
{
	if (desired_row < 0 || desired_row >= m_rows) // if the desired row is negative or if its greater than m_rows, throw out of bounds exception
	{
		throw Exception("Row index out of bounds");
	}
	if (desired_column < 0 || desired_column >= m_columns) // if the desired column is negative or greater than m_columns, throw out of bounds exception
	{
		throw Exception("Column index out of bounds");
	}

	return m_array[desired_row][desired_column]; // if not^^^ then return the desired row * the amount of columns, then at the column you are trying to access 
}
