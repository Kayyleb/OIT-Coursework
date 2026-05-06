#pragma once
#include "BSNode.h"
#include "Exception.h"

template <typename T>
class BSTree {
private: 
	BSNode<T>* root;

	BSTree(const BSTree<T>& other);
	BSTree(BSTree<T>&& other) noexcept;
	BSTree<T>& operator=(const BSTree<T>& other);
	BSTree<T>& operator=(BSTree<T>&& other) noexcept;
	~BSTree();

	void Insert(BSNode<T>*& root , T data);
	void Delete(BSNode<T>*& root, T data);
	void Purge(BSNode<T>*& root);
	T Height(BSNode<T>*& root);
	void InOrder(BSNode<T>*& root, void (*visit)(const T data));
	void PreOrder(BSNode<T>*& root, void (*visit)(const T data));
	void PostOrder(BSNode<T>*& root, void (*visit)(const T data));
	void BreadthFirst(BSNode<T>*& root, void (*visit)(const T data));



public:
	BSTree();

};

template<typename T>
BSTree<T>::BSTree() : root(nullptr)
{
}

template<typename T>
BSTree<T>::BSTree(const BSTree<T>& other)
{
	if (other.root == nullptr)
	{
		throw Exception("Tree Doesn't Exist");
	}
	
}

template<typename T>
BSTree<T>::BSTree(BSTree<T>&& other) noexcept
{
}

template<typename T>
BSTree<T>& BSTree<T>::operator=(const BSTree<T>& other)
{
	// TODO: insert return statement here
}

template<typename T>
BSTree<T>& BSTree<T>::operator=(BSTree<T>&& other) noexcept
{
	// TODO: insert return statement here
}

template<typename T>
BSTree<T>::~BSTree()
{
}

template<typename T>
void BSTree<T>::Insert(BSNode<T>*& root, T data)
{
	if (root == nullptr) // if the root/node is null
	{
		root = new BSNode<T>(data); // insert new node at that spot 
	}
	else if (data < root->data) // if the data is less than current data
	{
		Insert(root->left, data); // traverse left
	}
	else if (data > root->data) // if the data is greater than current data
	{
		Insert(root->right, data); // traverse right
	}
}

template<typename T>
void BSTree<T>::Delete(BSNode<T>*& root, T data)
{
	/* 
		4 Cases:
		1: Desired Node is a leaf node
		2: Desired Node has an empty left subtree & non-empty right subtree
		3: Desired Node has an empty right subtree & non-empty left subtree
		4: Desired Node has a non-empty left & right subtree 
	*/

	if (root == nullptr)
	{
		throw Exception("Tree doesn't exist");
	}
		// traverses the list
		if (data < root->data) // if the data is less than current data
		{
			Delete(root->left, data); // traverse left
		}
		else if (data > root->data) // if the data is greater than current data
		{
			Delete(root->right, data); // traverse right
		}

	else // if the root != nullptr
	{
		// case 1: Desired Node = Leaf Node
		if (root->left == nullptr && root->right == nullptr) // if left & right are both empty
		{
			delete root; // delete the current node
			root = nullptr; // then set it to null for cleanup
		}
		// case 2: Desired Node has an empty left & non-empty right
		else if (root-> left == nullptr && root->right != nullptr)
		{
			BSNode<T>* temp = root; // create a temp node, storing the desired root in it
			root = root->right; // now set the current root, to the right node
			delete temp; // then delete the old one 
		}
		// case 3: Desired Node has an non-empty left & empty right
		else if (root->left == nullptr && root->right != nullptr)
		{
			BSNode<T>* temp = root; // create a temp node, storing the desired root in it
			root = root->left; // now set the current root, to the left node
			delete temp; // then delete the old one 
		}
		else if (root->left != nullptr && root->right != nullptr)
		{
			// traverse to end of left subtree
			BSNode<T>* rightMost = root->left; // create a temp node, that is going to traverse to the far left of the tree
			while (rightMost->right != nullptr) // get to the right most child of the left tree
			{
				rightMost = rightMost->right; // keep going right (greater) until we reach the end
			}
			root->data = rightMost->data; // now replace the desired root with the rightmost node data

			Delete(root->data, rightMost->data); // now delete the original rightmost data
		}
	}
}

template<typename T>
void BSTree<T>::Purge(BSNode<T>*& root)
{
	if (root == nullptr) // if the inputed root is nullptr (inputed by recurrsion, then it will return
	{
		return;
	}
	Purge(root->left); // traverse left side
	Purge(root->right);// traverse right side

	delete root; // delete current root if the left and right = nullptr
	root = nullptr; // then clean up the deleted root
}

template<typename T>
T BSTree<T>::Height(BSNode<T>*& root)
{
	int leftCount = 0;
	int rightCount = 0;

	if (root == nullptr)
	{
		throw Exception("Tree doesn't exist");
	}

	


	return std::max(leftCount, rightCount); // find the greater count for the higher & return that value
}

template<typename T>
void BSTree<T>::InOrder(BSNode<T>*& root, void(*visit)(const T data))
{
	if (root != nullptr)
	{
		InOrder(root->left, visit);
		visit(root->data);
		InOrder(root->m_right, visit);
	}
}

template<typename T>
void BSTree<T>::PreOrder(BSNode<T>*& root, void(*visit)(const T data))
{
	if (root != nullptr)
	{
		visit(root->data);
		PreOrder(root->left, visit);
		PreOrder(root->right, visit);
	}
}

template<typename T>
void BSTree<T>::PostOrder(BSNode<T>*& root, void(*visit)(const T data))
{
	if (root != nullptr)
	{
		PostOrder(root->left, visit);
		PostOrder(root->right, visit);
		visit(root->data);
	}
}

template<typename T>
void BSTree<T>::BreadthFirst(BSNode<T>*& root, void(*visit)(const T data))
{

}


