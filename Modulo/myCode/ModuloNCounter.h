/*
 * ModuloNCounter.h
 *
 *  Created on: 03.11.2023
 *      Author: Felix
 */

#ifndef MODULONCOUNTER_H_
#define MODULONCOUNTER_H_

#include "ModuloNDigit.h"

#define MIN_COUNTER_SIZE 1
/** Lower limit of counterSize. */
#define MAX_COUNTER_SIZE 10
/** Upper limit of counterSize. */

/**
 * @brief
 * Class that uses the ModuloNDigit counter to implement an N digits counter.
 * This counts from 0 to the max value of each ModuloNDigit counter.
 */
class ModuloNCounter
{
private:
	ModuloNDigit *digitCountersArray;
	/**< Pointer to an array of single digit counters of class ModuloNDigit. */

	unsigned int counterSize;
	/**< Unsigned integer value representing the number of single digits
	 * (ModuluNDigit) counters in digitCountersArray. */

/*	unsigned int digitType;
	**< Unsigned integer value representing the size of individual
	 * ModuloNDigit counter. */

	/**
	 * Enum object consisting of all possible values for individual
	 * ModuloNDigit counters in the digitCountersArray.
	 */
	enum numberBases {
					  BIN = 2,
					  /**< Represents the Binary number system. */
					  OCT = 8,
					  /**< Represents the Octal number system. */
					  DEC = 10,
					  /**< Represents the Decimal number system. */
					  HEX = 16
					  /**< Represents the Hexadecimal number system. */
					 };

public:
	/**
	 * Default constructor for ModuloNCounter object.
	 * @param [in] counterSize Size of counter. Used in defining the
	 * corresponding size of digitCountersArray.
	 * @param [in] digitType Max count value for individual
	 * ModuloNDigit counter.
	 */
	ModuloNCounter(unsigned int counterSize,
				   unsigned int digitType);

	/**
	 * Copy constructor for the ModuloNCounter class.
	 * Initializes a new instance with values of data members of an
	 * existing instance.
	 * @param [in] origin Reference to an existing object of ModuloNCounter
	 */
	ModuloNCounter(ModuloNCounter& origin);

	/**
	 * Overloaded pre-increment operator. Increments the appropriate
	 * ModuloNDigit counter in digitCountersArray.
	 * @return An object by reference with the currentValue of the appropriate
	 * ModuloNDigit counter incremented or reset to 0.
	 */
	ModuloNCounter& operator++();

	/**
	 * Overloaded post-increment operator. Increments the appropriate
	 * ModuloNDigit counter in digitCountersArray.
	 * @param [in] c Pseudo input parameter.
	 * @return A ModuloNCounter object with the currentValue of the appropriate
	 * ModuloNDigit not incremented or reset to 0.
	 */
	ModuloNCounter operator++(int c);

	/**
	 * Overloaded assignment operator.
	 * @param [in] rhs Right Hand Side object of the assignment operation.
	 * @return A reference of this with members initialized with member values
	 * of rhs.
	 */
	ModuloNCounter& operator=(ModuloNCounter& rhs);


	/**
	 * Overloaded output << operator function.

	friend std::ostream& operator<<(std::ostream& out, ModuloNCounter counter);
	 */


	/**
	 * Prints the counter value in a specified format.
	 */
	void print();

	/**
	 * Deconstructor for the ModuloNCounter object.
	 * Frees all allocated memory.
	 */
	virtual ~ModuloNCounter();
};

#endif /* MODULONCOUNTER_H_ */
