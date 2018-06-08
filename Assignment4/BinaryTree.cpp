/**********************************************************

    Taylor Evans
    CS 360
    Assignment 4

    This file is the .cpp file for the BinaryTree class.
    This file contains the constructor that sets the root
    to null, a destructor to delete the node, and add node
    method, a search method, a print method in ascending or
    descending order and a cleanup tree method.

***********************************************************/

#include "BinaryTree.h"
#include <cstdlib>
#include <iostream>

using namespace std;
//Constructor that sets the root to null
BinaryTree::BinaryTree()
{
    root = NULL;
}
//Destructor that cleans up the tree and notifies once root has been deleted
BinaryTree::~BinaryTree()
{
    cleanupTree();
    cout << "root has been deleted" << endl;
}

/**************************************************

    addNode(int value)

    This function calls the addNode function that
    take a value and a node.

    Parameters: int
    Return: None

**************************************************/

void BinaryTree::addNode(int value)
{
    addNode(value, root);
}


/**************************************************

    addNode(int value, Node *leaf)

    This function first checks to se if the root
    is null. If it is then it creates a new node and 
    sets the root to it. If the root is not null
    then it checks to see if the value is greater
    than or less than the current node and then 
    recursively calls it until the node is in the
    correct spot or is a duplicate.

    Parameters: int, Node
    Return: None

**************************************************/

void BinaryTree::addNode(int value, Node *leaf)
{
    if(leaf == NULL)
    {
        root = new Node(value);
    }
    else if(value < leaf->getValue())
    {
        if(leaf->getLeft() == NULL)
        {
            Node *temp = new Node(value);
            leaf->setLeft(temp);
        }
        else{
            addNode(value, leaf->getLeft());
        }
    }
    else if(value > leaf->getValue())
    {
        if(leaf->getRight() == NULL)
        {
            Node *temp = new Node(value);
            leaf->setRight(temp);
        }
        else
        {
            addNode(value, leaf->getRight());
        }
    }
}

/**************************************************

    search(int value)

    This function checks to see if the root is null.
    If it is then it prints out that the value is not
    found and it it is not null then it calls the
    private search method.

    Parameters: int
    Return: Node

**************************************************/

Node* BinaryTree::search(int value)
{
    Node *temp = root;
    Node *searchNode = NULL;
    cout << "Searching for value: " << value << endl;

    if(temp != NULL)
    {
        searchNode = search(value, root);
    }

    if(searchNode == NULL)
    {
        cout << "Value was not found" << endl;
    }
    else
    {
        cout << "The value was found!!!" << endl;
    }

    return searchNode;
}

/**************************************************

    search(int value, Node *leaf)

    This function checks to see if the leaf value is
    the same as the value that is passed in. If it is 
    then the value is found and if not then it
    recursively iterates through the tree in the
    correct direction to see if the value is found. 
    If it is found it returns the Node with the value
    and if not then it returns a null node.

    Parameters: int, Node
    Return: Node

**************************************************/

Node* BinaryTree::search(int value, Node *leaf)
{
    Node *searchNode = NULL;

    if(leaf->getValue() == value)
    {
        searchNode = leaf;
    }
    else if(value < leaf->getValue())
    {
        if(leaf->getLeft() == NULL)
        {

        }
        else
        {
            searchNode = search(value, leaf->getLeft());
        }
    }
    else if(value > leaf->getValue())
    {
        if(leaf->getRight() == NULL)
        {

        }
        else
        {
            searchNode = search(value, leaf->getRight());
        }
    }

    return searchNode;
}

/**************************************************

    cleanupTree

    This function calls the private cleanupTree
    method and passes the root to it.

    Parameters: None
    Return: Void

**************************************************/

void BinaryTree::cleanupTree()
{   cout << "calling clean up on root" << endl;
    cleanupTree(root);
}

/**************************************************

    cleanupTree(Node *leaf)

    This function calls delete on the root which then
    passes it to the destructor and recursively deletes
    all nodes.

    Parameters: None
    Return: Void

**************************************************/

void BinaryTree::cleanupTree(Node *leaf)
{ 
    delete leaf;
}

/**************************************************

    printTree(bool)

    This function checks to see if the boolean that
    was passed in is true or false. If it is true
    then it calls the print in ascending order and if
    false then it calls the print in descending order. 

    Parameters: bool
    Return: Void

**************************************************/

void BinaryTree::printTree(bool Ascending)
{
    if(Ascending)
    {
        cout << "Printing tree in ascending order============================" << endl;
        printTreeAscending(root);
    }
    else
    {
        cout << "\nPrinting tree in descending order============================\n" << endl;
        printTreeDescending(root);
    }
}

/**************************************************

    printTreeAscending(Node *leaf)

    This function checks to see if the root is
    not null. If it is not then it recursively
    iterates throught the tree and prints it in 
    ascending order.

    Parameters: bool
    Return: Void

**************************************************/

void BinaryTree::printTreeAscending(Node *leaf)
{
    if(leaf != NULL)
    {
        if(leaf->getLeft() != NULL)
        {
            printTreeAscending(leaf->getLeft());
        }
        cout << "val: " << leaf->getValue() << endl;
        if(leaf->getRight() != NULL)
        {
            printTreeAscending(leaf->getRight());
        }
    }
}

/**************************************************

    printTreeDescending(Node *leaf)

    This function checks to see if the root is
    not null. If it is not then it recursively
    iterates throught the tree and prints it in 
    descending order.

    Parameters: bool
    Return: Void

**************************************************/

void BinaryTree::printTreeDescending(Node *leaf)
{
    if(leaf != NULL)
    {
        if(leaf->getRight() != NULL)
        {
            printTreeDescending(leaf->getRight());
        }
        cout << "val: " << leaf->getValue() << endl;
        if(leaf->getLeft() != NULL)
        {
            printTreeDescending(leaf->getLeft());
        }
    }
}
