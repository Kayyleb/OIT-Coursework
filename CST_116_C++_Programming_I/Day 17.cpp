// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int countChars(char str[], char c);//count and return the number of times a specific character occurs in a cString

bool isAlphaStr(char str[]);         //return true if the cString is all alphabetic characters

int endsIn3(int nums[], int n);            //returns how many integers end in 3-- should use modulus

int sumOfOdds(int nums[], int n);   //returns the sum of the odd numbers in the array

int main()
{
    char yellowFruit[] = "banana";

    char redFruit[] = "apple";

    char droid[] = "R2D2";

    int nums[] = { 13,7,24,23, 32 };

    int numsb[] = { 123, 456, 789, 23, 56, 89, 14, 73 };

    cout << countChars(yellowFruit, 'a') << endl;                    //should print 3

    cout << countChars(redFruit, 'p') << endl;                       //should print 2

    cout << (isAlphaStr(yellowFruit) ? "pass" : "fail") << endl;  //should print pass

    cout << (isAlphaStr(droid) ? "fail" : "pass") << endl;            //should print pass
   
    cout << endsIn3(nums, 5) << endl;                                //should print 2  

    cout << endsIn3(numsb, 8) << endl;                               //should print 3

    cout << sumOfOdds(nums, 5) << endl;                              //should print 43

    cout << sumOfOdds(numsb, 8) << endl;                             //should print 1097


}

int countChars(char str[], char c) {
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == c) {
            count++;
        }
    }
    return count;
}

bool isAlphaStr(char str[]) {
    for (int i = 0; i < strlen(str); i++) {
        if (isalpha(str[i]) == 0)
            return false;
    }
    return true;
}


int endsIn3(int nums[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++ ) {
        if (nums[i] %10 == 3) {
            count++;
        }
    }
    return count;
}

int sumOfOdds(int nums[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] % 2 == 1) {
            sum += nums[i];
        }
    }
    return sum;
}