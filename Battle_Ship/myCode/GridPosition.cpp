/*
 * GridPosition.cpp
 *
 *  Created on: 22 Dec 2023
 *      Author: FELIX WORKSTATION
 */

#include "GridPosition.h"

using namespace std;

GridPosition::GridPosition(char row, int column): row{row}, column{column}
{
}

GridPosition::GridPosition(std::string position)
{
	//row = char(*position.substr(0, 1).data());
	row = position[0];
	column = stoi(position.substr(1));
}

bool GridPosition::isValid() const
{
	if (row >= 'A' && row <= 'Z' && column > 0)
		return true;
	return false;
}

char GridPosition::getRow() const
{
	return row;
}

int GridPosition::getColumn() const
{
	return column;
}

GridPosition::operator std::string() const
{
	return row + to_string(column);
}

bool GridPosition::operator ==(const GridPosition other) const
{
	if (row == other.row && column == other.column)
		return true;

	return false;
}

bool GridPosition::operator<(const GridPosition other) const
{
	//if (*this == other)
		//return false;

	if (row < other.row)
		return true;
	else if (row > other.row)
		return false;
	else if (column < other.column)
		return true;
	return false;
}
