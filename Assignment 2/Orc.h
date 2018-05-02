/**********************************************************

    Taylor Evans
    CS 360
    Assignment 2

    This file is the .h file for the Orc class.
    This file contains all of the public method headers 
    used within the Orc class.

***********************************************************/

#ifndef ORC_H
#define ORC_H

#include "Enemy.h"

class Orc : public Enemy
{
    public:
        Orc(int, const int, const int, int, int); //Creates the orc
        void update(); //Updates the current Orcs position
        void attack(); //Attack to another player from Orc
        void injure(int); //Applies damage to the Orc
        void print(); //Prints the current enemy output
};
#endif