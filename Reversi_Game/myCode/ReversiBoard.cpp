/*
 * ReversiBoard.cpp
 *
 *  Created on: 26 Oct 2023
 *      Author: FELIX
 */

#include <iostream>

#include "ReversiBoard.h"

using namespace std;

int ReversiBoard::getFlipFields(field refField, field *fields)
{
	if (refField.fieldState == NONE)
		return 0;

	field curField = refField;
	state toFind = refField.fieldState == BLACK? WHITE : BLACK;
	coordinate nextCord = {-1, -1}; // Holds the next cordinate to inspect
	int lastSuccess = 0; // Stores the index of the last successful search
	int tmpSuccess = 0; // Stores the temp index of the last successful search

	// Transverse through different directions
	for (int dir = LEFT; dir <= DOWN_RIGHT; dir++)
	{
		curField = refField;
		tmpSuccess = 0;
		while (true)
		{
			nextCord = getNextCoordinate(curField.fieldLoc, (direction) dir) ;
			if (nextCord.row == -1)
				break;
			if (getFieldState(nextCord) == toFind)
			{
				//Field containing the new state
				curField = {refField.fieldState, nextCord};
				//Added to list of fields to be updated
				fields[lastSuccess + tmpSuccess] = curField;
				tmpSuccess++;
			}
			else if (getFieldState(nextCord) == refField.fieldState)
			{
				lastSuccess += tmpSuccess;
				break;
			}
			else if (getFieldState(nextCord) == NONE)
			{
				break;
			}

		}
	}
	return lastSuccess;
}

ReversiBoard::ReversiBoard()
{
	/* Initialize all fields to NONE. */
	for (int row = 0; row < BOARD_SIZE ; row++)
	{
		for (int col = 0; col < BOARD_SIZE; col++)
		{
			this->board[row][col].fieldState = NONE;
			this->board[row][col].fieldLoc = {row, col};
		}
	}
	//Set discs on 2 diagonal fields for each player at center of the Board
	this->board[3][3] = {BLACK, {3, 3}};
	this->board[4][4] = {BLACK, {4, 4}};
	this->board[3][4] = {WHITE, {3, 4}};
	this->board[4][3] = {WHITE, {4, 3}};
}


state ReversiBoard::getFieldState(coordinate cord)
{
	if  ((cord.row < 0 || cord.row >= BOARD_SIZE) ||
		 (cord.col < 0 || cord.col >= BOARD_SIZE))
		return NONE; // Invalid location returns NONE
	return board[cord.row][cord.col].fieldState;
}

ReversiBoard::coordinate ReversiBoard::getNextCoordinate(coordinate refCord,
	direction dir)
{

	switch (dir)
	{
	case LEFT:
		if (refCord.col - 1 < 0)
			return {-1, -1};

		return {refCord.row, refCord.col - 1};
	break;

	case RIGHT:
		if (refCord.col + 1 >= BOARD_SIZE)
			return {-1, -1};

		return {refCord.row, refCord.col + 1};
	break;

	case UP:
		if (refCord.row - 1 < 0)
			return {-1, -1};

		return {refCord.row - 1, refCord.col};
	break;

	case DOWN:
		if (refCord.row + 1 >= BOARD_SIZE)
			return {-1, -1};

		return {refCord.row + 1, refCord.col};
	break;

	case UP_LEFT:
		if (refCord.row - 1 < 0 || refCord.col - 1 < 0)
			return {-1, -1};

		return {refCord.row - 1, refCord.col - 1};
	break;

	case UP_RIGHT:
		if (refCord.row - 1 < 0 || refCord.col + 1 >= BOARD_SIZE)
			return {-1, -1};

		return {refCord.row - 1, refCord.col + 1};
	break;

	case DOWN_LEFT:
		if (refCord.row + 1 >= BOARD_SIZE || refCord.col - 1 < 0)
			return {-1, -1};

		return {refCord.row + 1, refCord.col - 1};
	break;

	case DOWN_RIGHT:
		if (refCord.row + 1 >= BOARD_SIZE || refCord.col + 1 >= BOARD_SIZE)
			return {-1, -1};

		return {refCord.row + 1, refCord.col + 1};
	break;

	default:
		return {-1, -1};
	break;
	}
}

void ReversiBoard::flipFields(field *fields, int n)
{
	int row = 0, col = 0;
	for (int i = 0; i < n; i++)
	{
		row = fields[i].fieldLoc.row;
		col = fields[i].fieldLoc.col;
		board[row][col].fieldState = fields[i].fieldState;
	}
}

int ReversiBoard::setFieldState(state s, coordinate c)
{
	field tmp = {s, c}; //create a temporary field
	field toFlip[MAX_FLIPS];
	for (int i = 0; i < MAX_FLIPS; i++)
		// initialize all fields to NONE and coordinate to (-1, -1)
		toFlip[i] = {NONE, {-1, -1}};
	int flips = getFlipFields(tmp, toFlip);
	if (flips == 0)
	{
		cout << "Invalid Move" << endl;
		return 0;
	}
	board[c.row][c.col] = {s, c};
	flipFields(toFlip, flips);
	return 1;
}
