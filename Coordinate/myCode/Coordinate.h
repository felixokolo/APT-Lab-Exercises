/*
 * CCoordinate.h
 *
 *  Created on: 18 Oct 2023
 *      Author: FELIX WORKSTATION
 */

#ifndef COORDINATE_H_
#define COORDINATE_H_

class Coordinate
{

private:
	float x; /**< X-axis position on the Cartesian coordinate. */
	float y; /**< Y-axis position on the Cartesian coordinate. */
	float z; /**< Z-axis position on the Cartesian coordinate. */

public:
	/**
	 * Constructor method for initializing data members in the Cartesian coordinate
	 *
	 * @param [in] x Float value describing the x-axis position on the Cartesian coordinate. Default (0) if the line gets longer than 80 columns what happens to m
	 * @param [in] z Float value describing the z-axis position on the Cartesian coordinate. Default (0)
	 */
	Coordinate(float x = 0, float y = 0, float z = 0);
	virtual ~Coordinate();
};

#endif /* COORDINATE_H_ */
