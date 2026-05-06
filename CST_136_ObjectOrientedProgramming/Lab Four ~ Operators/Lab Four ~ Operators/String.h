// Name: Kayleb Cook
// Programming Assignment: Lab 4 ~ Operators

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdexcept>


class String {
private:
	char* data;
	size_t size;

public:
// CONSTRUCTORS // 

	//Default Constructor: 
	String();

	//Copy Constructor
	String(const String& other);
	
	//Move Constructor
	String(String&& other) noexcept;

	//Takes char
	String(char str);
	
	//Takes Protected Char
	String(const char* str);

// OPERATORS // 

	String& operator=(const String& other);        //Copy Assignment Operator
	String& operator=(String&& other) noexcept;    //Move Assignment Operator

// COMPARISON OPERATORS: //
	
	bool operator<(const String& other) const;     // Less Than
	bool operator>(const String& other) const;     // Greather Than
	bool operator<=(const String& other) const;    // Less Than or Equal To
	bool operator>=(const String& other) const;    // Greater Than or Equal To
	bool operator==(const String& other) const;    // Equal To
	bool operator!=(const String& other) const;    // Not Equal To

	// Stream Insertion
	friend std::ostream& operator<<(std::ostream& os, const String& other);   

	//Concatenations
	String operator+(const String& other) const;    // Plus
	String& operator+=(const String& other);  // Plus Equals

	//Subscript Operator: []
	char& operator[](size_t index);
	const char& operator[](size_t index) const;

	//Destructor
	~String();

	//Other Member Functions: 
	size_t length() const;
	const char* getString() const;

};