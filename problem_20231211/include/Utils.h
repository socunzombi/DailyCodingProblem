/*
 * Utils.h
 *
 * Description: This file contains all the includes and functions declarations.
 *
 * Author: Joan Francesc Pedro Garcia
 * Date: 13-12-2023
 */

// region include
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
// endregion include

// Functions

typedef struct {
    int first;
    int second;
} Pair;

Pair cons(int first, int second);
int car (Pair pair);
int cdr (Pair pair);