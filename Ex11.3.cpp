#include <iostream>
#include "Ex11.3.h"
using namespace std;

int *doubleCapacity(const int *list, int size)
{
	//creates a new size for the new array which is double of the entered size
	int NewSize = size * 2;
	//creates a new array with the new size
	int* NewList = new int[NewSize];
	//assigns the first half of the array with the original array
	for (int i = 0; i < size; i++)
	{
		NewList[i] = list[i];
	}
	//returns the new array
	return NewList;
}

//shows the values in the new array
void printArray(const int* list, int size)
{
	//shows each value in the array
	for (int i = 0; i < size; i++)
	{
		cout << list[i] << " ";
	}
	cout << endl;
}