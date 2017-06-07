#include "Ex11.5.h"
#include <iostream>
#include <algorithm>
using namespace std;

double min(double* list, int size)
{
	double* min = list;
	for (int i = 0; i < size; i++)
	{
		if (list[i] < *min)
		{
			*min = list[i];
		}
	}
	return *min;
}