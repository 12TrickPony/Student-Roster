#include <iostream>
#include <string>
#include <iomanip>

#include "Student.h"

using namespace std;


string Student::getStudentID() const {
	return studentID;
}

string Student::getFirstName() const {
	return firstName;
}

string Student::getLastName() const {
	return lastName;
}

string Student::getEmailAddress() const {
	return emailAddress;
}

int Student::getAge() const {
	return age;
}

string Student::getDegree() const 
{
	return degree;
}

DegreeProgram Student::getDegreeProgram() const 
{
	return degreeProgram;
}

void Student::getDaysInCourse() const 
{
	cout << right 
		<< "(" << numDaysInCourse[0] 
		<< ", " << numDaysInCourse[1] 
		<< ", " << numDaysInCourse[2] << ")" 
		<< left << setw(13) << " ";
}


void Student::setStudentID(string inputStudentID)
{
	studentID = inputStudentID;
}

void Student::setFirstName(string inputFirstName)
{
	firstName = inputFirstName;
}

void Student::setLastName(string inputLastName)
{
	lastName = inputLastName;
}

void Student::setEmailAddress(string inputEmailAddress)
{
	emailAddress = inputEmailAddress;
}

void Student::setAge(int inputAge)
{
	age = inputAge;
}


void Student::setDegreeProgram()
{
	if (degree == "SECURITY") {
		degreeProgram = DegreeProgram::SECURITY;
	}
	else if (degree == "NETWORK") {
		degreeProgram = DegreeProgram::NETWORK;
	}
	else if (degree == "SOFTWARE") {
		degreeProgram = DegreeProgram::SOFTWARE;
	}
}

void Student::setDaysInCourse(int inputDays1, int inputDays2, int inputDays3) 
{
	numDaysInCourse[0] = inputDays1;
	numDaysInCourse[1] = inputDays2;
	numDaysInCourse[2] = inputDays3;
}

void Student::setDegree(string inputDegree) 
{
	degree = inputDegree;
}


Student::Student(string inputStudentID, string inputFirstName, string inputLastName, string inputEmailAddress, int inputAge, int days1, int days2, int days3, string inputDegree) 
{
	studentID = inputStudentID;
	firstName = inputFirstName;
	lastName = inputLastName;
	emailAddress = inputEmailAddress;
	age = inputAge;
	numDaysInCourse[0] = days1;
	numDaysInCourse[1] = days2;
	numDaysInCourse[2] = days3;
	degree = inputDegree;
	setDegreeProgram();
}


void Student::print() const
{
	cout << left
		<< setw(12)
		<< getStudentID()
		<< setw(15)
		<< getFirstName()
		<< setw(15)
		<< getLastName()
		<< setw(25)
		<< getEmailAddress()
		<< setw(5)
		<< getAge();
	getDaysInCourse();
	cout << left << setw(23)
		<< getDegree();
	cout << endl;
};
