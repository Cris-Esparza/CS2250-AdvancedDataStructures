#include <iostream>
#include <string>
#include <vector>
#include "Student.h"
using namespace std;

// TODO: move all of these functions to the bottom and use prototypes
string promptForString(string message);
float promptForFloat(string message);
void addStudent(vector<Student>& students);
int findStudent(vector<Student>& students);
void findHighestGpa(vector<Student>& students);
void changeStudentName(vector<Student>& students);
void changeStudentGpa(vector<Student>& students);
void printStudents(vector<Student>& students);
int printMenu();

int main()
{
	int response;
	// TODO: Create a vector of students
	vector<Student> students;

	do
	{
		response = printMenu();

		// Handle the user's choice
		switch (response)
		{
		case 1:
			// Add a student to the collection
			addStudent(/* pass the vector of students */ students);
			break;
		case 2:
			// Find a student in the collection
			findStudent(/* pass the vector of students */ students);
			break;
		case 3:
			// Find the student with the highest gpa
			findHighestGpa(/* pass the vector of students */students);
			break;
		case 4:
			// Change a student's name
			changeStudentName(/* pass the vector of students */students);
			break;
		case 5:
			// Change a student's gpa
			changeStudentGpa(/* pass the vector of students */students);
			break;
		case 6:
			// Print all the students
			printStudents(/* pass the vector of students */students);
			break;
		case 7:
			cout << "Goodbye!" << endl;
			break;
		}
	} while (response != 7);

	return 0;
}

// Ask the use for a string
string promptForString(string message)
{
	cout << message << endl;
	string input;
	getline(cin, input);
	return input;
}

// Ask the user for a floating point value
float promptForFloat(string message)
{
	cout << message << endl;
	float input;
	cin >> input;
	cin.ignore();
	return input;
}

// Add a new student to the collection	
void addStudent(/* TODO: pass the student collection */ vector<Student>& students)
{
	string name = promptForString("Please enter the student's name");
	float gpa = promptForFloat("Please enter the student's gpa");

	// TODO: Add the student to the collection
	Student student(name, gpa);
	students.push_back(student);
}

// Find a student by name
int findStudent(/* TODO: pass the student collection */vector<Student>& students)
{
	string name = promptForString("Please enter the student's name");

	// TODO: Find the student in the collection
	for (int i = 0; i < students.size(); ++i)
	{
		if (name == students[i].getName())
		{
			// Print this when found
			cout << "Found " << name << endl;
			return i;
		}
		else
		{
			// Print this if not found
			cout << "Could not find " << name << endl;
		}
	}
}

// Find the student with the highest gpa
void findHighestGpa(/* TODO: pass the student collection */vector<Student>& students)
{
	// TODO: Find the student with the highest GPA
	// Print this when found
	// cout << "Best Student is " << studnet << endl;
}

// Change a student's name
void changeStudentName(/* TODO: pass the student collection */vector<Student>& students)
{
	string name = promptForString("Please enter the student's name");
	string newName = promptForString("Please enter the student's new name");

	// TODO: Find the student and change their name
	int index = findStudent(students);
	if (index >= 0)
	{
		students[index].setName(newName);
		// Print this when successfully changed
		cout << "Changed " << name << " to " << newName << endl;
	}
	else
	{
		// Print this if not found
		cout << "Could not find " << name << endl;
	}
}

// Change a student's gpa
void changeStudentGpa(/* TODO: pass the student collection */vector<Student>& students)
{
	string name = promptForString("Please enter the student's name");
	float gpa = promptForFloat("Please enter the student's gpa");

	// TODO: Find the student by name and change their gpa
	int index = findStudent(students);
	if (index >= 0)
	{
		students[index].setGpa(gpa);
		// Print this when successfully changed
		cout << "Changed " << name << " to " << gpa << endl;
	}
	else
	{
		// Print this if not found
		cout << "Could not find " << name << endl;
	}
}

// Print all of the students
void printStudents(/* TODO: pass the student collection */vector<Student>& students)
{
	// TODO: Print each student on their own line
	for (int i = 0; i < students.size(); ++i)
	{
		cout << students[i] << endl;
	}
}

// Print the menu to the user and get their response
int printMenu()
{
	int response;
	// Print the menu
	cout << "*********************************" << endl
		<< "1 - Add a student" << endl
		<< "2 - Find a student" << endl
		<< "3 - Find highest gpa" << endl
		<< "4 - Change a student's name" << endl
		<< "5 - Change a student's gpa" << endl
		<< "6 - Print all of the students" << endl
		<< "7 - Quit" << endl
		<< "*********************************" << endl;

	// Request the user's choice from the menu
	cout << "Please select an option from the menu" << endl;
	cin >> response;
	cin.ignore();
	return response;
}