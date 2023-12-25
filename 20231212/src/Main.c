/*
 * Main.c
 * 
 * Description: Main file of the program
 * 
 * Author: Joan Francesc Pedro Garcia
 * Date: 25-12-2023
 */

#include "Utils.h"

int main() {
	printf("XOR Linked List: ");
    Node* head = NULL;

	printf("XOR Linked List: ");
    head = add(head, 1);
    head = add(head, 2);
    head = add(head, 3);
    head = add(head, 4);

    printf("XOR Linked List: ");
    for (int i = 0; i < 4; ++i) {
        Node* node = get(head, i);
        printf("%d ", node->data);
    }

	freeList(head);

    return 0;
}