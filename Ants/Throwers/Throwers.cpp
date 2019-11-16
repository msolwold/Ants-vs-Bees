/**
 * Thrower type ant
 * 
 * These ants have an active attack
 * 
 */

#include "Throwers.h"

Throwers::Throwers()
{
    attacked = false;

    Ant::blocking = true;
    Ant::attacker = true;
    Ant::proactive = true;
}

Throwers::Throwers(const Throwers &a)
{
    Throwers::min_range = a.min_range;
    Throwers::max_range = a.max_range;
    Throwers::attacked = a.attacked;
}