/*************************************************************
* Author: Kayleb Cook
* Filename: Lab03.cpp
* Date Created: 1/16/25
* Modifications:
*	1/16/25 - Created Files & Classes
*	1/17/25 - Implemented Array2D classes
*	1/19/25 - Figured out how and when I need to call
*				functions from Array.h
*	1/21/25 – Fixed Subscript Operator
**************************************************************/

/************************************************************************
* Class: Row
*
* Purpose: This class will create the rows for our 2D Array class, and 
* intialize them to a default state.
*
* Manager functions:
* Row<T>(Array2D<T>& array2D, int row)
*	- This is our default constructor, that will intialize our row variable
*	  by creating an array by calling our 2D array class, and establishes
*	  the rows. It establishes everything to a default state.
* 
* Methods: 
* T& operator[](int column) const
*	- Subscript operator for columns, will access the 2D array at the current
*	  Row and the designated input column 
* 
*************************************************************************/


#pragma once
#include <iostream>

template<typename T>
class Array2D;

template <typename T>
class Row {
public: 
	friend class Array2D<T>;
	Row<T>(Array2D<T>& array2D, int row);
	T& operator[](int column) const;

private:
	Array2D<T>& m_array2D;
	int m_row;
};

/**********************************************************************
* Purpose: This function is the default construxtor for the Row class,
			It will create the array and initialize the rows, as well
			as the array to the inputed default state.
*
* Precondition: 
* The precondition is that the 2D array class must exist, and be able to 
* be called and an array to be made with this function. 
* The other precondition is that the inputed row cannt be negative nor can
* be greater than the existing rows 
* 
* Postcondition:
* Will create an array with the number of rows initiated, and set them
*
************************************************************************/
template<typename T>
Row<T>::Row(Array2D<T>& array2D, int row) : m_array2D(array2D) , m_row(row)
{
	//Row Ctor; uses base member intialization to create our array2d and row member variables 

	if (row < 0 || row >= m_array2D.getRow())
	{
		throw Exception("Index is out of bounds");
	}
}

/**********************************************************************
* Purpose: This function accesses our column elements at a certain index
		   but the const ensures that 
*
* Precondition:
* The precondition is that the Array must first of course exist, but also
* the inputed column must not be negative, nor greater than the current 
* amount of columns 
*
* Postcondition:
* Will access the designated column that was inputed, by calling select
* and selecting that certiain column
*
************************************************************************/
template<typename T>
T& Row<T>::operator[](int column) const
{
	if (column < 0 || column >= m_array2D.getColumns())
	{
		throw Exception("Index is out of bounds");
	}
	return m_array2D.Select(m_row, column);
}
