#ifndef TEST_H
#define TEST_H
#include <iostream>
#include "Board.h"
#include "ConsoleView.h"

/**
 * Asserts a condition to be true, else an error message is printed.
 * @param [in] condition Boolean that describes the result of the condition.
 * @param [in] failedMessage Message to be printed if the condition is false.
 */
void assertTrue(bool condition, std::string failedMessage);

/**
 * Tests the conformity of Ship and GridPosition methods to the requirements.
 * GridPosition::isValid()
 *
 */
void part1tests ();

/**
 * Tests the conformity of Ship and GridPosition methods to the requirements.
 */
void part2tests ();
/**
 * Tests the conformity of OwnGrid and OpponentGrid methods to the requirements.
 */
void part3tests ();

#endif /* TEST_H */
