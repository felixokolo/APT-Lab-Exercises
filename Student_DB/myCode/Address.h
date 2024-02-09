/*
 * Address.h
 *
 *  Created on: 11 Jan 2024
 *      Author: FELIX WORKSTATION
 */

#ifndef ADDRESS_H_
#define ADDRESS_H_

#include <string>
#include <iostream>

/**
 * \brief Class describing an address of a Student.
 */
class Address
{
private:
	/**
	 * \brief Describes the street of the Address
	 */
	std::string street;

	/**
	 * \brief Postal code of the Address
	 */
	unsigned short postalCode;

	/**
	 * \brief City name of the Address
	 */
	std::string cityName;

	/**
	 * \brief Additional information regarding the Address
	 */
	std::string additionalInfo;


public:
	/**
	 * \brief Default constructor of Address object.
	 * Initializes all member strings with an empty string.
	 */
	Address();

	/**
	 * \brief Constructor for an Address object.
	 * @param [in] street \brief Describes the street name of the address.
	 * @param [in] postalCode Integer describing the postal code
	 * of the address.
	 * @param [in] cityName City name of the address.
	 * @param [in] additionalInfo Any info that describes the address better.
	 */
	Address(std::string street,
			unsigned short postalCode,
			std::string cityName,
			std::string additionalInfo);

	/**
	 * \brief String cast operator.
	 * @return A string representation of the address.
	 */
	operator std::string() const;

	/**
	 * \brief Writes to a specified std::ostream object.
	 * @param [in] out Reference to the ostream object to be written to.
	 */
	void write(std::ostream& out);
};

#endif /* ADDRESS_H_ */
