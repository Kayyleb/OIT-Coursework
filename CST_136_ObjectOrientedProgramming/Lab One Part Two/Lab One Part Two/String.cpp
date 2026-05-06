#define _CRT_SECURE_NO_WARNINGS
#include "String.h"


String::String() : data(nullptr) , length(0)
{
	std::cout << "String Default Constructor" << std::endl;

}

String::String(const char* str) : length(std::strlen(str)) 
										 //Get the length of the input string. When string is imputed, 
										 // runs the whole string and copies it's length into length
{
	std::cout << "String 1 Argument Constructor" << std::endl;
	if (str) {
		data = new char[length + 1];     // Allocate memory for the string and null terminator.
		std::strcpy(data, str);          // Copy the string data into data, so it will be perserved.
	}
	else {                               // If no literal in inputed, then data is just null, and length is reset to zero
		data = nullptr;
		length = 0;
	}
}

String::String(const String& other) : length(other.length)
{
	std::cout << "String Copy Constructor" << std::endl;
	if (other.length > 0)                      // So if the literal exists basically
	{
		data = new char[other.length + 1];     // Allocate memory
		std::strcpy(data, other.data);         // Copy the data into it's own address.
	}
	else 
	{
		data = nullptr;
	}
	// Summary: If the literal exists, then it will alocate memory into a new character address and copy it there. 
	
	/* To my own understanding, 1 Arg Ctor makes sure the string exists and inputs it's data such as length and the word itself, 
	then copy ctor does almost the same but stores it in it's own address so the original data variable can be over written later*/
}

String& String::operator=(const String& other)
{
	std::cout << "String Copy Assignment" << std::endl;
	if (this != &other) {
		delete[] data;                      // Free existing resource
		length = other.length;                
		if (length > 0) {
			data = new char[length + 1];    // Allocate new memory
			std::strcpy(data, other.data);  // Copy the string data
		}
		else {
			data = nullptr;
		}
	}
	return *this;
}

String::String(String&& other) noexcept : data(other.data) , length(other.length)
{
	std::cout << "String Move Constructor" << std::endl;
	other.data = nullptr;
	other.length = 0;
}

String& String::operator=(String&& other) noexcept
{
	std::cout << "String Move Assignemnt" << std::endl;
	if (this != &other) {
		delete[] data;           // Free existing resource
		data = other.data;       // Transfer ownership
		length = other.length;
		other.data = nullptr;    // Leave the source object in a valid state
		other.length = 0;
	}
	return *this;
}

String::~String()
{
	delete[] data;
	std::cout << "String Destructor" << std::endl;
}
