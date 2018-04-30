#include "Enemy.h"
using namespace std;

Enemy::Enemy(int hp, const int str, const int con, int xPos, int yPos):
    currentHealth(hp),
    strength(str),
    constitution(con),
    xLocation(xPos),
    yLocation(yPos)
{
    alive = true;
    uniqueID++;
    enemyID = uniqueID;
}

bool Enemy::isAlive()
{
    return alive;
}