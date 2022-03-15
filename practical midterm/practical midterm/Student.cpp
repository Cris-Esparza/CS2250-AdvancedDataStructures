// Student implementation
#include "Student.h"

// TODO: Student constructor should set name and gpa and have default parameters
Student::Student(string name, float gpa)
{
	name = " ";
	gpa = 4.0;
}

// TODO: getName
string Student :: getName()
{
	return name;
}

// TODO: getGpa
float Student::getGpa()
{
	return gpa;
}

// TODO: setName
void Student::setName(string newName)
{
	name = newName;
}

// TODO: setGpa
void Student::setGpa(float newGpa)
{
	gpa = newGpa;
}

// TODO: overload insertion operator for Student
ostream& operator << (ostream& sout, const Student& student)
{
	sout << student.name << " : " << student.gpa << endl;
	return sout;
}