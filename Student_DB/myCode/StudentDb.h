/*
 * StudentDb.h
 *
 *  Created on: 11 Jan 2024
 *      Author: FELIX WORKSTATION
 */

#ifndef STUDENTDB_H_
#define STUDENTDB_H_

#include <map>
#include <memory>
#include <functional>
#include <Poco/Net/SocketStream.h>
#include <Poco/Net/SocketAddress.h>
#include <Poco/JSON/Parser.h>
#include <Poco/JSON/Object.h>
#include <exception>

#include "Student.h"
#include "WeeklyCourse.h"
#include "BlockCourse.h"

/**
 * \brief Enum describing the different types of updates that can be done
 * on a student object
 */
enum StudentUpdate {
	STUDENT_NAME, /**< Update Student::firstName and Student::lastName. */
	STUDENT_DOB, /**< Update Student::dateOfBirth. */
	STUDENT_ADDRESS, /**< Update Student::address. */
	STUDENT_ENROLLMENT_GRADE, /**< Update Student::enrollments[].grade. */
	DELETE_STUDENT_ENROLLMENT, /**< Delete Student::enrollments[]. */
};

/**
 * \brief Implementation of a student database.
 *
 * Implements a student database class which stores records of students and
 * courses.
 */
class StudentDb
{
private:
	/**
	 * \brief Stores the record of all Student objects.
	 */
	std::map<int, Student> students;

	/**
	 * \brief Stores record of all Course objects.
	 */
	std::map<int, std::unique_ptr<const Course>> courses;

	/**
	 * \brief Splits a line of string into vector.
	 *
	 * Splits a line of formatted string containing data values into a vector
	 * of all the values.
	 *
	 */
	std::vector<std::string> splitLine(std::string line,
									   std::function<bool(char)> ops);

	/**
	 * \brief Web server to read student details.
	 */
	std::string serverHostAddress = "www.hhs.users.h-da.cloud";

	/**
	 * \brief Port of web server to connect to.
	 */
	int serverPort = 4242;

public:
	/**
	 * \brief Default constructor.
	 *
	 * Default constructor for Student object.
	 */
	StudentDb();

	/**
	 * \brief Adds a BlockCourse to StudentDb::courses.
	 * @param [in] courseKey see Course::courseKey
	 * @param [in] title see Course::title
	 * @param [in] major see Course::major
	 * @param [in] creditPoints see Course::creditPoints
	 * @param [in] startDate Start date of course.
	 * @param [in] endDate End date of block course
	 * @param [in] startTime Start time of block course
	 * @param [in] endTime End time of block course.
	 */
	bool addBlockCourse(unsigned int courseKey, std::string title,
					    std::string major, float creditPoints,
					    Poco::Data::Date startDate,
					    Poco::Data::Date endDate,
					    Poco::Data::Time startTime,
					    Poco::Data::Time endTime);

	/**
	 * \brief Adds a WeeklyCourse to StudentDb::courses.
	 * @param [in] courseKey see Course::courseKey
	 * @param [in] title see Course::title
	 * @param [in] major see Course::major
	 * @param [in] creditPoints see Course::creditPoints
	 * @param [in] dayOfWeek Day of the week SUN - MON
	 * @param [in] startTime Start time of weekly course
	 * @param [in] endTime Start time of weekly course
	 */
	bool addWeeklyCourse(unsigned int courseKey, std::string title,
						 std::string major, float creditPoints,
						 Poco::DateTime::DaysOfWeek dayOfWeek,
						 Poco::Data::Time startTime,
						 Poco::Data::Time endTime);

	/**
	 * \brief Adds a Student to StudentDb::students.
	 * @param [in] firstName First name of Student.
	 * @param [in] lastName Last name of Student.
	 * @param [in] day Day of birth.
	 * @param [in] month Month of birth.
	 * @param [in] year Year of birth.
	 * @param [in] street Describes the street name of the address.
	 * @param [in] postalCode Integer describing the postal code
	 * of the address.
	 * @param [in] cityName City name of the address.
	 * @param [in] additionalInfo Any info that describes the address better.
	 * @return Student::matrikelNumber
	 */
	int addStudent(std::string firstName, std::string lastName,
				   int day, int month, int year,
				   std::string street, unsigned short postalCode,
				   std::string cityName, std::string additionalInfo);

	/**
	 * \brief Adds an Enrollment object to a Student in StudentDB::students.
	 * @param [in] matrikelNumber Student's matriculation number
	 * @param [in] semester String that describes the semester of enrollment.
	 * @param [in] courseKey key of course to be enrolled.
	 * @param [in] grade Value of Enrollment::grade
	 * @return True if enrollment was added successfully.
	 */
	bool addEnrollment(int matrikelNumber,
					   std::string semester,
					   int courseKey,
					   float grade);

	/**
	 * \brief Searches for a keyword in the names of a student.
	 *
	 * Generates a string list of matrikel numbers annd names of students
	 * with the keyword contained in their names.
	 * An empty keyword lists all students.
	 * @param [in] keyword String keyword to be searched.
	 * @return String list of student matrikel numbers and names.
	 */
	std::string searchStudents(std::string keyword);

	/**
	 * \brief Checks if a course with courseKey exists in StudentDB::courses
	 * @param [in] courseKey Course key to be searched.
	 * @return True if course key is found
	 */
	bool courseExists(int courseKey);

	/**
	 * \brief Gets a string representation of a student with the specified
	 * matrielNumber.
	 * @param [in] matrikelNumber Matriculation number to search.
	 * @return String representation of found student.
	 */
	std::string getStudent(int matrikelNumber);

	/**
	 * \brief Checks if student exists in StudentDb::students.
	 * @param [in] matrikelNumber Matriculation number to search.
	 * @return True  if student is found.
	 */
	bool studentExists(int matrikelNumber);

	/**
	 * \brief Lists all the courses in StudentDb::courses in a string.
	 * @return String list of all courses in StudentDb::courses.
	 */
	std::string listCourses();

	/**
	 * \brief Updates a Student object.
	 * @param [in] matrikelNum Student matriculation number to be updated.
	 * @param [in] type Type of update to be done on the student.
	 * @param [in] params List of update parameters.
	 * @return True if update is successful.
	 */
	bool updateStudent(int matrikelNum, StudentUpdate type,
					   std::vector<std::string> params);

	/**
	 * Gets a list of student enrollments.
	 * @param [in] matrikelNum Student matriculation number to be updated.
	 * @return String of all enrollments contained in a Student.
	 */
	std::string getStudentEnrollments(int matrikelNum);

	/**
	 * \brief Writes all objects to specified std::ostream object.
	 * @param [in] out Reference to the ostream object to be written to.
	 */
	void write(std::ostream& out);

	/**
	 * \brief Reads and loads database from a specified input
	 * std::ostream object.
	 * @param [in] in Reference to the ostream object to be read.
	 */
	void read(std::istream& in);

	/**
	 * \brief Enters new students from info from web server.
	 * @param [in] n Number of students to load.
	 * @ return True if successful.
	 */
	bool readFromServer(int n);

};

#endif /* STUDENTDB_H_ */
