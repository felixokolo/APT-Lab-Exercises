/*
 * Shot.h
 *
 *  Created on: 31 Dec 2023
 *      Author: FELIX WORKSTATION
 */

#ifndef SHOT_H_
#define SHOT_H_

#include "GridPosition.h"

class Shot
{
public:
	/**
	 * Enum of possible shot results.
	 */
	enum Impact {
		NONE, 	/** Shot hit an empty GridPosition. */
		HIT, 	/** Shot hit a GridPosition occupied by a Ship. */
		SUNKEN	/** Shot hit the last GridPosition occupied by a Ship. */
	};
private:
	/**
	 * Specifies the position where the shot is made.
	 */
	GridPosition targetPosition;
public:
	/**
	 * Constructor for shot object
	 * @param [in] targetPosition GridPosition object that specifies the grid
	 * to be shot.
	 */
	Shot(GridPosition targetPosition);

	/**
	 * Returns a GridPosition object that represents grid of shot.
	 * @return GridPosition object.
	 */
	GridPosition getTargetPosition() const;

};

#endif /* SHOT_H_ */
