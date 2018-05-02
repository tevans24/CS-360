/**********************************************************

    Taylor Evans
    CS 360
    Assignment 2

    This file is the .cpp file for the Orc.
    This file contains the constructor for creating the
    Orc and all of the methods to update the current Orcs
    position, attack on another player, being attacked by 
    another player and printing out the current Orc stats.

***********************************************************/

#include "Orc.h"
#include <cstdlib>
#include <iostream>
using namespace std;

//Constructor that creates the Orc with all of its attributes
Orc::Orc(int hp, const int str, const int con, int xPos, int yPos) : Enemy(hp, str, con, xPos, yPos)
{
}

/**************************************************

    update

    This function updates the Orcs current
    location to move in a diagonal directing
    only. It moves the same amount in both x
    and y in both a positive and negative 
    direction of up to 5 or -5 units. The amount 
    moved is calculated by a random number generator.

    Parameters: None
    Return: void

**************************************************/

void Orc::update()
{
    int diagMove = rand() % 11 - 5; //Random number to set x and y location
    xLocation = xLocation + (diagMove); //Sets x location
    yLocation = yLocation + (diagMove); //Sets y location
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

void Orc::attack()
{
    int myRandom = rand() % 6 + 1;
    int attackTotal = myRandom + strength; //Sets attack total for passerby

    cout << "Orc " << enemyID << " attacks a random passerby for " << attackTotal << " damage!" << endl;
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
    int passerbyDamage = damage - constitution;

    if(passerbyDamage > 0) //Checks to see if passerby damage is greater than 0
    {
        currentHealth = currentHealth - passerbyDamage; //Sets new current health
        if(currentHealth <= 0)
        {
            cout << "Orc has been slain!" << endl;
            alive = false;
        }
        else
        {
            cout << "Orc " << enemyID << " takes " << passerbyDamage << " damage! Current HP = " << currentHealth << endl;
        }
    }
    else //If passerby damage is less than 0, no attack is done
    {
        cout << "The passerby tries to attack Orc " << enemyID << ", but its not very effective..." << endl;
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

void Orc::print()
{
    cout << "Orc " << enemyID << " @ (" << xLocation << "," << yLocation << ") hp = " << currentHealth << endl;
}