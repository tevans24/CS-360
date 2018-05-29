/**********************************************************

    Taylor Evans
    CS 360
    Assignment 3

    This file is the .cpp file for the Troll.
    This file contains the constructor for creating the
    Troll and all of the methods to update the current Trolls
    position, attack on another player, being attacked by 
    another player and printing out the current Troll stats.

    Update 5/28/18 by Taylor Evans

    The file has been udpated to add a get char method that
    returns the char of the enemy.

***********************************************************/

#include "Troll.h"
#include "GameBoard.h"
#include <cstdlib>
#include <iostream>
using namespace std;

//Constructor that creates the Troll with all of its attributes
Troll::Troll(int hp, int str, int con, int xPos, int yPos) : Enemy(hp, str, con, xPos, yPos)
{
    maxHealth = hp;
    print();
}

/**************************************************

    update

    This function updates the Trolls current
    location to move along the x axis only.
    It can move between 7-10 units or negative
    7-10 units. The amount moved is calculated
    by a random number generator.

    It also now validates that the enemies are not
    allowed to move to a location that is not on the
    gameboard.

    Parameters: None
    Return: void

**************************************************/

extern GameBoard *gb;
void Troll::update()
{

    cout << "Troll " << id << " previous position @ (" << xPosition << "," << yPosition << ") hp = " << health << endl;

    if(yPosition > gb->getYpos())
    {
        yPosition = gb->getYpos();
    }
    else if(yPosition < (gb->getYpos()) * -1)
    {
        yPosition = (gb->getYpos()) * -1;
    }
    
    int randChoice = rand() % 2; //Gets random number of either 0 or 1
    if(randChoice == 1)
    {
        xPosition = xPosition + (rand() % 4 + 7); //Sets x location to positive
        if(xPosition > gb->getXpos())
        {
            xPosition = gb->getXpos();
        }
    }
    else
    {
        xPosition = xPosition + (rand() % -4 - 7); //Sets x location to negative
        if(xPosition < (gb->getXpos()) * -1)
        {
            xPosition = (gb->getXpos()) * -1;
        }
    }

    if((health + con) > maxHealth)
    {
        cout << "Troll " << id << " regenerates " << (maxHealth - health) << " health" << endl;
        health = maxHealth;
    }
    else
    {
        health = health + con;
        cout << "Troll " << id << " regenerates " << con << " health" << endl;
    }
}

/**************************************************

    attack

    This function calculates a random number 
    between 1 and 8. That number is the added to
    the strength of the Troll to get an attack total.
    The attack total is then used to attack a 
    random passerby.

    Parameters: None
    Return: void

**************************************************/

void Troll::attack() const
{
    int myRandom = rand() % 8 + 1;
    int attackTotal = myRandom + str; //Sets attack total for passerby

    cout << "Troll " << id << " attacks a random passerby for " << attackTotal << " damage!" << endl;
}

/**************************************************

    injure

    This function takes a random number that is passed
    in to be passed in as damage. This number then
    multiplies the Troll constitution by 1.5 and that 
    number total is what is used to attack the Troll.
    If the Trolls health reaches 0 then it has been slain.

    Parameters: int - int value for damage done to Troll
    Return: void

**************************************************/

void Troll::injure(int damage)
{
    int passerbyDamage = damage - (con*1.5);

    if(passerbyDamage > 0) //Checks to see if passerby damage is greater than 0
    {
        health = health - passerbyDamage; //Sets new current health
        if(health <= 0)
        {
            cout << "Troll has been slain!" << endl;
            alive = false;
        }
        else
        {
            cout << "Troll " << id << " takes " << passerbyDamage << " damage! Current HP = " << health << endl;
        }
    }
    else //If passerby damage is less than 0, no attack is done
    {
        cout << "The passerby tries to attack Troll " << id << ", but its not very effective..." << endl;
    }
}

/**************************************************

    print

    This function prints out the current status of the
    Troll which includes the name, unique ID, current x 
    and y location and its current health.
    
    Parameters: none
    Return: void

**************************************************/

void Troll::print() const
{
    cout << "Troll " << id << " current position @ (" << xPosition << "," << yPosition << ") hp = " << health << endl;
}

/**************************************************

    getDisplayChar

    This function returns the char of the enemy and
    the char is capital if they are alive and lowercase
    if they are not alive.

    Parameters: None
    Return: char

**************************************************/

const char Troll::getDisplayChar() const
{
    if(alive == true)
    {
        return 'T';
    }
    else
    {
        return 't';
    }
}