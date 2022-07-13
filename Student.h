/*
C867-Scripting and Programming: Applications
Language: C++
David Sainvilus
StudentID: 001049272
*/

#pragma once
#include <string>
#include "Degree.h"

using namespace std;

class Student
{

public:

	//constructor
	//Student();


	Student(string studID, string fiName, string laName, string emAddr, int a, int* nmDays, Degree degree);

	//accessors for each instance variable
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getNumDays();
	Degree getDegree();


	//mutator for each instance variable
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setNumDays(int day0, int day1, int day2);
	void setDegree(Degree degree);
	void print();
	

	//Deconstructor
	~Student();

	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int numDays[3];
	Degree degree;
};

