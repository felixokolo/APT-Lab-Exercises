/*
 * ModuloNDigit.h
 *
 *  Created on: 03.11.2023
 *      Author: Felix
 */

#ifndef MODULONDIGIT_H_
#define MODULONDIGIT_H_

#include <ostream>

#define MAX_COUNT 16 /**< Maximum possible value for maxValue. */
#define MIN_COUNT 2 /**< Minimum possible value for maxValue. */

/**
 * @brief
 * Class that implements a digit counter which counts up to a maximum specified
 * digit and resets to 0.
 */

class ModuloNDigit
{
private:

	/** @brief Holds the current value of the ModuloNDigit counter object. */
	unsigned int currentValue;

	/** @brief Holds the maximum value of the ModuloNDigit counter object. */
	unsigned int maxValue;

	/** @brief Indicates if an overflow occurred during the last
	 * increment operation. */
	bool overflowFlag;



	/**
	 * @brief Method for setting maximum value of counter. Validates given
	 * value before setting the maxValue.
	 * @param [in] maxValue New maxValue
	 */
	void setMaxValue(unsigned int maxValue);

	/**
	 * @brief Increments the value of the counter by 1 and resets overflowFlag.
	 */
	void incrementCounter();

	/**
	 * @brief Resets the value of the counter to 0 and sets overflowFlag;
	 */
	void resetCounter();

public:
	/**
	 * @brief Default constructor for the ModuloNDigit object.
	 * Initializes the currentValue to 0.
	 * @param [in] maxValue Holds the maximum value of the ModuloNDigit
	 * counter object. Default =  MIN_COUNT.
	 */
	ModuloNDigit(unsigned int maxValue = MIN_COUNT);
	// Default value enables non-parametized construction

	/**
	 * @brief Overloaded pre-increment operator.
	 * @return An object by reference with the currentValue
	 * incremented or reset to 0.
	 */
	ModuloNDigit& operator++();

	/**
	 * @brief Overloaded post-increment operator.
	 * @param [in] c Pseudo input parameter.
	 * @return An object with the currentValue
	 * not incremented or reset to 0.
	 */
	ModuloNDigit operator++(int c);

	/**
	 * @brief Method to get the counter overflow flag. Returns the value of the
	 * overflowFlag indicating whether an overflow occurred during the last
	 * increment operation.
	 * @return Boolean value; true = overflow, false = no-overflow.
	 */
	bool isOverflow();


	/**
	 * @brief Overloaded output << operator function.

	friend std::ostream& operator<<(std::ostream& out, ModuloNDigit counter);
	 */

	/**
	 * @brief Prints the counter value in a specified format.
	 */
	void print();


};

#endif /* MODULONDIGIT_H_ */
