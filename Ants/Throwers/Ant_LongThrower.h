/**
 * Long Thrower Ant
 * Parent: Throwers
 * 
 */

#include <string>
#include <iostream>

#include "../Ant.h"
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