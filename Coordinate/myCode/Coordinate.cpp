/*
 * CCoordinate.cpp
 *
 *  Created on: 18 Oct 2023
 *      Author: FELIX WORKSTATION
 */


#include <iostream>
#include <cmath>
#include "Coordinate.h"

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

void Coordinate::getPolar(float *r, float *phi, float *theta)
{
	*r = sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));

	float pi = 2 * acos(0.0);
	if (x != 0 && y >= 0)
		*phi = acos(this->x / sqrt(pow(this->x, 2) + pow(this->y, 2)));
	else if (x != 0 && y < 0)
		*phi = 2 * pi - acos(this->x / sqrt(pow(this->x, 2) + pow(this->y, 2)));
	else
	{
		cout 	<< "WARNING: Undefined result. "
				<< "Setting all angles to 0"
				<< endl;
		*phi = 0l;
		*theta = 0l;
		return;
	}
	*theta = pi / 2 - atan(z / sqrt(pow(this->x, 2) + pow(this->y, 2)));
	*phi = *phi * 180 / pi;
	*theta = *theta * 180 / pi;

}

void Coordinate::getCylinder(float *r, float *phi, float *h)
{
	*r = sqrt(pow(this->x, 2) + pow(this->y, 2));

	float pi = 2 * acos(0.0);
	if (this->x > 0)
		*phi = atan(this->y / this->x);
	else if (this->x < 0 &&this->y >= 0)
		*phi = atan(this->y / this->x) + pi;
	else if (this->x < 0 && this->y < 0)
		*phi = atan(this->y / this->x) - pi;
	else if (this->x == 0 && this->y > 0)
		*phi = pi / 2;
	else if (this->x == 0 && y < 0)
		*phi = -pi / 2;
	else
	{
		cout << "WARNING: Undefined result. Setting phi to 0" << endl;
		*phi = 0l;
	}

	*h = this->z;
	*phi = *phi * 180 / pi;

}

/*
 * Instance deconstructor method
 */
Coordinate::~Coordinate()
{
	cout << "Destructor destroys object at " << this << endl;
}

void Coordinate::getCartesian(float *x, float *y, float *z)
{
	*x = this->x;
	*y = this->y;
	*z = this->z;
}

void Coordinate::setCartesian(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void Coordinate::add(Coordinate c)
{
	this->x = this->x + c.x;
	this->y = this->y + c.y;
	this->z = this->z + c.z;
}

void Coordinate::print(coordinate style)
{
	float r {}, phi {}, theta {}, h;
	switch(style)
	{
	case CARTESIAN:
		cout 	<< "Cartesian representation "
				<< "(x, y, z) = "
				<< "(" << this->x << ", " << this->y << ", " << this->z << ")"
				<< endl;
	break;

	case POLAR:
		this->getPolar(&r, &phi, &theta);
		cout 	<< "Polar representation "
				<< "(r, phi, theta) = "
				<< "(" << r << ", " << phi << ", " << theta << ")"
				<< endl;
	break;

	case CYLINDER:
		this->getCylinder(&r, &phi, &h);
		cout 	<< "Polar representation "
				<< "(r, phi, h) = "
				<< "(" << r << ", " << phi << ", " << h << ")"
				<< endl;
	break;

	default:
	break;
	}

}
