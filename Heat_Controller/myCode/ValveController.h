/*
 * ValveController.h
 *
 *  Created on: 14 Nov 2023
 *      Author: FELIX WORKSTATION
 */

#ifndef VALVECONTROLLER_H_
#define VALVECONTROLLER_H_

#include "IOPin.h"
#include "ValvePositonEncoder.h"

/**
 * @brief
 * It implements the actuation and position tracking of a valve.
 * The valve position is controlled through two DIGITAL IOPin.
 * driveOpenIOPin drives the valve open while the driveCloseIOPin drives the
 * valve to close position.
 */
class ValveController
{
private:

	/** @brief IOPin object representing the IO pin where
	 * the actuator close signal is connected.
	 */
	IOPin driveCloseIOPin;

	/** @brief IOPin object representing the IO pin where
	 * the actuator open signal is connected.
	 */
	IOPin driveOpenIOPin;

	/** @brief ValvePositonEncoder instance representing the position where
	 * the position encoder of the valve is connected.
	 */
	ValvePositonEncoder positionEnconer;


public:
	/**
	 * @brief Constructor for the ValveController class.
	 * @param [in] openIOPinNum Represents the address where the open valve
	 * control is connected. This is used to create an IOPin instance with the
	 * necessary details to describe the pin.
	 * @param [in] closeIOPinNum Represents the address where the close valve
	 * control is connected. This is used to create an IOPin instance with the
	 * necessary details to describe the pin.
	 * @param [in] encoderIOPinNum Represents the address where the encoder
	 * is connected. This is used to create an IOPin instance with the
	 * necessary details to describe the pin.
	 */
	ValveController(int openIOPinNum, int closeIOPinNum, int encoderIOPinNum);

	/**
	 * Method to set the valve to a specified position. The position is
	 * given in percentage with 0 representing close position and 100
	 * representing open position.
	 * @param [in] position Float value representing the required position
	 * of the valve.
	 */
	void setPosition(float position);

	/**
	 * Method to get the current position of the valve. The returned position
	 * is given in percentage with 0 representing close position and 100
	 * representing open position.
	 * @return Float value representing the current position
	 * of the valve.
	 */
	 float getPosition();

};

#endif /* VALVECONTROLLER_H_ */
