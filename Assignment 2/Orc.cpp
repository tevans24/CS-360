#include "Orc.h"
#include <cstdlib>
using namespace std;

Orc::Orc() : Enemy(hp, str, con, xPos, yPos)
{
}

void Orc::update()
{
    int diagMove = rand() % 10 -5;
    xLocation = xLocation + (diagMove);
    yLocation = yLocation + (diagMove);
}

void Orc::attack()
{
    int myRandom = rand() % 5 + 1;
    int attackTotal = myRandom + strength;

    cout << "Orc " << enemyID << " attacks a random passerby for " << attackTotal << " damage!" << endl;
}

void Orc::injure(int damage)
{
    int passerbyDamage = damage - constitution;

    if(passerbyDamage > 0)
    {
        currentHealth = currentHealth - passerbyDamage;
        if(currentHealth <= 0)
        {
            cout << "Orc has been slain!" << endl;
            isAlive = false;
        }
        else
        {
            cout << " Orc " << enemyID << " takes " << passerbyDamage << " damage! Current HP = " << currentHealth << endl;
        }
    }
    else
    {
        cout << "The passerby tries to attack Orc " << enemyID << ", but its not very effective..." << endl;
    }
}

void Orc::print()
{
    cout << "Orc " << enemyID << " @ (" << xLocation << "," << yLocation << ") hp = " << currentHealth << endl;
}