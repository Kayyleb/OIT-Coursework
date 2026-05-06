#include <iostream>
using namespace std;

void rootbeerVerse(int x);
void printSong();


int main()
{
	printSong();
}

void rootbeerVerse(int x) {
	cout << x << " bottles of rootbeer on the wall" << endl;
	cout << x << " bottles of rootbeer" << endl;
	cout << " take one down, pass it around" << endl;
	cout << (x - 1) << " bottles of rootbeer on the wall" << endl;
	cout << endl;
}

void printSong() {
	for (int i = 99; i > 0; i--)
		rootbeerVerse(i);
}