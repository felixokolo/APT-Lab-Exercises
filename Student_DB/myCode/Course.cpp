/*
 * Course.cpp
 *
 *  Created on: 11 Jan 2024
 *      Author: FELIX WORKSTATION
 */

#include "Course.h"

using namespace std;

std::map<unsigned char, std::string> Course::majorById;

Course::Course(unsigned int courseKey, string title,
			   string major, float creditPoints):
courseKey(courseKey), title(title), creditPoints{creditPoints}
{
	if (major.length() == 0)
		throw -1;
	// Convert major to upper case for uniformity
	for (unsigned int pos = 0; pos < major.length(); pos++)
		major[pos] = toupper(major[pos]);
	// Get the key for the major
	this->major = getMajorKey(major);

	majorById[this->major] = major;
}

int Course::getCourseKey() const
{
	return courseKey;
}

string Course::getTitle() const
{
	return title;
}

// Cast BlockCourse to a string
Course::operator std::string() const
{
	string creditPointStr = to_string(creditPoints);

	// Create string representation
	string stringRep =
			"Course Key:\t\t" + to_string(courseKey) + "\n" +
			"Title:\t\t\t" + title + "\n" +
			"Major:\t\t\t" + majorById[major] + "\n" +
			"Credit Points:\t\t" +
			// Format credit points to 2 decimal points
			creditPointStr.substr(0, creditPointStr.find('.') + 3) + " \n";
	return stringRep;
}

// Write all data members to a os stream separated by ';'
void Course::write(std::ostream &out) const
{
	// Write members to stream.
	out << courseKey << ';' << '"' << title << '"' << ';'
		<< '"' << majorById[major] << '"' << ';'
		<< creditPoints;
}


char Course::getMajorKey(std::string major)
{
	// Return A if this is the first major to be entered
	if (majorById.size() == 0)
		return 'A';

	// Search for major in majorById and return key if found
	for (auto majorPair : majorById)
		if (majorPair.second == major)
			return majorPair.first;

	// Return the next char after the last key.
	return majorById.rbegin()->first + 1;
}

Course::~Course()
{

}
