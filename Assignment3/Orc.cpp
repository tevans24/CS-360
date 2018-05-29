/**********************************************************

    Taylor Evans
    CS 360
    Assignment 3

    This file is the .cpp file for the Orc.
    This file contains the constructor for creating the
    Orc and all of the methods to update the current Orcs
    position, attack on another player, being attacked by 
    another player and printing out the current Orc stats.

    Update 5/28/18 by Taylor Evans

    The file has been udpated to add a get char method that
    returns the char of the enemy.

***********************************************************/

#include "Orc.h"
#include "GameBoard.h"
#include <cstdlib>
#include <iostream>
using namespace std;

//Constructor that creates the Orc with all of its attributes
Orc::Orc(int hp, int str, int con, int xPos, int yPos) : Enemy(hp, str, con, xPos, yPos)
{
    print();
}

/**************************************************

    update

    This function updates the Orcs current
    location to move in a diagonal directing
    only. It moves the same amount in both x
    and y in both a positive and negative 
    direction of up to 5 or -5 units. The amount 
    moved is calculated by a random number generator.

    It also now validates that the enemies are not
    allowed to move to a location that is not on the
    gameboard.

    Parameters: None
    Return: void

**************************************************/

extern GameBoard *gb;
void Orc::update()
{
    cout << "Orc " << id << " previous position @ (" << xPosition << "," << yPosition << ") hp = " << health << endl;

    int diagMove = rand() % 11 - 5; //Random number to set x and y location
    xPosition = xPosition + (diagMove); //Sets x location
    if(xPosition > gb->getXpos())
    {
        xPosition = gb->getXpos();
    }
    else if(xPosition < (gb->getXpos()) * -1)
    {
        xPosition = (gb->getXpos()) * -1;
    }
    
    yPosition = yPosition + (diagMove); //Sets y location
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
    between 1 and 6. That number is the added to
    the strength of the Orc to get an attack total.
    The attack total is then used to attack a 
    random passerby.

    Parameters: None
    Return: void

**************************************************/

void Orc::attack() const
{
    int myRandom = rand() % 6 + 1;
    int attackTotal = myRandom + str; //Sets attack total for passerby

    cout << "Orc " << id << " attacks a random passerby for " << attackTotal << " damage!" << endl;
}

/**************************************************

    injure

    This function takes a random number that is passed
    in to be passed in as damage. This number then
    subtracts the Orc constitution from it and that 
    number total is what is used to attack the Orc.
    If the Orcs health reaches 0 then it has been slain.

    Parameters: int - int value for damage done to Orc
    Return: void

**************************************************/

void Orc::injure(int damage)
{
    int passerbyDamage = damage - con;

    if(passerbyDamage > 0) //Checks to see if passerby damage is greater than 0
    {
        health = health - passerbyDamage; //Sets new current health
        if(health <= 0)
        {
            cout << "Orc has been slain!" << endl;
            alive = false;
        }
        else
        {
            cout << "Orc " << id << " takes " << passerbyDamage << " damage! Current HP = " << health << endl;
        }
    }
    else //If passerby damage is less than 0, no attack is done
    {
        cout << "The passerby tries to attack Orc " << id << ", but its not very effective..." << endl;
    }
}

/**************************************************

    print

    This function prints out the current status of the
    Orc which includes the name, unique ID, current x 
    and y location and its current health.

    Parameters: none
    Return: void

**************************************************/

void Orc::print() const
{
    cout << "Orc " << id << " current position @ (" << xPosition << "," << yPosition << ") hp = " << health << endl;
}

/**************************************************

    getDisplayChar

    This function returns the char of the enemy and
    the char is capital if they are alive and lowercase
    if they are not alive.

    Parameters: None
    Return: char

**************************************************/

const char Orc::getDisplayChar() const
{
    if(alive == true)
    {
        return 'O';
    }
    else
    {
        return 'o';
    }
}