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

#include "Goblin.h"
#include <cstdlib>
#include <iostream>
using namespace std;

//Constructor that creates the Goblin with all of its attributes
Goblin::Goblin(int hp, const int str, const int con, int xPos, int yPos) : Enemy(hp, str, con, xPos, yPos)
{
}

/**************************************************

    update

    This function updates the Goblins current
    location to move along the x and y axis.
    It can move between -3 and 3 units on the x
    axis and -2 and 2 on the y axis. The amount 
    moved is calculated by a random number generator.

    Parameters: None
    Return: void

**************************************************/

void Goblin::update()
{
    xLocation = xLocation + (rand() % 7 - 3); //Sets x location
    yLocation = yLocation + (rand() % 5 - 2); //Sets y location
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

void Goblin::attack()
{
    int myRandom = rand() % 4 + 1;
    int attackTotal = myRandom + strength; //Sets attack total for passerby

    cout << "Goblin " << enemyID << " attacks a random passerby for " << attackTotal << " damage!" << endl;
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
    int passerbyDamage = damage - (constitution/2);

    if(passerbyDamage > 0) //Checks to see if passerby damage is greater than 0
    {
        currentHealth = currentHealth - passerbyDamage; //Sets new current health
        if(currentHealth <= 0)
        {
            cout << "Goblin has been slain!" << endl;
            alive = false;
        }
        else
        {
            cout << "Goblin " << enemyID << " takes " << passerbyDamage << " damage! Current HP = " << currentHealth << endl;
        }
    }
    else //If passerby damage is less than 0, no attack is done
    {
        cout << "The passerby tries to attack Goblin " << enemyID << ", but its not very effective..." << endl;
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

void Goblin::print()
{
    cout << "Goblin " << enemyID << " @ (" << xLocation << "," << yLocation << ") hp = " << currentHealth << endl;
}