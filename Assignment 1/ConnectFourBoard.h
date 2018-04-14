#include <string>
using namespace std;

class ConnectFourBoard
{
    public:
        ConnectFourBoard();
        ~ConnectFourBoard();
        void printBoard();
        void setCurrentPlayer(char);
        char getCurrentPlayer();
        int validateColNum(string);
        bool validateColFull(string);
        void insertGameChip(int);
        bool checkDown();
        bool checkHorizontal();
        bool checkForwardDiag();
        bool checkBackwardDiag();

    private:
        static const int ROW = 6;
        static const int COLUMN = 7;
        char currentPlayer = 'R';
        char board[ROW][COLUMN];
        int rowCoordinate = 8;
        int colCoordinate = 8;
};