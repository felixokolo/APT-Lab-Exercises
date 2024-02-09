/*
 * part1tests.cpp
 *
 *  Created on: 15.11.2019
 *      Author: mnl
 */


using namespace std;

#include "tests.h"

void part2tests () {

	Board b1(10, 10);
	OwnGrid &g1 = b1.getOwnGrid();

	// Place Ship on edge
	assertTrue(g1.placeShip(Ship(GridPosition("A1"),
								 GridPosition("A4"))),
			   "Ship not added on edge");


	//Test for Blocked area
	assertTrue(g1.getBlockedAreas() ==
			   set<GridPosition>{{"A1"}, {"A2"}, {"A3"}, {"A4"}, {"A5"},
								 {"B1"}, {"B2"}, {"B3"}, {"B4"}, {"B5"},},
			   "Blocked areas not correct");

	// Test if ship can be placed next to another ship
	assertTrue(!(g1.placeShip(Ship({"B7"}, {"B5"}))),
			   "Ships can be placed next to another");

	// Test if an invalid ships can be added

	// 1. Diagonal ship
	assertTrue(!(g1.placeShip(Ship({"C4"}, {"D5"}))),
			   "Diagonal ship can be placed on own grid");

	// 2. Ships with invalid row or column
	assertTrue(!(g1.placeShip(Ship({"@4"}, {"D4"}))),
			   "Ship with invalid row can be placed on own grid");
	assertTrue(!(g1.placeShip(Ship({"D0"}, {"D4"}))),
			   "Ship with invalid column can be placed on own grid");

	// 3. Ships extending outside the grid
	assertTrue(!(g1.placeShip(Ship({"K4"}, {"D4"}))),
			   "Ship with invalid row can be placed on own grid");
	assertTrue(!(g1.placeShip(Ship({"D11"}, {"D4"}))),
			   "Ship with invalid column can be placed on own grid");

	// More or less than 2 ships of length 4 can(not) be added
	assertTrue((g1.placeShip(Ship({"G4"}, {"D4"}))),
			   "Less than 2 ships with length 4 can be placed on own grid");
	assertTrue(!(g1.placeShip(Ship({"J4"}, {"J7"}))),
			   "More than 2 ships with length 4 can be placed on own grid");

	// So far only 2 ships has been successfully added
	assertTrue(g1.getShips().size() == 2, "Number of ships added not 2");

	// More or less than 1 ship of length 5 can(not) be added
	assertTrue((g1.placeShip(Ship({"A10"}, {"E10"}))),
			   "Less than 1 ships with length 5 can be placed on own grid");
	assertTrue(!(g1.placeShip(Ship({"J4"}, {"J7"}))),
			   "More than 1 ships with length 5 can be placed on own grid");

	// More or less than 4 ship of length 2 can(not) be added
	assertTrue((g1.placeShip(Ship({"C1"}, {"C2"}))),
			   "Less than 1 ships with length 2 can be placed on own grid");
	assertTrue((g1.placeShip(Ship({"E1"}, {"E2"}))),
			   "Less than 2 ships with length 2 can be placed on own grid");
	assertTrue((g1.placeShip(Ship({"G1"}, {"G2"}))),
			   "Less than 3 ships with length 2 can be placed on own grid");
	assertTrue((g1.placeShip(Ship({"I1"}, {"I2"}))),
			   "Less than 4 ships with length 2 can be placed on own grid");
	assertTrue(!(g1.placeShip(Ship({"A6"}, {"A7"}))),
			   "More than 4 ships with length 2 can be placed on own grid");

	// So far only 7 ships has been successfully added
	assertTrue(g1.getShips().size() == 7, "Number of ships added not 7");

	// More or less than 3 ship of length 3 can(not) be added
	assertTrue((g1.placeShip(Ship({"A6"}, {"A8"}))),
			   "Less than 1 ships with length 3 can be placed on own grid");
	assertTrue((g1.placeShip(Ship({"C8"}, {"C6"}))),
			   "Less than 2 ships with length 3 can be placed on own grid");
	assertTrue((g1.placeShip(Ship({"E6"}, {"E8"}))),
			   "Less than 3 ships with length 3 can be placed on own grid");
	assertTrue(!(g1.placeShip(Ship({"G6"}, {"G8"}))),
			   "More than 3 ships with length 3 can be placed on own grid");

	// So far all 10 ships has been successfully added
	assertTrue(g1.getShips().size() == 10, "Number of ships added not 10");


}
