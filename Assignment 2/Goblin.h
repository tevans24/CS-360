#ifndef GOBLIN_H
#define GOBLIN_H

#include "Enemy.h"

class Goblin : public Enemy
{
    public:
        void update();
        void attack();
        void injure(int);
        void print();
};
#endif