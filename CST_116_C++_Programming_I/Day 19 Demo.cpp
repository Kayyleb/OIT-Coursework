// Day 19.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream demo("C:\\Users\\kayleb.cook\\Downloads\\demo.txt");
	if (demo.is_open()) {
		int num1;
		int num2;
		demo >> num1;
		demo >> num2;
		int sum = num1 + num2;
		char word1[6];
		char word2[6];
		demo >> word1;
		demo >> word2;
		demo.close();

		ofstream rightHand("C:\\Users\\kayleb.cook\\Downloads\\sum.txt");
		if (rightHand.is_open()) {
			rightHand << sum << " ";
			rightHand << word2 << " ";
			rightHand << word1;
			}
		}

}
