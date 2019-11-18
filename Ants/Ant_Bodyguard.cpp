/**
 * Bodyguard Ant
 * 
 * Cost: 4
 * Armor: 2
 * 
 * Action: Absorbs damage. Can share a square with another ant. Cannot Attack. 
 * 
 */

#include <string>
#include <iostream>

#include "Ant_Bodyguard.h"

using namespace std;

Ant_Bodyguard::Ant_Bodyguard()
{
    Ant::ant_type = "Bodyguard";
    Ant::armor = 2;
    Ant::health = 2;
    Ant::cost = 4;
    Ant::proactive = false;
    Ant::attacker = false;
    Ant::blocking = true;
}

Ant_Bodyguard *Ant_Bodyguard::clone() const
{
    return new Ant_Bodyguard(*this);
}

/**
 * Returns a string representing the action that the Ant has
 * 
 * @return string
 */
string Ant_Bodyguard::get_ant_action() const 
{
    return "Protects Ants from attacks by absorbing all Bee attacks. May only share a square with an Ant that is not a Bodyguard.";
}

/**
 * Returns the initials of the Ant
 * 
 * @return string
 */
string Ant_Bodyguard::get_ant_initials() const
{
    return "b";
}