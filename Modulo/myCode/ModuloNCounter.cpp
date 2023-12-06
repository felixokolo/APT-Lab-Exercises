/*
 * ModuloNCounter.cpp
 *
 *  Created on: 03.11.2023
 *      Author: Felix
 */

/**
 * \example main.cpp
 * This is a sample code on how to use the ModuloNCounter class.
 */


#include <iostream>
using namespace std;

#include "ModuloNCounter.h"

ModuloNCounter::ModuloNCounter(unsigned int counterSize,
							   unsigned int digitType)
{
	if (counterSize < MIN_COUNTER_SIZE)
	{
		cout << "Number of digits is less than the minimum of "
			 << MIN_COUNTER_SIZE << endl;
		cout << "Setting number of digits to " << MIN_COUNTER_SIZE << endl;
		counterSize = MIN_COUNTER_SIZE;
	}

	if (counterSize > MAX_COUNTER_SIZE)
	{
		cout << "Number of digits exceeds maximum of "
			 << MAX_COUNTER_SIZE << endl;
		cout << "Setting number of digits to " << MAX_COUNTER_SIZE << endl;
		counterSize = MAX_COUNTER_SIZE;
	}


	this->counterSize = counterSize;

	if (!(digitType == BIN ||
		  digitType == OCT ||
		  digitType == DEC ||
		  digitType == HEX))
	{
		cout << "Invalid input" << endl;
		return;

	}

	this->digitCountersArray = (new ModuloNDigit[counterSize]);
	//this->digitCountersArray =
	//		(ModuloNDigit*) malloc(sizeof(ModuloNDigit*) * counterSize);

	// Initialize array with ModuluNDigit counters with max size of digitType
	for (unsigned int i = 0; i < this->counterSize; i++)
		digitCountersArray[i] = ModuloNDigit(digitType);

}

ModuloNCounter::ModuloNCounter(ModuloNCounter &origin)
{
	counterSize = origin.counterSize;
	this->digitCountersArray = new ModuloNDigit[counterSize];

	for (unsigned int i = 0; i < this->counterSize; i++)
		this->digitCountersArray[i] = origin.digitCountersArray[i];
}

ModuloNCounter& ModuloNCounter::operator ++()
{
	for (unsigned int i = counterSize - 1; i >= 0; i--)
	{
		++digitCountersArray[i];
		if (digitCountersArray[i].isOverflow() && i != 0)
			continue;
		else
			break;
	}
	return *this;
}

ModuloNCounter ModuloNCounter::operator ++(int c)
{
	ModuloNCounter tmp(2, 2);
	tmp = *this;
	operator ++();
	return tmp;

}

void ModuloNCounter::print()
{
	for (unsigned int i = 0; i < counterSize; i++)
		digitCountersArray[i].print();
}

/*std::ostream& operator <<(std::ostream& out, ModuloNCounter counter)
{
	for (unsigned int i = 0; i < counter.counterSize; i++)
		out << counter.digitCountersArray[i];
	return out;
}*/

ModuloNCounter& ModuloNCounter::operator =(ModuloNCounter& rhs)
{
	if (this ==  &rhs)
		return *this;

	if (rhs.counterSize != this->counterSize)
	{
		this->counterSize = rhs.counterSize;
		delete[] this->digitCountersArray;
		this->digitCountersArray = new ModuloNDigit[rhs.counterSize];
	}
	else
	{
		// Do nothing
	}
	for (unsigned int i = 0; i < this->counterSize; i++)
		this->digitCountersArray[i] = rhs.digitCountersArray[i];
	return *this;
}


ModuloNCounter::~ModuloNCounter()
{
	delete[] digitCountersArray;
}

