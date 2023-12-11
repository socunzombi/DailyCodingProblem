/*
 * Utils.h
 *
 * Description: This file contains all the includes and functions declarations.
 *
 * Author: Joan Francesc Pedro Garcia
 * Date: 07-12-2023
 */

// region include
#include <iostream>
#include <string>
// endregion include

// region using
using namespace std;
// endregion using

// region define
const int LEFT = 1;
const int RIGHT= 2;
// endregion define

// Functions and objects
class Node {
    private:
        // Object parameters
        string value;
        Node* left;
        Node* right;

    public:
        // Constructor
        Node(const string& val, Node* leftNode = nullptr, Node* rightNode = nullptr);

        // Getters
        string getValue() const;
        Node* getLeft() const;
        Node* getRight() const;
        
        // Setters
        void setValue(const string& val);
        void setLeft(Node* left);
        void setRight(Node* right);
};

string serialize(Node* node);
string serializeRecursive(Node* node, const int* position);
Node deserialize(const string& serializedNode);