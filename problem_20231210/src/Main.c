/*
 * Main.c
 * 
 * Description: Main file of the program
 * 
 * Author: Joan Francesc Pedro Garcia
 * Date: 07-12-2023
 */

#include "Utils.h"

int main (int argc, char *argv[])
{
    // We check that the user gives us values
	if (argc < 3) {
		printf("Usage: %s <arrayValue1> <arrayValue2> ... <arrayValueN>\n", argv[0]);
		return 1;
	}


	// We set the variables with the parameters
	int arraySize = argc - 1;
	int values[arraySize];

	// We add all numbers to the array
	for (int n = 0; n < arraySize; n++)
	{
		values[n] = atoi(argv[n+1]);
	}

	printf("Lowest value: %d\n", lowestPositiveValue(values, arraySize));
	return 0;
}

int lowestPositiveValue(int values[], int arraySize)
{
	int numbersViewed[10000] = {0};

	for (int position = 0; position < arraySize; position++)
	{
		if (values[position] > 0)
		{
			numbersViewed[values[position]] = 1;
		}
	}

	for (int minValue = 1; minValue < 10000; minValue++)
	{
		if (numbersViewed[minValue] == 0)
		{
			return minValue;
		}
	}

	return 0;
}