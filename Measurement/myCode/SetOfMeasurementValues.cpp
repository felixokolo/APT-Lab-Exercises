/*
 * SetOfMeasurementValues.cpp
 *
 *  Created on: 24 Oct 2023
 *      Author: FELIX
 */

#include <iostream>
#include <float.h>
#include <ctime>
#include "SetOfMeasurementValues.h"

using namespace std;

void SetOfMeasurementValues::printSingleValue(unsigned int pos)
{
	string sUnit = "";
	switch (this->unit)
	{
		case A:
			sUnit = "Ampere";
		break;

		case V:
			sUnit = "Volt";
		break;

		case S:
			sUnit = "seconds";
		break;

		case W:
			sUnit = "Watt";
		break;

		case NONE:
			sUnit ="";
		break;

	}
	cout 	<< "Value[" << pos << "]: "
			<< this->value[pos] << " "
			<< sUnit << endl;
}

SetOfMeasurementValues::SetOfMeasurementValues(string name, unit_t unit)
{
	this->name = name;
	this->unit = unit;
	for (int i = MAXVALUE - 1; i >= 0; i--)
		this->value[i] = NOVALUE;
	cout << "Created object at : " << this << endl;
}

void SetOfMeasurementValues::setValue(unsigned int pos, double value)
{
	if (pos >= 0 && pos < MAXVALUE)
		this->value[pos] =value;
	else
		cout << "ERROR setValue: Position out of bounds" << endl;
}

void SetOfMeasurementValues::setRandomValues(int min, int max)
{
	srand(time(nullptr));
	float val = 0;
	for (int pos = 0; pos < MAXVALUE; pos++)
	{
		val = float(rand() % ((max - min)*10))/10 + min;
		setValue(pos, val);
	}
}

void SetOfMeasurementValues::print()
{
	cout << name << ":" << endl;
	for (int pos = 0; pos < MAXVALUE; pos++)
	{
		if (getValue(pos) == NOVALUE)
			continue;
		cout << "\t";
		printSingleValue(pos);
	}
	cout << "\tMax Value: " << getMax() << endl;
	cout << "\tMin Value: " << getMin() << endl;
	cout << "\tAvg Value: " << getAverage() << endl;
}

double SetOfMeasurementValues::getValue(unsigned int pos)
{
	if (pos >= 0 && pos < MAXVALUE)
		return this->value[pos];
	else
		cout << "ERROR getValue: Position out of bounds" << endl;
	return NOVALUE;
}

double SetOfMeasurementValues::getAverage()
{
	float sum = 0;
	int N = 0; // Number of samples
	for (int pos = 0; pos < MAXVALUE; pos++)
	{
		if (getValue(pos) == NOVALUE)
			continue;
		sum += getValue(pos);
		N++;
	}
	return sum / N;
}

double SetOfMeasurementValues::getMax()
{
	double max = DBL_MIN; // Assigns the minimum double value to max variable
		for (int i = MAXVALUE - 1; i >= 0; i--)
			if (this->value[i] != NOVALUE && this->value[i] > max)
				max = this->value[i];
		return max;
}

double SetOfMeasurementValues::getMin()
{
	double min = DBL_MAX; // Assigns the maximum double value to min variable
	for (int i = MAXVALUE - 1; i >= 0; i--)
		if (this->value[i] != NOVALUE && this->value[i] < min)
			min = this->value[i];
	return min;
}
