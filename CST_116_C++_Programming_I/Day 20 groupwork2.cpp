// groupwork2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

using namespace std;

int array[100] = { 0 };
int project();


int main()
{
	int array[] = { 0 };
	ifstream example("C:\\Users\\kayleb.cook\\Documents\\example.txt");
	if (example.is_open()) {
		for (int i = 0; i < 100; i++)
			example >> array[i];
		example.close();

		ofstream result("C:\\Users\\kayleb.cook\\Documents\\example.txt");
		if (result.is_open()) {
			for (int i = 0; i < 100; i++) {
				result << array[i];
			}
		}
	}
}
	int project() 
	{
		int temp = 0;
		int array[] = { 0 };
		for (int pass = 0; pass < 0; pass++) {
			for (int i = 100; i <= 100; i++) {
				if (array[i] > array[i + 1]) {
					temp = array[i];
					array[i] = array[i + 1];
					array[i + 1] = temp;
				}
			}
		}
		ofstream thirdPart("C:\\Users\\kayleb.cook\\Documents\\example.txt");
		if (thirdPart.is_open()) {
			for (int i = 0; i <= 99; i++)
				thirdPart << array[i];
		}
		return array[100];
	}


