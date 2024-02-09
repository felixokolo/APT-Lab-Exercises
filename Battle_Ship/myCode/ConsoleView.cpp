/*
 * ConsoleView.cpp
 *
 *  Created on: 26 Dec 2023
 *      Author: FELIX WORKSTATION
 */
#include <iostream>

#include "ConsoleView.h"

using namespace std;

ConsoleView::ConsoleView(Board *board): board{board}
{
	rows = board->getRows();
	columns = board->getColumns();

	// Initialize vector ownGrid and opponentGrids arrays with NO_SHIP_CHAR
	for (int i = 0; i < rows; i++)
	{
		ownGrid.push_back({});
		opponentGrid.push_back({});
		for (int j = 0; j < columns; j++)
		{
			ownGrid[i].push_back(NO_SHIP_CHAR);
			opponentGrid[i].push_back(NO_SHIP_CHAR);
		}

	}

}

void ConsoleView::print()
{
	clearAll();
	update();
	cout << "Own Grid" << endl;

	cout << ' ';
	for (int j = 0; j < SEPARATOR_NUM; j++)
		cout << SEPARATOR;
	for (int i = 1; i <= columns; i++)
	{
		cout << i;
		for (int j = 0; j < ((i > 9)? SEPARATOR_NUM - 1 : SEPARATOR_NUM); j++)
			cout << SEPARATOR;
	}


	cout << endl;

	for (int i = 0; i < rows; i++)
	{
		cout << (char) (FIRST_ROW + i);
		for (int j = 0; j < SEPARATOR_NUM; j++)
			cout << SEPARATOR;
		for (vector<char>::iterator itr = ownGrid[i].begin();

			 itr != ownGrid[i].end(); itr++)
		{
			cout << *itr;
			for (int j = 0; j < SEPARATOR_NUM; j++)
				cout << SEPARATOR;
		}
		cout << endl;
	}

	cout << endl;

	cout << "Opponent Grid" << endl;

	cout << ' ';
	for (int j = 0; j < SEPARATOR_NUM; j++)
		cout << SEPARATOR;
	for (int i = 1; i <= columns; i++)
	{
		cout << i;
		for (int j = 0; j < ((i > 9)? SEPARATOR_NUM - 1 : SEPARATOR_NUM); j++)
			cout << SEPARATOR;
	}


	cout << endl;

	for (int i = 0; i < rows; i++)
	{
		cout << (char) (FIRST_ROW + i);
		for (int j = 0; j < SEPARATOR_NUM; j++)
			cout << SEPARATOR;
		for (vector<char>::iterator itr = opponentGrid[i].begin();

			 itr != opponentGrid[i].end(); itr++)
		{
			cout << *itr;
			for (int j = 0; j < SEPARATOR_NUM; j++)
				cout << SEPARATOR;
		}
		cout << endl;
	}
	cout << endl;
}

void ConsoleView::setGrid(GridType gridType, char fill,
						  char row, int column)
{
	switch (gridType)
	{
	case OWN_GRID:
		ownGrid[row - FIRST_ROW][column-1] = fill;
		break;

	case OPPONENT_GRID:
		opponentGrid[row - FIRST_ROW][column-1] = fill;
		break;
	}
}


void ConsoleView::clearAll()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			ownGrid[i][j] = NO_SHIP_CHAR;
			opponentGrid[i][j] = NO_SHIP_CHAR;
		}

	}
}

void ConsoleView::update()
{
	// Add ships to initialized vector grids
	vector<Ship> sps = board->getOwnGrid().getShips();
	set<GridPosition> shots = board->getOwnGrid().getShotAt();

	for (GridPosition shot : shots)
		if (board->getOwnGrid().takeBlow(shot) == Shot::NONE)
			setGrid(OWN_GRID, SHOT_MISS,
					shot.getRow(), shot.getColumn());

	for (vector<Ship>::iterator itr = sps.begin(); itr != sps.end(); itr++)
	{
		set<GridPosition> gps = itr->occupiedArea();
		for (GridPosition itr2 : gps)
		{
			shots.find(itr2) == shots.end()?
					setGrid(OWN_GRID, SHIP_CHAR,
							itr2.getRow(), itr2.getColumn()):
					setGrid(OWN_GRID, SHOT_HIT,
							itr2.getRow(), itr2.getColumn());
		}

	}


	sps = board->getOpponentGrid().getSunkenShips();

	map<GridPosition, Shot::Impact> shotsAt =
			board->getOpponentGrid().getShotsAt();

	for (pair<GridPosition, Shot::Impact> shotAt : shotsAt)
		if (shotAt.second == Shot::NONE)
			setGrid(OPPONENT_GRID, SHOT_MISS,
					shotAt.first.getRow(), shotAt.first.getColumn());
		else if (shotAt.second == Shot::HIT || shotAt.second == Shot::SUNKEN)
			setGrid(OPPONENT_GRID, SHOT_HIT,
					shotAt.first.getRow(), shotAt.first.getColumn());


	for (vector<Ship>::iterator itr = sps.begin(); itr != sps.end(); itr++)
	{
		set<GridPosition> gps = itr->occupiedArea();
		for (GridPosition itr2 : gps)
		{
			setGrid(OPPONENT_GRID, SHIP_CHAR,
					itr2.getRow(), itr2.getColumn());
		}

	}


}
