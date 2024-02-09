/*
 * BlockCourse.cpp
 *
 *  Created on: 11 Jan 2024
 *      Author: FELIX WORKSTATION
 */

#include "BlockCourse.h"

using namespace std;

// Create an object of BlockCourse from parameters in vector.
BlockCourse::BlockCourse(std::vector<std::string> params):
// Initialize data members with basic parameters
		Course(stoi(params[1]), params[2], params[3],
			   stof(params[4]))

{
	// create Time and Date objects from parameters in params
	startDate = Poco::Data::Date(stoi(params[7]),
								 stoi(params[6]),
								 stoi(params[5]));
	endDate = Poco::Data::Date(stoi(params[10]),
							   stoi(params[9]),
							   stoi(params[8]));

	startTime = Poco::Data::Time(stoi(params[11]),
								 stoi(params[12]), 0);
	endTime = Poco::Data::Time(stoi(params[13]),
							   stoi(params[14]), 0);
}

// Create BlockCourse object with provided parameter list
BlockCourse::BlockCourse(unsigned int courseKey, std::string title,
		   	   	   	   	 std::string major, float creditPoints,
		   	   	   	   	 Poco::Data::Date startDate,
						 Poco::Data::Date endDate,
						 Poco::Data::Time startTime,
						 Poco::Data::Time endTime):
						// Initialize data members with parameter list
						 Course(courseKey, title, major, creditPoints),
						 startDate(startDate),
						 endDate(endDate),
						 startTime(startTime),
						 endTime(endTime)
{
	// Nothing to do
}

// Cast BlockCourse to a string
BlockCourse::operator std::string() const
{
	// Create a temporary stream object to write the string format
	std::stringstream stream;
	// Write Course Type with common data members in base class
	stream << "Block Course\n";
	stream << Course::operator string();

	// Create temporary DateTime objects for formatting purpose
	Poco::DateTime startTimeDate(startDate.year(),
								 startDate.month(),
								 startDate.day(),
								 startTime.hour(),
								 startTime.minute());
	Poco::DateTime endTimeDate(endDate.year(),
							   endDate.month(),
							   endDate.day(),
							   endTime.hour(),
							   endTime.minute());

	// Use DateTimeFormatter to format Date and Time data members
	stream << "Start Time & Date:\t"
		   << Poco::DateTimeFormatter::format(startTimeDate,
				   	   	   	   	   	   	   	  "%H:%M %w %f-%b-%Y")
		   << endl;
	stream << "End Time & Date:\t"
		   << Poco::DateTimeFormatter::format(endTimeDate,
				   	   	   	   	   	   	   	  "%H:%M %w %f-%b-%Y")
		   << "\n\n";

	// Return all that has been written to stream
	return stream.str();
}

// Write all data members to a os stream separated by ';'
void BlockCourse::write(std::ostream &out) const
{
	// Write course type.
	out << "B;";
	Course::write(out);
	// Data member separator
	out << ';';
	out << startDate.day() << '-' << startDate.month() << '-'
		<< startDate.year() << ';';
	out << endDate.day() << '-' << endDate.month() << '-'
		<< endDate.year() << ';';
	out << startTime.hour() << ':' << startTime.minute() << ';';
	out << endTime.hour() << ':' << endTime.minute();
}
