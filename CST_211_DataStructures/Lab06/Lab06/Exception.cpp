/*************************************************************
* Author: Kayleb Cook
* Filename: Lab06.cpp
* Date Created: 1/27/25
* Modifications:
*	1/27/25 - Created & Defined entire Stack class & wrote all tests
*	1/28/25 - Wrote all comment & comment blocks & checked for memory leaks
**************************************************************/

#include "Exception.h"

/**********************************************************************
* Purpose: This function is to create the Exception object and set it to a default state
*
* Precondition:
* No precondition
*
* Postcondition: 
* Creates Exception object and sets it to a default state
************************************************************************/
Exception::Exception() : m_msg(nullptr)
{
}

/**********************************************************************
* Purpose: This function is to delete the exception object and clean up memory
*
* Precondition: 
* No precondition
*
* Postcondition: 
* Deletes the exception object, and cleans up the memory associated with it
************************************************************************/
Exception::~Exception()
{
	delete[] m_msg;
}

/**********************************************************************
* Purpose: This function is to create the Exception object with a message
*
* Precondition: 
* input message must be a valid C-string
*
* Postcondition: 
* Creates Exception with copy of provided message
************************************************************************/
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

/**********************************************************************
* Purpose: This function is to create a copy of an existing Exception object
*
* Precondition: 
* copied message must be valid
*
* Postcondition: 
* Creates deep copy of inputed Exception
* If it isn't a valid message, then it will set the message to nullptr
************************************************************************/
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

/**********************************************************************
* Purpose: This function is to move an existing Exception object
*
* Precondition: 
* No precondition
*
* Postcondition: 
* Moves the message from the inputed Exception to the new Exception object
************************************************************************/
Exception::Exception(Exception&& move) noexcept
{
	m_msg = move.m_msg;
	move.m_msg = nullptr;
}

/**********************************************************************
* Purpose: This function is to copy the contents of one message, and copy it
* 		   to and existing address	
*
* Precondition: 
* inputed message must not be the same as the current message
*
* Postcondition: 
* Makes a deep copy of the exception and copies it to the other object's address
************************************************************************/
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

/**********************************************************************
* Purpose: This function is to move the contents of one Exception to
*          to another existing address
*
* Precondition: 
* No precondition
*
* Postcondition: 
* Moves the message from the inputed Exception to the other objects address
************************************************************************/
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

/**********************************************************************
* Purpose: This returns the exception message
*
* Precondition: 
* No precondition
*
* Postcondition: 
* Returns a pointer to the message
************************************************************************/
const char* Exception::getMessage()
{
	return m_msg;
}

/**********************************************************************
* Purpose: This function sets the message to a new inputed message
*
* Precondition: 
* inputed message must be a valid C-string
*
* Postcondition: 
* Sets the message to the new inputed message
************************************************************************/
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

/**********************************************************************
* Purpose: This function is to output the Exception message to a stream
*
* Precondition: 
* stream is a valid output stream, except is a valid Exception
*
* Postcondition: 
* Outputs exception message to stream and returns stream
************************************************************************/
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
