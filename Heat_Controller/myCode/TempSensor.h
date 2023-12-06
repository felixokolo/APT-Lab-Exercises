/*
 * TempSensor.h
 *
 *  Created on: 14 Nov 2023
 *      Author: FELIX WORKSTATION
 */

#ifndef TEMPSENSOR_H_
#define TEMPSENSOR_H_

#include "IOPin.h"


/**
 * @brief
 * A class representing a temperature sensor. The described sensor, outputs
 * the sensed temperature as an analog voltage signal between 0V to 5V.
 */
class TempSensor
{

private:
	IOPin ioPin;
	/**< Represents the pin in which the temperature sensor is connected to.*/
public:
	/**
	 * Constructor for the TempSensor class. The class initializes an IOPin
	 * object as follows IOPin(pinNum, INPUT, ANALOG).
	 * @param [in] pinNum Represents the address where the sensor is connected
	 * This is used to create an IOPin instance with the necessary details to
	 * describe the pin.
	 */
	TempSensor(int pinNum);

	/**
	 * Gets the value of the current temperature reading. The method reads the
	 * value from the temperature sensor.
	 * @return Current reading from the temperature sensor.
	 */
	float getCurrentTemperatureValue();
};

#endif /* TEMPSENSOR_H_ */
