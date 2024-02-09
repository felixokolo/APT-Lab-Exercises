/*
 * Address.cpp
 *
 *  Created on: 11 Jan 2024
 *      Author: FELIX WORKSTATION
 */

#include "Address.h"

using namespace std;

// Constructs an Address object with empty initial values
Address::Address(): street(""), postalCode(0), cityName(), additionalInfo()
{
}

// Constructs an Address object initialized with provided parameters.
Address::Address(std::string street, unsigned short postalCode,
				 std::string cityName, std::string additionalInfo):
				// Initialization of data members
				 street(street), postalCode(postalCode), cityName(cityName),
				 additionalInfo(additionalInfo)
{
}


Address::operator std::string() const
{
	// Return concatenated values of data members
	return street + " " +
		   to_string(postalCode) + " " +
		   cityName + " " +
		   additionalInfo;
}

void Address::write(std::ostream &out)
{
	/**
	 * Writes the data members in a specific format separated by ';' and
	 * string members surrounded with double quotes '"'
	 */
	out << '"' << street << '"' << ';'
		<< postalCode << ';'
		<< '"' << cityName << '"' << ';'
		<< '"' << additionalInfo << '"';
}
