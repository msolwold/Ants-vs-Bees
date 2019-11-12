/**
 * Ninja Ant
 * 
 * Parent: Ant
 */

#include "Ant.h"

class Ant_Ninja: public Ant {


    public:

        // * Constructor

        Ant_Ninja();

        // * Destructor

        ~Ant_Ninja();

        virtual void print_ant_action() const;
        virtual std::string ant_type() const;

    private:

        std::string type;

};