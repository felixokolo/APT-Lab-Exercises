/**
 * \mainpage
 * ModuloNDigit.cpp
 *
 *  Created on: 03.11.2023
 *      Author: Felix
 *
 *  This class implements a Digit counter that counts up to a
 *  specified maxValue.
 *  It only counts in digits with a maximum digit count of MAX_COUNT of 16
 *  and a minimum digit count of 2.
 *  This class can be used to implement base numbers counting with the base
 *  value represented as maxValue. E.g a maxValue of 2 represents the base 2
 *  number system.
 *
 */

#include <iostream>
using namespace std;

#include "ModuloNDigit.h"


ModuloNDigit::ModuloNDigit(unsigned int maxValue)
{
	setMaxValue(maxValue);
	resetCounter();
	overflowFlag = false;
}

ModuloNDigit& ModuloNDigit::operator ++()
{
	// Checks if currentValue is at max - 1
	this->currentValue == this->maxValue - 1?
			resetCounter() : // Resets to 0
			incrementCounter(); // Increments the currentValue by 1
	return *this;
}

ModuloNDigit ModuloNDigit::operator ++(int c)
{
	ModuloNDigit tmp(this->maxValue);
	tmp = *this;
	this->operator ++();
	return tmp;
}

bool ModuloNDigit::isOverflow()
{
	return overflowFlag;
}

void ModuloNDigit::print()
{
	this->currentValue < 10?
			cout << this->currentValue :
			cout << char('A' + (this->currentValue % 10));
}

/*ostream& operator<<(ostream& out, ModuloNDigit counter)
{
	counter.currentValue < 10?
				cout << counter.currentValue :
				cout << char('A' + (counter.currentValue % 10));
	return out;
}*/

void ModuloNDigit::setMaxValue(unsigned int maxValue)
{
	//Checks if maxValue is greater than the maximum count MAX_COUNT
		if (maxValue > MAX_COUNT)
			maxValue = MAX_COUNT;

		//Checks if maxValue is greater than the minimum count MIN_COUNT
		if (maxValue < MIN_COUNT)
			maxValue = MIN_COUNT;
		this->maxValue = maxValue;
}

void ModuloNDigit::incrementCounter()
{
	currentValue += 1;
	overflowFlag = false;
}

void ModuloNDigit::resetCounter()
{
	currentValue = 0;
	overflowFlag = true;
}
