#pragma once
#include "Exception.h"
#include "Array.h"

template<typename T>
class Queue {
private:
	Array<T> m_queue;
	int m_size;
	int m_tail;
	int m_head;
public:
	Queue();
	Queue(const Queue<T>& other);
	Queue(Queue<T>&& other) noexcept;
	Queue<T>& operator=(const Queue<T>& other);
	Queue<T>& operator=(Queue<T>&& other) noexcept; 
	~Queue();
	//methods:

	void Enqueue(T data);
	T Dequeue();
	T Peek() const;
	int getSize() const;
	bool isEmpty() const;
	bool isFull() const;
};

template<typename T>
Queue<T>::Queue() : m_queue() , m_size(0) , m_head(0) , m_tail(0)
{
}

template<typename T>
Queue<T>::Queue(const Queue<T>& other) : m_queue(other.m_queue), m_size(other.m_size), m_head(other.m_head), m_tail(other.m_tail)
{
}

template<typename T>
Queue<T>::Queue(Queue<T>&& other) noexcept : m_queue(std::move(other.m_queue)), m_size(other.m_size), m_head(other.m_head), m_tail(other.m_tail)
{
	other.m_size = 0;
	other.m_head = 0;
	other.m_tail = 0;
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{
	if (this != &other)
	{
		m_queue = other.m_queue;
		m_size = other.m_size;
		m_head = other.m_head;
		m_tail = other.m_tail;
	}
	return *this;
}

template<typename T>
Queue<T>& Queue<T>::operator=(Queue<T>&& other) noexcept
{
	if (this != &other)
	{
		m_queue = std::move(other.m_queue);
		m_size = other.m_size;
		m_head = other.m_head;
		m_tail = other.m_tail;

		other.m_size = 0;
		other.m_head = 0;
		other.m_tail = 0;
	}
	return *this;
}

template<typename T>
Queue<T>::~Queue()
{
	m_tail = 0;
	m_head = 0;
	m_size = 0;
}

template<typename T>
void Queue<T>::Enqueue(T data)
{
	if (isFull())
	{
		throw Exception("Overflow! Stack is FULL");
	}
	
	m_queue[m_tail] = data;
	m_tail++;
	if (m_tail == m_queue.getLength())
	{
		m_tail = 0;
	}
	m_size++;
}

template<typename T>
T Queue<T>::Dequeue()
{
	T data = m_queue[m_head];
	m_head++;
	if (m_head == m_queue.getLength()) {  // Wrap around if head exceeds the array size
		m_head = 0;
	}

	m_size--;
	return data;		  // now return the data
}

template<typename T>
T Queue<T>::Peek() const
{
	return m_queue[m_head];
}

template<typename T>
int Queue<T>::getSize() const
{
	return m_size;
}

template<typename T>
bool Queue<T>::isEmpty() const
{
	if (m_size == 0)
	{
		return true;
	}
	return false;
}

template<typename T>
bool Queue<T>::isFull() const
{
	return m_size == m_queue.getLength();
}
