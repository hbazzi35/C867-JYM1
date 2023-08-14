#include <iostream>
#include "roster.h"
#include <vector>
#include <string>
#include <sstream>


using namespace std;

int main()
{
	const string studentData[] =

	{   "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Hassan,Bazzi,bazzih3519@gmail.com,22,15,10,20,SOFTWARE"
	};

	const int numStudents = 5;
	Roster roster;

	for (int i = 0; i < numStudents; i++) roster.parse(studentData[i]);
	cout << "Students: " << endl;
	roster.printAll();
	cout << endl;

	for (int i = 0; i < 3; i++)
	{
		cout << "Student Degree Type: " << degreeProgramStrings[i] << endl;
		roster.printByDegreeProgram((DegreeProgram)i);
	}

	cout << "Students with invalid emails: " << endl;
	roster.printInvalidEmails();
	cout << endl;

	cout << "Average Days in Course: " << endl;
	for (int i = 0; i < numStudents; i++)
	{
		roster.printAverageDaysInCourse(roster.classRosterArray[i]->getID());
	}

	cout << "Removing Student with ID A3" << endl;
	roster.remove("A3");
	cout << endl;

	system("pause");
	return 0;



};

