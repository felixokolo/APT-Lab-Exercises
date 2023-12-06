/** \mainpage
 * Created on: 14 Nov 2023
 *      Author: FELIX WORKSTATION
 *
 * This project declares the functionalities of a heat controller system.
 * It approaches it from a functional perspective beginning from a standard
 * IOPin which is the main interface between the software and the hardware
 * components of the system.
 * A TempSensor describes the component which senses ambient heat.
 * A ValvePositionEncoder tracks the position of a valve used in regulating
 * generated heat from the system.
 * A ValveController actuates the valve to specified positions.
 * A PIDController is a software component that incorporates the
 * functionalities of a TempSensor, ValvePositionEncoder and a ValveController
 * to achieve heat control.
 *
 *
 * WORKING PRINCIPLE
 *
 * When the user increases the temperature by 5 degrees, this action is
 * received by the Button::readButtonState method which in turn calls the
 * IOPin::readDigitalValue  method. The new desired temperature value is
 * passed to the Display::writeToDisplay method to be written to the screen.
 * The desired temperature value is also passed to the
 * PIDController::setDesiredTemperature method to update the
 * PIDController::desiredTemperature instance variable. The
 * PIDController::regulateTemperature method is then invoked to calculate
 * a new position value for the valve using the error between
 * PIDController::desiredTemperature and the returned value from
 * TempSensor::getCurrentTemperatureValue (which reads the sensor data by
 * calling IOPin::readAnalogValue method). The calculated value is then
 * passed to the ValveController::setPosition to adjust the valve position
 * to the new state. This is achieved by setting the
 * ValveController::driveCloseioPin or ValveController::driveOpenioPin
 * IOPin instances, thereby closing or opening the valve until the new
 * position is reached based on the feedback from the
 * ValvePositionEncoder::getCurrentPosition.
 */

#ifndef IOPIN_H_
#define IOPIN_H_

/**
 * Defines the possible data direction of an IO pin.
 */
enum DataDirection {
	INPUT, /**< Represents a data input direction. */
	OUTPUT /**< Represents a data output direction. */
};

/**
 * Defines the permissible data type of the IO pin.
 */
enum DataType {
	DIGITAL, /**< Represents digital (Binary) data type. */
	ANALOG /**< Represents analog (Continuous) data type. */
};

/**
 * @brief
 * This class represents a basic communication IO pin on a microcontroller.
 * It describes all possible functionalities of an IO pin.
 */
class IOPin
{
private:
	int pinNum; /**< Integer representing the address of the pin. */
	DataDirection direction; /**< Representing the instance data direction.*/
	DataType dataType; /**< Representing the instance data type.*/


public:
	/**
	 * Constructor for the IOPin class.
	 * @param [in] pinNum Address of the IO pin.
	 * @param [in] direction Data direction of the IO pin.
	 * @param [in] dataType Data type being transmitted on the IO pin.
	 */
	IOPin(int pinNum,
		  DataDirection direction,
		  DataType dataType);

	/**
	 * Sets the Data direction of the IO pin to possible values in the
	 * DataDirection enum.
	 * @param [in] direction New DataDirection value for the direction.
	 */
	void setDirection(DataDirection direction);

	/**
	 * Reads the current digital value on the IO pin. This method checks the
	 * value of the dataType to read the appropriate value.
	 * @return An int value either 1 or 0 if dataType is set to DIGITAL.
	 * -1 if dataType is set to ANALOG
	 */
	int readDigitalValue();

	/**
	 * Reads the current analog value on the IO pin. This method checks the
	 * value of the dataType to read the appropriate value.
	 * @return An int value representing the current value on the 12-bits
	 * Analog to Digital Converter (0 - 4096) if dataType is set to ANALOG.
	 * -1 if dataType is set to DIGITAL.
	 */
	int readAnalogValue();
};

#endif /* IOPIN_H_ */
