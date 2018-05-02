/**********************************************************

    Taylor Evans
    CS 360
    Assignment 2

    This file is the .cpp file for the Troll.
    This file contains the constructor for creating the
    Troll and all of the methods to update the current Trolls
    position, attack on another player, being attacked by 
    another player and printing out the current Troll stats.

***********************************************************/

#include "Troll.h"
#include <cstdlib>
#include <iostream>
using namespace std;

//Constructor that creates the Troll with all of its attributes
Troll::Troll(int hp, const int str, const int con, int xPos, int yPos) : Enemy(hp, str, con, xPos, yPos)
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

    Parameters: None
    Return: void

**************************************************/

void Troll::update()
{
    int randChoice = rand() % 2; //Gets random number of either 0 or 1
    if(randChoice == 1)
    {
        xLocation = xLocation + (rand() % 4 + 7); //Sets x location to positive
    }
    else
    {
        xLocation = xLocation + (rand() % -4 - 7); //Sets x location to negative
    }

    if((currentHealth + constitution) > maxHealth)
    {
        cout << "Troll " << enemyID << " regenerates " << (maxHealth - currentHealth) << " health" << endl;
        currentHealth = maxHealth;
    }
    else
    {
        currentHealth = currentHealth + constitution;
        cout << "Troll " << enemyID << " regenerates " << constitution << " health" << endl;
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

void Troll::attack()
{
    int myRandom = rand() % 8 + 1;
    int attackTotal = myRandom + strength; //Sets attack total for passerby

    cout << "Troll " << enemyID << " attacks a random passerby for " << attackTotal << " damage!" << endl;
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
    int passerbyDamage = damage - (constitution*1.5);

    if(passerbyDamage > 0) //Checks to see if passerby damage is greater than 0
    {
        currentHealth = currentHealth - passerbyDamage; //Sets new current health
        if(currentHealth <= 0)
        {
            cout << "Troll has been slain!" << endl;
            alive = false;
        }
        else
        {
            cout << "Troll " << enemyID << " takes " << passerbyDamage << " damage! Current HP = " << currentHealth << endl;
        }
    }
    else //If passerby damage is less than 0, no attack is done
    {
        cout << "The passerby tries to attack Troll " << enemyID << ", but its not very effective..." << endl;
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

void Troll::print()
{
    cout << "Troll " << enemyID << " @ (" << xLocation << "," << yLocation << ") hp = " << currentHealth << endl;
}