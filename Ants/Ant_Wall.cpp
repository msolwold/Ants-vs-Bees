/**
 * Wall Ant
 * 
 * Cost: 4
 * Armor: 4
 * 
 * Action: Occupies a space blocking bees from passing. Cannot Attack
 * 
 */

#include <string>
#include <iostream>

#include "Ant_Wall.h"

using namespace std;

Ant_Wall::Ant_Wall()
{
    Ant::ant_type = "Wall";
    Ant::armor = 4;
    Ant::health = 4;
    Ant::cost = 4;
    Ant::proactive = false;
    Ant::attacker = false;
    Ant::blocking = true;
}

Ant_Wall *Ant_Wall::clone() const
{
    return new Ant_Wall(*this);
}

/**
 * Returns a string representing the action that the Ant has
 * 
 * @return string
 */
string Ant_Wall::get_ant_action() const 
{
    return "Prevents all Bees from moving to the next square.";
}

/**
 * Returns the initials of the Ant
 * 
 * @return string
 */
string Ant_Wall::get_ant_initials() const
{
    return "w";
}