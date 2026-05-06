// Name: Kayleb Cook
// Programming Assignment: Lab 3 ~ Dynamic Arrays
#include "Dynamic.h"

Dynamic::Dynamic() : strings(nullptr) ,  numElements(0)
{
}

Dynamic::Dynamic(const String* str, int num)
{

}

Dynamic::Dynamic(const Dynamic& other)
{
	strings = new String[numElements];
	for (int e = 0; e < numElements; e++) 
	{
		strings[e] = other.strings[e];
	}
}

Dynamic& Dynamic::operator=(const Dynamic& other)
{
	if (this != &other)
	{
		delete[] strings;
		numElements = other.numElements;
		strings = new String[numElements];
		for (int e = 0; e < numElements; e++) 
		{
			strings[e] = other.strings[e];
		}
	}
	return *this;
}

Dynamic::Dynamic(Dynamic&& other) noexcept : strings(other.strings), numElements(other.numElements)
{
	other.strings = nullptr;
	other.numElements = 0;
}

Dynamic& Dynamic::operator=(Dynamic&& other) noexcept 
{
	if (this != &other)
	{
		delete[] strings;
		numElements = other.numElements;
		strings = other.strings;

		other.numElements = 0;
		other.strings = nullptr;
	}
	return *this;
}

Dynamic::~Dynamic()
{
	delete[] strings;
}


// Member Functions: 
unsigned int Dynamic::Length() const 
{
	return numElements;
}

void Dynamic::addAtEnd(const String& newString)
{
	String* newArray = new String[numElements + 1];  // create new array with space for another element
	for (int e = 0; e < numElements; e++)
	{
		newArray[e] = strings[e];                    // copy all existing elements into newArray
	}
	
	newArray[numElements] = newString;               // then add the new string at the end

	delete[] strings;                                // delete the old array
	strings = newArray;                              // then update the pointer

	numElements++;
}

void Dynamic::addAtBeginning(const String& newString)
{
	String* newArray = new String[numElements + 1];  // create new array with space for another element
	newArray[0] = newString;                         // insert the new string (at the very beginning) 
	for (int e = 0; e < numElements; e++)
	{
		newArray[e + 1] = strings[e];                // copy all existing elements into newArray
	}                                                // since we added the new string at the beginning, must allocate enough space for that one plus the rest that are being copied
	                                                 // if newArray has [1/1] items and strings has [x/x] items then newArray must have [1+x] to have enough space for everything after the one we added at the beginning
	newArray[numElements] = newString;               // then add the new string at the end

	delete[] strings;                                // delete the old array
	strings = newArray;                              // then update the pointer

	numElements++;
}

void Dynamic::Delete(const String& other)
{
}

void Dynamic::Delete(int index)
{
}

int Dynamic::Search(const String& str)
{
	for (int e = 0; e < numElements; e++) {
		if (str = strings[e])
		{
			return numElements;
		}
	}
	return 0;
}
