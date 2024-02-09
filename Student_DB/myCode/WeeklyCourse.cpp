/*
 * WeeklyCourse.cpp
 *
 *  Created on: 11 Jan 2024
 *      Author: FELIX WORKSTATION
 */

#include "WeeklyCourse.h"

using namespace std;



WeeklyCourse::WeeklyCourse(std::vector<std::string> params):
	Course(atoi(params[1].c_str()), params[2], params[3],
		   atof(params[4].c_str()))

{
	dayOfWeek = Poco::DateTime::DaysOfWeek(atoi(params[5].c_str()));

	startTime = Poco::Data::Time(atoi(params[6].c_str()),
								 atoi(params[7].c_str()), 0);

	endTime = Poco::Data::Time(atoi(params[8].c_str()),
									 atoi(params[9].c_str()), 0);

}

WeeklyCourse::WeeklyCourse(unsigned int courseKey, std::string title,
						   std::string major, float creditPoints,
						   Poco::DateTime::DaysOfWeek dayOfWeek,
						   Poco::Data::Time startTime,
						   Poco::Data::Time endTime):
						   Course(courseKey, title, major, creditPoints),
						   dayOfWeek(dayOfWeek),
						   startTime(startTime),
						   endTime(endTime)
{
}

WeeklyCourse::operator std::string() const
{
	string days[7] = {"SUNS", "MONS", "TUES", "WEDS", "FRIS", "SATS"};
	stringstream stream;

	stream << "Weekly Course\n";
	stream << Course::operator string();
	stream << "Time:\t\t\t";
	stream << days[dayOfWeek] << " ";
	// From startTime - endTime
	stream << Poco::DateTimeFormatter::format(
							Poco::DateTime(2020, 1, 1, startTime.hour(),
										   startTime.minute()), "%H:%M")
		   << " - "
		   << Poco::DateTimeFormatter::format(
					Poco::DateTime(2020, 1, 1, endTime.hour(),
								   endTime.minute()), "%H:%M")
		   << "\n\n";
	return stream.str();
}

void WeeklyCourse::write(std::ostream &out) const
{
	out << "W;"; // Course type

	// Write base class data members
	Course::write(out);

	// Write class data members
	out << ';';
	out << dayOfWeek << ';';
	out << startTime.hour() << ':' << startTime.minute();
	out << ';';
	out << endTime.hour() << ':' << endTime.minute();
}


