/**
 * Bee class
 * 
 * Only one type of bee
 * 
 * Armor: 3
 * Damage: 1
 * 
 * New Bee spawns every round
 * Tries to move right to left
 * Can only move if space does not contain a blocking ant*
 * Attacks the ant in the space to the left until the ant dies or bee dies
 * 
 * TODO: Destructor
 * 
 */

#include <string>
#include <iostream>

#include "Bee.h"

Bee::Bee()
{
    armor = 3;
    health = 3;

    alive = true;
    attacked = false;
}

// * Accessors

/**
 * Returns the current health of the Bee
 * 
 * @return int
 */
int Bee::get_bee_health() const
{
    return health;
}

/**
 * Returns the armor of the Bee
 * 
 * @return int
 */
int Bee::get_bee_armor() const
{
    return armor;
}

/**
 * Returns true if the Bee is alive
 * 
 * @return bool
 */
bool Bee::isAlive() const
{
    return alive;
}

/**
 * Returns the current position of the Bee
 * 
 * @return int
 */
int Bee::get_bee_position() const
{
    return position;
}

/**
 * Returns true if the Bee has already attacked
 * 
 * @return bool
 */
bool Bee::hasAttacked() const
{
    return attacked;
}

// * Mutators

/**
 * Sets the current position of the Bee
 * 
 * @param int index
 */
void Bee::set_bee_position(int index)
{
    position = index;
}

/**
 * Attack function for the Bee
 * 
 * Flips the attacked flag
 */
void Bee::attack()
{
    attacked = true;
}

/**
 * Refreshes the Bee
 * 
 * Sets the attacked flag to false
 */
void Bee::refresh_bee()
{
    attacked = false;
}

/**
 * Deals damage to the Bee
 * 
 * Default damage amount = 1
 * 
 * Returns true if the Bee dies from the attack
 * 
 * @param int damage
 * 
 * @return bool
 */
bool Bee::damage(int damage)
{
    health -= damage;
    return health <= 0;
}