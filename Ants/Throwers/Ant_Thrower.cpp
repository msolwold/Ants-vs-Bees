/**
 * Thrower Ant
 * 
 * Cost: 4
 * Armor: 1
 * 
 * Action: Damage a bee in its square for 1 damage
 * 
 */

#include <string>
#include <iostream>

#include "Ant_Thrower.h"

using namespace std;

Ant_Thrower::Ant_Thrower(){

    Ant::ant_type = "Thrower";
    Ant::armor = 1;
    Ant::health = armor;
    Ant::cost = 4;

    Throwers::min_range = 0;
    Throwers::max_range = 0;
}


Ant_Thrower * Ant_Thrower::clone() const {
    return new Ant_Thrower(*this);
}