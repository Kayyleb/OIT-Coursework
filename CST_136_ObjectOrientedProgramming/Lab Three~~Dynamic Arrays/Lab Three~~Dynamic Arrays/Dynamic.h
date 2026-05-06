// Name: Kayleb Cook
// Programming Assignment: Lab 3 ~ Dynamic Arrays
#pragma once
#include <iostream>
#include "String.h"

class Dynamic {
private: 
	String* strings;
	int numElements;

public: 
	// 1)  Default Constructor: 
	Dynamic();

	// 2) 2 Argument Constructor
	Dynamic(const String* str , int num);

	// 3) Copy Constructor
	Dynamic(const Dynamic& other);

	// 4) Copy Assignment Operator
	Dynamic& operator=(const Dynamic& other);

	// 5) Move Constructor
	Dynamic(Dynamic&& other) noexcept;

	// 6) Move Assignment Operator
	Dynamic& operator=(Dynamic&& other) noexcept;

	// 7) Destructor
	~Dynamic();


	//Other Member Fucntions: 
	unsigned int Length() const;                   // Returns # of elements in the array
	void addAtEnd(const String& newString);        // Adds the String that was passed in to the end of the array
	void addAtBeginning(const String& newString);  // Adds the string that was passed in to the beggining of the array
	void Delete(const String& other);                    // Removes the first string it findds that case-insensitive matches the parameter                      - if it doesnt find a match, shouldn't error
	void Delete(int index);                        // Removes the string at the specified index, if the index is not valid, throws an appropriate message
	int Search(const String& other);                     // Returns the index of the first string that it finds that case-insensitive matches the parameter     - if it doesnt find a match, shouldn't error
};
