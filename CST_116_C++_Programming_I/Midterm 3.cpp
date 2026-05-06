// Midterm3.cpp : Rubric(2 pts for Q1, 2 pts for Q2, 1 pt for Q3)
//1.  Write a function that takes an array of integers and returns the sum of the numbers that are multiples of 5.
// Write two test cases in your main function to test your sumMultiplesOfFive function.
//2. Write a function that reads in a number n from an input text file(input.txt) 
//and prints the number n times to an output file(output.txt).
// For example, if input.txt contains 3, your output.txt should have 333. 
// If input.txt contains 4, your output.txt shsould have 4444.
//3. Answer the following questions.
//3a.  What is a parameter?  What is it useful for?
//3b.  How big a character buffer do you need to store the phrase "games are fun"?
#include <iostream>
#include <fstream>
using namespace std;

int sumMultiplesOfFive(int nums[], int size);

int main()
{
	int arrayExampleOne[] = {5, 8, 10, 15, 23, 14};
	int arrayExampleTwo[] = { 100, 5, 2, 1, 15 }; 
	cout << sumMultiplesOfFive(arrayExampleOne, 6) << endl;
	cout << sumMultiplesOfFive(arrayExampleTwo, 5) << endl;

	ifstream inputNumber("C:\\Users\\kayleb.cook\\Desktop\\input.txt");
	if (inputNumber.is_open()) {
		int number;
			inputNumber >> number;
		inputNumber.close();

		ofstream outputNumber("C:\\Users\\kayleb.cook\\Desktop\\output.txt");
		if (outputNumber.is_open()) {
			for (int i = 0; i < number; i++) {
				outputNumber << number;
			}
		}
	}
}

int sumMultiplesOfFive(int nums[], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		if (nums[i] %5 == 0) {
			sum += nums[i];
		}
	}
	return sum;
}

Questions: 
	3a. A parameter is when you set the variables to stay within a certain range when declaring your function. They are used to pass variables through the function when
		using a function call. It basically sets variables for you to use in your function so that you don't need to write them on and on again. 

	3b. You will need a buffer of 13 to store the phrase, to account for the two spaces, the null character afterwards, and the 10 character phrase. 