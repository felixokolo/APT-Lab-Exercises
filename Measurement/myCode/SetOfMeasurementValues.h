/*
 * SetOfMeasurementValues.h
 *
 *  Created on: 24 Oct 2023
 *      Author: FELIX
 */

#ifndef SETOFMEASUREMENTVALUES_H_
#define SETOFMEASUREMENTVALUES_H_

#define MAXVALUE 10
#define NOVALUE -9999

#include <string>

/*
 * Enum type representing several possible units of measurement.
 */
enum unit_t {
			 A, 	/**<Member representing Ampere.*/
			 V, 	/**<Member representing Volts.*/
			 S, 	/**<Member representing Seconds.*/
			 W, 	/**<Member representing Watts.*/
			 NONE 	/**<Member representing unitless values.*/
			};


class SetOfMeasurementValues
{
private:
	double value[MAXVALUE]; 	/**< Array to store consecutive measurements. */
	unit_t unit; 		/**< Stores unit of the measurements.*/
	std::string name; 	/**< Stores name of the measurements. */

	/*
	 * Prints the value of a measurement at a specified index
	 * @param [in] pos Index of the measurement to be printed.
	 */
	void printSingleValue(unsigned int pos);


public:
	/*
	 * Constructor for class SetofMeasurementValues.
	 * @param [in] name String representing the name of the measurements.
	 * @param [in] unit Enum member representing the unit of the measurements
	 */
	SetOfMeasurementValues(std::string name = "Periodic", unit_t unit = S);

	/*
	 * Sets the value of a measurement at a given index
	 * @param [in] pos Index to set
	 * @param [in] value Value of measurement to set
	 */
	void setValue(unsigned int pos, double value);

	/*
	 * Sets random values in the measurement array.
	 * @param [in] min Lower limit of random value.
	 * @param [in] max Upper limit of random value.
	 */
	void setRandomValues(int min, int max);

	/*
	 * Prints the array of measurements.
	 */
	void print();

	/*
	 * Gets the value of measurement at a given Index.
	 * @param [in] pos Index of the measurement to get.
	 * @return Double containing the measurement at the specified index.
	 */
	double getValue(unsigned int pos);

	/*
	 * Calculates the average of the measurements on the array.
	 * @return Average of all measurement.
	 */
	double getAverage();

	/*
	 * Gets the maximum value in the array of measurements.
	 * @return Double value of the maximum value in the array.
	 */
	double getMax();

	/*
		 * Gets the minimum value in the array of measurements.
		 * @return Double value of the minimum value in the array.
		 */
		double getMin();
};

#endif /* SETOFMEASUREMENTVALUES_H_ */
