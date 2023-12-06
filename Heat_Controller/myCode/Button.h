/*
 * Button.h
 *
 *  Created on: 14 Nov 2023
 *      Author: FELIX WORKSTATION
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include "IOPin.h"

/**
 * @brief
 * Class that implements a simple input button with reading function.
 */
class Button
{
private:
	/**
	 * IOPin object that describes the pin where the button is connected.
	 */
	IOPin ioPin;

	/**
	 * Unique ID for describing the button instance.
	 */
	int ID;

public:
	/**
	 * Constructor for the Button class. The class initializes an IOPin
	 * object as follows IOPin(pinNum, INPUT, DIGITAL).
	 * @param [in] pinNum Represents the address where the button is connected
	 * This is used to create an IOPin instance with the necessary details to
	 * describe the pin.
	 * @param [in] ID Unique ID for each button instance.
	 */
	Button(int pinNum, int ID);

	/**
	 * Reads the state of the button. Returns an integer value representing
	 * the current state of the button.
	 * @return 1 if button is pressed and 0 if button is not pressed.
	 */
	int readButtonState();
};

#endif /* BUTTON_H_ */
