/**********************************************************

    Taylor Evans
    CS 360
    Assignment 2

    This file is the .cpp file for the Goblin.
    This file contains the constructor for creating the
    Goblin and all of the methods to update the current Goblins
    position, attack on another player, being attacked by 
    another player and printing out the current Goblins stats.

***********************************************************/

#include "Enemy.h"
int Enemy::uniqueID = 0;

//Constructor that creates the Enemy with all of its attributes
Enemy::Enemy(int hp, const int str, const int con, int xPos, int yPos):
    currentHealth(hp),
    strength(str),
    constitution(con),
    xLocation(xPos),
    yLocation(yPos)
{
    alive = true;
    uniqueID++;
    enemyID = uniqueID;
}

/**************************************************

    isAlive

    This function returns if the current enemy is
    alive or not.

    Parameters: None
    Return: boolean

**************************************************/

bool Enemy::isAlive() const
{
    return alive;
}