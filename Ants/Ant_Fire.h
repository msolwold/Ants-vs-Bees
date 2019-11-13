/**
 * Fire Ant
 * 
 * Parent: Ant
 */

#ifndef ANT_FIRE_H
#define ANT_FIRE_H

#include "Ant.h"

class Ant_Fire: public Ant {


    public:

        // * Constructor

        Ant_Fire();

        // * Destructor

        ~Ant_Fire();

        virtual void print_ant_action() const;
        virtual std::string ant_type() const;

    private:

        std::string type;

};

#endif