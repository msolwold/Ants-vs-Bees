/**
 * BodyGuard Ant
 * 
 * Parent: Ant
 */

#include "Ant.h"

class Ant_Bodyguard: public Ant {


    public:

        // * Constructor

        Ant_Bodyguard();

        // * Destructor

        ~Ant_Bodyguard();

        virtual void print_ant_action() const;
        virtual std::string ant_type() const;

    private:

        std::string type;

};