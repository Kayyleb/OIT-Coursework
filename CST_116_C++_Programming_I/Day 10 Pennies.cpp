// Day10 Pennies.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void pennyADay();

int main()
{
	pennyADay();
}

void pennyADay() {
	int daysWorked = 0;
	int penniesEarned = 1;
	int totalEarned = 1;
	cout << "How many days do you work? " << endl;
	cin >> daysWorked;
	for (int i = 1; i <= daysWorked; i++) 
	{
		cout << i << "\t";
		cout << penniesEarned <<  "\t";
		penniesEarned = penniesEarned * 2; 
		cout << totalEarned << "\n";
		totalEarned = penniesEarned + totalEarned ;
		
	}

	}