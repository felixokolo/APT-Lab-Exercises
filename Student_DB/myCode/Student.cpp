/*
 * Student.cpp
 *
 *  Created on: 11 Jan 2024
 *      Author: FELIX WORKSTATION
 */

#include "Student.h"

using namespace std;

unsigned int Student::nextMatrikelNumber = 100000;

Student::Student(std::vector<std::string> params)
{
	matrikelNumber = nextMatrikelNumber++;
	firstName = params[1];
	lastName = params[2];

	// Make first letters of the names upper case
	firstName[0] = toupper(firstName[0]);
	lastName[0] = toupper(lastName[0]);

	dateOfBirth = Poco::Data::Date(atoi(params[5].c_str()),
								   atoi(params[4].c_str()),
								   atoi(params[3].c_str()));
	setAddress(params[6], atoi(params[7].c_str()), params[8], params[9]);
}

Student::Student(std::string firstName, std::string lastName):
				 firstName(firstName), lastName(lastName)
{
	matrikelNumber = nextMatrikelNumber++;

	// Make first letters of the names upper case
	firstName[0] = toupper(firstName[0]);
	lastName[0] = toupper(lastName[0]);
}

Student::Student(Student &&student)
{
	nextMatrikelNumber ++; // To counter the decrement from the destructor.

	// Avoid self assignment.
	if (this == &student)
	{
		return;
	}
	*this = move(student);

}

void Student::setAddress(string street, unsigned int postalCode,
						 string cityName, string additionalInfo)
{
	address = Address(street, postalCode, cityName, additionalInfo);
}

int Student::getMatrikelNumber()
{
	return matrikelNumber;
}

void Student::setDateOfBirth(unsigned int day,
							 unsigned int month,
							 unsigned int year)
{
	dateOfBirth = Poco::Data::Date(year, month, day);
}

Student::operator std::string() const
{
	stringstream stream;

	stream << "Name:\t\t" << firstName << " " << lastName << "\n";
	stream << "Matr Num:\t" << matrikelNumber << "\n";
	stream << "Date of Birth:\t"
		   << Poco::DateTimeFormatter::format(
				   Poco::DateTime(dateOfBirth.year(),
				   dateOfBirth.month(),
				   dateOfBirth.day()),
								 "%w %f-%b-%Y")
		   << "\n";
	stream << "Address:\t" << (string) address << "\n";
	stream << "\nEnrollments:\n";
	stream << listEnrollments();
	return stream.str();

}

std::string Student::getName()
{
	return lastName + " " + firstName;
}

bool Student::addEnrollment(std::string semester, Course *course,
		float grade)
{
	bool exists = false; // To check if enrollment already exists.

	Enrollment enrollToAdd(semester, course, grade);
	for (auto itr = enrollments.begin(); itr != enrollments.end(); itr++)
	{
		exists = *itr == enrollToAdd;
		if (exists)
			break;
	}
	enrollments.insert(enrollments.end(), move(enrollToAdd));

	return exists;
}

bool Student::enrollmentExists(Enrollment &enrollment)
{
	for (auto itr = enrollments.begin(); itr != enrollments.end(); itr++)
	{
		if (enrollment.getCourse() == itr->getCourse())
			return true;
	}
	return false;

}

void Student::setNames(std::string firstName, std::string lastName)
{
	this->firstName = firstName;
	this->lastName = lastName;
}

void Student::setEnrollmentGrade(unsigned int index, float grade)
{
	if (enrollments.size() > index-1)
		enrollments[index-1].setGrade(grade);
}

std::string Student::listEnrollments() const
{
	stringstream stream;
	int n = 1;
	for (auto itr = enrollments.begin(); itr != enrollments.end(); itr++)
	{
		stream << "-----------" << n
			   << "-----------\n" << (string) *itr << "\n";
		n++;
	}
	return stream.str();
}

void Student::deleteEnrollment(unsigned int index)
{
	if (enrollments.size() > index)
		return;
	enrollments.erase(enrollments.begin() + index);
}

void Student::write(std::ostream &out)
{
	out << matrikelNumber << ';'
		<< '"' << firstName << '"' << ';'
		<< '"'<< lastName << '"' << ';'
		<< dateOfBirth.day() << '-' << dateOfBirth.month() << '-'
		<< dateOfBirth.year() << ';';
	address.write(out);
}

std::vector<Enrollment>& Student::getEnrollments()
{
	return enrollments;
}

Student& Student::operator =(Student &&other)
{
	if (this == &other)
	{
		return *this;
	}
	// Move resources
	this->matrikelNumber = move(other.matrikelNumber);
	this->firstName = move(other.firstName);
	this->lastName = move(other.lastName);
	this->address = move(other.address);
	this->dateOfBirth = move(other.dateOfBirth);
	this->enrollments = move(other.enrollments);
	return *this;
}

Student::~Student()
{
	nextMatrikelNumber--;
}
