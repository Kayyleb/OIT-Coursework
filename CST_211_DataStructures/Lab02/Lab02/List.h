/************************************************************************
* Class: List
*
* Purpose: This class creates and modifies a linkedlist 
*
* Manager functions:
*	List();                                       Default Ctor
*	List(const List& other);                      Copy Ctor
*	List(List&& other) noexcept;                  Move Ctor
*	~List();                                      Default Dtor
*	List<T>& operator=(const List<T>& other);     Copy Assignment
*	List<T>& operator=(List<T>&& other) noexcept; Move Assignment
*
*	// Other Methods:
*	bool isEmpty() const;
*	 - checks if the list is empty
*
*	T First();
*	 - returns the first element in the List
*	T Last();
*	 - returns the last element in the List
*
*	void Prepend(T other);
*	 - adds to the beggining of the list
*	void Append(T other);
*	 - adds to the end of the list
*
*	void Purge();
*	 - deletes all elements of the list
*	void Extract(T other);
*	 - removes an element of the list
*
*	void InsertAfter(T newItem, T existingItem);
*	 - inserts an element after an item
*	void InsertBefore(T newItem, T existingItem);
*	 - inserts an element before an item
*
*	const Node<T>* getHead() const;
*	 - returns the head of the list
*	const Node<T>* getTail() const;
*	 - returns the tail of the list
*
*	void PrintForward();
*	 - prints the list
*	void PrintBackward();
*	 - prints the list backwards
* 
*************************************************************************/

#pragma once
#include "Node.h"
#include "Exception.h"

template <typename T>
class List {

private:
	Node<T>* head;
	Node<T>* tail;

public:
	// Cannonical Methods: 
	List();
	List(const List& other);
	List(List&& other) noexcept;
	~List();
	List<T>& operator=(const List<T>& other);
	List<T>& operator=(List<T>&& other) noexcept;

	// Other Methods: 
	bool isEmpty() const; //checking if the list is empty

	T First(); //returning the first element in the List
	T Last();  //returning the last element in the List

	void Prepend(T other); //adding to the beggining of the list
	void Append(T other); //adding to the end of the list

	void Purge(); //deleting all elements of the list
	void Extract(T other); //remove an element of the list

	void InsertAfter(T newItem, T existingItem); //insert an element after an item
	void InsertBefore(T newItem, T existingItem);//insert an element before an item

	const Node<T>* getHead() const; //return the head of the list
	const Node<T>* getTail() const; //return the tail of the list

	void PrintForward(); //print the list
	void PrintBackward(); //print the list backwards 

};

template<typename T>
List<T>::List() : head(nullptr) , tail(nullptr)
{
}

template<typename T>
List<T>::List(const List& other) : head(nullptr) , tail(nullptr)
{
	if (other.head == nullptr)
	{
		throw Exception("List Doesn't Exist");
	}

	Node<T>* current = other.head;
	while (current != nullptr)
	{
		Append(current->data);
		current = current->next;
	}
}

template<typename T>
List<T>::List(List&& other) noexcept
{
	head = other.head;
	tail = other.tail;

	other.head = nullptr;
	other.tail = nullptr;
}

template<typename T>
List<T>::~List()
{
	Purge();
}

template<typename T>
List<T>& List<T>::operator=(const List<T>& other)
{
	if (this != &other) 
	{
		Purge();
		Node<T>* current = other.head;
		while (current != nullptr)
		{
			Append(current->data);
			current = current->next;
		}
	}
	return *this;
}

template<typename T>
List<T>& List<T>::operator=(List<T>&& other) noexcept
{
	if (this != &other)
	{
		Purge();
		head = other.head;
		tail = other.tail;
		other.head = nullptr;
		other.tail = nullptr;
	}
	return *this;
}

/**********************************************************************
* Purpose: The function checks if the LinkedList is empty .
*
* Precondition:
*
* Postcondition:
* Returns true if the head is nullptr, as in if the list is empty 
* Returns false if the head isn't nullptr, as in the list isn't empty
************************************************************************/

template<typename T>
bool List<T>::isEmpty() const
{
	return head == nullptr;

}

/**********************************************************************
* Purpose: This function returns the first node in the list, aka the head
*
* Precondition:
* List must exist, and head must be established correctly
*
* Postcondition:
* Returns the first node in the list, the head. 
* If the list doesn't exist, then it throw an exception
************************************************************************/
template<typename T>
T List<T>::First()
{
	if (head == nullptr)
	{
		throw Exception("List Doesn't Exist");
	}

	return head->data;
}

/**********************************************************************
* Purpose: This function returns the last node in the list, aka the tail
*
* Precondition:
* List must exist, and tail must be established correctly
*
* Postcondition:
* Returns the last node in the list, the tail.
* If the list doesn't exist, then it throw an exception
************************************************************************/
template<typename T>
T List<T>::Last()
{
	if (tail == nullptr)
	{
		throw Exception("List Doesn't Exist");
	}

	return tail->data;
}

/**********************************************************************
* Purpose: This function adds a node to the start of the list
*
* Precondition:
* Must take in any kind of value
*
* Postcondition:
* Creates a new node at the beggining of the list, and sets it as the 
* head, if the list doesn't exist yet, then it will create a list based 
* on the inputed data, then set that one piece of data as both the head 
* and the tail
************************************************************************/
template<typename T>
void List<T>::Prepend(T other)
{
	Node<T>* newNode = new Node<T>(other); // create a newNode with the consumers data

	if (head == nullptr)
	{
		head = newNode; // if the list doesn't exist, then the list is created, and the new node is now set as the head, as well as the tail
		tail = newNode;
	}
	else
	{
		newNode->next = head;     //Point newNode's next pointer to the head, which places it before the current head
		head->previous = newNode; //Set the current head's previous pointer as the newNode to establish its link, and making newNode the first Node on the list
		head = newNode;           //Now set the newNode as the head
	}
}

/**********************************************************************
* Purpose: This function adds a node to the end of the list
*
* Precondition:
* Must take in any kind of value
*
* Postcondition:
* Creates a new node at the end of the list, and sets it as the
* tail, if the list doesn't exist yet, then it will create a list based
* on the inputed data, then set that one piece of data as both the head
* and the tail
************************************************************************/
template<typename T>
void List<T>::Append(T other)
{
	Node<T>* newNode = new Node<T>(other); // this will create a new node based on the input, no matter what

	if (head == nullptr)
	{
		head = newNode; // if the list doesn't exist, then the list is created, and the new node is now set as the head, as well as the tail
		tail = newNode;
	}
	else
	{
		tail->next = newNode;     // since we have a tail pointer, pointing to the end of the list, we will set the tails next pointer to the newNode
		newNode->previous = tail; // link the newNode's previous pointer to the tail to establish the back and forth travel on the list, as well as setting the newNode as the tail
		tail = newNode;           // now we assign the created node to the tail pointer
	}
		
		// Old Notes on how to I wrote this function before: 
		// Node* current = head;               // A Node pointer called current will point to the head of the List
		// while (current->next != nullptr)    // While loop; this will traverse to the end of the List, as in when the next item from current is null (the end)
		// {
		//	current = current->next;           // After reaching the end of the linked list, we set the last Node as the current node
		// }
		// current->next = new Node(other);    // now we create a new node, and use current->next to place it after the current one which we previously set as the last node
		// tail = current->next                // then we can set this new last node as the tail since we just placed it at the end
	}

/**********************************************************************
* Purpose: This function deletes an entire list
*
* Precondition:
* List must exist in order to delete
*
* Postcondition:
* Will store the lists' head into a temporary pointer, then traverse the
* list, deleting the next node as we go along, then we set the head and tail
* pointers to a default state.
************************************************************************/
template<typename T>
void List<T>::Purge()
{
	while (head != nullptr)   // traversr the list
	{
		Node<T>* temp = head; // store the head into temp
		head = head->next;    // now set the Next Node as the head
		delete temp;          // then delete the old head (temp)
	}
	head = nullptr;           // set head & tail to default states
	tail = nullptr;
}

/**********************************************************************
* Purpose: This function deletes a specified node
*
* Precondition:
*  - list must exist 
*  - must take in an input
*  - that input must exist inside of the list
*
* Postcondition:
* searches through the list, and if the inputed data is found, it will
* delete that piece of data. If that data is the head or the tail, then
* it will update the head and the tail pointers as well to the new head
* or tail after deleting 
************************************************************************/
template<typename T>
void List<T>::Extract(T other)
{
	if (head == nullptr)
	{
		throw Exception("list is empty");
	}

	Node<T>* current = head;

	while (current != nullptr)                               // traverse the list
	{
		if (current->data == other)                          // if we find the item that needs to be extracted
		{
			if (current == head)                             // and if that item is the head
			{                          
				head = current->next;                        // set the head pointer to the current head's next node
				if (head != nullptr) 
				{
					head->previous = nullptr;                // now delete the old head
				}
				else                                         // if the list is empty
				{
					tail = nullptr;                          // set the tail to a default state 
				}
			}
			else if (current == tail)                        // if the target is the tail
			{                     
				tail = current->previous;                    // set the tail's previous node as the tail
				tail->next = nullptr;                        // now delete the old tail
			}
			else {                                           // if the target is somewhere in the middle
				current->previous->next = current->next;     // set the current node's previous' next pointer, as the next node
				current->next->previous = current->previous; // and then set the next's previous' pointer, as the previous node
			}                                                // this will remove all pointers away from the current node
			delete current;                                  // now delete the target
			return;                                          // avoid traversing the loop, and exit.
		}
		current = current->next;                             // this pointer traverses the list by pointing to the next item 
	}
	throw Exception("Item not found");                       // throw if we cant find the item
}
		
/**********************************************************************
* Purpose: This function inserts a piece of data after a specified piece
* of data
*
* Precondition:
* List must exist & take in two parameters, and the existingItem must also
* exist inside of the list
*
* Postcondition:
* This will add a node after a specified node, if that node is either the
* tail or the head, it also updates it as needed
************************************************************************/
template<typename T>
void List<T>::InsertAfter(T newItem, T existingItem)
{
	if (head == nullptr)
	{
		throw Exception("Existing Item to Insert After Doesn't Exist");
	}

	Node<T>* current = head;                         // create a current pointer to point to the head

	while (current != nullptr)                       // traverse through the list to find the existing item
	{
		if (current->data == existingItem)           // if the existing item is found
		{
			Node<T>* newNode = new Node<T>(newItem); // create a new node with the newItem input

			newNode->next = current->next;           // set the newNode's next pointer to the existing item's next pointer, because we are adding it in after the current node
			newNode->previous = current;             // set the newNode's previous pointer to the existing item because it's now in front of it
			if (current->next != nullptr)            // check if the existing item is the tail
			{
				current->next->previous = newNode;  // if not, then set the current item's next previous pointer to the newNode to set it in the list
			}
			else
			{
				tail = newNode;                      // if it is the tail, then we will set the newNode as the tail
			}
			current->next = newNode;                 // now point the current's next pointer to the newNode we created
			current = current->next;                 // then set the current to the next node in case we cannot find the item and need to loop around again
			return;                                  // then return
		}
		throw Exception("Cannot Find Existing Item"); // if we cannot find the item throw and exception
	}
}

/**********************************************************************
* Purpose: This function inserts a piece of data before a specified piece
* of data
*
* Precondition:
* List must exist & take in two parameters, and the existingItem must also
* exist inside of the list
*
* Postcondition:
* This will add a node before a specified node, if that node is either the
* tail or the head, it also updates it as needed
************************************************************************/
template<typename T>
void List<T>::InsertBefore(T newItem,T existingItem)
{

	if (head == nullptr)
	{
		throw Exception("Existing Item to Insert After Doesn't Exist");
	}

	Node<T>* current = head; // create a pointer to the head

	while (current != nullptr) 
	{                     // traverse the list to find the existing item
		if (current->data == existingItem)           // if we find the item 
		{
			Node<T>* newNode = new Node<T>(newItem); // create a new node taking in the new item as the parameter
			newNode->next = current;                 // set the new nodes next pointer to the existing node because it is now before the existing one
			newNode->previous = current->previous;   // set the new nodes previous pointer to the existing node's previous pointer (because it's going behind the current node)
			if (current->previous != nullptr)        // if the existing node is NOT the head
			{
				current->previous->next = newNode;   // set the existing node's previous' next pointer to the new node to set it in the list
			}
			else
			{
				head = newNode;                      // if the existing node IS the head, set the newNode as the new head
			}
			current->previous = newNode;             // now set the existing item's previous pointer to the created node
			return;
		}
		current = current->next;                     // then set the current to the next node in case we cannot find the item and need to loop around again
	}
	throw Exception("Cannot Find Existing Item");    // if we cannot find the item throw and exception
}

/**********************************************************************
* Purpose: This function returns the head of the list
*
* Precondition:
* List must exist
*
* Postcondition:
* Will return the head of the list 
************************************************************************/
template<typename T>
const Node<T>* List<T>::getHead() const
{
	return head;
}

/**********************************************************************
* Purpose: This function returns the tail of the list
*
* Precondition:
* List must exist
*
* Postcondition:
* Will return the tail of the list
************************************************************************/
template<typename T>
const Node<T>* List<T>::getTail() const
{
	return tail;
}

/**********************************************************************
* Purpose: This function prints the list normally
* Precondition:
* List must exist
*
* Postcondition:
* prints the list
************************************************************************/
template<typename T>
void List<T>::PrintForward()
{
	Node<T>* current = head;                     // set a current pointer as the head
	while (current != nullptr)                   // traverse the list
	{
		std::cout << current->data << std::endl; // print each piece of data one at a time 
		current = current->next;                 // then point to the next piece of data
	}
}

/**********************************************************************
* Purpose: This function prints the list, but backwards
*
* Precondition:
* List must exist
*
* Postcondition:
* Will print the list backwards
************************************************************************/
template<typename T>
void List<T>::PrintBackward()
{
	Node<T>* current = tail;                     // set a current pointer as the tail
	while (current != nullptr)                   // traverse the list backwards starting from the tail
	{
		std::cout << current->data << std::endl; // print each piece of data one at a time 
		current = current->previous;             // then point to the next piece of data (pointing to the previous piece technically, but we're just traversing backwards)
	}
}


