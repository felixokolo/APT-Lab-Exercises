/*
 * CCoordinate.h
 *
 *  Created on: 18 Oct 2023
 *      Author: FELIX WORKSTATION
 */

#ifndef COORDINATE_H_
#define COORDINATE_H_

 /*
  * Enum type representing various styles of the coordinate system
  */
enum coordinate {
				 CARTESIAN, /**< Represents the cartesian coordinate system.*/
				 CYLINDER, /**< Represents the cylinder coordinate system.*/
				 POLAR /**< Represents the polar coordinate system.*/
				};


class Coordinate
{

private:
	/* Private instance variables.*/
	float x; /**< X-axis position on the Cartesian coordinate. */
	float y; /**< Y-axis position on the Cartesian coordinate. */
	float z; /**< Z-axis position on the Cartesian coordinate. */

	/*Private instance methods declarations.*/

	/*
	 * Retrieves the values of respective points of the polar coordinate
	 * system. The method calculates the values of the respective points
	 * and stores it in the appropriate location.
	 *
	 * @param [in, out] r for the radius
	 * @param [in, out] phi for the angle with respect to the XY-plane
	 * @param [in, out] theta for angle with respect to the z-axis
	 */
	void getPolar(float *r, float *phi, float *theta);

	/*
	 * Retrieves the values of respective points of the cylinder coordinate
	 * system. The method calculates the values of the respective points
	 * and stores it in the appropriate location.
	 *
	 * @param [in, out] for the radius
	 * @param [in, out] phi for the angle with respect to the XY-plane
	 * @param [in, out] h for the height on the z-axis
	 */
	void getCylinder(float *r, float *phi, float *h);

public:
	/**
	 * Constructor method for initializing data members in
	 * the Cartesian coordinate
	 *
	 * @param [in] x Float value describing the x-axis position on
	 * the Cartesian coordinate. Default (0).
	 *
	 * @param [in] z Float value describing the z-axis position on
	 * the Cartesian coordinate. Default (0)
	 */
	Coordinate(float x = 0, float y = 0, float z = 0);

	/*
	 * Instance deconstructor method
	 */
	virtual ~Coordinate();

	/*
	 * Retrieves the values of respective points of the cartesian coordinate
	 * system. The method retrieves the current values of the respective points
	 * and stores it in the appropriate location.
	 *
	 * @param [in, out] x for point on the X-axis
	 * @param [in, out] y for point on the Y-axis
	 * @param [in, out] z for point on the X-axis
	 */
	void getCartesian(float *x, float *y, float *z);
	/* Passing references to the above function results in a compilation error*/

	/*
	 * Sets the val;ues of respective points of the cartesian coordinate
	 * system. The method replaces the current values of the respective points
	 * with the respective given values.
	 *
	 * @param [in] x for point on the X-axis
	 * @param [in] y for point on the Y-axis
	 * @param [in] z for point on the X-axis
	 */
	void setCartesian(float x, float y, float z);
	/* Passing non-reference values to the above function results in a
	 * compilation error*/

	/*
	 * Method for adding a coordinate point to the points of the instance point
	 *
	 * @param [in] c Coordinate instance to be added
	 */
	void add(Coordinate c);

	/*
	 * Prints the points of a coordinate in a specified style
	 *
	 * @param [in] style Coordinate printing style to be utilized
	 */
	void print(coordinate style);
};

#endif /* COORDINATE_H_ */
