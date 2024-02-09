/*
 * BlockCourse.h
 *
 *  Created on: 11 Jan 2024
 *      Author: FELIX WORKSTATION
 */

#ifndef BLOCKCOURSE_H_
#define BLOCKCOURSE_H_

#ifndef POCOFORMAT
#define POCOFORMAT Poco::DateTimeFormatter
#endif

#include <Poco/Data/Date.h>
#include <Poco/Data/Time.h>

#include"Course.h"

/**
 * \brief  Class describing a block course which occurs only within a
 * specified period of time.
 */
class BlockCourse : public Course
{
private:
	/**
	 * \brief Start date of BlockCourse
	 */
	Poco::Data::Date startDate;
	/**
	 * \brief End date of BlockCourse
	 */
	Poco::Data::Date endDate;
	/**
	 * \brief Start time of BlockCourse
	 */
	Poco::Data::Time startTime;
	/**
	 * \brief End time of BlockCourse
	 */
	Poco::Data::Time endTime;

public:
	/**
	 * \brief Constructs an object of BlockCourse with parameters stored in a
	 * std::vector<std::string>
	 * @param [in] params Vector list of the parameters for initializing all
	 * instance members.
	 *
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
	 * <th>param[5]</th> <td>start day.</td>
	 * </tr>
	 * <tr>
	 * <th>param[6]</th> <td>start month.</td>
	 * </tr>
	 * <tr>
	 * <th>param[7]</th> <td>start year.</td>
	 * </tr>
	 * <tr>
	 * <th>param[8]</th> <td>end day.</td>
	 * </tr>
	 * <tr>
	 * <th>param[9]</th> <td>end month.</td>
	 * </tr>
	 * <tr>
	 * <th>param[10]</th> <td>end year.</td>
	 * </tr>
	 * <tr>
	 * <th>param[11]</th> <td>start hour.</td>
	 * </tr>
	 * <tr>
	 * <th>param[12]</th> <td>start minute.</td>
	 * </tr>
	 * <tr>
	 * <th>param[13]</th> <td>end hour.</td>
	 * </tr>
	 * <tr>
	 * <th>param[14]</th> <td>end minute.</td>
	 * </tr>
	 * </table>
	 */
	BlockCourse(std::vector<std::string> params);

	/**
	 * \brief Constructs an object of BlockCourse from parameters entered.
	 * @param [in] courseKey see Course::courseKey
	 * @param [in] title see Course::title
	 * @param [in] major see Course::major
	 * @param [in] creditPoints see Course::creditPoints
	 * @param [in] startDate Start date of course.
	 * @param [in] endDate End date of block course
	 * @param [in] startTime Start time of block course
	 * @param [in] endTime End time of block course.
	 */
	BlockCourse(unsigned int courseKey, std::string title,
			    std::string major, float creditPoints,
				Poco::Data::Date startDate,
				Poco::Data::Date endDate,
				Poco::Data::Time startTime,
				Poco::Data::Time endTime);

	/**
	 * \brief String cast operator.
	 * @return A string representation of BlockCourse.
	 */
	operator std::string() const override;

	/**
	 * \brief Writes data members to a specified std::ostream object.
	 * Data members are written in the specified format;
	 *
	 * B;Course::courseKey;\"Course::title\";\"Course::major\";
	 * Course::creditPoints;BlockCourse::startDate(dd-mm-yyy);
	 * BlockCourse::endDate(dd-mm-yyy);BlockCourse::startTime(HH:MM);
	 * BlockCourse::endTime(HH:MM)
	 * @param [in] out Reference to the ostream object to be written to.
	 */
	void write(std::ostream &out) const override;

};

#endif /* BLOCKCOURSE_H_ */
