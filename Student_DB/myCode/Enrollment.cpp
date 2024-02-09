/*
 * Enrollment.cpp
 *
 *  Created on: 11 Jan 2024
 *      Author: FELIX WORKSTATION
 */

#include "Enrollment.h"

using namespace std;

// Create Enrollment object with passed parameters
Enrollment::Enrollment(std::string semester,
					   Course *course, float grade):
					   // Initialize parameter list
					   semester(semester), course(course), grade(grade)
{
	// Do nothing
}

Enrollment::Enrollment(Enrollment &&enrollment)
{
	// Move resources of enrollment to this object
	*this = move(enrollment);
}

Enrollment::operator std::string() const
{
	// Create a temporary string stream object and write data members.
	stringstream stream;
	stream << "Semester:\t\t" << semester << "\n";
	stream << "Course Title:\t" << course->getTitle() << "\n";
	stream << "Grade:\t\t" << grade << "\n";
	return stream.str();
}

const Course* Enrollment::getCourse()
{
	return course;
}

void Enrollment::setGrade(float grade)
{
	this->grade = grade;
}

// Write all data members to a os stream separated by ';'
void Enrollment::write(std::ostream &out)
{
	out << '"' << semester << '"' << ';'
		<< course->getCourseKey() << ';'
		<< grade;
}

void Enrollment::operator =(Enrollment &&other)
{
	semester = other.semester;
	// Move course resources.
	course = move(other.course);
	grade = other.grade;
}

bool Enrollment::operator ==(Enrollment &other)
{
	// Compare the two enrollments' Semester and Course Pointer
	return (semester == other.semester) && (course == other.course);
}
