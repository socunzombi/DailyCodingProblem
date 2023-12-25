/*
 * Node.c
 * 
 * Description: Node functions
 * 
 * Author: Joan Francesc Pedro Garcia
 * Date: 25-12-2023
 */

#include "Utils.h"

Node* XOR(Node* a, Node* b) {
    
}

Node* add(Node* head, int data) {

}

Node* get(Node* head, int index) {
    
}

void freeList(Node* head) {
    Node* curr = head;
    Node* prev = NULL;
    Node* next;

    while (curr != NULL) {
        next = XOR(prev, curr->xor_ptr);
        free(prev);
        prev = curr;
        curr = next;
    }

    free(prev);
}