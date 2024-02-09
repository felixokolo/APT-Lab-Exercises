/*
 * SimpleUI.cpp
 *
 *  Created on: 11 Jan 2024
 *      Author: FELIX WORKSTATION
 */

#include "SimpleUI.h"

using namespace std;

SimpleUI::SimpleUI(StudentDb &db)
{
	this->db = &db;
}

void SimpleUI::addNewCourse()
{

	cout << courseTypeDialog << endl; // Display prompt command to user
	int command;
	cout << ">> ";
	cin >> command;
	if (command == 0)
		return; // Exit point

	// Get course key from user
	cout << "Enter Integer Course Key" << endl;
	int courseKey;
	cout << ">> ";
	cin >> courseKey;

	// Get course title
	cout << "Enter Course Title" << endl;
	string title;
	cout << ">> ";
	cin.ignore(); // Ignore newline
	getline(cin, title);

	// Get course major from user
	cout << "Enter Course Major" << endl;
	string major;
	cout << ">> ";
	getline(cin, major);

	// Get course credit points from user
	cout << "Enter Course Credit Points" << endl;
	float creditPoints;
	cout << ">> ";
	cin >> creditPoints;

	// Perform different task based on user command
	switch (command)
	{
	case 0: // Exit point
		break;
	case 1: // Add block course
		addBlockCourse(courseKey, title, major, creditPoints);
		break;
	case 2: // Add weekly course
		addWeeklyCourse(courseKey, title, major, creditPoints);
		break;

	}
}

void SimpleUI::addBlockCourse(unsigned int courseKey, string title,
		   	   	   	   	   	  string major, float creditPoints)
{
	// Get start date from user
	int day, month, year;
	cout << "Enter start date in the form DD MM YYYY" << endl;
	cout << ">> ";
	cin >> day >> month >> year;
	Poco::Data::Date startDate(year, month, day);

	// Get end date from user
	cout << "Enter end date in the form DD MM YYYY" << endl;
	cout << ">> ";
	cin >> day >> month >> year;
	Poco::Data::Date endDate(year, month, day);

	// Get start time from user
	int hr, min;
	cout << "Enter start time in the 24 Hrs form HH MM" << endl;
	cout << ">> ";
	cin >> hr >> min;
	Poco::Data::Time startTime(hr, min, 0);

	// Get end time from user
	cout << "Enter end time in the 24 Hrs form HH MM" << endl;
	cin >> hr >> min;
	Poco::Data::Time endTime(hr, min, 0);

	// Add course to DB
	bool res =
	db->addBlockCourse(courseKey, title, major,
				 creditPoints, startDate,
				 endDate, startTime,
				 endTime);

	if (res)
	cout << "Block Course " << title
		 << " added successfully" << endl;
	else
		cout << "Encountered an Error" << endl;
}

// Add weekly course
void SimpleUI::addWeeklyCourse(unsigned int courseKey, string title,
		   	   	   	   	   	  string major, float creditPoints)
{
	// Get day of week from user
	int dayOfWeek;
	cout << "Enter Weekday\n"
			"0 - SUN\n"
			"1 - MON\n"
			"2 - TUE\n"
			"3 - WED\n"
			"4 - THU\n"
			"5 - FRI\n"
			"6 - SAT\n" << endl;

	cout << ">> ";
	cin >> dayOfWeek;

	// Get start time from user
	int hr, min;
	cout << "Enter start time in the `form HH MM" << endl;
	cout << ">> ";
	cin >> hr;
	cin >> min;
	Poco::Data::Time startTime(hr, min, 0);

	// Get end time from user
	cout << "Enter end time in the 24 Hrs form HH MM" << endl;
	cout << ">> ";
	cin >> hr;
	cin >> min;
	Poco::Data::Time endTime(hr, min, 0);

	// Add Weekly course to DB
	bool res =
	db->addWeeklyCourse(courseKey, title,
					   major,creditPoints,
					   Poco::DateTime::DaysOfWeek(dayOfWeek),
					   startTime, endTime);

	if (res)
	cout << "Weekly Course " << title
		 << " added successfully" << endl;
	else
		cout << "Encountered an Error" << endl;
}

void SimpleUI::listCourses()
{
	cout << db->listCourses();
}

void SimpleUI::addStudent()
{
	// Get personal details from user
	cout << "\nPersonal Details\n"
			"----------------\n";
	cin.ignore();
	string firstName;
	cout << "Enter First Name\n";
	cout << ">> ";
	getline(cin, firstName); // Get first name

	string lastName;
	cout << "Enter Last Name\n";
	cout << ">> ";
	getline(cin, lastName); // Get last name

	int day, month, year;
	cout << "Enter Date of Birth in the form DD MM YYYY" << endl;
	cout << ">> ";
	cin >> day >> month >> year;



	// Get Student address details
	cout << "\nAddress Details\n"
			"---------------\n";

	cin.ignore();
	string street;
	cout << "Street Name\n";
	cout << ">> ";
	getline(cin, street); // Street

	unsigned short postalCode;
	cout << "Postal Code\n";
	cout << ">> ";
	cin >> postalCode; // Postal code

	cin.ignore();
	string cityName;
	cout << "City Name\n";
	cout << ">> ";
	getline(cin, cityName); // City

	string additionalInfo;
	cout << "Additional Info\n";
	cout << ">> ";
	getline(cin, additionalInfo); // Additional info

	// Add student with the obtained details to DB
	try { // Check for invalid parameters
		int matrikelNum =
				db->addStudent(firstName, lastName, day, month, year,
							   street, postalCode, cityName, additionalInfo);

		cout << "Student with Matr Num "
			 << matrikelNum << " "
			 << " successfully added" << endl;
	} catch (exception &e) {
		cout << "Error adding student to DB. Check entered details" << endl;
	}
}

void SimpleUI::addEnrollment()
{
	// Get matric number of student to which to add enrollment
	int matrikelNumber;
	cout << "Enter Matrikel Number\n";
	cout << ">> ";
	cin >> matrikelNumber;

	// Check if a student exists with such matric number
	if (db->studentExists(matrikelNumber))
	{
		// Get course key for enrollment
		cout << "Enter Course Key" << endl;
		int courseKey;
		cout << ">> ";
		cin >> courseKey;

		// Check if course exists in the DB
		 if (db->courseExists(courseKey))
		 {
			 // Get enrollment semester
			 cout << "Enter semester" << endl;
			 string semester;
			 cin.ignore();
			 cout << ">> ";
			 getline(cin, semester);

			 // Get enrollment grade
			 cout << "Enter grade" << endl;
			 float grade;
			 cout << ">> ";
			 cin >> grade;

			 // Add enrollment to student.
			 // Return value indicates if the enrollment exists already
			 bool exists =db->addEnrollment(matrikelNumber, semester,
					 courseKey, grade);
			 if (exists)
				 cout << "Warning: Enrollment already exists" << endl;
			 else
				 cout << "Enrollment added successfully" << endl;
		 }
		 else
			 cout << "No course with such Course Key" << endl;

	}
	else
		cout << "No student with such Matrikel Number" << endl;
}

void SimpleUI::printStudent()
{
	// Get matric number of student to print
	cout << "Enter Matrikel Number" << endl;
	int matrikelNumber;
	cout << ">> ";
	cin >> matrikelNumber;

	// check if Student with such matric number exists on DB
	if (db->studentExists(matrikelNumber))
	{
		// Get string details of student to be printed
		cout << db->getStudent(matrikelNumber);
	}
	else
		cout << "No student with such Matrikel Number" << endl;

}

void SimpleUI::searchStudent()
{
	// Get keyword to search
	cout << "Enter keyword to search\n";
	cin.ignore();
	string keyword;
	cout << ">> ";
	getline(cin, keyword);

	// Pass keyword to Student DB to search and return results
	string result = db->searchStudents(keyword);

	// Write results to output
	cout << "Results:\n"
			"--------------------------\n"
			"Mat Num\t\tFull Name\n"
			"--------------------------\n";
	if (result.length() == 0)
		cout << "No results found\n";
	else
		cout << result;
}

void SimpleUI::updateStudent()
{
	// Get matric number of student to update
	cout << "Enter Matrikel Number" << endl;
	int matrikelNumber;
	cout << ">> ";
	cin >> matrikelNumber;

	// Check if student exists
	if (db->studentExists(matrikelNumber))
	{
		// Display possible update options
		cout << studentUpdateCommands;
		int command;
		cout << ">> ";
		cin >> command;
		if (command == 0)
			return;

		// Switch between possible options
		switch (command)
		{
		case 0: // Exit point
			break;
		case 1: // Update Names
		{
			// Get new names
			cin.ignore();
			string firstName, lastName;
			cout << "Enter First Name\n";
			cout << ">> ";
			getline(cin, firstName); // First name

			cout << "Enter Last Name\n";
			cout << ">> ";
			getline(cin, lastName); // Last name

			// Pass new parameters in vector to Student DB for update
			db->updateStudent(matrikelNumber, STUDENT_NAME,
							  std::vector<std::string>{firstName, lastName});
			cout << "Name update successful" << endl;
			break;
		}

		case 2: // Update date of birth
		{
			// Get new date of birth
			int day, month, year;
			cout << "Enter Date of Birth in the form DD MM YYYY" << endl;
			cout << ">> ";
			cin >> day >> month >> year;

			// Pass new parameters in vector to Student DB for update
			db->updateStudent(matrikelNumber, STUDENT_DOB,
							  std::vector<std::string>{to_string(day),
													   to_string(month),
													   to_string(year)});
			cout << "Date of birth update successful" << endl;
			break;
		}
		case 3: // Update Address
		{
			// Get new address details
			string street, cityName,additionalInfo;
			cin.ignore();
			cout << "Street Name\n";
			cout << ">> ";
			getline(cin, street); // Street

			unsigned short postalCode;
			cout << "Postal Code\n";
			cout << ">> ";
			cin >> postalCode; // Post code

			cin.ignore();
			cout << "City Name\n";
			cout << ">> ";
			getline(cin, cityName); // City

			cout << "Additional Info\n";
			cout << ">> ";
			getline(cin, additionalInfo); // Additional info

			db->updateStudent(matrikelNumber, STUDENT_ADDRESS,
							  std::vector<std::string>{street,
													   to_string(postalCode),
													   cityName,
													   additionalInfo
													   }
							  );
			cout << "Address update successful" << endl;
			break;
		}
		case 4: // Update enrollment
		{
			cout << "Enter Enrollment Integer Index to update" << endl;
			cout << db->getStudentEnrollments(matrikelNumber);
			cout << "0: Cancel" << endl;
			int enrollIndex;
			cout << ">> ";
			cin >> enrollIndex;

			// Display enrollment update options.
			cout << enrollmentUpdateCommands;
			int command;
			cout << ">> ";
			cin >> command;

			// Switch through the possible options
			switch (command)
			{
			case 0: // Exit point
				break;
			case 1: // Update grade
				cout << "Enter new grade" << endl;
				float grade;
				cout << ">> ";
				cin >> grade;

				// Pass new parameters in vector to Student DB for update
				db->updateStudent
				(matrikelNumber, STUDENT_ENROLLMENT_GRADE,
				 std::vector<std::string>{
										  to_string(enrollIndex),
										  to_string(grade)});
				cout << "Grade changed successfully";
				break;
			case 2: // Delete enrollment
				// Pass new parameters in vector to Student DB for update
				db->updateStudent
				(matrikelNumber, DELETE_STUDENT_ENROLLMENT,
				 std::vector<std::string>{to_string(enrollIndex)});
				cout << "Enrollment deleted successfully" << endl;
				break;
			}
				break;
		}
		}
	}
	else
		cout << "No student with such Matrikel Number" << endl;
}

void SimpleUI::writeDB()
{
	cout << "Enter file name\n";
	string filename;
	cin.ignore();
	cout << ">> ";
	getline(cin, filename); // Get filename to write to

	// Try block in case of error accessing file system
	try {
		fstream fs(filename, fstream::out);
		db->write(fs);
		cout << "File written successfully" << endl;
	} catch (exception &e) {
		cout << "Error accessing file " << filename << endl;
	}
}

void SimpleUI::readToDB()
{

	cout << "Enter file name\n";
	string filename;
	cin.ignore();
	cout << ">> ";
	getline(cin, filename);

	// Try block in case of error accessing file system
	try {
		fstream fs(filename, fstream::in);
		db->read(fs);
		fs.close();
		cout << "DB loaded successfully" << endl;
	} catch (runtime_error &r) // Catch error thrown by DB read method
	{
		cout << r.what() << endl;
	} catch (exception &e) {
		cout << "Error accessing file " << filename << endl;
	}
}

void SimpleUI::readFromServer()
{
	cout << "Enter number of students" << endl;
	cout << ">> ";
	int n;
	cout << ">> ";
	cin >> n;
	db->readFromServer(n);
}

void SimpleUI::run()
{
	cout << welcomeMessage << endl;
	while (1)
	{
		cout << commandList << endl;
		int command;
		cout << ">> ";
		cin >> command;
		switch (command)
		{
		case 0:
			cout << "Program ended." << endl;
			exit(0);
			break;
		case 1:
			addNewCourse();
			break;
		case 2:
			listCourses();
			break;
		case 3:
			addStudent();
			break;
		case 4:
			addEnrollment();
			break;
		case 5:
			printStudent();
			break;
		case 6:
			searchStudent();
			break;
		case 7:
			updateStudent();
			break;
		case 8:
			writeDB();
			break;
		case 9:
			readToDB();
			break;
		case 10:
			readFromServer();
			break;
		}
	}
}

