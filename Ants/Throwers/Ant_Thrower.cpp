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

Ant_Thrower::Ant_Thrower()
{
    Ant::ant_type = "Thrower";
    Ant::armor = 1;
    Ant::health = 1;
    Ant::cost = 4;

    Throwers::min_range = 0;
    Throwers::max_range = 0;
}

Ant_Thrower * Ant_Thrower::clone() const
{
    return new Ant_Thrower(*this);
}

/**
 * Returns a string representing the action that the Ant has
 * 
 * @return string
 */
string Ant_Thrower::get_ant_action() const 
{
    return "Throws a leaf at a closest bee that is also sharing a square with it";
}

/**
 * Returns the initials of the Ant
 * 
 * @return string
 */
string Ant_Thrower::get_ant_initials() const
{
    return "t";
}