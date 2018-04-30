#ifndef ORC_H
#define ORC_H

#include "Enemy.h"

class Orc : public Enemy
{
    public:
        void update();
        void attack();
        void injure(int);
        void print();
};
#endif