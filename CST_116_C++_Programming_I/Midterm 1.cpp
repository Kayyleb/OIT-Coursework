// Day8Midterm1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void weeklyWage();
void progressReport();

int main() {
	
	weeklyWage();
	progressReport();
}

void weeklyWage() {
	int hours = 0;
	float hourlyWage = 0;
	cout << "How many hours a week do you work?" << endl;
	cin >> hours;
	cout << "What is your hourly wage?" << endl;
	cin >> hourlyWage;
	float weeklyWage = ((hours) * (hourlyWage));
	cout << "The amount of money you make in a single week is: $" << weeklyWage << "." << endl;
}

void progressReport() {
	int answerOne = 0;
	int answerTwo = 0;
	cout << "What is 1 + 2" << endl;
	cin >> answerOne;
	cout << "What is 2 + 3" << endl;
	cin >> answerTwo;

	if ((answerOne == 3) && (answerTwo == 5))
		cout << "Good Job!" << endl;
	else if (((answerOne != 3) && (answerTwo == 5)) || ((answerOne == 3) && (answerTwo != 5)))
		cout << "You're making progress." << endl;
	else if ((answerOne != 3) && (answerTwo != 5))
		cout << "Please get help from the teacher" << endl;
}

Question 3
3a) The CPU is made of the Arithmetic Logic Unit(ALU) which conducts the artihmetic part of the cpu, such as adding and subtracting, and is also the logic part of the CPU which will compare values to see if they are equal.
The next part of the CPU is the Control Unit(CU) which executes instructions that you program for it, and it chooses which instructions to execute.The last part of the CPU is the Registers, which basically holds and stores
data that is constantly being manipulated or changed by the various things you do with your computer.

3b) Charles Babbage is credited for creating the Analytical Engine, and is known as the father of computing.
Ada Lovelace on the other hand is credited for creating the program for the analytical engine, and is credited as the first programmer, meaning she created the first program.