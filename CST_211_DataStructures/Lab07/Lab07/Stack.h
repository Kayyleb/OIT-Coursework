/*************************************************************
* Author: Kayleb Cook
* Filename: Lab07
* Date Created: 1/30/2025
* Modifications:
*   - 1/30: Started Lab
*   - 1/31: Finished Lab & Made comments
**************************************************************/

/************************************************************************
* Class: Stack
*
* Purpose: 
* The purpose of this class is to create a LinkedList based object, called stack
* and give it all the properties of a typical stack function, such as Pop, Push,
* and Peek.
*
* Manager functions:
* 	Stack();										  - default ctor
*	Stack(const Stack<T>& other);					  - copy ctor
*	Stack(Stack<T>&& other) noexcept;			      - move ctor
*	~Stack();										  - default dtor
*	Stack<T>& operator=(const Stack<T>& other);		  - move assignment
*	Stack<T>& operator=(Stack<T>&& other) noexcept;	  -copy assignment
*
* Methods:
* 	void Push(T data);
*		- Push data to the top of the stack
*	T Pop();
*		- Remove & Return data from the top of the stack
*	const T Peek() const;
*		- Return data of the top of the stack
*	int getNumOfElements() const;
*		- get the number of elements of the stack
*	bool isEmpty();
*		- check if the stack is empty
*
*************************************************************************/

#include <iostream>
#include "List.h"
#include "Exception.h"
#pragma once

template <typename T>
class Stack {
private:
	List<T> m_stack;
	int num_elements;

public:
	Stack();
	Stack(const Stack<T>& other);
	Stack(Stack<T>&& other) noexcept;
	~Stack();
	Stack<T>& operator=(const Stack<T>& other);
	Stack<T>& operator=(Stack<T>&& other) noexcept;

	void Push(T data);
	T Pop();
	const T Peek() const;
	int getNumOfElements() const;
	bool isEmpty();
};

template<typename T>
Stack<T>::Stack() : m_stack() , num_elements(0) // num elements to default state, m_stack is set to default in the List class because its a list object
{
}

template<typename T>
Stack<T>::Stack(const Stack<T>& other) : m_stack(other.m_stack) , num_elements(other.num_elements) // copy ctor in List is called, but set the data memebers to their copied state
{
}

template<typename T>
Stack<T>::Stack(Stack<T>&& other) noexcept : m_stack(std::move(other.m_stack)) , num_elements(other.num_elements) // same as copy ctor, set the data members to the moved state, but List move ctor is called to do the process
{
}

template<typename T> 
Stack<T>::~Stack()
{
	m_stack.Purge(); // call purge to destroy m_stack, it is a List object, so lets use the list destructor to destroy the object correctly
	num_elements = 0;// set num elements to their default state when we destroy the stack object
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
	if (this != &other) // make sure that the current object isnt the same as the new object
	{
		m_stack = other.m_stack; // now set the data members to their copied state
		num_elements = other.num_elements;
	}
	return *this; // return a pointer to the object
}	// copy assignment is called in Stack to do the operations

template<typename T>
Stack<T>& Stack<T>::operator=(Stack<T>&& other) noexcept
{
	if (this != &other) // make sure that the current object isnt the same as the new object
	{
		m_stack = std::move(other.m_stack); // now set the data members to their moved state
		num_elements = other.num_elements;
	}
	return *this; // return a pointer to the object
}	// move assignment is called in Stack to do the operations

/**********************************************************************
* Purpose: The purpose of this function is to add data to the top of the 
*		   Stack
*
* Precondition:
* No precondition
*
* Postcondition:
* Data is added to the top of the stack and the number of elements counter
* is increased to go with it. Considering this is a linkedlist object, and not 
* a real stack object, we use Append to add the data to the back of the list 
* (if theres no list, then one is created), and the back of the list, and so
* on will be treated as the top of the stack
*
************************************************************************/
template<typename T>
void Stack<T>::Push(T data)
{
	m_stack.Append(data); // call append to push the data to back of the list, which we will consider the top
	num_elements++;		  // increment the counter
}

/**********************************************************************
* Purpose: The purpose of this function is to remove and return the data
*		   at the top of the stack
*
* Precondition:
* The stack cannot be empty, nothing to pop off
*
* Postcondition:
* The top of the stacks data is returned, and then removed from from the stack.
* To do this we call the last function in List, which returns the Last node
* of the list, and since all we're doing is adding to the back of the list, 
* we can use this to return the top of the stack. After that we call extract to 
* remove that piece of data, then decrement the counter
*
************************************************************************/
template<typename T>
T Stack<T>::Pop()
{
	if (m_stack.isEmpty()) // check if the stack is empty 
	{
		throw Exception("Underdlow! Stack is Empty!");
	}
	
	T data = m_stack.Last(); // return the back of the list, which is the top of the stack
	m_stack.Extract(data);	 // now remove/extract that piece of data off the list
	num_elements--;			 // then decrement the counter
	return data;			 // and return the data
}

/**********************************************************************
* Purpose: The purpose of this function is to return the top of the stack
*
* Precondition:
* The stack cannot be empty, nothing to return
*
* Postcondition: 
* The top of the list is returned, but not touched. We use the last function
* again to return the data as a const to make sure its unmodified
*
************************************************************************/
template<typename T>
const T Stack<T>::Peek() const
{
	if (m_stack.isEmpty()) // check if stack is empty
	{
		throw Exception("Underdlow! Stack is Empty!");
	}
	
	return m_stack.Last(); // return the top of the stack(back of the list)
}

/**********************************************************************
* Purpose: The purpose of this function is to return the number of elements
*		   added onto the stack
*
* Precondition:
* The stack cannot be empty, there will be nothing to return
*
* Postcondition:
* The number of elements that we keep track of during the push and pop functions
* are returned as a const, don't want to modify the number of elements
* 
************************************************************************/
template<typename T>
int Stack<T>::getNumOfElements() const
{
	if (m_stack.isEmpty()) // check if the stack is empty 
	{
		throw Exception("Underdlow! Stack is Empty!");
	}
	
	return num_elements; // return the number of elements
}

/**********************************************************************
* Purpose: This function checks and returns if the stack is empty or not
*
* Precondition: 
* No precondition
*
* Postcondition:
* The stack is checked if it's empty, to do this we call or linkedlist's 
* isEmpty function on m_stack to check if our List object is empty or not
* then we return true or false. 
************************************************************************/
template<typename T>
bool Stack<T>::isEmpty()
{
	return m_stack.isEmpty();
}




