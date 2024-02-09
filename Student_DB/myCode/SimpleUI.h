/*
 * SimpleUI.h
 *
 *  Created on: 11 Jan 2024
 *      Author: FELIX WORKSTATION
 */

#ifndef SIMPLEUI_H_
#define SIMPLEUI_H_

#include <iostream>
#include <fstream>
#include "StudentDb.h"

/**
 * \brief Simple UI class for accessing and modify
 */
class SimpleUI
{
private:
	/**
	 * \brief Adds new Course to SimpleUI::db
	 */
	void addNewCourse();

	/**
	 * \brief Adds a BlockCourse to SimpleUI::db
	 * @param [in] courseKey Describes the course key of the course to be added
	 * @param [in] title Describes the title of the course.
	 * @param [in] major Describes the major of the course.
	 * @param [in] creditPoints The number of credits of the course.
	 */
	void addBlockCourse(unsigned int courseKey, std::string title,
				  		std::string major, float creditPoints);

	/**
	 * \brief Adds a WeeklyCourse to SimpleUI::db
	 * @param [in] courseKey Describes the course key of the course to be added
	 * @param [in] title Describes the title of the course.
	 * @param [in] major Describes the major of the course.
	 * @param [in] creditPoints The number of credits of the course.
	 */
	void addWeeklyCourse(unsigned int courseKey, std::string title,
			   	   	   	 std::string major, float creditPoints);

	/**
	 * \brief Lists the courses present in SimpleUI::db
	 */
	void listCourses();

	/**
	 * \brief Adds new Student to SimpleUI::db
	 */
	void addStudent();

	/**
	 * \brief Adds new Enrollment to a Student in SimpleUI::db
	 */
	void addEnrollment();

	/**
	 * \brief Prints the details of a Student in SimpleUI;;db
	 */
	void printStudent();

	/**
	 * \brief Searches SimpleUI::db for a Student and prints its details.
	 */
	void searchStudent();

	/**
	 * \brief Updates a Student in SimpleUI::db
	 */
	void updateStudent();

	/**
	 * \brief Writes the contents of SimpleUI::db to a file.
	 */
	void writeDB();

	/**
	 * \brief Writes the contents of a database file to SimpleUI::db.
	 */
	void readToDB();

	/**
	 * \brief Adds Students into DB from a web server.
	 */
	void readFromServer();


private:
	/**
	 * \brief Reference to a StudentDB object.
	 */
	StudentDb *db;

	/**
	 * \brief Welcome message displayed on UI.
	 */
	const std::string welcomeMessage =
			"~~~~~~~~~~~~~~~~~~~~~~~~~\n"
			"| Welcome to student DB |.\n"
			"~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	/**
	 * \brief List of commands available on the UI.
	 */
	const std::string commandList =
			"\nEnter a command to execute.\n\n"
			"Commands|\tDescriptions\n"
			"\t|\t\n"
			"   1 \t|\tAdd new Course.\n"
			"   2 \t|\tList Courses.\n"
			"   3 \t|\tAdd new Student.\n"
			"   4 \t|\tAdd Enrollment.\n"
			"   5 \t|\tPrint Student.\n"
			"   6 \t|\tSearch Student.\n"
			"   7 \t|\tUpdate Student.\n"
			"   8 \t|\tWrite DB to File.\n"
			"   9 \t|\tRead File to DB.\n"
			"   10 \t|\tAdd Students from Server.\n"
			"   0 \t|\tExit.\n";

	/**
	 * \brief Course type dialog.
	 */
	const std::string courseTypeDialog = "Choose course type:\n"
										 "   1 \t\tAdd Block Course.\n"
										 "   2 \t\tAdd Weekly Course.\n"
										 "   0 \t\tBack.\n";

	/**
	 * \brief Dialog for student update options
	 */
	const std::string studentUpdateCommands =
			"Choose data to update:\n"
			"   1 \t\tName\n"
			"   2 \t\tDate of Birth.\n"
			"   3 \t\tAddress.\n"
			"   4 \t\tEnrollments.\n"
			"   0 \t\tCancel.\n";

	/**
	 * \brief Dialog for Enrollment object update options.
	 */
	const std::string enrollmentUpdateCommands =
			"Choose action\n"
			"   1 \t\tUpdate Grade\n"
			"   2 \t\tDelete Enrollment.\n"
			"   0 \t\tCancel.\n";
public:
	/**
	 * \brief Constructs a SimpleUI object.
	 * @param [in] db Reference to a StudentDB object.
	 */
	SimpleUI(StudentDb &db);

	/**
	 * \brief Runs the SimpleUI to execute entered commands.
	 */
	void run();
};

#endif /* SIMPLEUI_H_ */
