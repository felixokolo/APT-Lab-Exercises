/*
 * Board.h
 *
 *  Created on: 23 Dec 2023
 *      Author: FELIX WORKSTATION
 */

#ifndef BOARD_H_
#define BOARD_H_

#include "OwnGrid.h"
#include "OpponentGrid.h"
#include "Ship.h"

class Board
{
private:
	/**
	 * OwnGrid object that holds the record of Ship objects and Shot objects.
	 */
	OwnGrid ownGrid;

	/**
	 * OpponentGrid object that holds the record of Ship objects and
	 * Shot objects.
	 */
	OpponentGrid opponentGrid;
public:
	/**
	 * Default constructor for Board object. Called to create the board of the
	 * game.
	 * @param [in] rows Represents the number rows of the game board.
	 * @param [in] columns Represents the number columns of the game board.
	 */
	Board(int rows, int columns);

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
	 * Returns the OwnGrid data member in Board.
	 * @return A reference to Board::ownGrid.
	 */
	OwnGrid& getOwnGrid();

	/**
	 * Returns the OpponentGrid data member in Board.
	 * @return A reference to Board::opponentGrid.
	 */
	OpponentGrid& getOpponentGrid();
};

#endif /* BOARD_H_ */
