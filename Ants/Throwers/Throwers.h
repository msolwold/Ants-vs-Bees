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

#include "Ant.h"

class Throwers: public Ant {


    public:

        // * Constructors

        Throwers();
        
        // * Destructor

        ~Throwers();

        // * Accessors

        virtual void print_ant_action() const = 0;
        virtual std::string ant_type() const = 0;

        virtual int get_min_range() const;
        virtual int get_max_range() const;
        virtual bool hasAttacked() const;

        // * Mutators

        virtual void attack();
        virtual void refresh_ant();

    protected:

        int min_range;
        int max_range;

        bool attacked;

};

#endif