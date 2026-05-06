#pragma once
#include <iostream>

template <typename T>
class BSTree;

template <typename T>
class BSNode {
	friend class BSTree<T>;

private:
	T data;				// the node data
	BSNode<T>* left;    // pointer to the left of the node
	BSNode<T>* right;	// pointer to the right of the node
	
public:
	BSNode(); // default ctor
	BSNode(T data , BSNode<T>* left = nullptr , BSNode<T>* right = nullptr); // Node class ctor
};


template<typename T>
BSNode<T>::BSNode() : data(T{}), left(nullptr), right(nullptr) // base member initialization to make sure the variables are created correctly
{
}

template<typename T>
BSNode<T>::BSNode(T data, BSNode<T>* left, BSNode<T>* right) : data(data) , left(left) , right(right) // base member initialization to correctly create the pointers
{
}

