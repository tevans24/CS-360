/**********************************************************

    Taylor Evans
    CS 360
    Assignment 2

    This file is the .h file for the Enemy class.
    This file is the super class for all enemies and
    it contains all of the public method headers 
    and protected variable used within the enemy class.

***********************************************************/

#ifndef ENEMY_H
#define ENEMY_H

class Enemy
{
    public:
        Enemy(int, const int, const int, int, int); //Creates the enemy
        bool isAlive() const; //returns if the enemy is alive
        virtual void update() = 0; //pure virtual for updating the enemy
        virtual void attack() = 0; //pure virtual for attacking passerby
        virtual void injure(int) = 0; //pure virtual for passerby attcking enemy
        virtual void print() = 0; //pure virtual for printing enemy status

    protected:
        static int uniqueID; //static int for unique ID
        int enemyID; //ID for each enemy
        int currentHealth; //variable for current health
        const int strength; //variable for strength
        const int constitution; //variablel for constitution
        int xLocation; //variable for x location
        int yLocation; //variable for y location
        bool alive; //boolean for if enemy is alive

}; //end class enemy

#endif //ENEMY_H