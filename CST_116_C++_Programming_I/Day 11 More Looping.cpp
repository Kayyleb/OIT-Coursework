
#include <iostream>

using namespace std;

void isPrime(int x);
void isPerfect(int n);
void euclideanAlgorithm(int a, int b);

int main() {
	isPrime(15);
	isPerfect(28);
	euclideanAlgorithm(56,49);
}

void isPrime(int x) {
	cout << "enter a number" << endl;
	cin >> x;
	bool found = false;
	for (int i = 2; i < x; i++) {
		if (x % i == 0) {
			found = true;
		}
	}
	if (found) {
	cout << "your number is not prime" << endl;
		}
	else {
		cout << "your number is prime" << endl;
	}
}

void isPerfect(int n) {
	int sum = 0;
	cout << "enter a number" << endl;
	cin >> n;
	for (int i = 1; i < n; i++) {
		if (n% i == 0) {
			sum += i;
		}
	}
	if (sum != n)
	cout << "your number is not perfect" << endl;

	else if (sum == n)
	cout << "your number is perfect" << endl;
}

void euclideanAlgorithm(int a, int b) {
	while (a != b) {
		if (a > b)
			a = (a - b);
		else 
		{
			b = (b - a);
		}
	}
	cout << a;

}
