/*  
C867-Scripting and Programming: Applications
Language: C++
David Sainvilus
StudentID: 001049272
*/


#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include "Student.h"
#include "Degree.h"
#include "Roster.h"

using namespace std;


Roster::Roster() {}


//Updating the classRosterArray
void Roster::add(string studID, string fiName, string laName, string emAddr, int a, int day0, int day1, int day2, Degree degree) {
	int nmDaysIn[] = { day0, day1, day2 };
	if (degree == Degree::NETWORKING) {
		classRosterArray[addIndex++] = new Student(studID, fiName, laName, emAddr, a, nmDaysIn, degree);
	}
	if (degree == Degree::SECURITY) {
		classRosterArray[addIndex++] = new Student(studID, fiName, laName, emAddr, a, nmDaysIn, degree);
	}
	if (degree == Degree::SOFTWARE) {
		classRosterArray[addIndex++] = new Student(studID, fiName, laName, emAddr, a, nmDaysIn, degree);
	}
}


//2printing entire roster
void Roster::printAll() {
	cout << "Displaying all students:" << endl;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr) {
			(*classRosterArray[i]).print();
		}
	}
	cout << endl;
}

//3 Checking Emails and displayign invalid ones
void Roster::printBadEmails() {
	cout << "Displaying invalid emails:" << endl;
	cout << endl;
	for (int i = 0; i < 5; i++) {
		bool foundCharAt = false;
		bool foundCharPeriod = false;
		bool foundCharSpace = false;
		string email = "";
		email = (*classRosterArray[i]).getEmailAddress();
		for (char& c : email) {
			if (c == '@') {
				foundCharAt = true;
			}
			if (c == '.') {
				foundCharPeriod = true;
			}
			if (c == ' ') {
				foundCharSpace = true;
			}
		}
		if (foundCharAt == false || foundCharPeriod == false || foundCharSpace == true) {
			cout << (*classRosterArray[i]).getEmailAddress() << endl;
		}
	}
	cout << endl;
}

//4 printing the average days it took to complete 3 courses
void Roster::printnumDays(string studentID) {
	for (int i = 0; i < 5; i++) {
		if ((*classRosterArray[i]).getStudentID() == studentID) {
			int avg = 0;
			avg = ((*classRosterArray[i]).getNumDays()[0] + (*classRosterArray[i]).getNumDays()[1]
				+ (*classRosterArray[i]).getNumDays()[2]) / 3;
			cout << "The average days it took the student with studentID: " << studentID << " to finish 3 courses: " << avg << '\n';
		}
	}
	cout << '\n';
}

//5 Printing studnts who are in a specific degree program
void Roster::printByDegree(string degree) {
	 Degree testDeg = Degree::SOFTWARE;
	 
	 if (degree == "SECURITY") {
		 testDeg = Degree::SECURITY;
		 cout << "Showing students in the Security degree:" << endl;
	 }
	 if (degree == "NETWORKING") {
		testDeg = Degree::NETWORKING;
		cout << "Showing students in the Networking degree:" << endl;
	 }
	 if (degree == "SOFTWARE") {
		testDeg = Degree::SOFTWARE;
		cout << "Showing students in the Software degree:" << endl;
	 }
	 cout << endl;
	 for (int i = 0; i < 5; i++) {
		 if (testDeg == (*classRosterArray[i]).getDegree()) {
			(*classRosterArray[i]).print();
		 }
	 }
	 cout << '\n';
}



//6Removing student from the roster by Student ID
void Roster::remove(string studentID) {
	bool removed = false;
	cout << "Removing " << studentID <<"..."<< '\n';
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != NULL) {
			if (studentID == classRosterArray[i]->getStudentID()) {
				classRosterArray[i] = nullptr;
				removed = true;
				cout << studentID << " Removed" << endl;
			}
		}
	}

	if (!removed) {

		cout << "The student with the ID: " << studentID << " was not found." << '\n';
	}
}

//Deconstructor
Roster::~Roster()
{
	for (int i = 0; i < 5; i++)
	{
		delete classRosterArray[i];
	}
}
