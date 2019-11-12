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

Ant_Wall::Ant_Wall(){

    Ant::ant_type = "Wall";
    Ant::armor = 4;
    Ant::health = armor;
    Ant::cost = 4;
    Ant::proactive = false;
    Ant::attacker = false;
    Ant::blocking = true;
}