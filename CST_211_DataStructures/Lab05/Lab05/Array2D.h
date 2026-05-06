/*************************************************************
* Author: Kayleb Cook
* Filename: Lab05.cpp
* Date Created: 1/23/25
* Modifications:
*	1/23/25 - Created classes & started to set up cell class
*	1/24/25 - Finished cell class & started board class
*	1/25/25 - Finished board class & started working on minesweeper
*	1/26/25 - Applied finishing touches such as headers and cleaning
*			  up code
* 
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
#include "Array.h"


template <typename T>
class Array2D {
private: 
	Array<T> m_array;
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
Array2D<T>::Array2D() : m_array() , m_rows(0) , m_columns(0)
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
Array2D<T>::Array2D(int rows, int columns) : m_rows(rows) , m_columns(columns)
{
	if (rows < 0)
	{
		throw Exception("out of bounds");
	}
	if (columns < 0)
	{
		throw Exception("out of bounds");
	}
	
	m_array.setLength(rows * columns);
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
Array2D<T>::Array2D(const Array2D<T>& copy) : m_array(copy.m_array) , m_rows(copy.m_rows) , m_columns(copy.m_columns)
{
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
		m_array = copy.m_array;
		m_rows = copy.m_rows;
		m_columns = copy.m_columns;
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
* Will set the amount of rows to the inputed amount, and then set the length
* of the new 2D array by calling set length
*
************************************************************************/
template<typename T>
void Array2D<T>::setRows(int rows)
{
	if (rows < 0) // If the inputed amount of rows is negative, throw exception
	{
		throw Exception("Rows cannot be negative");
	}
	m_rows = rows; // set m_rows to the inputed rpws
	m_array.setLength(m_rows * m_columns); // now call array's setlength function with the rows and columns together
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

	Array<T> data(m_rows * columns);

	int columnCount = std::min(m_columns, columns);
	for (int i = 0; i < m_rows; i++)
	{
		for (int e = 0; e < columnCount; e++)
		{
			data[i * columns + e] = m_array[i * m_columns + e];
		}
	}

	m_columns = columns; // set m_columns to the inputed columns
	m_array = data; // now call array'setLength function with the rows and columns together
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
Row<T> Array2D<T>::operator[](int row) {
    if (row < 0 || row >= m_rows) {
        throw Exception("Index out of bounds");
    }
    return Row<T>(*this, row); // Assuming Row is a class that handles a row of the 2D array
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

	return m_array[desired_row * m_columns + desired_column]; // if not^^^ then return the desired row * the amount of columns, then at the column you are trying to access 
}

