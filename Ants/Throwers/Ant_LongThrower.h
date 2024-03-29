/**
 * Long Thrower Ant
 * Parent: Throwers
 * 
 */

#ifndef ANT_LONGTHROWER_H
#define ANT_LONGTHROWER_H

#include <string>
#include <iostream>

#include "Throwers.h"

class Ant_LongThrower : public Throwers
{

public:
    // * Constructors

    Ant_LongThrower();

    virtual Ant_LongThrower *clone() const;

    // * Destructors

    virtual ~Ant_LongThrower(){}

    virtual std::string get_ant_action() const;
    virtual std::string get_ant_initials() const;

private:
};

#endif