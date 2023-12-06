/*
 * Display.h
 *
 *  Created on: 14 Nov 2023
 *      Author: FELIX WORKSTATION
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <string>
#include "IOPin.h"

/**
 * @brief
 * Class describing a display with necessary communication and writing
 * functions. The display uses a standard RS-232 communication protocol for
 * for communication.
 */
class Display
{
private:
	/**
	 * IOPin object representing the address of the transmission pin.
	 */
	IOPin TX;

	/**
	 * IOPin object representing the address of the receive pin.
	 */
	IOPin RX;
public:
	/**
	 * Constructor for Display class.
	 * @param [in] ioPinTX Represents the address where the transmission
	 * pin of the display is connected.
	 * @param [in] ioPinRX Represents the address where the receive
	 * pin of the display is connected.
	 */
	Display(int ioPinTX, int ioPinRX);

	/**
	 * Writes a string to the display beginning at a specified point.
	 * @param [in] message String to be written to screen.
	 * @param [in] start Integer value representing the starting point of
	 * the text on the screen.
	 */
	void writeToDisplay(std::string message, int start);

	/**
	 * Clears the display.
	 */
	void clearDisplay();
};

#endif /* DISPLAY_H_ */
