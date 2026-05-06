// Name: Kayleb Cook
// Programming Assignment: Lab 4 ~ Operators

#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include "String.h"

int main()
{
	String str1("radios");     //Im listening to them while writing this & I don't know what else to put
	String str2("deaf");
	String insert;

	std::cout << "Comparison Operators: " << std::endl;
	// Less Than
	if (str1 < str2)
	{
		std::cout << str1.getString() << " is LESS than " << str2.getString() << std::endl;
	}
	// Greater Than
	if (str1 > str2)
	{
		std::cout << str1.getString() << " is GREATER than " << str2.getString() << std::endl;
	}
	// Less Than or Equal To
	if (str1 <= str2)
	{
		std::cout << str1.getString() << " is LESS than or EQUAL to " << str2.getString() << std::endl;
	}
	// Greater Than or Equal To
	{
		std::cout << str1.getString() << " is GREATER than or EQUAL to " << str2.getString() << std::endl;
	}
	// Equal To
	if (str1 == str2)
	{
		std::cout << str1.getString() << " is EQUAL to " << str2.getString() << std::endl;
		std::cout << "\n";
	}
	// Not Equal To
	if (str1 != str2)
	{
		std::cout << str1.getString() << " is NOT EQUAL to " << str2.getString() << std::endl;
		std::cout << "\n";
	}

	//Concatenations: 
	std::cout << "Concatenation Outputs: " << std::endl;

	String str3 = str1 + str2;
	std::cout << "The ++ Concatenation of " << str1.getString() << " and " << str2.getString() << " is " << str3.getString() << std::endl;

	str1 += str2;
	std::cout << "The += Concatenation of " << str1.getString() << " and " << str2.getString() << " is " << str1.getString() << std::endl;
	std::cout << "\n";

	//Insertion
	std::cout << "Concatenation Outputs Using Insertion Operator: " << std::endl;
	std::cout << "The ++ Concatenation of " << str1 << " and " << str2 << " is " << str3 << std::endl;

	std::cout << "The += Concatenation of " << str1 << " and " << str2 << " is " << str1 << std::endl;
	std::cout << "\n";

	//Subscript 
	try
	{
		// Character in bounds: 
		std::cout << "Subscript: " << std::endl;
		std::cout << "Char at index 3: " << str1[3] << std::endl;

		// Character out of bounds: 
		std::cout << "Char at index 15: " << str1[15] << std::endl;
		std::cout << "\n";
	}
	catch(const std::out_of_range& e)
	{
		std::cerr << "Exception " << e.what() << std::endl;
	}
}