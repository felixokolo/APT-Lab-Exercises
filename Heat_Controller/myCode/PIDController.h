/*
 * PIDController.h
 *
 *  Created on: 14 Nov 2023
 *      Author: FELIX WORKSTATION
 */

#ifndef PIDCONTROLLER_H_
#define PIDCONTROLLER_H_

#include "ValveController.h"
#include "TempSensor.h"

/**
 * @brief
 * Class that describes a PID controller for heat control. This is a software
 * component that regulates the flow of heat through a valve. It gets its
 * feedback from a Temperature sensor.
 */
class PIDController
{
private:
	/**
	 * TempSensor object for getting temperature feedback readings.
	 */
	TempSensor tempSensor;

	/**
	 * ValveController object for setting the valve position.
	 */
	ValveController valveController;

	/**
	 * Float value representing the value of the desired temperature used
	 * in regulating the heating system.
	 */
	float desiredTemperature;

	/**
	 * Performs the PID control functions to determine the required valve
	 * position to correct the error between the tempSensor current value and
	 * the desiredTemperature.
	 * This method will be run periodically to perform the regulation function.
	 */
	void regulateTemperature();

public:
	/**
	 * Constructor for a PIDController. It receives the addresses for a
	 * temperature sensor, a valve position encoder and a valve controller.
	 * @param [in] ioPinTemp Represents the address where the sensor is
	 * connected. This is used to create an IOPin instance with the
	 * necessary details to describe the pin.
	 * @param [in] ioPinValveOpen Represents the address where the open valve
	 * control is connected. This is used to create an IOPin instance with the
	 * necessary details to describe the pin.
	 * @param [in] ioPinValveClose Represents the address where the close valve
	 * control is connected. This is used to create an IOPin instance with the
	 * necessary details to describe the pin.
	 * @param [in] ioPinPosEncoder Represents the address where the encoder
	 * is connected. This is used to create an IOPin instance with the
	 * necessary details to describe the pin.
	 */
	PIDController(int ioPinTemp,
				  int ioPinValveOpen,
				  int ioPinValveClose,
				  int ioPinPosEncoder);

	/**
	 * Updates the value of the desired temperature used in regulating
	 * the heating system.
	 */
	void setDesiredTemperature(float desiredTemperature);


};

#endif /* PIDCONTROLLER_H_ */
