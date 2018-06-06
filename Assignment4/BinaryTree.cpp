#include "BinaryTree.h"
#include <cstdlib>
#include <iostream>

using namespace std;

BinaryTree::BinaryTree()
{
    root = NULL;
}

BinaryTree::~BinaryTree()
{
    cleanupTree();
}

void BinaryTree::addNode(int value)
{
    addNode(value, root);
}

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

Node* BinaryTree::search(int value)
{
    Node *temp = root;
    Node *searchNode = NULL;

    if(temp != NULL)
    {
        if(temp->getValue() == value)
        {
            searchNode = temp;
        }
        else
        {
            searchNode = search(value, root);
        }
    }

    return searchNode;
}

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

void BinaryTree::cleanupTree()
{
    cleanupTree(root);
}

void BinaryTree::cleanupTree(Node *leaf)
{
    delete leaf->getLeft();
    delete leaf->getRight();
    delete leaf;
}

void BinaryTree::printTree(bool Ascending)
{
    if(Ascending)
    {
        printTreeAscending(root);
    }
    else
    {
        printTreeDescending(root);
    }
}

void BinaryTree::printTreeAscending(Node *leaf)
{
    if(leaf != NULL)
    {
        if(leaf->getLeft() != NULL)
        {
            printTreeAscending(leaf->getLeft());
        }
        cout << leaf->getValue() << " ";
        if(leaf->getRight() != NULL)
        {
            printTreeAscending(leaf->getRight());
        }
    }
}

void BinaryTree::printTreeDescending(Node *leaf)
{
    if(leaf != NULL)
    {
        if(leaf->getRight() != NULL)
        {
            printTreeDescending(leaf->getRight());
        }
        cout << leaf->getValue() << " ";
        if(leaf->getLeft() != NULL)
        {
            printTreeDescending(leaf->getLeft());
        }
    }
}
