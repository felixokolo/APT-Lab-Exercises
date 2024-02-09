/*
 * OpponentGrid.h
 *
 *  Created on: 26 Dec 2023
 *      Author: FELIX WORKSTATION
 */

#ifndef OPPONENTGRID_H_
#define OPPONENTGRID_H_

#include <iostream>
#include <vector>
#include <map>

#include "Ship.h"
#include "Shot.h"

class OpponentGrid
{
private:
	/**
	 * Number of rows in the OpponentGrid.
	 */
	int rows;

	/**
	 * Number of columns in the OpponentGrid.
	 */
	int columns;

	/**
	 * Vector object holding the record of all the sunken Ship objects of the
	 * opponent.
	 */
	std::vector<Ship> sunkenShips;

	/**
	 * Map object that holds record of the Shot objects made on the opponent's
	 * OwnGrid object.
	 */
	std::map<GridPosition, Shot::Impact> shots;
public:

	/**
	 * Constructor for OpponentGrid object.
	 * @param [in] rows Specifies the number of rows of the
	 * OpponentGrid object.
	 * @param [in] columns Specifies the number of columns of the
	 * OpponentGrid object.
	 */
	OpponentGrid(int rows, int columns);

	/**
	 * Returns the number of rows in the board.
	 * @return Number of rows n.
	 */
	int getRows();

	/**
	 * Returns the number of columns in the board.
	 * @return Number of columns n.
	 */
	int getColumns();

	/**
	 * Returns all sunken Ships in the OpponentGrid.
	 * @return Vector object containing all sunken Ship objects on
	 * OpponentGrid.
	 */
	std::vector<Ship> getSunkenShips();

	/**
	 * Adds a Shot record and the resulting Shot::Impact made on the
	 * OpponentGrid and finds the Ship::bow and Ship::stern of a sunken Ship
	 * if the resulting Shot::Impact is Shot::SUNKEN.
	 *
	 * @param [in] shot Shot object indicating the target GridPosition on the
	 * OpponentGrid.
	 *
	 * @param [in] impact Shot::Impact indicating the result of the shot.
	 */
	void shotResult(const Shot &&shot, Shot::Impact impact);

	/**
	 * Returns the records of shots made on the OpponentGrid
	 * @return map object with Shot::Impact values for all shots made on
	 * several GridPosition on the OpponentGrid.
	 */
	const std::map<GridPosition, Shot::Impact> &getShotsAt();
};

#endif /* OPPONENTGRID_H_ */
