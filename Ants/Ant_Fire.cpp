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

Ant_Fire::Ant_Fire()
{
    Ant::ant_type = "Fire";
    Ant::armor = 1;
    Ant::health = 1;
    Ant::cost = 4;
    Ant::proactive = false;
    Ant::attacker = false;
    Ant::blocking = true;
}

Ant_Fire *Ant_Fire::clone() const
{
    return new Ant_Fire(*this);
}

/**
 * Returns a string representing the action that the Ant has
 * 
 * @return string
 */
string Ant_Fire::get_ant_action() const 
{
    return "When this Ant is killed, all Bees that share the square will be killed with it.";
}

/**
 * Returns the initials of the Ant
 * 
 * @return string
 */
string Ant_Fire::get_ant_initials() const
{
    return "f";
}