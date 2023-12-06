#include <iostream>
#include <cstdlib>
#include "Coordinate.h"

using namespace std;


int main ()
{
	Coordinate c1 (4, 4, 2);
	Coordinate c2;
	Coordinate c3 (-4);

	c1.print(CARTESIAN);
	c1.print(CYLINDER);
	c2.print(CYLINDER);

	c1.print(POLAR);
	c2.print(POLAR);
	c3.print(POLAR);

	c1.add(c3);
	c2.add(Coordinate(1, 2, 3));
	c1.print(CARTESIAN);
	c2.print(CARTESIAN);
	return 0;
}
