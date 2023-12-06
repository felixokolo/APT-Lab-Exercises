/**
 * \mainpage
 * Created on: 26 Oct 2023
 *      Author: FELIX WORKSTATION
 *
 *  This project codes the Reversi board game in the C++ laguage.
 *  It contains 2 major classes as follows;
 *  1. ReversiBoard - Models the board and its states.
 *  2. ReversiConsoleView - Implements the printing functionality
 *  for the board.
 *
 *  Users can simply create an object of the ReversiBoard, and set the
 *  states of each field by calling the setState function which validates
 *  if the move is in accordance with the game rules before setting the
 *  specified state and thereafter, updates the states of other affected
 *  fields;
 *
 */

#ifndef REVERSIBOARD_H_
#define REVERSIBOARD_H_

#define BOARD_SIZE 8
/**< Defines the default size of ReversiBoard used during instance
 * initialization. */

#define MAX_FLIPS 64
/**< Defines the maximum size of array used in storing fields to be flipped
 * which is passed to the ReversiBoard::getFlipFields method */


/**
 * Enum member that represents possible state of a field on the board;
 */
enum state {
			BLACK,	/**< Member indicating a black disc. */
			WHITE,	/**< Member indicating a white disc. */
			NONE 	/**< Member indicating a no disc. */
		   };
/**
 * @class ReversiBoard
 * @brief This class represents a Reversi game board. It implements the basic
 * game rules of the reversi such as placing a disc in a valid location,
 * flipping opponents discs and other functionalities.
 */
class ReversiBoard
{
private:

	/**
	 * Enum member that represents possible transverse directions.
	 */
	enum direction
	{
		LEFT = 1,	/**< Member representing the left transverse. */
		RIGHT,	/**< Member representing the right transverse. */
		UP,		/**< Member representing the up transverse. */
		DOWN,	/**< Member representing the down transverse. */
		UP_LEFT, /**< Member representing the diagonal up-left transverse. */
		UP_RIGHT, /**< Member representing the diagonal up-right transverse. */
		DOWN_LEFT, /**< Member representing the diag down-left transverse.*/
		DOWN_RIGHT /**< Member representing the diag down-right transverse. */
	};

	/**
	 * Structure member representing coordinate of a field.
	 */
	struct coordinate
	{
		int row; /**< Member representing the row position. */
		int col; /**< Member representing the column position. */
	};

	/**
	 * Structure representing a field on the board.
	 */
	struct field
	{
		state fieldState; /**< Member representing field state. */
		coordinate fieldLoc; /**< Member representing field location. */
	};

	field board[BOARD_SIZE][BOARD_SIZE];
	/**< 2D array representing the fields of the board. */

	/**
	 * Finds all fields that will be flipped with reference to a specified
	 * field by transversing through each direction
	 * @param [in] refField Field to begin search for opponent's discs
	 * @param [out] fields Array of found fields to be flipped
	 * @return Number of valid flips found
	 */
	int getFlipFields(field refField, field *fields);

	/**
	 * Flips the first n fields in the fields array
	 * @param [in] fields Array of fields to be flipped
	 * @param [in] n Number of fields in the array to be flipped
	 */
	void flipFields(field *fields, int n);

	/**
	 * Get the next coordinate towards a specified direction
	 * @param [in] ref Reference coordinate
	 * @param [in] dir Specified direction
	 * @return New coordinate in the specified direction
	 * or (-1, -1) for invalid next positions
	 */
	coordinate getNextCoordinate(coordinate ref, direction dir);

public:
	/**
	 * Reversi Board constructor.
	 * Constructor creates a reversi board with size BOARD_SIZE
	 * Initializes all fields' state to NONE and sets diagonal discs for each
	 * player at the center of the board
	 */
	ReversiBoard();

	/**
	 * Queries the state of a field at a given coordinate
	 * @param [in] cord Coordinate to query
	 * @return A valid enum state
	 */
	state getFieldState(coordinate cord);

	/**
	 * Sets the state of a field at a specified coordinate.
	 * @param [in] s New state of the field.
	 * @param [in] c Coordinate of the field to set.
	 * @return 1 if valid move else 0
	 */
	int setFieldState(state s, coordinate c);
};

#endif /* REVERSIBOARD_H_ */
