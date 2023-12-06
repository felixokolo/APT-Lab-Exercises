// Standard (system) header files
#include <iostream>
#include <cstdlib>

#include "SetOfMeasurementValues.h"

using namespace std;

// Main program
int main ()
{
    SetOfMeasurementValues myVoltageValues("myVoltageValues", V);
    myVoltageValues.setValue(1, 10);
    myVoltageValues.setValue(3, 20);
    myVoltageValues.print();
    myVoltageValues.setValue(30, 20);
    myVoltageValues.getValue(77);
    SetOfMeasurementValues myCurrentValues("myCurrentValues", A);
    myCurrentValues.setRandomValues(0, 1);
    myCurrentValues.print();
	return 0;
}
