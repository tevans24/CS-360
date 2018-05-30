/**********************************************************

    Taylor Evans
    CS 360
    Assignment 3

    This file is the .h file for the GameBoard.
    This file contains the protected and private
    variables and functions that are used by the
    gameboard.

***********************************************************/

#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "Enemy.h"
#include <vector>
using std::vector;

class GameBoard{
	protected:
        int xCoordinate; //Sets max x coordinate
        int yCoordinate; //Sets max y coordinate
        vector <Enemy*> board; 

	public:
        GameBoard(int x, int y);
        void addGamePiece(Enemy * piece);
        void printBoard();
        void resetBoard();
        int getYpos() const;
        int getXpos() const;
		
};//end of class

#endif