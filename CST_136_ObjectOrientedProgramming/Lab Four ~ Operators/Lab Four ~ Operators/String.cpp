// Name: Kayleb Cook
// Programming Assignment: Lab 4 ~ Operators

#include "String.h"

String::String() : data(nullptr) , size(0)
{
}

String::String(const String& other) : size(other.size)
{
	if (other.size > 0)                        // So if the literal exists basically
	{
		data = new char[other.size + 1];       // Allocate memory
		std::strcpy(data, other.data);         // Copy the data into it's own address.
	}
	else
	{
		data = nullptr;
	}
}

String::String(String&& other) noexcept : data(other.data) , size(other.size)
{
	other.data = nullptr;
	other.data = 0;
}

String::String(char str) // Creates a string object that only takes a single character 
{
	data = new char[2];  // Allocate Memory, 1 for the new data and 1 for the \0
	data[0] = str;       // Assign the character 
	data[1] = '\0';      // Null Terminate the String
	size = 1;            // Set the size to one 
}

String::String(const char* str) // Creates a string object that takes a cstring
{
	if (str == nullptr)      // If the string taken in is null
	{
		data = new char[1];  // Allocate Memory for an empty string
		data[0] = '\0';      // Assign to null (Null terminate)
		size = 0;            // Set size to 0
	}
	else 
	{
		size = strlen(str);         //Getting length of input string, then setting size to it
		data = new char[size + 1];  // Allocating memory for the string + a null
		strcpy(data, str);          // Copy all the data from the input string
	}
}

String& String::operator=(const String& other)
{
	if (this != &other) {
		delete[] data;                      // Free existing resource
		size = other.size;
		if (size > 0) {
			data = new char[size + 1];    // Allocate new memory
			std::strcpy(data, other.data);  // Copy the string data
		}
		else {
			data = nullptr;
		}
	}
	return *this;
}

String& String::operator=(String&& other) noexcept
{
	if (this != &other) {
		delete[] data;           // Free existing resource
		data = other.data;       // Transfer ownership
		size = other.size;
		other.data = nullptr;    // Leave the source object in a valid state
		other.size = 0;
	}
	return *this;
}

bool String::operator<(const String& other) const
{
	return strcmp(data , other.data) < 0;
}

bool String::operator>(const String& other) const
{
	return strcmp(data, other.data) > 0;
}

bool String::operator<=(const String& other) const
{
	return strcmp(data , other.data) <= 0;
}

bool String::operator>=(const String& other) const
{
	return strcmp(data, other.data) >= 0;
}

bool String::operator==(const String& other) const
{
 	return strcmp(data, other.data) == 0;
}

bool String::operator!=(const String& other) const
{
	return  strcmp(data, other.data) != 0;
}

String String::operator+(const String& other) const
{
	size_t newSize = (size + other.size);      // The new size of everything (size + other size)
	char* newData = new char[newSize + 1];   // Allocating memory for the new string in newData
	std::strcpy(newData, data);                   // Copy the data into the nee string
	std::strcat(newData, other.data);             // strcat concatenates the two pieces of data, links together both datas into one, storing it in new data

	String sum(newData);                     // Store the new concatenated data into a new string called Sum
	delete[] newData;                        // Clean up space after already storing what was in new data

	return sum;                              // Then return that new string 
	
}

String& String::operator+=(const String& other) 
{
	size_t newSize = (size + other.size);      // The new size of everything (size + other size)
	char* newData = new char[newSize + 1];   // Allocating memory for the new string in newData
	std::strcpy(newData, data);                   // Copy the data into the nee string
	std::strcat(newData, other.data);             // strcat concatenates the two pieces of data, links together both datas into one, storing it in new data}

	delete[] data;                           // Delete data before, to ensure it's clean before storing new data

	data = newData;                          // Set data to the new data to override the old data
	size = newSize;                          // Set size to the new size to override the old size

	return *this;
	
	//Difference between += and + is that in + you are creating a new string that takes the new concatenated data and returning it, 
	//In the += you are doing the exact same but instead of creating a new string and returning it, you just overwrite the old data setting it as the new concatenated data.
}

char& String::operator[](size_t index)               // Actual
{
	if (index >= size) 
	{
		throw std::out_of_range("out of bounds");
	}
	
	return data[index];
}

const char& String::operator[](size_t index) const    // Read only versiom...?
{
	if (index >= size)
	{
		throw std::out_of_range("out of bounds");
	}

	return data[index];
}

String::~String()
{
	delete[] data;
}

size_t String::length() const
{
	return size;
}

const char* String::getString() const
{
	return data;
}

std::ostream& operator<<(std::ostream& os, const String& other)
{
	os << other.getString();
	return os;
}
