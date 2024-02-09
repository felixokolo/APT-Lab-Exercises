/*
 * OpponentGrid.cpp
 *
 *  Created on: 26 Dec 2023
 *      Author: FELIX WORKSTATION
 */

#include "OpponentGrid.h"
#include "Ship.h"

using namespace std;

OpponentGrid::OpponentGrid(int rows, int columns):
	rows(rows), columns(columns),
	sunkenShips()
{
}

int OpponentGrid::getRows()
{
	return rows;
}

int OpponentGrid::getColumns()
{
	return columns;
}

std::vector<Ship> OpponentGrid::getSunkenShips()
{
	return sunkenShips;
}

void OpponentGrid::shotResult(const Shot &&shot, Shot::Impact impact)
{
	shots[shot.getTargetPosition()] = impact;
	if (impact == Shot::SUNKEN)
	{
		set<GridPosition> hits; // Store all hits grid positions

		// insert the sinking grid position
		hits.insert(shot.getTargetPosition());
		for (pair<GridPosition, Shot::Impact> itr : shots)
		{
			// Get all grid positions on map with HIT
			if (itr.second == Shot::HIT) hits.insert(itr.first);
		}

		char shipKind = 'C'; // Sunken is on a Row R or Column C
		char sinkRow = shot.getTargetPosition().getRow();
		int sinkCol = shot.getTargetPosition().getColumn();
		GridPosition bow('@', 0);
		GridPosition stern('@', 0);

		/**
		 * If there is a hit on the left or the right grid next to the
		 * sinking grid, then sinking ship is on the row.
		 */
		if (hits.find(GridPosition(sinkRow - 1, sinkCol)) == hits.end() &&
			hits.find(GridPosition(sinkRow + 1, sinkCol)) == hits.end())
			shipKind = 'R';

		if (shipKind == 'C')
		{
			char currentRow = sinkRow;
			/**
			 * Go through the hits beginning from the sinking grid position
			 * till the end of hits finding the adjacent positions on the
			 * sinking grid column
			 */
			for (set<GridPosition>::iterator itr =
					hits.find(shot.getTargetPosition());
					itr != hits.end(); itr ++)
			{
				if (itr->getColumn() == sinkCol &&
					itr->getRow() == currentRow + 1)
					currentRow = itr->getRow();
			}
			stern = GridPosition(currentRow, sinkCol);

			currentRow = sinkRow;
			set<GridPosition>::iterator itr;

			for (itr = hits.find(shot.getTargetPosition());
					itr != hits.begin(); itr --)
			{
				if (itr->getColumn() == sinkCol &&
					itr->getRow() == currentRow - 1)
					currentRow = itr->getRow();
			}
			if (itr->getColumn() == sinkCol &&
				itr->getRow() == currentRow - 1)
				currentRow = itr->getRow();

			bow = GridPosition(currentRow, sinkCol);
		}

		if (shipKind == 'R')
		{
			int currentCol = sinkCol;
			for (set<GridPosition>::iterator itr =
					hits.find(shot.getTargetPosition());
					itr != hits.end(); itr ++)
			{
				if (itr->getRow() == sinkRow &&
					itr->getColumn() == currentCol + 1)
					currentCol = itr->getColumn();
			}
			stern = GridPosition(sinkRow, currentCol);

			currentCol = sinkCol;
			set<GridPosition>::iterator itr;

			for (itr = hits.find(shot.getTargetPosition());
				 itr != hits.begin(); itr --)
			{
				if (itr->getRow() == sinkRow &&
					itr->getColumn() == currentCol - 1)
					currentCol = itr->getColumn();
			}
			if (itr->getRow() == sinkRow &&
				itr->getColumn() == currentCol - 1)
				currentCol = itr->getColumn();
			bow = GridPosition(sinkRow, currentCol);
		}
		sunkenShips.push_back(Ship({(string) bow}, {(string) stern}));
	}
}

const std::map<GridPosition, Shot::Impact>& OpponentGrid::getShotsAt()
{
	return shots;
}
