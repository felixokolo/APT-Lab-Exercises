/*
 * Complex.cpp
 *
 *  Created on: 02.11.2023
 *      Author: acer
 */

#include <cmath>
#include <iostream>
using namespace std;

#include "Complex.h"


Complex::Complex(float real, float imaginary)
{
	if (real <= -100 ||
		real >= 100 ||
		imaginary <= -100 ||
		imaginary >= 100)
	{
		real = 0;
		imaginary = 0;
	}
	this->real = real;
	this->imaginary = imaginary;

	cout << "Complex object generated at " << this << endl;
	cout << "Value = " << *this << endl;
}

Complex::Complex(const Complex &c)
{

	this->real = c.real;
	this->imaginary = c.imaginary;
	cout << "Complex object generated at " << this << endl;
	//cout << "Value = " << *this << endl;
}

void Complex::set(float real, float imaginary)
{
	if (real <= -100 ||
		real >= 100 ||
		imaginary <= -100 ||
		imaginary >= 100)
		{
			real = 0;
			imaginary = 0;
		}
		this->real = real;
		this->imaginary = imaginary;

}

float Complex::abs()
{
	return std::abs(real);
}

void Complex::print()
{
	cout << "Value = " << this->real << " + i" << this->imaginary << endl;
}

Complex Complex::operator +(Complex &rhs)
{
	Complex result;
	result.real = this->real + rhs.real;
	result.imaginary = this->imaginary + rhs.imaginary;
	return result;
}

Complex& Complex::operator -(Complex &rhs)
{
	Complex *result = new Complex;
	result->real = this->real - rhs.real;
	result->imaginary = this->imaginary - rhs.imaginary;
	return *result;
}

Complex& Complex::operator *(Complex &rhs)
{
	return rhs;
}

Complex& Complex::operator /(Complex &rhs)
{
	return rhs;
}

Complex& Complex::operator ++()
{
	this->real += 1;
	this->imaginary += 1;
	return *this;
}

Complex Complex::operator ++(int int1)
{
	Complex old = *this;
	operator++();
	return old;
}



Complex::~Complex()
{
	// TODO Auto-generated destructor stub
}

std::ostream& operator<<(std::ostream& out, Complex c)
{
	out << c.real << " ";
	c.imaginary >= 0? out << "+ i" : out << "- i";
	out << abs(c.imaginary) << endl;
	return out;
}
