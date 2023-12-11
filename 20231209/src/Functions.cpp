/*
 * Functions.cpp
 * 
 * Description: Functions of the program
 * 
 * Author: Joan Francesc Pedro Garcia
 * Date: 11-12-2023
 */

#include "Utils.h"

string serialize(Node* node)
{
    return "Root:\'" + node->getValue() + "\'" 
        + serializeRecursive(node->getLeft(), &LEFT) 
        + serializeRecursive(node->getRight(), &RIGHT);
}

string serializeRecursive(Node* node, const int* position)
{
    string content = 
    "\'" +
    (
        node == nullptr 
        ? "null\'" 
        : 
        (
            node->getValue() + "\'" + 
            (
                node->getLeft() == nullptr && node->getRight() == nullptr 
                ? "" 
                : serializeRecursive(node->getLeft(), &LEFT) + serializeRecursive(node->getRight(), &RIGHT)
            )
        )
    );
    
    switch (*position)
    {
    case LEFT:
        return "{LEFT:" + content + ",";
    case RIGHT:
        return "RIGHT:" + content + "}";
    }
}

Node deserialize(const string& serializedNode)
{

}