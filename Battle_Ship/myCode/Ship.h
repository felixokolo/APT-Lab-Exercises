/*
 * Ship.h
 *
 *  Created on: 23 Dec 2023
 *      Author: FELIX WORKSTATION
 */

#ifndef SHIP_H_
#define SHIP_H_

#include <set>
#include "GridPosition.h"

class Ship
{
private:
	/**
	 * GridPosition that specifies the start (bow) position of the Ship object.
	 */
	GridPosition bow;

	/**
	 * GridPosition that specifies the end (stern) position of the Ship object.
	 */
	GridPosition stern;

public:
	/**
	 * Default constructor for Ship object.
	 * @param [in] bow Represents the start position of the Ship object.
	 * @param [in] stern Represents the end position of the Ship object.
	 */
	Ship(GridPosition const &bow, GridPosition const &stern);

	/**
	 * Checks the validity of the GridPositions of the bow and stern, whether
	 * the ship is positioned horizontally or vertically and if the length
	 * is between 2 and 5.
	 * @return True if all the above conditions are met.
	 */
	bool isValid() const;

	/**
	 * Returns the GridPosition of the bow.
	 * @return GridPosition representing the position of the ship's bow.
	 */
	GridPosition getBow() const;

	/**
	 * Returns the GridPosition of the stern.
	 * @return GridPosition representing the position of the ship's stern.
	 */
	GridPosition getStern() const;

	/**
	 * Calculates the length of the ship using the bow and stern GridPosition.
	 * @return Integer representing the horizontal or vertical length.
	 */
	int length() const;

	/**
	 * Gets the set of GridPosition occupied by the ship.
	 * @return Set containing GridPosition objects
	 */
	const std::set<GridPosition> occupiedArea() const;

	/**
	 * Implemented later
	 */
	const std::set<GridPosition> blockedArea() const;
};

#endif /* SHIP_H_ */
