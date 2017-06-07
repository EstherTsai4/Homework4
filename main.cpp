#include <iostream>
#include <cmath>
#include "Ex11.3.h"
#include "Ex11.5.h"
#include "Rectangle2D.h"
#include "CourseClass.h"
using namespace std;

int main()
{
	//Exercise 11.1
	//declare and initialize variables for array and the size of the array
	int size = 0;
	int * num;

	//ask user how many numbers they would like to enter and store as count, which is the size of the array
	cout << "How many numbers would you like to enter? ";
	cin >> size;

	//create an array of integers with the count
	num = new int[size];

	//ask user to enter in that many number of integers and store in array
	cout << "Enter in the numbers: ";
	for (int i = 0; i < size; i++)
	{
		cin >> num[i];
	}

	//get the sum of the integers by adding up each value in the array
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += num[i];
	}
	
	//calculate the average of the array
	double average = 0;
	average = sum / size;

	//display the average
	cout << "The average of the numbers is: " << average << endl;

	//find out how many of the integers in the array are greater than the average
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (num[i] > average)
		{
			count++;
		}
	}

	//display the number of integers above avereage
	cout << "There are " << count << " numbers greater than the average." << endl;

	delete[] num;

	//Exercise 11.3
	//initialize and declare the array
	int list[3] = { 1, 2, 3 };
	
	//call the double capacity function which returns a new array. 
	//set the pointer p to the new array
	int* p = doubleCapacity(list, 3);
	
	//call the print array function to view each value in the new array
	printArray(p, 6);
	//get rid of the p array 
	delete [] p;

	//Exercise 11.5
	//create a list of an array of numbers
	double list2[8] = { 1, 2, 4, 5, 10, 100, 2, -22 }; 
	//call the function to find the minimum value of the list
	cout << "The minimum value in the list2 is: " << min (list2, 8) << endl;

	//Exercise 11.9
	//create rectangle objects with given dimensions
	Rectangle2D *r1 = new Rectangle2D(2, 2, 5.5, 4.9);
	Rectangle2D *r2 = new Rectangle2D(4, 5, 10.5, 3.2);
	Rectangle2D *r3 = new Rectangle2D(3, 5, 2.3, 5.4);

	//call function to get the area of rectangle r1
	cout << "The area of rectangle r1 is " << (*r1).getArea() << endl;
	//call function to get the perimeter of rectangle r1
	cout << "The perimeter of rectangle r1 is " << (*r1).getPerimeter() << endl;
	//see if the rectangle r1 contains the point (3,3)
	cout << "Rectangle r1 contains the point (3,3). True(1) or false(0)? " << (*r1).contains(3, 3) << endl;
	//see if the rectangle r2 is inside of rectangle r1
	cout << "Rectangle r2 is inside of rectangle r1. True(1) or false(0)? " << (*r1).contains(*r2) << endl;
	//see if the rectangle r3 overlaps rectangle r1
	cout << "Rectangle r3 overlaps rectangle r1. True(1) or false(0)? " << (*r1).overlaps(*r3) << endl;

	//remove rectangles from data
	delete r1, r2, r3;

	//Exercise 11.13
	//create course object by asking user for the course name and capacity
	int capacity = 0;
	string name = " ";

	cout << "What is the name of the course? ";
	cin.ignore();
	getline(cin, name);
	
	cout << "What is the capacity of the class? ";
	cin >> capacity;

	Course *course1 = new Course(name, capacity);

	//ask user how many students they would like to add to the class
	int addstudent = 0;
	cout << "How many students would you like to add to the class? ";
	cin >> addstudent;

	//add each student to the course
	string *Studentname = new string[addstudent];
	cout << "Enter in the names of the " << addstudent << " student(s): ";
	for (int i = 0; i < addstudent; i++)
	{
		cin >> Studentname[i];
		(*course1).addStudent(Studentname[i]);
	}

	//delete the entered student names from memory because already stored in class
	delete[] Studentname;

	//remove one of the students
	string removedstudent;
	cout << "Who would you like to remove from the class? ";
	cin >> removedstudent;
	(*course1).dropStudent(removedstudent);

	//display the students in the class
	cout << "The students in the class are: " << endl;
	for (int i = 0; i < (*course1).getNumberOfStudents(); i++)
	{
		cout << (*course1).getStudents()[i] << endl;
	}

	return 0;
}