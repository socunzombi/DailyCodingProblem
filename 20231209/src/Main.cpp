/*
 * Main.cpp
 * 
 * Description: Main file of the program
 * 
 * Author: Joan Francesc Pedro Garcia
 * Date: 11-12-2023
 */

#include "Utils.h"

int main (int argc, char *argv[])
{
    Node* node = new Node("1", 
        new Node("2", 
            new Node("4",
                nullptr,
                new Node("8")), 
            new Node("5",
                new Node("9"),
                nullptr)), 
        new Node("3",
            new Node("6"), 
            new Node("7",
                nullptr,
                new Node("10"))));


	cout << serialize(node) << endl;
    return 0;
}