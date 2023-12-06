/*
 * ReversiConsoleView.cpp
 *
 *  Created on: 27 Oct 2023
 *      Author: FELIX
 */

#include <iostream>

#include "ReversiConsoleView.h"

using namespace std;

ReversiConsoleView::ReversiConsoleView(ReversiBoard *board)
{
	this->board = board;
}

void ReversiConsoleView::print()
{
	cout << "r/c";
	for (int col = 0; col < BOARD_SIZE; col++)
		cout << col << " ";
	cout << endl;
	for (int row = 0; row < BOARD_SIZE; row++)
	{
		cout << row << " ";
		for (int col = 0; col < BOARD_SIZE; col++)
		{
			switch (board->getFieldState({row, col}))
			{
			case BLACK:
				cout << "|#";
			break;

			case WHITE:
				cout << "|o";
			break;

			case NONE:
				cout << "|.";
			break;
			}
		}
		cout << '|' << endl;
	}
	cout << endl;
}
