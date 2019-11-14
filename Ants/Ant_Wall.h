/**
 * Wall Ant
 * 
 * Parent: Ant
 */

#ifndef ANT_WALL_H
#define ANT_WALL_H

#include "Ant.h"

class Ant_Wall: public Ant {


    public:

        // * Constructor

        Ant_Wall();

        virtual Ant_Wall * clone() const;

        // * Destructor

        ~Ant_Wall();

        virtual std::string get_ant_action() const;
        virtual std::string ant_type() const;

    private:

        std::string type;

};

#endif