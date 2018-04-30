#ifndef ENEMY_H
#define ENEMY_H

class Enemy
{
    public:
        Enemy(int, const int, const int, int, int);
        bool isAlive() const;
        virtual void update() = 0;
        virtual void attack() = 0;
        virtual void injure(int) = 0;
        virtual void print() = 0;

    protected:
        static int uniqueID = 0;
        int enemyID = 0
        int currentHealth;
        const int strength;
        const int constitution;
        int xLocation
        int yLocation;
        bool alive;

} //end class enemy

#endif //ENEMY_H