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
#include "Student.h"
#include "Degree.h"
#include "Roster.h"

using namespace std;


int main()
{
	const string studentData[] = {
	 "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	 "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	 "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	 "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	 "A5,David,Sainvilus,dsainvi@wgu.edu,27,32,11,23,SOFTWARE"
	};

	//Creating Roster Instance
	Roster classRoster;

	// Creating Degree Instance
	Degree myDegree;

	// adding each student to the classRoster
	for (int i = 0; i < 5; i++) {
		stringstream ss(studentData[i]);

		vector<string> result;

		while (ss.good()) {
			string substr;
			getline(ss, substr, ',');
			result.push_back(substr);
		}
		if (result[8] == "NETWORK") {
			myDegree = Degree::NETWORKING;
		}
		if (result[8] == "SECURITY") {
			myDegree = Degree::SECURITY;
		}
		if (result[8] == "SOFTWARE") {
			myDegree = Degree::SOFTWARE;
		}

		classRoster.add(result[0], result[1], result[2], result[3], stoi(result[4]), stoi(result[5]),
			stoi(result[6]), stoi(result[7]), myDegree);
	}

	//print Personal Info 
	cout << "C867-Scripting and Programming: Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "StudentID: 001049272" << endl;
	cout << "Name: David Sainvilus" << endl;
	cout << endl;

	// printing all results
	classRoster.printAll();

	classRoster.printBadEmails();
	for (int i = 0; i < 5; i++)
	{
		classRoster.printnumDays(classRoster.classRosterArray[i]->getStudentID());
	}

	classRoster.printByDegree("SOFTWARE");

	classRoster.remove("A3");

	classRoster.printAll();

	classRoster.remove("A3");
}