#pragma once
using namespace std;
class Character
{
    // set the player's health to 50
private:
    int health = 50;
public:
    string name;
    // functions for allowing child classes to access the health variable
    void setHealth(int hp) {
        health = hp;
    }
    int getHealth() {
        return health;
    }
    void Attack()
    {
        
    }
};

