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

Ant_LongThrower::Ant_LongThrower()
{ 
    Ant::ant_type = "LongThrower";
    Ant::armor = 1;
    Ant::health = 1;
    Ant::cost = 3;

    Throwers::min_range = 4;
    Throwers::max_range = 1000;
}

Ant_LongThrower * Ant_LongThrower::clone() const
{
    return new Ant_LongThrower(*this);
}

/**
 * Returns a string representing the action that the Ant has
 * 
 * @return string
 */
string Ant_LongThrower::get_ant_action() const 
{
    return "Throws a pointy twig dealing 1 damage to the Bee that is closest to it but at least 4 squares away.";
}

/**
 * Returns the initials of the Ant
 * 
 * @return string
 */
string Ant_LongThrower::get_ant_initials() const
{
    return "lt";
}