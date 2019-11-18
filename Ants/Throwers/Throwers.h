/**
 * Thrower type interface
 * 
 * Abstract Class
 * Parent: Ant
 * Children: Thrower, Long Thrower, Short Thrower
 */

#ifndef THROWERS_H
#define THROWERS_H

#include <string>
#include <iostream>

#include "../Ant.h"
#include "../../Core/Board.h"

class Throwers : public Ant
{

public:
    // * Constructors

    Throwers();
    Throwers(const Throwers &a);

    virtual Throwers *clone() const = 0;

    // * Destructor

    virtual ~Throwers(){}

    // * Accessors

    virtual std::string get_ant_action() const = 0;
    virtual std::string get_ant_initials() const = 0;

    virtual int get_min_range() const;
    virtual int get_max_range() const;
    virtual bool hasAttacked() const;

    // * Mutators

    virtual void attack(Board * b);
    virtual void refresh_ant();

protected:
    int min_range;
    int max_range;

    bool attacked;
};

#endif