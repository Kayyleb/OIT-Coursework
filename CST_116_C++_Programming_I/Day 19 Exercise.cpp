// Day 19 Exercise.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream inputText("C:\\Users\\kayleb.cook\\Downloads\\input.txt");
	if (inputText.is_open()) {
		int num1;
		int num2;
		int num3;
		int num4;
		int num5;
		inputText >> num1;
		inputText >> num2;
		inputText >> num3;
		inputText >> num4;
		inputText >> num5;
		char string1[25];
		char string2[25];
		char string21[25];
		char string22[25];
		char string23[25];
		char string3[25];
		inputText >> string1;
		inputText >> string2;
		inputText >> string21;
		inputText >> string22;
		inputText >> string23;
		inputText >> string3;
		cout << num1 << "\n";
		cout << num2 << "\n";
		cout << num3 << "\n";
		cout << num4 << "\n";
		cout << num5 << "\n";
		cout << string1 << "\n";
		cout << string2 << " ";
		cout << string21 << " ";
		cout << string22 << " ";
		cout << string23 << "\n";
		cout << string3 << "\n" << endl;
		inputText.close();
	}

	ifstream outputText("C:\\Users\\kayleb.cook\\Downloads\\output.txt");
	if (outputText.is_open()) {
		char word1[25];
		char word2[25];
		cout << "Enter Two Words: " << endl;
		cin.getline(word1, 25);
		cin.getline(word2, 25);
		outputText.close();

		ofstream outputText("C:\\Users\\kayleb.cook\\Downloads\\output.txt");
		if (outputText.is_open()) {
			outputText << "Cecily Heiner \n";
			outputText << "Kayleb Cook\n";
			outputText << word1 << "\n";
			outputText << word2 << "\n";
			outputText.close();
		}

	}
}