/*************************************************************
* Author: Kayleb Cook
* Filename: Lab06.cpp
* Date Created: 1/27/25
* Modifications:
*	1/27/25 - Created & Defined entire Stack class & wrote all tests
*	1/28/25 - Wrote all comment & comment blocks & checked for memory leaks
**************************************************************/

/************************************************************************
* Class: Exception
*
* Purpose: This class is to create an Exception object that can be used to 
*		   throw and catch error messages.
*
* Manager functions:
*	Exception(); default ctor
*	~Exception(); default dtor
*	Exception(const char* msg); 1 arg ctor
*	Exception(const Exception& copy); copy ctor
*	Exception(Exception&& move) noexcept; move ctor
*	Exception& operator=(const Exception& rhs); copy assignment
*	Exception& operator=(Exception&& rhs) noexcept; move assignment
*
* Methods:
*	const char* getMessage(); 
*	- Returns the error message associated with the exception
*
*	void setMessage(const char* msg);
*	- Sets the error message for the exception
* 
*	friend std::ostream& operator<<(std::ostream& stream, const Exception& except);
*	- Overloads the output stream operator to print the exception message
*
*************************************************************************/


#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include <iostream>
#include <ostream>
#include <stdexcept>

class Exception {
private:
	char* m_msg;

public:
	Exception();
	~Exception();
	Exception(const char* msg);
	Exception(const Exception& copy);
	Exception(Exception&& move) noexcept;
	Exception& operator=(const Exception& rhs);
	Exception& operator=(Exception&& rhs) noexcept;

	const char* getMessage();
	void setMessage(const char* msg);

	friend std::ostream& operator<<(std::ostream& stream, const Exception& except);







};