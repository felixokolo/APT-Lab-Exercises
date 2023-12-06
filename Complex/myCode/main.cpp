// Standard (system) header files
#include <iostream>
#include <cstdlib>
// Add more standard header files as required
// #include <string>

using namespace std;

#include "Complex.h"

// Main program
int main ()
{
	Complex c1(1, -10);
	Complex c2 = c1;
	c2 = c1 + c2;
	c2.print();
	c1.print();
	c1++;
	c1.print();
	cout << c1++;
	return 0;
}
