/**
 * Wall Ant
 * 
 * Parent: Ant
 */

#include "Ant.h"

class Ant_Wall: public Ant {


    public:

        // * Constructor

        Ant_Wall();

        // * Destructor

        ~Ant_Wall();

        virtual void print_ant_action() const;
        virtual std::string ant_type() const;

    private:

        std::string type;

};