/*
 * CCoordinate.cpp
 *
 *  Created on: 18 Oct 2023
 *      Author: FELIX WORKSTATION
 */


#include <iostream>
#include "Coordinate.h"
#include <string>

using namespace std;

/**
 * Constructor method for initializing data members in the Cartesian coordinate
 *
 * @param [in] x Float value describing the x-axis position on the Cartesian
 * coordinate. Default (0)
 * @param [in] y Float value describing the y-axis position on the Cartesian
 * coordinate. Default (0)
 * @param [in] z Float value describing the z-axis position on the Cartesian
 * coordinate. Default (0)
 */
Coordinate::Coordinate(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
	cout << "Constructor generates object at " << this << endl;
	cout 	<< "Value = (" << this->x << ", "
			<< this->y << ", " << this->z << ")"
			<< endl;
}

Coordinate::~Coordinate()
{
	// TODO Auto-generated destructor stub
}

