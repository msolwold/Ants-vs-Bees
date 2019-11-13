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

class Ant_LongThrower: public Throwers {

    public:

        // * Constructors

        Ant_LongThrower();

        // * Destructors

        ~Ant_LongThrower();

        virtual void print_ant_action() const;
        virtual std::string ant_type() const;

    private:

};

#endif