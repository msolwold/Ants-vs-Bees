/**
 * Long Thrower Ant
 * 
 * Cost: 3
 * Armor: 1
 * 
 * Action: Damage Closest bee that is at least 4 squares away
 * 
 */

#include <string>
#include <iostream>

#include "Ant_LongThrower.h"

using namespace std;

Ant_LongThrower::Ant_LongThrower(){

    Ant::ant_type = "LongThrower";
    Ant::armor = 1;
    Ant::health = armor;
    Ant::cost = 3;

    Throwers::min_range = 4;
    Throwers::max_range = 10;
}