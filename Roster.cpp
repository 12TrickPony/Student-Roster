#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

#include "Student.h"
#include "Roster.h"

//TASK E.2a,b
void Roster::parseTable(string const studentDataTable[], int numStudents)
{
	for (int i = 0; i < numStudents; i++)
	{
		string table_str = studentDataTable[i];
		vector<string> tableValue;
		stringstream str_stream(table_str);

		while (str_stream.good())
		{
			string substr;
			getline(str_stream, substr, ',');
			tableValue.push_back(substr);
		}
		add(tableValue.at(0),
			tableValue.at(1),
			tableValue.at(2),
			tableValue.at(3),
			stoi(tableValue.at(4)),
			stoi(tableValue.at(5)),
			stoi(tableValue.at(6)),
			stoi(tableValue.at(7)),
			tableValue.at(8), i);
	}
}

// TASK E.3a
void Roster::add(string studentId, string firstName, string lastName, string emailAddress, int age, int numDays1, int numDays2, int numDays3, string inputDegree, int i)
{
	classRosterArray[tableSize++] = new Student(studentId, firstName, lastName, emailAddress, age, numDays1, numDays2, numDays3, inputDegree);
}

// TASK E.3.b
void Roster::remove(string inputStudentID)
{
	bool sIDfound = false;

	for (int i = 0; (i < tableSize) && !sIDfound; ++i)
	{
		if (classRosterArray[i]->getStudentID() == inputStudentID)
		{
			delete classRosterArray[i];
			classRosterArray[i] = classRosterArray[i+1];
			classRosterArray[i+1] = classRosterArray[i + 2];
			--tableSize;
			sIDfound = true;
		}
	}
	if (sIDfound)
	{
		cout << "Student ID " << inputStudentID << " Found" << endl;
		cout << "Student ID " << inputStudentID << " Removed" << endl;
	}
	else
	{
		cout << "Student ID Not Found!" << endl;
	}

}

// TASK E.3c
void Roster::printAll() {
	cout << left 
		<< setw(12) 
		<< "STUDENT ID" 
		<< setw(15) 
		<< "FIRST NAME" 
		<< setw(15)
		<< "LAST NAME" 
		<< setw(25) 
		<< "EMAIL ADDRESS" 
		<< setw(5) 
		<< "AGE" 
		<< setw(25) 
		<< "COURSE COMPLETION DAYS" 
		<< setw(16) 
		<< "DEGREE PROGRAM";
	cout << endl;

	for (int i = 0; i < tableSize; i++) 
	{
		classRosterArray[i]->print();
	}

	cout << endl;
}

// TASK E.3d
void Roster::AvgCourseDays(string studentID) 
{
	bool found = false;
	int totalVal = 0;
	int avgVal = 0;
	int numInt = 3;

	for (int i = 0; (i < 5) && found == false; i++) 
	{
		if (classRosterArray[i]->getStudentID() == studentID) 
		{
			found = true;
			for (int d = 0; d < numInt; d++) {
				totalVal = totalVal + classRosterArray[i]->numDaysInCourse[d];
			}

		}

	}

	avgVal = totalVal / numInt;

	cout << "The average course completion days for student ID number " << studentID << " is: " << avgVal << endl;

}

// TASK E.3e
void Roster::printInvalidEmails()
{
	string validateEmail;

	for (int i = 0; i < tableSize; i++)
	{
		validateEmail = classRosterArray[i]->getEmailAddress();
		if (validateEmail.find('@') == string::npos ||
			validateEmail.find('.') == string::npos ||
			validateEmail.find(' ') != string::npos)
		{
			cout << classRosterArray[i]->getEmailAddress() << endl;
		}

	}

}

// TASK E.3f
void Roster::printByDegree(DegreeProgram inputDegreeProgram)
{
	cout << left
		<< setw(12)
		<< "STUDENT ID"
		<< setw(15)
		<< "FIRST NAME"
		<< setw(15)
		<< "LAST NAME"
		<< setw(25)
		<< "EMAIL ADDRESS"
		<< setw(5)
		<< "AGE"
		<< setw(25)
		<< "COURSE COMPLETION DAYS"
		<< setw(16)
		<< "DEGREE PROGRAM";

	cout << endl;
	for (int i = 0; i < tableSize; i++) 
	{
		if (classRosterArray[i]->getDegreeProgram() == inputDegreeProgram)
		{
			classRosterArray[i]->print();
		}
	}

}

// TASK F.5
Roster::~Roster()
{
	for (int i = 0; i < tableSize; i++)
		delete classRosterArray[i];
};
