/**
 * Bodyguard Ant
 * 
 * Cost: 4
 * Armor: 2
 * 
 * Action: Absorbs damage. Can share a square with another ant. Cannot Attack. 
 * 
 */

#include <string>
#include <iostream>

#include "Ant_Bodyguard.h"

using namespace std;

Ant_Bodyguard::Ant_Bodyguard(){

    Ant::ant_type = "Bodyguard";
    Ant::armor = 2;
    Ant::health = armor;
    Ant::cost = 4;
    Ant::proactive = false;
    Ant::attacker = false;
    Ant::blocking = true;
}

Ant_Bodyguard * Ant_Bodyguard::clone() const { 
    return new Ant_Bodyguard(*this);
}