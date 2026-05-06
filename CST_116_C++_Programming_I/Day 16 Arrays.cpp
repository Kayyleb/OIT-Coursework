
// Day16 Arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int min(int nums[], int size); //return the minimum value in the array

int max(int nums[], int size); //return the maximum value in the array

int minIndex(int nums[], int size); //return the minimum value in the array

int maxIndex(int nums[], int size); //return the maximum value in the array

int main() {
    int array[] = { 3,2,1,5,4 };
    int arrayB[] = { 5,-7,6,3,-1,2,-4,9,8 };
    cout << min(array, 5) << endl;//should print 1

    cout << max(array, 5) << endl;// should print 5

    cout << minIndex(array, 5) << endl;// should print 2

    cout << maxIndex(array, 5) << endl;//should print 3

    cout << min(arrayB, 9) << endl;//should print -7

    cout << max(arrayB, 9) << endl;// should print 9

    cout << minIndex(arrayB, 9) << endl;// should print 1

    cout << maxIndex(arrayB, 9) << endl;//should print 7
}

int min(int nums[], int size) {
    int minimum = nums[0];
    for (int i = 0; i < size; i++) {
        if (nums[i] < minimum) {
            minimum = nums[i];
        }
    }
    return minimum;
}
int max(int nums[], int size) {
    int maximum = nums[0];
    for (int i = 0; i < size; i++) {
        if (nums[i] > maximum) {
            maximum = nums[i];
        }
    }
    return maximum;
}
int minIndex(int nums[], int size) {
    int minimum = nums[0];
    int minIndex = 0;
    for (int i = 0; i < size; i++) {
        if (nums[i] < minimum) {
            minimum = nums[i];
            minIndex = i;
        }
    }
    return minIndex;
}
int maxIndex(int nums[], int size) {
    int maximum = nums[0];
    int maxIndex = 0;
    for (int i = 0; i < size; i++) {
        if (nums[i] > maximum) {
            maximum = nums[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}



    