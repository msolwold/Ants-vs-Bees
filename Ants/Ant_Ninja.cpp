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

Ant_Ninja::Ant_Ninja()
{
    Ant::ant_type = "Ninja";
    Ant::armor = 1;
    Ant::health = 1;
    Ant::cost = 6;
    Ant::proactive = false;
    Ant::attacker = true;
    Ant::blocking = false;
}

Ant_Ninja *Ant_Ninja::clone() const
{
    return new Ant_Ninja(*this);
}

/**
 * Returns a string representing the action that the Ant has
 * 
 * @return string
 */
string Ant_Ninja::get_ant_action() const 
{
    return "Hides in the dirt unable to be seen by the Bees. Uses a splinter to stab any Bee that moves past dealing 1 damage.";
}

/**
 * Returns the initials of the Ant
 * 
 * @return string
 */
string Ant_Ninja::get_ant_initials() const
{
    return "n";
}