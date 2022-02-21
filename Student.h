#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

#include "Degree.h"

using namespace std;

// CREATE STUDENT CLASS
class Student 
{
public:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	DegreeProgram degreeProgram;
	string degree;
	int numDaysInCourse[3];
	
	string getStudentID() const;
	string getFirstName() const;
	string getLastName() const;
	string getEmailAddress() const;
	int getAge() const;
	void getDaysInCourse() const;
	string getDegree() const;
	DegreeProgram getDegreeProgram() const;

	void setStudentID(string inputStudentID);
	void setFirstName(string inputFirstName);
	void setLastName(string inputLastName);
	void setEmailAddress(string inputEmailAddress);
	void setAge(int inputAge);
	void setDaysInCourse(int inputDays1, int inputDays2, int inputDays3);
	void setDegree(string inputDegree);
	void setDegreeProgram();

	Student(string inputstudentID, string inputfirstName, string inputlastName, string inputEmailAddress,
		int inputAge, int days1, int days2, int days3, string inputDegree);

	void print() const;
};
#endif
