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

Ant_Harvester::Ant_Harvester()
{
    Ant::ant_type = "Harvester";
    Ant::armor = 1;
    Ant::health = 1;
    Ant::cost = 2;
    Ant::proactive = true;
    Ant::attacker = false;
    Ant::blocking = true;

    generated_resource = false;
}

Ant_Harvester *Ant_Harvester::clone() const
{
    return new Ant_Harvester(*this);
}

/**
 * Returns a string representing the action that the Ant has
 * 
 * @return string
 */
string Ant_Harvester::get_ant_action() const 
{
    return "Generates 1 fruit at the end of each turn.";
}

/**
 * Returns the initials of the Ant
 * 
 * @return string
 */
string Ant_Harvester::get_ant_initials() const
{
    return "h";
}
