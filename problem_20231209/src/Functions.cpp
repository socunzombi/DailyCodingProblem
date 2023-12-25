/*
 * Functions.cpp
 * 
 * Description: Functions of the program
 * 
 * Author: Joan Francesc Pedro Garcia
 * Date: 11-12-2023
 */

#include "Utils.h"
#include "Functions.h"

/// @brief Serialization of the binary tree
/// @param node Binary tree
/// @return Serialization in string format of the binary tree
string serialize(Node* node)
{
    return "Root:\'" + node->getValue() + "\'" +
        (node->getLeft() != nullptr || node->getRight() != nullptr ?
         serializeRecursive(node->getLeft(), &LEFT) 
        + serializeRecursive(node->getRight(), &RIGHT) : "");
}

/// @brief Serialization of the binary tree and make it recursive
/// @param node Binary tree
/// @param position Left or Right, to know in which node we are
/// @return Serialization in string format of the node and childs
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

/// @brief Deserialization of the string in a binary tree
/// @param serializedNode Serializated string of the binary tree
/// @return Deserialized binary tree
Node* deserialize(const string& serializedNode)
{
    // Root:'1'{LEFT:'2'{LEFT:'4'{LEFT:'null',RIGHT:'8'},RIGHT:'5'{LEFT:'9',RIGHT:'null'}},RIGHT:'3'{LEFT:'6',RIGHT:'7'{LEFT:'null',RIGHT:'10'}}}
    // 0123456789012345678901234
    
    /* TODO -> no se ha terminado la deserializacion */
    cout << "ACTUAL STRING: " + serializedNode << endl;
    cout << "Corchetes: " + to_string(count(serializedNode.begin(), serializedNode.end(), '{')) << endl;

    if (count(serializedNode.begin(), serializedNode.end(), '{') == 1)
    {
        cout << "Solo un corchete" << endl;
        int position = serializedNode.find('\'') + 1;

        string valueRoot;
        string valueLeft;
        string valueRight;

        while (serializedNode[position] != '\'')
        {
            valueRoot = serializedNode[position];
            position ++;
        }

        position += 2;
        int separatorPosition = serializedNode.find(',');
        string subStringLeft = serializedNode.substr(position, separatorPosition);

        cout << subStringLeft << endl;

        return new Node("a");
    }
    else
    {
        int position = serializedNode.find('\'') + 1;
        cout << "POSITION: " + to_string(position) << endl;

        string value;

        while (serializedNode[position] != '\'')
        {
            value = serializedNode[position];
            position ++;
        }
        
        if (serializedNode[position+1] == '\0' || serializedNode[position+1] == ',' || serializedNode[position+1] == '}')
        {
            return new Node(value);
        }
        else
        {
            position += 2;
            int subStringLeftInit = position;
            int subStringLeftEnd;
            int subStringRightInit;
            int subStringRightEnd = serializedNode.length() - 1;
            int counterBraces = 0;
            string subString = serializedNode.substr(subStringLeftInit, subStringRightEnd-subStringLeftInit);
            int subPosition = 0;
            
            do
            {
                subPosition = subString.find('{') < subString.find('}') ? subString.find('{') : subString.find('}');
                cout << subPosition << endl;
                if (subPosition != -1)
                {
                    subString[subPosition] == '{' ? ++counterBraces : --counterBraces;
                    position += subPosition+1;
                    subString = subString.substr(subPosition+1);
                }
            }
            while (counterBraces != 0);

            subStringRightInit = position+1;
            subStringLeftEnd = position;
            string leftString = serializedNode.substr(subStringLeftInit, subStringLeftEnd-subStringLeftInit);
            string rightString = serializedNode.substr(subStringRightInit, subStringRightEnd-subStringRightInit);
            cout << "Left String: " + leftString << endl;
            cout << "Right String: " + rightString << endl;

            return new Node(value, deserialize(leftString), deserialize(rightString));
        }
    }
}

/// @brief Deserialization of the string in a binary tree and make it recursive
/// @param serializedNode Serializated string of the binary tree
/// @return Binary tree of the node and childs
Node* deserializeRecursive(char* subCharArray)
{

}