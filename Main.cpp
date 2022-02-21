#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "Student.h"
#include "Roster.h"
#include "Degree.h"

using namespace std;

int main() 
{
	cout << "----------------------------------------------------------------------------------------------------------------" << endl;
	cout << "UNIVERSITY NAME HERE | COLLEGE OF IT" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------" << endl << endl;

	// TASK F.1 - STUDENT, COURSE, & PROJECT INFO HEADER
	cout << "COURSE: XXXX - SCRIPTING & PROGRAMMING: APPLICATIONS" << endl;
	cout << "ASSIGNMENT: TASK 1: CLASS ROSTER" << endl;
	cout << "CODING LANGUAGE: C++" << endl;
	cout << "STUDENT NAME: STUDENT NAME HERE" << endl;
	cout << "STUDENT ID: XXXXXXXXX" << endl << endl;

	cout << "----------------------------------------------------------------------------------------------------------------" << endl;
	cout << "CLASS ROSTER" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------" << endl << endl;


	// MODIFY STUDENT DATA TABLE
	int numStudents = 5;
	const string studentDataTable[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,First Name,Last Name,Email,Age,XX,XX,XX,SOFTWARE"
	};

	// CREATE INSTANCE IN ROSTER CLASS - classRoster
	// ADD STUDENTS TO CLASS ROSTER
	// printAll()
	Roster classRoster;
	classRoster.parseTable(studentDataTable, numStudents);
	classRoster.printAll();

	// PRINT INVALID EMAILS
	cout << "----------------------------------------------------------------------------------------------------------------" << endl;
	cout << "INVALID EMAIL ADDRESSES DETECTED" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------" << endl << endl;

	classRoster.printInvalidEmails();
	cout << endl;

	// DISPLAY AVG COURSE COMPLETION DAYS
	cout << "----------------------------------------------------------------------------------------------------------------" << endl;
	cout << "AVERAGE COURSE COMPLETION DAYS PER STUDENT" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------" << endl << endl;

	for (int i = 0; i < numStudents; i++)
	{
		classRoster.AvgCourseDays(classRoster.classRosterArray[i]->getStudentID());
	}
	cout << endl;

	// PRINT BY DEGREE PROGRAM
	cout << "----------------------------------------------------------------------------------------------------------------" << endl;
	cout << "STUDENTS ENROLLED IN THE SOFTWARE DEGREE PROGRAM" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------" << endl << endl;

	classRoster.printByDegree(DegreeProgram::SOFTWARE);
	cout << endl;

	// REMOVE STUDENT FROM CLASS ROSTER
	cout << "----------------------------------------------------------------------------------------------------------------" << endl;
	cout << "STUDENT REMOVAL FROM ROSTER" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------" << endl << endl;

	cout << "Find & Remove Student ID: A3" << endl;
	classRoster.remove("A3");
	cout << endl;

	// PRINT UPDATED CLASS ROSTER
	cout << "----------------------------------------------------------------------------------------------------------------" << endl;
	cout << "UPDATED CLASS ROSTER" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------" << endl << endl;

	classRoster.printAll();
	cout << endl;

	// VERIFY STUDENT REMOVAL FROM ROSTER
	cout << "----------------------------------------------------------------------------------------------------------------" << endl;
	cout << "REMOVAL VERIFICATION" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------" << endl << endl;

	cout << "Find & Remove Student ID: A3" << endl;
	classRoster.remove("A3");
	cout << endl;

	cout << "----------------------------------------------------------------------------------------------------------------" << endl;
	cout << "END OF PROGRAM" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------" << endl;

};
