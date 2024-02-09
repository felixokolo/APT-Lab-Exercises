/*
 * ConsoleView.h
 *
 *  Created on: 26 Dec 2023
 *      Author: FELIX WORKSTATION
 */

#ifndef CONSOLEVIEW_H_
#define CONSOLEVIEW_H_

#define SHIP_CHAR '#'
#define NO_SHIP_CHAR '~'
#define SHOT_MISS '^'
#define SHOT_HIT 'O'
#define FIRST_ROW 'A'
#define SEPARATOR " "
#define SEPARATOR_NUM 2

#include "Board.h"

enum GridType {
	OWN_GRID,
	OPPONENT_GRID,
};

class ConsoleView
{
private:
	/**
	 * Reference to Board object to be printed.
	 */
	Board *board;
	/**
	 * Char vector representation of Board::ownGrid.
	 */
	std::vector<std::vector<char>> ownGrid;

	/**
	 * Char vector representation of Board::opponentGrid.
	 */
	std::vector<std::vector<char>> opponentGrid;

	/**
	 * Number of rows in board.
	 */
	int rows;

	/**
	 * Number of columns in board.
	 */
	int columns;

public:
	/**
	 * Default constructor for Board ConsoleView object.
	 * @param [in] board Board to be printed on console.
	 */
	ConsoleView(Board *board);

	/**
	 * Prints the board which includes OwnGrid and OpponentGrid on the console.
	 */
	void print();

	/**
	 * Sets occupied grid with fill
	 * @param [in] gridType Specifies the grid type to be set.
	 * @param [in] fill Specifies the character to be used for filling
	 * the position.
	 * @param [in] row Specifies the row to be set.
	 * @param [in] column Specifies the column to be set.
	 */
	void setGrid(GridType gridType, char fill,
				 char row, int column);

	/**
	 * Clears all the grids with NO_SHIP_CHAR
	 */
	void clearAll();

	/**
	 * Updates vector boards with current state of ships
	 */
	void update();

};

#endif /* CONSOLEVIEW_H_ */
