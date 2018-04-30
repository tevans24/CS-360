#ifndef TROLL_H
#define TROLL_H

#include "Enemy.h"

class Troll : public Enemy
{
    public:
        void update();
        void attack();
        void injure(int);
        void print();

    protected:
        int maxHealth;
};
#endif