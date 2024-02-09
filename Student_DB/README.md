# Student Database Project

## Summary
This is a simple implementation of a typical database capable of creating
student, courses and course enrollment records. The project consists of 7
classes namely.
* SimpleUI class - This is at the top most level. It creates a console based
user interface for the interaction with the database. It achieves this by
implementing several user commands as follows;

<table style="width:70%" border=1px solid black>
	<tr>
		<th>Commands</th> <th>Descriptions</th>
	</tr>
	<tr>
		<th>1</th> <td>Add new Course</td>
	</tr>
	<tr>
		<th>2</th> <td>List courses</td>
	</tr>
	<tr>
		<th>3</th> <td>Add new student</td>
	</tr>
	<tr>
		<th>4</th> <td>Add enrollment</td>
	</tr>
	<tr>
		<th>5</th> <td>Print student</td>
	</tr>
	<tr>
		<th>6</th> <td>Search student</td>
	</tr>
	<tr>
		<th>7</th> <td>Update student</td>
	</tr>
	<tr>
		<th>8</th> <td>Write DB to File</td>
	</tr>
	<tr>
		<th>9</th> <td>Read File to DB</td>
	</tr>
	<tr>
		<th>10</th> <td>Add Students from Server</td>
	</tr>
	<tr>
		<th>0</th> <td>Exit</td>
	</tr>
</table>

* StudentDb class - This implements the database records and all methods
necessary for creating records, writing and reading to/from the database.

* Student Class - This is implements the basic records possibly owned by
a student such as Names, Date of Birth, Address and Enrollment records to
different Course.

* Course Class - This is an abstract representation of a basic course. It
parents 2 Classes which are WeeklyCourse and BlockCourse.

* WeeklyCourse Class - An implementation of the Course class which describes
a basic Course that occurs on a weekly basis.

* BlockCourse - An implementation of the Course class which describes a basic
Course that occurs within a short period of time.

* Address Class - This implements a basic address which a Student resides.

## Usage
The project can be used by simply creating objects of a StudentDB and a
SimpleUI using the reference to the StudentDb object as shown below;

```cpp
#include "SimpleUI.h"
StudentDb db;
SimpleUI UI(db);
```
Calling the SimpleUI::run() method starts the UI which displays all available
commands.

```cpp
UI.run();
```
