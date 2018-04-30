#include "Goblin.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Goblin::Goblin() : Enemy(hp, str, con, xPos, yPos)
{
}

void Goblin::update()
{
    xLocation = xLocation + (rand() % 6 -3);
    yLocation = yLocation + (rand() % 4 -2);
}

void Goblin::attack()
{
    int myRandom = rand() % 3 + 1;
    int attackTotal = myRandom + strength;

    cout << "Goblin " << enemyID << " attacks a random passerby for " << attackTotal << " damage!" << endl;
}

void Goblin::injure(int damage)
{
    int passerbyDamage = damage - (constitution/2);

    if(passerbyDamage > 0)
    {
        currentHealth = currentHealth - passerbyDamage;
        if(currentHealth <= 0)
        {
            cout << "Goblin has been slain!" << endl;
            isAlive = false;
        }
        else
        {
            cout << " Goblin " << enemyID << " takes " << passerbyDamage << " damage! Current HP = " << currentHealth << endl;
        }
    }
    else
    {
        cout << "The passerby tries to attack Goblin " << enemyID << ", but its not very effective..." << endl;
    }
}

void Goblin::print()
{
    cout << "Goblin " << enemyID << " @ (" << xLocation << "," << yLocation << ") hp = " << currentHealth << endl;
}