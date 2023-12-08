/*
 * utils.h
 *
 * Description: This file contains all the includes and functions declarations.
 *
 * Author: Joan Francesc Pedro Garcia
 * Date: 07-12-2023
 */

// region include
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
// endregion include

// Functions
void productArray (int values[], int size);
long int productSubArray(int values[], int size, int avoidPosition);
void printArray(long int productArray[], int size);