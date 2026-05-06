//Name: Kayleb Cook
//Programming Assignment: Lab Seven: Templated List Enhancements
#define _CRTDBG_MAP_ALLOC

#include <iostream>
#include <crtdbg.h>
#include "LinkedList.h"

/*
Fixed From Lab 6:
 - "IF" statements instead of while statements for throwing error messages
 - Made sure to transfer ownership from other.head to head in the move ctor
 - Separated class LinkedList class Node by defining Node after LinkedList, but defining it in LinkedList instead
 - Added Default, Copy, & Move Ctors to Node as well as Copy & Move Operators, and Dtor
 - Changed function names to the correct names
*/

void multiply(int &num) 
{
	int value = 25;
	num = num * value;
}
void Sum(int& num1, int& num2)
{
	num1 += num2;
}
int compInts(const int& num1 , const int& num2)
{
	if (num1 < num2) return -1;
	if (num1 > num2) return 1;
	return 0;
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	try
	{
		LinkedList<int> List; // Creates a linked list of doubles
		List.AddAtFront(7);
		List.AddAtEnd(14);
		List.AddAtFront(8);
		List.AddAtEnd(21);
		List.AddAtIndex(21, 1);
		List.AddAtFront(75);
		List.AddAtEnd(1);
		List.AddAtFront(2);
		List.AddAtEnd(121);
		List.AddAtIndex(31, 1);

		std::cout << "After Modifying List: " << " " << std::endl;
		List.Display(); // Displaying after adding & removing elements 
		std::cout << "\n" << std::endl;

		// Using the index operator
		std::cout << "Index 0: " << List[0] << std::endl;
		std::cout << "Index 1: " << List[1] << std::endl;
		std::cout << "Index 2: " << List[2] << std::endl;
		std::cout << "\n" << std::endl;

		// Removing Values
		int val1 = List.RemoveFront();
		std::cout << "Removed Front value: " << val1 << std::endl;

		int val2 = List.RemoveEnd();
		std::cout << "Removed End value: " << val2 << std::endl;
		std::cout << "\n" << std::endl;

		std::cout << "After Modifying List: " << " " << std::endl;
		List.Display();


		int val3 = List.RemoveIndex(1);
		std::cout << "Removed Index value " << val3 << std::endl;
		std::cout << "\n" << std::endl;

		std::cout << "After Modifying List: " << " " << std::endl;
		List.Display();
		std::cout << "\n" << std::endl;

		// Returning Front & End Values
		std::cout << "Front Value: " << List.Front() << std::endl;
		std::cout << "End Value: " << List.End() << std::endl;
		std::cout << "\n" << std::endl;

	//Lab Seven Functions: 
		//ForEach
		std::cout << "List after For Each: " << std::endl;
		List.ForEach(multiply);
		List.Display();
		std::cout << "\n" << std::endl;
		
		//ForEach + Parameter
		int value = 245;
		std::cout << "List After For Each + Additional Data: " << std::endl;
		List.ForEach(Sum, value);
		List.Display();
		std::cout << "\n" << std::endl;

		//Reverse
		std::cout << "Linked List: " << std::endl;
		List.Display();
		std::cout << "\n" << std::endl;

		std::cout << "Reversed Linked List: " << std::endl;
		List.Reverse();
		List.Display();
		std::cout << "\n" << std::endl;


		std::cout << "Sorted Linked List: " << std::endl;
		List.Sort(compInts);
		List.Display();
	}

	catch (const std::out_of_range& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}