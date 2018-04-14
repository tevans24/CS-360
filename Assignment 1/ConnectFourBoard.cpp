#include "ConnectFourBoard.h"
#include <iostream>
#include <cstdlib>
using namespace std;

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

ConnectFourBoard::~ConnectFourBoard()
{
    //delete board;
}

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

void ConnectFourBoard::setCurrentPlayer(char player)
{
    currentPlayer = player;
}

char ConnectFourBoard::getCurrentPlayer()
{
    return currentPlayer;
}

int ConnectFourBoard::validateColNum(string colChoice)
{
    string nextCol;
    int validNum;
    
    if(colChoice[0] >= 48 && colChoice[0] < 55 && !(validateColFull(colChoice)))
    {
        validNum = (int)colChoice[0]-48;
    }
    else if(colChoice[0] >= 48 && colChoice[0] < 55 && (validateColFull(colChoice)))
    {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Sorry that column is full.\nEnter another column (0-6): ";
        cin >> nextCol;
        validNum = validateColNum(nextCol);
    }
    else
    {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Sorry that column is invalid\nEnter column (0-6): ";
        cin >> nextCol;
        validNum = validateColNum(nextCol);
    }

    return validNum;
}

bool ConnectFourBoard::validateColFull(string colChoice)
{
    bool colFull = true;
    int colNum = (int)colChoice[0]-48;

    if(board[0][colNum] == '_')
    {
        colFull = false;
    }

    return colFull;
}

void ConnectFourBoard::insertGameChip(int validCol)
{
    bool placedMove = false;
    int count = 5;

    while(!placedMove)
    {
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

bool ConnectFourBoard::checkDown()
{
    int pieceCount = 1;
    int tempCol = colCoordinate;
    int tempRow = rowCoordinate + 1;
    bool noMoreDown = false;
    bool isWinner = false;

    while(!noMoreDown && tempRow < 6)
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

    return isWinner;
}

bool ConnectFourBoard::checkHorizontal()
{
    int pieceCount = 1;
    int tempCol = colCoordinate;
    int tempRow = rowCoordinate;
    bool noMoreLeft = false;
    bool noMoreRight = false;
    bool isWinner = false;

    while(!noMoreLeft && tempCol > -1)
    {
        if(board[tempRow][tempCol - 1] == currentPlayer)
        {   cout << "(" << tempRow << "," << (tempCol - 1) << ")";
            cout << "Piece count = " << pieceCount << endl;
            pieceCount++;
            tempCol--;
        }
        else
        {
            tempCol = colCoordinate;
            noMoreLeft = true;
        }
    }

    while(!noMoreRight && tempCol < 6)
    {
        if(board[tempRow][tempCol + 1] == currentPlayer)
        {   cout << "(" << tempRow << "," << (tempCol+1) << ")";
            cout << "Piece count = " << pieceCount << endl;
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

    return isWinner;
}

bool ConnectFourBoard::checkForwardDiag()
{
    int pieceCount = 1;
    int tempCol = colCoordinate;
    int tempRow = rowCoordinate;
    bool noMoreDownLeft = false;
    bool noMoreUpRight = false;
    bool isWinner = false;

    while(!noMoreDownLeft && tempRow < 6 && tempCol > -1)
    {
        if(board[tempRow + 1][tempCol - 1] == currentPlayer)
        {
            pieceCount++;
            tempCol--;
            tempRow++;
        }
        else
        {
            tempCol = colCoordinate;
            tempRow = rowCoordinate;
            noMoreDownLeft = true;
        }
    }

    while(!noMoreUpRight && tempRow > -1 && tempCol < 7)
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

    return isWinner;
}

bool ConnectFourBoard::checkBackwardDiag()
{
    int pieceCount = 1;
    int tempCol = colCoordinate;
    int tempRow = rowCoordinate;
    bool noMoreUpLeft = false;
    bool noMoreDownRight = false;
    bool isWinner = false;

    while(!noMoreUpLeft && tempRow > -1 && tempCol > -1)
    {
        if(board[tempRow - 1][tempCol - 1] == currentPlayer)
        {
            pieceCount++;
            tempCol--;
            tempRow--;
        }
        else
        {
            tempCol = colCoordinate;
            tempRow = rowCoordinate;
            noMoreUpLeft = true;
        }
    }

    while(!noMoreDownRight && tempRow < 6 && tempCol < 7)
    {
        if(board[tempRow + 1][tempCol + 1] == currentPlayer)
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
    
    return isWinner;
}