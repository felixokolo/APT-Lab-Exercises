/*
 * GridPosition.h
 *
 *  Created on: 22 Dec 2023
 *      Author: FELIX
 */

#ifndef GRIDPOSITION_H_
#define GRIDPOSITION_H_

#include <string>

class GridPosition
{
private:
	/**
	 * Row of GridPosition
	 */
	char row;

	/**
	 * Column of GridPosition
	 */
	int column;


public:
	/**
	 * Default constructor for GridPosition object.
	 * @param [in] row Represents the row of the grid. Ranges from A-Z.
	 * @param [in] column Represents the column of the grid. column >= 1.
	 */
	GridPosition(char row, int column);

	/**
	 * Constructor for GridPosition object using string.
	 * @param [in] position String object containing the grid details in the
	 * form "A0" where A is the row and 0 is the column.
	 */
	GridPosition(std::string position);

	/**
	 * Method that checks for the validity of the grid row and column values.
	 * @return True if row is between A-Z and column is >= 0.
	 */
	bool isValid() const;

	/**
	 * Method that gets the value of the row.
	 * @return Char representing the value of the row.
	 */
	char getRow() const;

	/**
	 * Method that gets the value of the column.
	 * @return Char representing the value of the row.
	 */
	int getColumn() const;

	/**
	 * Overloaded string cast operator
	 * @return String representation of the GridPosition.
	 */
	operator std::string() const;

	/**
	 * Overloaded equality operator. Compares the values of this GridPosition
	 * object to another.
	 * @param [in] other An object of GridPosition to compare.
	 * @return True if both rows and columns are same.
	 */
	bool operator== (const GridPosition other) const;

	/**
	 * Overloaded less than operator. Compares the values of this GridPosition
	 * object to another.
	 * This method is required to implement a set of this class.
	 * @param [in] other An object of GridPosition to compare.
	 * @return True if this GridPosition is less than other.
	 */
	bool operator< (const GridPosition other) const;

};

#endif /* GRIDPOSITION_H_ */
