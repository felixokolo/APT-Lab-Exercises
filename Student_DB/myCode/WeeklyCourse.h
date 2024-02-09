/*
 * WeeklyCourse.h
 *
 *  Created on: 11 Jan 2024
 *      Author: FELIX WORKSTATION
 */

#ifndef WEEKLYCOURSE_H_
#define WEEKLYCOURSE_H_

#include <Poco/Data/Time.h>
#include <Poco/DateTime.h>

#include "Course.h"

/**
 * \brief  Class describing a weekly course which occurs weekly.
 */
class WeeklyCourse : public Course
{
private:
	/**
	 * \brief Describes the day of week which course takes place.
	 */
	Poco::DateTime::DaysOfWeek dayOfWeek = Poco::DateTime::MONDAY;

	/**
	 * \brief Describes the start time of the course.
	 */
	Poco::Data::Time startTime;

	/**
	 * Describes the end time for the course.
	 */
	Poco::Data::Time endTime;
public:
	/**
	 * \brief Constructor for WeeklyCourse object.
	 * @param [in] courseKey see Course::courseKey
	 * @param [in] title see Course::title
	 * @param [in] major see Course::major
	 * @param [in] creditPoints see Course::creditPoints
	 * @param [in] dayOfWeek Day of the week SUN - MON
	 * @param [in] startTime Start time of weekly course
	 * @param [in] endTime Start time of weekly course
	 */
	WeeklyCourse(unsigned int courseKey, std::string title,
			   	 std::string major, float creditPoints,
				 Poco::DateTime::DaysOfWeek dayOfWeek,
				 Poco::Data::Time startTime,
				 Poco::Data::Time endTime);

	/**
	 * \brief Constructs an object of BlockCourse with parameters stored in a
	 * std::vector<std::string>
	 * @param [in] params Vector list of the parameters for initializing all
	 * instance members
	 * <table style="width:70%" border=1px solid black>
	 * <tr>
	 *	<th>Patameter Position</th> <th>Descriptions</th>
	 * </tr>
	 * <tr>
	 * <th>param[0]</th> <td>course type</td>
	 * </tr>
	 * <tr>
	 * <th>param[1]</th> <td>courseKey.</td>
	 * </tr>
	 * <tr>
	 * <th>param[2]</th> <td>course title.</td>
	 * </tr>
	 * <tr>
	 * <th>param[3]</th> <td>course major.</td>
	 * </tr>
	 * <tr>
	 * <th>param[4]</th> <td>course credit points.</td>
	 * </tr>
	 * <tr>
	 * <th>param[5]</th> <td>Day of week (SUN - SAT).</td>
	 * </tr>
	 * <tr>
	 * <th>param[6]</th> <td>start hour.</td>
	 * </tr>
	 * <tr>
	 * <th>param[7]</th> <td>start minute.</td>
	 * </tr>
	 * <tr>
	 * <th>param[8]</th> <td>end hour.</td>
	 * </tr>
	 * <tr>
	 * <th>param[9]</th> <td>end minute.</td>
	 * </tr>
	 * </table>
	 */
	WeeklyCourse(std::vector<std::string> params);

	/**
	 * String cast operator.
	 * @return A string representation of WeeklyCourse.
	 */
	operator std::string() const override;

	/**
	 * Writes to a specified std::ostream object.
	 * @param [in] out Reference to the ostream object to be written to.
	 */
	void write(std::ostream &out) const override;
};

#endif /* WEEKLYCOURSE_H_ */
