// Name: Kayleb Cook
// Programming Assignment: Lab 2: Transport More Manager Functions
#pragma once
#include <iostream>
//when making header files dont include ones that don't need to be included
  // Transport can include passenger but not other way around, same for passenger and string!

class String {
private:
	char* data;
	size_t length;

public:
	// 1)  Default Constructor: 
	String();

	// 2) 1 Argument Constructor; Takes a String Literal
	String(const char* str);

	// 3) Copy Constructor
	String(const String& other);
	
	// 4) Copy Assignment Operator
	String& operator=(const String& other);
	
	// 5) Move Constructor
	String(String&& other) noexcept;
	
	// 6) Move Assignment Operator
	String& operator=(String&& other) noexcept;

	// 7) Destructor
	~String();

};
