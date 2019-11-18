/**
 * Ninja Ant
 * 
 * Parent: Ant
 */

#ifndef ANT_NINJA
#define ANT_NINJA

#include "Ant.h"

class Ant_Ninja : public Ant
{

public:
    // * Constructor

    Ant_Ninja();

    virtual Ant_Ninja *clone() const;

    // * Destructor

    virtual ~Ant_Ninja(){}

    virtual std::string get_ant_action() const;
    virtual std::string get_ant_initials() const;

private:
    std::string type;
};

#endif