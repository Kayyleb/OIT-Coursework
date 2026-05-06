#include "Fractions.h"

Fraction::Fraction() : m_numerator(0), m_denominator(0)
{
}

Fraction::Fraction(int numerator, int denominator): m_numerator(numerator) , m_denominator(denominator)
{
}

void Fraction::add(Fraction f)
{
	int num1 = m_numerator;
	int num2 = f.getNumerator();
	int den1 = m_denominator;
	int den2 = f.getDenominator();
	
	num1 = (num1 * den2);
	num2 = (num2 * den1);
	den1 = (den1 * den2);
	num1 = (num1 + num2);

	m_numerator = num1;
	m_denominator = den1;
	reduce();
}

void Fraction::subtract(Fraction f)
{
	int num1 = m_numerator;
	int num2 = f.getNumerator();
	int den1 = m_denominator;
	int den2 = f.getDenominator();

	num1 = (num1 * den2);
	num2 = (num2 * den1);
	den1 = (den1 * den2);
	num1 = (num1 - num2);

	m_numerator = num1;
	m_denominator = den1;
	reduce();
}

void Fraction::multiply(Fraction f)
{
	int num1 = m_numerator;
	int num2 = f.getNumerator();
	int den1 = m_denominator;
	int den2 = f.getDenominator();

	num1 = (num1 * num2);
	den1 = (den1 * den2);

	m_numerator = num1;
	m_denominator = den1;
	reduce();
}

void Fraction::divide(Fraction f)
{
	int num1 = m_numerator;
	int num2 = f.getNumerator();
	int den1 = m_denominator;
	int den2 = f.getDenominator();
	
	int temp = 0;
	temp = num2;
	num2 = den2;
	den2 = temp;

	num1 = (num1 * num2);
	den1 = (den1 * den2);

	m_numerator = num1;
	m_denominator = den1;
	reduce();
}

void Fraction::reduce()
{
	int a = m_numerator;
	int b = m_denominator;
	while (a != b) {
		if (a > b)
			a = (a - b);
		else {
			b = (b - a);
		}
	}
	m_numerator /= a;
	m_denominator /= a;
}

void Fraction::operator+=(Fraction f)
{
	this->add(f);
}
void Fraction::operator-=(Fraction f)
{
	this->subtract(f);
}
void Fraction::operator*=(Fraction f)
{
	this->multiply(f);
}
void Fraction::operator/=(Fraction f)
{
	this->divide(f);
}


void Fraction::setNumerator(int numerator)
{
	m_numerator = numerator;
}

void Fraction::setDenominator(int denominator)
{
	m_denominator = denominator;
}

int Fraction::getNumerator()
{
	return m_numerator;
}

int Fraction::getDenominator()
{
	return m_denominator;
}

void Fraction::display()
{
	cout << m_numerator << "/" << m_denominator << endl;
}

Fraction::~Fraction()
{
}
