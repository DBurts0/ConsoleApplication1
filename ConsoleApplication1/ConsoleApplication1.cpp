// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <ctime>
#include "Character.h"
#include "Ninja.h"
#include "Pirate.h"
using namespace std;
int playerHealth;
int enemyHealth = 25;
int damage;
string actionType;
string playerSide;

int main()
{
    Character character;
    
    Ninja ninja;

    Pirate pirate;

    cout << "Will you play as a pirate or a ninja?\n";
    cin >> playerSide;
    if (playerSide == "pirate")
    {
        cout << "You are a pirate, what is your name?\n";
        cin >> character.name;
        cout << "\n Welcome " + character.name + ", the rest of the crew is aboard the ship.\n";
        playerHealth = pirate.health;
    }
    else if (playerSide == "ninja") {
        cout << "You are a ninja, what is your name?\n";
        cin >> character.name;
        cout << "\n Welcome " + character.name + ", the others are training inside the dojo.\n";
        playerHealth = ninja.health;
    }

    while (playerHealth > 0) {
        cout << "\nYou are under attack, will you fight or run? \n";
        cin >> actionType;
        if (actionType == "fight") {
            enemyHealth -= 5;
            cout << "You attack and deal 5 damage \n";
            if (enemyHealth > 0) {
                cout << "current enemy health:\n";
                cout << enemyHealth << endl;
                cout << "The enemy strikes back!\n";
                srand(time(0));
                damage = 1 + (rand() % 5);
                playerHealth -= damage;
                cout << damage << endl;
                cout << "current health: ";
                cout << playerHealth << endl;
            }
        }
        else if (actionType == "run") {
            cout << "You run away\n";
            playerHealth = 0;
        }
        else if (actionType == "help") {
            cout << "Type 'fight' to attack the enemy or 'run' to leave the battle.\n";

        }
        if (enemyHealth == 0) {
            cout << "Greate job " + character.name + "! You've defeated the enemy \n";
            cout << "Do you wish to continue? \n";
            cin >> actionType;
            if (actionType == "no") {
                playerHealth = 0;
            }
            else if (actionType == "yes")
            {
                cout << "You continue the fight\n";
            }
        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
