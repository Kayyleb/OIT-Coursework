// MidtermPrac2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void questionOne();
void questionTwo();

int main()
{
	questionOne();
	questionTwo();
}

void questionOne() 
{
	int angleOne = 0;
	int angleTwo = 0; 

	cout << "Enter your first angle: " << endl;
	cin >> angleOne;
	while ((angleTwo + angleOne) != 180) {
		cout << "Enter your supplementary angle: " << endl;
		cin >> angleTwo;

	}

	if ((angleTwo >= 90 && (angleTwo + angleOne) == 180))
		cout << "your supplementary angle is obtuse." << endl;
	else if ((angleTwo < 90 && (angleTwo + angleOne) == 180))
		cout << "your supplementary angle is acute." << endl;
}

void questionTwo()
{
	int n = 1;
	cout << "Enter your selected number" << endl;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cout << pow(i, 2) << "\t";
	}
}


questionThree
a) An infinite loop is a loop that has no end, and will continuously execute unless stopped / terminated manually.
b) The only difference between c and c++ regarding loops is that in C, it is illegal to decalre
variables in the intialization of the for loop; all variables must be declared at the beginning of a block.
c) If theres an error in my code, such as the output, you want to put a breakpoint on the loop, and then step into it, essentially
running the whole program step by step to see exactly where the error is occuring in the loop, then fix it from there. 

