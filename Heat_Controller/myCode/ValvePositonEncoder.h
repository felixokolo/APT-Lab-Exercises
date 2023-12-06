/*
 * Valve.h
 *
 *  Created on: 14 Nov 2023
 *      Author: FELIX WORKSTATION
 */

#ifndef VALVEPOSITONENCODER_H_
#define VALVEPOSITONENCODER_H_

#include "IOPin.h"

/**
 * @brief
 * Describes a position encoder for a valve component.
 * It implements the position tracking of a valve.
 * The valve position is represented through an analog
 * voltage signal 0V - 5V representing the open and closed states respectively.
 */
class ValvePositonEncoder
{
private:
	IOPin ioPin;
	/**< IOPin object representing the IO pin where encoder is connected. */

public:
	/**
	 * Constructor for the ValvePositonEncoder class. The class initializes
	 * an IOPin object as follows IOPin(pinNum, INPUT, ANALOG).
	 * @param [in] pinNum Represents the address where the encoder is connected
	 * This is used to create an IOPin instance with the necessary details to
	 * describe the pin.
	 */
	ValvePositonEncoder(int pinNum);

	/**
	 * Gets the value of the current position reading. The method reads the
	 * value from the position encoder.
	 * @return Current reading from the position encoder.
	 */
	float getCurrentPosition();

};

#endif /* VALVEPOSITONENCODER_H_ */
