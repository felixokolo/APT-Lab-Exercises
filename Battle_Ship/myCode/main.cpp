/**
 * \mainpage
 * Created on: 10 Jan 2024
 *      Author: Felix
 *
 *	##Summary
 *  This project codes the Battle Ship game in the C++ language.
 *  It contains the following classes;
 *
 *  1. GridPosition - This class describes the basic unit of the game which is
 *  a grid on the board where ships shall occupy and shots shall be made.
 *
 *  2. Ship - This class describes the a ship which has a start and end
 *  GridPosition Ship::bow and Ship::stern respectively.
 *
 *  3. OwnGrid - This class describes the grids of the player. Player shall
 *  arrange Ship objects on these grid.
 *
 *  4. OpponentGrid - This class describes the grids of the opponent. It will
 *  hold records of shots made and sunken Ship objects of the opponent.
 *
 *  5. Shot - This class describes a shot made on either the OwnGrid or on
 *  the OpponentGrid.
 *
 *  6. Board - This class gives incorporates the OwnGrid and OpponentGrid to
 *  create a player's board and provides access to these objects.
 *
 *  7. ConsoleView - This class provides a view to the OwnGrid and OpponentGrid
 *  of a board reference.
 */
#include <iostream>

#include "Board.h"
#include "ConsoleView.h"
#include "tests.h"

using namespace std;


// Main program
int main ()
{
	cout << "Battle_Ship started." << endl << endl;

	cout << ">> Performing tests" << endl;
	cout << "---------------------------------------------" << endl;
	cout << ">> Failure Messages:" << endl << endl;
	part1tests();
	part2tests();
	part3tests();

	cout << "---------------------------------------------" << endl;
	cout << ">> Tests ended with above failure messages." << endl << endl;


	cout << ">> Starting Demonstration." << endl;
	cout << "---------------------------------------------" << endl;


	cout << ">> Creating a board of 10x10 with console vie." << endl
		 << endl;
	Board board(10, 10);
	ConsoleView consoleView(&board);

	cout << ">> Printing console view." << endl <<endl;
	consoleView.print();

	cout << ">> Placing 3 ships {B2, B4} {D4, G4} {F6, F9} on OwnGrid" << endl;
	OwnGrid &ownGrid = board.getOwnGrid();
	ownGrid.placeShip(Ship{GridPosition{"B2"}, GridPosition{"B4"}});
	ownGrid.placeShip({{"D4"}, {"G4"}});
	ownGrid.placeShip({{"F6"}, {"F9"}});

	cout << ">> Printing console view with ships on OwnGrid." << endl << endl;
	consoleView.print();

	cout << ">> Receiving shots on OwnGrid on grids B3, B4, and B5"
		 << endl << endl;
	ownGrid.takeBlow(Shot{GridPosition{"B3"}});
	ownGrid.takeBlow({{"B4"}});
	ownGrid.takeBlow({{"B5"}});

	cout << ">> Printing console view with received shots on OwnGrid."
		 << endl << endl;
	consoleView.print();

	cout << ">> Calling shots on OpponentGrid with results as follows; \n\n"
			"\t GRID --- IMPACT \n"
			"\t C3 ------- HIT \n"
			"\t C2 ------- NONE \n"
			"\t G5 ------- HIT \n"
			"\t G4 ------- NONE \n"
			"\t G6 ------- HIT \n"
			"\t C5 ------- HIT \n"
			"\t F5 ------- MISS \n"
			"\t I5 ------- MISS \n"
		 << endl;

	OpponentGrid &opponentGrid = board.getOpponentGrid();
	opponentGrid.shotResult(Shot{GridPosition{"C3"}}, Shot::HIT);
	opponentGrid.shotResult({{"C2"}}, Shot::NONE);
	opponentGrid.shotResult({{"G5"}}, Shot::HIT);
	opponentGrid.shotResult({{"G4"}}, Shot::NONE);
	opponentGrid.shotResult({{"G6"}}, Shot::HIT);
	opponentGrid.shotResult({{"C5"}}, Shot::HIT);
	opponentGrid.shotResult({{"F5"}}, Shot::NONE);
	opponentGrid.shotResult({{"I5"}}, Shot::NONE);

	cout << ">> Printing console view with received shots on OpponentGrid."
		 << endl << endl;
	consoleView.print();

	cout << ">> Calling a sinking shot on OpponentGrid on grid C4" << endl;
	opponentGrid.shotResult({{"C4"}}, Shot::SUNKEN);

	cout << ">> Printing console view with sunken ship on OpponentGrid."
		 << endl << endl;
	consoleView.print();

	cout << "---------------------------------------------" << endl;
	cout << ">> End of Demonstration." << endl << endl;

	return 0;
}
