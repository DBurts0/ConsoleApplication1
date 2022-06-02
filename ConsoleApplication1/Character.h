#pragma once
using namespace std;
class Character
{
private:
    int health = 50;
public:
    string name;
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

