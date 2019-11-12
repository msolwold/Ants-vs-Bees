/**
 * Short Thrower Ant
 * Parent: Throwers
 * 
 */

#include <string>
#include <iostream>

#include "../Ant.h"
#include "Throwers.h"

class Ant_ShortThrower: public Throwers {

    public:

        // * Constructor

        Ant_ShortThrower();
        
        // * Destructor

        ~Ant_ShortThrower();

        virtual void print_ant_action() const;
        virtual std::string ant_type() const;

    private:

        std::string type();

};