/**
 * Ninja Ant
 * 
 * Cost: 6
 * Armor: 1
 * 
 * Action: Deal 1 damage to all bees that pass. Cannot Block bees and Bees cannot attack the ant
 * 
 */

#include <string>
#include <iostream>

#include "Ant_Ninja.h"

using namespace std;

Ant_Ninja::Ant_Ninja(){

    Ant::ant_type = "Ninja";
    Ant::armor = 1;
    Ant::health = armor;
    Ant::cost = 6;
    Ant::proactive = false;
    Ant::attacker = true;
    Ant::blocking = false;
}