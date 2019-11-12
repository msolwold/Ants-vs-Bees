/**
 * Thrower Ant
 * Parent: Throwers
 *
 */

#include <string>
#include <iostream>

#include "../Ant.h"
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