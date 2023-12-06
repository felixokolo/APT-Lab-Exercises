/*
 * Complex.h
 *
 *  Created on: 02.11.2023
 *      Author: acer
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>

class Complex
{
private:
	float real;
	/**< Float variable representing the real part of a complex number*/
	float imaginary;
	/**< Float variable representing the imaginary part of a complex number*/

public:
	/**
	 * Default constructor for Complex class. Initializes an instance of a Complex
	 * class with passed arguments.
	 * @param [in] real Float parameter representing the real part of
	 * a complex number. Default value = 0.
	 * @param [in] imaginary Float parameter representing the real part of
	 * a complex number. Default value = 0.
	 */

	Complex(float real = 0, float imaginary = 0);
	/**
	 * Copy constructor for Complex class. Initializes an instance of a Complex
	 * class with passed arguments.
	 * @param [in] c Complex object to be copied into the new instance.
	 */
	Complex(Complex const &c);

	/**
	 * Sets the values of the real and imaginary members of the Complex object
	 * to the specified values.
	 * @param [in] real Float parameter representing the real part of
	 * a complex number.
	 * @param [in] imaginary Float parameter representing the real part of
	 * a complex number.
	 */
	void set(float real, float imaginary);

	/**
	 * Calculates the absolute value of the complex number.
	 * @return float value representing the absolute value of the complex
	 * number.
	 */
	float abs();

	/**
	 * Prints the complex number in a pretty format.
	 */
	void print();

	/**
	 * Overloaded operator function + operator.
	 * @param [in] rhs Complex object to be added.
	 */
	Complex operator+(Complex &rhs);

	/**
	 * Overloaded operator function - operator.
	 * @param [in] rhs Complex object to be subtracted.
	 */
	Complex& operator-(Complex &rhs);

	/**
	 * Overloaded operator function * operator.
	 * @param [in] rhs Complex object to be multiplied.
	 */
	Complex& operator*(Complex &rhs);

	/**
	 * Overloaded operator function / operator.
	 * @param [in] rhs Complex object to be divided.
	 */
	Complex& operator/(Complex &rhs);

	/**
	 * Overloaded operator function pre increment operator.
	 */
	Complex& operator++();

	/**
	 * Overloaded operator function post increment operator.
	 */
	Complex operator++(int);

	/**
	 * Overloaded operator function output operator.
	 */
	friend std::ostream& operator<<(std::ostream& out, Complex c);

	virtual ~Complex();
};

#endif /* COMPLEX_H_ */
