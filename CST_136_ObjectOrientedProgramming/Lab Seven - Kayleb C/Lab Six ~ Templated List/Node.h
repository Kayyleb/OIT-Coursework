#pragma once
#ifndef NODE_H
#define NODE_H

template <typename E>
class Node
{
	friend class LinkedList<E>;  // Making LinkedList a friend class to allow it to access the members of the Node class

private:
	E data;      // Template datatype E
	Node* Next;  // Pointer to Next Node

	Node(const E& other, Node* Next = nullptr) : data(other), Next(Next) {} // Constructor for Node
};
#endif