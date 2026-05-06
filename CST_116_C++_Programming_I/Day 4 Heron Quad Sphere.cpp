#include <iostream>

using namespace std;

void heronsFormula();
void quadraticFormula();
void sphereVolume();

int main()

{
    heronsFormula();
    quadraticFormula();
    sphereVolume();
}

void heronsFormula() {
    int a = 0;
    int b = 0;
    int c = 0; 
    cout << "enter the value of a:" << endl;
    cin >> a; 
    cout << "enter the value of b:" << endl;
    cin >> b;
    cout << "enter the value of c:" << endl;
    cin >> c; 
    int s = (((a)+(b)+(c)) / (2));
    int area = sqrt(s * ((s - a) * (s - b) * (s - c)));
    cout << "the area of your triangle is: " << area << "." << endl;
}

void quadraticFormula() {
    int a = 0; 
    int b = 0;
    int c = 0;
    cout << "enter the value of a:" << endl;
    cin >> a;
    cout << "enter the value of b:" << endl;
    cin >> b;
    cout << "enter the value of c:" << endl;
    cin >> c;
    int positiveX = (-b + sqrt( (b * b) - 4 * (a * c))) / (2 * a);
    int negativeX = (-b - sqrt( (b * b) - 4 * (a * c))) / (2 * a);
    cout << "your two solutions are: " << positiveX << " and " << negativeX << endl;
}

void sphereVolume() {
    int radius = 0;
    const float PI = 3.14;
    const float x = 4.0 / 3.0;
    cout << "enter your radius: " << endl;
    cin >> radius;
    float volume = ((x) * (PI) * (pow(radius, 3)));
    cout << "the volume of your sphere is: " << volume << "." << endl;

}