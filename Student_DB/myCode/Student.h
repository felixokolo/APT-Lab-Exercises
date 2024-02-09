/*
 * Student.h
 *
 *  Created on: 11 Jan 2024
 *      Author: FELIX WORKSTATION
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#ifndef POCOFORMAT
#endif

#include <string>
#include <vector>
#include <memory>
#include "Poco/Data/Date.h"
#include "Poco/DateTimeFormatter.h"

#include "Enrollment.h"
#include "Address.h"

/**
 * \brief Student class that describes the attributes of a student.
 *
 * This also includes the enrollments made by the student.
 */
class Student
{
private:
	/**
	 * \brief Holds the next matrikel number for initializing the next
	 * Student::matrikelNumber.
	 */
	static unsigned int nextMatrikelNumber;

	/**
	 * \brief Describes the Matriculation number of the Student.
	 */
	unsigned int matrikelNumber;

	/**
	 * \brief Student's first name
	 */
	std::string firstName;

	/**
	 * \brief Student's last name
	 */
	std::string lastName;

	/**
	 * \brief Student's date of birth
	 */
	Poco::Data::Date dateOfBirth;

	/**
	 * \brief List containing all the Enrollment to Course objects made
	 * by a Student.
	 */
	std::vector<Enrollment> enrollments;

	/**
	 * \brief Object to describe address of Student.
	 */
	Address address;

public:
	/**
	 * \brief Constructs an object of Student with parameters stored in a
	 * std::vector<std::string>
	 * @param [in] params Vector list of the parameters for initializing all
	 * instance members
	 * <table style="width:70%" border=1px solid black>
	 * <tr>
	 *	<th>Patameter Position</th> <th>Descriptions</th>
	 * </tr>
	 * <tr>
	 * <th>param[0]</th> <td>Matriculation Number</td>
	 * </tr>
	 * <tr>
	 * <th>param[1]</th> <td>First name</td>
	 * </tr>
	 * <tr>
	 * <th>param[2]</th> <td>Last name.</td>
	 * </tr>
	 * <tr>
	 * <th>param[3]</th> <td>Day of birth.</td>
	 * </tr>
	 * <tr>
	 * <th>param[4]</th> <td>Month of birth.</td>
	 * </tr>
	 * <tr>
	 * <th>param[5]</th> <td>Year of birth.</td>
	 * </tr>
	 * <tr>
	 * <th>param[6]</th> <td>Address street.</td>
	 * </tr>
	 * <tr>
	 * <th>param[7]</th> <td>Address post code.</td>
	 * </tr>
	 * <tr>
	 * <th>param[8]</th> <td>Address city.</td>
	 * </tr>
	 * <tr>
	 * <th>param[9]</th> <td>Address additional info.</td>
	 * </tr>
	 * </table>
	 */
	Student(std::vector<std::string> params);

	/**
	 * \brief Move constructor.
	 * @param [in] student Student object to be moved.
	 */
	Student(Student &&student);


	/**
	 * \brief Constructs a Student object from a list of parameters.
	 * @param [in] firstName First name of Student.
	 * @param [in] lastName Last name of Student.
	 */
	Student(std::string firstName, std::string lastName);

	/**
	 * \brief String cast operator.
	 * @return A string representation of Student.
	 */
	operator std::string() const;

	/**
	 * \brief Move assignment operator.
	 * @param [in] other Student object to be moved.
	 * @return Moved object of student
	 */
	Student& operator=(Student &&other);

	/**
	 * \brief Gets the matriculation number of Student.
	 * @return Student::matrikelNumber
	 */
	int getMatrikelNumber();

	/**
	 * \brief Gets the concatenated last and first names of Student
	 * @return Full name of Student
	 */
	std::string getName();


	/**
	 * \brief Sets the Student::address.
	 * @param [in] street Describes the street name of the address.
	 * @param [in] postalCode Integer describing the postal code
	 * of the address.
	 * @param [in] cityName City name of the address.
	 * @param [in] additionalInfo Any info that describes the address better.
	 */
	void setAddress(std::string street,
					unsigned int postalCode,
					std::string cityName, std::string additionalInfo);

	/**
	 * \brief Sets the date of birth of Student
	 * @param [in] day Day of birth.
	 * @param [in] month Month of birth.
	 * @param [in] year Year of birth.
	 */
	void setDateOfBirth(unsigned int day,
						unsigned int month,
						unsigned int year);

	/**
	 * \brief Adds an Enrollment to Student::enrollments.
	 * @param [in] semester String that describes the semester of enrollment.
	 * @param [in] course Reference to a unique Course object of enrollment.
	 * @param [in] grade Value of Enrollment::grade
	 * @return true if the entollment was added successfully.
	 */
	bool addEnrollment(std::string semester, Course *course, float grade);

	/**
	 * \brief Checks if an enrollment exists in Student::enrollments.
	 * @param [in] enrollment Pointer to an Enrollment object to be added.
	 * @return True if enrollment exists in Student::enrollments
	 */
	bool enrollmentExists(Enrollment &enrollment);

	/**
	 * \brief Sets full name of a Student.
	 * @param [in] firstName New first name of Student.
	 * @param [in] lastName New last name of Student.
	 */
	void setNames(std::string firstName, std::string lastName);

	/**
	 * \brief Sets the grade of an Enrollment to a new grade.
	 * @param [in] index Position of enrollment in Student::enrollments.
	 * @param [in] grade New grade to set.
	 */
	void setEnrollmentGrade(unsigned int index, float grade);

	/**
	 * \brief Generates a list of all Enrollment objects in
	 * Student::enrollments.
	 * @return String containing all string representation of enrollment.
	 */
	std::string listEnrollments() const;

	/**
	 * \brief Removes an Enrollment object from Student::enrollments.
	 * @param [in] index Index of Enrolloment object to be removed.
	 */
	void deleteEnrollment(unsigned int index);

	/**
	 * \brief Writes to a specified std::ostream object.
	 * @param [in] out Reference to the ostream object to be written to.
	 */
	void write(std::ostream& out);

	/**
	 * \brief Gets list of all Enrollment objects.
	 * @return Student::enrollments.
	 */
	std::vector<Enrollment> &getEnrollments();

	/**
	 * \brief Destructor of Student;
	 */
	~Student();


};

#endif /* STUDENT_H_ */
