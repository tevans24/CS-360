/**********************************************************

    Taylor Evans
    CS 360
    Assignment 1

    This file is the .cpp file for the ConnectFourBoard.
    This file contains the constructor for creating the
    board and all of the methods to check for validation,
    insert the pieces into the correct spots and to check
    to see if there is a winner.

***********************************************************/

#include "ConnectFourBoard.h"
#include <iostream>
#include <cstdlib>
using namespace std;

//Constructor that created the Connect four board
ConnectFourBoard::ConnectFourBoard()
{
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COLUMN; j++)
        {
            board[i][j] = '_';
        }
    }
}

/**************************************************

    ConnectFourBoard

    This function prints out the current board
    status including the location of all of the
    pieces.

    Parameters: None
    Return: void

**************************************************/

void ConnectFourBoard::printBoard()
{
    cout << "Current board status:\n\n" << endl;
    cout << "0 1 2 3 4 5 6" << endl;

    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COLUMN; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n" << endl;
    }
}

/**************************************************

    setCurrentPlayer

    This function takes a player of either red or black
    and it sets it to the current player.

    Parameters: player - Players turn of either red or black
    Return: void

**************************************************/

void ConnectFourBoard::setCurrentPlayer(char player)
{
    currentPlayer = player;
}

/**************************************************

    getCurrentPlayer

    This function returns a char value of either red
    or black for the current player.

    Parameters: None
    Return: A char value of either red or black

**************************************************/

char ConnectFourBoard::getCurrentPlayer()
{
    return currentPlayer;
}

/**************************************************

    validateColNum

    This function accepts a string column choice and 
    validates if it is between 0 and 6. If it is then
    it returns that value and if it is not then it prompts
    the user to enter a new value.

    Parameters: colChoice - String value to be checked for validation
    Return: and int value of the correct column number

**************************************************/

int ConnectFourBoard::validateColNum(string colChoice)
{
    string nextCol;
    int validNum;
    //Sets the valid number if it is between 0 and 6 and column is not full
    if(colChoice[0] >= 48 && colChoice[0] < 55 && !(validateColFull(colChoice)))
    {
        validNum = (int)colChoice[0]-48;
    }
    else if(colChoice[0] >= 48 && colChoice[0] < 55 && (validateColFull(colChoice)))
    {   //If number is correct but column is full, prompts to enter another column
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Sorry that column is full.\nEnter another column (0-6): ";
        cin >> nextCol;
        validNum = validateColNum(nextCol);
    }
    else
    {   //If number is outside of valid range, prompts to enter a new column
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Sorry that column is invalid\nEnter column (0-6): ";
        cin >> nextCol;
        validNum = validateColNum(nextCol);
    }

    return validNum;
}

/**************************************************

    validatColFull

    This function takes a string value which is the column
    and it check to see if that column has any open spaces and
    returns if it does or not.

    Parameters: colChoice - String value of column to check if full
    Return: A boolean of true or false if it is full or not

**************************************************/

bool ConnectFourBoard::validateColFull(string colChoice)
{
    bool colFull = true;
    int colNum = (int)colChoice[0]-48; //Sets column to valid int

    if(board[0][colNum] == '_')  //Checks to see if top spot is full
    {
        colFull = false;
    }

    return colFull;
}

/**************************************************

    insertGameChip

    This function takes an integer which is the column
    that the piece is to be inserted in to. It then
    starts at the bottom and checks each index upward 
    until it finds an open spot.

    Parameters: validCol
    Return: void

**************************************************/

void ConnectFourBoard::insertGameChip(int validCol)
{
    bool placedMove = false;
    int count = 5;

    while(!placedMove)
    {   //Starts from the bottom and decrements to find open space
        if(board[count][validCol] == '_')
        {
            board[count][validCol] = currentPlayer;
            rowCoordinate = count;
            colCoordinate = validCol;
            placedMove = true;
        }
        count--;   
    }
}

/**************************************************

    checkDown

    This function checks the column from where the most previous
    piece was inserted to see if there is a winner. It checks down
    from the column and row of the last piece. If there is
    four in a row then it returns a boolean of true or false if 
    there is not.

    Parameters: None
    Return: A boolean value of true of false if there is a winner

**************************************************/

bool ConnectFourBoard::checkDown()
{
    int pieceCount = 1;
    int tempCol = colCoordinate;
    int tempRow = rowCoordinate + 1;
    bool noMoreDown = false;
    bool isWinner = false;

    while(!noMoreDown && tempRow < 6)  //Checks down to get total count
    {
        if(board[tempRow][tempCol] == currentPlayer)
        {
            pieceCount++;
            tempRow++;
        }
        else
        {
            noMoreDown = true;
        }
    }
    
    if(pieceCount >= 4)
    {
        isWinner = true;
    }

    return isWinner;  //Returns true or false if there is a winner
}

/**************************************************

    checkHorizontal

    This function checks the row from where the most previous
    piece was inserted to see if there is a winner. It checks left
    from the column and row of the last piece and then it checks 
    right. If there is four in a row then it returns a boolean of 
    true or false if there is not.

    Parameters: None
    Return: a boolean of true or false if there is a winner

**************************************************/

bool ConnectFourBoard::checkHorizontal()
{
    int pieceCount = 1;
    int tempCol = colCoordinate;
    int tempRow = rowCoordinate;
    bool noMoreLeft = false;
    bool noMoreRight = false;
    bool isWinner = false;

    while(!noMoreLeft && tempCol > 0) //Checks left of current placed piece
    {
        if(board[tempRow][tempCol - 1] == currentPlayer)
        {
            pieceCount++;
            tempCol--;
        }
        else
        {
            noMoreLeft = true;
        }
    }
    //Resets column to starting point
    tempCol = colCoordinate;

    while(!noMoreRight && tempCol < 6) //Checks right of current placed piece
    {
        if(board[tempRow][tempCol + 1] == currentPlayer)
        {
            pieceCount++;
            tempCol++;
        }
        else
        {
            noMoreRight = true;
        }
    }

    if(pieceCount >= 4)
    {
        isWinner = true;
    }

    return isWinner;  //Returns true or false if there is a winner
}

/**************************************************

    checkForwardDiag

    This function checks the diagonal from where the most previous
    piece was inserted to see if there is a winner. It checks down 
    left from the column and row of the last piece and then it checks 
    up right. If there is four in a row then it returns a boolean of 
    true or false if there is not.

    Parameters: None
    Return: a boolean of true or false if there is a winner

**************************************************/

bool ConnectFourBoard::checkForwardDiag()
{
    int pieceCount = 1;
    int tempCol = colCoordinate;
    int tempRow = rowCoordinate;
    bool noMoreDownLeft = false;
    bool noMoreUpRight = false;
    bool isWinner = false;

    while(!noMoreDownLeft && tempRow < 5 && tempCol > 0) //Checks down left of current piece
    {
        if(board[tempRow + 1][tempCol - 1] == currentPlayer)
        {
            pieceCount++;
            tempCol--;
            tempRow++;
        }
        else
        {
            noMoreDownLeft = true;
        }
    }
    //Resets row and column to starting point
    tempCol = colCoordinate;
    tempRow = rowCoordinate;
    
    while(!noMoreUpRight && tempRow > 0 && tempCol < 6) //Checks up right of current piece
    {
        if(board[tempRow - 1][tempCol + 1] == currentPlayer)
        {
            pieceCount++;
            tempCol++;
            tempRow--;
        }
        else
        {
            noMoreUpRight = true;
        }
    }

    if(pieceCount >= 4)
    {
        isWinner = true;
    }

    return isWinner;  //Returns true or false if there is a winner
}

/**************************************************

    checkBackwardDiag

    This function checks the diagonal from where the most previous
    piece was inserted to see if there is a winner. It checks up left
    from the column and row of the last piece and then it checks 
    down right. If there is four in a row then it returns a boolean of 
    true or false if there is not.

    Parameters: None
    Return: a boolean of true or false if there is a winner

**************************************************/

bool ConnectFourBoard::checkBackwardDiag()
{
    int pieceCount = 1;
    int tempCol = colCoordinate;
    int tempRow = rowCoordinate;
    bool noMoreUpLeft = false;
    bool noMoreDownRight = false;
    bool isWinner = false;

    while(!noMoreUpLeft && tempRow > 0 && tempCol > 0) //Checks up left of current piece
    {
        if(board[tempRow - 1][tempCol - 1] == currentPlayer)
        {
            pieceCount++;
            tempCol--;
            tempRow--;
        }
        else
        {
            noMoreUpLeft = true;
        }
    }
    //Resets row and column to starting point
    tempCol = colCoordinate;
    tempRow = rowCoordinate;
    
    while(!noMoreDownRight && tempRow < 5 && tempCol < 6)
    {
        if(board[tempRow + 1][tempCol + 1] == currentPlayer) //Checks down right of current piece
        {
            pieceCount++;
            tempCol++;
            tempRow++;
        }
        else
        {
            noMoreDownRight = true;
        }
    }

    if(pieceCount >= 4)
    {
        isWinner = true;
    }
    
    return isWinner;  //Returns true or false if there is a winner
}