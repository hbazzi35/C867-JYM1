#include <iostream>
#include "roster.h"
#include <regex>
using namespace std;

void Roster::parse(string studentData)
{
	DegreeProgram degreeProgram = NETWORK;
	if (studentData.at(1) == '1') degreeProgram = SECURITY;
	else if (studentData.at(1) == '4') degreeProgram = SECURITY;
	else if (studentData.at(1) == '3') degreeProgram = SOFTWARE;
	else if (studentData.at(1) == '5') degreeProgram = SOFTWARE;

	int rhs = studentData.find(",");
	string studentID = studentData.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string firstName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string lastName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string emailAddress = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int age = stod(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	double dCourse1 = stod(studentData.substr(lhs, rhs - lhs));
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	double dCourse2 = stod(studentData.substr(lhs, rhs - lhs));
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	double dCourse3 = stod(studentData.substr(lhs, rhs - lhs));

	add(studentID, firstName, lastName, emailAddress, age, dCourse1, dCourse2, dCourse3, degreeProgram);

}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, double dCourse1, double dCourse2, double dCourse3,
	DegreeProgram degreeProgram)
{
	double darr[3] = { dCourse1,dCourse2,dCourse3 };
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, darr, degreeProgram);
}

void Roster::printAll() {

	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->print();
		}
	}
}


void Roster::printByDegreeProgram(DegreeProgram  degreeProgram)
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) classRosterArray[i]->print();
	}
	cout << endl;
}

void Roster::printInvalidEmails()
{
	bool any = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		string emailAddress = (classRosterArray[i]->getEmailAddress());
		if (emailAddress.find('@') == string::npos)
		{
			any = true;
			cout << emailAddress << ": " << classRosterArray[i]->getFirstName() << endl;
		}
		else if (emailAddress.find('.') == string::npos)
		{
			any = true;
			cout << emailAddress << ": " << classRosterArray[i]->getFirstName() << endl;
		}
	}

	for (int i = 0; i <= Roster::lastIndex; i++) {
		std::string emailAddress = classRosterArray[i]->getEmailAddress();

		if (emailAddress.find(" ") != std::string::npos) 
		{
			std::cout << emailAddress << ": " << classRosterArray[i]->getFirstName() << std::endl;
		}
	}


}

void Roster::printAverageDaysInCourse(string studentID)
{
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i]->getID() == studentID)
		{
			cout << studentID << ": ";
			cout << (classRosterArray[i]->getDaysInCourse()[0]
				+ classRosterArray[i]->getDaysInCourse()[1]
				+ classRosterArray[i]->getDaysInCourse()[2]) / 3.0 << endl;
		}
	}
	cout << endl;
}

void Roster::remove(string studentID)
{
	bool success = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getID() == studentID)
		{
			success = true;
			if (i < numStudents - 1)
			{
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = temp;
			}
			Roster::lastIndex--;

		}

	}
	if (success)
	{
		cout << studentID << " has been removed from the roster." << endl << endl;
		this->printAll();
	}
	else cout << studentID << " not found in roster!" << endl << endl;
}

Roster::~Roster()
{
	cout << "Destructor Called" << endl << endl;
	for (int i = 0; i < numStudents; i++)
	{
		cout << "Destroying Student #" << i + 1 << endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}