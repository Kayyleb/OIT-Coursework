/*************************************************************
* Author: Kayleb Cook
* Filename: Lab08
* Date Created: 2/1/2025
* Modifications:
*   - 2/1: Started Lab, made class and most of test functions
*   - 2/2: Finished Lab & Made comments
**************************************************************/

/************************************************************************
* Class: Queue
*
* Purpose: This class uses our doubly linked list class to create a queue object
*		   with the same properties of a queue
*
* Manager functions:
	Queue(); default ctor
	Queue(const Queue<T>& other); copy ctor
	Queue(Queue<T>&& other); move ctor
	Queue<T>& operator=(const Queue<T>& other); copy assignment
	Queue<T>& operator=(Queue<T>&& other); move assignment 
	~Queue(); default dtor

	void Enqueue(T data);	
		- adds our data to the end of the queue 
	T Dequeue();
		- removes our data from the start of the queue
	const T Peek() const;
		- returns the first data in the queue
	const int getNumElements() const;
		- returns the number of elements currently in the queue
	const bool isEmpty() const;
		- checks if the queue is empty or not
*
*************************************************************************/

#include <iostream>
#include "List.h"
#include "Exception.h"

template <typename T>
class Queue {
private:
	List<T> m_queue;
	int m_num_elements;

public:
	Queue();
	Queue(const Queue<T>& other);
	Queue(Queue<T>&& other) noexcept;
	Queue<T>& operator=(const Queue<T>& other);
	Queue<T>& operator=(Queue<T>&& other) noexcept;
	~Queue();

	void Enqueue(T data);
	T Dequeue();
	const T Peek() const;
	const int getNumElements() const;
	const bool isEmpty() const;
};

template<typename T>
Queue<T>::Queue() : m_queue() , m_num_elements(0) // sets our data members to their default state, m_queue is automatically set to a default state when the list object is created, and set the number of elements to 0
{
}

template<typename T>
Queue<T>::Queue(const Queue<T>& other) : m_queue(other.m_queue) , m_num_elements(other.m_num_elements)
{ // the copy constructor in List is called, so using base member initialization, we set the copy elements to the original, then call the copy ctor in list to do the operations
}

template<typename T>
Queue<T>::Queue(Queue<T>&& other) noexcept : m_queue(std::move(other.m_queue)), m_num_elements(other.m_num_elements)
{ // same as the copy ctor, we will call the move ctor in List to do the operations, but we will set the moved elements equal to the original using base member initializaton 
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{
	if (this != &other) // check if the current object isnt the same as the one we are creating the copy to
	{
		m_queue = other.m_queue; // set the elements to the copied state
		m_num_elements = other.m_num_elements;
	} // calls list's copy assigment to do the operations 
	return *this; // return a pointer of the current object 
}

template<typename T>
Queue<T>& Queue<T>::operator=(Queue<T>&& other) noexcept
{
	if (this != &other) // check if the current object isnt the same as the one we are moving to
	{
		m_queue = std::move(other.m_queue); // move the elements over
		m_num_elements = other.m_num_elements;
	} // calls list's move assigment to do the operations 
	return *this; // return a pointer of the current object 
}

template<typename T>
Queue<T>::~Queue()
{
	m_queue.Purge(); // call purge in the list class to properly clean up the list object
	m_num_elements = 0; // set the number of elements back to default
}

/**********************************************************************
* Purpose: This function will add our data to the front of the queue
*
* Precondition:
* no precondition
*
* Postcondition:
* Uses Append to add any new data to the back of the list. If the list doesnt
* exist yet it will create one with the data at the front, just like how a queue
* starts, and data is added to the back
************************************************************************/
template<typename T>
void Queue<T>::Enqueue(T data)
{
	m_queue.Append(data);     // add the data to the end of the queue
	m_num_elements++;         // increment the counter
}

/**********************************************************************
* Purpose: This function will remove our data from the back of the queue
*
* Precondition:
* List cannot be empty
*
* Postcondition:
* After checking if the list is empty, we will grab the first piece of data
* from the list, then remove it by calling extract in the list class. We\
* then return that data removed. This is to create the FIFO system, where the 
* first in (head of list) is the first to one we dequeue
************************************************************************/
template<typename T>
T Queue<T>::Dequeue()
{
	if (m_queue.isEmpty())
	{
		throw Exception("Underflow! Queue is empty");
	}
	T data = m_queue.First(); // return the first piece of data in in the queue (start of the line)
	m_queue.Extract(data);    // now extract that piece of data from the queue
	m_num_elements--;         // decrement the counter
	return data;			  // return the data from the beggining of the queue
}

/**********************************************************************
* Purpose: This function will only return the head of the list
*
* Precondition:
* List cannot be empty
*
* Postcondition:
* After checking if the list is empty, we will grab the first piece of data
* from the list and then return it as a const, to make sure it isn't altered
* We are only returning, not modifying
************************************************************************/
template<typename T>
const T Queue<T>::Peek() const
{
	if (m_queue.isEmpty())
	{
		throw Exception("Underflow! Queue is empty");
	}
	return m_queue.First();	   // return the beggining of the queue by calling First and getting head of function 
}

/**********************************************************************
* Purpose: This function will return the number of elements currently in queue
*
* Precondition:
* List cannot be empty
*
* Postcondition:
* After checking if the list is empty, we will return the number of elements
* variable that we keep track of in other functions. 
* 
************************************************************************/
template<typename T>
const int Queue<T>::getNumElements() const
{
	if (m_queue.isEmpty())
	{
		throw Exception("Underflow! Queue is empty");
	}
	return m_num_elements;	   // return the number of elements we increment and decrement in the enqueue and dequeue functions 
}

/**********************************************************************
* Purpose: This function will check if the list is empty 
*
* Precondition:
* No precondition 
*
* Postcondition:
* the isEmpty function is called from the list class to properly make sure
* that the list object is empty, then we return true or false in the queue class
* which then passes it on to whenever this function is called in the tests
************************************************************************/
template<typename T>
const bool Queue<T>::isEmpty() const
{
	return m_queue.isEmpty();		  // call the isEmpty function from List to check if the list object is empty or not
}




