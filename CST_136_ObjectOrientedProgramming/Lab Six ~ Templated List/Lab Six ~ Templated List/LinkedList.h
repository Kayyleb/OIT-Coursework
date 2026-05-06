//Name: Kayleb Cook
//Programming Assignment: Lab Seven: Templated List Enhancements
#pragma once

template <typename E>
class LinkedList
{
private: 
	class Node; // Declaring Node Class 
	
	Node* head; // Head pointer for the list

public:
	LinkedList();                                          // Default Ctor
	~LinkedList();                                         // Default Dtor
	LinkedList(const LinkedList& other);                   // Copy Ctor
	LinkedList(LinkedList&& other) noexcept;               // Move Ctor
	LinkedList<E>& operator=(const LinkedList& other);     // Copy Operator
	LinkedList<E>& operator=(LinkedList&& other) noexcept; // Move Operator


	void AddAtFront(const E& other);
	void AddAtEnd(const E& other);
	void AddAtIndex(const E& other, size_t index);

	E Front() const;
	E End() const;

	E& operator[](size_t index);
	const E& operator[](size_t index) const;

	E RemoveFront();
	E RemoveEnd();
	E RemoveIndex(size_t index);

	void Purge();
	
	void Display() const;

	//Lab Seven: 
	template <typename E>
	using CompareFunction = int(*)(const E& first, const E& second);

	void Sort(CompareFunction<E> compare);
	void ForEach(void(*function)(E& other));
	template <typename U>
	void ForEach(void(*function)(E& other1, U& other2) , U& data);

	void Reverse();

};

// Defining Node Here
template <class E>
class LinkedList<E>::Node
{
public:
	E data;      // Template datatype E
	Node* Next;  // Pointer to Next Node

	Node() : data(nullptr), Next(nullptr)          // Default Ctor
	{
	}
	~Node()                                        // Default Dtor
	{
	}                                            
	Node(const Node& other) : data(other.data), Next(nullptr)  // Copy Ctor
	{
	}
	Node(Node&& other) noexcept : data(other.data) , Next(other.Next) // Move Ctor
	{
		data = nullptr;
		Next = nullptr;
	}
	Node& operator=(const Node& other)            // Copy Operator
	{
		if (this != &other)
		{
			data = other.data;
		} return *this;
	}
	Node& operator=(Node&& other) noexcept        // Move Operator
	{
		if (this != &other)
		{
			data = other.data;
			Next = other.Next;
			other.data = nullptr;
			other.Next = nullptr;
		} return *this;
	}

	Node(const E& other, Node* Next = nullptr) : data(other), Next(Next) {} // Constructor for Node
	friend class LinkedList<E>;  // Making LinkedList a friend class to allow it to access the members of the Node class
};

template<typename E>
inline LinkedList<E>::LinkedList() : head(nullptr)
{
}

template<typename E>
inline LinkedList<E>::~LinkedList()
{
	Purge();
	// In the LinkedList Dtor we call Purge so that it can delete (purpge) the linked list just like how in regular classes we do "delete[] data" 
}

template<typename E>
inline LinkedList<E>::LinkedList(const LinkedList& other)
{
	Node* current = other.head;
	Node** newCurrent = &head;

	while (current != nullptr) {
		*newCurrent = new Node(current->data); 
		newCurrent = &(*newCurrent)->Next;
		current = current->Next;
	}
}

template<typename E>
inline LinkedList<E>::LinkedList(LinkedList&& other) noexcept : head(other.head) //fixed: transfers ownership of other.head to head
{
	other.head = nullptr;
}

template<typename E>
inline LinkedList<E>& LinkedList<E>::operator=(const LinkedList& other)
{
	if (this != &other) 
	{
		Purge();           
		Node* current = other.head; 
		Node** newCurrent = &head;  
		while (current != nullptr) {
			*newCurrent = new Node(current->data); 
			newCurrent = &(*newCurrent)->Next;     
			current = current->Next;              
		}
	}
	return *this;
}

template<typename E>
inline LinkedList<E>& LinkedList<E>::operator=(LinkedList&& other) noexcept
{
	if (this != &other) 
	{  
		Purge();
		head = other.head;
		other.head = nullptr;
	}
	return *this;
}

template<typename E>
inline void LinkedList<E>::AddAtFront(const E& other)
{
	head = new Node(other, head);
	// Make the head equal to the the new node that takes in the data (new head), then takes the old head as its data
}

template<typename E>
inline void LinkedList<E>::AddAtEnd(const E& other)
{
	if (head == nullptr)
	{
		head = new Node(other);
		// If the LinkedList doesn't exist, then this will create a new one with this data as the head
	}
	else
	{
		Node* current = head;               // A Node pointer called current will point to the head of the LinkedList
		while (current->Next != nullptr)    // While loop, that when the data Next to the head doesnt equal nullptr
		{                                   // Traversing to the end of the LinkedList
			current = current->Next;        // After reaching the end of the linked list, we set the last Node to current
		}
		current->Next = new Node(other);    // Now point to the Node after current (current being the last Node) and then create a New Node and add our data there	
	}
}

template<typename E>
inline void LinkedList<E>::AddAtIndex(const E& other, size_t index)
{
	if (index == 0)
	{
		AddAtFront(other);
		// If the index = 0, then the node either doesm't exist or we're adding to the front, so we can call AddAtFront to do the work instead of recoding it 
	}
	else
	{
		Node* current = head;                                  // A Node pointer called current will point to the head of the LinkedList
		size_t currentIndex = 0;                               // Set the currentIndex to 0
		while (current != nullptr && currentIndex < index - 1) // While the current doesnt equal null and the index is less then the CHOSEN index-1 (the index before the index chosen)
		{
			current = current->Next;                           // Set current to the Node before the index imputed
			currentIndex++;                                    // Increment CurrentIndex
		}
		if (current == nullptr)
		{
			throw std::out_of_range("Out of Range");           // Throw an error message if imputed index is out of bounds
		}
		Node* newNode = new Node(other, current->Next);        // Make a new node that takes the data imputed
		current->Next = newNode;                               // Now link it to the previousious node
	}
}

template<typename E>
inline E LinkedList<E>::Front() const
{
	if (head == nullptr)
	{
		throw std::out_of_range("List does not exist!");
	}
	return head->data;
}

template<typename E>
inline E LinkedList<E>::End() const
{
	if (head == nullptr)
	{
		throw std::out_of_range("List does not exist!");
	}
	Node* current = head;
	while (current->Next != nullptr)
	{
		current = current->Next;
	}
	return current->data;
}

template<typename E>
inline E& LinkedList<E>::operator[](size_t index)
{
	Node* current = head;
	size_t currentIndex = 0;
	while (current != nullptr && currentIndex < index) {
		current = current->Next;  // Traverse to the specified index
		currentIndex++;
	}

	if (current == nullptr) {
		throw std::out_of_range("Out of Range");
	}

	return current->data;  // Return the data from the node at the specified index
}

template<typename E>
inline const E& LinkedList<E>::operator[](size_t index) const
{
	Node* current = head;
	size_t currentIndex = 0;
	while (current != nullptr && currentIndex < index) {
		current = current->Next;  // Traverse to the specified index
		currentIndex++;
	}

	if (current == nullptr) {
		throw std::out_of_range("Out of Range");
	}

	return current->data;  // Return the data from the node at the specified index
}

template<typename E>
inline E LinkedList<E>::RemoveFront()
{
	if (head == nullptr)
	{
		throw std::out_of_range("List does not exist");
	}

	Node* temp = head;    // Create a new pointer and set it equal to head
	E other = head->data; // Copy the data from head into other
	head = head->Next;    // Now set the Next Node as the head
	delete temp;          // Then delete the old head

	return other;         // then return the data from the old head
}

template<typename E>
inline E LinkedList<E>::RemoveEnd()
{
	if (head == nullptr)
	{
		throw std::out_of_range("List does not exist");
	}
	
	if (head->Next == nullptr)
	{                         // This is for a LinkedList with only one Node
		E other = head->data; // Copy the data from head into other 
		delete head;          // Delete the head
		head = nullptr;       // Set the head to null
		return other;         // Return the data from the head
	}

	Node* current = head;
	while (current->Next != nullptr && current->Next->Next != nullptr) 
	{
		current = current->Next; // This will point to the second to the last node 
	}
	E other = current->Next->data;
	delete current->Next;           // Deletes the very last node (b/c we set current to the 2nd last node, so deleting current Next will delete the last one)
	current->Next = nullptr;        // Now set the last Node spot as NULL
	return other;                   // Now return the old data
}

template<typename E>
inline E LinkedList<E>::RemoveIndex(size_t index)
{
	if (head == nullptr)
	{
		throw std::out_of_range("List does not exist");
	}

	if (index == 0)
	{
		return RemoveFront(); // If the index that is imputed is 0, then just call Remove front 
	}

	Node* current = head;                                   // A Node pointer called current will point to the head of the LinkedList
	size_t currentIndex = 0;                                // Set the currentIndex to 0
	while (current != nullptr && currentIndex < index - 1)  // While the current doesnt equal null and the index is less then the CHOSEN index-1 (the index before the index chosen)
	{
		current = current->Next;                            // Set current to the Node before the index imputed
		currentIndex++;                                     // Increment CurrentIndex
	}

	if (current == nullptr || current->Next == nullptr)
	{
		throw std::out_of_range("List does not exist");
	}
	Node* temp = current->Next;     // Create a temp pointer and set it to current's Next Node
	E other = temp->data;           // Copy the data from temp into other
	current->Next = temp->Next;     // Set current's Next value to temp's Next value
	delete temp;                    // Delete temp (the old node)
	return other;                   // Return the old node's data
}

template<typename E>
inline void LinkedList<E>::Purge()
{
	while (head != nullptr)
	{
		Node* temp = head; // store the head into temp
		head = head->Next; // now set the Next Node as the head
		delete temp;       // then delete the old head (temp)
	}
}

template<typename E>
inline void LinkedList<E>::Display() const
{
	Node* current = head;
	while (current != nullptr)
	{
		std::cout << current->data << std::endl;
		current = current->Next;
	}
}

template<typename E>
inline void LinkedList<E>::Sort(CompareFunction<E> compare)
{
	if (head == nullptr || head->Next == nullptr)
	{
		throw std::out_of_range("List does not exist");
	}
	else
	{
		bool swapped;
		Node* current;
		Node* previous;

		do
		{
			swapped = false;
			current = head;
			previous = nullptr;

			while (current != nullptr && current->Next != nullptr)
			{
				if (compare(current->data, current->Next->data) > 0)
				{
					if (previous == nullptr)
					{
						Node* temp = current->Next;
						current->Next = temp->Next;
						temp->Next = current;
						head = temp;
					}
					else
					{
						Node* temp = current->Next;
						current->Next = temp->Next;
						temp->Next = current;
						previous->Next = temp;
					} swapped = true;
				}
				else
				{
					previous = current;
					current = current->Next;
				}
			}

		} while (swapped);
	}
}

template<typename E>
inline void LinkedList<E>::ForEach(void(*function)(E& other))
{
	Node* current = head;
	while (current != nullptr)
	{
		function(current->data);
		current = current->Next;
	}
}

template<typename E>
template<typename U>
inline void LinkedList<E>::ForEach(void(*function)(E& other1, U& other2) , U& data)
{
	Node* current = head;
	while (current != nullptr)
	{
		function(current->data , data);
		current = current->Next;
	}
}

template<typename E>
inline void LinkedList<E>::Reverse()
{
	if (head == nullptr)
	{
		throw std::out_of_range("List does not exist");
	}

	Node* current = head;
	Node* previous = nullptr;
	Node* Next = nullptr;

	while (current != nullptr)
	{
		Next = current->Next;       // Save the Next node
		current->Next = previous;   // Reverse the current node's Next pointer
		previous = current;         // Move previousious one step forward
		current = Next;             // Move current one step forward
	}
	head = previous;
	
}




