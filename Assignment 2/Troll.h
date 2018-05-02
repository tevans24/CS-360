/**********************************************************

    Taylor Evans
    CS 360
    Assignment 2

    This file is the .h file for the Troll class.
    This file contains all of the public method headers 
    and protected variables used within the Troll class.

***********************************************************/

#ifndef TROLL_H
#define TROLL_H

#include "Enemy.h"

class Troll : public Enemy
{
    public:
        Troll(int, const int, const int, int, int); //Creates the troll
        void update(); //Updates the current Trolls position
        void attack(); //Attack to another player from Troll
        void injure(int); //Applies damage to the Troll
        void print(); //Prints the current enemy output

    protected:
        int maxHealth; //Sets the max health of the troll
};
#endif