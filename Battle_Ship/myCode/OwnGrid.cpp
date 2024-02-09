/*
 * OwnGrid.cpp
 *
 *  Created on: 26 Dec 2023
 *      Author: FELIX WORKSTATION
 */
#include <algorithm>
#include <iostream>

#include "OwnGrid.h"

using namespace std;

OwnGrid::OwnGrid(int rows, int columns): rows(rows), columns(columns), ships(),
		shipsTable{{5, 1}, {4, 2}, {3, 3}, {2, 4}}
{
}

int OwnGrid::getRows()
{
	return rows;
}

int OwnGrid::getColumns()
{
	return columns;
}

bool OwnGrid::placeShip(const Ship &&ship)
{
	// Check if ship is valid
	if (!ship.isValid())
		return false;

	//Check if ship is beyond the bonds of ownGrid
	if (ship.getBow().getRow() >= 'A' + rows ||
		ship.getBow().getColumn() > columns)
		return false;

	if (ship.getStern().getRow() >= 'A' + rows ||
		ship.getStern().getColumn() > columns)
		return false;

	set<GridPosition> blocked = getBlockedAreas();
	set<GridPosition> occupied = ship.occupiedArea();
	set<GridPosition> intersect;
	set_intersection(blocked.begin(), blocked.end(),
					 occupied.begin(), occupied.end(),
					 inserter(intersect, intersect.begin()));
	// Check if ship touches another
	if (!intersect.empty())
		return false;

	if (shipsTable[ship.length()] == 0)
		return false;

	ships.push_back(ship);
	shipsTable[ship.length()] -= 1;

	return true;
}

const vector<Ship> OwnGrid::getShips()
{
	return ships;
}

std::set<GridPosition> OwnGrid::getBlockedAreas()
{
	set<GridPosition> tmp{};
	for (vector<Ship>::iterator itr = ships.begin(); itr != ships.end(); itr++)
	{
		set<GridPosition> gps = itr->blockedArea();
		for (set<GridPosition>::iterator itr2 = gps.begin();
			 itr2 != gps.end(); itr2++)
			tmp.insert(GridPosition(itr2->getRow(), itr2->getColumn()));
	}
	return tmp;
}

Shot::Impact OwnGrid::takeBlow(const Shot &shot)
{
	Shot::Impact tmp = Shot::NONE;

	for (Ship ship : ships)
	{
		set<GridPosition> occupied = ship.occupiedArea();
		set<GridPosition>::iterator itr =
				occupied.find(shot.getTargetPosition());
		if (itr == occupied.end())
			continue;

		set<GridPosition> intersect;
		set_intersection(occupied.begin(), occupied.end(),
						 shotAt.begin(), shotAt.end(),
						 inserter(intersect, intersect.begin()));
		if (intersect.size() == 0)
			tmp = Shot::HIT;
		else
			tmp = (ship.length() - intersect.size()) == 1? Shot::SUNKEN :
					Shot::HIT;

		shotAt.insert(shot.getTargetPosition());
		return tmp;
	}
	shotAt.insert(shot.getTargetPosition());
	return tmp;
}

const std::set<GridPosition> OwnGrid::getShotAt()
{
	return shotAt;
}
