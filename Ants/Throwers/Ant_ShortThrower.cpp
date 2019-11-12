/**
 * Short Thrower Ant
 * 
 * Cost: 3
 * Armor: 1
 * 
 * Action: Damage closest bee that is at most 2 squares away
 * 
 */

#include <string>
#include <iostream>

#include "Ant_ShortThrower.h"

using namespace std;

Ant_ShortThrower::Ant_ShortThrower(){

    Ant::ant_type = "ShortThrower";
    Ant::armor = 1;
    Ant::health = armor;
    Ant::cost = 3;

    Throwers::min_range = 0;
    Throwers::max_range = 2;
}