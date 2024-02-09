/*
 * OwnGrid.h
 *
 *  Created on: 26 Dec 2023
 *      Author: FELIX WORKSTATION
 */

#ifndef OWNGRID_H_
#define OWNGRID_H_

#include <vector>
#include <map>

#include "Ship.h"
#include "Shot.h"

class OwnGrid
{
private:
	int rows; /** Number of rows in the OwnGrid object. */

	int columns; /** Number of columns in the OwnGrid object. */

	std::vector<Ship> ships; /** vector of Ship objects on the grid. */

	/**
	 * map table consisting of different Ship lengths and possible number of
	 * each Ship that can be placed on the grid. */
	std::map<int, int> shipsTable;

	/** set of GridPosition objects on the grid. */
	std::set<GridPosition> shotAt;
public:
	/**
	 * Constructor for OwnGrid object.
	 * @param [in] rows Number of rows on the OwnGrid.
	 * @param [in] columns Number of columns on the OwnGrid.
	 */
	OwnGrid(int rows, int columns);

	/**
	 * Returns the number of rows on the OwnGrid.
	 * @return Integer number of the rows.
	 */
	int getRows();

	/**
	 * Returns the number of columns on the OwnGrid.
	 * @return Integer number of the columns.
	 */
	int getColumns();

	/**
	 * Adds a ship to OwnGrid
	 * @param [in] ship Ship object to be added to OwnGrid.
	 * @return Return true if ship can be placed on the grid following the
	 * game rules.
	 */
	bool placeShip(const Ship &&ship);

	/**
	 * Returns a vector containing all the Ship objects currently on the grid.
	 * @return Vector object containing records of all Ship object placed on
	 * OwnGrid using OwnGrid::placeShip.
	 */
	const std::vector<Ship> getShips();

	/**
	 * Returns a set of GridPosition that represents all grid positions
	 * occupied by a Ship and its surrounding grid positions.
	 */
	std::set<GridPosition> getBlockedAreas();

	/**
	 * Receives a shot on OwnGrid
	 * @param [in] shot Reference to Shot object.
	 * @return An Shot::Impact member indicating the result of the shot.
	 */
	Shot::Impact takeBlow(const Shot& shot);

	/**
	 * Returns list of shots on grid.
	 * @return Set of Shot objects.
	 */
	const std::set<GridPosition> getShotAt();
};

#endif /* OWNGRID_H_ */
