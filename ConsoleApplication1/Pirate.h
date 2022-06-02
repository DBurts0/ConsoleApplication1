#pragma once
#include "Character.h"
using namespace std;
class Pirate : public Character
{
public:
    void Attack() {
        cout << "Swinging sword!\n";
    }
    // access the health variable in the parent class
    Character character;
    int health = character.getHealth();
};

