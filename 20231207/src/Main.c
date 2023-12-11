/*
 * Main.c
 * 
 * Description: Main file of the program
 * 
 * Author: Joan Francesc Pedro Garcia
 * Date: 07-12-2023
 */

#include "Utils.h"

// checkSum
bool checkSum (int sumValue, int values[], int size)
{
	printf("Start checking...\n");

	// We create an array to save the nubers viewed
	int numbersViewed[10000] = {0};

	for (int n = 0; n < size; n++)
	{
		// We create a complement number that will be the difference of the sum value less the actual number looking
		int supNumber = sumValue - values[n];
		
		// we check if the complement number exists in our numberViewed array, what means that
		// the sum of our actual number values[n] plus the supNumber is equal to the sumValue
		if (numbersViewed[supNumber]) {
			return true;
		}

		// if not, we add our number to the numbersViewed array
		numbersViewed[values[n]] = 1;
	}

	// if we finish the bucle means that the sum does not exist in this case
	return false;
}

// Main execution
int main (int argc, char *argv[])
{
	// We check that the user gives us values
	if (argc < 4) {
		printf("Usage: %s <sumValue> <arrayValue1> <arrayValue2> ... <arrayValueN>\n", argv[0]);
		return 1;
	}


	// We set the variables with the parameters
	int sumValue = atoi(argv[1]);
	int arraySize = argc - 2;
	int values[arraySize];

	// We add all numbers to the array
	for (int n = 0; n < arraySize; n++)
	{
		values[n] = atoi(argv[n+2]);
	}

	// We make the check
	if (checkSum(sumValue, values, arraySize))
	{
		printf("TRUE! In the array exists a sum of two numbers that equals to %d\n", sumValue);
	}
	else
	{
		printf("FALSE! In the array does not exists a sum of two numbers that equals to %d\n", sumValue);
	}

	return 0;
}

