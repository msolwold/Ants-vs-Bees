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

Ant_ShortThrower::Ant_ShortThrower()
{
    Ant::ant_type = "ShortThrower";
    Ant::armor = 1;
    Ant::health = 1;
    Ant::cost = 3;

    Throwers::min_range = 0;
    Throwers::max_range = 2;
}

Ant_ShortThrower * Ant_ShortThrower::clone() const
{
    return new Ant_ShortThrower(*this);
}

/**
 * Returns a string representing the action that the Ant has
 * 
 * @return string
 */
string Ant_ShortThrower::get_ant_action() const 
{
    return "Throws a pebble dealing 1 damage to the Bee that is closest to it but no more than 2 squares away";
}

/**
 * Returns the initials of the Ant
 * 
 * @return string
 */
string Ant_ShortThrower::get_ant_initials() const
{
    return "st";
}