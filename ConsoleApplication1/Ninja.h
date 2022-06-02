#pragma once
#include "Character.h"
using namespace std;
class Ninja : public Character
{
    // 
public:
    void Attack() {
        cout << "Throwing stars!\n";
    }
    // access the health variable in the parent class
    Character character;
    int health = character.getHealth();
        
};

