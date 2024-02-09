/*
 * Board.cpp
 *
 *  Created on: 23 Dec 2023
 *      Author: FELIX WORKSTATION
 */

#include "Board.h"

Board::Board(int rows, int columns):
	ownGrid(rows, columns),
	opponentGrid(rows, columns)
{
}

int Board::getRows()
{
	return ownGrid.getRows();
}

int Board::getColumns()
{
	return ownGrid.getColumns();
}

OwnGrid& Board::getOwnGrid()
{
	return ownGrid;
}

OpponentGrid& Board::getOpponentGrid()
{
	return opponentGrid;
}
