#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Fraction {
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction();
	Fraction(int numerator, int denominator);
	
	void add(Fraction f);
	void subtract(Fraction f);
	void multiply(Fraction f);
	void divide(Fraction f);
	void reduce();
	void operator+=(Fraction f);
	void operator-=(Fraction f);
	void operator*=(Fraction f);
	void operator/=(Fraction f);


	void setNumerator(int numerator);
	void setDenominator(int denominator);

	int getNumerator();
	int getDenominator();

	void display();

	~Fraction();
};