// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <ctime>
#include "Character.h"
#include "Ninja.h"
#include "Pirate.h"
using namespace std;
// variables for storing the player's and the enemy's health
int playerHealth;
int enemyHealth = 25;
// variable for how much damage the enemies do
int damage;
// variables for player input
string actionType;
string playerSide;

int main()
{
    // variables for accessing classes
    Character character;
    
    Ninja ninja;

    Pirate pirate;

    // ask the player which side this wish to fight for and their name
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
    // ask the player which action they wish to do each round
    while (playerHealth > 0) {
        cout << "\nYou are under attack, will you fight or run? \n";
        cin >> actionType;
        // attack the enemy for 5 damage
        if (actionType == "fight") {
            enemyHealth -= 5;
            cout << "You attack and deal 5 damage \n";
            if (enemyHealth > 0) {
                cout << "current enemy health:\n";
                cout << enemyHealth << endl;
                // have the enemy deal a random amount of damage between 0 and 5
                cout << "The enemy strikes back!\n";
                srand(time(0));
                damage = 1 + (rand() % 5);
                playerHealth -= damage;
                cout << damage << endl;
                // display the player's current health
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
                // reset the enemy's health and begin a new battle
                cout << "You continue the fight\n";
                enemyHealth = 25;
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
