/**
 * Fire Ant
 * 
 * Cost: 4
 * Armor: 1
 * 
 * Action: On death kills all bees in its square
 * 
 */ 

#include <string>
#include <iostream>

#include "Ant_Fire.h"

using namespace std;

Ant_Fire::Ant_Fire(){

    Ant::ant_type = "Fire";
    Ant::armor = 1;
    Ant::health = armor;
    Ant::cost = 4;
    Ant::proactive = false;
    Ant::attacker = false;
    Ant::blocking = true;
}

Ant_Fire * Ant_Fire::clone() const { 
    return new Ant_Fire(*this);
}