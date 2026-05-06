/************************************************************************
* Class: List
*
* Purpose: This class creates and modifies a linkedlist
*
* Manager functions:
	Exception(); Default Ctor
	~Exception();Default Dtor
	Exception(const char* msg); 1 Arg Ctor
	Exception(const Exception& copy); copy ctor
	Exception(Exception&& move) noexcept; move ctor
	Exception& operator=(const Exception& rhs); copy assignment
	Exception& operator=(Exception&& rhs) noexcept; move assignment

	const char* getMessage(); getter
	void setMessage(const char* msg); setter

	friend std::ostream& operator<<(std::ostream& stream, const Exception& except); ostream operator
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