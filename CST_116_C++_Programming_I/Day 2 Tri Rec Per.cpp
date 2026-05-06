// Day2 Tri Rec Per.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void rectanglePerimeter();
void trianglePerimeter();
void ageDays();
void cylinderVolume();

int main()
{
    rectanglePerimeter();
    trianglePerimeter();
    ageDays();
    cylinderVolume();
}

void rectanglePerimeter() {
    int base = 0;
    int height = 0;
    cout << "please enter the base: " << endl;
    cin >> base; 
    cout << "please enter the height: " << endl;
    cin >> height;
    int perimeter = ((2 * base) + (2 * height));
    cout << "the perimeter of your rectangle is " << perimeter << "." << endl;
}

void trianglePerimeter() {
    int base = 0;
    int side = 0;
    int side2 = 0;
    cout << "please enter the base: " << endl; 
    cin >> base;
    cout << "please enter the first side: " << endl;
    cin >> side;
    cout << "please enter the second side: " << endl;
    cin >> side2;
    int perimeter = ((base) + (side) + (side2));
    cout << "the perimeter if your triangle is: " << perimeter << "." << endl;
}

void ageDays() {
    int age = 0;
    const int DAYS = 365;
    cout << "please enter your age: " << endl;
    cin >> age;
    int ageinDays = ((age) * (DAYS));
    cout << "your age in days is: " << ageinDays << "." << endl;
}

void cylinderVolume() {
    int radius = 0;
    int height = 0;
    const float PI = 3.14;
    cout << "please enter the radius: " << endl;
    cin >> radius;
    cout << "please enter the height: " << endl;
    cin >> height; 
    float volume = ((PI) * ((radius) * (radius)) * (height));
    cout << "the volume of your cylinder is: " << volume << "." << endl;
}