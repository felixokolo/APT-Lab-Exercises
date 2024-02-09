/*
 * part1tests.cpp
 *
 *  Created on: 15.11.2019
 *      Author: mnl
 */


using namespace std;

#include "tests.h"

/**
 */
void part3tests () {

	Board b1(10, 10);
	OwnGrid &ownGrid = b1.getOwnGrid();
	OpponentGrid &opponentGrid = b1.getOpponentGrid();

	// Place Ship on edge
	assertTrue(ownGrid.placeShip(Ship(GridPosition("A1"),
								 GridPosition("A4"))),
			   "Ship not added on edge");
	// Test Hit
	assertTrue(ownGrid.takeBlow(Shot({"A2"})) == Shot::HIT,
			   "Impact not hit for A3");

	// Test Miss
	assertTrue(ownGrid.takeBlow(Shot({"A5"})) == Shot::NONE,
			   "Impact not missed");


	// Test Sunken
	assertTrue(ownGrid.takeBlow(Shot({"A1"})) == Shot::HIT,
			   "Impact not hit for A1");
	assertTrue(ownGrid.takeBlow(Shot({"A3"})) == Shot::HIT,
			   "Impact not hit for A2");
	assertTrue(ownGrid.takeBlow(Shot({"A4"})) == Shot::SUNKEN,
			   "Impact not sunken");

	// Test Opponent Grid Shot at
	opponentGrid.shotResult(Shot{{"C2"}}, Shot::NONE);
	opponentGrid.shotResult(Shot{{"F5"}}, Shot::NONE);
	opponentGrid.shotResult(Shot{{"G4"}}, Shot::NONE);
	opponentGrid.shotResult(Shot{{"I5"}}, Shot::NONE);
	opponentGrid.shotResult(Shot{{"G5"}}, Shot::HIT);
	opponentGrid.shotResult(Shot{{"G6"}}, Shot::HIT);
	opponentGrid.shotResult(Shot{{"C5"}}, Shot::HIT);
	opponentGrid.shotResult(Shot{{"C3"}}, Shot::HIT);
	opponentGrid.shotResult(Shot{{"C4"}}, Shot::SUNKEN);

	assertTrue(opponentGrid.getSunkenShips().size() == 1,
			   "Sunken ship 1 not added");
	assertTrue(opponentGrid.getSunkenShips()[0].occupiedArea() ==
			   set<GridPosition>{{"C3"}, {"C4"}, {"C5"}},
			   "Sunken ship 1 not correct");


	opponentGrid.shotResult(Shot{{"B9"}}, Shot::HIT);
	opponentGrid.shotResult(Shot{{"E9"}}, Shot::HIT);
	opponentGrid.shotResult(Shot{{"C9"}}, Shot::HIT);
	opponentGrid.shotResult(Shot{{"D9"}}, Shot::HIT);
	opponentGrid.shotResult(Shot{{"F9"}}, Shot::SUNKEN);

	assertTrue(opponentGrid.getSunkenShips().size() == 2,
			   "Sunken ship 2 not added");
	assertTrue(opponentGrid.getSunkenShips()[1].occupiedArea() ==
			   set<GridPosition>{{"B9"}, {"C9"}, {"D9"}, {"E9"}, {"F9"}},
			   "Sunken ship 2 not correct");

}
