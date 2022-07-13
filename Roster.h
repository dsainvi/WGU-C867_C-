/* 
C867-Scripting and Programming: Applications
Language: C++
David Sainvilus
StudentID: 001049272
*/

#pragma once


#include "Student.h"
//#include <array>

class Roster {
public:
	Roster();

	~Roster();

	void printAll();

	void add(string studID, string fiName, string laName, string emAddr, int a, int day0, int day1, int day2, Degree degree);

	void remove(string studentID);

	void printByDegree(string degree);

	void printnumDays(string);

	void printBadEmails();

	int addIndex = 0;

	// Declaring array of pointers
	Student *classRosterArray[5];
};
