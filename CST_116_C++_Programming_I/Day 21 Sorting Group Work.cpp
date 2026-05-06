// Sorting Work.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream unsorted("C:\\Users\\kayleb.cook\\Desktop\\numbers.txt");
	if (unsorted.is_open()) {
		int line[100];
		for (int i = 0; i < 100; i++) {
			unsorted >> line[i];
			cout << line[i] << endl;
		}

		unsorted.close();
		int temp = 0;
		for (int i = 0; i < 99; i++) {
			for (int j = 0; j < 99; j++) {
				if (line[j] > line[j + 1]) {
					temp = line[j];
					line[j] = line[j + 1];
					line[j + 1] = temp;
				}
			}
		}
		ofstream sorted("C:\\Users\\kayleb.cook\\Desktop\\sorted.txt");
		if (sorted.is_open()) {
			for (int j = 0; j < 99; j++)
			sorted << line[j] << endl;
		}
		sorted.close();
	}
}
