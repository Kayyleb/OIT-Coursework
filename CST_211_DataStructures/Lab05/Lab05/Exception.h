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