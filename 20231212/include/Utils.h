/*
 * Utils.h
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
#include <stdint.h>
// endregion include

// Functions

typedef struct Node {
    int data;
    struct Node* xor_ptr;
} Node;

Node* XOR(Node* a, Node* b);
Node* add(Node* head, int data);
Node* get(Node* head, int index);
void freeList(Node* head);