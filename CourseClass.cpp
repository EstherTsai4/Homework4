#include "CourseClass.h"
#include <iostream>
using namespace std;

//creates a course based on the entered in information
Course::Course(const string& courseName, int capacity)
{
	numberOfStudents = 0;
	//sets the course name to the given name
	this->courseName = courseName;
	//sets the capacity of the course to the entered capacity
	this->capacity = capacity;
	//creates an array of students with the maximum amount as the capacity
	students = new string[capacity];
}

//create destructor of the course which deletes array of students in the course
Course::~Course()
{
	delete[] students;
}

//returns the course name 
string Course::getCourseName() const
{
	return courseName;
}

//adds a student to the course
void Course::addStudent(const string& name)
{
	//if the number of students exceeds capacity, create a larger array and copy past info into the array
	if (numberOfStudents >= capacity)
	{
		cout << "The maximum size of array exceeded" << endl;
		//increase array size
		int NewCapacity = 2 * capacity;
		//create a new array with the new capacity
		string* students = new string[NewCapacity];
		//copy the previous names into the new array
		for (int i = 0; i < capacity; i++)
		{
			students[i] = this->students[i];
		}
		students[numberOfStudents] = name;
	}

	students[numberOfStudents] = name;
	numberOfStudents++;
}

void Course::dropStudent(const string& name)
{
	//set the index of the student that will be dropped to zero
	int dropStudent = 0;
	bool drop = true;
	//goes through the array of students to find the student with the matching name
	for (int i = 0; i < capacity; i++)
	{
		//once the name matches the student's name, 
		//record the index in the array and exit out of loop
		if (students[i] == name)
		{
			dropStudent = i;
			students[i].clear();
			drop = true;
			break;
		}
		else
		{
			drop = false;
		}
	}
	if (drop == false)
	{
		//if the name is not found
		cout << name << " student does not exist in the system. " << endl;
	}

	//drop the student by shifting the array down
	for (int i = dropStudent; i < (numberOfStudents - 1); i++)
	{
		students[i] = students[i + 1];
	}

	//decrease the number of students by one
	numberOfStudents--;
}

void Course::clear()
{
	//goes through each array and clears the string at each index
	for (int i = 0; i < capacity; i++)
	{
		students[i].clear();
	}
}

string* Course::getStudents() const
{
	return students;
}

int Course::getNumberOfStudents() const
{
	return numberOfStudents;
}

Course::Course(const Course& course)
{
	courseName = course.courseName;
	numberOfStudents = course.numberOfStudents;
	capacity = course.capacity;
	students = new string[capacity];
}