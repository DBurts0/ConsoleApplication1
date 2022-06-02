#pragma once
#include "Character.h"
using namespace std;
class Ninja : public Character
{
public:
    void Attack() {
        cout << "Throwing stars!\n";
    }
    int damage = 10;

    Character character;
    int health = character.getHealth();
        
};

