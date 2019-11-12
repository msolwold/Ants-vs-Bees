/**
 * Thrower type ant
 * 
 * These ants have an active attack
 * 
 */

#include "Throwers.h"

Throwers::Throwers(){

    attacked = false;

    Ant::blocking = true;
    Ant::attacker = true;
    Ant::proactive = true;
}