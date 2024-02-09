/*
 * Enrollment.h
 *
 *  Created on: 11 Jan 2024
 *      Author: FELIX WORKSTATION
 */

#ifndef ENROLLMENT_H_
#define ENROLLMENT_H_

#include <string>
#include <memory>
#include <iostream>

#include "Course.h"

/**
 * \brief Describes an enrollment of a Student to a Course.
 *
 * Holds a pointer to a Course object and an associated semester and grade
 * for that course.
 */
class Enrollment
{
private:
	/**
	 * \brief Describes the semester of the course enrollment.
	 */
	std::string semester;

	/**
	 * \brief Points to a unique Course object.
	 */
	Course *course;

	/**
	 * \brief Holds the grade of the enrollment.
	 */
	float grade;


public:

	/**
	 * \brief Constructs an enrollment object from passed parameters.
	 * @param [in] semester String that describes the semester of enrollment.
	 * @param [in] course Reference to a unique Course object of enrollment.
	 * @param [in] grade Value of Enrollment::grade
	 */
	Enrollment(std::string semester, Course *course, float grade);

	/**
	 * \brief Move constructor.
	 * @param [in] enrollment Enrollment object to be moved.
	 */
	Enrollment(Enrollment &&enrollment);

	/**
	 * \brief String cast operator.
	 * @return A string representation of Course.
	 */
	operator std::string() const;

	/**
	 * \brief Gets the course of enrollment.
	 * @return Enrollment::course
	 */
	const Course* getCourse();

	/**
	 * \brief Sets Enrollment::grade
	 * @param [in] grade New grade for enrollment.
	 */
	void setGrade(float grade);

	/**
	 * \brief Writes to a specified std::ostream object.
	 * @param [in] out Reference to the ostream object to be written to.
	 */
	void write(std::ostream& out);

	/**
	 * \brief Move assignment operator.
	 *
	 * Moves resources of an object to this object.
	 * @param [in] other Object with resources to be moved.
	 */
	void operator =(Enrollment &&other);

	/**
	 * \brief Equal logic operator.
	 *
	 * Checks if an two enrollments are same.
	 * @param [in] other Object to be compared.
	 * @return True if all data members are same.
	 */
	bool operator ==(Enrollment &other);


};

#endif /* ENROLLMENT_H_ */
