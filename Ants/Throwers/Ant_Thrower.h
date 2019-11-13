/**
 * Thrower Ant
 * Parent: Throwers
 *
 */

#ifndef ANT_THROWER_H
#define ANT_THROWER_H

#include <string>
#include <iostream>

#include "Throwers.h"

class Ant_Thrower: public Throwers {

    public:

        // * Constructors
        
        Ant_Thrower();

        // * Destructor

        ~Ant_Thrower();

        virtual void print_ant_action() const;
        virtual std::string ant_type() const;

    private:

};

#endif