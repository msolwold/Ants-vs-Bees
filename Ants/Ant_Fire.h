/**
 * Fire Ant
 * 
 * Parent: Ant
 */

#ifndef ANT_FIRE_H
#define ANT_FIRE_H

#include "Ant.h"

class Ant_Fire : public Ant
{

public:
    // * Constructor

    Ant_Fire();

    virtual Ant_Fire *clone() const;

    // * Destructor

    virtual ~Ant_Fire(){}

    virtual std::string get_ant_action() const;
    virtual std::string get_ant_initials() const;

private:
    std::string type;
};

#endif