/**
 * Harvester Ant
 * Sunflower
 * 
 * Cost: 2
 * Armor: 1
 * 
 * Action: Generates 1 food every turn
 * 
 */

#include <string>
#include <iostream>

#include "Ant_Harvester.h"

using namespace std;

Ant_Harvester::Ant_Harvester(){

    Ant::ant_type = "Harvester";
    Ant::armor = 1;
    Ant::health = armor;
    Ant::cost = 2;
    Ant::proactive = true;
    Ant::attacker = false;
    Ant::blocking = true;
}

Ant_Harvester * Ant_Harvester::clone() const {
    return new Ant_Harvester(*this);
}
