/*
 * Main.c
 * 
 * Description: Main file of the program
 * 
 * Author: Joan Francesc Pedro Garcia
 * Date: 13-12-2023
 */

#include "Utils.h"

int main ()
{
	int first;
	int second;

	printf("Give me the first value of the pair: ");
	scanf("%d", &first);

	printf("Give me the first value of the pair: ");
	scanf("%d", &second);

	Pair pair = cons (first, second);

	printf("The car of the pair is: %d\nThe cdr of the pair is: %d\n", car(pair), cdr(pair));

	return 0;
}

Pair cons(int first, int second)
{
    Pair pair;
    pair.first = first;
    pair.second = second;
    return pair;
}

int car (Pair pair)
{
	return pair.first;
}

int cdr (Pair pair)
{
	return pair.second;
}