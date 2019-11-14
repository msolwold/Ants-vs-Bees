/**
 * Ant Class
 * 
 * Can place a new ant every round assuming food level is sufficient
 * 
 * There are 8 types of ants with varying actions, damage, and armor
 * 
 * Ants protect the queen ant, far left, from the spawning bees, far right.
 */

#include "Ant.h"

Ant::Ant(){
    
    alive = true;
}

Ant::Ant(const Ant &a) {

    Ant::ant_type = a.ant_type;
    Ant::armor = a.armor;
    Ant::health = a.health;
    Ant::cost = a.cost;
    Ant::blocking = a.blocking;
    Ant::proactive = a.proactive;
    Ant::attacker = a.attacker;
    Ant::alive = a.alive;
}