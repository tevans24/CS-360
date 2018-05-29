/**********************************************************

    Taylor Evans
    CS 360
    Assignment 3

    This file is the .cpp file for the GameBoard.
    This file contains the constructor for creating 
    the gameboard, adding a game piece, resetting the
    baord, getting the x and y locations ans also printing
    the board with the enemies in the proper locations.

***********************************************************/

#include "GameBoard.h"
#include "Enemy.h"
#include <string>
#include <iostream>
using namespace std;

//Constructor that saves the size of the board into variables
GameBoard::GameBoard(int x, int y)
{
    xCoordinate = x;
    yCoordinate = y;
}

/**************************************************

    addGamePiece

    This function adds a game piece to the 
    created vector to be later used to add 
    the enemy to the gameboard.

    Parameters: piece which is a pointer to enemy
    Return: void

**************************************************/

void GameBoard::addGamePiece(Enemy * piece)
{
    board.push_back(piece);
}

/**************************************************

    printBoard

    This function creates a string of characters in a 
    specific order to match the size of the board that 
    is created. It then prints the message to format
    the board with the enemies and other characters in
    specific locations. 
    
    Parameters: None
    Return: void

**************************************************/

void GameBoard::printBoard()
{
    int i, j;
    string message;
    bool enemySpot = false;
    char enemyChar;

    for(i = yCoordinate; i > (yCoordinate * -1) -1; i--)
    {
        for(j = (xCoordinate * -1); j < (xCoordinate + 1); j++)
        {
            enemySpot = false;

            for(int k = 0; k < board.size(); k++)
            {
                if(board[k]->getY() == i && board[k]->getX() == j)
                {
                    enemySpot = true;
                    enemyChar = board[k]->getDisplayChar();
                }
            }

            if(enemySpot == true)
            {
                message = message + enemyChar + " ";
            }
            else if(i != 0 && j == 0)
            {
                message = message + "| ";
            }
            else if(i == 0 && j != 0)
            {
                message = message + "- ";
            }
            else if(i == 0 && j == 0)
            {
                 message = message + "+ ";
            }
            else
            {
                message = message + "* ";
            }
        }
        message = message + "\n";
    }

    cout << message;
}

/**************************************************

    resetBoard

    This function clears the vector of all enemies

    Parameters: None
    Return: void

**************************************************/

void GameBoard::resetBoard()
{
    board.clear();
}

/**************************************************

    getXpos

    This function returns the max X position

    Parameters: None
    Return: int

**************************************************/

int GameBoard::getXpos() const
{
    return xCoordinate;
}

/**************************************************

    getYpos

    This function returns the max Y position

    Parameters: None
    Return: int

**************************************************/

int GameBoard::getYpos() const
{
    return yCoordinate;
}