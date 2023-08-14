#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"

using namespace std;

class Student {
public:

	const static int daysInCourseArray = 3;

private:

	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	double daysInCourse[daysInCourseArray];
	DegreeProgram degreeProgram;

public:

	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, double daysInCourse[],
	DegreeProgram degreeProgram);
	~Student();

	string getID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	double* getDaysInCourse();
	DegreeProgram getDegreeProgram();

	void setID(string studentId);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDaysInCourse(double daysInCourse[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	static void printHeader();

	void print();

};