#include "ConnectFourBoard.h"
#include <iostream>
using namespace std;

int main()
{
    char choice;
    bool validChoice = false;
    bool gameOver = false;
    bool stillPlaying = true;

    cout << "\n~*~*~* Welcome to Connect Four! *~*~*~\n" << endl;

    cout << "0: quit\n1: new game\nEnter choice: ";
    cin >> choice;

    while(!validChoice)
    {
        if(choice == '0')
        {
            return 0;
        }
        else if(choice == '1')
        {
            validChoice = true;
        }
        else
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "I am sorry, but that's not a valid choice. Please try again." << endl;
            cout << "0: quit\n1: new game\nEnter choice: ";
            cin >> choice;
        }
    }

    while(stillPlaying)
    {
        int moveCount = 0;
        ConnectFourBoard game;
        game.printBoard();
        bool gameOver = false;
        bool replayChoice = false;

        while(!gameOver)
        {
            string colChoice;
            char playerMove = game.getCurrentPlayer();
            bool winner = false;

            if(playerMove == 'R')
            {
                cout << "It is red's turn.\nEnter column (0-6): ";
                cin >> colChoice;
                int validCol = game.validateColNum(colChoice);
                game.insertGameChip(validCol);
            }
            else  //playerMove == 'B'
            {
                cout << "It is black's turn.\nEnter column (0-6): ";
                cin >> colChoice;
                int validCol = game.validateColNum(colChoice);
                game.insertGameChip(validCol);
            }

            game.printBoard();
            winner = game.checkDown();
            if(winner == false)
            {
                winner = game.checkHorizontal();
                if(winner == false)
                {
                    winner = game.checkForwardDiag();
                    if(winner == false)
                    {
                        winner = game.checkBackwardDiag();
                    }
                }
            }
            
            if(winner == true)
            {
                if(playerMove == 'R')
                {
                    cout << "~*~*~* Red Wins! *~*~*~" << endl;
                }
                else
                {
                    cout << "~*~*~* Black Wins! *~*~*~" << endl;
                }

                gameOver = true;
            }

            if(playerMove == 'R')
            {
                game.setCurrentPlayer('B');
            }
            else
            {
                game.setCurrentPlayer('R');
            }

            moveCount++;
            if(moveCount == 42 && gameOver == false)
            {
                cout << "There are no more possible moves. Game results in a tie!" << endl;
                gameOver = true;
            }
        }

        cout << "0: quit\n1: new game\nEnter choice: ";
        cin >> choice;

        while(!replayChoice)
        {
            if(choice == '0')
            {
                return 0;
            }
            else if(choice == '1')
            {
                replayChoice = true;
                stillPlaying = true;
            }
            else
            {
                cin.clear();
                cin.ignore(1000,'\n');
                cout << "I am sorry, but that's not a valid choice. Please try again." << endl;
                cout << "0: quit\n1: new game\nEnter choice: ";
                cin >> choice;
            }
        }
    }
}