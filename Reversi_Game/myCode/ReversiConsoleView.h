/*
 * ReversiConsoleView.h
 *
 *  Created on: 27 Oct 2023
 *      Author: FELIX
 */

#ifndef REVERSICONSOLEVIEW_H_
#define REVERSICONSOLEVIEW_H_

#include "ReversiBoard.h"

/**
 * @class ReversiConsoleView
 * @brief This class implements the display functionality for a ReversiBoard
 * instance. It prints the ReversiBoard to a console.
 */
class ReversiConsoleView
{
private:
	ReversiBoard *board;
	/**< Saves the pointer to a referenced ReversiBoard. */

public:
	/**
	 * Constructor of a viewing console for the Reversi Board game
	 * @param [in] board Pointer to a ReversiBoard object
	 */
	ReversiConsoleView(ReversiBoard *board);

	/**
	 * Prints the ReversiBoard object on console
	 */
	void print();
};

#endif /* REVERSICONSOLEVIEW_H_ */
