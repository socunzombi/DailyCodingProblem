/*
 * main.c
 * 
 * Description: Main file of the program
 * 
 * Author: Joan Francesc Pedro Garcia
 * Date: 07-12-2023
 */

#include "utils.h"

/// @brief main function to execute program
/// @param argc 
/// @param argv 
/// @return ok / ko
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

	productArray(values, arraySize);

	return 0;
}

/// @brief we create a new array that the value is the product of the array less the actual position.
/// @param values 
/// @param size 
void productArray (int values[], int size)
{
	long int productArray[size];
	for (int pos = 0; pos < size; pos++)
	{
		productArray[pos] = productSubArray(values, size, pos);
	}

	printArray(productArray, size);
}

/// @brief We create the product of the values of the array avoiding the avoidPosition.
/// @param values 
/// @param size 
/// @param avoidPosition 
/// @return product of the array
long int productSubArray(int values[], int size, int avoidPosition)
{
	long int product = 1;
	for (int pos = 0; pos < size; pos++)
	{
		if (pos != avoidPosition)
		{
			product = product * values[pos];
		}
	}
	return product;
}

/// @brief We print the result in the console.
/// @param productArray 
/// @param size 
void printArray(long int productArray[], int size)
{
	printf("The value of the new array is: {%ld", productArray[0]);
	for (int pos = 1; pos < size; pos++)
	{
		printf(", %ld", productArray[pos]);
	}
	printf("}\n");
}