// Midterm2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void snowfall();
void oddNumbers();

int main()
{
    snowfall();
    oddNumbers();
}

void snowfall() {
    int sum = 0;
    int n = 1;
    cout << "How much snow has fallen?" << endl;
    while (n != 0) {
        cin >> n;
            sum += n;
    }
    cout << (sum) << endl;
}

void oddNumbers() {
    int n = 1;
    int s = 0;
    cout << "enter your starting value" << endl;
    cin >> s;
    cout << "enter the amount of numbers you want to print" << endl;
    cin >> n;

    for (int i = s; i < (n * 2)+s; i+=2) {
            cout << i << "\t";
    }
}