#pragma once
// TODO: student declaration
#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iostream>
using namespace std;
class Student
{
public:
	// TODO: Student constructor should set name and gpa and have default parameters
	Student(string name, float gpa);
	// TODO: getName
	string getName();
	// TODO: getGpa
	float getGpa();
	// TODO: setName
	void setName(string newName);
	// TODO: setGpa
	void setGpa(float newGpa);
	// TODO: overload insertion operator for Student
	friend ostream& operator << (ostream& sout, const Student& student);
private:
	string name;
	float gpa;
};
#endif
