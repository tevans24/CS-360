/**********************************************************

    Taylor Evans
    CS 360
    Assignment 1

    This file is the .h file for the ConnectFourBoard.
    This file contains all of the public method headers 
    along with the private variables used within the connect
    four board.

***********************************************************/

#include <string>
using namespace std;

class ConnectFourBoard
{
    public:
        ConnectFourBoard();  //Creates the board
        void printBoard();  //Prints the board
        void setCurrentPlayer(char);  //Sets the current player
        char getCurrentPlayer();  //Gets the current player
        int validateColNum(string);  //Validates the column
        bool validateColFull(string);  //Checks if column is full
        void insertGameChip(int);  //Inserts the game chip
        bool checkDown();  //Checks down for a winner
        bool checkHorizontal();  //Checks horizontal for a winner
        bool checkForwardDiag();  //Checks forward slash for a winner
        bool checkBackwardDiag();  //Checks back slash for a winner

    private:
        static const int ROW = 6;
        static const int COLUMN = 7;
        char currentPlayer = 'R';  //Starting player
        char board[ROW][COLUMN];
        int rowCoordinate = 8;
        int colCoordinate = 8;
};