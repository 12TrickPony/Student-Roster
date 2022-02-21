#pragma once
#ifndef ROSTER_H
#define ROSTER_H

#include <iostream>
#include <string>
#include <vector>

#include "Student.h"
#include "Degree.h"

using namespace std;

// TASK E.1 - CREATE ROSTER CLASS
class Roster 
{
public:
	Student* classRosterArray[5];
	int tableSize = 0;

	void parseTable(string const studentData[], int numStudents);

	void add(string studentId, string firstName, string lastName, string emailAddress, int age, int numDays1, int numDays2, int numDays3, string inputDegree, int i);
	void remove(string studentID);
	void printAll();
	void AvgCourseDays(string studentID);
	void printInvalidEmails();
	void printByDegree(DegreeProgram inputDegreeProgram); 

	~Roster();
};
#endif