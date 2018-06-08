/**********************************************************

    Taylor Evans
    CS 360
    Assignment 4

    This file is the .cpp file for the Node class.
    This file contains the constructor for creating a 
    node, a destructor to delete the node, a getValue 
    method, and get left and right node and a set left
    and right node.

***********************************************************/

#include "Node.h"
#include <cstdlib>
#include <iostream>

using namespace std;
//Constructor that creates a node and sets its left and right to null
Node::Node(int val)
{
    value = val;
    left = NULL;
    right = NULL;
}
//Destructor that deletes the left and right nodes
Node::~Node()
{
    delete left;
    delete right;
}

/**************************************************

    getValue

    This function returns the value of the node

    Parameters: None
    Return: int

**************************************************/

int Node::getValue()
{
    return value;
}

/**************************************************

    getLeft

    This function returns the left child of a parent node

    Parameters: None
    Return: Node*

**************************************************/

Node* Node::getLeft()
{
    return left;
}

/**************************************************

    getRight

    This function returns the right child of a parent node

    Parameters: None
    Return: Node*

**************************************************/

Node* Node::getRight()
{
    return right;
}

/**************************************************

    setLeft

    This function sets the left child of a parent node

    Parameters: Node*
    Return: none

**************************************************/

void Node::setLeft(Node* l)
{
    left = l;
}

/**************************************************

    setRight

    This function sets the right child of a parent node

    Parameters: Node*
    Return: none

**************************************************/

void Node::setRight(Node* r)
{
    right = r;
}