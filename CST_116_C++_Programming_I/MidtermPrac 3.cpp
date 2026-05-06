// Midterm Three.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

using namespace std;

void removeVowels();

int main()
{
	removeVowels();

	ifstream fin("C:\\Users\\kayleb.cook\\Desktop\\readIn.txt");
	ofstream fout("C:\\Users\\kayleb.cook\\Desktop\\readOut.txt");
	char sentence[100];
	if (fout.is_open()) {
		if (fin.is_open()) {
			while (!fin.eof()) {
				fin >> sentence;
				fout << sentence;
			}
			fin.close();
		}
	}
}

void removeVowels() {
	char remove[25];
	cout << "Enter your word" << endl;
	cin >> remove;
	for (int i = 0; i < strlen(remove); i++) {
		if (remove[i] != ('a')&& remove[i] != ('e') && remove[i] != ('i') && remove[i] != ('o') && remove[i] != ('u')) {
			cout << remove[i];
			}
		}
	}

Questions: 
3a) a function call is when you pass a function's properties, such as Char sentence[100], which is an array, and then use only the name declared to represent the whole function.
It makes it easier to pass on functions without having to rewrite entire lines of code to do the same thing. 

3b) when making a character array, you have to give the array a range, so that it knows how many characters it needs to read. Also when setting a variable to a specific output,
there is no reason or way to cin a variable into the character, cause it was already set.

3c) Binary search is when a piece of data is needed to be pinpointed, then the array is split in half, then it is determined which section the value is in, and then that half is split in half again, and again, until the data is found. 
Linear search is when each value in the array is compared with the target data, if the data matches, then it is processed, but if not, it is moved on and the process continues until it finds a match. If all parts of the array are searched, then it is
determined for the data needed to not exist. Overall Binary search is more efficient, but does require the data to be sorted by a certain key value. 