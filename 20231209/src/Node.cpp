/*
 * Node.cpp
 * 
 * Description: Node object
 * 
 * Author: Joan Francesc Pedro Garcia
 * Date: 11-12-2023
 */

#include "Utils.h"

// Constructor definition
Node::Node(const string& val, Node* leftNode, Node* rightNode)
    : value(val), left(leftNode), right(rightNode) 
{}

// Getters
string Node::getValue() const 
{
    return value;
}
Node* Node::getLeft() const 
{
    return left;
}
Node* Node::getRight() const 
{
    return right;
}

// Setters
void Node::setValue(const string& val) 
{
    value = val;
}
void Node::setLeft(Node* leftNode) 
{
    left = leftNode;
}
void Node::setRight(Node* rightNode) 
{
    right = rightNode;
}
