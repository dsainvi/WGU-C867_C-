/* 
C867-Scripting and Programming: Applications
Language: C++
David Sainvilus
StudentID: 001049272
*/

#include <iostream>
#include <string>
#include "Student.h"
#include "Degree.h"


using namespace std;

// default constructor definition
/*Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	this->numDays[0] = (int)0;
	this->numDays[1] = (int)1;
	this->numDays[2] = (int)2;
	this->degree = Degree::SECURITY;
	
}
*/
Student::Student(string studID, string fiName, string laName, string emAddr, int a, int* nmDays, Degree degree)
{
	this->studentID = studID;
	this->firstName = fiName;
	this->lastName = laName;
	this->emailAddress = emAddr;
	this->age = a;
	this->numDays[0] = nmDays[0];
	this->numDays[1] = nmDays[1];
	this->numDays[2] = nmDays[2];
	this->degree = degree;
}


string Student::getStudentID() {
	return studentID;
}

void Student::setStudentID(string studID) {
	studentID = studID;
	//studentID = studID;
}

string Student::getFirstName()
{
	return firstName;
}

void Student::setFirstName(string fiName)
{
	firstName = fiName;
}

string Student::getLastName()
{
	return lastName;
}

void Student::setLastName(string laName)
{
	lastName = laName;
}

string Student::getEmailAddress()
{
	return emailAddress;
}
void Student::setEmailAddress(string emAddr)
{
	emailAddress = emAddr;
}

int Student::getAge()
{
	return age;
}

void Student::setAge(int a)
{
	age = a;
}

int* Student::getNumDays() {
	return numDays;
}

void Student::setNumDays(int day0, int day1, int day2)
{
	numDays[0] = day0;
	numDays[1] = day1;
	numDays[2] = day2;
}


Degree Student::getDegree()
{
	return degree;
}


void Student::setDegree(Degree degree)
{
	this->degree = degree;
}



//Student::Student() {}

void Student::print() {
	cout << "StudentID:" << getStudentID() << "\t" << " First Name:" << getFirstName() << "\t" << " Last Name:" << getLastName() << "\t" << "Age:" << getAge() << "\t" << " daysInCourse:{"; cout << getNumDays()[0] << "," << getNumDays()[1] << "," << getNumDays()[2] << "}";
	cout <<"Degree:"<< degreeTypeStrings[this->getDegree()]<<endl;
}

// default deconstructor definition
Student::~Student()
{

}
