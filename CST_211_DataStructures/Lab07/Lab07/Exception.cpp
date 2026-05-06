#include "Exception.h"

Exception::Exception() : m_msg(nullptr)
{
}

Exception::~Exception()
{
	delete[] m_msg;
}

Exception::Exception(const char* msg)
{
	if (m_msg) 
	{
		m_msg = new char[strlen(msg) + 1];
		strcpy(m_msg, msg);
	}
	else
	{
		m_msg = nullptr;
	}
}

Exception::Exception(const Exception& copy) : m_msg(copy.m_msg)
{
	if (copy.m_msg) 
	{
		m_msg = new char[strlen(copy.m_msg) + 1];
		strcpy(m_msg, copy.m_msg);
	}
	else
	{
		m_msg = nullptr;
	}
}

Exception::Exception(Exception&& move) noexcept
{
	m_msg = move.m_msg;
	move.m_msg = nullptr;
}

Exception& Exception::operator=(const Exception& rhs)
{
	if (this != &rhs)
	{
		m_msg = rhs.m_msg;

		m_msg = new char[strlen(rhs.m_msg) + 1];
		strcpy(m_msg, rhs.m_msg);

	} 
	return *this;
}

Exception& Exception::operator=(Exception&& rhs) noexcept
{
	if (this != &rhs)
	{
		delete[] rhs.m_msg;
		m_msg = rhs.m_msg;
		rhs.m_msg = nullptr;
	} 
	return *this;
}

const char* Exception::getMessage()
{
	return m_msg;
}

void Exception::setMessage(const char* msg)
{
	delete[] m_msg;
	if (m_msg)
	{
		m_msg = new char[strlen(msg) + 1];
		strcpy(m_msg, msg);
	}
	else
	{
		m_msg = nullptr;
	}
}

std::ostream& operator<<(std::ostream& stream, const Exception& except)
{
	if (except.m_msg)
	{
		stream << except.m_msg;
	}
	else
	{
		stream << "no message." << std::endl;
	}
	
	return stream;
}
