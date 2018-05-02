/**********************************************************

    Taylor Evans
    CS 360
    Assignment 2

    This file is the .h file for the Goblin class.
    This file contains all of the public method headers 
    used within the Goblin class.

***********************************************************/

#ifndef GOBLIN_H
#define GOBLIN_H

#include "Enemy.h"

class Goblin : public Enemy
{
    public:
        Goblin(int, const int, const int, int, int); //Creates the Goblin
        void update(); //Updates the current Goblins position
        void attack(); //Attack to another player from Goblin
        void injure(int); //Applies damage to the Goblin
        void print(); //Prints the current enemy output
};
#endif