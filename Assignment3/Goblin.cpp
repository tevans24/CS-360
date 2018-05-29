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

    The file has been udpated to add a get char method that
    returns the char of the enemy.

***********************************************************/

#include "Goblin.h"
#include "GameBoard.h"
#include <cstdlib>
#include <iostream>
using namespace std;

//Constructor that creates the Goblin with all of its attributes
Goblin::Goblin(int hp, int str, int con, int xPos, int yPos) : Enemy(hp, str, con, xPos, yPos)
{
    print();
}

/**************************************************

    update

    This function updates the Goblins current
    location to move along the x and y axis.
    It can move between -3 and 3 units on the x
    axis and -2 and 2 on the y axis. The amount 
    moved is calculated by a random number generator.

    It also now validates that the enemies are not
    allowed to move to a location that is not on the
    gameboard.

    Parameters: None
    Return: void

**************************************************/

extern GameBoard *gb;
void Goblin::update()
{
    cout << "Goblin " << id << " previous position @ (" << xPosition << "," << yPosition << ") hp = " << health << endl;
    
    xPosition = xPosition + (rand() % 7 - 3); //Sets x location
    if(xPosition > gb->getXpos())
    {
        xPosition = gb->getXpos();
    }
    else if(xPosition < (gb->getXpos()) * -1)
    {
        xPosition = (gb->getXpos()) * -1;
    }
    
    yPosition = yPosition + (rand() % 5 - 2); //Sets y location
    if(yPosition > gb->getYpos())
    {
        yPosition = gb->getYpos();
    }
    else if(yPosition < (gb->getYpos()) * -1)
    {
        yPosition = (gb->getYpos()) * -1;
    }
}

/**************************************************

    attack

    This function calculates a random number 
    between 1 and 4. That number is the added to
    the strength of the Goblin to get an attack total.
    The attack total is then used to attack a 
    random passerby.

    Parameters: None
    Return: void

**************************************************/

void Goblin::attack() const
{
    int myRandom = rand() % 4 + 1;
    int attackTotal = myRandom + str; //Sets attack total for passerby

    cout << "Goblin " << id << " attacks a random passerby for " << attackTotal << " damage!" << endl;
}

/**************************************************

    injure

    This function takes a random number that is passed
    in to be passed in as damage. This number then
    divides the Goblin constitution by 2 and that 
    number total is what is used to attack the Goblin.
    If the Goblins health reaches 0 then it has been slain.

    Parameters: int - int value for damage done to Goblin
    Return: void

**************************************************/

void Goblin::injure(int damage)
{
    int passerbyDamage = damage - (con/2);

    if(passerbyDamage > 0) //Checks to see if passerby damage is greater than 0
    {
        health = health - passerbyDamage; //Sets new current health
        if(health <= 0)
        {
            cout << "Goblin has been slain!" << endl;
            alive = false;
        }
        else
        {
            cout << "Goblin " << id << " takes " << passerbyDamage << " damage! Current HP = " << health << endl;
        }
    }
    else //If passerby damage is less than 0, no attack is done
    {
        cout << "The passerby tries to attack Goblin " << id << ", but its not very effective..." << endl;
    }
}

/**************************************************

    print

    This function prints out the current status of the
    Goblin which includes the name, unique ID, current x 
    and y location and its current health.
    
    Parameters: none
    Return: void

**************************************************/

void Goblin::print() const
{
    cout << "Goblin " << id << " current position @ (" << xPosition << "," << yPosition << ") hp = " << health << endl;
}

/**************************************************

    getDisplayChar

    This function returns the char of the enemy and
    the char is capital if they are alive and lowercase
    if they are not alive.

    Parameters: None
    Return: char

**************************************************/

const char Goblin::getDisplayChar() const
{
    if(alive == true)
    {
        return 'G';
    }
    else
    {
        return 'g';
    }
}