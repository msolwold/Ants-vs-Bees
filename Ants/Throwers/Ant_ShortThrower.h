/**
 * Short Thrower Ant
 * Parent: Throwers
 * 
 */

#ifndef ANT_SHORTTHROWER_H
#define ANT_SHORTTHROWER_H

#include <string>
#include <iostream>

#include "Throwers.h"

class Ant_ShortThrower : public Throwers
{

public:
    // * Constructor

    Ant_ShortThrower();

    virtual Ant_ShortThrower *clone() const;

    // * Destructor

    virtual ~Ant_ShortThrower(){}

    virtual std::string get_ant_action() const;
    virtual std::string get_ant_initials() const;

private:
    std::string type();
};

#endif