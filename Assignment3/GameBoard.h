#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "Enemy.h"
#include <vector>
using std::vector;

class GameBoard{
	protected:
        int xCoordinate;
        int yCoordinate;
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