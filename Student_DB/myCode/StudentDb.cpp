/*
 * StudentDb.cpp
 *
 *  Created on: 11 Jan 2024
 *      Author: FELIX WORKSTATION
 */

#include "StudentDb.h"

using namespace std;

//Default Constructor.
StudentDb::StudentDb()
{
	// Do nothing
}

bool StudentDb::addBlockCourse(unsigned int courseKey, std::string title,
						  std::string major, float creditPoints,
						  Poco::Data::Date startDate,
						  Poco::Data::Date endDate,
						  Poco::Data::Time startTime,
						  Poco::Data::Time endTime)
{
	// Create a unique pointer to a new BlockCourse object.
	unique_ptr<BlockCourse> blockCourse =
		std::unique_ptr<BlockCourse>(new BlockCourse(courseKey, title, major,
													 creditPoints, startDate,
													 endDate, startTime,
													 endTime));
	// Add new Course to courses.
	courses[blockCourse->getCourseKey()] = std::move(blockCourse);
	return true;
}

bool StudentDb::addWeeklyCourse(unsigned int courseKey, std::string title,
	   	 std::string major, float creditPoints,
		 Poco::DateTime::DaysOfWeek dayOfWeek,
		 Poco::Data::Time startTime,
		 Poco::Data::Time endTime)
{
	// Create a unique pointer to a new WeeklyCourse object.
	unique_ptr<WeeklyCourse> weeklyCourse =
		std::unique_ptr<WeeklyCourse>(new WeeklyCourse
									  (courseKey, title,
									   major,creditPoints,
									   Poco::DateTime::DaysOfWeek(dayOfWeek),
									   startTime, endTime));
	// Add new Course to courses.
	courses[weeklyCourse->getCourseKey()] = std::move(weeklyCourse);
	return true;
}


int StudentDb::addStudent(std::string firstName, std::string lastName,
						  // Date of Birth params
						  int day, int month, int year,
						  // Address params
						  std::string street, unsigned short postalCode,
						  std::string cityName, std::string additionalInfo)
{
	// Create Student object to be added
	Student student(firstName, lastName);
	student.setDateOfBirth(day, month, year);
	student.setAddress(street, postalCode, cityName, additionalInfo);

	int matrikelNum = student.getMatrikelNumber();

	// Add new student to students map using matrikelNumber
	students.emplace(student.getMatrikelNumber(), move(student));
	return matrikelNum; // Return matriculation number of new student
}

bool StudentDb::courseExists(int courseKey)
{
	// If course is found in courses map
	if (courses.find(courseKey) != courses.end())
		return true;

	return false;
}


bool StudentDb::addEnrollment(int matrikelNumber, std::string semester,
							  int courseKey, float grade)
{
	Course *course;
	// Get pointer to course if course exists
	if (courseExists(courseKey))
		course = const_cast<Course*>(courses[courseKey].get());
	else
		return false;
	bool exists = false;
	exists = students.at(matrikelNumber).addEnrollment(semester, course, grade);
	return exists;
}

bool StudentDb::studentExists(int matrikelNumber)
{
	// If a student with matrikel number is found.
	if (students.find(matrikelNumber) != students.end())
		return true;
	return false;
}


std::string StudentDb::getStudent(int matrikelNumber)
{
	// Return string representation of of student.
	return (string) students.at(matrikelNumber);
}



string StudentDb::searchStudents(std::string keyword)
{
	// Create temporal string stream object
	stringstream result;

	// Iterate through students and find all student with name containing
	// the specified keyword
	for (auto studentPair = students.begin();
		 studentPair != students.end(); studentPair++)
	{
		// Get full name of the current student
		string toSearch = studentPair->second.getName();

		// convert both the full name and keyword to lower case for uniformity
		transform(toSearch.begin(), toSearch.end(), toSearch.begin(),
				[](unsigned char c){return tolower(c);});
		transform(keyword.begin(), keyword.end(), keyword.begin(),
				[](unsigned char c){return tolower(c);});

		// Check if keyword is contained in the full name
		if (toSearch.find(keyword) != string::npos)
		{
			// Write Matrikel number and full name to string stream
			result << studentPair->second.getMatrikelNumber() << "\t\t"
				   << studentPair->second.getName() << "\n";
		}

	}

	return result.str();
}

//Lists all the courses in a string
std::string StudentDb::listCourses()
{
	// Create temporal string stream object
	stringstream stream;

	// Iterate through Courses and write their string representation to
	// string stream
	// coursePair is map<int, unique_ptr<const Course>>::iterator type
	for (auto coursePair = courses.begin();
		 coursePair != courses.end();
		 coursePair++)
	{
		stream << (string) *(coursePair->second);
	}

	return stream.str();
}

// Update different attributes of a student
bool StudentDb::updateStudent(int matrikelNum, StudentUpdate type,
							  std::vector<std::string> params)
{
	// Switch through all the possible types of update
	switch (type)
	{
	case STUDENT_NAME: // Update Student names
		students.at(matrikelNum).setNames(params[0], params[1]);
		break;

	case STUDENT_DOB: // Update Student date of birth
		students.at(matrikelNum).setDateOfBirth(stoi(params[0]),
												stoi(params[1]),
												stoi(params[2]));
		break;

	case STUDENT_ADDRESS: // Update student address
		students.at(matrikelNum).setAddress(params[0], stoi(params[1]),
											params[2], params[3]);
		break;

	case STUDENT_ENROLLMENT_GRADE: // Update enrollment grade
		students.at(matrikelNum).setEnrollmentGrade(stoi(params[0]),
													stof(params[1]));
		break;

	case DELETE_STUDENT_ENROLLMENT: // Remove an enrollment
		students.at(matrikelNum).deleteEnrollment(stoi(params[0]));
		break;

	}
	return true;
}

// Get string list of all enrollments of a student
std::string StudentDb::getStudentEnrollments(int matrikelNum)
{
	return students.at(matrikelNum).listEnrollments();
}

// Write DB string representation to output stream
void StudentDb::write(std::ostream &out)
{
	// Starting with Courses

	// Get and write the number of courses in database
	out << courses.size() << '\n';
	// Loop through courses and write string representation to stream
	for (auto &coursePair : courses)
	{
		coursePair.second->write(out);
		out << '\n';
	}


	// Go through all student objects

	// To count the number of enrollment objects in all students
	int enrollNum = 0;
	out << students.size() << '\n';

	// Temporary string stream to store all strings to be written to DB.
	stringstream stream;

	// Loop through students, write serialized string objects to output stream
	// Also keep get serialized string objects for enrollments into stream var
	for (auto &student : students)
	{
		// Write student objects to output stream. Addresses are also written.
		student.second.write(out);
		out << '\n';

		int eSize = student.second.getEnrollments().size();
		// Get enrollment records for each student into string stream
		if (eSize > 0)
		{
			enrollNum += eSize; // Keep track of total number of enrollments
			auto &enrollment = student.second.getEnrollments();
			// Loop through student enrollments
			for (auto itr = enrollment.begin(); itr != enrollment.end(); itr++)
			{
				// Write matriculation number first
				stream << student.second.getMatrikelNumber() << ';';
				itr->write(stream); // then write enrollment object
				stream << '\n';
			}
		}

	}

	out << enrollNum << '\n';
	// Finally, write the combined enrollments into output stream
	out << stream.str();
}

void StudentDb::read(std::istream &in)
{
	courses.clear(); // Delete all courses records.
	students.clear(); // Delete all Student records
	string line;

	// classPos tracks the class type
	// 1 -> Course
	// 2 -> Student and Address
	// 3 -> Enrollment
	int classPos = 0;
	int objectNum = 0;
	// Read lines from the database file
	getline(in,  line);
	do
	{
		// Classes are processed in the following order
		// Courses -> Students + Address -> Enrollments

		// Checks if the current line contains only a number which indicates
		// the beginning of a class.
		if (all_of(line.begin(), line.end(), ::isdigit))
		{
			classPos++; // Go to the next class

			if (objectNum != 0)
				// number of objects in database incorrect.
				throw runtime_error("Error parsing DB contents");

			objectNum = stoi(line);
			continue; // No processing required
		}

		vector<string> params =
					splitLine(line,
							// lambda function that compares delimiters to
							// determine splitting points
							  [](char c) -> bool{
								  return (c == ';')||
										 (c == '-')||
										 (c==':');
								  });

		switch (classPos)
		{
		case 0:
			break;

		case 1: // Adding Courses into DB
		{
			char courseType = params[0].c_str()[0];

			switch (courseType)
			{
			case 'W': // WeeklyCourse Processing
			{
				std::unique_ptr<WeeklyCourse> weeklyCourse =
						std::unique_ptr<WeeklyCourse>(new WeeklyCourse(params));
				courses[weeklyCourse->getCourseKey()] = std::move(weeklyCourse);

			break;
			}

			case 'B': // BlockCourse Processing
			{
				std::unique_ptr<BlockCourse> blockCourse =
						std::unique_ptr<BlockCourse>(new BlockCourse(params));

				courses[blockCourse->getCourseKey()] = std::move(blockCourse);
			break;
			}

			}

		break;
		}

		case 2: // Student and Address Processing
		{
			// Create a student object in-place using params.
			students.emplace(stoi(params[0]), params);
		break;
		}

		case 3: // Enrollment Processing
			addEnrollment(stoi(params[0]), params[1], stoi(params[2]),
					stof(params[3]));
			break;
		}
		objectNum--; // Keep track of the number of objects added
	}
	while (getline(in,  line)); // Read next line
}

std::vector<std::string> StudentDb::splitLine(std::string line,
		std::function<bool(char)> ops)
{
	vector<string> result; // Parameters storage
	stringstream stream;
	bool ignore = false; // Tracks the beginning and end of a string parameter
	for (char s : line)
	{
		if (s == '"') // Beginning or end of a string parameter
		{
			// XOR logic.
			// Flips to true at the start of a string and false at the end of
			// a string parameter
			ignore = ignore != true;
			continue; // No processing required
		}
		// If a delimiter outside a string parameter is encountered, this
		// indicates the end of a parameter
		if (ops(s) && !ignore) // Checks for delimiters
		{
			// Writes found parameter into result vector
			result.push_back(stream.str());
			stream.str(""); // Clear stream
		}
		else
			stream << s; // Saves parameter character
	}
	result.push_back(stream.str()); // Last found parameter
	return result;
}

bool StudentDb::readFromServer(int n)
{
	// Create a socket address object with host address and port.
	const Poco::Net::SocketAddress sockAdd(serverHostAddress, serverPort);
	// Create Socket stream using a stream socket bound to the sockAdd
	Poco::Net::StreamSocket streamSock(sockAdd);


	while (n > 0)
	{
		Poco::Net::SocketStream sockStream{streamSock};
		// Send generate command to server
		sockStream << "generate\n";
		sockStream.flush();

		string buff; // To store received bytes packets
		stringstream stream; // To hold entire packets

		int status;
		int i;

		sockStream >> status;
		if (status == 100) // check if command received by server.
			do
			{
				sockStream >> buff;
				if (buff == "Generating") // Check beginning of response
					continue;
				if (buff == "200") // Check for end of response.
					break;
				stream << buff;
				i++;
			}
			// Extra end of response checks to prevent infinite loop.
			while (buff.find("generated") == buff.npos && i < 1024);
		string response = stream.str();

		// Create JSON Parser object and parse response
		// to extract student details
		Poco::JSON::Parser parser;
		Poco::Dynamic::Var res = parser.parse(response);

		Poco::JSON::Object::Ptr obj = res.extract<Poco::JSON::Object::Ptr>();

		std::vector<std::string> parame = {};
		parame.push_back("0");
		Poco::DynamicStruct ds = *obj; // Dynamic structure to access values

		// Get Student names
		parame.push_back(ds["name"]["firstName"]);
		parame.push_back(ds["name"]["lastName"]);

		// Get Student date of birth
		parame.push_back(ds["dateOfBirth"]["date"]);
		parame.push_back(ds["dateOfBirth"]["month"]);
		parame.push_back(ds["dateOfBirth"]["year"]);

		// Get Student address
		parame.push_back(ds["location"]["street"]);
		parame.push_back(ds["location"]["postCode"]);
		parame.push_back(ds["location"]["city"]);
		parame.push_back(ds["location"]["state"]);


		// Exceptions due to invalid date numbers and other invalid parameters
		// such as post code
		try
		{
			// !!! Creating the student object using the parameters from sever
			// does not chect the validity of the names so that for example
			// a Chinese name 台至强 can be created.
			Student student(parame);
			int matrikelNummer = student.getMatrikelNumber();
			cout << "Adding " << student.getName() << endl;
			students.emplace(matrikelNummer, move(student));
		} catch (exception &e)
		{
			continue;
		}

		n--;
		if (n == 0)
		{
			// close connection
			sockStream << "quit\n";
			sockStream.flush();
		}

	}
	cout << "\nStudents added successfully" << endl;

	return false;
}
