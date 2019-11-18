/**
 * Ant Class
 * 
 * Can place a new ant every round assuming food level is sufficient
 * 
 * There are 8 types of ants with varying actions, damage, and armor
 * 
 * Ants protect the queen ant, far left, from the spawning bees, far right.
 */

#include <string>
#include <iostream>

#include "Ant.h"

using namespace std;

Ant::Ant()
{
    alive = true;
}

Ant::Ant(const Ant &a)
{
    Ant::ant_type = a.ant_type;
    Ant::armor = a.armor;
    Ant::health = a.health;
    Ant::cost = a.cost;
    Ant::blocking = a.blocking;
    Ant::proactive = a.proactive;
    Ant::attacker = a.attacker;
    Ant::alive = a.alive;
}

// * Accessors

/**
 * Returns a string representing the Ant Type
 * 
 * @return string
 */
string Ant::get_ant_type() const
{
    return ant_type;
}

/**
 * Returns the health of the current ant
 * 
 * @return int
 */
int Ant::get_ant_health() const
{
    return health;
}

/**
 * Returns the armor of the current Ant
 * 
 * @return int
 */
int Ant::get_ant_armor() const
{
    return armor;
}

/**
 * Returns the cost of the ant
 * 
 * @return int
 */
int Ant::get_ant_cost() const
{
    return cost;
}

/**
 * Returns true if the ants health is greater than or equal to 0
 * 
 * @return bool
 */
bool Ant::isAlive() const
{
    return health >=0;
}

/**
 * Returns true if the Ant blocks bees from passing through the square
 * 
 * @return bool
 */
bool Ant::isBlocking() const
{
    return blocking;
}

/**
 * Returns true if the Ants action is proactive
 * 
 * @return bool
 */
bool Ant::isProactive() const
{
    return proactive;
}

/**
 * Returns true if the Ant is an attacker (Throwers)
 * 
 * @return bool
 */
bool Ant::isAttacker() const
{
    return attacker;
}

// * Mutators

/**
 * Subtracks one health from the Ant
 * 
 * Returns true if the Ant is killed by the damage
 * 
 * @return bool
 */
bool Ant::damage()
{
    health-=1;
    return health <= 0;
}

/**
 * Sets the current position of the Ant
 * 
 * @param int index
 */
void Ant::set_ant_position(int index)
{
    position = index;
}