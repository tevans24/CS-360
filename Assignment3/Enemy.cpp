/**********************************************************

    Taylor Evans
    CS 360
    Assignment 3

    This file is the .cpp file for the Goblin.
    This file contains the constructor for creating the
    Goblin and all of the methods to update the current Goblins
    position, attack on another player, being attacked by 
    another player and printing out the current Goblins stats.

    Update 5/28/18 by Taylor Evans

    The file has been udpated to add getters for the 
    enemy variables.

***********************************************************/

#include "Enemy.h"
int Enemy::idGenerator = 0;

//Constructor that creates the Enemy with all of its attributes
Enemy::Enemy(int hp, int str, int con, int xPos, int yPos):
    health(hp),
    str(str),
    con(con),
    xPosition(xPos),
    yPosition(yPos)
{
    alive = true;
    idGenerator++;
    id = idGenerator;
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

/**************************************************

    getID

    This function returns the ID of the enemy

    Parameters: None
    Return: int

**************************************************/

int Enemy::getId() const
{
    return id;
}

/**************************************************

    getHealth

    This function returns the health of the enemy

    Parameters: None
    Return: int

**************************************************/

int Enemy::getHealth() const
{
    return health;
}

/**************************************************

    getStr

    This function returns the strength of the enemy

    Parameters: None
    Return: int

**************************************************/

int Enemy::getStr() const
{
    return str;
}

/**************************************************

    getCon

    This function returns the constitution of the enemy

    Parameters: None
    Return: int

**************************************************/

int Enemy::getCon() const
{
    return con;
}

/**************************************************

    getX

    This function returns the x location of the enemy

    Parameters: None
    Return: int

**************************************************/

int Enemy::getX() const
{
    return xPosition;
}

/**************************************************

    getID

    This function returns the y position of the enemy

    Parameters: None
    Return: int

**************************************************/

int Enemy::getY() const
{
    return yPosition;
}