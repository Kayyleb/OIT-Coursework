#include <iostream>
#include <fstream>
using namespace std;

int powerExerciseOne(int n, int p);
int binarySearch(int arr[], int begin, int end, int search);
int displayCharacters(char* chars);
int fibonacci(int f);
int twelveDays(int c);

int main() {
	// Part One
		// Exercise One
	int n = 0;
	int p = 0;
	cout << "Enter Base Number" << endl;
	cin >> n;
	cout << "Enter Power Number" << endl;
	cin >> p;
	cout << powerExerciseOne(n, p) << endl;
	//Exercise 2
	int arr[] = { 1 , 2, 3, 4, 5, 8, 9, 15, 34 };
	int begin = 0;
	int end = 8;
	int search = 3;
	cout << binarySearch(arr, 0, 9, 3) << endl;
	//Part Two
		//Exercise 3
	char chars[] = { 'a' , 'b' , 'c' , 'd' , 'e' , 'f' , '\0' };
	displayCharacters(chars);
	//Exercise 4
	int f = 0;
	cout << endl;
	cout << "Give a number: " << endl;
	cin >> f;
	cout << fibonacci(f) << endl;
	//Exercise 5
	twelveDays(1);
}

int powerExerciseOne(int n, int p) {
	if (p != 1) {
		n = powerExerciseOne(n, (p - 1)) * n;
	}
	return n;
}

int binarySearch(int arr[], int begin, int end, int search) {
	bool found = false;
	int middle = (begin + end) / 2;
	if (arr[middle] == search) {
		return true;
	}
	else if (search > arr[middle]) {
		begin = middle + 1;
	}
	else if (search < arr[middle]) {
		end = middle - 1;
	}
	found = binarySearch(arr, begin, end, search);
	return found;
}

int displayCharacters(char* chars) {
	if (*chars == '\0') {
		return 0;
	}
	return displayCharacters(chars + 1);
	cout << *chars;

}

int fibonacci(int f) {
	if (f == 0) {
		return 0;
	}
	if (f == 1) {
		return 1;
	}
	return fibonacci(f - 1) + fibonacci(f - 2);
}

int twelveDays(int c) {
	cout << "On the " << c << " day of christmas," << endl;
	switch (c) {
	case 12:
		cout << "Twelve drummers drumming," << endl;
	case 11:
		cout << "Eleven pipers piping," << endl;
	case 10:
		cout << "Ten lords a-leaping," << endl;
	case 9:
		cout << "Nine ladies dancing," << endl;
	case 8:
		cout << "Eight maids a-milking," << endl;
	case 7:
		cout << "Seven swans a-swimming," << endl;
	case 6:
		cout << "Six geese a-laying," << endl;
	case 5:
		cout << "Five golden rings," << endl;
	case 4:
		cout << "Four calling birds," << endl;
	case 3:
		cout << "Three french hens," << endl;
	case 2:
		cout << "Two turtle doves," << endl;
	case 1:
		cout << "my true love gave to me" << endl << "A partridge in a pear tree" << endl;	}
	if (c != 12) {
		return twelveDays(c + 1);
		}
}