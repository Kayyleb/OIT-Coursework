/************************************************************************
* Class: Node
*
* Purpose: This class creates and modifies a linkedlist
*
* Manager functions:
	Default Ctor: Node(); 
	Copt Ctor: Node(const Node<T>& other);
	Move Ctor: Node(Node<T>&& other);
	Node Ctor: Node(T data, Node<T>* next = nullptr, Node<T>* previous = nullptr);
	Default Dtor: ~Node();
	Copy Assignment: Node<T>& operator=(const Node<T>& other);
	Move Assignment: Node<T>& operator-(Node<T>&& other);
*************************************************************************/

#pragma once
#include <iostream>

template<typename T>
class List;

template <typename T>
class Node
{
	friend class List<T>;  // Making LinkedList a friend class to allow it to access the members of the Node class
private:
	T data;         // Template datatype E
	Node<T>* next;  // Pointer to next Node
	Node<T>* previous;

	Node();
	Node(const Node<T>& other);
	Node(Node<T>&& other);
	Node(T data, Node<T>* next = nullptr, Node<T>* previous = nullptr);
	~Node();
	Node<T>& operator=(const Node<T>& other);
	Node<T>& operator-(Node<T>&& other);

	// no getters and setters required due to the friend class
};

template<typename T>
Node<T>::Node() : data(T()) , next(nullptr) , previous(nullptr)
{
}

template<typename T>
Node<T>::Node(const Node<T>& other) : data(other.data) , next(other.next) , previous(other.previous)
{
	if (other.next != nullptr)
	{
		next = new Node<T>(other.next);
		next->previous = this;
	}
}

template<typename T>
Node<T>::Node(Node<T>&& other)
{
	next = other.next;
	data = other.data;
	previous = other.previous;

	other.next = nullptr;
	other.data = nullptr;
	other.previous = nullptr;
}

template<typename T>
Node<T>::Node(T data, Node<T>* next, Node<T>* previous) : data(data) , next(next) , previous(previous)
{
}

template<typename T>
Node<T>::~Node()
{
}

template<typename T>
Node<T>& Node<T>::operator=(const Node<T>& other)
{
	if (this != &other)
	{
		delete[] next;
		data = other.data;
		next = new Node<T>(other.next);
	}
	return *this;
}

template<typename T>
Node<T>& Node<T>::operator-(Node<T>&& other)
{
	if (this != &other)
	{
		next = other.next;
		data = other.data;
		previous = other.previous;

		other.next = nullptr;
		other.data = nullptr;
		other.previous = nullptr;
	}
	return *this;
}
