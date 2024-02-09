#include <iostream>
#include <cstdlib>

#include "SimpleUI.h"


using namespace std;

// Main program
int main ()
{
	cout << "Student_DB started." << endl << endl;

	StudentDb db;
	SimpleUI UI(db);
	UI.run();
	return 0;
}
