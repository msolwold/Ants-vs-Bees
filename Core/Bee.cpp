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

Bee::Bee(){

    armor = 3;
    health = 3;

    alive = true;
    attacked = false;
    position = 10;
}