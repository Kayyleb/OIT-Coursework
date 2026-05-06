// Day6 Median Conditionals.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void conditionalMedian();

int main() {
	
	conditionalMedian();
}

void conditionalMedian() {
	int numberInput1;
	int numberInput2;
	int numberInput3;

	cout << "enter your first number" << endl;
	cin >> numberInput1; 
	cout << "enter your second number" << endl;
	cin >> numberInput2;
	cout << "enter your third number" << endl;
	cin >> numberInput3; 

	if ((numberInput2 > numberInput1) && (numberInput2 < numberInput3))
		cout << "your median is: " << numberInput2 << "." << endl;

	else if ((numberInput1 > numberInput2) && (numberInput1 > numberInput3) && (numberInput2 > numberInput3))
		cout << "your median is: " << numberInput2 << "." << endl;

	else if ((numberInput1 < numberInput2) && (numberInput2 > numberInput3) && (numberInput1 < numberInput3))
		cout << "your median is: " << numberInput3 << "." << endl;

	else if ((numberInput1 > numberInput2) && (numberInput1 > numberInput3) && (numberInput3 > numberInput2))
		cout << "your median is: " << numberInput3 << "." << endl;

	else if ((numberInput1 < numberInput2) && (numberInput1 > numberInput3) && (numberInput2 > numberInput3))
		cout << "your median is: " << numberInput1 << "." << endl;

	else if ((numberInput1 > numberInput2) && (numberInput1 < numberInput3) && (numberInput3 > numberInput2))
		cout << "your median is: " << numberInput1 << "." << endl;

}
