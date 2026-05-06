// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void reliabilityTesting();
void weatherAdvice();

int main() {
	reliabilityTesting();
	weatherAdvice(); 
}

void reliabilityTesting() {
	int time = 0;
	int velocityLambda = 0;
	int frequencyLambda = 0;
	float e = 2.71828183;

	cout << "Enter the Velocity for the Lambda value" << endl;
	cin >> velocityLambda;
	cout << "Enter the Frequency for the Lambda value" << endl;
	cin >> frequencyLambda;
	int lambda = ((velocityLambda) / (frequencyLambda));
	cout << "Enter the value for time" << endl;
	cin >> time;
	float reliabilityEquation = pow(e, ((lambda) * (time)));
	cout << "Your realibity value is: " << reliabilityEquation << "." << endl;

}

void weatherAdvice() {
	int tempature = 0;
	char cloudySunny;
	cout << "Is it cloudy today? (put Y for yes, and N for no) " << endl;
	cin >> cloudySunny;
	cout << "What is the tempature today? " << endl;
	cin >> tempature;
	
	if (cloudySunny == 'n')
		cout << "It is Sunny today!" << endl;
	else if ((tempature >= 32) && (cloudySunny == 'y'))
		cout << "It is going to rain today" << endl;
	else if ((tempature < 32) && (cloudySunny == 'y'))
		cout << "it is going to snow today" << endl;
}
