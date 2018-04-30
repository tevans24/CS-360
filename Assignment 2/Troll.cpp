#include "Troll.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Troll::Troll() : Enemy(hp, str, con, xPos, yPos)
{
    maxHealth = hp;
}

void Troll::update()
{
    int randChoice = rand() % 1 + 1;
    if(randChoice == 1)
    {
        xLocation = xLocation + (rand() % 3 7);
    }
    else
    {
        xLocation = xLocation + (rand() % -3 -7);
    }

    if((currentHealth + constitution) > maxHealth)
    {
        currentHealth = maxHealth;
        cout << "Troll " << enemyID << " regenerates " << (maxHealth - currentHealth) << " health" << endl;
    }
    else
    {
        currentHealth = currentHealth + constitution;
        cout << "Troll " << enemyID << " regenerates " << constitution << " health" << endl;
    }
}

void Troll::attack()
{
    int myRandom = rand() % 7 + 1;
    int attackTotal = myRandom + strength;

    cout << "Troll " << enemyID << " attacks a random passerby for " << attackTotal << " damage!" << endl;
}

void Troll::injure(int damage)
{
    int passerbyDamage = damage - (constitution*1.5);

    if(passerbyDamage > 0)
    {
        currentHealth = currentHealth - passerbyDamage;
        if(currentHealth <= 0)
        {
            cout << "Troll has been slain!" << endl;
            isAlive = false;
        }
        else
        {
            cout << " Troll " << enemyID << " takes " << passerbyDamage << " damage! Current HP = " << currentHealth << endl;
        }
    }
    else
    {
        cout << "The passerby tries to attack Troll " << enemyID << ", but its not very effective..." << endl;
    }
}

void Troll::print()
{
    cout << "Troll " << enemyID << " @ (" << xLocation << "," << yLocation << ") hp = " << currentHealth << endl;
}