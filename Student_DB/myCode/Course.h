/*
 * Course.h
 *
 *  Created on: 11 Jan 2024
 *      Author: FELIX WORKSTATION
 */

#ifndef COURSE_H_
#define COURSE_H_

#include <string>
#include <map>
#include <sstream>
#include <vector>

#include "Poco/DateTimeFormatter.h"
#include "Poco/Timestamp.h"
#include <Poco/DateTime.h>

/**
 * \brief Abstract class that describes common attributes in a course.
 *
 * Child classes implement specific related attributes.
 */
class Course
{
private:
	/**
	 * \brief Maps existing majors to a char key. Used for optimization.
	 */
	static std::map<unsigned char, std::string> majorById;

	/**
	 * \brief Describes the course key of the course. Should be unique.
	 */
	unsigned int courseKey;

	/**
	 * \brief Describes the title of the course.
	 */
	std::string title;

	/**
	 * \brief Describes the major of the course.
	 */
	unsigned char major;

	/**
	 * \brief Holds the credit points of the course.
	 */
	float creditPoints;

	/**
	 * \brief Describes the format for displaying time members.
	 */
	const std::string timeFormat = "%H:%M";

	/**
	 * \brief Describes the format for displaying date members.
	 */
	const std::string dateFormat = "%e.%n.%Y";

	/**
	 * \brief Checks if a major already exists in Course::majorById.
	 * Returns the key else returns the next available key.
	 * @param [in] major Major string to be searched.
	 * @return Char value of the key to the Major string.
	 */
	char getMajorKey(std::string major);


public:

	/**
	 * \brief Abstract constructor for initializing data members
	 * @param [in] courseKey Holds a unique course integer key.
	 * @param [in] title Describes the title of the course.
	 * @param [in] major Describes the course major.
	 * @param [in] creditPoints Holds the credit points of the course
	 */
	Course(unsigned int courseKey, std::string title,
		   std::string major, float creditPoints);

	/**
	 * \brief Returns the course key value.
	 * @return Course::courseKey
	 */
	int getCourseKey() const;

	/**
	 * \brief Returns the course title value.
	 * @return Course::title
	 */
	std::string getTitle() const;

	/**
	 * \brief String cast operator.
	 * @return A string representation of Course.
	 */
	virtual operator std::string() const;

	/**
	 * \brief Writes to a specified std::ostream object.
	 *
	 * Written in this format;
	 * Course::courseKey;\"Course::title\";\"Course::major\";
	 * Course::creditPoints
	 * @param [in] out Reference to the ostream object to be written to.
	 */
	virtual void write(std::ostream& out) const;

	/**
	 * \brief Abstract destructor.
	 */
	virtual ~Course() = 0;
};

#endif /* COURSE_H_ */
