// Day5 FortuneTeller.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void fortuneTeller();

int main() {
	fortuneTeller();
}

void fortuneTeller() {
	char color;
	int number;
	int siblings; 

	cout << "What's your favorite color? R for red, B for Blue, P for Pink, G for Green" << endl;
	cin >> color;

	cout << "What's your favorite number?" << endl;
	cin >> number;

	cout << "How many siblings do you have?" << endl;
	cin >> siblings;
	
	if (siblings >= 5)
		cout << "your favorite hoodie will get torn apart by a gang of hamsters." << endl;
	else if (number > 10)
		cout << "You will die in 37 minutes." << endl;
	else if (number < 10)
		cout << "You will make it to the age of 198." << endl;
	else if (color == 'g')
		cout << "a main will give 8 million dollars 2.5 seconds after you see a rainbow" << endl; 

}