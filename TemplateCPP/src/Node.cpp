/*
 * Node.c
 * 
 * Description: object node
 * 
 * Author: Joan Francesc Pedro Garcia
 * Date: 07-12-2023
 */

#include "utils.h"

struct Node
{
    char value[];
    Node left;
    Node right;
};

// Constructor
struct Node* constructor (char* value, Node left, Node right)
{
    struct Node* obj = (struct Node*)malloc(sizeof(struct Node));

    if (obj != null)
    {
        
    }
}

// Setters
void setValue(struct Node *node, char value[]) 
{
    node->value = value;
}

void setLeft (struct Node *node, Node left)
{
    node->left = left;
}

void setRight (struct Node *node, Node right)
{
    node->right = right;
}

// Getters
char* getValue(struct Node *node) 
{
    return node->value;
}

Node getLeft(struct Node *node)
{
    return node->left;
}

Node getRight(struct Node *node)
{
    return node->right;
}