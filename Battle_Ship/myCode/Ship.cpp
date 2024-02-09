/*
 * Ship.cpp
 *
 *  Created on: 23 Dec 2023
 *      Author: FELIX WORKSTATION
 */

#include <iostream>

#include "Ship.h"

using namespace std;

Ship::Ship(const GridPosition &bow, const GridPosition &stern):
		bow(bow), stern(stern)
{
}

bool Ship::isValid() const
{
	if (!((bow.getRow() == stern.getRow()) !=
		(bow.getColumn() == stern.getColumn())))
		return false;

	int len = length();
	if (!(len >= 2 && len <= 5))
		return false;

	if (!bow.isValid() || !stern.isValid())
		return false;

	return true;
}

GridPosition Ship::getBow() const
{
	return bow;
}

GridPosition Ship::getStern() const
{
	return stern;
}

int Ship::length() const
{
	int len = 0;
	if (bow.getRow() == stern.getRow())
		len = abs(bow.getColumn() - stern.getColumn()) + 1;
	else if (bow.getColumn() == stern.getColumn())
		len = (int) (abs(bow.getRow() - stern.getRow()) + 1);
	return len;
}

const set<GridPosition> Ship::occupiedArea() const
{
	set<GridPosition> tmp = {};
	int len = length();
	// Check if bow is before or after the stern.
	int dir = stern < bow? -1 : 1;

	for (int i = 0; abs(i) < len; i += dir)
		bow.getColumn() == stern.getColumn()?
		tmp.insert(GridPosition(bow.getRow() + i, bow.getColumn())) :
		tmp.insert(GridPosition(bow.getRow(), bow.getColumn() + i));

	return tmp;
}

const set<GridPosition> Ship::blockedArea() const
{
	set<GridPosition> tmp = {};
	set<GridPosition> occupiedGrids = occupiedArea();

	for (set<GridPosition>::iterator itr = occupiedGrids.begin();
			itr != occupiedGrids.end(); itr++)
	{
		char row = itr->getRow();
		int col = itr->getColumn();

		for (char row_itr = row - 1; row_itr <= row + 1; row_itr++)
			for (int col_itr = col - 1; col_itr <= col + 1; col_itr++)
			{
				if (GridPosition(row_itr, col_itr).isValid())
					tmp.insert(GridPosition(row_itr, col_itr));
			}

	}
	return tmp;
}
