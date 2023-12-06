// Standard (system) header files
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

#include "ModuloNDigit.h"
#include "ModuloNCounter.h"

void getParam(unsigned int &numOfDigits, unsigned int &type)
{
	cout << "Please enter parameters of your counter:" << endl;
	cout << "number of digits: ";
	cin >> numOfDigits;
	cout << "type (2/8/10/16): ";
	cin >> type;
	cout << endl;
}

void printTitle(int numOfDigits, int type)
{
	string counterName = "";

	switch (type)
	{
	case 2:
		counterName = "binary counter";
		break;
	case 8:
		counterName = "octal counter";
		break;
	case 10:
		counterName = "decimal counter";
		break;
	case 16:
		counterName = "hexadecimal counter";
		break;
	case -1:
		cout << "End of the test!";
		exit(0);
		break;
	default:
		break;
	}
	cout << numOfDigits << " digit " << counterName << endl;
}

// Main program
int main ()
{
	unsigned int numOfDigits, type;
	int newLinePos = 0;

	while (1)
	{
		getParam(numOfDigits, type);
		printTitle(numOfDigits, type);
		ModuloNCounter m1(numOfDigits, type);
		ModuloNCounter m2(numOfDigits, type);

		switch (type)
		{
		case 2:
		case 16:
			newLinePos = 16;
			break;
		case 8:
			newLinePos = 8;
			break;
		case 10:
			newLinePos = 10;
			break;

		}
		int maxCount = pow(type, numOfDigits) + 1;
		for (int i = maxCount; i >= 0; i--)
		{
			(m1++).print();
			cout << " ";
			if ((maxCount - i + 1) % newLinePos == 0) cout << endl;
		}
		cout << endl << endl;
	}
	return 0;
}
