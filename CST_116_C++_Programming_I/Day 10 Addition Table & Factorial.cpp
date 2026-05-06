// Day10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void additionTable();
void factorial();

int main() {
	int choice = 0;
	do {
		cout << "Welcome to the program, you have two options. Here they are" << endl;
		cout << "To Quit: 0" << endl;
		cout << "Option One: Addition Tables" << endl;
		cout << "Option Two: Factorials" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			additionTable();
			break;
		case 2:
			factorial();
			break;
		}
	} while (choice != 0);
}

void additionTable() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << (j + i) << "\t";
		}
		cout << endl;
	}
}

void factorial() {
	int x = 0;
	cout << "what number do you want the factorial of?" << endl;
	cin >> x;
	int f = 1; 
	for (int i = 1; i <= x; i++) {
		f = f * i;
	}
	cout << x << " ! is " << f << endl;
}